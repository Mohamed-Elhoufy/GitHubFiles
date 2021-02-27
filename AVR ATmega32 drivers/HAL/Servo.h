/*
 * Servo.h
 *
 * Created: 12/23/2020 1:08:35 AM
 *  Author: Amrth
 */ 


#ifndef SERVO_H_
#define SERVO_H_
#include "Timers.h"

#define START_ANGLE			0
#define End_ANGLE			180

void servo_Init(void);
u8 servo_SetAngle(s16 angle);





#endif /* SERVO_H_ */