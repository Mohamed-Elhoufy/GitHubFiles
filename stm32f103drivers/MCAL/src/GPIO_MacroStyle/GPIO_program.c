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






/*void	DIO_voidSetPinDirection(port,pin,mode);*/
void DIO_voidSetPinDirection(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Mode) {
	/*		Range Check							*/
	if ((Copy_u8PortID < 3) && (Copy_u8PinID < 16)) {
		switch (Copy_u8PortID) {
		case DIO_U8_PORTA:
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
		case DIO_U8_PORTB:
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
		case DIO_U8_PORTC:
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
		case DIO_U8_PORTA:
			switch (Copy_u8Value) {
			case DIO_U8_HIGH:
				SET_BIT(GPIOA_ODR, Copy_u8PinID);
				break;
			case DIO_U8_LOW:
				CLR_BIT(GPIOA_ODR, Copy_u8PinID);
				break;
			default:
				; /*		Return ERROR		*/
			}
			break;
		case DIO_U8_PORTB:
			switch (Copy_u8Value) {
			case DIO_U8_HIGH:
				SET_BIT(GPIOB_ODR, Copy_u8PinID);
				break;
			case DIO_U8_LOW:
				CLR_BIT(GPIOB_ODR, Copy_u8PinID);
				break;
			default:
				; /*		Return ERROR		*/
			}
			break;
		case DIO_U8_PORTC:
			switch (Copy_u8Value) {
			case DIO_U8_HIGH:
				SET_BIT(GPIOC_ODR, Copy_u8PinID);
				break;
			case DIO_U8_LOW:
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

/*		if Pin is Input (Return High or Low)	*/
u8 DIO_u8GetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID) {
	u8 Local_u8Value = 0XFF;
	/*		Range Check							*/
	if ((Copy_u8PortID < 3) && (Copy_u8PinID < 16)) {

		switch (Copy_u8PortID) {
		case DIO_U8_PORTA:
			Local_u8Value = GET_BIT(GPIOA_IDR, Copy_u8PinID);
			break;
		case DIO_U8_PORTB:
			Local_u8Value = GET_BIT(GPIOB_IDR, Copy_u8PinID);
			break;
		case DIO_U8_PORTC:
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
		DIO_voidSetPinDirection(Copy_u8PortID, DIO_U8_PIN0, Copy_u8Mode);
		DIO_voidSetPinDirection(Copy_u8PortID, DIO_U8_PIN1, Copy_u8Mode);
		DIO_voidSetPinDirection(Copy_u8PortID, DIO_U8_PIN2, Copy_u8Mode);
		DIO_voidSetPinDirection(Copy_u8PortID, DIO_U8_PIN3, Copy_u8Mode);
		DIO_voidSetPinDirection(Copy_u8PortID, DIO_U8_PIN4, Copy_u8Mode);
		DIO_voidSetPinDirection(Copy_u8PortID, DIO_U8_PIN5, Copy_u8Mode);
		DIO_voidSetPinDirection(Copy_u8PortID, DIO_U8_PIN6, Copy_u8Mode);
		DIO_voidSetPinDirection(Copy_u8PortID, DIO_U8_PIN7, Copy_u8Mode);
		DIO_voidSetPinDirection(Copy_u8PortID, DIO_U8_PIN8, Copy_u8Mode);
		DIO_voidSetPinDirection(Copy_u8PortID, DIO_U8_PIN9, Copy_u8Mode);
		DIO_voidSetPinDirection(Copy_u8PortID, DIO_U8_PIN10, Copy_u8Mode);
		DIO_voidSetPinDirection(Copy_u8PortID, DIO_U8_PIN11, Copy_u8Mode);
		DIO_voidSetPinDirection(Copy_u8PortID, DIO_U8_PIN12, Copy_u8Mode);
		DIO_voidSetPinDirection(Copy_u8PortID, DIO_U8_PIN13, Copy_u8Mode);
		DIO_voidSetPinDirection(Copy_u8PortID, DIO_U8_PIN14, Copy_u8Mode);
		DIO_voidSetPinDirection(Copy_u8PortID, DIO_U8_PIN15, Copy_u8Mode);
	} else {/*	Return ERROR	*/
	}
}

void DIO_voidSetPortValue(u8 Copy_u8PortID, u16 Copy_u16Data) {

	/*		Range Check							*/
	if (Copy_u8PortID < 3) {
		DIO_voidSetPinValue(Copy_u8PortID, DIO_U8_PIN0,
				GET_BIT(Copy_u16Data, DIO_U8_PIN0));
		DIO_voidSetPinValue(Copy_u8PortID, DIO_U8_PIN1,
				GET_BIT(Copy_u16Data, DIO_U8_PIN1));
		DIO_voidSetPinValue(Copy_u8PortID, DIO_U8_PIN2,
				GET_BIT(Copy_u16Data, DIO_U8_PIN2));
		DIO_voidSetPinValue(Copy_u8PortID, DIO_U8_PIN3,
				GET_BIT(Copy_u16Data, DIO_U8_PIN3));
		DIO_voidSetPinValue(Copy_u8PortID, DIO_U8_PIN4,
				GET_BIT(Copy_u16Data, DIO_U8_PIN4));
		DIO_voidSetPinValue(Copy_u8PortID, DIO_U8_PIN5,
				GET_BIT(Copy_u16Data, DIO_U8_PIN5));
		DIO_voidSetPinValue(Copy_u8PortID, DIO_U8_PIN6,
				GET_BIT(Copy_u16Data, DIO_U8_PIN6));
		DIO_voidSetPinValue(Copy_u8PortID, DIO_U8_PIN7,
				GET_BIT(Copy_u16Data, DIO_U8_PIN7));
		DIO_voidSetPinValue(Copy_u8PortID, DIO_U8_PIN8,
				GET_BIT(Copy_u16Data, DIO_U8_PIN8));
		DIO_voidSetPinValue(Copy_u8PortID, DIO_U8_PIN9,
				GET_BIT(Copy_u16Data, DIO_U8_PIN9));
		DIO_voidSetPinValue(Copy_u8PortID, DIO_U8_PIN10,
				GET_BIT(Copy_u16Data, DIO_U8_PIN10));
		DIO_voidSetPinValue(Copy_u8PortID, DIO_U8_PIN11,
				GET_BIT(Copy_u16Data, DIO_U8_PIN11));
		DIO_voidSetPinValue(Copy_u8PortID, DIO_U8_PIN12,
				GET_BIT(Copy_u16Data, DIO_U8_PIN12));
		DIO_voidSetPinValue(Copy_u8PortID, DIO_U8_PIN13,
				GET_BIT(Copy_u16Data, DIO_U8_PIN13));
		DIO_voidSetPinValue(Copy_u8PortID, DIO_U8_PIN14,
				GET_BIT(Copy_u16Data, DIO_U8_PIN14));
		DIO_voidSetPinValue(Copy_u8PortID, DIO_U8_PIN15,
				GET_BIT(Copy_u16Data, DIO_U8_PIN15));
	}

}

u16 DIO_u16GetPortValue(u8 Copy_u8PortID) {
	u16 Local_u16Data = 0XFFFF;
	/*		Range Check							*/
	if ((Copy_u8PortID < 3)) {
		switch (Copy_u8PortID) {
		case DIO_U8_PORTA:
			WRT_BIT(Local_u16Data, DIO_U8_PIN0, GET_BIT(GPIOA_IDR,DIO_U8_PIN0));
			WRT_BIT(Local_u16Data, DIO_U8_PIN1, GET_BIT(GPIOA_IDR,DIO_U8_PIN1));
			WRT_BIT(Local_u16Data, DIO_U8_PIN2, GET_BIT(GPIOA_IDR,DIO_U8_PIN2));
			WRT_BIT(Local_u16Data, DIO_U8_PIN3, GET_BIT(GPIOA_IDR,DIO_U8_PIN3));
			WRT_BIT(Local_u16Data, DIO_U8_PIN4, GET_BIT(GPIOA_IDR,DIO_U8_PIN4));
			WRT_BIT(Local_u16Data, DIO_U8_PIN5, GET_BIT(GPIOA_IDR,DIO_U8_PIN5));
			WRT_BIT(Local_u16Data, DIO_U8_PIN6, GET_BIT(GPIOA_IDR,DIO_U8_PIN6));
			WRT_BIT(Local_u16Data, DIO_U8_PIN7, GET_BIT(GPIOA_IDR,DIO_U8_PIN7));
			WRT_BIT(Local_u16Data, DIO_U8_PIN8, GET_BIT(GPIOA_IDR,DIO_U8_PIN8));
			WRT_BIT(Local_u16Data, DIO_U8_PIN9, GET_BIT(GPIOA_IDR,DIO_U8_PIN9));
			WRT_BIT(Local_u16Data, DIO_U8_PIN10,
					GET_BIT(GPIOA_IDR,DIO_U8_PIN10));
			WRT_BIT(Local_u16Data, DIO_U8_PIN11,
					GET_BIT(GPIOA_IDR,DIO_U8_PIN11));
			WRT_BIT(Local_u16Data, DIO_U8_PIN12,
					GET_BIT(GPIOA_IDR,DIO_U8_PIN12));
			WRT_BIT(Local_u16Data, DIO_U8_PIN13,
					GET_BIT(GPIOA_IDR,DIO_U8_PIN13));
			WRT_BIT(Local_u16Data, DIO_U8_PIN14,
					GET_BIT(GPIOA_IDR,DIO_U8_PIN14));
			WRT_BIT(Local_u16Data, DIO_U8_PIN15,
					GET_BIT(GPIOA_IDR,DIO_U8_PIN15));
			break;
		case DIO_U8_PORTB:
			WRT_BIT(Local_u16Data, DIO_U8_PIN0, GET_BIT(GPIOB_IDR,DIO_U8_PIN0));
			WRT_BIT(Local_u16Data, DIO_U8_PIN1, GET_BIT(GPIOB_IDR,DIO_U8_PIN1));
			WRT_BIT(Local_u16Data, DIO_U8_PIN2, GET_BIT(GPIOB_IDR,DIO_U8_PIN2));
			WRT_BIT(Local_u16Data, DIO_U8_PIN3, GET_BIT(GPIOB_IDR,DIO_U8_PIN3));
			WRT_BIT(Local_u16Data, DIO_U8_PIN4, GET_BIT(GPIOB_IDR,DIO_U8_PIN4));
			WRT_BIT(Local_u16Data, DIO_U8_PIN5, GET_BIT(GPIOB_IDR,DIO_U8_PIN5));
			WRT_BIT(Local_u16Data, DIO_U8_PIN6, GET_BIT(GPIOB_IDR,DIO_U8_PIN6));
			WRT_BIT(Local_u16Data, DIO_U8_PIN7, GET_BIT(GPIOB_IDR,DIO_U8_PIN7));
			WRT_BIT(Local_u16Data, DIO_U8_PIN8, GET_BIT(GPIOB_IDR,DIO_U8_PIN8));
			WRT_BIT(Local_u16Data, DIO_U8_PIN9, GET_BIT(GPIOB_IDR,DIO_U8_PIN9));
			WRT_BIT(Local_u16Data, DIO_U8_PIN10,
					GET_BIT(GPIOB_IDR,DIO_U8_PIN10));
			WRT_BIT(Local_u16Data, DIO_U8_PIN11,
					GET_BIT(GPIOB_IDR,DIO_U8_PIN11));
			WRT_BIT(Local_u16Data, DIO_U8_PIN12,
					GET_BIT(GPIOB_IDR,DIO_U8_PIN12));
			WRT_BIT(Local_u16Data, DIO_U8_PIN13,
					GET_BIT(GPIOB_IDR,DIO_U8_PIN13));
			WRT_BIT(Local_u16Data, DIO_U8_PIN14,
					GET_BIT(GPIOB_IDR,DIO_U8_PIN14));
			WRT_BIT(Local_u16Data, DIO_U8_PIN15,
					GET_BIT(GPIOB_IDR,DIO_U8_PIN15));
			break;
		case DIO_U8_PORTC:
			WRT_BIT(Local_u16Data, DIO_U8_PIN0, GET_BIT(GPIOA_IDR,DIO_U8_PIN0));
			WRT_BIT(Local_u16Data, DIO_U8_PIN1, GET_BIT(GPIOC_IDR,DIO_U8_PIN1));
			WRT_BIT(Local_u16Data, DIO_U8_PIN2, GET_BIT(GPIOC_IDR,DIO_U8_PIN2));
			WRT_BIT(Local_u16Data, DIO_U8_PIN3, GET_BIT(GPIOC_IDR,DIO_U8_PIN3));
			WRT_BIT(Local_u16Data, DIO_U8_PIN4, GET_BIT(GPIOC_IDR,DIO_U8_PIN4));
			WRT_BIT(Local_u16Data, DIO_U8_PIN5, GET_BIT(GPIOC_IDR,DIO_U8_PIN5));
			WRT_BIT(Local_u16Data, DIO_U8_PIN6, GET_BIT(GPIOC_IDR,DIO_U8_PIN6));
			WRT_BIT(Local_u16Data, DIO_U8_PIN7, GET_BIT(GPIOC_IDR,DIO_U8_PIN7));
			WRT_BIT(Local_u16Data, DIO_U8_PIN8, GET_BIT(GPIOC_IDR,DIO_U8_PIN8));
			WRT_BIT(Local_u16Data, DIO_U8_PIN9, GET_BIT(GPIOC_IDR,DIO_U8_PIN9));
			WRT_BIT(Local_u16Data, DIO_U8_PIN10,
					GET_BIT(GPIOC_IDR,DIO_U8_PIN10));
			WRT_BIT(Local_u16Data, DIO_U8_PIN11,
					GET_BIT(GPIOC_IDR,DIO_U8_PIN11));
			WRT_BIT(Local_u16Data, DIO_U8_PIN12,
					GET_BIT(GPIOC_IDR,DIO_U8_PIN12));
			WRT_BIT(Local_u16Data, DIO_U8_PIN13,
					GET_BIT(GPIOC_IDR,DIO_U8_PIN13));
			WRT_BIT(Local_u16Data, DIO_U8_PIN14,
					GET_BIT(GPIOC_IDR,DIO_U8_PIN14));
			WRT_BIT(Local_u16Data, DIO_U8_PIN15,
					GET_BIT(GPIOC_IDR,DIO_U8_PIN15));
			break;

		}
	} else {/*	Return ERROR	*/}

	return Local_u16Data;
}

