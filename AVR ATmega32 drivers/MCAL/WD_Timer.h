/*
 * WD_Timer.h
 *
 * Created: 12/22/2020 2:29:26 PM
 *  Author: Amrth
 */ 


#ifndef WD_TIMER_H_
#define WD_TIMER_H_


#include "StdTypes.h"#include "MemMap.h"#include "Utils.h"typedef enum{	timeout_16ms=0,	timeout_32ms,	timeout_65ms,	timeout_130ms,	timeout_260ms,	timeout_520ms,	timeout_1000ms,	timeout_2100ms,}TimeOut_type;void WDT_Set(TimeOut_type time);void WDT_Stop(void);



#endif /* WD_TIMER_H_ */