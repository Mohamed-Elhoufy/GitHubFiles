/*
 * LCD_Config.h
 *
 *  Created on: Feb 9, 2021
 *      Author: Mohamed Allam
 */

#ifndef LCD_HEADERS_LCD_CONFIG_H_
#define LCD_HEADERS_LCD_CONFIG_H_

/*************************************************************************
 * LCD MODE can be   NAPLE   if LCD is connected via 4 data Leads(D4:D7) *
 * either it can be   BYTE   if LCD is connected via 8 data Leads(D0:D7) *
 * 																		 *
 * ***********************************************************************
 */




#define  RS    PINA2
#define  EN    PINA3

#define CURSER_SPEED 200



#define D4 PINA4
#define D5 PINA5
#define D6 PINA6
#define D7 PINA7
/***************************END*****************************************************/



#endif /* LCD_HEADERS_LCD_CONFIG_H_ */
