#include "stm32f10x.h"  
#include "bsp_i2c_gpio.h"
#include "bsp_usart.h"
#include "SSD1306.h"

extern OLED_IN OLED_In;
static void BSP_Init(void);

int main(void)
{	
	
	uint16_t i;

  BSP_Init();
	OLED_Refresh();
	OLED_In.buff_in[0] ="a0";
	OLED_In.buff_in[1] ="b1";
	OLED_In.buff_in[2] ="c2";
	OLED_In.buff_in[3] ="d3";
	OLED_In.buff_in[4] ="e4";
	OLED_In.buff_in[5] ="f5";	
	OLED_In.buff_in[6] ="a6";
	OLED_In.buff_in[7] ="b7";
	OLED_In.buff_in[8] ="c8";
	OLED_In.buff_in[9] ="d9";
	OLED_In.buff_in[10] ="10";
	OLED_In.buff_in[11] ="11";	
	
	OLED_Refresh();
//	OLED_ShowString(0,0,"hhhhhh",16);
	while(1){
  OLED_ShowON(12);
    }

}

static void BSP_Init(void)
{
	Key_GPIO_Config();
	USART_Config();
  OLED_Config();
}