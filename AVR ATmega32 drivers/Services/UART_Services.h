/*
 * UART_Services.h
 *
 * Created: 12/24/2020 1:13:15 PM
 *  Author: Amrth
 */ 


#ifndef UART_SERVICES_H_
#define UART_SERVICES_H_

#include <string.h>
#include "DIO_Interface.h"
#include "UART.h"

void UART_SendString(u8 *str);
u8 *UART_ReceiveString(void);
/**************************/
void UART_InterruptReceiveString(void (*localFptr)(void));
/**************************/
void UART_SendU32 (u32 data);
u32 UART_ReceiveU32 ();


void UART_GetFrame(u8 *str);
void UART_DecodeFrame(u8 *uart_frame,u8 *function_str,u8 *parameter1,u8 *parameter2);
 
#endif /* UART_SERVICES_H_ */