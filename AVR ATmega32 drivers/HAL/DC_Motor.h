/*
 * DC_Motor.h
 *
 * Created: 12/2/2020 1:40:29 PM
 *  Author: Amrth
 */ 


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#define  F_CPU 8000000
#include "DIO_Interface.h"
#include "Timers.h"
#include <util/delay.h>

#define  Motor1_P		PIND4
#define  Motor1_N		PIND5

//#define  Motor1_EN		PIND2
// #define  Motor2_EN		PIND3
// #define  Motor2_P		PIND4
// #define  Motor2_N		PIND5

typedef enum {Motor1,Motor2}Motor_Type;

void Motor_Init (void);
void Motor_CW   (Motor_Type Motor);
void Motor_CCW  (Motor_Type Motor);
void Motor_Stop (Motor_Type Motor);
void Motor_QuickStop (Motor_Type Motor);

/************ DC MOTOR PWM SPEED CONTROL **************/


#define PWM_FREQUENCY_kHz		20       /* Range 5kHz ~ 20kHz */
void Motor_SpeedControlInit(void);
void Motor_SetSpeed(u8 Percentage);


#endif /* DC_MOTOR_H_ */