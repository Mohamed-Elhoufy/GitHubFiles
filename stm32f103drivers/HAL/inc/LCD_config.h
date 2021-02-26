/*
 * LCD_config.h
 *
 *  Created on: Feb 6, 2021
 *      Author: General
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/*********************** config LCD *****************************/
#define LCD_4BIT 4
#define LCD_8BIT 8
#define LCD_MODE LCD_4BIT
/*********************** Port config *****************/
#define LCD_PORT DIO_U8_PORTA
/*********************** Port config *****************/
#if(LCD_MODE==LCD_4BIT)
#define LCD_RS DIO_U8_PIN1
#define LCD_EN DIO_U8_PIN2
#define LCD_PIN1 DIO_U8_PIN3
#define LCD_PIN2 DIO_U8_PIN4
#define LCD_PIN3 DIO_U8_PIN5
#define LCD_PIN4 DIO_U8_PIN6
#endif
#if(LCD_MODE==LCD_8BIT)
#define LCD_RS DIO_U8_PIN8
#define LCD_EN DIO_U8_PIN9
#define LCD_PIN1 DIO_U8_PIN0
#define LCD_PIN2 DIO_U8_PIN1
#define LCD_PIN3 DIO_U8_PIN2
#define LCD_PIN4 DIO_U8_PIN3
#define LCD_PIN5 DIO_U8_PIN4
#define LCD_PIN6 DIO_U8_PIN5
#define LCD_PIN7 DIO_U8_PIN6
#define LCD_PIN8 DIO_U8_PIN7
#endif


/***************************************************/


#endif /* LCD_CONFIG_H_ */
