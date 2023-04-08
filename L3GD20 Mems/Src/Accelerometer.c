

#include "RegisterAddresses.h"

#define ACCELEROMETER_READ  0x33
#define ACCELEROMETER_WRITE 0x32

void I2CStartRestart()
{
	ACCESS(I2C1_CR1) |= (1 << 8);
}

void I2CStop()
{

	ACCESS(I2C1_CR1) |= (1 << 9);
}

void I2CEnableAcknowledge()
{

	ACCESS(I2C1_CR1) |= (1 << 10);
}

void I2CDisableAcknowledge()
{
	ACCESS(I2C1_CR1) &= ~(1 << 10);
}

void I2CSendSlaveAddress(unsigned short address)
{
	while((ACCESS(I2C1_SR1) & 1) == 0);

	ACCESS(I2C1_DR) = address;

	while((ACCESS(I2C1_SR1) & (1 << 1)) == 0);

	ACCESS(I2C1_SR1);
	ACCESS(I2C1_SR2);
}

void I2CSendRegister(unsigned short registerAddress)
{
	while((ACCESS(I2C1_SR1) & (1 << 7)) == 0);

	ACCESS(I2C1_DR) = registerAddress;

	while((ACCESS(I2C1_SR1) & (1 << 7)) == 0);
}

void I2CWaitIfBusy()
{
	while((ACCESS(I2C1_SR2) & (1 << 1)) == (1 << 1));
}

void I2CWriteByte(unsigned char data)
{
	ACCESS(I2C1_DR) = data;

	while((ACCESS(I2C1_SR1) & (1 << 2)) == 0);
}

unsigned char I2CGetData()
{
	while((ACCESS(I2C1_SR1) & (1 << 6)) == 0) { }

	return ACCESS(I2C1_DR);
}

unsigned char ReadFromAccelerometer(unsigned short registerAddress)
{
	I2CWaitIfBusy();

	I2CEnableAcknowledge();

	I2CStartRestart();

	I2CSendSlaveAddress(ACCELEROMETER_WRITE);

	I2CSendRegister(registerAddress);

	I2CStartRestart();

	I2CSendSlaveAddress(ACCELEROMETER_READ);

	I2CDisableAcknowledge();

	I2CStop();

	return I2CGetData();
}

void WriteToAccelerometer(unsigned short registerAddress, unsigned char data)
{
	I2CWaitIfBusy();

	I2CStartRestart();

	I2CSendSlaveAddress(ACCELEROMETER_WRITE);

	I2CSendRegister(registerAddress);

	I2CWriteByte(data);

	I2CStop();
}


void AccelerometerInit()
{

	ACCESS(RCC_AHB1ENR) |= (1 << 1);

	ACCESS(GPIOB_MODER) |= ((1 << 13) | (1 << 19));


	ACCESS(GPIOB_AFRL) |= (4 << 24);
	ACCESS(GPIOB_AFRH) |= (4 << 4);

	ACCESS(GPIOB_OSPEEDR) |= ((2 << 12) | (2 << 18));

	ACCESS(RCC_APB1ENR) |= (1 << 21);

	ACCESS(I2C1_CR2) &= ~(0x3F);
	ACCESS(I2C1_CR2) |= (0x02);


	ACCESS(I2C1_CCR) &= ~(0xFFF);
	ACCESS(I2C1_CCR) |= 0x50;


	ACCESS(I2C1_TRISE) &= ~(0x3F);
	ACCESS(I2C1_TRISE) |= 0x03;


	ACCESS(I2C1_OAR1) |= ((0x21 << 1) | (1 << 14));

	ACCESS(I2C1_CR1) |= 1;


	unsigned char accelerometerID = ReadFromAccelerometer(0xF);
	if(accelerometerID != 0x33)
	{
	}


	WriteToAccelerometer(0x20, 0x47);
}

void GetAccelerometerValues(short* x, short* y, short* z)
{
	*x = ((ReadFromAccelerometer(0x29) << 8) | ReadFromAccelerometer(0x28));
	*y = ((ReadFromAccelerometer(0x2B) << 8) | ReadFromAccelerometer(0x2A));
	*z = ((ReadFromAccelerometer(0x2D) << 8) | ReadFromAccelerometer(0x2C));
}
