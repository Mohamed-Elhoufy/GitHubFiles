/*
 * BIT_MATH.h
 *
 *  Created on: Feb 3, 2021
 *      Author: General
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG , BIT_NUM)		   REG |= (1<<BIT_NUM)
#define CLR_BIT(REG , BIT_NUM)		   REG &= ~(1<<BIT_NUM)
#define TOG_BIT(REG , BIT_NUM)         REG ^= (1<<BIT_NUM)
#define GET_BIT(REG , BIT_NUM)         ((REG>>BIT_NUM)&1)

#define WRT_BIT(REG , BIT_NUM , VALUE) (REG=(REG&~(1<<BIT_NUM))|(VALUE<<BIT_NUM))

#endif /* BIT_MATH_H_ */
