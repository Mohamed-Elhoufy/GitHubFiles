/*
 * SEG_interface.h
 *
 *  Created on: Feb 4, 2021
 *      Author: General
 */

#ifndef SEG_INTERFACE_H_
#define SEG_INTERFACE_H_

void SEG_Init(void);

//#if (SEG_TYBE_NUM==SEG_CHARACTER_NUM)
void SEG_Display(u8 num);
//#endif

//#if (SEG_TYBE_NUM==SEG_INTEGER_NUM)
//void SEG_Display(u16 num);
//#endif
#endif /* SEG_INTERFACE_H_ */
