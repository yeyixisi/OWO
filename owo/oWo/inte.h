#ifndef _INTE_
#define _INTE_
#include "main.h"
struct keys{
	uchar jd;//判断执行阶段
	uchar key_sta;//接受引脚状态
	uchar oOo;//是否被摁下
	uint kt;//计时器
	uint lf;//是否被长摁
};
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
#endif