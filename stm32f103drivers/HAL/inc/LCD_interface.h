/*
 * LCD_interface.h
 *
 *  Created on: Feb 6, 2021
 *      Author: General
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_Init(void);
void LCD_WriteChar(u8 ch);
void LCD_WriteString(char* str);
void LCD_WriteNumber(s64 num);
void LCD_WriteNumber_4D(s16 num);
void LCD_WriteNumberBinary(u16 num);
void LCD_WriteNumberBinary_16D(u16 num);
void LCD_WriteNumberBinary_8D(u8 num);
void LCD_WriteNumberHex(u8 num);
void LCD_SetCursor(u8 line,u8 x);
void LCD_Clear(void);
void LCD_Create_Character(u8 *pattern,u8 location);

#endif /* LCD_INTERFACE_H_ */
