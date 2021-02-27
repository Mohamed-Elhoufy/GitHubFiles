#include "LCD.h"



void LCD_WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	
	#if LCD_MODE==8-BIT
	
	DIO_WritePort(LCD_PORT,data);
	
	#elif	LCD_MODE==4-BIT
	
	DIO_WritePin(D4,GET_BIT(data,4));
	DIO_WritePin(D5,GET_BIT(data,5));
	DIO_WritePin(D6,GET_BIT(data,6));
	DIO_WritePin(D7,GET_BIT(data,7));
	
	DIO_WritePin(E,HIGH);
	_delay_ms(1);
	DIO_WritePin(E,LOW);
	_delay_ms(1);
	DIO_WritePin(D4,GET_BIT(data,0));
	DIO_WritePin(D5,GET_BIT(data,1));
	DIO_WritePin(D6,GET_BIT(data,2));
	DIO_WritePin(D7,GET_BIT(data,3));
	
	#endif

	DIO_WritePin(E,HIGH);
	_delay_ms(1);
	DIO_WritePin(E,LOW);
	_delay_ms(1);
}



void LCD_WriteCommand(u8 command)
{
	DIO_WritePin(RS,LOW);
	
	#if LCD_MODE==8-BIT
	
	DIO_WritePort(LCD_PORT,command);
	
	#elif	LCD_MODE==4-BIT
	
	DIO_WritePin(D4,GET_BIT(command,4));
	DIO_WritePin(D5,GET_BIT(command,5));
	DIO_WritePin(D6,GET_BIT(command,6));
	DIO_WritePin(D7,GET_BIT(command,7));
		
	DIO_WritePin(E,HIGH);
	_delay_ms(1);
	DIO_WritePin(E,LOW);
	_delay_ms(1);
	DIO_WritePin(D4,GET_BIT(command,0));
	DIO_WritePin(D5,GET_BIT(command,1));
	DIO_WritePin(D6,GET_BIT(command,2));
	DIO_WritePin(D7,GET_BIT(command,3));
	
	#endif

	DIO_WritePin(E,HIGH);
	_delay_ms(1);
	DIO_WritePin(E,LOW);
	_delay_ms(1);
}




void LCD_Init(void)
{
	_delay_ms(50);
	
	#if LCD_MODE==8-BIT
	
	LCD_WriteCommand(0x38);			//8BIT mode - 5x7 font - 2 lines
	
	#elif	LCD_MODE==4-BIT
	
	LCD_WriteCommand(0x02);
	LCD_WriteCommand(0x28);        //4BIT mode - 5x7 font -2 lines
	
	#endif
	
	_delay_ms(1);
	LCD_WriteCommand(0x0C);			//Display on - Cursor off									//0x0F - 0x0E
	_delay_ms(1);
	LCD_WriteCommand(0x01);			//Clear LCD
	_delay_ms(2);
	LCD_WriteCommand(0x06);			//Increase DDRAM, no shift
	_delay_ms(1);
	
	
}



/*************************************************************************************************/
void LCD_ClearScreen(void)
{
	LCD_WriteCommand(0x01);
}


void LCD_SetCursor(u8 line,u8 cell)
{
	if (line==1)		LCD_WriteCommand(0x80+0x40+cell);
	else                LCD_WriteCommand(0x80+cell);
}


void LCD_WriteChar(u8 ch)
{
	LCD_WriteData(ch);
}

void LCD_WriteCharXY (u8 row, u8 cell, u8 ch)
{
	LCD_SetCursor(row,cell);
	LCD_WriteChar(ch);
}

void LCD_WriteString (u8* str)
{
	u8 i;
	for (i=0;str[i];i++)
	{
		LCD_WriteChar(str[i]);
	}
}


void LCD_WriteStringXY (u8 row, u8 cell, u8* str)
{
	LCD_SetCursor(row,cell);
	LCD_WriteString(str);
}


void LCD_WriteNum (s64 num)
{
	u64 digit=1;
	u64 temp;
	if (num<0)
	{
		LCD_WriteChar('-');
		num*= -1;
	}
	else if(num==0)
	{
		LCD_WriteChar('0');
		return;
	}
	
	temp=num;
	while (temp>0)	
	{
		temp/=10;
		digit*=10;
		
	}
	while(digit>1)
	{
		digit/=10;
		LCD_WriteChar((((num/digit)%10)+'0'));
	}
}


void LCD_WriteNumXY (u8 row, u8 cell, s64 num)
{
	LCD_SetCursor(row,cell);
	LCD_WriteNum(num);
}

/*
// void LCD_WriteNumFixed (s64 num,u8 digits)
// {
// 	s64 inv_num=0;
// 	
// 	for (int i=0;i<digits;i++)
// 	{
// 		inv_num=num%10;
// 		inv_num*=10;
// 		num/=10;
// 	}
// 	LCD_WriteNum(inv_num);
// 	while (inv_num>0)
// 	{
// 		LCD_WriteChar(inv_num%10 + '0');
// 		inv_num/=10;
// 	}
// }
*/

void LCD_WriteBinary (s16 num)
{
	u8 flag=0;
	for (int i=0;i<16;i++)
	{
		if (GET_BIT(num,16))
		{
			LCD_WriteNum(GET_BIT(num,16));
			flag++;
		}
		else if (flag>0)
		{
			LCD_WriteNum(GET_BIT(num,16));
		}
		num<<=1;
	}
}

void LCD_WriteBinary_8D (s8 num)
{
	for (int i=0;i<8;i++)
	{
		LCD_WriteNum(GET_BIT(num,16));
		num<<=1;
	}
}

void LCD_WriteHex (s64 num)
{
	u8 hex_temp,x=16;
	for (int i=0;i<16;i++)
	{
		x--;
		hex_temp=((num>>(4*x)) & 0x0F);
		if (hex_temp>9)			LCD_WriteChar((hex_temp-10)+'A');
		else                    LCD_WriteChar(hex_temp+'0');
	}
}

/********************************** Dead Man Task ************************************************/


void LCD_AddCustomSymbol(const u8 *symbol)
{
	static u8 char_ID=0;
	if(char_ID <= 0x4F)
	{
		LCD_WriteCommand(0x48+char_ID);
		for (u8 i=0;i<8;i++)
		{
			LCD_WriteData(symbol[i]);
		}
		LCD_SetCursor(0,0);
		char_ID+=8;
	}
}


