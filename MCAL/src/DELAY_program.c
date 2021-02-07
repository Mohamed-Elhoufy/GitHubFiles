/*
 * DELAY_program.c
 *
 *  Created on: Feb 6, 2021
 *      Author: General
 */

#include "Includes_all.h"


void DELAY_mS(u32 Copy_u32Time)
{
	for(u32 i=0 ; i<Copy_u32Time ; i++ )
	{
		for(u16 j=0; j<565; j++)
		{
			asm("NOP");
		}
	}
}
void DELAY_uS(u32 Copy_u32Time)
{
	for(u32 i=0 ; i<Copy_u32Time ; i++ )
	{
			asm("NOP");
	}
}
