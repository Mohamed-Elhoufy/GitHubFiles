#define F_CPU 8000000U
#include "Segment.h"
#include "DIO_Interface.h"
#include "StdTypes.h"
#include<util/delay.h>

/* if not BCD don't include array */
#if(!BCD)
static u8 SegNumbers[]={
	0x3F,
	0x06,
	0x5B,
	0x4F,
	0x66,
	0x6D,
	0x7D,
	0x07,
	0x7F,
	0x6F,
	0x77,
	0x7C,
	0x39,
	0x5E,
	0x79,
	0x71
};
#endif

/**************************************************************/
/************ this driver for just two seven segments *********/
/**************************************************************/
#if(!BCD)
/************************IF Not BCD ****************************/
#if(!MODE && !COMMON)	/* MODE -> NORMAL && COMMON -> CATHODE */
/* Seg_2Display: display decimal numbers (NORMAL)
   Pre: configure SEG1_PORT, SEG2_PORT, mode, common, and number should be less than 10 */
void Seg_2Display(u8 num,u8 point_mode)
{
	DIO_WritePort(SEG1_NORMAL_PORT, SegNumbers[num%10]);
	DIO_WritePort(SEG2_NORMAL_PORT, SegNumbers[num/10]);
}
#elif(!MODE && COMMON)	/* MODE -> NORMAL && COMMON -> ANODE */
void Seg_2Display(u8 num,u8 point_mode)
{
	DIO_WritePort(SEG1_NORMAL_PORT, ~SegNumbers[num%10]);
	DIO_WritePort(SEG2_NORMAL_PORT, ~SegNumbers[num/10]);
}

/* Seg_2Display: display decimal numbers (MUX)
   Pre: configure SEG_PORT, SEG1_EN, SEG2_EN , mode, common and number should be less than 10 */
#elif(MODE && !COMMON)	/* MODE -> MUX && COMMON -> CATHODE */
void Seg_2Display(u8 num,u8 point_mode)
{
	DIO_WritePin(SEG2_EN, LOW);
	DIO_WritePin(SEG1_EN, HIGH);
	if (point_mode==1)
	{
		DIO_WritePin(PINB0,HIGH);
	}
	else						DIO_WritePort(SEG_MUX_PORT, (SegNumbers[num%10])<<1);
	
	_delay_ms(1);
	DIO_WritePin(PINB0,LOW);
	/* ERROR: you have to change the SEG2_EN to low first  */
	/* DIO_WritePin(SEG1_EN, HIGH);
		DIO_WritePin(SEG2_EN, LOW); */
	DIO_WritePin(SEG1_EN, LOW);
	DIO_WritePin(SEG2_EN, HIGH);
	if (point_mode==2)
	{
		DIO_WritePin(PINB0,HIGH);
	}			
	DIO_WritePort(SEG_MUX_PORT, (SegNumbers[num/10])<<1);

	_delay_ms(1);
	DIO_WritePin(PINB0,LOW);
}
#elif(MODE && COMMON)	/* MODE -> MUX && COMMON -> ANODE */
void Seg_2Display(u8 num,u8 point_mode)
{
		DIO_WritePin(SEG1_EN, LOW);
		DIO_WritePin(SEG2_EN, HIGH);			
		
		DIO_WritePort(SEG_MUX_PORT, ~(SegNumbers[num%10]));
		_delay_ms(1); 
			
		DIO_WritePin(SEG2_EN, LOW);
		DIO_WritePin(SEG1_EN, HIGH);	
		if (point_mode==2)			DIO_WritePort(SEG_MUX_PORT,((~(SegNumbers[num/10])) & 0x7F));
		else						DIO_WritePort(SEG_MUX_PORT, ~(SegNumbers[num/10]));
		_delay_ms(1);
}

#endif


#else
/************************IF BCD ****************************/
/* Seg_2Display: display decimal numbers
   Pre: configure SEG1_PORT, SEG2_PORT number should be less than 10 */
void Seg_2Display(u8 num,u8 point_mode)
{
	DIO_WritePort(SEG1_NORMAL_PORT, num%10);
	DIO_WritePort(SEG2_NORMAL_PORT, num/10);
}

#endif






void Seg_Toggle(Flash_type seg)
{
	static u8 seg1_status=0,seg2_status=0,seg_status;
	
	switch(seg)
	{
		case first:
		if (seg2_status)
		{
			DIO_WritePin(SEG1_EN,LOW);
			seg1_status++;
		}
		else
		{
			DIO_WritePin(SEG1_EN,HIGH);
			seg1_status--;
		}
		break;
		
		case second:
		if (seg2_status)
		{
			DIO_WritePin(SEG2_EN,LOW);
			seg2_status++;
		}
		else
		{
			DIO_WritePin(SEG2_EN,HIGH);
			seg2_status--;
		}
		break;
		
		case both:
		if (seg_status)
		{
			DIO_WritePin(SEG1_EN,LOW);
			DIO_WritePin(SEG2_EN,LOW);
			seg_status++;
		}
		else
		{
			DIO_WritePin(SEG1_EN,LOW);
			DIO_WritePin(SEG2_EN,HIGH);
			seg_status--;
		}
	}
}


