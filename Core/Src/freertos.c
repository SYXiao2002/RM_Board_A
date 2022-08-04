/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
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

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "LEDs_onboard.h"
#include "user_pid.h"
#include "usbd_cdc_if.h"
#include "st7735.h"
#include "support.h"
#include "bsp_buzzer.h"
#define MAX_PSC                 1000

#define MAX_BUZZER_PWM      20000
#define MIN_BUZZER_PWM      10000

uint16_t psc = 0;
uint16_t pwm = MIN_BUZZER_PWM;
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
/* USER CODE END Variables */
/* Definitions for LED_Blink */
osThreadId_t LED_BlinkHandle;
const osThreadAttr_t LED_Blink_attributes = {
  .name = "LED_Blink",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for OLED_Display */
osThreadId_t OLED_DisplayHandle;
const osThreadAttr_t OLED_Display_attributes = {
  .name = "OLED_Display",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for Buzzer_Annoying */
osThreadId_t Buzzer_AnnoyingHandle;
const osThreadAttr_t Buzzer_Annoying_attributes = {
  .name = "Buzzer_Annoying",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void Task_LED_Blink(void *argument);
void Task_OLED_Display(void *argument);
void Task_Buzzer_Annoying(void *argument);

extern void MX_USB_DEVICE_Init(void);
void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* Hook prototypes */
void configureTimerForRunTimeStats(void);
unsigned long getRunTimeCounterValue(void);

/* USER CODE BEGIN 1 */
/* Functions needed when configGENERATE_RUN_TIME_STATS is on */
__weak void configureTimerForRunTimeStats(void)
{

}

__weak unsigned long getRunTimeCounterValue(void)
{
	return 0;
}
/* USER CODE END 1 */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
	/* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
	/* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
	/* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
	/* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of LED_Blink */
  LED_BlinkHandle = osThreadNew(Task_LED_Blink, NULL, &LED_Blink_attributes);

  /* creation of OLED_Display */
  OLED_DisplayHandle = osThreadNew(Task_OLED_Display, NULL, &OLED_Display_attributes);

  /* creation of Buzzer_Annoying */
  Buzzer_AnnoyingHandle = osThreadNew(Task_Buzzer_Annoying, NULL, &Buzzer_Annoying_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
	/* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
	/* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_Task_LED_Blink */
/**
  * @brief  Function implementing the LED_Blink thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_Task_LED_Blink */
void Task_LED_Blink(void *argument)
{
  /* init code for USB_DEVICE */
  MX_USB_DEVICE_Init();
  /* USER CODE BEGIN Task_LED_Blink */
	/* Infinite loop */
	for(;;)
	{
		osDelay(1);
		LEDs_CTRL_Events(ShowWaterful);
		LEDs_CTRL_Events(ALLOff);
	}
  /* USER CODE END Task_LED_Blink */
}

/* USER CODE BEGIN Header_Task_OLED_Display */
/**
* @brief Function implementing the OLED_Display thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_OLED_Display */
void Task_OLED_Display(void *argument)
{
  /* USER CODE BEGIN Task_OLED_Display */
	/* Infinite loop */
	for(;;)
	{
		osDelay(100);

		ST7735_FillScreen(black);
		osDelay(100);
		ST7735_FillScreen(white);
	}
  /* USER CODE END Task_OLED_Display */
}

/* USER CODE BEGIN Header_Task_Buzzer_Annoying */
/**
* @brief Function implementing the Buzzer_Annoying thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_Buzzer_Annoying */
void Task_Buzzer_Annoying(void *argument)
{
  /* USER CODE BEGIN Task_Buzzer_Annoying */
	/* Infinite loop */
	for(;;)
	{
		osDelay(2000);
	}
  /* USER CODE END Task_Buzzer_Annoying */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

