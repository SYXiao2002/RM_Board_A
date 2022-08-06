/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ST7735_DC_Pin GPIO_PIN_9
#define ST7735_DC_GPIO_Port GPIOB
#define CAN1_RX_Pin GPIO_PIN_0
#define CAN1_RX_GPIO_Port GPIOD
#define CAN1_TX_Pin GPIO_PIN_1
#define CAN1_TX_GPIO_Port GPIOD
#define J20_24V_POWER_CTRL_Pin GPIO_PIN_2
#define J20_24V_POWER_CTRL_GPIO_Port GPIOH
#define J22_24V_POWER_CTRL_Pin GPIO_PIN_3
#define J22_24V_POWER_CTRL_GPIO_Port GPIOH
#define J19_24V_POWER_CTRL_Pin GPIO_PIN_4
#define J19_24V_POWER_CTRL_GPIO_Port GPIOH
#define LED_onboard_A_Pin GPIO_PIN_8
#define LED_onboard_A_GPIO_Port GPIOG
#define J21_24V_POWER_CTRL_Pin GPIO_PIN_5
#define J21_24V_POWER_CTRL_GPIO_Port GPIOH
#define LED_onboard_B_Pin GPIO_PIN_7
#define LED_onboard_B_GPIO_Port GPIOG
#define LED_onboard_C_Pin GPIO_PIN_6
#define LED_onboard_C_GPIO_Port GPIOG
#define LED_onboard_D_Pin GPIO_PIN_5
#define LED_onboard_D_GPIO_Port GPIOG
#define LED_onboard_E_Pin GPIO_PIN_4
#define LED_onboard_E_GPIO_Port GPIOG
#define LED_onboard_F_Pin GPIO_PIN_3
#define LED_onboard_F_GPIO_Port GPIOG
#define LED_onboard_G_Pin GPIO_PIN_2
#define LED_onboard_G_GPIO_Port GPIOG
#define LED_onboard_H_Pin GPIO_PIN_1
#define LED_onboard_H_GPIO_Port GPIOG
#define Button_A2D_Pin GPIO_PIN_6
#define Button_A2D_GPIO_Port GPIOA
#define ST7735_RST_Pin GPIO_PIN_10
#define ST7735_RST_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
