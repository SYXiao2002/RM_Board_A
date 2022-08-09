//
// Created by 沈逸潇 on 2022/7/14.
//

#ifndef RM_BOARD_A_LEDS_ONBOARD_H
#define RM_BOARD_A_LEDS_ONBOARD_H

#include "main.h"
#include "bsp_flash.h"

typedef void (*LEDs_onboard_Init_Func)     (void);
typedef uint8_t (*LEDs_onboard_WriteODR_Func) (uint8_t);
typedef uint8_t (*LEDs_onboard_WriteWaterfulNum_Func) (uint8_t);
typedef uint8_t (*LEDs_onboard_GetODR_Func)  (void);

typedef struct{
	LEDs_onboard_Init_Func                  Init;
	LEDs_onboard_WriteODR_Func              WriteODR;
	LEDs_onboard_WriteWaterfulNum_Func      WriteWaterfulNum;
	LEDs_onboard_GetODR_Func                GetODR;
	uint8_t                                 WaterfulNum;
} LEDs_onboard_IO_t;



typedef void (*LEDs_onboard_Display_Func)  (void);

typedef struct{
	LEDs_onboard_Display_Func       AllOn;
	LEDs_onboard_Display_Func       ALLOff;
	LEDs_onboard_Display_Func       ALLToggle;
	LEDs_onboard_Display_Func       ShowWaterful;
	LEDs_onboard_Display_Func       ShowBlink;
} LEDs_onboard_Driver_t;



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



extern LEDs_onboard_IO_t Fused_LEDs_IO;
extern LEDs_onboard_Driver_t Fused_LEDs_Display;
void LEDs_CTRL_Manually(LEDs_Id_t LED_id, LED_Status_t LED_status);

#endif //RM_BOARD_A_LEDS_ONBOARD_H
