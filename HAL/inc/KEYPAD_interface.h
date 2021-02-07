/*
 * KEYPAD_interface.h
 *
 *  Created on: Feb 7, 2021
 *      Author: General
 */

#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#define  KEYPAD_INPUT_PORT       DIO_U8_PORTB
#define  KEYPAD_INPUT_PIN1		DIO_U8_PIN0
#define  KEYPAD_INPUT_PIN2		DIO_U8_PIN1
#define  KEYPAD_INPUT_PIN3		DIO_U8_PIN2
#define  KEYPAD_INPUT_PIN4		DIO_U8_PIN3
#define  KEYPAD_OUTPUT_PORT       DIO_U8_PORTB
#define  KEYPAD_OUTPUT_PIN1		DIO_U8_PIN4
#define  KEYPAD_OUTPUT_PIN2		DIO_U8_PIN5
#define  KEYPAD_OUTPUT_PIN3		DIO_U8_PIN6
#define  KEYPAD_OUTPUT_PIN4		DIO_U8_PIN7
#define  KEYPAD_DEFAULT_KEY		' '


void Keypad_Init(void);
u8 Keypad_GetKey(void);

#endif /* KEYPAD_INTERFACE_H_ */
