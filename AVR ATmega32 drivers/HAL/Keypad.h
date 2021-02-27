/*
 * Keypad.h
 *
 * Created: 12/7/2020 9:57:28 AM
 *  Author: Amrth
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#define  F_CPU			8000000
#include "DIO_Interface.h"
#include "LCD.h"
#include <util/delay.h>

#define  FIRST_INPUT		PIND2
#define  FIRST_OUTPUT		PINB4
#define  DEFAULT_KEY		'.'
				
  
				   
u8 Keypad_GetKey(void);

#endif /* KEYPAD_H_ */