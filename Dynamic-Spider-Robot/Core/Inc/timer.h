/*
 * timer.h
 *
 *  Created on: Jan 19, 2023
 *      Author: Bilal Habes Akcam
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "stm32f4xx_hal.h"


void PIDtimerInit(void);
void PIDtimerEnable(void);
void PIDtimerDisable(void);

uint32_t timerGetCounter(void);


#endif /* INC_TIMER_H_ */
