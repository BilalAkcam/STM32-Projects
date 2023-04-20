

#include "RegisterAddresses.h"
#include <stdint.h>

void WaitForSPI1RXReady()
{

	while((ACCESS(SPI1_SR) & 1) == 0 || (ACCESS(SPI1_SR) & (1 << 7)) == 1) { }
}

void WaitForSPI1TXReady()
{
	while((ACCESS(SPI1_SR) & (1 << 1)) == 0 || (ACCESS(SPI1_SR) & (1 << 7)) == 1) { }
}



unsigned char ReadFromGyro(unsigned char gyroRegister)
{
	ACCESS(GPIOE_BSRR) |= (1 << 19);
	WaitForSPI1TXReady();
	ACCESS(SPI1_DR) = (gyroRegister | 0x80);
	WaitForSPI1RXReady();
	ACCESS(SPI1_DR);
	WaitForSPI1TXReady();
	ACCESS(SPI1_DR) = 0xFF;
	WaitForSPI1RXReady();
	volatile unsigned char readValue = (unsigned char)ACCESS(SPI1_DR);
	ACCESS(GPIOE_BSRR) |= (1 << 3);

	return readValue;
}

void WriteToGyro(unsigned char gyroRegister, unsigned char value)
{
	ACCESS(GPIOE_BSRR) |= (1 << 19);
	WaitForSPI1TXReady();
	ACCESS(SPI1_DR) = gyroRegister;
	WaitForSPI1RXReady();
	ACCESS(SPI1_DR);
	WaitForSPI1TXReady();
	ACCESS(SPI1_DR) = value;
	WaitForSPI1RXReady();
	ACCESS(SPI1_DR);
	ACCESS(GPIOE_BSRR) |= (1 << 3);
}

void GyroInit()
{

	ACCESS(RCC_AHB1ENR) |= 1;


	ACCESS(RCC_AHB1ENR) |= (1 << 4);


	ACCESS(GPIOA_MODER) |= ((1 << 11) | (1 << 13) | (1 << 15));
	ACCESS(GPIOE_MODER) |= (1 << 6);

	ACCESS(GPIOA_AFRL) |= ((5 << 20) | (5 << 24) | (5 << 28));

	ACCESS(GPIOA_OSPEEDR) |= ((2 << 10) | (2 << 12) | (2 << 14));
	ACCESS(GPIOE_OSPEEDR) |= (2 << 6);

	ACCESS(RCC_APB2ENR) |= (1 << 12);


	ACCESS(SPI1_CR1) |= (1 | (1 << 1) | (1 << 2) | (2 << 3) | (1 << 8) | (1 << 9));

	ACCESS(SPI1_CR1) |= (1 << 6);

	ACCESS(GPIOE_BSRR) |= (1 << 3);

	if(ReadFromGyro(0x0F) != 0xD4)
	{
	}

	WriteToGyro(0x20, 0x0F);
}

short GetAxisValue(unsigned char lowRegister, unsigned char highRegister)
{

	double scaler = 8.75 * 0.001;
	short temp = (ReadFromGyro(lowRegister) | (ReadFromGyro(highRegister) << 8));
	return (short)((double)temp * scaler);
}

void GetGyroValues(short* x, short* y, short* z)
{
	*x = GetAxisValue(0x28, 0x29);
	*y = GetAxisValue(0x2A, 0x2B);
	*z = GetAxisValue(0x2C, 0x2D);
}
