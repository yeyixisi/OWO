#ifndef _INTE_
#define _INTE_
#include "main.h"
struct keys{
	uchar jd;
	uchar key_sta;
	uchar oOo;
	uint kt;
	uint lf;
};
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
#endif