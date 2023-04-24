/*
 * PID.h
 *
 *  Created on: Jan 12, 2023
 *      Author: Bilal Habes Akcam
 */

#ifndef INC_PID_H_
#define INC_PID_H_

#include "stm32f4xx_hal.h"

double getControlSignal(double, double, double, double, double, double);
void resetPidVariables();
void calcMotorPower(short x);



	#endif /* INC_PID_H_ */
