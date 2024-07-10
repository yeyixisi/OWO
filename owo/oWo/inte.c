#include "inte.h"
struct keys key[4]={0};
//这里定义了一个名为key的数组，它由4个struct keys类型的元素组成，并初始化为0。
	//这通常意味着每个元素将包含默认值0，即所有的成员变量被初始化为0或它们的默认状态。
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	//这是一个函数定义，当与htim相关的定时器周期结束时，
	//此函数将被调用。在STM32 HAL库中，这是用于处理定时器中断的标准回调函数。
	if(htim->Instance==TIM3){
		//接下来是一个循环，遍历key数组中的所有元素。对于每个元素，根据jd（可能是"Judge"的缩写，用于判断按键状态）和key_sta（按键状态）的当前值，执行以下操作：

//如果jd为0且key_sta为低电平，则设置jd为1，并重置kt为0。
//如果jd为1且key_sta仍然为低电平，则将jd设置为2。
//如果jd为2且key_sta变为高电平，则检查kt是否小于70。如果是，则设置oOo（可能表示按键按下事件）为1
//		；否则，如果kt达到或超过70，则设置lf（可能表示长按事件）为1，并重置jd为0。
		key[0].key_sta=HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0);
		key[1].key_sta=HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_1);
		key[2].key_sta=HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_2);
		key[3].key_sta=HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0);
		for(int i=0;i<4;i++){
			if(key[i].jd==0){
				if(key[i].key_sta==0)key[i].jd=1,key[i].kt=0;
			}
			else if(key[i].jd==1){
				if(key[i].key_sta==0)key[i].jd=2;
				else key[i].jd=0;
			}
			else if(key[i].jd==2){
				if(key[i].key_sta==1){
					key[i].jd=0;
					if(key[i].kt<70)key[i].oOo=1;
				}
				else {
					key[i].kt++;
					if(key[i].kt>=70)key[i].lf=1,key[i].jd=0;
				}
			}
		}
	}
}
extern uint8_t receiveData[100];
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size){
	
		HAL_UART_Transmit_DMA(&huart1,receiveData,Size);
		uint8_t tmp[20];
		for(int i=0;i<20;i++){
			if(i<Size)tmp[i]=receiveData[i];
			else tmp[i]=' ';
		}
		LCD_DisplayStringLine(Line0,tmp);
		HAL_UARTEx_ReceiveToIdle_DMA(&huart1,receiveData,100);
		
}
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	HAL_UART_Transmit_DMA(&huart1,receiveData,2);
	HAL_UART_Receive_DMA(&huart1,receiveData,2);
}