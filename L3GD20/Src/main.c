#include "Accelerometer.h"
#include "Gyro.h"
#include "DisplayData.h"

#define DELAY_LENGTH  100000

void InitializeGyro();
void InitializeAccel();
void Delay();

int main()
{
	InitializeGyro();
	InitializeAccel();

	while(1)
	{
		DisplayAxisValues();
		Delay();
	}

	return 0;
}

void InitializeGyro()
{
	GyroInit();
}

void InitializeAccel()
{
	AccelerometerInit();
}

void Delay()
{
	for(volatile int i = 0; i < DELAY_LENGTH; ++i);
}
