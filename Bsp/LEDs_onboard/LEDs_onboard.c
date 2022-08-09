//
// Created by 沈逸潇 on 2022/7/14.
//

#include "LEDs_onboard.h"
#include "cmsis_os.h"
#include "usbd_cdc_if.h"

#define LEDs_onboard_GPIO_Port GPIOG
#define LEDs_onboard_NUM 8                      //the number of all diodes onboard
#define ShowWaterful_INTERVAL 400               //the time interval
#define LEDs_Ok 0
#define LEDs_Error 1

static void LEDs_onboard_Init();
static uint8_t LEDs_onboard_WriteODR(uint8_t Reg_ODR);
static uint8_t LEDs_onboard_WriteWaterfulNum(uint8_t number);
static uint8_t LEDs_onboard_GetODR();

static void LEDs_onboard_AllOn();
static void LEDs_onboard_AllOff();
static void LEDs_onboard_AllToggle();
static void LEDs_onboard_ShowWaterful();
static void LEDs_onboard_ShowBlink();


LEDs_onboard_IO_t Fused_LEDs_IO={
		LEDs_onboard_Init,
		LEDs_onboard_WriteODR,
		LEDs_onboard_WriteWaterfulNum,
		LEDs_onboard_GetODR,
		6,
		//todo: read it initially from flash, and every time changed, write it into the flash too.
};

LEDs_onboard_Driver_t Fused_LEDs_Display={
		LEDs_onboard_AllOn,
		LEDs_onboard_AllOff,
		LEDs_onboard_AllToggle,
		LEDs_onboard_ShowWaterful,
		LEDs_onboard_ShowBlink,
};




void LEDs_onboard_Init(){
	LEDs_onboard_ShowBlink();
}

uint8_t LEDs_onboard_WriteODR(uint8_t Reg_ODR){
	uint32_t temp = Reg_ODR;
	LEDs_onboard_GPIO_Port->ODR= (temp << 1U);
	return LEDs_Ok;
}

uint8_t LEDs_onboard_WriteWaterfulNum(uint8_t number){
	if(number > LEDs_onboard_NUM || number < 1){
		usb_printf("[WARNING] Waterful Number should between 1 and 8\r\n");
		return LEDs_Error;
	}

	Fused_LEDs_IO.WaterfulNum = number;
	usb_printf("[SUCCEED] Enlighten %d LEDs!\r\n", Fused_LEDs_IO.WaterfulNum);

	return LEDs_Ok;
}

uint8_t LEDs_onboard_GetODR(){
	return (LEDs_onboard_GPIO_Port->ODR >> 1U);
}

void LEDs_onboard_AllOn(){
	LEDs_onboard_GPIO_Port->ODR=0x00000000;
}

void LEDs_onboard_AllOff(){
	LEDs_onboard_GPIO_Port->ODR=~0x00000000;
}

void LEDs_onboard_AllToggle(){
	LEDs_onboard_GPIO_Port->ODR = ~LEDs_onboard_GPIO_Port->ODR;
}

void LEDs_onboard_ShowWaterful(){
	LEDs_onboard_AllOff();
	for(LEDs_Id_t temp = LED_H >> 1U; temp < (LED_H << Fused_LEDs_IO.WaterfulNum); temp <<= 1U) {
		LEDs_CTRL_Manually(temp, ON);
		osDelay(ShowWaterful_INTERVAL);
	}
}

void LEDs_onboard_ShowBlink(){
	for (int i = 0; i <= 6; ++i) {
		HAL_Delay(100);
		LEDs_onboard_AllOff();
		HAL_Delay(100);
		LEDs_onboard_AllOn();
	}
}


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


///**
// * Switch the LEDs by remote control, via DT7&DR16 from DJI.
// */
//void LEDs_CTRL_by_Remote_DT7(){
//    switch(get_remote_control_point()->rc.s[0]){
//        case RC_SW_UP:
//            break;
//        case RC_SW_MID:
//            break;
//        case RC_SW_DOWN:
//            break;
//        default :
//            break;
//    }
//}
//
//
///**
// * Switch the LEDs by shell command, via USB_OTG_FS from Virtual COM Port(VCP).
// */
//void LEDs_CTRL_by_SHELL_USB(){
//    //control the LEDs by SHELL via USB_OTG_FS
//}
