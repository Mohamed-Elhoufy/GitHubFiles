/*
 * BIT_MATH.h
 *
 *  Created on: Feb 3, 2021
 *      Author: General
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG , BIT_NUM)		      REG |= (1<<BIT_NUM)     //set bit to 1 ignoring its previous value
#define CLR_BIT(REG , BIT_NUM)		      REG &= ~(1<<BIT_NUM)    //clear bit to 0 ignoring its previous value
#define TOG_BIT(REG , BIT_NUM)            REG ^= (1<<BIT_NUM)    //toggle bit  1 become 0 and 0 become 1
#define GET_BIT(REG , BIT_NUM)            ((REG>>BIT_NUM)&1)      //read bit value

#define WRT_BIT(REG , BIT_NUM , VALUE)    (REG=(REG&~(1<<BIT_NUM))|(VALUE<<BIT_NUM))

#endif /* BIT_MATH_H_ */
