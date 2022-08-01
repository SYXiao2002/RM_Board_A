//
// Created by 沈逸潇 on 2022/7/28.
//

#ifndef RM_BOARD_A_GLOBAL_STATUS_H
#define RM_BOARD_A_GLOBAL_STATUS_H
/**
 * This file stores the global variables in this XJTLU_Torpedo project.
 */
#include "LEDs_onboard.h"
void GLOBAL_All_Status_Init();
extern uint8_t LED_OFF_NUM;




static uint8_t get_LEDs_ODR();
#endif //RM_BOARD_A_GLOBAL_STATUS_H
