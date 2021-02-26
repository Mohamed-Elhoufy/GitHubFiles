

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_


typedef enum{
	DIO_E_INPUT_ANALOG          = 0b0000  	    ,
	DIO_E_INPUT_FLOATING        = 0b0100 	    ,
	DIO_E_INPUT_PULL_UP      	= 0b1000  	    ,
	DIO_E_INPUT_PULL_DOWN       = 0b10001111    ,
	DIO_E_OUTPUT_2MHZ_PUSH      = 0b0010	    ,
	DIO_E_OUTPUT_2MHZ_PULL   	= 0b00101111    ,
	DIO_E_OUTPUT_2MHZ_OD	    = 0b0110    	,
	DIO_E_OUTPUT_2MHZ_AF_PP     = 0b1010        ,
	DIO_E_OUTPUT_2MHZ_AF_OD		= 0b1110        ,
	DIO_E_OUTPUT_10MHZ_PUSH		= 0b0001		,
	DIO_E_OUTPUT_10MHZ_PULL		= 0b00011111	,
	DIO_E_OUTPUT_10MHZ_OD		= 0b0101		,
	DIO_E_OUTPUT_10MHZ_AF_PP	= 0b1001		,
	DIO_E_OUTPUT_10MHZ_AF_OD	= 0b1101		,
	DIO_E_OUTPUT_50MHZ_PUSH		= 0b0011		,
	DIO_E_OUTPUT_50MHZ_PULL		= 0b00111111	,
	DIO_E_OUTPUT_50MHZ_OD		= 0b0111		,
	DIO_E_OUTPUT_50MHZ_AF_PP	= 0b1011		,
	DIO_E_OUTPUT_50MHZ_AF_OD	= 0b1111    	,
}DIO_PinStatus_type;
typedef enum{
	DIO_PORTA=0,
	DIO_PORTB,
	DIO_PORTC,
}DIO_Port_type;

typedef enum
{
	LOW=0,
	HIGH
}DIO_Voltage_type;


typedef enum
{
	PINA0=0,
	PINA1=1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
	PINA7,
	PINA8,
	PINA9,
	PINA10,
	PINA11,
	PINA12,
	PINA13,
	PINA14,
	PINA15,
	PINB0,
	PINB1,
	PINB2,
	PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7,
	PINB8,
	PINB9,
	PINB10,
	PINB11,
	PINB12,
	PINB13,
	PINB14,
	PINB15,
	PINC0,
	PINC1,
	PINC2,
	PINC3,
	PINC4,
	PINC5,
	PINC6,
	PINC7,
	PINC8,
	PINC9,
	PINC10,
	PINC11,
	PINC12,
	PINC13,
	PINC14,
	PINC15,
	TOTAL_PINS
}DIO_Pin_type;


void DIO_InitPin(DIO_Pin_type pin,DIO_PinStatus_type status);
void DIO_WritePin(DIO_Pin_type pin,DIO_Voltage_type volt);

DIO_Voltage_type DIO_ReadPin(DIO_Pin_type pin);
void DIO_TogglePin(DIO_Pin_type pin);
void DIO_WritePort(DIO_Port_type port,u16 data);
u16 DIO_ReadPort(DIO_Port_type port);
void DIO_Init(void);








/*void	DIO_voidSetPinDirection(port,pin,mode);*/
void	DIO_voidSetPinDirection(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8Mode);
/*		if Pin is Output (High or Low)	*/
void	DIO_voidSetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8Value);
/*		Toggle output pin												*/
void	DIO_voidTogglePin(u8 Copy_u8PortID,u8 Copy_u8PinID);
/*		if Pin is Input (Return High or Low)	*/
u8		DIO_u8GetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID);

/*		SET PORT DIRECTION											*/
void	DIO_voidSetPortDirection(u8 Copy_u8PortID,u32 Copy_u32Mode);
/*		SET PORT VALUE												*/
void	DIO_voidSetPortValue(u8 Copy_u8PortID,u16 Copy_u16Value);

#define 		DIO_U8_SINGLE_ASSMPLY_INSTRUCTION				0

#define 		DIO_U8_PORTA			0
#define 		DIO_U8_PORTB			1
#define 		DIO_U8_PORTC			2

#define 		DIO_U8_PIN0		    	0
#define 		DIO_U8_PIN1		    	1
#define 		DIO_U8_PIN2		    	2
#define 		DIO_U8_PIN3		    	3
#define 		DIO_U8_PIN4		    	4
#define 		DIO_U8_PIN5		    	5
#define 		DIO_U8_PIN6		    	6
#define 		DIO_U8_PIN7		    	7
#define 		DIO_U8_PIN8		    	8
#define 		DIO_U8_PIN9		    	9
#define 		DIO_U8_PIN10	    	10
#define 		DIO_U8_PIN11	    	11
#define 		DIO_U8_PIN12	    	12
#define 		DIO_U8_PIN13	    	13
#define 		DIO_U8_PIN14	    	14
#define 		DIO_U8_PIN15	    	15

#define 		DIO_U8_HIGH				1
#define 		DIO_U8_LOW				0

/*				INPUT Options					*/
#define			DIO_INPUT_ANALOG		0b0000
#define			DIO_INPUT_FLOATING		0b0100
#define			DIO_INPUT_PULL_UP_DOWN	0b1000

/*				OUTPUT 2 MHz Options			*/
#define			DIO_OUTPUT_2MHZ_PP		0b0010
#define			DIO_OUTPUT_2MHZ_OD		0b0110
#define			DIO_OUTPUT_2MHZ_AF_PP	0b1010
#define			DIO_OUTPUT_2MHZ_AF_OD	0b1110

/*				OUTPUT 10 MHz Options			*/
#define			DIO_OUTPUT_10MHZ_PP		0b0001
#define			DIO_OUTPUT_10MHZ_OD		0b0101
#define			DIO_OUTPUT_10MHZ_AF_PP	0b1001
#define			DIO_OUTPUT_10MHZ_AF_OD	0b1101

/*				OUTPUT 50 MHz Options			*/
#define			DIO_OUTPUT_50MHZ_PP		0b0011
#define			DIO_OUTPUT_50MHZ_OD		0b0111
#define			DIO_OUTPUT_50MHZ_AF_PP	0b1011
#define			DIO_OUTPUT_50MHZ_AF_OD	0b1111

/*				PORT MODES						*/
/*INPUT Options*/

#define			DIO_PORT_INPUT_ANALOG		 \
((u32)DIO_INPUT_ANALOG | ((u32)DIO_INPUT_ANALOG<<4) |((u32)DIO_INPUT_ANALOG<<8) |((u32)DIO_INPUT_ANALOG<<12) |((u32)DIO_INPUT_ANALOG<<16) |((u32)DIO_INPUT_ANALOG<<20) |((u32)DIO_INPUT_ANALOG<<24) |((u32)DIO_INPUT_ANALOG<<28) )

#define			DIO_PORT_INPUT_FLOATING		 \
((u32)DIO_INPUT_FLOATING | ((u32)DIO_INPUT_FLOATING<<4) |((u32)DIO_INPUT_FLOATING<<8) |((u32)DIO_INPUT_FLOATING<<12) |((u32)DIO_INPUT_FLOATING<<16) |((u32)DIO_INPUT_FLOATING<<20) |((u32)DIO_INPUT_FLOATING<<24) |((u32)DIO_INPUT_FLOATING<<28) )

#define			DIO_PORT_INPUT_PULL_UP_DOWN	 \
((u32)DIO_INPUT_PULL_UP_DOWN | ((u32)DIO_INPUT_PULL_UP_DOWN<<4) |((u32)DIO_INPUT_PULL_UP_DOWN<<8) |((u32)DIO_INPUT_PULL_UP_DOWN<<12) |((u32)DIO_INPUT_PULL_UP_DOWN<<16) |((u32)DIO_INPUT_PULL_UP_DOWN<<20) |((u32)DIO_INPUT_PULL_UP_DOWN<<24) |((u32)DIO_INPUT_PULL_UP_DOWN<<28) )
/*				OUTPUT 2 MHz Options			*/

#define			DIO_PORT_OUTPUT_2MHZ_PP		 \
((u32)DIO_OUTPUT_2MHZ_PP | ((u32)DIO_OUTPUT_2MHZ_PP<<4) |((u32)DIO_OUTPUT_2MHZ_PP<<8) |((u32)DIO_OUTPUT_2MHZ_PP<<12) |((u32)DIO_OUTPUT_2MHZ_PP<<16) |((u32)DIO_OUTPUT_2MHZ_PP<<20) |((u32)DIO_OUTPUT_2MHZ_PP<<24) |((u32)DIO_OUTPUT_2MHZ_PP<<28) )

#define			DIO_PORT_OUTPUT_2MHZ_OD		 \
((u32)DIO_OUTPUT_2MHZ_OD | ((u32)DIO_OUTPUT_2MHZ_OD<<4) |((u32)DIO_OUTPUT_2MHZ_OD<<8) |((u32)DIO_OUTPUT_2MHZ_OD<<12) |((u32)DIO_OUTPUT_2MHZ_OD<<16) |((u32)DIO_OUTPUT_2MHZ_OD<<20) |((u32)DIO_OUTPUT_2MHZ_OD<<24) |((u32)DIO_OUTPUT_2MHZ_OD<<28) )

#define			DIO_PORT_OUTPUT_2MHZ_AF_PP	 \
(DIO_PORT_OUTPUT_2MHZ_OD ^ 0xCCCCCCCC)

#define			DIO_PORT_OUTPUT_2MHZ_AF_OD	 \
(DIO_PORT_OUTPUT_2MHZ_PP ^ 0xCCCCCCCC)
 /*				10MHz							*/
#define			DIO_PORT_OUTPUT_10MHZ_PP	 \
((u32)DIO_OUTPUT_10MHZ_PP | ((u32)DIO_OUTPUT_10MHZ_PP<<4) |((u32)DIO_OUTPUT_10MHZ_PP<<8) |((u32)DIO_OUTPUT_10MHZ_PP<<12) |((u32)DIO_OUTPUT_10MHZ_PP<<16) |((u32)DIO_OUTPUT_2MHZ_PP<<20) |((u32)DIO_OUTPUT_10MHZ_PP<<24) |((u32)DIO_OUTPUT_10MHZ_PP<<28) )

#define			DIO_PORT_OUTPUT_10MHZ_OD	 \
((u32)DIO_OUTPUT_10MHZ_OD | ((u32)DIO_OUTPUT_10MHZ_OD<<4) |((u32)DIO_OUTPUT_10MHZ_OD<<8) |((u32)DIO_OUTPUT_10MHZ_OD<<12) |((u32)DIO_OUTPUT_10MHZ_OD<<16) |((u32)DIO_OUTPUT_10MHZ_OD<<20) |((u32)DIO_OUTPUT_10MHZ_OD<<24) |((u32)DIO_OUTPUT_10MHZ_OD<<28) )

#define			DIO_PORT_OUTPUT_10MHZ_AF_PP	 \
(DIO_PORT_OUTPUT_10MHZ_OD ^ 0xCCCCCCCC)

#define			DIO_PORT_OUTPUT_10MHZ_AF_OD	 \
(DIO_PORT_OUTPUT_10MHZ_PP ^ 0xCCCCCCCC)

/*			50MHz								*/
#define			DIO_PORT_OUTPUT_50MHZ_PP	 \
((u32)DIO_OUTPUT_50MHZ_PP | ((u32)DIO_OUTPUT_50MHZ_PP<<4) |((u32)DIO_OUTPUT_50MHZ_PP<<8) |((u32)DIO_OUTPUT_50MHZ_PP<<12) |((u32)DIO_OUTPUT_50MHZ_PP<<16) |((u32)DIO_OUTPUT_50MHZ_PP<<20) |((u32)DIO_OUTPUT_50MHZ_PP<<24) |((u32)DIO_OUTPUT_50MHZ_PP<<28) )

#define			DIO_PORT_OUTPUT_50MHZ_OD	 \
((u32)DIO_OUTPUT_50MHZ_OD | ((u32)DIO_OUTPUT_50MHZ_OD<<4) |((u32)DIO_OUTPUT_50MHZ_OD<<8) |((u32)DIO_OUTPUT_50MHZ_OD<<12) |((u32)DIO_OUTPUT_50MHZ_OD<<16) |((u32)DIO_OUTPUT_50MHZ_OD<<20) |((u32)DIO_OUTPUT_50MHZ_OD<<24) |((u32)DIO_OUTPUT_50MHZ_OD<<28) )

#define			DIO_PORT_OUTPUT_50MHZ_AF_PP	 \
(DIO_PORT_OUTPUT_50MHZ_OD ^ 0xCCCCCCCC)

#define			DIO_PORT_OUTPUT_50MHZ_AF_OD	 \
(DIO_PORT_OUTPUT_50MHZ_PP ^ 0xCCCCCCCC)


#endif /* GPIO_INTERFACE_H_ */
