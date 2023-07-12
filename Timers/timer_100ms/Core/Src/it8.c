/*
 * it.c
 *
 *  Created on: Mar 18, 2023
 *      Author: sri kanya rasi
 */


#include "stm32f4xx_hal.h"
#include "main.h"
//Systick interrupt occurs at every 1 millisecond
extern UART_HandleTypeDef huart2;
void SysTick_Handler(void)
{
	HAL_IncTick();
	//TO  process the systik interrupt we call the cube api
	HAL_SYSTICK_IRQHandler();
}

