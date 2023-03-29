/*
 * SpiderDriver.h
 *
 *  Created on: Dec 26, 2022
 *      Author: Bilal Habes Akcam
 */

#ifndef INC_SPIDERDRIVER_H_
#define INC_SPIDERDRIVER_H_



#include "stm32f4xx_hal.h"

#define forwardDelay	200
#define initDelay		300


void leg1_1(int angle);
void leg1_2(int angle);
void leg1_3(int angle);

void leg2_1(int angle);
void leg2_2(int angle);
void leg2_3(int angle);

void leg3_1(int angle);
void leg3_2(int angle);
void leg3_3(int angle);

void leg4_1(int angle);
void leg4_2(int angle);
void leg4_3(int angle);



void moveBack(void);
void turnAround(void);
void moveForward(void);
void initPosition(void);
void robot_tims_init(void);
void robot_all_leg_90(void);
void robot_all_leg_init(void);

void kademeliArttir(TIM_HandleTypeDef,unsigned int, int, int, int, int);


#endif /* INC_SPIDERDRIVER_H_ */
