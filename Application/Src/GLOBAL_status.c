//
// Created by 沈逸潇 on 2022/7/28.
//
#include "GLOBAL_status.h"

void GLOBAL_All_Status_Init(){

}

uint8_t LED_OFF_NUM=2;

/*
 * Global variable for LEDs_onboard unit.
 *
 *                Output Data Register(ODR)
 * Bit:  15 14 13 12    11 10 9 8      7 6 5 4     3 2 1 0
 * LED:                         A      B C D E     F G H
 *                      After ">> 1"
 * Bit:  xx 15 14 13    12 11 10 9     8 7 6 5     4 3 2 1
 * LED:                                A B C D     E F G H
 *
 * E.g.     "00000010(Binary)"="2(Decimal)"="2(Hex)" represents that
 *          only the LED_G is switched on, others are switched off.
 */
uint8_t get_LEDs_ODR(){
    return LEDs_onboard_GPIO_Port->ODR >> 1;
    //    usb_printf("%x\r\n", get_LEDs_ODR());
}

