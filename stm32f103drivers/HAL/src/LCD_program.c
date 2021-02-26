/*
 * LCD_program.c
 *
 *  Created on: Feb 6, 2021
 *      Author: General
 */

#include "Includes_all.h"




#if (LCD_MODE==LCD_4BIT)
void LCD_WriteData(u8 data)
{
	DIO_voidSetPinValue(LCD_PORT, LCD_RS, DIO_U8_HIGH);
	DIO_voidSetPinValue(LCD_PORT,LCD_PIN4,GET_BIT(data,7));
	DIO_voidSetPinValue(LCD_PORT,LCD_PIN3,GET_BIT(data,6));
	DIO_voidSetPinValue(LCD_PORT,LCD_PIN2,GET_BIT(data,5));
	DIO_voidSetPinValue(LCD_PORT,LCD_PIN1,GET_BIT(data,4));
	DIO_voidSetPinValue(LCD_PORT,LCD_EN,DIO_U8_HIGH);
	DELAY_mS(2);
	DIO_voidSetPinValue(LCD_PORT,LCD_EN,DIO_U8_LOW);
	DELAY_mS(2);
	DIO_voidSetPinValue(LCD_PORT,LCD_PIN4,GET_BIT(data,3));
	DIO_voidSetPinValue(LCD_PORT,LCD_PIN3,GET_BIT(data,2));
	DIO_voidSetPinValue(LCD_PORT,LCD_PIN2,GET_BIT(data,1));
	DIO_voidSetPinValue(LCD_PORT,LCD_PIN1,GET_BIT(data,0));
	DIO_voidSetPinValue(LCD_PORT,LCD_EN,DIO_U8_HIGH);
	DELAY_mS(2);
	DIO_voidSetPinValue(LCD_PORT,LCD_EN,DIO_U8_LOW);
	DELAY_mS(2);
}
void LCD_WriteCommand(u8 command)
{
	DIO_voidSetPinValue(LCD_PORT,LCD_RS,DIO_U8_LOW);
	DIO_voidSetPinValue(LCD_PORT,LCD_PIN4,GET_BIT(command,7));
	DIO_voidSetPinValue(LCD_PORT,LCD_PIN3,GET_BIT(command,6));
	DIO_voidSetPinValue(LCD_PORT,LCD_PIN2,GET_BIT(command,5));
	DIO_voidSetPinValue(LCD_PORT,LCD_PIN1,GET_BIT(command,4));
	DIO_voidSetPinValue(LCD_PORT,LCD_EN,DIO_U8_HIGH);
	DELAY_mS(2);
	DIO_voidSetPinValue(LCD_PORT,LCD_EN,DIO_U8_LOW);
	DELAY_mS(2);
	DIO_voidSetPinValue(LCD_PORT,LCD_PIN4,GET_BIT(command,3));
	DIO_voidSetPinValue(LCD_PORT,LCD_PIN3,GET_BIT(command,2));
	DIO_voidSetPinValue(LCD_PORT,LCD_PIN2,GET_BIT(command,1));
	DIO_voidSetPinValue(LCD_PORT,LCD_PIN1,GET_BIT(command,0));
	DIO_voidSetPinValue(LCD_PORT,LCD_EN,DIO_U8_HIGH);
	DELAY_mS(2);
	DIO_voidSetPinValue(LCD_PORT,LCD_EN,DIO_U8_LOW);
	DELAY_mS(2);
}
void LCD_Init(void)
{
	    DIO_voidSetPinDirection(LCD_PORT, LCD_PIN1,DIO_OUTPUT_2MHZ_PP);
		DIO_voidSetPinDirection(LCD_PORT, LCD_PIN2,DIO_OUTPUT_2MHZ_PP);
		DIO_voidSetPinDirection(LCD_PORT, LCD_PIN3,DIO_OUTPUT_2MHZ_PP);
		DIO_voidSetPinDirection(LCD_PORT, LCD_PIN4,DIO_OUTPUT_2MHZ_PP);

		DIO_voidSetPinDirection(LCD_PORT, LCD_RS,DIO_OUTPUT_2MHZ_PP);
		DIO_voidSetPinDirection(LCD_PORT, LCD_EN,DIO_OUTPUT_2MHZ_PP);
		DELAY_mS(100);
	LCD_WriteCommand(0x02); //bit mode,fonts5*7,2 lines
	DELAY_mS(2);
	LCD_WriteCommand(0x28); //bit mode,fonts5*7,2 lines
	DELAY_mS(2);
	LCD_WriteCommand(0x0c); //0x0f,0x0e display , cursor
	DELAY_mS(2);
	LCD_WriteCommand(0x01); //clear screen
	DELAY_mS(4);
	LCD_WriteCommand(0x06); //increase DDRAM Address,no shift
	DELAY_mS(2);
}
#elif (LCD_MODE==LCD_8BIT)
void LCD_WriteData(u8 data)
{
	DIO_voidSetPinValue(LCD_PORT,LCD_RS,DIO_U8_HIGH);
	DIO_voidSetPinValue(LCD_PORT,LCD_PIN8,GET_BIT(data,7));
	DIO_voidSetPinValue(LCD_PORT,LCD_PIN7,GET_BIT(data,6));
	DIO_voidSetPinValue(LCD_PORT,LCD_PIN6,GET_BIT(data,5));
	DIO_voidSetPinValue(LCD_PORT,LCD_PIN5,GET_BIT(data,4));
	DIO_voidSetPinValue(LCD_PORT,LCD_PIN4,GET_BIT(data,3));
	DIO_voidSetPinValue(LCD_PORT,LCD_PIN3,GET_BIT(data,2));
	DIO_voidSetPinValue(LCD_PORT,LCD_PIN2,GET_BIT(data,1));
	DIO_voidSetPinValue(LCD_PORT,LCD_PIN1,GET_BIT(data,0));
	DIO_voidSetPinValue(LCD_PORT,LCD_EN,DIO_U8_HIGH);
		DELAY_mS(1);
		DIO_voidSetPinValue(LCD_PORT,LCD_EN,DIO_U8_LOW);
		DELAY_mS(1);
}
void LCD_WriteCommand(u8 command)
{
	    DIO_WritePin(LCD_RS,LOW);
	    DIO_voidSetPinValue(LCD_PORT,LCD_PIN8,GET_BIT(command,7));
		DIO_voidSetPinValue(LCD_PORT,LCD_PIN7,GET_BIT(command,6));
		DIO_voidSetPinValue(LCD_PORT,LCD_PIN6,GET_BIT(command,5));
		DIO_voidSetPinValue(LCD_PORT,LCD_PIN5,GET_BIT(command,4));
		DIO_voidSetPinValue(LCD_PORT,LCD_PIN4,GET_BIT(command,3));
		DIO_voidSetPinValue(LCD_PORT,LCD_PIN3,GET_BIT(command,2));
		DIO_voidSetPinValue(LCD_PORT,LCD_PIN2,GET_BIT(command,1));
		DIO_voidSetPinValue(LCD_PORT,LCD_PIN1,GET_BIT(command,0));
		DIO_voidSetPinValue(LCD_PORT,LCD_EN,DIO_U8_HIGH);
				DELAY_mS(1);
				DIO_voidSetPinValue(LCD_PORT,LCD_EN,DIO_U8_LOW);
				DELAY_mS(1);
}
void LCD_Init(void)
{
	DIO_voidSetPinDirection(LCD_PORT, LCD_PIN1,DIO_OUTPUT_2MHZ_PP);
			DIO_voidSetPinDirection(LCD_PORT, LCD_PIN2,DIO_OUTPUT_2MHZ_PP);
			DIO_voidSetPinDirection(LCD_PORT, LCD_PIN3,DIO_OUTPUT_2MHZ_PP);
			DIO_voidSetPinDirection(LCD_PORT, LCD_PIN4,DIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(LCD_PORT, LCD_PIN5,DIO_OUTPUT_2MHZ_PP);
			DIO_voidSetPinDirection(LCD_PORT, LCD_PIN6,DIO_OUTPUT_2MHZ_PP);
			DIO_voidSetPinDirection(LCD_PORT, LCD_PIN7,DIO_OUTPUT_2MHZ_PP);
			DIO_voidSetPinDirection(LCD_PORT, LCD_PIN8,DIO_OUTPUT_2MHZ_PP);
	DELAY_mS(50);
LCD_WriteCommand(0x38); //bit mode,fonts5*7,2 lines
DELAY_mS(1);
LCD_WriteCommand(0x0c); //0x0f,0x0e display , cursor
DELAY_mS(1);
LCD_WriteCommand(0x01); //clear screen
DELAY_mS(2);
LCD_WriteCommand(0x06); //increase DDRAM Address,no shift
DELAY_mS(1);
}
#endif

void LCD_WriteChar(u8 ch)
{
	LCD_WriteData(ch);
}

void LCD_WriteString(char* str)
{
	u8 i;
	for (i=0;str[i];i++)
	{
		LCD_WriteData(str[i]);
	}

}

void LCD_WriteNumber(s64 num)
{
	u8 j,i;
	s8 str[20]={0};

	if (num==0)
	{
		LCD_WriteData('0');
		return;
	}
	if (num<0)
	{
		LCD_WriteData('-');
		num=num*(-1);
	}
	for (i=0;num>0;i++)
	{
		str[i]=num%10+'0';
		num=num/10;
	}
	for (j=i;j>0;j--)
	{
		LCD_WriteData(str[j-1]);
	}
}
void LCD_WriteNumber_4D(s16 num)
{
	s8 i;
	u16 x=1000;
	if (num==0)
	{
		LCD_WriteString("0000");
		return;
	}
	if (num<0)
	{
		LCD_WriteData('-');
		num=num*(-1);
	}

	for (i=3;i>=0;i--)
	{
		LCD_WriteData(((num%(10*x))/x)+'0');
		x=x/10;
	}
}

void LCD_WriteNumberBinary(u16 num)
{
	s8 i,flag=0;
	for (i=15;i>=0;i--)
	{
		if (GET_BIT(num,i))
		{
			LCD_WriteData('1');
			flag=1;
		}
		else if(flag==1)
		{
			LCD_WriteData('0');
		}
	}
}

void LCD_WriteNumberBinary_16D(u16 num)
{
	s8 i;
	for (i=15;i>=0;i--)
	{
		if (GET_BIT(num,i))
		{
			LCD_WriteData('1');
		}
		else
		{
			LCD_WriteData('0');
		}
	}
}
void LCD_WriteNumberBinary_8D(u8 num)
{
	s8 i;
	for (i=7;i>=0;i--)
	{
		if (GET_BIT(num,i))
		{
			LCD_WriteData('1');
		}
		else
		{
			LCD_WriteData('0');
		}
	}
}

void LCD_WriteNumberHex(u8 num)//11110001
{
	u8 hex[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	u8 high=num>>4;
	u8 low=num&0x0f;
	LCD_WriteData(hex[high]);
	LCD_WriteData(hex[low]);
}

void LCD_SetCursor(u8 line,u8 x)
{
	if(line==0)
	{
	LCD_WriteCommand(0x80+x);  //10001111
	}
	else if (line==1)
	{
	LCD_WriteCommand(0x80+0x40+x);
	}

}
void LCD_Clear(void)
{
	LCD_WriteCommand(0x01);
}

void LCD_Create_Character(u8 *pattern,u8 location)
{
	u8 i=0;
	LCD_WriteCommand((0x40+(location*8)));
	for(i=0;i<8;i++)
	{
		LCD_WriteData(pattern[i]);
	}
	LCD_WriteCommand(0x80);
}

