//
// Created by 沈逸潇 on 2022/7/28.
//
#include "GLOBAL_status.h"

void GLOBAL_All_Status_Init(){
	GLOBAL_OLED_Pre_Setting();
	Fused_LEDs_IO.Init();
}

void GLOBAL_OLED_Pre_Setting(){
	ST7735_DrawString(0, 0, "Total ", green);
	ST7735_DrawString(7, 0, " LEDs are lighting!", green);
}
