

#include "StringUtilities.h"
#include "Accelerometer.h"
#include "Gyro.h"


short gyroX, gyroY, gyroZ;
short accelX, accelY, accelZ;




void DisplayIntegerValue(short value)
{
	char valueAsString[12];
	IntegerToString(value, valueAsString, BASE_10);

	short strlen = 0;
	while(valueAsString[strlen])
	{
		strlen++;
	}

	while(strlen < 7)
	{
		++strlen;
	}


}

void DisplayAxisValue(char* label, short accel, short gyro)
{

	DisplayIntegerValue(accel); 
	DisplayIntegerValue(gyro); 
}

void DisplayAxisValues()
{
	GetAccelerometerValues(&accelX, &accelY, &accelZ);

	GetGyroValues(&gyroX, &gyroY, &gyroZ);



}
