#include "ADC.h"

void ADC_Init(ADC_Vref_type vref,ADC_Scaler_type scaler)      
{
	//scaler
	ADCSRA = (ADCSRA & 0xF8) | scaler;
	
	
	//ref
	switch(vref)
	{
		case VREF_AREF:
		CLR_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		break;
		
		case VREF_AVCC:
		SET_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		break;
		
		case VREF_256:
		SET_BIT(ADMUX,REFS0);
		SET_BIT(ADMUX,REFS1);
		break;
	}
	
	//start ADC
	SET_BIT(ADCSRA,ADEN);
}

u16  ADC_Read(ADC_Channel_type channel)
{
	u16 *buffer=&ADCL;
	ADMUX= (ADMUX & 0xE0) | channel;
	SET_BIT(ADCSRA,ADSC);
	while (GET_BIT(ADCSRA,ADSC));	
	//buffer= (((u16)ADCH<<8) | ADCL);
	return *buffer;
	// or
	 //u16 	
}


u16  ADC_Read_Percent(ADC_Channel_type channel)
{
	u16 ADCVal=ADC_Read(channel);
	u8 ADCPercent=((u32)ADCVal*100)/1023;
	return ADCPercent;
}