#include "KEY.h"

uint8_t Key_GetState(void)
{
    if (HAL_GPIO_ReadPin(Key1_GPIO_Port, Key1_Pin) == GPIO_PIN_RESET)
    {
        HAL_Delay(20);
        while (HAL_GPIO_ReadPin(Key1_GPIO_Port, Key1_Pin) == GPIO_PIN_RESET)
            ;
        HAL_Delay(20);
        return 1;
    }

    if (HAL_GPIO_ReadPin(Key2_GPIO_Port, Key2_Pin) == GPIO_PIN_RESET)
    {
        HAL_Delay(20);
        while (HAL_GPIO_ReadPin(Key2_GPIO_Port, Key2_Pin) == GPIO_PIN_RESET)
            ;
        HAL_Delay(20);
        return 2;
    }

    if (HAL_GPIO_ReadPin(Key3_GPIO_Port, Key3_Pin) == GPIO_PIN_RESET)
    {
        HAL_Delay(20);
        while (HAL_GPIO_ReadPin(Key3_GPIO_Port, Key3_Pin) == GPIO_PIN_RESET)
            ;

        HAL_Delay(20);
        return 3;
    }
    return 0;
}
