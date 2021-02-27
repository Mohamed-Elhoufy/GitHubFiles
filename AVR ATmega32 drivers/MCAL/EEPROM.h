/*
 * EEPROM.h
 *
 * Created: 12/23/2020 10:04:01 AM
 *  Author: Amrth
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "MemMap.h"

void EEPROM_write(unsigned int uiAddress, unsigned char ucData);
unsigned char EEPROM_read(unsigned int uiAddress);



#endif /* EEPROM_H_ */