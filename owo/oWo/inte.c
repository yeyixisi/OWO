#include "inte.h"
struct keys key[4]={0};
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance==TIM3){
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