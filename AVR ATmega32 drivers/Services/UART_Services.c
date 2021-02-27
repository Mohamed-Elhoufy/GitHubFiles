/*
 * UART_Services.c
 *
 * Created: 12/24/2020 1:13:35 PM
 *  Author: Amrth
 */ 
#include "UART_Services.h"


// void UART_SendString(u8 *str)
// {
// 	for (u8 i=0;str[i];i++)
// 	{
// 		UART_Send(str[i]);
// 	}
// }

/***************************************/
static void (*fptr_Rxc)(void);

static void RxStr_func (void)
{
	fptr_Rxc();
}

void UART_InterruptReceiveString(void (*localFptr)(void))
{
	UART_Init();
	UART_RXC_Interrupt_Enable();
	fptr_Rxc=localFptr;
	UART_RXC_SetCallBack(RxStr_func);	
}



/************************************************/

u8 *UART_ReceiveString(void)
{
	static u8 str[100]={0};
	u8 i;
	for (i=0;;i++)
	{
		str[i]=UART_Receive();
		if     (str[i]==13 || str[i]==10)
		{
			UART_Receive();
			break;
		}
		else if(str[i]==8)		i-=2;
	}
	str[i]=0;
	return str;
}

/**************** UART Checksum send and receive *****************/

void UART_checksum_send(u8 *data)
{
	u16 i,checksum=0;
	u8 length=0;
	length=strlen(data);
	UART_Send(length);
	for (i=0;i<length;i++)
	{
		UART_Send(data[i]);
		checksum+=data[i];
	}
	UART_Send((u8)checksum);
	UART_Send((u8)(checksum>>8));
}



u8 UART_checksum_receive(u8* data)
{
	u8 b1=0,b2=0,i=0,j,length=0;
	u16 mychecksum=0,senderchecksum=0;
	for (j=0;j<3;)
	{
		switch (j)
		{
			case 0:
			length=UART_Receive();
			j++;
			break;
			
			case 1:
			for (i=0;i<length;i++)
			{
				data[i]=UART_Receive();
				mychecksum+=data[i];
			}
			j++;
			
			break;
			
			case 2:
			data[i]=0;
			b1=UART_Receive();
			b2=UART_Receive();
			senderchecksum=b1|(((u16)b2)<<8);
			j++;
			break;
		}
	}
	
	if (senderchecksum==mychecksum)		return 1;
	else                                return 0;
}

/*******************************************************************/
void UART_SendU32 (u32 data)
{
	UART_Send((u8)data);
	UART_Send((u8)(data>>8));
	UART_Send((u8)(data>>16));
	UART_Send((u8)(data>>24));
}


u32 UART_ReceiveU32 ()
{
	u32 data;
	u8 b1,b2,b3,b4;
	b1=UART_Receive;
	b2=UART_Receive;
	b3=UART_Receive;
	b4=UART_Receive;
	data=b1 | (((u32)b2)<<8) | (((u32)b3)<<16) | (((u32)b4)<<24);
	return data;
}

/********************UART Asnchronous send *************************/
static u8 *SendStr=0;

static void TX_Func(void)
{
	static u8 i=1;
	if (SendStr[i])
	{
		UART_SendNoBlock(SendStr[i]);
		i++;
	}
	else
	{
		i=1;
	}
}

void UART_SendStringAsync(u8 *str)
{
	UART_SendNoBlock(str[0]);
	UART_TXC_SetCallBack(TX_Func);
	UART_TXC_Interrupt_Enable();
	SendStr=str;
}

/********************UART Asnchronous receive*************************/
static u8 *ReceiveStr=0;
static u8 i=0;
static void RX_Func(void)
{
	ReceiveStr[i]=UART_ReceiveNoBlock();
	i++;
}

void UART_ReceiveStringAsync(u8 *str)
{
	//UART_ReceiveNoBlock(str[0]);
	UART_RXC_SetCallBack(RX_Func);
	UART_RXC_Interrupt_Enable();
	ReceiveStr=str;
	i=0;
}


/****************** Frame Services ************************************/

 

 void UART_GetFrame(u8 *str)
 {
	 memset(str,0,20);
	 strncpy(str,UART_ReceiveString(),20);
 }

 void UART_DecodeFrame(u8 *uart_frame,u8 *function_str,u8 *parameter1,u8 *parameter2)
 {
	 memset(function_str,0,15);
	 memset(parameter1,0,5);
	 memset(parameter2,0,5);
	 u8 i,j,stage=0;
	 for (i=0,j=0,stage=0;uart_frame[i];i++)
	 {
		 if (uart_frame[i]==' ')
		 {
			 j=0;
			 stage++;
		 }
		 else
		 {
			 switch(stage)
			 {
				 case 0:
				 if (j<14)		function_str[j]=uart_frame[i];
				 else
				 {
					 function_str[j]=0;
					 stage=3;
				 }
				 break;

				 case 1:
				 if (j<4)		parameter1[j]=uart_frame[i];
				 else
				 {
					 parameter1[j]=0;
					 stage=3;
				 }
				 break;

				 case 2:
				 if (j<4)		parameter2[j]=uart_frame[i];
				 else
				 {
					 parameter2[j]=0;
					 stage=3;
				 }
				 break;
			 }
			 if (stage==3)		break;
			 j++;
		 }
	 }
 }

