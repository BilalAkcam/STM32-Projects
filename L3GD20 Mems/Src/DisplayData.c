

#include "StringUtilities.h"
#include "Accelerometer.h"
#include "Gyro.h"


short gyroX, gyroY, gyroZ;
short accelX, accelY, accelZ;



void DisplayHeader()
{
	SendString("    Accel   Gyro\r\n");
}

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
		SendString(" ");
		++strlen;
	}

	SendString(valueAsString);
}

void DisplayAxisValue(char* label, short accel, short gyro)
{
	SendString(label);
	SendString(":");
	DisplayIntegerValue(accel); 
	DisplayIntegerValue(gyro); 
}

void DisplayAxisValues()
{
	GetAccelerometerValues(&accelX, &accelY, &accelZ);

	GetGyroValues(&gyroX, &gyroY, &gyroZ);



}
