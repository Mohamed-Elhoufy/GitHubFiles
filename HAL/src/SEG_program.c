/*
 * SEG_program.c
 *
 *  Created on: Feb 4, 2021
 *      Author: General
 */



#include "Includes_all.h"


#if((SEG_TYPE==SEG_CATHODE)&&(SEG_NUM_SYS==SEG_HEXADECIMAL))
static u8 SEG_Au8Numbers[SEG_NUM_SYS]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
#elif((SEG_TYPE==SEG_ANODE)&&(SEG_NUM_SYS==SEG_HEXADECIMAL))
static u8 SEG_Au8Numbers[SEG_NUM_SYS]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
#elif((SEG_TYPE==SEG_CATHODE)&&(SEG_NUM_SYS==SEG_DECIMAL))
static u8 SEG_Au8Numbers[SEG_NUM_SYS] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D,0x7D, 0x07, 0x7F, 0x6F };
#elif((SEG_TYPE==SEG_ANODE)&&(SEG_NUM_SYS==SEG_DECIMAL))
static u8 SEG_Au8Numbers[SEG_NUM_SYS]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
#elif((SEG_TYPE==SEG_CATHODE)&&(SEG_NUM_SYS==SEG_BINARY))
static u8 SEG_Au8Numbers[SEG_NUM_SYS]={0x3F,0x06};
#elif((SEG_TYPE==SEG_ANODE)&&(SEG_NUM_SYS==SEG_BINARY))
static u8 SEG_Au8Numbers[SEG_NUM_SYS]={0xc0,0xf9};
#endif
//normal decimal
#if ((SEG_MODE==SEG_NORMAL)&&(SEG_NUM_SYS==SEG_DECIMAL))
//#if (SEG_TYBE_NUM==SEG_CHARACTER_NUM)
void SEG_Init(void)
{
	DIO_voidSetFirstHalfPortDirection(SEG1_PORT, DIO_OUTPUT_2MHZ_PP);
	DIO_voidSetFirstHalfPortDirection(SEG2_PORT, DIO_OUTPUT_2MHZ_PP);
}
void SEG_Display(u8 Copy_u8_Num)
{
#if((SEG_N_PORTS==SEG_ONE)||(SEG_N_PORTS > SEG_ONE))
	DIO_voidSetFirstHalfPortValue(SEG1_PORT, SEG_Au8Numbers[(Copy_u8_Num)%10]);
	#endif
	#if((SEG_N_PORTS==SEG_TWO)||(SEG_N_PORTS > SEG_TWO))
	DIO_voidSetFirstHalfPortValue(SEG2_PORT, SEG_Au8Numbers[(Copy_u8_Num/10)%10]);
	#endif
}
//#endif
//#if (TYBE_NUM==INTEGER_NUM)
//void SEG_Display(u16 Copy_u16_Num)
//{
//#if((SEG_N_PORTS==SEG_ONE)||(SEG_N_PORTS > SEG_ONE))
//DIO_voidSetPinValue(SEG1_PORT, SEG1_PIN1, GET_BIT(SEG_Au8Numbers[Copy_u16_Num%10],0));
//DIO_voidSetPinValue(SEG1_PORT, SEG1_PIN2, GET_BIT(SEG_Au8Numbers[Copy_u16_Num%10],1));
//DIO_voidSetPinValue(SEG1_PORT, SEG1_PIN3, GET_BIT(SEG_Au8Numbers[Copy_u16_Num%10],2));
//DIO_voidSetPinValue(SEG1_PORT, SEG1_PIN4, GET_BIT(SEG_Au8Numbers[Copy_u16_Num%10],3));
//DIO_voidSetPinValue(SEG1_PORT, SEG1_PIN5, GET_BIT(SEG_Au8Numbers[Copy_u16_Num%10],4));
//DIO_voidSetPinValue(SEG1_PORT, SEG1_PIN6, GET_BIT(SEG_Au8Numbers[Copy_u16_Num%10],5));
//DIO_voidSetPinValue(SEG1_PORT, SEG1_PIN7, GET_BIT(SEG_Au8Numbers[Copy_u16_Num%10],6));
//DIO_voidSetPinValue(SEG1_PORT, SEG1_PIN8, GET_BIT(SEG_Au8Numbers[Copy_u16_Num%10],7));
//#endif
//#if((SEG_N_PORTS==SEG_TWO)||(SEG_N_PORTS > SEG_TWO))
//    DIO_voidSetPinValue(SEG2_PORT, SEG2_PIN1, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/10)%10],0));
//	DIO_voidSetPinValue(SEG2_PORT, SEG2_PIN2, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/10)%10],1));
//	DIO_voidSetPinValue(SEG2_PORT, SEG2_PIN3, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/10)%10],2));
//	DIO_voidSetPinValue(SEG2_PORT, SEG2_PIN4, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/10)%10],3));
//	DIO_voidSetPinValue(SEG2_PORT, SEG2_PIN5, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/10)%10],4));
//	DIO_voidSetPinValue(SEG2_PORT, SEG2_PIN6, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/10)%10],5));
//	DIO_voidSetPinValue(SEG2_PORT, SEG2_PIN7, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/10)%10],6));
//	DIO_voidSetPinValue(SEG2_PORT, SEG2_PIN8, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/10)%10],7));
//#endif
//#if((SEG_N_PORTS==SEG_THREE)||(SEG_N_PORTS > SEG_THREE))
//	DIO_voidSetPinValue(SEG3_PORT, SEG3_PIN1, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/100)%10],0));
//		DIO_voidSetPinValue(SEG3_PORT, SEG3_PIN2, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/100)%10],1));
//		DIO_voidSetPinValue(SEG3_PORT, SEG3_PIN3, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/100)%10],2));
//		DIO_voidSetPinValue(SEG3_PORT, SEG3_PIN4, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/100)%10],3));
//		DIO_voidSetPinValue(SEG3_PORT, SEG3_PIN5, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/100)%10],4));
//		DIO_voidSetPinValue(SEG3_PORT, SEG3_PIN6, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/100)%10],5));
//		DIO_voidSetPinValue(SEG3_PORT, SEG3_PIN7, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/100)%10],6));
//		DIO_voidSetPinValue(SEG3_PORT, SEG3_PIN8, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/100)%10],7));
//	#endif
//	#if((SEG_N_PORTS==SEG_FOUR)||(SEG_N_PORTS > SEG_FOUR))
//		    DIO_voidSetPinValue(SEG4_PORT, SEG4_PIN1, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/1000)%10],0));
//			DIO_voidSetPinValue(SEG4_PORT, SEG4_PIN2, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/1000)%10],1));
//			DIO_voidSetPinValue(SEG4_PORT, SEG4_PIN3, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/1000)%10],2));
//			DIO_voidSetPinValue(SEG4_PORT, SEG4_PIN4, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/1000)%10],3));
//			DIO_voidSetPinValue(SEG4_PORT, SEG4_PIN5, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/1000)%10],4));
//			DIO_voidSetPinValue(SEG4_PORT, SEG4_PIN6, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/1000)%10],5));
//			DIO_voidSetPinValue(SEG4_PORT, SEG4_PIN7, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/1000)%10],6));
//			DIO_voidSetPinValue(SEG4_PORT, SEG4_PIN8, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/1000)%10],7));
//	#endif
//}
//#endif
//normal hexadecimal
#elif ((SEG_MODE==SEG_NORMAL)&&(SEG_NUM_SYS==SEG_HEXADECIMAL))
//#if (SEG_TYBE_NUM==SEG_CHARACTER_NUM)
void SEG_Init(void)
{
	DIO_voidSetFirstHalfPortDirection(SEG1_PORT, DIO_OUTPUT_2MHZ_PP);
	DIO_voidSetFirstHalfPortDirection(SEG2_PORT, DIO_OUTPUT_2MHZ_PP);
}
void SEG_Display(u8 Copy_u8_Num)
{
	#if((SEG_N_PORTS==SEG_ONE)||(SEG_N_PORTS > SEG_ONE))
	DIO_voidSetFirstHalfPortValue(SEG1_PORT, SEG_Au8Numbers[(Copy_u8_Num)%16]);
	#endif
	#if((SEG_N_PORTS==SEG_TWO)||(SEG_N_PORTS > SEG_TWO))
	DIO_voidSetFirstHalfPortValue(SEG2_PORT, SEG_Au8Numbers[(Copy_u8_Num/16)%16]);
	#endif
}
//#endif
//#if (SEG_TYBE_NUM==SEG_INTEGER_NUM)
//void SEG_Display(u16 Copy_u16_Num)
//{
//#if((SEG_N_PORTS==SEG_ONE)||(SEG_N_PORTS > SEG_ONE))
//DIO_voidSetPinValue(SEG1_PORT, SEG1_PIN1, GET_BIT(SEG_Au8Numbers[Copy_u16_Num%16],0));
//DIO_voidSetPinValue(SEG1_PORT, SEG1_PIN2, GET_BIT(SEG_Au8Numbers[Copy_u16_Num%16],1));
//DIO_voidSetPinValue(SEG1_PORT, SEG1_PIN3, GET_BIT(SEG_Au8Numbers[Copy_u16_Num%16],2));
//DIO_voidSetPinValue(SEG1_PORT, SEG1_PIN4, GET_BIT(SEG_Au8Numbers[Copy_u16_Num%16],3));
//DIO_voidSetPinValue(SEG1_PORT, SEG1_PIN5, GET_BIT(SEG_Au8Numbers[Copy_u16_Num%16],4));
//DIO_voidSetPinValue(SEG1_PORT, SEG1_PIN6, GET_BIT(SEG_Au8Numbers[Copy_u16_Num%16],5));
//DIO_voidSetPinValue(SEG1_PORT, SEG1_PIN7, GET_BIT(SEG_Au8Numbers[Copy_u16_Num%16],6));
//DIO_voidSetPinValue(SEG1_PORT, SEG1_PIN8, GET_BIT(SEG_Au8Numbers[Copy_u16_Num%16],7));
//#endif
//#if((SEG_N_PORTS==SEG_TWO)||(SEG_N_PORTS > SEG_TWO))
//    DIO_voidSetPinValue(SEG2_PORT, SEG2_PIN1, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/16)%16],0));
//	DIO_voidSetPinValue(SEG2_PORT, SEG2_PIN2, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/16)%16],1));
//	DIO_voidSetPinValue(SEG2_PORT, SEG2_PIN3, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/16)%16],2));
//	DIO_voidSetPinValue(SEG2_PORT, SEG2_PIN4, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/16)%16],3));
//	DIO_voidSetPinValue(SEG2_PORT, SEG2_PIN5, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/16)%16],4));
//	DIO_voidSetPinValue(SEG2_PORT, SEG2_PIN6, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/16)%16],5));
//	DIO_voidSetPinValue(SEG2_PORT, SEG2_PIN7, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/16)%16],6));
//	DIO_voidSetPinValue(SEG2_PORT, SEG2_PIN8, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/16)%16],7));
//#endif
//#if((SEG_N_PORTS==SEG_THREE)||(SEG_N_PORTS > SEG_THREE))
//	DIO_voidSetPinValue(SEG3_PORT, SEG3_PIN1, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/256)%16],0));
//		DIO_voidSetPinValue(SEG3_PORT, SEG3_PIN2, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/256)%16],1));
//		DIO_voidSetPinValue(SEG3_PORT, SEG3_PIN3, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/256)%16],2));
//		DIO_voidSetPinValue(SEG3_PORT, SEG3_PIN4, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/256)%16],3));
//		DIO_voidSetPinValue(SEG3_PORT, SEG3_PIN5, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/256)%16],4));
//		DIO_voidSetPinValue(SEG3_PORT, SEG3_PIN6, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/256)%16],5));
//		DIO_voidSetPinValue(SEG3_PORT, SEG3_PIN7, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/256)%16],6));
//		DIO_voidSetPinValue(SEG3_PORT, SEG3_PIN8, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/256)%16],7));
//	#endif
//	#if((SEG_N_PORTS==SEG_FOUR)||(SEG_N_PORTS > SEG_FOUR))
//		    DIO_voidSetPinValue(SEG4_PORT, SEG4_PIN1, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/4096)%16],0));
//			DIO_voidSetPinValue(SEG4_PORT, SEG4_PIN2, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/4096)%16],1));
//			DIO_voidSetPinValue(SEG4_PORT, SEG4_PIN3, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/4096)%16],2));
//			DIO_voidSetPinValue(SEG4_PORT, SEG4_PIN4, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/4096)%16],3));
//			DIO_voidSetPinValue(SEG4_PORT, SEG4_PIN5, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/4096)%16],4));
//			DIO_voidSetPinValue(SEG4_PORT, SEG4_PIN6, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/4096)%16],5));
//			DIO_voidSetPinValue(SEG4_PORT, SEG4_PIN7, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/4096)%16],6));
//			DIO_voidSetPinValue(SEG4_PORT, SEG4_PIN8, GET_BIT(SEG_Au8Numbers[(Copy_u16_Num/4096)%16],7));
//	#endif
//}
//#endif
//normal binary
#elif ((SEG_MODE==SEG_NORMAL)&&(SEG_NUM_SYS==SEG_BINARY))
void SEG_Init(void)
{
	DIO_voidSetFirstHalfPortDirection(SEG1_PORT, DIO_OUTPUT_2MHZ_PP);
	DIO_voidSetFirstHalfPortDirection(SEG2_PORT, DIO_OUTPUT_2MHZ_PP);
}
void SEG_Display(u8 Copy_u8_Num)
{
#if((SEG_N_PORTS==SEG_ONE)||(SEG_N_PORTS > SEG_ONE))
	DIO_voidSetFirstHalfPortValue(SEG1_PORT, SEG_Au8Numbers[(Copy_u8_Num)%2]);
	#endif
	#if((SEG_N_PORTS==SEG_TWO)||(SEG_N_PORTS > SEG_TWO))
	DIO_voidSetFirstHalfPortValue(SEG2_PORT, SEG_Au8Numbers[(Copy_u8_Num/2)%2]);
	#endif
#if((SEG_N_PORTS==SEG_THREE)||(SEG_N_PORTS > SEG_THREE))
	DIO_voidSetFirstHalfPortValue(SEG3_PORT, SEG_Au8Numbers[(Copy_u8_Num/4)%2]);
	#endif
	#if((SEG_N_PORTS==SEG_FOUR)||(SEG_N_PORTS > SEG_FOUR))
	DIO_voidSetFirstHalfPortValue(SEG4_PORT, SEG_Au8Numbers[(Copy_u8_Num/8)%2]);
	#endif
}
//Multiplexing using 1 port decimal
#elif ((SEG_MODE==SEG_MULIPX)&&(SEG_NUM_SYS==SEG_DECIMAL))
void SEG_Init(void)
{
	DIO_voidSetFirstHalfPortDirection(SEG_PORT, DIO_OUTPUT_2MHZ_PP);

	DIO_voidSetPinDirection(SEG_PORT, SEG1_EN,DIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(SEG_PORT, SEG2_EN,DIO_OUTPUT_2MHZ_PP);
}
void SEG_Display(u8 Copy_u8_Num) {
	u16 i;
	for (i = 0; i < SEG_DISPLAY_TIME; i=i+1) {
		DIO_voidSetPinValue(SEG_PORT, SEG2_EN, DIO_U8_LOW);
	DIO_voidSetFirstHalfPortValue(SEG_PORT, SEG_Au8Numbers[(Copy_u8_Num)%10]<<1);
		DIO_voidSetPinValue(SEG_PORT, SEG1_EN, DIO_U8_HIGH);
		DELAY_mS(SEG_MULIPX_DELAY);
		DIO_voidSetPinValue(SEG_PORT, SEG1_EN, DIO_U8_LOW);
		DIO_voidSetFirstHalfPortValue(SEG_PORT, SEG_Au8Numbers[(Copy_u8_Num/10)%10]<<1);
		DIO_voidSetPinValue(SEG_PORT, SEG2_EN, DIO_U8_HIGH);
		DELAY_mS(SEG_MULIPX_DELAY);
	}
}
//Multiplexing using 1 port hexadecimal
#elif ((SEG_MODE==SEG_MULIPX)&&(SEG_NUM_SYS==SEG_HEXADECIMAL))
void SEG_Init(void)
{
	DIO_voidSetFirstHalfPortDirection(SEG_PORT, DIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(SEG_PORT, SEG1_EN,DIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(SEG_PORT, SEG2_EN,DIO_OUTPUT_2MHZ_PP);
}
void SEG_Display(u8 Copy_u8_Num)
{
	u16 i;
	for(i=0;i<SEG_DISPLAY_TIME;i++)
	{
		DIO_voidSetPinValue(SEG_PORT, SEG2_EN, DIO_U8_LOW);
		DIO_voidSetFirstHalfPortValue(SEG_PORT, SEG_Au8Numbers[(Copy_u8_Num)%16]<<1);

		DIO_voidSetPinValue(SEG_PORT, SEG1_EN, DIO_U8_HIGH);

		DELAY_mS(SEG_MULIPX_DELAY);

				DIO_voidSetPinValue(SEG_PORT, SEG1_EN, DIO_U8_LOW);

				DIO_voidSetFirstHalfPortValue(SEG_PORT, SEG_Au8Numbers[(Copy_u8_Num/16)%16]<<1);

			DIO_voidSetPinValue(SEG_PORT, SEG2_EN, DIO_U8_HIGH);
			DELAY_mS(SEG_MULIPX_DELAY);
	}

}
//Multiplexing using 1 port binary
#elif ((SEG_MODE==SEG_MULIPX)&&(SEG_NUM_SYS==SEG_BINARY))
void SEG_Init(void)
{
	DIO_voidSetFirstHalfPortDirection(SEG_PORT, DIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(SEG_PORT, SEG1_EN,DIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(SEG_PORT, SEG2_EN,DIO_OUTPUT_2MHZ_PP);
}
void SEG_Display(u8 Copy_u8_Num)
{
	u16 i;
	for(i=0;i<SEG_DISPLAY_TIME;i++)
	{
		DIO_voidSetPinValue(SEG_PORT, SEG2_EN, DIO_U8_LOW);
		DIO_voidSetFirstHalfPortValue(SEG_PORT, SEG_Au8Numbers[(Copy_u8_Num)%2]<<1);

		DIO_voidSetPinValue(SEG_PORT, SEG1_EN, DIO_U8_HIGH);

		DELAY_mS(SEG_MULIPX_DELAY);

				DIO_voidSetPinValue(SEG_PORT, SEG1_EN, DIO_U8_LOW);

				DIO_voidSetFirstHalfPortValue(SEG_PORT, SEG_Au8Numbers[(Copy_u8_Num/2)%2]<<1);

			DIO_voidSetPinValue(SEG_PORT, SEG2_EN, DIO_U8_HIGH);
			DELAY_mS(SEG_MULIPX_DELAY);
	}


}

//using 1 port to 2 BCD hexadecimal
#elif ((SEG_MODE==SEG_BCD)&&(SEG_NUM_SYS==SEG_HEXADECIMAL))
void SEG_Init(void)
{
	DIO_voidSetFirstHalfPortDirection(SEG_PORT, DIO_OUTPUT_2MHZ_PP);


}
void SEG_Display(u8 Copy_u8_Num)
{
	DIO_voidSetPinValue(SEG_PORT, SEG_PIN1, GET_BIT(Copy_u8_Num%16],0));
		DIO_voidSetPinValue(SEG_PORT, SEG_PIN2, GET_BIT(Copy_u8_Num%16],1));
		DIO_voidSetPinValue(SEG_PORT, SEG_PIN3, GET_BIT(Copy_u8_Num%16],2));
		DIO_voidSetPinValue(SEG_PORT, SEG_PIN4, GET_BIT(Copy_u8_Num%16],3));
		DIO_voidSetPinValue(SEG_PORT, SEG_PIN1, GET_BIT((Copy_u8_Num/16)%16],4));
		DIO_voidSetPinValue(SEG_PORT, SEG_PIN2, GET_BIT((Copy_u8_Num/16)%16],5));
		DIO_voidSetPinValue(SEG_PORT, SEG_PIN3, GET_BIT((Copy_u8_Num/16)%16],6));
		DIO_voidSetPinValue(SEG_PORT, SEG_PIN4, GET_BIT((Copy_u8_Num/16)%16],7));
}
//using 1 port to 2 BCD decimal
#elif ((SEG_MODE==SEG_BCD)&&(SEG_NUM_SYS==SEG_DECIMAL))
void SEG_Init(void)
{
	DIO_voidSetFirstHalfPortDirection(SEG_PORT, DIO_OUTPUT_2MHZ_PP);

}
void SEG_Display(u8 Copy_u8_Num)
{
	DIO_voidSetPinValue(SEG_PORT, SEG_PIN1, GET_BIT(Copy_u8_Num%10],0));
			DIO_voidSetPinValue(SEG_PORT, SEG_PIN2, GET_BIT(Copy_u8_Num%10],1));
			DIO_voidSetPinValue(SEG_PORT, SEG_PIN3, GET_BIT(Copy_u8_Num%10],2));
			DIO_voidSetPinValue(SEG_PORT, SEG_PIN4, GET_BIT(Copy_u8_Num%10],3));
			DIO_voidSetPinValue(SEG_PORT, SEG_PIN1, GET_BIT((Copy_u8_Num/10)%10],4));
			DIO_voidSetPinValue(SEG_PORT, SEG_PIN2, GET_BIT((Copy_u8_Num/10)%10],5));
			DIO_voidSetPinValue(SEG_PORT, SEG_PIN3, GET_BIT((Copy_u8_Num/10)%10],6));
			DIO_voidSetPinValue(SEG_PORT, SEG_PIN4, GET_BIT((Copy_u8_Num/10)%10],7));
}
//using 1 port to 2 BCD BINARY
#elif ((SEG_MODE==SEG_BCD)&&(SEG_NUM_SYS==SEG_BINARY))
void SEG_Init(void)
{
	DIO_voidSetFirstHalfPortDirection(SEG_PORT, DIO_OUTPUT_2MHZ_PP);

}
void SEG_Display(u8 Copy_u8_Num)
{
	DIO_voidSetPinValue(SEG_PORT, SEG_PIN1, GET_BIT(Copy_u8_Num%2],0));
				DIO_voidSetPinValue(SEG_PORT, SEG_PIN2, GET_BIT(Copy_u8_Num%2],1));
				DIO_voidSetPinValue(SEG_PORT, SEG_PIN3, GET_BIT(Copy_u8_Num%2],2));
				DIO_voidSetPinValue(SEG_PORT, SEG_PIN4, GET_BIT(Copy_u8_Num%2],3));
				DIO_voidSetPinValue(SEG_PORT, SEG_PIN1, GET_BIT((Copy_u8_Num/2)%2],4));
				DIO_voidSetPinValue(SEG_PORT, SEG_PIN2, GET_BIT((Copy_u8_Num/2)%2],5));
				DIO_voidSetPinValue(SEG_PORT, SEG_PIN3, GET_BIT((Copy_u8_Num/2)%2],6));
				DIO_voidSetPinValue(SEG_PORT, SEG_PIN4, GET_BIT((Copy_u8_Num/2)%2],7));
}
#endif
