#include "Sensors.h"

void Sensors_Init(void)
{
	ADC_Init(VREF_AVCC,ADC_SCALER_64);
}

/*************** Volt *******************/

u32 POT_VoltRead(void)
{
	u32 buffer=ADC_Read(POT_CH);
	buffer=(((buffer * 5000)/1024));        /*Change range from 0~1024 to 0~5000mv*/
	return buffer;
}

u32 POT_VoltReadPercent(void)
{
	u64 buffer=ADC_Read(POT_CH);
	buffer=((buffer*100)/1023);
	//buffer=(((buffer * 5000)/1024));        /*Change range from 0~1024 to 0~5000mv*/
	return buffer;
}

/**************** LDR *******************/

u16  LDR_GetLux (void)
{
	u32 Light=ADC_Read(LDR_CH);
	Light=((Light*5000)/1024);        /*Change range from 0~1024 to 0~5000mv*/
	return Light;
}

/**************** LM35 ******************/

u32 LM35_GetTemp(void)
{
	u32 buffer=ADC_Read(LM35_CH);
	buffer=(((buffer * 5000)/1024));        /*Change range from 0~1024 to 0~5000mv*/
	//u32 temp=buffer/10;
	return buffer;
}


/************** PMX4115 ****************/

#define PMX4115_CH		CH0
#define ACCURACY		1000000
#define DECIMAL_VAL		100

u16 PMX4115_ReadPressure(void)
{
	u16 ADCVal,pressure;
	const u64 slope_p=(((115-15)*ACCURACY)/(976-55));
	ADCVal=ADC_Read(PMX4115_CH);
	pressure=(((slope_p*(ADCVal-55))/(ACCURACY/DECIMAL_VAL))+15*DECIMAL_VAL);
	
	if (pressure%10>=5)		pressure+=(10-(pressure%10));
	else                    pressure-=(pressure%10);
	pressure/=10;
	
	return pressure;
} 