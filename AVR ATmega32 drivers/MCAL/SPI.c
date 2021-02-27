/*
 * SPI.c
 *
 * Created: 12/29/2020 11:07:38 AM
 *  Author: Amrth
 */ 

#include "SPI.h"

static void (*UART_SPI_Fptr) (void)=NULLPTR;

void SPI_Interrupt_Enable(void)
{
	SET_BIT(SPCR,SPIE);
}

void SPI_Interrupt_Disable(void)
{
	CLR_BIT(SPCR,SPIE);
}

void SPI_SetCallBack(void(*local_fptr)(void))
{
	UART_SPI_Fptr = local_fptr;
}


/****************************************************************************************/

void SPI_MasterInit(void)
{
	/* Set MOSI and SCK output, MISO  & DD_ Input */
	//DDR_SPI = (1<<DD_MOSI)|(1<<DD_SCK);
	/* Enable SPI, Master, set clock rate fck/16 */
	 //SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
	
	
	SET_BIT(SPCR,MSTR);
	SET_BIT(SPCR,SPE);
}

void SPI_SlaveInit(void)
{
	/* Set MISO output, all others input */
	//DDR_SPI = (1<<DD_MISO);
	/* Enable SPI */
	//SPCR = (1<<SPE);
	
	
	CLR_BIT(SPCR,MSTR);
	SET_BIT(SPCR,SPE);
}



void SPI_MasterTransmit(char cData)
{
	/* Start transmission */
	SPDR = cData;
	/* Wait for transmission complete */
	while(!GET_BIT(SPCR,SPIF));
}

char SPI_SlaveReceive(void)
{
	/* Wait for reception complete */
	while(!GET_BIT(SPCR,SPIF));
	/* Return data register */
	return SPDR;
}

u8 SPI_SendReceive(u8 data)
{
	SPDR = data;
	while(!GET_BIT(SPSR,SPIF));
	return SPDR;
}

void SPI_SendNoBlock(u8 data)
{
	SPDR=data;
}

u8 SPI_ReceiveNoBlock(void)
{
	return SPDR;
}

u8 SPI_receivePerodic(u8*pdata)
{
	if (GET_BIT(SPSR,SPIF))
	{
		*pdata=SPDR;
		return 1;
	}
	return 0;
	
}



// 
// ISR(SPI_STC_vect)
// {
// 	if(UART_SPI_Fptr!=NULLPTR)
// 	{
// 		UART_SPI_Fptr();
// 	}
// 	
// }