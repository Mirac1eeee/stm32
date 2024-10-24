#include "Delay.h"


/**
  * @brief 微秒级延时
  * @param time： 单位：us 取值范围：0~233016
  */
void Delay_us(uint32_t time){
	/*配置SysTick控制及状态寄存器*/
	SysTick->CTRL = 0x00000005;				//使能定时器  采用内核时钟FCLK：72MHz
	
	/*配置SysTick重装载数值寄存器*/
	SysTick->LOAD = 72*time;				
	
	/*配置SysTick当前数值寄存器*/
	SysTick->VAL  = 0;
	
	while(SysTick->CTRL != 0x00010005);		//COUNTFLAG == 1 [16]
	SysTick->CTRL = 0;	//关闭定时器
	
}

