#include "main.h"
#include "dma.h"
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

#include "OLED.h"
#include "math.h"
#include "KEY.h"

uint8_t Current = 0, Next = 1;
uint8_t Keynum, count = 0;
void Model1_Init(void)
{
  OLED_Clear();
  OLED_ShowString(0, 8, "[Model1]", 6);
  OLED_Update();
}

void Model1_Loop(void)
{
  if (Keynum == 2)
  {
    HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
  }
}

void Mode1_Exit(void)
{
  HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
}

void Model2_Init(void)
{
  OLED_Clear();
  OLED_ShowString(0, 8, "[Model2]", 6);
  OLED_ShowNum(0, 16, count, 3, 6);
  OLED_Update();
}

void Model2_Loop(void)
{
  if (Keynum == 2)
  {
    count++;
    OLED_ShowNum(0, 16, count, 3, 6);
    OLED_Update();
  }
}

void Mode2_Exit(void)
{
  count = 0;
}

uint8_t Time_count = 0;
uint8_t Time_falg = 0;

void Model3_Init(void)
{
  OLED_Clear();
  OLED_ShowString(0, 8, "[Model3]", 6);
  OLED_ShowNum(0, 16, Time_count, 3, 6);
  OLED_Update();
}

void Model3_Loop(void)
{

  if (Keynum == 2)
  {
    Time_falg = !Time_falg;
  }
  OLED_ShowNum(0, 16, Time_count, 3, 6);
  OLED_Update();
}

void Mode3_Exit(void)
{
  Time_count = 0;
  Time_falg = 0;
}

void Model3_Tick(void)
{
  static uint16_t count0 = 0;
  count0++;
  if (count0 >= 1000)
  {
    count0 = 0;
    if (Time_falg)
    {
      Time_count++;
    }
  }
}

void Global_Init(void)
{
  OLED_Init();
}
void Global_Loop(void)
{
  Keynum = Key_GetState();
  if (Keynum == 1)
  {
    Next++;
    if (Next > 3)
      Next = 1;
  }
}
void Global_Tick(void) {}

void SystemClock_Config(void);

int main(void)
{
  HAL_Init();

  SystemClock_Config();

  MX_GPIO_Init();
  MX_DMA_Init();
  MX_USART1_UART_Init();
  MX_I2C2_Init();
  MX_TIM2_Init();
  HAL_TIM_Base_Start_IT(&htim2);

  Global_Init();

  while (1)
  {
    Global_Loop();
    if (Current == Next)
    {
      switch (Current)
      {
      case 1:
        Model1_Loop();
        break;

      case 2:
        Model2_Loop();
        break;
      case 3:
        Model3_Loop();
        break;
      }
    }
    else
    {
      switch (Current)
      {
      case 1:
        Mode1_Exit();
        break;

      case 2:
        Mode2_Exit();
        break;
      case 3:
        Mode3_Exit();
        break;
      }

      switch (Next)
      {
      case 1:
        Model1_Init();
        break;

      case 2:
        Model2_Init();
        break;
      case 3:
        Model3_Init();
        break;
      }
      Current = Next;
    }
  }
}

void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if (htim->Instance == TIM2)
  {
    Global_Tick();
    if (Current == Next)
    {
      switch (Current)
      {
      case 3:
        Model3_Tick();
        break;
      }
    }
  }
}

void Error_Handler(void)
{
  __disable_irq();
  while (1)
  {
  }
}
#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line)
{
}
#endif
