#include "bsp_i2c_gpio.h"
static void i2c_Delay(void)
{
	uint8_t i;
	for (i = 0; i < 10; i++);
}


void i2c_Start(void)
{
	SDA_1();
	SCL_1();
	i2c_Delay();
	SDA_0();
	i2c_Delay();
	SCL_0();
	i2c_Delay();
}


void i2c_Stop(void)
{
	SDA_0();
	SCL_1();
	i2c_Delay();
	SDA_1();
}

void i2c_SendByte(uint8_t _ucByte)
{
	uint8_t i;

	for (i = 0; i < 8; i++)
	{		
		if (_ucByte & 0x80)
		{
			SDA_1();
		}
		else
		{
			SDA_0();
		}
		i2c_Delay();
		SCL_1();
		i2c_Delay();	
		SCL_0();
		if (i == 7)
		{
			 SDA_1();
		}
		_ucByte <<= 1;
		i2c_Delay();
	}
}



uint8_t i2c_WaitAck(void)
{
	
	SCL_1();
	SCL_0();
}


 void i2c_CfgGpio(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_PORT, ENABLE);
  	GPIO_PinRemapConfig(GPIO_Remap_I2C1,ENABLE);
	GPIO_InitStructure.GPIO_Pin = SCL_PIN | SDA_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD; 
	GPIO_Init(GPIO_PORT, &GPIO_InitStructure);

	SCL_0();
	SDA_0();
}

