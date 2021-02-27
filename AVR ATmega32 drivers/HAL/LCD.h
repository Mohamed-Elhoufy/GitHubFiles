/*
 * LCD.h
 *
 * Created: 12/3/2020 10:13:36 AM
 *  Author: Amr Mohamed
 */ 


#ifndef LCD_H_
#define LCD_H_

#define F_CPU   8000000
#include "DIO_Interface.h"
#include <util/delay.h>

#define LCD_MODE		4-BIT				//OPERATION MODE	(4-BIT/8-BIT)

#define E			PINA2
#define RS			PINA1

#if LCD_MODE==8-BIT

#define	LCD_PORT	PA

#elif LCD_MODE==4-BIT

#define D4	PINA3
#define D5	PINA4
#define D6	PINA5
#define D7	PINA6

#endif

	
	
void LCD_Init(void);
void LCD_WriteChar(u8 ch);
void LCD_WriteCharXY (u8 row, u8 cell, u8 ch);
void LCD_WriteString (u8* str);
void LCD_WriteStringXY (u8 row, u8 cell, u8* str);
void LCD_WriteNum (s64 num);
void LCD_WriteNumXY (u8 row, u8 cell, s64 num);
void LCD_WriteNumFixed (s64 num,u8 digits);
void LCD_WriteBinary (s16 num);
void LCD_WriteBinary_8D (s8 num);
void LCD_WriteHex (s64 num);
void LCD_SetCursor(u8 line,u8 cell);
void LCD_ClearScreen(void);
void LCD_AddCustomSymbol(const u8 *symbol);

#endif /* LCD_H_ */