/*
 * delay.h
 *
 *  Created on: Aug 22, 2022
 *      Author: user
 */

#ifndef INC_DELAY_H_
#define INC_DELAY_H_

#include <stm32f4xx.h>

extern void delay_ns(unsigned int);
extern void delay_us(unsigned int);
extern void delay_ms(unsigned int);


#endif /* INC_DELAY_H_ */
