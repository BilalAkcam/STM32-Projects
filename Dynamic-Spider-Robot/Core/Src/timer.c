/*
 * timer.c
 *
 *  Created on: Jan 19, 2023
 *      Author: Bilal Habes Akcam
 */


#include "timer.h"


void PIDtimerInit(void){

	__HAL_RCC_TIM2_CLK_ENABLE();

	TIM2->PSC = 31999;
	TIM2->ARR = 4800000;


}



void PIDtimerEnable(void){

	TIM2->CR1 |= (1<<0);
}


void PIDtimerDisable(void){

	TIM2->CR1 &= ~(1<<0);
}




uint32_t PIDtimerGetCounter(void){

	return (TIM2->CNT);
}




