#include "inte.h"
#include "i2c.h"
extern uint8_t redat[100];
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size){
		HAL_UART_Transmit_DMA(&huart1,redat,Size);
		uint8_t tmp[20];
		for(int i=0;i<20;i++){
			if(i<Size)tmp[i]=redat[i];
			else tmp[i]=' ';
		}
		
		
		RES_Write(Size);
		for(int i=0;i<Size;i++)ee_write(i+1,tmp[i]);
		for(int i=0;i<Size;i++)tmp[i]=ee_read(i+1);
		LCD_DisplayStringLine(Line0,tmp);
		ee_write(20,Size);
		ctrl(Size);
	
		HAL_UARTEx_ReceiveToIdle_DMA(&huart1,redat,100);
		
}
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	HAL_UART_Transmit_DMA(&huart1,redat,2);
	HAL_UART_Receive_DMA(&huart1,redat,2);
}