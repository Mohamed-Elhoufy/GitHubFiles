/*
 * RCC_program.c
 *
 *  Created on: Feb 2, 2021
 *      Author: Boon
 */


#include "Includes_all.h"


void RCC_voidInit(void)
{
	u32 Local_u32TimeOut = 0 ;
	#if(CLOCK_TYPE == RCC_HSI)
	/*		HSI ON							*/
			SET_BIT(RCC_CR,0);
	/*		HSI is Ready?	//POLLING		*/
		while((GET_BIT(RCC_CR , 1)) == 0 && Local_u32TimeOut != 10000)
		{
			Local_u32TimeOut++;
		}
	#elif(CLOCK_TYPE == RCC_HSE)
		/*		HSI ON							*/
				SET_BIT(RCC_CR,16);
		/*		System clock switch				*/
				SET_BIT(RCC_CFGR,0);
				CLR_BIT(RCC_CFGR,1);
		/*			HSE is Crystal or RC		*/
		#if		RCC_HSE_SOURCE	== RCC_CRYSTAL
				CLR_BIT(RCC_CR , 18);
		#elif	RCC_HSE_SOURCE	== RCC_RC
				SET_BIT(RCC_CR , 18);
		#endif
		/*		HSI is Ready?	//POLLING		*/
			while((GET_BIT(RCC_CR , 17)) == 0 && Local_u32TimeOut != 10000)
			{
				Local_u32TimeOut++;
			}
			/*		POLLING on SWS				*/
	#elif	CLOCK_TYPE == RCC_PLL

	#else
	       #error "Wrong clock system choice!"

	#endif
}
void RCC_voidEnablePeripheralClock(u8 Copy_u8BusID,u8 Copy_u8PeripheralID)
{
	/*	Range Check	*/
	if(Copy_u8PeripheralID < 32)
	{
		switch(Copy_u8BusID)
		{
			case RCC_AHB:	SET_BIT(RCC_AHBENR,Copy_u8PeripheralID);	break;
			case RCC_APB1:	SET_BIT(RCC_APB1ENR,Copy_u8PeripheralID);	break;
			case RCC_APB2:	SET_BIT(RCC_APB2ENR,Copy_u8PeripheralID);	break;
		}
	}
	else{/*		Return ERROR	*/}
}
void RCC_voidDisablePeripheralClock(u8 Copy_u8BusID,u8 Copy_u8PeripheralID)
{
	/*	Range Check	*/
	if(Copy_u8PeripheralID < 32)
	{
		switch(Copy_u8BusID)
		{
			case RCC_AHB:	CLR_BIT(RCC_AHBENR,Copy_u8PeripheralID);	break;
			case RCC_APB1:	CLR_BIT(RCC_APB1ENR,Copy_u8PeripheralID);		break;
			case RCC_APB2:	CLR_BIT(RCC_APB2ENR,Copy_u8PeripheralID);		break;
		}
	}
	else{/*		Return ERROR	*/}
}
