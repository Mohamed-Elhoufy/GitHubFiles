/*
 * Utils.h
 *
 * Created: 12/1/2020 11:18:43 AM
 *  Author: Amrth
 */ 


#ifndef UTILS_H_
#define UTILS_H_


#define	GET_BIT(reg,bit)	((reg>>bit) & 1)
#define SET_BIT(reg,bit)	(reg |= (1<<bit))
#define CLR_BIT(reg,bit)	(reg &= ~(1<<bit))
#define TOG_BIT(reg,bit)    (reg^= (1<<bit))


#endif /* UTILS_H_ */