/*
 * GPIO_interface.h
 *
 *  Created on: Feb 3, 2021
 *      Author: Boon
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

//setting all directions for all pins
void DIO_voidInit(void);

/*void	DIO_voidSetPinDirection(port,pin,mode);*/
void DIO_voidSetPinDirection(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Mode);
/*		if Pin is Output (High or Low)	*/
void DIO_voidSetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Value);
/*		if Pin is Input (Return High or Low)	*/
u8 DIO_u8GetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID);


void DIO_voidTogPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID);


/*void	DIO_voidSetPortDirection(port,mode);*/
void DIO_voidSetPortDirection(u8 Copy_u8PortID, u8 Copy_u8Mode);

/*	write port Output as data 	*/
void DIO_voidSetPortValue(u8 Copy_u8PortID, u16 Copy_u16Data);
/*	read port Input return data 	*/
u16 DIO_u16GetPortValue(u8 Copy_u8PortID);

/*		SET PORT DIRECTION											*/
/*		SET PORT VALUE												*/



typedef enum {
	DIO_enuPORTA = 0,
	DIO_enuPORTB,
	DIO_enuPORTC
} DIO_enuPortID_type;


typedef enum {
	DIO_enuPIN0 = 0,
	DIO_enuPIN1 = 1,
	DIO_enuPIN2,
	DIO_enuPIN3,
	DIO_enuPIN4,
	DIO_enuPIN5,
	DIO_enuPIN6,
	DIO_enuPIN7,
	DIO_enuPIN8,
	DIO_enuPIN9,
	DIO_enuPIN10,
	DIO_enuPIN11,
	DIO_enuPIN12,
	DIO_enuPIN13,
	DIO_enuPIN14,
	DIO_enuPIN15,
} DIO_enuPinID_type;

#define DIO_PORT_PINS_NUM 16

typedef enum {
	DIO_enuLOW,
	DIO_enuHIGH
} DIO_enuVoltage_type;

/*				INPUT Options					*/
		//DIO_INPUT_ANALOG		    0b0000
		//DIO_INPUT_FLOATING		0b0100
		//DIO_INPUT_PULL_UP_DOWN	0b1000

/*				OUTPUT 2 MHz Options			*/
		//DIO_OUTPUT_2MHZ_PP		0b0010
		//DIO_OUTPUT_2MHZ_OD		0b0110
		//DIO_OUTPUT_2MHZ_AF_PP	0b1010
		//DIO_OUTPUT_2MHZ_AF_OD	0b1110

/*				OUTPUT 10 MHz Options			*/
		//DIO_OUTPUT_10MHZ_PP		0b0001
		//DIO_OUTPUT_10MHZ_OD		0b0101
		//DIO_OUTPUT_10MHZ_AF_PP	0b1001
		//DIO_OUTPUT_10MHZ_AF_OD	0b1101

/*				OUTPUT 50 MHz Options			*/
		//DIO_OUTPUT_50MHZ_PP		0b0011
		//DIO_OUTPUT_50MHZ_OD		0b0111
	    //DIO_OUTPUT_50MHZ_AF_PP	0b1011
	    //DIO_OUTPUT_50MHZ_AF_OD	0b1111

typedef enum {
	DIO_enuINPUT_ANALOG = 0,
	DIO_enuOUTPUT_10MHZ_PP = 1,
	DIO_enuOUTPUT_2MHZ_PP = 2,
	DIO_enuOUTPUT_50MHZ_PP = 3,
	DIO_enuINPUT_FLOATING = 4,
	DIO_enuOUTPUT_10MHZ_OD = 5,
	DIO_enuOUTPUT_2MHZ_OD = 6,
	DIO_enuOUTPUT_50MHZ_OD = 7,
	DIO_enuINPUT_PULL_UP_DOWN = 8,
	DIO_enuOUTPUT_10MHZ_AF_PP = 9,
	DIO_enuOUTPUT_2MHZ_AF_PP = 10,
	DIO_enuOUTPUT_50MHZ_AF_PP = 11,
	DIO_enuOUTPUT_10MHZ_AF_OD = 13,
	DIO_enuOUTPUT_2MHZ_AF_OD = 14,
	DIO_enuOUTPUT_50MHZ_AF_OD = 15
} DIO_enuPinMode_type;

#endif /* GPIO_INTERFACE_H_ */
