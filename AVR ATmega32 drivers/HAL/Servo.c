/*
 * Servo.c
 *
 * Created: 12/23/2020 1:08:25 AM
 *  Author: Amrth
 */ 
#include "Servo.h"



void servo_Init(void)
{
	Timer1_Init(TIMER1_FASTPWM_OCRA_TOP_MODE,TIMER1_SCALER_8);
	Timer1_OCRB1Mode(OCRB_NON_INVERTING);
	OCR1A=18000;
}

u8 servo_SetAngle(s16 angle)
{
	if ( (angle <= End_ANGLE) && (angle >= START_ANGLE))
	{
		OCR1B=((u32)angle*1000)/180+999;
		return 1;
	}
	else        return 0;
}
