/*
 * SpiderDriver.c
 *
 *  Created on: Dec 26, 2022
 *      Author: Bilal Habes Akcam
 */

#include "SpiderDriver.h"

int aa = 22.5;
int a = 45;
int b = 67.5;
int c = 90;
int d = 112.5;
int e = 135;
int f = 157.5;


extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim5;


int currentPosition[5][5]={{90,90,90,90,90},
						   {90,90,90,90,90},
						   {90,90,90,90,90},
						   {90,90,90,90,90},
						   {90,90,90,90,90}};




void kademeliArttir(TIM_HandleTypeDef timer,unsigned int chanel, int bacak, int eklem, int angle, int fark){
	int i;
	int current = currentPosition[bacak][eklem];

	if(current == angle){
		__HAL_TIM_SET_COMPARE(&timer, chanel, current);
		return;
	}

	if(current < angle){
		for(i=current; i<=angle; i++){
			HAL_Delay(3);
			__HAL_TIM_SET_COMPARE(&timer, chanel, i);
		}
		currentPosition[bacak][eklem] = angle;
	}
	else{
		for(i=current; i>=angle; i--){

			HAL_Delay(3);
			__HAL_TIM_SET_COMPARE(&timer, chanel, i);
		}
		currentPosition[bacak][eklem] = angle;
	}

}


void leg1_1(int angle){
	if(angle < 0)
		 angle = 0;
	if(angle >180)
		angle = 180;
	angle = angle + 35;
	kademeliArttir(htim4, TIM_CHANNEL_1, 1, 1, angle, 35);
	//__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, angle);
}

void leg1_2(int angle){
	if(angle < 0)
		 angle = 0;
	if(angle >180)
		angle = 180;
	angle = angle + 48;
	kademeliArttir(htim3, TIM_CHANNEL_3, 1, 2, angle, 48);
	//__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, angle);
}

void leg1_3(int angle){
	if(angle < 0)
		 angle = 0;
	if(angle >180)
		angle = 180;
	angle = angle + 48;
	kademeliArttir(htim1, TIM_CHANNEL_2, 1, 3, angle, 48);
	//__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, angle);
}

void leg2_1(int angle){

	if(angle < 0)
		 angle = 0;
	if(angle >180)
		angle = 180;
	angle = angle + 45;
	kademeliArttir(htim1, TIM_CHANNEL_3, 2, 1, angle, 45);
	//__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, angle);
}

void leg2_2(int angle){

	if(angle < 0)
		 angle = 0;
	if(angle >180)
		angle = 180;
	angle = angle + 47;
	kademeliArttir(htim5, TIM_CHANNEL_3, 2, 2, angle, 47);
	//__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_3, angle);
}

void leg2_3(int angle){

	if(angle < 0)
		 angle = 0;
	if(angle >180)
		angle = 180;
	angle = angle + 32;
	kademeliArttir(htim5, TIM_CHANNEL_1, 2, 3, angle, 32);
	//__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_1, angle);
}

void leg3_1(int angle){

	if(angle < 0)
		 angle = 0;
	if(angle >180)
		angle = 180;
	angle = angle + 40;
	kademeliArttir(htim4, TIM_CHANNEL_4, 3, 1, angle, 45);
	//__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, angle);

}

void leg3_2(int angle){

	if(angle < 0)
		 angle = 0;
	if(angle >180)
		angle = 180;
	angle = angle + 47;
	kademeliArttir(htim4, TIM_CHANNEL_2, 3, 2, angle, 47);
	//__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, angle);

}

void leg3_3(int angle){
	if(angle < 0)
		 angle = 0;
	if(angle >180)
		angle = 180;
	angle = angle + 37;
	kademeliArttir(htim3, TIM_CHANNEL_4, 3, 3, angle, 37);
	//__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, angle);
}

void leg4_1(int angle){

	if(angle < 0)
		 angle = 0;
	if(angle >180)
		angle = 180;
	angle = angle + 45;
	kademeliArttir(htim5, TIM_CHANNEL_2, 4, 1, angle, 45);
	//__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_2, angle);

}

void leg4_2(int angle){

	if(angle < 0)
		 angle = 0;
	if(angle >180)
		angle = 180;
	angle = angle + 40;//37
	kademeliArttir(htim1,TIM_CHANNEL_4, 4, 2, angle, 37);
	//__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, angle);

}

void leg4_3(int angle){

	if(angle < 0)
		 angle = 0;
	if(angle >180)
		angle = 180;
	angle = angle + 45;
	kademeliArttir(htim1, TIM_CHANNEL_1, 4, 3, angle, 45);
	//__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, angle);

}








void leg1_1_d(int angle){
	if(angle < 0)
		 angle = 0;
	if(angle >180)
		angle = 180;
	angle = angle + 35;
	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, angle);
}

void leg1_2_d(int angle){
	if(angle < 0)
		 angle = 0;
	if(angle >180)
		angle = 180;
	angle = angle + 48;
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, angle);
}

void leg3_1_d(int angle){

	if(angle < 0)
		 angle = 0;
	if(angle >180)
		angle = 180;
	angle = angle + 40;
	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, angle);

}

void leg3_2_d(int angle){

	if(angle < 0)
		 angle = 0;
	if(angle >180)
		angle = 180;
	angle = angle + 47;
	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, angle);

}



void robot_tims_init(void) {

	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);

	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);

	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_4);

	HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_3);

}


void scalingServo(void){

		leg1_1(a);
		HAL_Delay(100);
		leg1_1(b);
		HAL_Delay(100);
		leg1_1(c);
		HAL_Delay(100);
		leg1_1(d);
		HAL_Delay(100);
		leg1_1(e);
		HAL_Delay(100);

		leg1_2(a);
		HAL_Delay(100);
		leg1_2(b);
		HAL_Delay(100);
		leg1_2(c);
		HAL_Delay(100);
		leg1_2(d);
		HAL_Delay(100);
//		leg1_2(e);
		HAL_Delay(100);

//		leg1_3(a);
		HAL_Delay(100);
		leg1_3(b);
		HAL_Delay(100);
		leg1_3(c);
		HAL_Delay(100);
		leg1_3(d);
		HAL_Delay(100);
		leg1_3(e);
		HAL_Delay(100);
		leg1_3(f);
		HAL_Delay(100);

		leg2_1(a);
		HAL_Delay(100);
		leg2_1(b);
		HAL_Delay(100);
		leg2_1(c);
		HAL_Delay(100);
		leg2_1(d);
		HAL_Delay(100);
		leg2_1(e);
		HAL_Delay(100);

//		leg2_2(a);
		HAL_Delay(100);
		leg2_2(b);
		HAL_Delay(100);
		leg2_2(c);
		HAL_Delay(100);
		leg2_2(d);
		HAL_Delay(100);
		leg2_2(e);
		HAL_Delay(100);

		leg2_3(aa);
		HAL_Delay(100);
		leg2_3(a);
		HAL_Delay(100);
		leg2_3(b);
		HAL_Delay(100);
		leg2_3(c);
		HAL_Delay(100);
		leg2_3(d);
		HAL_Delay(100);
//		leg2_3(e);

		leg3_1(a);
		HAL_Delay(100);
		leg3_1(b);
		HAL_Delay(100);
		leg3_1(c);
		HAL_Delay(100);
		leg3_1(d);
		HAL_Delay(100);
		leg3_1(e);
		HAL_Delay(100);

//		leg3_2(a);
		HAL_Delay(100);
		leg3_2(b);
		HAL_Delay(100);
		leg3_2(c);
		HAL_Delay(100);
		leg3_2(d);
		HAL_Delay(100);
		leg3_2(e);
		HAL_Delay(100);

		leg3_3(aa);
		HAL_Delay(100);
		leg3_3(a);
		HAL_Delay(100);
		leg3_3(b);
		HAL_Delay(100);
		leg3_3(c);
		HAL_Delay(100);
		leg3_3(d);
		HAL_Delay(100);
//		leg3_3(e);
//		HAL_Delay(100);

		leg4_1(a);
		HAL_Delay(100);
		leg4_1(b);
		HAL_Delay(100);
		leg4_1(c);
		HAL_Delay(100);
		leg4_1(d);
		HAL_Delay(100);
		leg4_1(e);
		HAL_Delay(100);

		leg4_2(a);
		HAL_Delay(100);
		leg4_2(b);
		HAL_Delay(100);
		leg4_2(c);
		HAL_Delay(100);
		leg4_2(d);
		HAL_Delay(100);
//		leg4_2(e);
//		HAL_Delay(100);

//		leg4_3(a);
//		HAL_Delay(100);
		leg4_3(b);
		HAL_Delay(100);
		leg4_3(c);
		HAL_Delay(100);
		leg4_3(d);
		HAL_Delay(100);
		leg4_3(e);
		HAL_Delay(100);
		leg4_3(f);
		HAL_Delay(100);

}



void robot_all_leg_90(void) {

	int i = 90;

	leg1_1(i);
	HAL_Delay(500);
	leg1_2(i);
	HAL_Delay(500);
	leg1_3(i);
	HAL_Delay(1500);

	leg2_1(i);
	HAL_Delay(500);
	leg2_2(i);
	HAL_Delay(500);
	leg2_3(i);
	HAL_Delay(1500);

	leg3_1(i);
	HAL_Delay(500);
	leg3_2(i);
	HAL_Delay(500);
	leg3_3(i);
	HAL_Delay(1500);

	leg4_1(i);
	HAL_Delay(500);
	leg4_2(i);
	HAL_Delay(500);
	leg4_3(i);
	HAL_Delay(500);

}


void robot_all_leg_init(void) {

	leg1_1(115);
	HAL_Delay(500);
	leg1_2(120);
	HAL_Delay(500);
	leg1_3(140);
	HAL_Delay(500);

	leg4_1(115);
	HAL_Delay(500);
	leg4_2(120);
	HAL_Delay(500);
	leg4_3(140);
	HAL_Delay(500);

	leg2_1(65);
	HAL_Delay(500);
	leg2_2(60);
	HAL_Delay(500);
	leg2_3(40);
	HAL_Delay(500);

	leg3_1(65);
	HAL_Delay(500);
	leg3_2(60);
	HAL_Delay(500);
	leg3_3(40);
	HAL_Delay(500);

}



void initPosition() {

	leg1_3(d);
	HAL_Delay(initDelay);
	leg2_3(b);
	HAL_Delay(initDelay);
	leg3_3(b);
	HAL_Delay(initDelay);
	leg4_3(d);
	HAL_Delay(initDelay);

	leg1_2(b);
	HAL_Delay(initDelay);
	leg2_2(d);
	HAL_Delay(initDelay);
	leg3_2(d);
	HAL_Delay(initDelay);
	leg4_2(b);
	HAL_Delay(initDelay);

	leg1_1(b);
	HAL_Delay(initDelay);
	leg2_1(d);
	HAL_Delay(initDelay);
	leg3_1(d);
	HAL_Delay(initDelay);
	leg4_1(b);
	HAL_Delay(initDelay);

}

void moveForward() {

	leg2_2(e);
	HAL_Delay(forwardDelay);
	leg2_3(aa);
	leg2_1(c);
	HAL_Delay(forwardDelay);
	leg2_2(d);
	HAL_Delay(forwardDelay);

	leg1_3(c); //leg1_3(c + 20);
	leg3_3(aa);
	leg4_3(f);
	leg1_1(a);
	leg2_1(d);
	leg3_1(c);
	leg4_1(c); //	leg4_1(c + 10);
	HAL_Delay(forwardDelay);

	leg3_2(e);
	HAL_Delay(forwardDelay);
	leg3_3(c); //leg3_3(c - 20);
	leg3_1(d);
	HAL_Delay(forwardDelay);
	leg3_2(d);
	HAL_Delay(forwardDelay);

	leg1_2(a);
	HAL_Delay(forwardDelay);
	leg1_3(f);
	leg1_1(b);
	HAL_Delay(forwardDelay);
	leg1_2(b);
	HAL_Delay(forwardDelay);

	leg1_3(d); //  d   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	leg2_3(b);
	leg3_3(b);
	leg4_2(c);
	leg1_1(b);
	leg4_1(d + 10);
	HAL_Delay(forwardDelay);

	leg4_2(a);
	HAL_Delay(forwardDelay);
	leg4_3(d);
	leg4_1(b + 10);
	HAL_Delay(forwardDelay);
	leg4_2(b);
}
