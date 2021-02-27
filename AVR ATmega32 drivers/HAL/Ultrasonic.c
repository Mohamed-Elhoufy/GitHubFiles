/*
 * Ultrasonic.c
 *
 * Created: 12/21/2020 2:10:58 PM
 *  Author: Amrth
 */ 
#include "Ultrasonic.h"

static volatile u8 flag=0;
static volatile u32 t1,t2;
static void ICU_Func(void)
{
	if (flag==0)
	{
		t1=ICR1;
		flag=1;
		Timer1_InputCaptureEdge(FALLING);
	}
	else if (flag==1)
	{
		t2=ICR1;
		flag=2;
		//Timer1_InputCaptureEdge(RISING);
	}
}

void ULTRASONIC_Init(void)
{
	Timer1_Init(TIMER1_NORMAL_MODE,TIMER1_SCALER_8);
	Timer1_ICU_SetCallBack(ICU_Func);
	
}

u16  ULTRASONIC_Read(Ultrasonic_Type  US)
{
	Timer1_ICU_InterruptEnable();
	u16 time,d;
	flag=0;
	Timer1_InputCaptureEdge(RISING);
	DIO_WritePin(US,HIGH);
	_delay_us(10);
	DIO_WritePin(US,LOW);
	while (flag<2);
	if (t2<t1)	time=(t2+20000)-t1;
	else		time=t2-t1;
	d=time/58;
	return d;
	Timer1_ICU_InterruptDisable();
}