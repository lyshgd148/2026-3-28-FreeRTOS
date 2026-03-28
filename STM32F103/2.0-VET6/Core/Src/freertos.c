/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * File Name          : freertos.c
 * Description        : Code for freertos applications
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2026 STMicroelectronics.
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
#include <stdio.h>

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
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for Log_Task */
osThreadId_t Log_TaskHandle;
const osThreadAttr_t Log_Task_attributes = {
  .name = "Log_Task",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow1,
};
/* Definitions for Key_Task */
osThreadId_t Key_TaskHandle;
const osThreadAttr_t Key_Task_attributes = {
  .name = "Key_Task",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow1,
};
/* Definitions for KeyBinary01 */
osSemaphoreId_t KeyBinary01Handle;
const osSemaphoreAttr_t KeyBinary01_attributes = {
  .name = "KeyBinary01"
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
uint8_t flag=0;
/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);
void LogTaskFunc(void *argument);
void KeyTaskFunc(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

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

  /* Create the semaphores(s) */
  /* creation of KeyBinary01 */
  KeyBinary01Handle = osSemaphoreNew(1, 1, &KeyBinary01_attributes);

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
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of Log_Task */
  Log_TaskHandle = osThreadNew(LogTaskFunc, NULL, &Log_Task_attributes);

  /* creation of Key_Task */
  Key_TaskHandle = osThreadNew(KeyTaskFunc, NULL, &Key_Task_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
 * @brief  Function implementing the defaultTask thread.
 * @param  argument: Not used
 * @retval None
 */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  uint32_t tick = 0;
  /* Infinite loop */
  for (;;)
  {
    // printf("FreeRTOS tick: %lu\r\n", (unsigned long)tick++);
    osDelay(1000);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_LogTaskFunc */
/**
 * @brief Function implementing the Log_Task thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_LogTaskFunc */
void LogTaskFunc(void *argument)
{
  /* USER CODE BEGIN LogTaskFunc */
  /* Infinite loop */
  for (;;)
  {
    if(osSemaphoreAcquire(KeyBinary01Handle,100)==osOK)
    {
      printf("Key Press!\r\n");
    }
    // if(flag==1)
    // {
    //   flag=0;
    //   printf("Key Press!\r\n");
    // }
    osDelay(500);
  }
  /* USER CODE END LogTaskFunc */
}

/* USER CODE BEGIN Header_KeyTaskFunc */
/**
 * @brief Function implementing the Key_Task thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_KeyTaskFunc */
void KeyTaskFunc(void *argument)
{
  /* USER CODE BEGIN KeyTaskFunc */
  /* Infinite loop */
  for (;;)
  {
    if (HAL_GPIO_ReadPin(Key1_GPIO_Port, Key1_Pin) == GPIO_PIN_RESET)
    {
      osSemaphoreRelease(KeyBinary01Handle);
      // flag=1;
    }
    osDelay(1);
  }
  /* USER CODE END KeyTaskFunc */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

