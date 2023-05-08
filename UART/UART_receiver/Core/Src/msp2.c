/*
 * msp.c
 *
 *  Created on: Mar 18, 2023
 *      Author: sri kanya rasi
 */
//low level initialisation
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_UART.h"
void HAL_MspInit(void)
{
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);//1
	SCB->SHCSR |=0X7 << 16;//2)USAGE,memory,bus used
	HAL_NVIC_SetPriority(MemoryManagement_IRQn,0,0);
	HAL_NVIC_SetPriority(BusFault_IRQn,0,0);
	HAL_NVIC_SetPriority(UsageFault_IRQn,0,0);

}
void  HAL_UART_MspInit(UART_HandleTypeDef *huart)
{//here we are going ro do rthe low level initialization of pheripherals
	GPIO_InitTypeDef gpio_uart;
	__HAL_RCC_USART2_CLK_ENABLE(); // 1)enable clock for usart2
	__HAL_RCC_GPIOA_CLK_ENABLE();//CLOCK ENABLE FOR GPIO PIN

	//2nd step pin configuration
	gpio_uart.Pin =GPIO_PIN_2;
	gpio_uart.Mode =GPIO_MODE_AF_PP;
	gpio_uart.Pull =GPIO_PULLUP;
	gpio_uart.Speed = GPIO_SPEED_FREQ_LOW;
	gpio_uart.Alternate =GPIO_AF7_USART2;//uart2 tx
	HAL_GPIO_Init(GPIOA,&gpio_uart);

	gpio_uart.Pin =GPIO_PIN_3;
	HAL_GPIO_Init(GPIOA,&gpio_uart);

	//3 enable irq it is optioal
	HAL_NVIC_EnableIRQ(USART2_IRQn);
	HAL_NVIC_SetPriority(USART2_IRQn,15,0);


}
