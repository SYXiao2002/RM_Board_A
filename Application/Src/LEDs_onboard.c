//
// Created by 沈逸潇 on 2022/7/14.
//

#include "stm32f4xx_hal.h"
#include "LEDs_onboard.h"
#include "remote_control.h"
#include "main.h"

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
        HAL_GPIO_TogglePin(LEDs_onboard_GPIO_Port, DIODE_Pins[i]);
        HAL_Delay(LEDs_onboard_interval);
    }
    SwitchOffAllLEDs_onboard();
    HAL_Delay(LEDs_onboard_interval);
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

void RC_SwitchLED(){
    switch(rc_ctrl.rc.s[0]){
        case RC_SW_UP:
            SwitchOffAllLEDs_onboard();
            break;
        case RC_SW_MID:
            SwitchOnAllLEDs_onboard();
            break;
        case RC_SW_DOWN:
            SwitchOffAllLEDs_onboard();
            break;
        default :
            ShowWaterful();
    }

}