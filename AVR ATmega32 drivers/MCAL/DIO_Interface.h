
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "MemMap.h"
#include "Utils.h"
#include "StdTypes.h"

typedef enum { OUTPUT,INFREE,INPLUP }DIO_PinStatus_type;
typedef enum { PA,PB,PC,PD }DIO_port_type;
typedef enum {LOW,HIGH}DIO_voltage_type;
typedef enum
{	PINA0,PINA1,PINA2,PINA3,PINA4,PINA5,PINA6,PINA7,
	PINB0,PINB1,PINB2,PINB3,PINB4,PINB5,PINB6,PINB7,
	PINC0,PINC1,PINC2,PINC3,PINC4,PINC5,PINC6,PINC7,
	PIND0,PIND1,PIND2,PIND3,PIND4,PIND5,PIND6,PIND7,
	TOTAL_PINS
}DIO_Pin_type;

void DIO_Init(void);
void DIO_InitPin(DIO_Pin_type pin,DIO_PinStatus_type status);
void DIO_WritePin(DIO_Pin_type pin,DIO_voltage_type volt);
DIO_voltage_type DIO_ReadPin(DIO_Pin_type pin);

void DIO_TogglePin(DIO_Pin_type pin);
void DIO_WritePort(DIO_port_type port,u8 data);
u8   DIO_ReadPort (DIO_port_type port);

#endif /* DIO_INTERFACE_H_ */