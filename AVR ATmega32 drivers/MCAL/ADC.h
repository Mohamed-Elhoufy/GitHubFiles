/*
 * ADC.h
 *
 * Created: 12/9/2020 10:25:03 AM
 *  Author: Amrth
 */ 


#ifndef ADC_H_
#define ADC_H_
#define F_CPU 8000000
#include "StdTypes.h"
#include "Utils.h"
#include "MemMap.h"
#include <util/delay.h>


typedef enum{VREF_AREF ,VREF_AVCC,VREF_256}ADC_Vref_type;
typedef enum{ADC_SCALER_2 ,ADC_SCALER_4,ADC_SCALER_8,ADC_SCALER_16,ADC_SCALER_32,ADC_SCALER_64,ADC_SCALER_128}ADC_Scaler_type;
typedef enum{CH0,CH1,CH2,CH3,CH4,CH5,CH6,CH7}ADC_Channel_type;

void ADC_Init(ADC_Vref_type vref,ADC_Scaler_type scaler);
u16  ADC_Read(ADC_Channel_type channel);
u16  ADC_Read_Percent(ADC_Channel_type channel);



#endif /* ADC_H_ */