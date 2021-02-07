/*
 * KEYPAD_program.c
 *
 *  Created on: Feb 7, 2021
 *      Author: General
 */
#include "Includes_all.h"

u8 KEYPAD_Keys[4][4]={{'7','8','9','/'},
			   {'4','5','6','*'},
			   {'1','2','3','-'},
			   {'c','0','=','+'}};

extern volatile u8 Keypad_HOLD_FLAG=0;

void Keypad_Init(void)
{
            DIO_voidSetPinDirection(KEYPAD_INPUT_PORT, KEYPAD_INPUT_PIN1,DIO_INPUT_PULL_UP_DOWN);
			DIO_voidSetPinDirection(KEYPAD_INPUT_PORT, KEYPAD_INPUT_PIN2,DIO_INPUT_PULL_UP_DOWN);
			DIO_voidSetPinDirection(KEYPAD_INPUT_PORT, KEYPAD_INPUT_PIN3,DIO_INPUT_PULL_UP_DOWN);
			DIO_voidSetPinDirection(KEYPAD_INPUT_PORT, KEYPAD_INPUT_PIN4,DIO_INPUT_PULL_UP_DOWN);
	        DIO_voidSetPinDirection(KEYPAD_OUTPUT_PORT, KEYPAD_OUTPUT_PIN1,DIO_OUTPUT_2MHZ_PP);
			DIO_voidSetPinDirection(KEYPAD_OUTPUT_PORT, KEYPAD_OUTPUT_PIN2,DIO_OUTPUT_2MHZ_PP);
			DIO_voidSetPinDirection(KEYPAD_OUTPUT_PORT, KEYPAD_OUTPUT_PIN3,DIO_OUTPUT_2MHZ_PP);
			DIO_voidSetPinDirection(KEYPAD_OUTPUT_PORT, KEYPAD_OUTPUT_PIN4,DIO_OUTPUT_2MHZ_PP);
}
u8 Keypad_GetKey(void)
{
	u8 r,c,key=KEYPAD_DEFAULT_KEY;
	u16 hold=0;
	DIO_voidSetPinValue(KEYPAD_OUTPUT_PORT,KEYPAD_OUTPUT_PIN1,DIO_U8_HIGH);
	DIO_voidSetPinValue(KEYPAD_OUTPUT_PORT,KEYPAD_OUTPUT_PIN2,DIO_U8_HIGH);
	DIO_voidSetPinValue(KEYPAD_OUTPUT_PORT,KEYPAD_OUTPUT_PIN3,DIO_U8_HIGH);
	DIO_voidSetPinValue(KEYPAD_OUTPUT_PORT,KEYPAD_OUTPUT_PIN4,DIO_U8_HIGH);
		for (r=0;r<4;r++)
		{
			DIO_voidSetPinValue(KEYPAD_OUTPUT_PORT,KEYPAD_OUTPUT_PIN1+r,DIO_U8_LOW);
			for (c=0;c<4;c++)
			{
				if (!DIO_u8GetPinValue(KEYPAD_INPUT_PORT, KEYPAD_INPUT_PIN1+c))
				{
					key=KEYPAD_Keys[r][c];
					while ((!Keypad_HOLD_FLAG) && (!DIO_u8GetPinValue(KEYPAD_INPUT_PORT, KEYPAD_INPUT_PIN1+c)))
					{
						hold++;
						if (hold >1000)
						{
							Keypad_HOLD_FLAG=1;
							break;
						}
						DELAY_mS(1);

					}

				}
			}
			DIO_voidSetPinValue(KEYPAD_OUTPUT_PORT,KEYPAD_OUTPUT_PIN1+r,DIO_U8_HIGH);
		}

		if ((Keypad_HOLD_FLAG==1) && (key==KEYPAD_DEFAULT_KEY))
		{
			Keypad_HOLD_FLAG=0;
		}
		return key;
}
