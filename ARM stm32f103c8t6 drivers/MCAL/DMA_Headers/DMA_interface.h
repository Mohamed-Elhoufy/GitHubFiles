/*
 * DMA_interface.h
 *
 *  Created on: Feb 14, 2021
 *      Author: Boon
 */

#ifndef DMA_INTERFACE_H_
#define DMA_INTERFACE_H_

void DMA1_voidChannelInit(void);
void DMA1_voidChannelStart(u32 * Copy_Pu32SourceAdd ,u32 * Copy_Pu32DestinationAdd ,u16 Copy_u16BlockSize);

#endif /* DMA_INTERFACE_H_ */
