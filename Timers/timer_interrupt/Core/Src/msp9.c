/*
 * msp.c
 *
 *  Created on: Mar 18, 2023
 *      Author: sri kanya rasi
 */
//low level initialisation
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_UART.h"
#include "main.h"
void HAL_MspInit(void)
{
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);//1
	SCB->SHCSR |=0X7 << 16;//2)USAGE,memory,bus used
	HAL_NVIC_SetPriority(MemoryManagement_IRQn,0,0);
	HAL_NVIC_SetPriority(BusFault_IRQn,0,0);
	HAL_NVIC_SetPriority(UsageFault_IRQn,0,0);

}
void  HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htimer)
{
	//1. enable the clock for the time6 pheripheral
	__HAL_RCC_TIM6_CLK_ENABLE();

	//2.enable of irq

	HAL_NVIC_EnableIRQ(TIM6_DAC_IRQn);

	//set up the priority
	HAL_NVIC_SetPriority(TIM6_DAC_IRQn,15,0);
}
