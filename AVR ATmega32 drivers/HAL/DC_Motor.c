#include "DC_Motor.h"



void Motor_Init (void)
{	
	//DIO_InitPin(Motor1_EN,OUTPUT);
	DIO_InitPin(Motor1_P,OUTPUT);
	DIO_InitPin(Motor1_N,OUTPUT);
	//DIO_WritePin(Motor1_EN,LOW);
	DIO_WritePin(Motor1_N,LOW);
	DIO_WritePin(Motor1_P,LOW);

// 	DIO_InitPin(Motor2_EN,OUTPUT);
// 	DIO_InitPin(Motor2_P,OUTPUT);
// 	DIO_InitPin(Motor2_N,OUTPUT);
// 	DIO_WritePin(Motor2_EN,LOW);
// 	DIO_WritePin(Motor2_N,LOW);
// 	DIO_WritePin(Motor2_P,LOW);
}


void Motor_CW   (Motor_Type Motor)
{
	switch (Motor)
	{
		case Motor1:
		//DIO_WritePin(Motor1_EN,HIGH);
		DIO_WritePin(Motor1_N,HIGH);
		DIO_WritePin(Motor1_P,LOW);
		break;
		
// 		case Motor2:
// 		DIO_WritePin(Motor2_EN,HIGH);
// 		DIO_WritePin(Motor2_N,HIGH);
// 		DIO_WritePin(Motor2_P,LOW);
// 		break;
	}
}



void Motor_CCW  (Motor_Type Motor)
{
	switch (Motor)
	{
		case Motor1:
		//DIO_WritePin(Motor1_EN,HIGH);
		DIO_WritePin(Motor1_N,LOW);
		DIO_WritePin(Motor1_P,HIGH);
		break;
		
// 		case Motor2:
// 		DIO_WritePin(Motor2_EN,HIGH);
// 		DIO_WritePin(Motor2_N,LOW);
// 		DIO_WritePin(Motor2_P,HIGH);
// 		break;
	}
}


void Motor_Stop (Motor_Type Motor)
{
	switch (Motor)
	{
		case Motor1:
		//DIO_WritePin(Motor1_EN,LOW);
		DIO_WritePin(Motor1_N,LOW);
		DIO_WritePin(Motor1_P,LOW);
		break;
		
// 		case Motor2:
// 		DIO_WritePin(Motor2_EN,LOW);
// 		DIO_WritePin(Motor2_N,LOW);
// 		DIO_WritePin(Motor2_P,LOW);
// 		break;
	}
}


void Motor_QuickStop (Motor_Type Motor)
{
	switch (Motor)
	{
		case Motor1:
		if (Motor1_P==1)		  Motor_CCW(Motor1);
		else if (Motor1_N==1)    Motor_CW (Motor1);
		_delay_ms(3000);
		//DIO_WritePin(Motor1_EN,LOW);
		DIO_WritePin (Motor1_N,LOW);
		DIO_WritePin (Motor1_P,LOW);
		break;
		
// 		case Motor2:
// 		if (Motor2_P)		  Motor_CCW(Motor2);
// 		else if (Motor2_N)    Motor_CW (Motor2);
// 		_delay_ms(3000);
// 		DIO_WritePin(Motor2_EN,LOW);
// 		DIO_WritePin (Motor2_N,LOW);
// 		DIO_WritePin (Motor2_P,LOW);
// 		break;
	}
}


/************ DC MOTOR PWM SPEED CONTROL **************/

u32 PWM_TOP=0;
void Motor_SpeedControlInit(void)
{
	Timer1_Init(TIMER1_PWM_PHASE_FREQ_ICR_TOP_MODE,TIMER1_SCALER_8);
	Timer1_OCRA1Mode(OCRA_NON_INVERTING);
	PWM_TOP=(PWM_FREQUENCY_kHz*1000)/2;
	ICR1=PWM_TOP;
}

void Motor_SetSpeed(u8 Percentage)
{
	OCR1A=(PWM_TOP*Percentage)/100;
}
