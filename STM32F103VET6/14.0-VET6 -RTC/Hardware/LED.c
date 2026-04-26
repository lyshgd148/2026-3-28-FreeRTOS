#include "LED.h"



uint16_t led_tick[LED_NUM] = {0};
uint8_t led_mode[LED_NUM] = {0};

 void LED_ON(uint8_t num)
{
    if (num == 0)
        HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
    else if (num == 1)
        HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
    else
        HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_RESET);
}

 void LED_OFF(uint8_t num)
{
    if (num == 0)
        HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
    else if (num == 1)
        HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
    else
        HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_SET);
}

void LED_SetMode(uint8_t mode, uint8_t nb)
{
    if (mode != led_mode[nb])
    {
        led_mode[nb]=mode;
        led_tick[nb]=0;

    }
}

static void LED_RunMode(uint8_t *led_mode, uint16_t *lde_tick, uint8_t nb)
{

    if (led_mode[nb] == 0)
    {
        LED_OFF(nb);
    }
    else if (led_mode[nb] == 1)
    {
        LED_ON(nb);
    }
    else if (led_mode[nb] == 2)
    {
        led_tick[nb]++;
        led_tick[nb] %= 1000;
        if (led_tick[nb] < 500)
            LED_ON(nb);
        else
            LED_OFF(nb);
    }
    else if (led_mode[nb] == 3)
    {
        led_tick[nb]++;
        led_tick[nb] %= 100;
        if (led_tick[nb] < 50)
            LED_ON(nb);
        else
            LED_OFF(nb);
    }
    else if (led_mode[nb] == 4)
    {
        led_tick[nb]++;
        led_tick[nb] %= 1000;
        if (led_tick[nb] < 100)
            LED_ON(nb);
        else
            LED_OFF(nb);
    }
}

void LED_Tick(void)
{
    for (uint8_t i = 0; i < LED_NUM; i++)
        LED_RunMode(led_mode, led_tick, i);
}
