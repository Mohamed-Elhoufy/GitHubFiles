#include "Stepper.h"

void STEPPER_BiPolar_CW (void)
{
	
	DIO_WritePin(COIL1_A,LOW);
	DIO_WritePin(COIL1_B,LOW);
	DIO_WritePin(COIL2_A,HIGH);
	DIO_WritePin(COIL2_B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1_A,LOW);
	DIO_WritePin(COIL1_B,HIGH);
	DIO_WritePin(COIL2_A,LOW);
	DIO_WritePin(COIL2_B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1_A,LOW);
	DIO_WritePin(COIL1_B,LOW);
	DIO_WritePin(COIL2_A,LOW);
	DIO_WritePin(COIL2_B,HIGH);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1_A,HIGH);
	DIO_WritePin(COIL1_B,LOW);
	DIO_WritePin(COIL2_A,LOW);
	DIO_WritePin(COIL2_B,LOW);
	_delay_ms(DELAY);
	
}

void STEPPER_BiPolar_CCW(void)
{

	DIO_WritePin(COIL1_A,LOW);
	DIO_WritePin(COIL1_B,LOW);
	DIO_WritePin(COIL2_A,LOW);
	DIO_WritePin(COIL2_B,HIGH);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1_A,LOW);
	DIO_WritePin(COIL1_B,HIGH);
	DIO_WritePin(COIL2_A,LOW);
	DIO_WritePin(COIL2_B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1_A,LOW);
	DIO_WritePin(COIL1_B,LOW);
	DIO_WritePin(COIL2_A,HIGH);
	DIO_WritePin(COIL2_B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1_A,HIGH);
	DIO_WritePin(COIL1_B,LOW);
	DIO_WritePin(COIL2_A,LOW);
	DIO_WritePin(COIL2_B,LOW);
	_delay_ms(DELAY);
}

void STEPPER_UniPolar_CW (void)
{
	
	DIO_WritePin(BLUE,LOW);
	DIO_WritePin(PURPLE,LOW);
	DIO_WritePin(YELLOW,LOW);
	DIO_WritePin(ORANGE,HIGH);
	_delay_ms(DELAY);
	DIO_WritePin(BLUE,LOW);
	DIO_WritePin(PURPLE,LOW);
	DIO_WritePin(YELLOW,HIGH);
	DIO_WritePin(ORANGE,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(BLUE,LOW);
	DIO_WritePin(PURPLE,HIGH);
	DIO_WritePin(YELLOW,LOW);
	DIO_WritePin(ORANGE,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(BLUE,HIGH);
	DIO_WritePin(PURPLE,LOW);
	DIO_WritePin(YELLOW,LOW);
	DIO_WritePin(ORANGE,LOW);
	_delay_ms(DELAY);

}

void STEPPER_UniPolar_CCW(void)
{
	DIO_WritePin(BLUE,HIGH);
	DIO_WritePin(PURPLE,LOW);
	DIO_WritePin(YELLOW,LOW);
	DIO_WritePin(ORANGE,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(BLUE,LOW);
	DIO_WritePin(PURPLE,HIGH);
	DIO_WritePin(YELLOW,LOW);
	DIO_WritePin(ORANGE,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(BLUE,LOW);
	DIO_WritePin(PURPLE,LOW);
	DIO_WritePin(YELLOW,HIGH);
	DIO_WritePin(ORANGE,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(BLUE,LOW);
	DIO_WritePin(PURPLE,LOW);
	DIO_WritePin(YELLOW,LOW);
	DIO_WritePin(ORANGE,HIGH);
	_delay_ms(DELAY);
		
}

							      /*0011 0001 1001 1000 1100 0100 0110 0010*/
static const u8 UniPolar_States[8]={0x03,0x01,0x09,0x08,0x0C,0x04,0x06,0x02};
static s8 STEPPER_Motor_Pos=0;

void STEPPER_UniPolar_CW_Step (void)
{

	if (STEPPER_Motor_Pos>0)		STEPPER_Motor_Pos--;
	else					STEPPER_Motor_Pos=7;
	DIO_WritePin(BLUE,GET_BIT(UniPolar_States[STEPPER_Motor_Pos],0));
	DIO_WritePin(PURPLE,GET_BIT(UniPolar_States[STEPPER_Motor_Pos],1));
	DIO_WritePin(YELLOW,GET_BIT(UniPolar_States[STEPPER_Motor_Pos],2));
	DIO_WritePin(ORANGE,GET_BIT(UniPolar_States[STEPPER_Motor_Pos],3));
	_delay_ms(DELAY);
	

}

void STEPPER_UniPolar_CCW_Step (void)
{
	
	if (STEPPER_Motor_Pos<7)		
	{
		STEPPER_Motor_Pos++;
	}
	else
	{	
		STEPPER_Motor_Pos=0;
	}
	DIO_WritePin(BLUE,GET_BIT(UniPolar_States[STEPPER_Motor_Pos],0));
	DIO_WritePin(PURPLE,GET_BIT(UniPolar_States[STEPPER_Motor_Pos],1));
	DIO_WritePin(YELLOW,GET_BIT(UniPolar_States[STEPPER_Motor_Pos],2));
	DIO_WritePin(ORANGE,GET_BIT(UniPolar_States[STEPPER_Motor_Pos],3));
	_delay_ms(DELAY);
	

}


void STEPPER_UniPolar_Angle (s16 angle)
{
	u8 i;
	angle /= 5;
	
	if (angle >= 0)
	{
		for (i=0;i<angle;i++)		
		{
			STEPPER_UniPolar_CW_Step();
		}
	}
	else
	{
		angle= (angle* -1);
		for (i=0;i<angle;i++)
		{
			STEPPER_UniPolar_CCW_Step();
		}		

	}
}


void STEPPER_UniPolar_Cycle (s16 cycle)
{
	u16 i;
	cycle *= 72;
	
	if (cycle >= 0)
	{
		for (i=0;i<cycle;i++)		STEPPER_UniPolar_CW_Step();
	}
	else
	{
		cycle= (cycle* -1);
		for (i=0;i<cycle;i++)
		{
			STEPPER_UniPolar_CCW_Step();
		}
	}
}