/*
 * UART.c
 *
 * Created: 12/24/2020 1:10:35 PM
 *  Author: Amrth
 */ 
#include "UART.h"


static void (*UART_RX_Fptr) (void)=NULLPTR;
static void (*UART_TX_Fptr) (void)=NULLPTR;

/**********************************************/
void UART_RXC_Interrupt_Enable(void)
{
	SET_BIT(UCSRB,RXCIE);
}

void UART_RXC_Interrupt_Disable(void)
{
	CLR_BIT(UCSRB,RXCIE);
}

void UART_TXC_Interrupt_Enable(void)
{
	SET_BIT(UCSRB,TXCIE);
}

void UART_TXC_Interrupt_Disable(void)
{
	CLR_BIT(UCSRB,TXCIE);
}

void UART_RXC_SetCallBack(void(*local_fptr)(void))
{
	UART_RX_Fptr = local_fptr;
}

void UART_TXC_SetCallBack(void(*local_fptr)(void))
{
	UART_TX_Fptr = local_fptr;
}
/*****************************************************/

void UART_Init(void)
{
	UBRRL=51;				//baud 9600 FCPU 8MHZ
	CLR_BIT(UCSRA,U2X);
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
}

void UART_Send(u8 data)
{
	while (!GET_BIT(UCSRA,UDRE));
	UDR=data;
}

void UART_SendString(u8 *str)
{
	for (u8 i=0;str[i];i++)
	{
		UART_Send(str[i]);
	}
}

u8 UART_Receive(void)
{
	while (!GET_BIT(UCSRA,RXC));
	return UDR;
}

u8 UART_Receive_periodic(void)
{
	if (GET_BIT(UCSRA,RXC))		return UDR;
	else						return 0;
}

void UART_SendNoBlock (u8 data)
{
	UDR=data;
}

u8 UART_ReceiveNoBlock(void)
{
	return UDR;
}

/*********************************************************/


 
//  ISR(UART_RX_vect)
//  {
//  	if(UART_RX_Fptr!=NULLPTR)
//  	{
//  		UART_RX_Fptr();
//  	} 
//  	
//  }


// ISR(UART_TX_vect)
// {
// 	if(UART_TX_Fptr!=NULLPTR)
// 	{
// 		UART_TX_Fptr();
// 	}
// 	
// }

