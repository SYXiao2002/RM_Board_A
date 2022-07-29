//
// Created by 沈逸潇 on 2022/7/14.
//

#include "LEDs_onboard.h"

/**
 * Roughly spend less time by omitting the GPIO Port...
 * @param LED_id [A,B,...,G]
 * @param LED_status {ON, OFF}
 */
void LEDs_CTRL_Manually(LEDs_Id_t LED_id, LED_Status_t LED_status){
    switch (LED_status) {
        case TOGGLE:
            HAL_GPIO_TogglePin(LEDs_onboard_GPIO_Port, LED_id);
            break;
        case OFF:
            LEDs_onboard_GPIO_Port->BSRR = LED_id;
            break;
        case ON:
            LEDs_onboard_GPIO_Port->BSRR = (uint32_t)LED_id << 16U;
            break;
    }
}

/**
 * Preset display functions for LEDs, including switching them all off/on, or show waterful...
 * @param event {ALLOn, ALLOff, ALLToggle, ShowWaterful}
 */
void LEDs_CTRL_Events(LEDs_events event){
    switch (event) {
        case ALLOn:
            LEDs_onboard_GPIO_Port->ODR=0x00000000;
            break;
        case ALLOff:
            LEDs_onboard_GPIO_Port->ODR=~0x00000000;
            break;
        case ALLToggle:
            LEDs_onboard_GPIO_Port->ODR = ~LEDs_onboard_GPIO_Port->ODR;
            break;
        case ShowWaterful:
            for(LEDs_Id_t temp = LED_H; temp <= LED_A; temp <<= 1U) {
                LEDs_CTRL_Manually(temp, TOGGLE);
                osDelay(ShowWaterful_INTERVAL);
            }
            break;
    }
}

/**
 * Switch the LEDs by remote control, via DT7&DR16 from DJI.
 */
void LEDs_CTRL_by_Remote_DT7(){
    switch(get_remote_control_point()->rc.s[0]){
        case RC_SW_UP:
            break;
        case RC_SW_MID:
            break;
        case RC_SW_DOWN:
            break;
        default :
            break;
    }
}


/**
 * Switch the LEDs by shell command, via USB_OTG_FS from Virtual COM Port(VCP).
 */
void LEDs_CTRL_by_SHELL_USB(){
    //control the LEDs by SHELL via USB_OTG_FS
}
