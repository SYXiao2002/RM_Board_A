//
// Created by 沈逸潇 on 2022/7/14.
//

#include "stm32f4xx_hal.h"
#include "LEDs_onboard.h"
#include "main.h"

#define LEDs_onboard_GPIO_Port GPIOG
#define LEDs_onboard_NUM 8                      //the number of all diodes onboard
#define LEDs_onboard_interval 200               //the time interval

uint16_t DIODE_Pins[LEDs_onboard_NUM]={
        LED_onboard_A_Pin,
        LED_onboard_B_Pin,
        LED_onboard_C_Pin,
        LED_onboard_D_Pin,
        LED_onboard_E_Pin,
        LED_onboard_F_Pin,
        LED_onboard_G_Pin,
        LED_onboard_H_Pin,
};

void ShowWaterful(){
    for (int i=0; i<LEDs_onboard_NUM;i++){
        HAL_Delay(LEDs_onboard_interval);
        HAL_GPIO_TogglePin(LEDs_onboard_GPIO_Port, DIODE_Pins[i]);
    }
    SwitchOffAllLEDs_onboard();
}

void SwitchOffAllLEDs_onboard(){
    for (int i=0; i<LEDs_onboard_NUM;i++){
        HAL_GPIO_WritePin(LEDs_onboard_GPIO_Port, DIODE_Pins[i], GPIO_PIN_SET);
    }
}

void SwitchOnAllLEDs_onboard(){
    for (int i=0; i<LEDs_onboard_NUM;i++){
        HAL_GPIO_WritePin(LEDs_onboard_GPIO_Port, DIODE_Pins[i], GPIO_PIN_RESET);
    }
}