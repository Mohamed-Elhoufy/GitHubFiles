/*
 * SPI.h
 *
 * Created: 12/29/2020 11:07:55 AM
 *  Author: Amrth
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"

#define  NULLPTR ((void *)0)

void SPI_Interrupt_Enable(void);
void SPI_Interrupt_Disable(void);

void SPI_SetCallBack(void(*local_fptr)(void));

void SPI_MasterInit(void);
void SPI_SlaveInit(void);
void SPI_MasterTransmit(char cData);
char SPI_SlaveReceive(void);

u8 SPI_SendReceive(u8 data);
u8 SPI_receivePerodic(u8*pdata);
void SPI_SendNoBlock(u8 data);
u8 SPI_ReceiveNoBlock(void);
#endif /* SPI_H_ */