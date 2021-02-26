/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
#include "StdTypes.h"
#include "Utils.h"

#include "RCC_Interface.h"
#include "GPIO_interface.h"
//#include "SEG_interface.h"
//#include "Keypad_interface.h"
#include "LCD_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "STK_interface.h"
#include "ADC_interface.h"
#include "Timer_private.h"
#include "Timer_interface.h"
#include "UART_interface.h"



#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

/********************************************************/

/*		Static Screens  */
#define   	 SCREEN1L0					"  WELCOME  IN   "
#define   	 SCREEN1L1					"Comunication Sys"

#define   	 SCREEN2L0					"  System Main   "
#define   	 SCREEN2L1					"LIGHT:    S:    "

#define   	 SCREEN3L0					"  Config LIGHT  "
#define   	 SCREEN3L1					"New Light :    %"

#define   	 SCREEN4L0					"  Config SPEED  "
#define   	 SCREEN4L1					"New SPEED :    %"

#define   	 SCREEN5L0					"     VALID      "
#define   	 SCREEN5L1					"    COMMAND     "

#define   	 SCREEN6L0					"    INVALID     "
#define   	 SCREEN6L1					"  !!COMMAND!!   "

/*  Dynamic Screens   */
#define     DISP_LIGHT_INTENSITY_L				           	1
#define     DISP_LIGHT_INTENSITY_C				        	6

#define     DISP_FAN_SPEED_L	     				         1
#define     DISP_FAN_SPEED_C			    	            14

#define     DISP_NEW_CONFIGURATION_L					    1
#define     DISP_NEW_CONFIGURATION_C					   12

typedef enum {
	DISP_SCREEN1,
	DISP_SCREEN2,
	DISP_SCREEN3,
	DISP_SCREEN4,
	DISP_SCREEN5,
	DISP_SCREEN6,
	TURN_ON_GREEN_LED,
	TURN_OFF_GREEN_LED,
	TURN_ON_BLUE_LED,
	TURN_OFF_BLUE_LED,
}System_State;

typedef enum {
	RECIVING_COMMANDS,           /* TIME BASED  */
	CHECKING_COMMANDS_VIDALITY,  /* EVENT BASED */
	COMMAND1_VALID	,            /* EVENT BASED */
	COMMAND2_VALID	,            /* EVENT BASED */
	COMMAND3_VALID	,            /* EVENT BASED */
	COMMAND4_VALID	,            /* EVENT BASED */
	COMMAND5_VALID	,            /* EVENT BASED */
	COMMAND6_VALID	,            /* EVENT BASED */
	COMMAND7_VALID	,            /* EVENT BASED */
	COMMAND8_VALID	,            /* EVENT BASED */
	COMMAND9_VALID	,            /* EVENT BASED */
	COMMAND10_VALID	,            /* EVENT BASED */
	COMMAND11_VALID	,            /* EVENT BASED */
	COMMAND12_VALID	,            /* EVENT BASED */
	COMMAND13_VALID	,            /* EVENT BASED */
	COMMAND14_VALID	,            /* EVENT BASED */
	COMMAND15_VALID	,            /* EVENT BASED */
	COMMAND16_VALID	,            /* EVENT BASED */
	COMMANDS_UNVALID,            /* EVENT BASED */
	RECIVING_ADC_READINGS        /* TIME BASED  */
	//CALLING_USER_BACK,		 /* EVENT BASED */

}System_States;
/********************************************************/

#define OPEN_CLOSE_LOCK      '1'
#define FAN_AUTO_MANUAL      '2'
#define LIGHT_AUTO_MANUAL    '3'

#define STOP_LIGHT           '4'
#define START_LIGHT_100      '5'
#define START_LIGHT_75       '6'
#define START_LIGHT_50       '7'
#define START_LIGHT_25       '8'

#define START_FAN_100        '9'
#define START_FAN_50         '10'
#define START_FAN_25         '11'
#define STOP_FAN             '12'

#define LCD_STRT_SCREEN1     '13'
#define LCD_STRT_SCREEN2     '14'
#define LCD_STRT_SCREEN3     '15'
#define LCD_STRT_SCREEN4     '16'

/***********************Valid Commands**********************/

//static u8 Comm1[]  =  "OPEN_CLOSE_LOCK " ;
//static u8 Comm2[]  =  "FAN_AUTO_MANUAL " ;
//static u8 Comm3[]  =  "LIGHT_AUTO_MANUAL " ;
//
//static u8 Comm4[]  =  "STOP.LIGHT" ;
//static u8 Comm5[]  =  "START.LIGHT.100 " ;
//static u8 Comm6[]  =  "START.LIGHT.70 " ;
//static u8 Comm7[]  =  "START.LIGHT.50 " ;
//static u8 Comm8[]  =  "START.LIGHT.25 " ;
//
//static u8 Comm9[]  =  "START.FAN.100 " ;
//static u8 Comm10[] =  "START.FAN.50 " ;
//static u8 Comm11[] =  "START.FAN.25 " ;
//static u8 Comm12[] =  "STOP.FAN " ;
//
//static u8 Comm13[] =  "LCD.STRT.SCREEN1 " ;
//static u8 Comm14[] =  "LCD.STRT.SCREEN2 " ;
//static u8 Comm15[] =  "LCD.STRT.SCREEN3 " ;
//static u8 Comm16[] =  "LCD.STRT.SCREEN4 " ;


/***************************END****************************/

#define LIGHT_AUTO 0
#define LIGHT_MANUAL 0
#define FAN_AUTO 0
#define FAN_MANUAL 0
#define LOCK_OPEN 0
#define LOCK_CLOSE 0


int main(void)
{
	/********************* Global declerations ******************/

	System_States  CurrentState = RECIVING_COMMANDS ;
	//static u8 Command[200]={0};
	u8 FanSpeed=0,Light=0,i=0,pf=0;
	/*	Timer declecartion && PWM Decleration  				*/
	Timer_Config_type timer3={_TIM3,  PRELOAD, UPCOUNTER , DISABLE, 8 } ;      /* prescaller 8MHz/80 =100KHz and TickTime 10us */
	PWM_Config_type  PWM3_CH3={_TIM3,TIM_CHANNEL3,EDGE_ALIGN,MODE1_START_HIGH,10,2,50};    /*2% Angel 0--10% Angel 180*/
	PWM_Config_type  PWM3_CH4={_TIM3,TIM_CHANNEL4,EDGE_ALIGN,MODE1_START_HIGH,10,2,50};
	/*  UART  declecartion                   				*/
	UART_init_type uart1 ={ ID_UART1 ,  STRTBIT_8DATA_NSTOPBIT , NO_PARITY,  STOP_1_BIT ,DMA_TX_DISABLE, DMA_RX_DISABLE ,RATE_9600};
	/* 	RCC External Crystal	FCPU=8MHz		*/
	RCC_voidInit();
	RCC_voidEnablePeripheralClock_EntireBus(RCC_APB2);
	RCC_voidEnablePeripheralClock_EntireBus(RCC_APB1); /*  UART2 / UART3	*/
	/*	Systick	  F=Fcpu/8 =1Mhz and tick time=1us		*/
	STK_voidInit();
	/* 	GPIO 			*/
	DIO_Init();
	DIO_InitPin(PINA0, DIO_E_INPUT_ANALOG);
	DIO_InitPin(PINA1, DIO_E_INPUT_ANALOG);
	DIO_InitPin(PINA2, DIO_E_OUTPUT_2MHZ_PUSH);
	DIO_InitPin(PINA3, DIO_E_OUTPUT_2MHZ_PUSH);
	DIO_InitPin(PINA4, DIO_E_OUTPUT_2MHZ_PUSH);
	DIO_InitPin(PINA5, DIO_E_OUTPUT_2MHZ_PUSH);
	DIO_InitPin(PINA6, DIO_E_OUTPUT_2MHZ_PUSH);
	DIO_InitPin(PINA7, DIO_E_OUTPUT_2MHZ_PUSH);
	DIO_InitPin(PINA8, DIO_E_OUTPUT_2MHZ_PUSH);
	/* 	UART 1 PINs Init                     		*/
	DIO_InitPin(PINA9, DIO_E_OUTPUT_2MHZ_AF_PP);      /* TX1 */
	DIO_InitPin(PINA10, DIO_E_INPUT_PULL_UP);         /* RX1 */
	/* 	Timer 2 PINs Init                     		*/
	DIO_InitPin(PINB0, DIO_E_OUTPUT_2MHZ_AF_PP);       /* TIM3 CH3 / Fan Speed      */
	DIO_InitPin(PINB1, DIO_E_OUTPUT_2MHZ_AF_PP);      /* TIM3 CH4 / LEDs Adjustment */
	/* 	ADC Init                     		*/
	ADC_voidInit();
	/* 	LCD Init                     		*/
	LCD_Init();
	/*	UART init &	Enable	*/
	UART_voidInit(&uart1);
	/*	timer init & Enable	  */
	TimerInit(&timer3);
	/*  PWM init & Enable */
	timer_voidGPWM(&PWM3_CH3); /* TIM3 CH3 / Fan Speed      */
	timer_voidGPWM(&PWM3_CH4); /* TIM3 CH4 / LEDs Adjustment */
	u8 command,light_flag=LIGHT_AUTO,fan_flag=FAN_AUTO,lock_flag=LOCK_OPEN,fan_last_manual=0,light_last_manual=0,ldr_Read,pot_Read;

	while(1)
	{
		switch(CurrentState)
		{
		case RECIVING_COMMANDS:
			command=UART_u8ReciveChar(&uart1);
			/*There is a Recived Command */
			if(command!=0)		    CurrentState = CHECKING_COMMANDS_VIDALITY ;
			else          		    CurrentState = RECIVING_ADC_READINGS ;
			break;

		case CHECKING_COMMANDS_VIDALITY:
			if(OPEN_CLOSE_LOCK==command)          CurrentState = COMMAND1_VALID;
			else if(FAN_AUTO_MANUAL==command)     CurrentState = COMMAND2_VALID;
			else if(LIGHT_AUTO_MANUAL==command)   CurrentState = COMMAND3_VALID;

			else if((STOP_LIGHT==command)&&(LIGHT_MANUAL==light_flag))          CurrentState = COMMAND4_VALID;
			else if((START_LIGHT_100==command)&&(LIGHT_MANUAL==light_flag))     CurrentState = COMMAND5_VALID;
			else if((START_LIGHT_75==command)&&(LIGHT_MANUAL==light_flag))      CurrentState = COMMAND6_VALID;
			else if((START_LIGHT_50==command)&&(LIGHT_MANUAL==light_flag))      CurrentState = COMMAND7_VALID;
			else if((START_LIGHT_25==command)&&(LIGHT_MANUAL==light_flag))      CurrentState = COMMAND8_VALID;

			else if((START_FAN_100==command)&&(FAN_MANUAL==fan_flag))       CurrentState = COMMAND9_VALID;
			else if((START_FAN_50==command)&&(FAN_MANUAL==fan_flag))        CurrentState = COMMAND10_VALID;
			else if((START_FAN_25==command)&&(FAN_MANUAL==fan_flag))        CurrentState = COMMAND11_VALID;
			else if((STOP_FAN==command)&&(FAN_MANUAL==fan_flag))            CurrentState = COMMAND12_VALID;

			else if(LCD_STRT_SCREEN1==command)    CurrentState = COMMAND13_VALID;
			else if(LCD_STRT_SCREEN2==command)    CurrentState = COMMAND14_VALID;
			else if(LCD_STRT_SCREEN3==command)    CurrentState = COMMAND15_VALID;
			else if(LCD_STRT_SCREEN4==command)    CurrentState = COMMAND16_VALID;

			else if((CurrentState!=COMMAND1_VALID|| CurrentState!=COMMAND2_VALID || CurrentState!=COMMAND3_VALID
					|| CurrentState!=COMMAND4_VALID  || CurrentState!=COMMAND5_VALID || CurrentState!=COMMAND6_VALID
					||  CurrentState!=COMMAND7_VALID || CurrentState!=COMMAND8_VALID || CurrentState!=COMMAND9_VALID
					||  CurrentState!=COMMAND10_VALID|| CurrentState!=COMMAND11_VALID||CurrentState!=COMMAND12_VALID
					||  CurrentState!=COMMAND13_VALID|| CurrentState!=COMMAND14_VALID|| CurrentState!=COMMAND15_VALID
					||  CurrentState!=COMMAND16_VALID||CurrentState!=COMMAND17_VALID || CurrentState!=COMMAND18_VALID
					||  CurrentState!=COMMAND19_VALID|| CurrentState!=COMMAND20_VALID) && CurrentState==CHECKING_COMMANDS_VIDALITY  )
				CurrentState=COMMANDS_UNVALID;

			break;

		case COMMAND1_VALID:
			/*OPEN or Close Lock*/
			if(LOCK_OPEN==lock_flag)
			{
				DIO_WritePin(PINA8,HIGH);
				lock_flag=LOCK_CLOSE;
			}
			else if (LOCK_CLOSE==lock_flag)
			{
				DIO_WritePin(PINA8,LOW);
				lock_flag=LOCK_OPEN;
			}
			CurrentState=RECIVING_ADC_READINGS;
			break;
		case COMMAND2_VALID:
			/*Fan Auto or Manual*/
			if(FAN_AUTO==fan_flag)
			{
				//fan_last_manual  make pwm of tim3 ch4 at last manual value
				PWM3_CH3.duty=fan_last_manual;
				timer_voidGPWM(&PWM3_CH3);
				fan_flag=FAN_MANUAL;
			}
			else if (FAN_MANUAL==fan_flag)
			{
				//make pwm of tim3 ch3 at the adc READ Equivalent
				DIO_WritePin=pot_Read;
				timer_voidGPWM(&PWM3_CH3);
				fan_flag=FAN_AUTO;
			}
			CurrentState=RECIVING_ADC_READINGS;
			break;
		case COMMAND3_VALID:
			if(LIGHT_AUTO==light_flag)
			{
				//Light_last_manual  make pwm of tim3 ch4 at last manual value
				PWM3_CH4.duty=light_last_manual;
				timer_voidGPWM(&PWM3_CH4);
				light_flag=light_MANUAL;
			}
			else if (LIGHT_MANUAL==light_flag)
			{
				//make pwm of tim3 ch4 at the adc READ Equivalent
				PWM3_CH4.duty=ldr_Read;
				timer_voidGPWM(&PWM3_CH4);
				light_flag=LIGHT_AUTO;
			}
			CurrentState=RECIVING_ADC_READINGS;
			break;
		case COMMAND4_VALID:
			/*stop Lights*/
			//make pwm of tim3 ch4 at 0
			PWM3_CH4.duty=0;
			timer_voidGPWM(&PWM3_CH4);
			light_last_manual=0;
			CurrentState=RECIVING_ADC_READINGS;
			break;
		case COMMAND5_VALID:
			/*START_LIGHT_100*/
			//make pwm of tim3 ch4 at 100
			PWM3_CH4.duty=100;
			timer_voidGPWM(&PWM3_CH4);
			light_last_manual=100;
			CurrentState=RECIVING_ADC_READINGS;
			break;
		case COMMAND6_VALID:
			/*START_LIGHT_75*/
			//make pwm of tim3 ch4 at 75
			PWM3_CH4.duty=75;
			timer_voidGPWM(&PWM3_CH4);
			light_last_manual=75;
			CurrentState=RECIVING_ADC_READINGS;
			break;
		case COMMAND7_VALID:
			/*START_LIGHT_50*/
			//make pwm of tim3 ch4 at 50
			PWM3_CH4.duty=50;
			timer_voidGPWM(&PWM3_CH4);
			light_last_manual=50;
			CurrentState=RECIVING_ADC_READINGS;
			break;
		case COMMAND8_VALID:
			/*START_LIGHT_25*/
			//make pwm of tim3 ch4 at 25
			PWM3_CH4.duty=25;
			timer_voidGPWM(&PWM3_CH4);
			light_last_manual=25;
			CurrentState=RECIVING_ADC_READINGS;
			break;
		case COMMAND9_VALID:
			/*START_FAN_100*/
			PWM3_CH3.duty=100;
			timer_voidGPWM(&PWM3_CH3);
			fan_last_manual=100;
			CurrentState=RECIVING_ADC_READINGS;
			break;
		case COMMAND10_VALID:
			/*START_FAN_50*/
			PWM3_CH3.duty=50;
			timer_voidGPWM(&PWM3_CH3);
			fan_last_manual=50;
			CurrentState=RECIVING_ADC_READINGS;
			break;
		case COMMAND11_VALID:
			/*START_FAN_25*/
			PWM3_CH3.duty=25;
			timer_voidGPWM(&PWM3_CH3);
			fan_last_manual=25;
			CurrentState=RECIVING_ADC_READINGS;
			break;
		case COMMAND12_VALID:
			/*STOP_FAN*/
			PWM3_CH3.duty=0;
			timer_voidGPWM(&PWM3_CH3);
			fan_last_manual=0;
			CurrentState=RECIVING_ADC_READINGS;
			break;
		case COMMAND13_VALID:
			/*LCD_STRT_SCREEN1*/
			CurrentState=RECIVING_ADC_READINGS;
			break;
		case COMMAND14_VALID:
			/*LCD_STRT_SCREEN2*/
			CurrentState=RECIVING_ADC_READINGS;
			break;
		case COMMAND15_VALID:
			/*LCD_STRT_SCREEN3*/
			CurrentState=RECIVING_ADC_READINGS;
			break;
		case COMMAND16_VALID:
			/*LCD_STRT_SCREEN4*/
			CurrentState=RECIVING_ADC_READINGS;
			break;
		case COMMANDS_UNVALID:
			/*no command happens*/
			CurrentState=RECIVING_ADC_READINGS;
			break;
		case RECIVING_ADC_READINGS:
			/* ADC api for LDR */
			/* if different readings appear change Light , CurrentState = ADJUSTING_LIGHT  */
			ldr_Read=LDR_PercentRead(1);
			pot_Read=POT_PercentRead(0);
			else   CurrentState = RECIVING_COMMANDS
		default: CurrentState = RECIVING_ADC_READINGS ;  break;
		}
	}
}


