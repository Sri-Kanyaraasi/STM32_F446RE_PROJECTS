#include "stm32f4xx_hal.h"
//Systick interrupt occurs at every 1 millisecond
extern UART_HandleTypeDef huart2;
void SysTick_Handler(void)
{
	HAL_IncTick();
	//TO  process the systik interrupt we call the cube api
	HAL_SYSTICK_IRQHandler();
}

void USART2_IRQHandler(void)
{
	HAL_UART_IRQHandler(&huart2);
}
