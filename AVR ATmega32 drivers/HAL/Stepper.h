/*
 * Stepper.h
 *
 * Created: 08/12/2020 11:06:44 ص
 *  Author: lab126-00
 */ 


#ifndef STEPPER_H_
#define STEPPER_H_

#define  F_CPU     8000000
#include "DIO_Interface.h"
#include <util/delay.h>

#define COIL1_A		PINC0
#define COIL1_B		PINC1
#define COIL2_A		PINC2
#define COIL2_B		PINC3

#define DELAY		100

#define BLUE        PINB0
#define PURPLE      PINB1
#define YELLOW      PINB2
#define ORANGE      PINB3

void STEPPER_BiPolar_CW (void);
void STEPPER_BiPolar_CCW(void);

void STEPPER_UniPolar_CW (void);
void STEPPER_UniPolar_CCW (void);

void STEPPER_UniPolar_CW_Step (void);
void STEPPER_UniPolar_CCW_Step (void);
void STEPPER_UniPolar_Angle (s16 angle);
void STEPPER_UniPolar_Cycle (s16 cycle);

#endif /* STEPPER_H_ */