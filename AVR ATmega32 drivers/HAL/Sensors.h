/*
 * Sensors.h
 *
 * Created: 12/9/2020 10:41:55 PM
 *  Author: Amrth
 */ 


#ifndef SENSORS_H_
#define SENSORS_H_

#include "ADC.h"	 

void Sensors_Init(void);

/*************** Volt *******************/
#define POT_CH			CH0
u32 POT_VoltRead(void);
u32 POT_VoltReadPercent(void);

/**************** LDR *******************/
#define LDR_CH			CH0

u16  LDR_GetLux (void);

/**************** LM35 ******************/

#define LM35_CH		CH0

u32  LM35_GetTemp (void);

/************** PMX4115 ****************/

#define PMX4115_CH		CH0

u16 PMX4115_ReadPressure (void);


#endif /* SENSORS_H_ */