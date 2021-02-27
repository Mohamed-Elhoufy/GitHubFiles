/*
 * UART.h
 *
 * Created: 12/24/2020 1:10:51 PM
 *  Author: Amrth
 */ 


#ifndef UART_H_
#define UART_H_

#define  NULLPTR ((void *)0)

#include "MemMap.h"
#include "StdTypes.h"
 #include "Utils.h"
/************************************/
void UART_RXC_Interrupt_Enable(void);
void UART_RXC_Interrupt_Disable(void);
void UART_TXC_Interrupt_Enable(void);
void UART_TXC_Interrupt_Disable(void);

void UART_RXC_SetCallBack(void(*local_fptr)(void));
void UART_TXC_SetCallBack(void(*local_fptr)(void));

/*******************************************************/
void UART_Init(void);
void UART_Send(u8 data);
u8 UART_Receive(void);
void UART_SendString(u8 *str);
u8 UART_Receive_periodic(void);
void UART_SendNoBlock (u8 data);
u8 UART_ReceiveNoBlock();

#endif /* UART_H_ */