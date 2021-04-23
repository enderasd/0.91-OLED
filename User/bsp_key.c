#include "bsp_key.h"  


void Key_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK|KEY2_GPIO_CLK,ENABLE);
	
	//ѡ�񰴼�������
	GPIO_InitStructure.GPIO_Pin = KEY1_GPIO_PIN; 

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 
	//ʹ�ýṹ���ʼ������
	GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStructure);
	
	//ѡ�񰴼�������
	GPIO_InitStructure.GPIO_Pin = KEY2_GPIO_PIN; 
	//���ð���������Ϊ��������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 
	//ʹ�ýṹ���ʼ������
	GPIO_Init(KEY2_GPIO_PORT, &GPIO_InitStructure);	
}


uint8_t Key1_Scan(void)
{			
	/*����Ƿ��а������� */
	if(GPIO_ReadInputDataBit(KEY1_GPIO_PORT,KEY1_GPIO_PIN) == KEY_ON )  
	{	 
		/*�ȴ������ͷ� */
		while(GPIO_ReadInputDataBit(KEY1_GPIO_PORT,KEY1_GPIO_PIN) == KEY_ON);   
		return 	KEY_ON;	 
	}
	else
		return KEY_OFF;
}
uint8_t Key2_Scan(void)
{			
	/*����Ƿ��а������� */
	if(GPIO_ReadInputDataBit(KEY2_GPIO_PORT,KEY2_GPIO_PIN) == KEY_ON )  
	{	 
		/*�ȴ������ͷ� */
		while(GPIO_ReadInputDataBit(KEY2_GPIO_PORT,KEY2_GPIO_PIN) == KEY_ON);   
		return 	KEY_ON;	 
	}
	else
		return KEY_OFF;
}
