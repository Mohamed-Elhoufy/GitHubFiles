/*
 * RCC_private.h
 *
 *  Created on: Feb 3, 2021
 *      Author: General
 */

/*		File Guard											*/
#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

/*			Base Address For RCC							*/
#define		RCC_BASE_ADD		(0x40021000)

/*			RCC Registers		(BASE ADD + Offset)			*/
#define 	RCC_CR				*((u32 * )(RCC_BASE_ADD + 0x00))
#define 	RCC_CFGR			*((u32 * )(RCC_BASE_ADD + 0x04))
#define 	RCC_CIR				*((u32 * )(RCC_BASE_ADD + 0x08))
#define 	RCC_APB2RSTR		*((u32 * )(RCC_BASE_ADD + 0x0C))
#define 	RCC_APB1RSTR		*((u32 * )(RCC_BASE_ADD + 0x10))
#define 	RCC_AHBENR			*((u32 * )(RCC_BASE_ADD + 0x14))
#define 	RCC_APB2ENR			*((u32 * )(RCC_BASE_ADD + 0x18))
#define 	RCC_APB1ENR			*((u32 * )(RCC_BASE_ADD + 0x1C))
#define 	RCC_BDCR			*((u32 * )(RCC_BASE_ADD + 0x20))
#define 	RCC_CSR				*((u32 * )(RCC_BASE_ADD + 0x24))

#define   RCC_HSI 1
#define   RCC_HSE 2
#define   RCC_PLL 3

#define RCC_CRYSTAL     4
#define RCC_RC          5

#endif /* RCC_PRIVATE_H_ */
