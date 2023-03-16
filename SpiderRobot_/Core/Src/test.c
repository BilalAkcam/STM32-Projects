/*
 * test.c
 *
 *  Created on: Mar 16, 2023
 *      Author: ralpm
 */


#include "test.h"

//void robot_tims_init(void){
//
//
//	  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
//	  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
//	  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
//
//	  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
//	  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
//	  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
//
//	  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
//	  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);
//	  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_4);
//
//	  HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_1);
//	  HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_2);
//	  HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_3);
//
//
//}

//static TIM_HandleTypeDef htim1;
//static TIM_HandleTypeDef htim3;
//static TIM_HandleTypeDef htim4;
//static TIM_HandleTypeDef htim5;
//



//int currentPosition[4][3]={{90,90,90},
//		{90,90,90},
//		{90,90,90},
//		{90,90,90}};

//void robot_tims_init(void){
//
//
//	  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
//	  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
//	  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
//
//	  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
//	  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
//	  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
//
//	  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
//	  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);
//	  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_4);
//
//	  HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_1);
//	  HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_2);
//	  HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_3);
//
//
//}
//
//
//
//
//void kademeliArttir(TIM_HandleTypeDef timer,unsigned int chanel, int bacak, int eklem, int angle, int fark){
//	int i;
//	int current = currentPosition[bacak][eklem];
//
//	if(current == angle){
//		__HAL_TIM_SET_COMPARE(&timer, chanel, current);
//		return;
//	}
//
//	if(current < angle){
//		for(i=current; i<=angle; i++){
//			HAL_Delay(3);
//			__HAL_TIM_SET_COMPARE(&timer, chanel, i);
//		}
//		currentPosition[bacak][eklem] = angle;
//	}
//	else{
//		for(i=current; i>=angle; i--){
//
//			HAL_Delay(3);
//			__HAL_TIM_SET_COMPARE(&timer, chanel, i);
//		}
//		currentPosition[bacak][eklem] = angle;
//	}
//
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//void leg1_1(int angle){
//	if(angle < 0)
//		 angle = 0;
//	if(angle >180)
//		angle = 180;
//	angle = angle + 35;
//	kademeliArttir(htim4, TIM_CHANNEL_1, 1, 1, angle, 35);
//	//__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, angle);
//}
//
//
//void leg1_2(int angle){
//	if(angle < 0)
//		 angle = 0;
//	if(angle >180)
//		angle = 180;
//	angle = angle + 48;
//	kademeliArttir(htim3, TIM_CHANNEL_3, 1, 2, angle, 48);
//	//__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, angle);
//}
//
//
//void leg1_3(int angle){
//	if(angle < 0)
//		 angle = 0;
//	if(angle >180)
//		angle = 180;
//	angle = angle + 48;
//	kademeliArttir(htim3, TIM_CHANNEL_1, 1, 3, angle, 48);
//	//__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, angle);
//}
//
//
//
//
//
//
//void leg2_1(int angle){
//
//	if(angle < 0)
//		 angle = 0;
//	if(angle >180)
//		angle = 180;
//	angle = angle + 45;
//	kademeliArttir(htim1, TIM_CHANNEL_3, 2, 1, angle, 45);
//	//__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, angle);
//}
//
//
//void leg2_2(int angle){
//
//	if(angle < 0)
//		 angle = 0;
//	if(angle >180)
//		angle = 180;
//	angle = angle + 47;
//	kademeliArttir(htim5, TIM_CHANNEL_3, 2, 2, angle, 47);
//	//__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_3, angle);
//}
//
//
//void leg2_3(int angle){
//
//	if(angle < 0)
//		 angle = 0;
//	if(angle >180)
//		angle = 180;
//	angle = angle + 32;
//	kademeliArttir(htim5, TIM_CHANNEL_1, 2, 3, angle, 32);
//	//__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_1, angle);
//}
//
//
//
//
//
//
//void leg3_1(int angle){
//
//	if(angle < 0)
//		 angle = 0;
//	if(angle >180)
//		angle = 180;
//	angle = angle + 45;
//	kademeliArttir(htim4, TIM_CHANNEL_4, 3, 1, angle, 45);
//	//__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, angle);
//
//}
//
//
//void leg3_2(int angle){
//
//	if(angle < 0)
//		 angle = 0;
//	if(angle >180)
//		angle = 180;
//	angle = angle + 47;
//	kademeliArttir(htim4, TIM_CHANNEL_2, 3, 2, angle, 47);
//	//__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, angle);
//
//}
//
//
//void leg3_3(int angle){
//	if(angle < 0)
//		 angle = 0;
//	if(angle >180)
//		angle = 180;
//	angle = angle + 37;//37
//	kademeliArttir(htim1, TIM_CHANNEL_2, 3, 3, angle, 37);
//	//__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, angle);
//}
//
//
//
//
//
//
//
//void leg4_1(int angle){
//
//	if(angle < 0)
//		 angle = 0;
//	if(angle >180)
//		angle = 180;
//	angle = angle + 45;
//	kademeliArttir(htim5, TIM_CHANNEL_2, 4, 1, angle, 45);
//
//	//__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_2, angle);
//
//}
//
//void leg4_2(int angle){
//
//	if(angle < 0)
//		 angle = 0;
//	if(angle >180)
//		angle = 180;
//	angle = angle + 37;//37
//	kademeliArttir(htim3,TIM_CHANNEL_2, 4, 2, angle, 37);
////	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, angle);
//
//}
//
//
//void leg4_3(int angle){
//
//	if(angle < 0)
//		 angle = 0;
//	if(angle >180)
//		angle = 180;
//	angle = angle + 45;
//	kademeliArttir(htim1, TIM_CHANNEL_1, 4, 3, angle, 45);
//	//__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, angle);
//
//}
