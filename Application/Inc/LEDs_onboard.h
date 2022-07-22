//
// Created by 沈逸潇 on 2022/7/14.
//

#ifndef RM_BOARD_A_LEDS_ONBOARD_H
#define RM_BOARD_A_LEDS_ONBOARD_H

#define LEDs_onboard_GPIO_Port GPIOG
#define LEDs_onboard_NUM 8                      //the number of all diodes onboard
#define LEDs_onboard_interval 200               //the time interval

void ShowWaterful();
void SwitchOffAllLEDs_onboard();
void SwitchOnAllLEDs_onboard();
void RC_SwitchLED();

#endif //RM_BOARD_A_LEDS_ONBOARD_H
