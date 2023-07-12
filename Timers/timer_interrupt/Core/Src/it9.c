/*
 * it.c
 *
 *  Created on: Mar 18, 2023
 *      Author: sri kanya rasi
 */


#include "stm32f4xx_hal.h"
#include "main.h"
extern TIM_HandleTypeDef htime6;
//Systick interrupt occurs at every 1 millisecond

void SysTick_Handler(void)
{
	HAL_IncTick();
	//TO  process the systik interrupt we call the cube api
	HAL_SYSTICK_IRQHandler();
}
void TIM6_DAC_IRQHandler()
{
	//INTERRUPT PROCESSING API

	HAL_TIM_IRQHandler(&htime6);
}
