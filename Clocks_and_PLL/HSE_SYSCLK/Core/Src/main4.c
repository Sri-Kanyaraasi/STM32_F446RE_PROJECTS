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
#include<stdio.h>
#define TRUE 1
#define FALSE 0

void SystemClockConfig(void);
void UART2_Init(void);
void Error_Handler(void);
uint8_t convert_to_capital(uint8_t data);

UART_HandleTypeDef huart2;

/*char *user_data="the application is running\r\n";
uint8_t data_buffer[100];
uint8_t recvd_data;
uint32_t count=0;
uint8_t reception_complete = FALSE;*/
char *user_data="hello world\r\n";

int main(void)
{
	HAL_Init();
	SystemClockConfig();
	UART2_Init();


	//uint16_t len_of_data = strlen(user_data);
	HAL_UART_Transmit(&huart2,(uint8_t*)user_data,strlen(user_data),HAL_MAX_DELAY);

	/*while(reception_complete!=TRUE)
	{
	HAL_UART_Receive_IT(&huart2,&recvd_data,1);
	}*/

	while(1);

	return 0;
}


void SystemClockConfig(void)
{

}

void UART2_Init(void)
{
	huart2.Instance=USART2;
	huart2.Init.BaudRate =115200;
	huart2.Init.WordLength = UART_WORDLENGTH_8B;
	huart2.Init.StopBits=UART_STOPBITS_1;
	huart2.Init.Parity=UART_PARITY_NONE;
	huart2.Init.HwFlowCtl=UART_HWCONTROL_NONE;
	huart2.Init.Mode=UART_MODE_TX_RX;
	if (HAL_UART_Init(&huart2)!=HAL_OK)
	{
		//there is a problem
		Error_Handler();
	}
}



void Error_Handler(void)
{
	while(1);
}
