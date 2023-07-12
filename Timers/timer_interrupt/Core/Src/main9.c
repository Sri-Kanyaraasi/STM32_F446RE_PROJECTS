
/*
 * main.c
 *
 *  Created on: Mar 18, 2023
 *      Author: sri kanya rasi
 */


#include "stm32f4xx_hal.h"
#include "main.h"
#include "stm32f4xx_hal_UART.h"
#include <string.h>

void SystemClockConfig(void);

void Error_Handler(void);
void time6_init(void);
void GPIO_Init(void);

TIM_HandleTypeDef htime6;

int main(void)
{
	HAL_Init();
	SystemClockConfig();
	GPIO_Init();
	time6_init();

	//start timer
	HAL_TIM_Base_Start_IT(&htime6);
	while(1);

	return 0;
}


void SystemClockConfig(void)
{

}

void GPIO_Init(void)
{
	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIO_InitTypeDef ledgpio;
	ledgpio.Pin = GPIO_PIN_5;
	ledgpio.Mode = GPIO_MODE_OUTPUT_PP;
	ledgpio.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA,&ledgpio);
}
void time6_init(void)
{
	htime6.Instance = TIM6;
	htime6.Init.Prescaler =24;
	htime6.Init.Period = 64000-1; //give one number less than the calculated one
	if(HAL_TIM_Base_Init(&htime6)!=HAL_OK)
	{
		Error_Handler();
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htime6)
{
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
}


void Error_Handler(void)
{
	while(1);
}
