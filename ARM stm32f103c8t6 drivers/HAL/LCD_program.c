#include "StdTypes.h"
#include "Utils.h"

#include "GPIO_interface.h"
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_Config.h"

static void Delay_ms(u32 Copy_u32Time)
{
	for(u32 i=0; i<Copy_u32Time;i++)
		{
			for(u16 j=0;j<565;j++)
			{
				asm("NOP");
			}
		}

}

void LCD_WriteData(u8 data)
{

	DIO_WritePin(RS,HIGH);
	DIO_WritePin(D7,GET_BIT(data,7));
	DIO_WritePin(D6,GET_BIT(data,6));
	DIO_WritePin(D5,GET_BIT(data,5));
	DIO_WritePin(D4,GET_BIT(data,4));
	DIO_WritePin(EN,HIGH);
	Delay_ms(1);
	DIO_WritePin(EN,LOW);
	Delay_ms(1);
	DIO_WritePin(D7,GET_BIT(data,3));
	DIO_WritePin(D6,GET_BIT(data,2));
	DIO_WritePin(D5,GET_BIT(data,1));
	DIO_WritePin(D4,GET_BIT(data,0));
	DIO_WritePin(EN,HIGH);
	Delay_ms(1);
	DIO_WritePin(EN,LOW);
	Delay_ms(1);
}

void LCD_WriteCommand(u8 data)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePin(D7,GET_BIT(data,7));
	DIO_WritePin(D6,GET_BIT(data,6));
	DIO_WritePin(D5,GET_BIT(data,5));
	DIO_WritePin(D4,GET_BIT(data,4));
	DIO_WritePin(EN,HIGH);
	Delay_ms(1);
	DIO_WritePin(EN,LOW);
	Delay_ms(1);
	DIO_WritePin(D7,GET_BIT(data,3));
	DIO_WritePin(D6,GET_BIT(data,2));
	DIO_WritePin(D5,GET_BIT(data,1));
	DIO_WritePin(D4,GET_BIT(data,0));
	DIO_WritePin(EN,HIGH);
	Delay_ms(1);
	DIO_WritePin(EN,LOW);
	Delay_ms(1);

}
void LCD_Init(void)
{
	Delay_ms(50);
	LCD_WriteCommand(0x02);
	Delay_ms(50);
	LCD_WriteCommand(0x28);//8 bit mode ,font 5*7 , 2 line
	Delay_ms(1);
	LCD_WriteCommand(0x0c);//0x0f ,0x0e display ,cursor
	Delay_ms(1);
	LCD_WriteCommand(0x01);//Clear screen
	Delay_ms(2);
	LCD_WriteCommand(0x06);//increas ddram address no
	Delay_ms(2);

}

void LCD_WriteChar(u8 ch)
{
	LCD_WriteData(ch);
}
void LCD_WriteString(u8* str)
{
	u8 i=0;
	while(str[i]!=0)
	{

		LCD_WriteChar(str[i]);

		i++;

	}

}
void LCD_WriteNumber(s64 num)
{
	u8 ch[16]={0};
	u8 i=0;
	u8 j=0;
	if(num==0)
	{
		LCD_WriteChar('0');
	}
	else if(num>0)
	{
		while(num!=0)
		{
			ch[i]=num%10;
			num=num/10;
			i++;
		}
		for(j=i-1;j>=0;j--)
		{

			LCD_WriteChar(ch[j]+'0');
			if(j==0) break;
		}


	}
	else if(num<0)
	{
		LCD_WriteChar('-');
		num=num*(-1);
			while(num!=0)
			{
				ch[i]=num%10;
				num=num/10;
				i++;
			}
			for(j=i-1;j>=0;j--)
			{

				LCD_WriteChar(ch[j]+'0');
				if(j==0) break;
			}

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
	u8 hex[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','E','F'};
	u8 high=num>>4;
	u8 low=num&0x0f;
	LCD_WriteData(hex[high]);
	LCD_WriteData(hex[low]);
}

void LCD_WriteNumber_4D(u64 num)
{

		//LCD_WriteData((num/1000)+'0');
		//num=num%1000;
		LCD_WriteData((num/100)+'0');
		num=num%100;
		LCD_WriteData((num/10)+'0');
		num=num%10;
		LCD_WriteData((num/1)+'0');


}
void LCD_SetCursor(u8 row,u8 colm)
{
	if(row==0)
	{
		LCD_WriteCommand(0x80+colm);

	}
	else if(row==1)
	{

		LCD_WriteCommand(0x40+0x80+colm);
	}
}
void LCD_Clear(void)
{

	LCD_WriteCommand(0x01);
}

int string_lens(u8*str)
{
	u8 i;
	for(i=0; str[i]; i++);
	return i;
}

void LCD_CreateChar(Custom_Char_type patt,u8 location) // choose pattren and location in CGRAM
{
	u8 i;
	switch(patt)
	{
		case MAN:
			LCD_WriteCommand(0x40+(location * 8)); // goto CGRAM , location 0 then 40 , loc1 then 48 , etc: 1 location = 8 bytes as if pointer to 8 bytes
			for(i=0 ; i<8 ; i++){
				LCD_WriteData(Sadman_pattren[i]);}
				break;
		case HAPPY_MAN:
			LCD_WriteCommand(0x40+(location * 8)); // goto CGRAM , location 0 then 40 , loc1 then 48 , etc: 1 location = 8 bytes as if pointer to 8 bytes
			for(i=0;i<8;i++)
				LCD_WriteData(HappyMman_Pattern[i]);
			break;
		case DEAD_MAN_right:
				LCD_WriteCommand(0x40+(location * 8));
				for(i=0;i<8;i++)
					LCD_WriteData(dead_man_right_pattren[i]);
				break;
		case ARROW:
				LCD_WriteCommand(0x40+(location * 8));
				for(i=0;i<8;i++)
					LCD_WriteData(arrow_pattren[i]);
				break;
		case DAMAGE:
				LCD_WriteCommand(0x40+(location * 8));
				for(i=0;i<8;i++)
					LCD_WriteData(damage_pattren[i]);
				break;
		case  RECT:
			LCD_WriteCommand(0x40+(location * 8));
			for(i=0;i<8;i++)
				LCD_WriteData(rect_pattren[i]);
			break;
		case  KA:
			LCD_WriteCommand(0x40+(location * 8));
			for(i=0;i<8;i++)
				LCD_WriteData(Ka_pattren[i]);
			break;
		case  ALPH:
			LCD_WriteCommand(0x40+(location * 8));
			for(i=0;i<8;i++)
				LCD_WriteData(Aa_pattren[i]);
			break;
		case  NOON:
			LCD_WriteCommand(0x40+(location * 8));
			for(i=0;i<8;i++)
				LCD_WriteData(Noon_pattren[i]);
			break;
		case  SEEN:
			LCD_WriteCommand(0x40+(location * 8));
			for(i=0;i<8;i++)
				LCD_WriteData(Seen_pattren[i]);
			break;
		case  SHARTA:
			LCD_WriteCommand(0x40+(location * 8));
			for(i=0;i<8;i++)
				LCD_WriteData(Sharta_pattren[i]);
			break;
		case  A3een:
			LCD_WriteCommand(0x40+(location * 8));
			for(i=0;i<8;i++)
				LCD_WriteData(a3_pattren[i]);
			break;
		case  DAL:
			LCD_WriteCommand(0x40+(location * 8));
			for(i=0;i<8;i++)
				LCD_WriteData(Dal_pattren[i]);
			break;
		case  TAA:
			LCD_WriteCommand(0x40+(location * 8));
			for(i=0;i<8;i++)
				LCD_WriteData(Taa_pattren[i]);
			break;
		case  SMILE:
			LCD_WriteCommand(0x40+(location * 8));
			for(i=0;i<8;i++)
				LCD_WriteData(Smile_pattren[i]);
			break;
		case  MUSIC:
			LCD_WriteCommand(0x40+(location * 8));
			for(i=0;i<8;i++)
				LCD_WriteData(Music_pattren[i]);
			break;
		case  BILL:
			LCD_WriteCommand(0x40+(location * 8));
			for(i=0;i<8;i++)
				LCD_WriteData(Bill_pattren[i]);
			break;
		case  HEART:
			LCD_WriteCommand(0x40+(location * 8));
			for(i=0;i<8;i++)
				LCD_WriteData(Hreat_pattern[i]);
			break;
		case  HOLO_HART:
			LCD_WriteCommand(0x40+(location * 8));
			for(i=0;i<8;i++)
				LCD_WriteData(HoloHeart_pattren[i]);
			break;


	}
	LCD_WriteCommand(0x80);// return to DDRAM , then user can set corser as he like
}

void LCD_WriteCharXY (u8 row, u8 cell, u8 ch)
{
	LCD_SetCursor(row,cell);
	LCD_WriteChar(ch);
}
void LCD_WriteStringXY (u8 row, u8 cell, u8* str)
{
	LCD_SetCursor(row,cell);
	LCD_WriteString(str);
}
void LCD_WriteNumberXY (u8 row, u8 cell, s64 num)
{
	LCD_SetCursor(row,cell);
    LCD_WriteNumber(num);
}


