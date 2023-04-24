/*
 * PID.c
 *
 *  Created on: Jan 12, 2023
 *      Author: Bilal Habes Akcam
 */


#include "PID.h"
#include "SpiderDriver.h"
#include "timer.h"

// P, I, D Katsayilari

#define KP 0.002
#define KI 0.00001
#define KD 0.025

double Pid_I, Last_Error;
double Control_Signal;
unsigned long DeltaTime;


extern int a;
extern int b;
extern int c;
extern int d;
extern int e;



void resetPidVariables() {

  int Pid_I = 0;
  int last_error = 0;

}


double getControlSignal(double error, double kp, double ki, double kd, double pid_i, double last_error) {
  double pid_p = error;
  double pid_d = (error - last_error) / 12;
  pid_i += error * 12;

  double control_signal = (kp*pid_p) + (ki*pid_i) + (kd*pid_d);
  last_error = error;
  return control_signal;

}


void calcMotorPower(short x) {

	double Error = 200 - x;

	Control_Signal = getControlSignal(Error, KP, KI, KD,
			Pid_I, Last_Error);

	leg1_2(b - Control_Signal);
	leg1_1(b - Control_Signal);
	leg3_2(d + Control_Signal);
	leg3_1(d + Control_Signal);


	leg2_2(d - Control_Signal);
	leg2_1(d - Control_Signal);
	leg4_2(b + Control_Signal);
	leg4_1(b + Control_Signal);



}










