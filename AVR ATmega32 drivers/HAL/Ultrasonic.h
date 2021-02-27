/*
 * Ultrasonic.h
 *
 * Created: 12/21/2020 2:11:52 PM
 *  Author: Amrth
 */ 


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#define F_CPU 8000000
#include "DIO_Interface.h"
#include <util/delay.h>
#include "Timers.h"

#define US1   PINC7
#define US2   PINC6
#define US3   PINC5
#define US4   PINC4
#define Ultrasonic_Type			DIO_Pin_type

void ULTRASONIC_Init(void);
u16  ULTRASONIC_Read(Ultrasonic_Type  US);


#endif /* ULTRASONIC_H_ */