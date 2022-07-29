//
// Created by 沈逸潇 on 2022/7/14.
//

#ifndef RM_BOARD_A_LEDS_ONBOARD_H
#define RM_BOARD_A_LEDS_ONBOARD_H
#include "stm32f427xx.h"
#include "GLOBAL_status.h"
#include "remote_control.h"
#include "main.h"
#include "cmsis_os.h"
#include "usbd_cdc_if.h"


#define LEDs_onboard_GPIO_Port GPIOG
#define LEDs_onboard_NUM 8                      //the number of all diodes onboard
#define ShowWaterful_INTERVAL 1000               //the time interval

typedef enum{
    LED_H=LED_onboard_H_Pin,
    LED_G=LED_onboard_G_Pin,
    LED_F=LED_onboard_F_Pin,
    LED_E=LED_onboard_E_Pin,
    LED_D=LED_onboard_D_Pin,
    LED_C=LED_onboard_C_Pin,
    LED_B=LED_onboard_B_Pin,
    LED_A=LED_onboard_A_Pin,
}LEDs_Id_t;

typedef enum{
    ON = GPIO_PIN_RESET,
    OFF = GPIO_PIN_SET,
    TOGGLE,
}LED_Status_t;

typedef enum{
    ALLOn,
    ALLOff,
    ALLToggle,
    ShowWaterful,
}LEDs_events;

void LEDs_CTRL_Manually(LEDs_Id_t LED_id, LED_Status_t LED_status);
void LEDs_CTRL_Events(LEDs_events event);

void LEDs_CTRL_by_Remote_DT7();
void LEDs_CTRL_by_SHELL_USB();



#endif //RM_BOARD_A_LEDS_ONBOARD_H
