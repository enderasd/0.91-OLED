#ifndef _BSP_I2C_GPIO_H
#define _BSP_I2C_GPIO_H


#include <inttypes.h>
#include "stm32f10x.h"

/*
i2c¶Ë¿ÚÅäÖÃ
*/

#define GPIO_PORT	GPIOB		
#define RCC_PORT 	RCC_APB2Periph_GPIOB	
#define SCL_PIN		GPIO_Pin_10		
#define SDA_PIN		GPIO_Pin_11	



#if 1
	#define SCL_1()  GPIO_SetBits(GPIO_PORT, SCL_PIN)		/* SCL = 1 */
	#define SCL_0()  GPIO_ResetBits(GPIO_PORT, SCL_PIN)		/* SCL = 0 */
	
	#define SDA_1()  GPIO_SetBits(GPIO_PORT, SDA_PIN)		/* SDA = 1 */
	#define SDA_0()  GPIO_ResetBits(GPIO_PORT, SDA_PIN)		/* SDA = 0 */
	
	#define SDA_READ()  GPIO_ReadInputDataBit(GPIO_PORT, SDA_PIN)	/* ¶ÁSDA¿ÚÏß×´Ì¬ */
#else
	#define SCL_1()  GPIO_PORT->BSRR = SCL_PIN				/* SCL = 1 */
	#define SCL_0()  GPIO_PORT->BRR = SCL_PIN				/* SCL = 0 */
	
	#define SDA_1()  GPIO_PORT->BSRR = SDA_PIN				/* SDA = 1 */
	#define SDA_0()  GPIO_PORT->BRR = SDA_PIN				/* SDA = 0 */
	
	#define SDA_READ()  ((GPIO_PORT->IDR & SDA_PIN) != 0)	/* ¶ÁSDA¿ÚÏß×´Ì¬ */
#endif


void i2c_Start(void);
void i2c_Stop(void);
void i2c_SendByte(uint8_t _ucByte);
uint8_t i2c_WaitAck(void);


void i2c_CfgGpio(void);

#endif

