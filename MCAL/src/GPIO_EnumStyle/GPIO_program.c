/*
 * GPIO_program.c
 *
 *  Created on: Feb 3, 2021
 *      Author: Boon
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

extern const DIO_enuPinMode_type DIO_AenuPinModePortA[DIO_PORT_PINS_NUM];
extern const DIO_enuPinMode_type DIO_AenuPinModePortB[DIO_PORT_PINS_NUM];
extern const DIO_enuPinMode_type DIO_AenuPinModePortC[DIO_PORT_PINS_NUM];

void DIO_voidInit(void)
{

	DIO_enuPinMode_type Local_enuPinModeCount;
		for(Local_enuPinModeCount=DIO_enuPIN0;DIO_PORT_PINS_NUM>Local_enuPinModeCount;Local_enuPinModeCount++)
		{
			DIO_voidSetPinDirection(DIO_enuPORTA , Local_enuPinModeCount , DIO_AenuPinModePortA[Local_enuPinModeCount]);
			DIO_voidSetPinDirection(DIO_enuPORTB , Local_enuPinModeCount , DIO_AenuPinModePortA[Local_enuPinModeCount]);
			DIO_voidSetPinDirection(DIO_enuPORTC , Local_enuPinModeCount , DIO_AenuPinModePortA[Local_enuPinModeCount]);
		}
}

/*void	DIO_voidSetPinDirection(port,pin,mode);*/
void DIO_voidSetPinDirection(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Mode) {
	/*		Range Check							*/
	if ((Copy_u8PortID < 3) && (Copy_u8PinID < 16)) {
		switch (Copy_u8PortID) {
		case DIO_enuPORTA:
			/*		LOW PORT				*/
			if (Copy_u8PinID < 8) {
				/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
				GPIOA_CRL &= ~((u32) (0b1111) << (Copy_u8PinID * 4));
				GPIOA_CRL |= ((u32) (Copy_u8Mode) << (Copy_u8PinID * 4));
			}
			/*		HIGH PORT				*/
			else {
				Copy_u8PinID -= 8;
				/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
				GPIOA_CRH &= ~((u32) (0b1111) << (Copy_u8PinID * 4));
				GPIOA_CRH |= ((u32) (Copy_u8Mode) << (Copy_u8PinID * 4));
			}
			break;
		case DIO_enuPORTB:
			if (Copy_u8PinID < 8) {
				/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
				GPIOB_CRL &= ~((u32) (0b1111) << (Copy_u8PinID * 4));
				GPIOB_CRL |= ((u32) (Copy_u8Mode) << (Copy_u8PinID * 4));
			}
			/*		HIGH PORT				*/
			else {
				Copy_u8PinID -= 8;
				/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
				GPIOB_CRH &= ~((u32) (0b1111) << (Copy_u8PinID * 4));
				GPIOB_CRH |= ((u32) (Copy_u8Mode) << (Copy_u8PinID * 4));
			}
			break;
		case DIO_enuPORTC:
			if (Copy_u8PinID < 8) {
				/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
				GPIOC_CRL &= ~((u32) (0b1111) << (Copy_u8PinID * 4));
				GPIOC_CRL |= ((u32) (Copy_u8Mode) << (Copy_u8PinID * 4));
			}
			/*		HIGH PORT				*/
			else {
				Copy_u8PinID -= 8;
				/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
				GPIOC_CRH &= ~((u32) (0b1111) << (Copy_u8PinID * 4));
				GPIOC_CRH |= ((u32) (Copy_u8Mode) << (Copy_u8PinID * 4));
			}
			break;
		}
	} else {/*	Return ERROR	*/
	}

}

/*		if Pin is Output (High or Low)	*/
void DIO_voidSetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Value) {
	/*		Range Check							*/
	if ((Copy_u8PortID < 3) && (Copy_u8PinID < 16)) {
		switch (Copy_u8PortID) {
		case DIO_enuPORTA:
			switch (Copy_u8Value) {
			case DIO_enuHIGH:
				SET_BIT(GPIOA_ODR, Copy_u8PinID);
				break;
			case DIO_enuLOW:
				CLR_BIT(GPIOA_ODR, Copy_u8PinID);
				break;
			default:
				; /*		Return ERROR		*/
			}
			break;
		case DIO_enuPORTB:
			switch (Copy_u8Value) {
			case DIO_enuHIGH:
				SET_BIT(GPIOB_ODR, Copy_u8PinID);
				break;
			case DIO_enuLOW:
				CLR_BIT(GPIOB_ODR, Copy_u8PinID);
				break;
			default:
				; /*		Return ERROR		*/
			}
			break;
		case DIO_enuPORTC:
			switch (Copy_u8Value) {
			case DIO_enuHIGH:
				SET_BIT(GPIOC_ODR, Copy_u8PinID);
				break;
			case DIO_enuLOW:
				CLR_BIT(GPIOC_ODR, Copy_u8PinID);
				break;
			default:
				; /*		Return ERROR		*/
			}
			break;
		}
	} else {/*	Return ERROR	*/
	}
}

void DIO_voidTogPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID)
{
	/*		Range Check							*/
		if ((Copy_u8PortID < 3) && (Copy_u8PinID < 16)) {
			switch (Copy_u8PortID) {
			case DIO_enuPORTA:
					TOG_BIT(GPIOA_ODR, Copy_u8PinID);
				break;
			case DIO_enuPORTB:
					TOG_BIT(GPIOB_ODR, Copy_u8PinID);
				break;
			case DIO_enuPORTC:
					TOG_BIT(GPIOC_ODR, Copy_u8PinID);
				break;
			}
		} else {/*	Return ERROR	*/
		}
}

/*		if Pin is Input (Return High or Low)	*/
u8 DIO_u8GetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID) {
	u8 Local_u8Value = 0XFF;
	/*		Range Check							*/
	if ((Copy_u8PortID < 3) && (Copy_u8PinID < 16)) {

		switch (Copy_u8PortID) {
		case DIO_enuPORTA:
			Local_u8Value = GET_BIT(GPIOA_IDR, Copy_u8PinID);
			break;
		case DIO_enuPORTB:
			Local_u8Value = GET_BIT(GPIOB_IDR, Copy_u8PinID);
			break;
		case DIO_enuPORTC:
			Local_u8Value = GET_BIT(GPIOC_IDR, Copy_u8PinID);
			break;

		}
	} else {/*	Return ERROR	*/
	}

	return Local_u8Value;
}

/*void	DIO_voidSetPortDirection(port,mode);*/
void DIO_voidSetPortDirection(u8 Copy_u8PortID, u8 Copy_u8Mode) {
	/*		Range Check							*/
	if (Copy_u8PortID < 3) {
		DIO_voidSetPinDirection(Copy_u8PortID, DIO_enuPIN0, Copy_u8Mode);
		DIO_voidSetPinDirection(Copy_u8PortID, DIO_enuPIN1, Copy_u8Mode);
		DIO_voidSetPinDirection(Copy_u8PortID, DIO_enuPIN2, Copy_u8Mode);
		DIO_voidSetPinDirection(Copy_u8PortID, DIO_enuPIN3, Copy_u8Mode);
		DIO_voidSetPinDirection(Copy_u8PortID, DIO_enuPIN4, Copy_u8Mode);
		DIO_voidSetPinDirection(Copy_u8PortID, DIO_enuPIN5, Copy_u8Mode);
		DIO_voidSetPinDirection(Copy_u8PortID, DIO_enuPIN6, Copy_u8Mode);
		DIO_voidSetPinDirection(Copy_u8PortID, DIO_enuPIN7, Copy_u8Mode);
		DIO_voidSetPinDirection(Copy_u8PortID, DIO_enuPIN8, Copy_u8Mode);
		DIO_voidSetPinDirection(Copy_u8PortID, DIO_enuPIN9, Copy_u8Mode);
		DIO_voidSetPinDirection(Copy_u8PortID, DIO_enuPIN10, Copy_u8Mode);
		DIO_voidSetPinDirection(Copy_u8PortID, DIO_enuPIN11, Copy_u8Mode);
		DIO_voidSetPinDirection(Copy_u8PortID, DIO_enuPIN12, Copy_u8Mode);
		DIO_voidSetPinDirection(Copy_u8PortID, DIO_enuPIN13, Copy_u8Mode);
		DIO_voidSetPinDirection(Copy_u8PortID, DIO_enuPIN14, Copy_u8Mode);
		DIO_voidSetPinDirection(Copy_u8PortID, DIO_enuPIN15, Copy_u8Mode);
	} else {/*	Return ERROR	*/
	}
}


void DIO_voidSetPortValue(u8 Copy_u8PortID, u16 Copy_u16Data) {

	/*		Range Check							*/
	if (Copy_u8PortID < 3) {
		DIO_voidSetPinValue(Copy_u8PortID, DIO_enuPIN0,
				GET_BIT(Copy_u16Data, DIO_enuPIN0));
		DIO_voidSetPinValue(Copy_u8PortID, DIO_enuPIN1,
				GET_BIT(Copy_u16Data, DIO_enuPIN1));
		DIO_voidSetPinValue(Copy_u8PortID, DIO_enuPIN2,
				GET_BIT(Copy_u16Data, DIO_enuPIN2));
		DIO_voidSetPinValue(Copy_u8PortID, DIO_enuPIN3,
				GET_BIT(Copy_u16Data, DIO_enuPIN3));
		DIO_voidSetPinValue(Copy_u8PortID, DIO_enuPIN4,
				GET_BIT(Copy_u16Data, DIO_enuPIN4));
		DIO_voidSetPinValue(Copy_u8PortID, DIO_enuPIN5,
				GET_BIT(Copy_u16Data, DIO_enuPIN5));
		DIO_voidSetPinValue(Copy_u8PortID, DIO_enuPIN6,
				GET_BIT(Copy_u16Data, DIO_enuPIN6));
		DIO_voidSetPinValue(Copy_u8PortID, DIO_enuPIN7,
				GET_BIT(Copy_u16Data, DIO_enuPIN7));
		DIO_voidSetPinValue(Copy_u8PortID, DIO_enuPIN8,
				GET_BIT(Copy_u16Data, DIO_enuPIN8));
		DIO_voidSetPinValue(Copy_u8PortID, DIO_enuPIN9,
				GET_BIT(Copy_u16Data, DIO_enuPIN9));
		DIO_voidSetPinValue(Copy_u8PortID, DIO_enuPIN10,
				GET_BIT(Copy_u16Data, DIO_enuPIN10));
		DIO_voidSetPinValue(Copy_u8PortID, DIO_enuPIN11,
				GET_BIT(Copy_u16Data, DIO_enuPIN11));
		DIO_voidSetPinValue(Copy_u8PortID, DIO_enuPIN12,
				GET_BIT(Copy_u16Data, DIO_enuPIN12));
		DIO_voidSetPinValue(Copy_u8PortID, DIO_enuPIN13,
				GET_BIT(Copy_u16Data, DIO_enuPIN13));
		DIO_voidSetPinValue(Copy_u8PortID, DIO_enuPIN14,
				GET_BIT(Copy_u16Data, DIO_enuPIN14));
		DIO_voidSetPinValue(Copy_u8PortID, DIO_enuPIN15,
				GET_BIT(Copy_u16Data, DIO_enuPIN15));
	}

}

u16 DIO_u16GetPortValue(u8 Copy_u8PortID) {
	u16 Local_u16Data = 0XFFFF;
	/*		Range Check							*/
	if ((Copy_u8PortID < 3)) {
		switch (Copy_u8PortID) {
		case DIO_enuPORTA:
			WRT_BIT(Local_u16Data, DIO_enuPIN0, GET_BIT(GPIOA_IDR,DIO_enuPIN0));
			WRT_BIT(Local_u16Data, DIO_enuPIN1, GET_BIT(GPIOA_IDR,DIO_enuPIN1));
			WRT_BIT(Local_u16Data, DIO_enuPIN2, GET_BIT(GPIOA_IDR,DIO_enuPIN2));
			WRT_BIT(Local_u16Data, DIO_enuPIN3, GET_BIT(GPIOA_IDR,DIO_enuPIN3));
			WRT_BIT(Local_u16Data, DIO_enuPIN4, GET_BIT(GPIOA_IDR,DIO_enuPIN4));
			WRT_BIT(Local_u16Data, DIO_enuPIN5, GET_BIT(GPIOA_IDR,DIO_enuPIN5));
			WRT_BIT(Local_u16Data, DIO_enuPIN6, GET_BIT(GPIOA_IDR,DIO_enuPIN6));
			WRT_BIT(Local_u16Data, DIO_enuPIN7, GET_BIT(GPIOA_IDR,DIO_enuPIN7));
			WRT_BIT(Local_u16Data, DIO_enuPIN8, GET_BIT(GPIOA_IDR,DIO_enuPIN8));
			WRT_BIT(Local_u16Data, DIO_enuPIN9, GET_BIT(GPIOA_IDR,DIO_enuPIN9));
			WRT_BIT(Local_u16Data, DIO_enuPIN10,
					GET_BIT(GPIOA_IDR,DIO_enuPIN10));
			WRT_BIT(Local_u16Data, DIO_enuPIN11,
					GET_BIT(GPIOA_IDR,DIO_enuPIN11));
			WRT_BIT(Local_u16Data, DIO_enuPIN12,
					GET_BIT(GPIOA_IDR,DIO_enuPIN12));
			WRT_BIT(Local_u16Data, DIO_enuPIN13,
					GET_BIT(GPIOA_IDR,DIO_enuPIN13));
			WRT_BIT(Local_u16Data, DIO_enuPIN14,
					GET_BIT(GPIOA_IDR,DIO_enuPIN14));
			WRT_BIT(Local_u16Data, DIO_enuPIN15,
					GET_BIT(GPIOA_IDR,DIO_enuPIN15));
			break;
		case DIO_enuPORTB:
			WRT_BIT(Local_u16Data, DIO_enuPIN0, GET_BIT(GPIOB_IDR,DIO_enuPIN0));
			WRT_BIT(Local_u16Data, DIO_enuPIN1, GET_BIT(GPIOB_IDR,DIO_enuPIN1));
			WRT_BIT(Local_u16Data, DIO_enuPIN2, GET_BIT(GPIOB_IDR,DIO_enuPIN2));
			WRT_BIT(Local_u16Data, DIO_enuPIN3, GET_BIT(GPIOB_IDR,DIO_enuPIN3));
			WRT_BIT(Local_u16Data, DIO_enuPIN4, GET_BIT(GPIOB_IDR,DIO_enuPIN4));
			WRT_BIT(Local_u16Data, DIO_enuPIN5, GET_BIT(GPIOB_IDR,DIO_enuPIN5));
			WRT_BIT(Local_u16Data, DIO_enuPIN6, GET_BIT(GPIOB_IDR,DIO_enuPIN6));
			WRT_BIT(Local_u16Data, DIO_enuPIN7, GET_BIT(GPIOB_IDR,DIO_enuPIN7));
			WRT_BIT(Local_u16Data, DIO_enuPIN8, GET_BIT(GPIOB_IDR,DIO_enuPIN8));
			WRT_BIT(Local_u16Data, DIO_enuPIN9, GET_BIT(GPIOB_IDR,DIO_enuPIN9));
			WRT_BIT(Local_u16Data, DIO_enuPIN10,
					GET_BIT(GPIOB_IDR,DIO_enuPIN10));
			WRT_BIT(Local_u16Data, DIO_enuPIN11,
					GET_BIT(GPIOB_IDR,DIO_enuPIN11));
			WRT_BIT(Local_u16Data, DIO_enuPIN12,
					GET_BIT(GPIOB_IDR,DIO_enuPIN12));
			WRT_BIT(Local_u16Data, DIO_enuPIN13,
					GET_BIT(GPIOB_IDR,DIO_enuPIN13));
			WRT_BIT(Local_u16Data, DIO_enuPIN14,
					GET_BIT(GPIOB_IDR,DIO_enuPIN14));
			WRT_BIT(Local_u16Data, DIO_enuPIN15,
					GET_BIT(GPIOB_IDR,DIO_enuPIN15));
			break;
		case DIO_enuPORTC:
			WRT_BIT(Local_u16Data, DIO_enuPIN0, GET_BIT(GPIOA_IDR,DIO_enuPIN0));
			WRT_BIT(Local_u16Data, DIO_enuPIN1, GET_BIT(GPIOC_IDR,DIO_enuPIN1));
			WRT_BIT(Local_u16Data, DIO_enuPIN2, GET_BIT(GPIOC_IDR,DIO_enuPIN2));
			WRT_BIT(Local_u16Data, DIO_enuPIN3, GET_BIT(GPIOC_IDR,DIO_enuPIN3));
			WRT_BIT(Local_u16Data, DIO_enuPIN4, GET_BIT(GPIOC_IDR,DIO_enuPIN4));
			WRT_BIT(Local_u16Data, DIO_enuPIN5, GET_BIT(GPIOC_IDR,DIO_enuPIN5));
			WRT_BIT(Local_u16Data, DIO_enuPIN6, GET_BIT(GPIOC_IDR,DIO_enuPIN6));
			WRT_BIT(Local_u16Data, DIO_enuPIN7, GET_BIT(GPIOC_IDR,DIO_enuPIN7));
			WRT_BIT(Local_u16Data, DIO_enuPIN8, GET_BIT(GPIOC_IDR,DIO_enuPIN8));
			WRT_BIT(Local_u16Data, DIO_enuPIN9, GET_BIT(GPIOC_IDR,DIO_enuPIN9));
			WRT_BIT(Local_u16Data, DIO_enuPIN10,
					GET_BIT(GPIOC_IDR,DIO_enuPIN10));
			WRT_BIT(Local_u16Data, DIO_enuPIN11,
					GET_BIT(GPIOC_IDR,DIO_enuPIN11));
			WRT_BIT(Local_u16Data, DIO_enuPIN12,
					GET_BIT(GPIOC_IDR,DIO_enuPIN12));
			WRT_BIT(Local_u16Data, DIO_enuPIN13,
					GET_BIT(GPIOC_IDR,DIO_enuPIN13));
			WRT_BIT(Local_u16Data, DIO_enuPIN14,
					GET_BIT(GPIOC_IDR,DIO_enuPIN14));
			WRT_BIT(Local_u16Data, DIO_enuPIN15,
					GET_BIT(GPIOC_IDR,DIO_enuPIN15));
			break;

		}
	} else {/*	Return ERROR	*/
	}

	return Local_u16Data;
}

