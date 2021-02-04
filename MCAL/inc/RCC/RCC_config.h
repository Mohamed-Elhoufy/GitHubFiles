/*
 * RCC_config.h
 *
 *  Created on: Feb 3, 2021
 *      Author: General
 */


#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/* Clock Type 1- RCC_HSI
 *            2- RCC_HSE
 *            3- RCC_PLL
 *
 */

#define CLOCK_TYPE RCC_HSE

#if CLOCK_TYPE == RCC_HSE
                                      // Can be RCC_Crystal or RCC_RC
#define RCC_HSE_SOURCE RCC_CRYSTAL
#endif

#if CLOCK_TYPE == RCC_PLL
                                      // PLL Multiplication Factor 1: 16
#define RCC_PLL_MUL 1
                                      // PLL Source (HSE/HSI)
#define RCC_PLL_SOURCE RCC_HSI
#endif
#endif /* RCC_CONFIG_H_ */
