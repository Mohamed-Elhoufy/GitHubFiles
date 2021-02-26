/*
 * SEG_config.h
 *
 *  Created on: Feb 4, 2021
 *      Author: General
 */

#ifndef SEG_CONFIG_H_
#define SEG_CONFIG_H_

/************config segment way *****************/
#define SEG_MULIPX 1
#define SEG_NORMAL 2
#define SEG_BCD 3
#define SEG_MODE SEG_MULIPX
/************config segment number system *****************/
#define SEG_HEXADECIMAL 16
#define SEG_DECIMAL 10
#define SEG_BINARY 2
#define SEG_NUM_SYS SEG_HEXADECIMAL

/************config segment type *****************/
#define SEG_ANODE 1
#define SEG_CATHODE 2
#define SEG_TYPE SEG_CATHODE

/************config number of segments *****************/
#define SEG_ONE 1
#define SEG_TWO 2
//#define SEG_THREE 3
//#define SEG_FOUR 4

#define SEG_N_PORTS TWO_SEG

/************config segment port & pins for normal *****************/

//#define SEG1_PORT DIO_U8_PORTA
//
//#define SEG1_PIN1 DIO_U8_PIN0
//#define SEG1_PIN2 DIO_U8_PIN1
//#define SEG1_PIN3 DIO_U8_PIN2
//#define SEG1_PIN4 DIO_U8_PIN3
//#define SEG1_PIN5 DIO_U8_PIN4
//#define SEG1_PIN6 DIO_U8_PIN5
//#define SEG1_PIN7 DIO_U8_PIN6
//#define SEG1_PIN8 DIO_U8_PIN7
//
//#define SEG2_PORT DIO_U8_PORTB
//
//#define SEG2_PIN1 DIO_U8_PIN0
//#define SEG2_PIN2 DIO_U8_PIN1
//#define SEG2_PIN3 DIO_U8_PIN2
//#define SEG2_PIN4 DIO_U8_PIN3
//#define SEG2_PIN5 DIO_U8_PIN4
//#define SEG2_PIN6 DIO_U8_PIN5
//#define SEG2_PIN7 DIO_U8_PIN6
//#define SEG2_PIN8 DIO_U8_PIN7
//
//#define SEG3_PORT DIO_U8_PORTA
//
//#define SEG3_PIN1 DIO_U8_PIN8
//#define SEG3_PIN2 DIO_U8_PIN9
//#define SEG3_PIN3 DIO_U8_PIN10
//#define SEG3_PIN4 DIO_U8_PIN11
//#define SEG3_PIN5 DIO_U8_PIN12
//#define SEG3_PIN6 DIO_U8_PIN13
//#define SEG3_PIN7 DIO_U8_PIN14
//#define SEG3_PIN8 DIO_U8_PIN15
//
//#define SEG4_PORT DIO_U8_PORTB
//
//#define SEG4_PIN1 DIO_U8_PIN8
//#define SEG4_PIN2 DIO_U8_PIN9
//#define SEG4_PIN3 DIO_U8_PIN10
//#define SEG4_PIN4 DIO_U8_PIN11
//#define SEG4_PIN5 DIO_U8_PIN12
//#define SEG4_PIN6 DIO_U8_PIN13
//#define SEG4_PIN7 DIO_U8_PIN14
//#define SEG4_PIN8 DIO_U8_PIN15


/************config segment enable for mul or BCD*****************/

#define SEG_PORT DIO_U8_PORTA

#define SEG1_EN DIO_U8_PIN8
#define SEG2_EN DIO_U8_PIN9



#define SEG_PIN1 DIO_U8_PIN0
#define SEG_PIN2 DIO_U8_PIN1
#define SEG_PIN3 DIO_U8_PIN2
#define SEG_PIN4 DIO_U8_PIN3
#define SEG_PIN5 DIO_U8_PIN4
#define SEG_PIN6 DIO_U8_PIN5
#define SEG_PIN7 DIO_U8_PIN6
#define SEG_PIN8 DIO_U8_PIN7

/************************number type************************/
#define SEG_CHARACTER_NUM 1
//#define SEG_INTEGER_NUM 2
#define SEG_TYBE_NUM SEG_CHARACTER_NUM
/************************ Time of Display************************/

#define SEG_DISPLAY_TIME 50
#define SEG_MULIPX_DELAY 10
/***********************************************************/

#endif /* SEG_CONFIG_H_ */
