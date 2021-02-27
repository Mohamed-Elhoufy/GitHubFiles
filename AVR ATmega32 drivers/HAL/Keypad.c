#include  "Keypad.h"

u8 Keys[4][4]={{'1','2','3','D'},
			   {'4','5','6','F'},
			   {'7','8','9','L'},
			   {'A','B','C','E'}};
				   
extern volatile u8 Keypad_HOLD_FLAG=0; 				   
				
u8 Keypad_GetKey(void)
{
	u8 r,c,key=DEFAULT_KEY;
	u16 hold=0;
	DIO_WritePin(FIRST_OUTPUT,HIGH);
	DIO_WritePin(FIRST_OUTPUT+1,HIGH);
	DIO_WritePin(FIRST_OUTPUT+2,HIGH);
	DIO_WritePin(FIRST_OUTPUT+3,HIGH);
		for (r=0;r<4;r++)
		{
			DIO_WritePin(FIRST_OUTPUT+r,LOW);
			for (c=0;c<4;c++)
			{
				if (!DIO_ReadPin(FIRST_INPUT+c))
				{
					key=Keys[r][c];
					while ((!Keypad_HOLD_FLAG) && (!DIO_ReadPin(FIRST_INPUT+c)))
					{
						hold++;
						if (hold >1000)
						{
							Keypad_HOLD_FLAG=1;
							break;	
						}
						_delay_ms(1);
							
					}
					
				}
			}
			DIO_WritePin(FIRST_OUTPUT+r,HIGH);
		}
		
		if ((Keypad_HOLD_FLAG==1) && (key==DEFAULT_KEY))
		{
			Keypad_HOLD_FLAG=0;
		}
		return key;
}