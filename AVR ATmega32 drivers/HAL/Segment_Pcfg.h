/************* Pre-Build Configuration ************/

#ifndef SEGMENT_PCFG_H_
#define SEGMENT_PCFG_H_

#include "DIO_Interface.h"

#define CATHODE		0
#define ANODE		1
#define NORMAL		0
#define MUX			1


/************* Select BCD ************/
/* 1: enable BCD, 0: disable BCD */
#define BCD		0

/************* Select Common and Mode if BCD is 0 ************/
/* COMMON: (ANODE, CATHODE)	*/
#define COMMON	CATHODE
/* MODE: (NORMAL, MUX) */
#define MODE	MUX

/****************************************************/
/************* configuration for 2 7seg *************/
/****************************************************/

/************* Normal configuration ************/
#if(!MODE)
#define SEG1_NORMAL_PORT	PC
#define SEG2_NORMAL_PORT	PD

/********** Multiplexer configuration ************/
#elif(MODE)
#define SEG_MUX_PORT	PA
#define SEG_DP			PINB0
#define SEG1_EN			PINC6
#define SEG2_EN			PINC7

#endif


#endif /* SEGMENT_PCFG_H_ */