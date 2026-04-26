#include "KEY.h"

uint8_t Key_Num;

uint8_t Key_GetNum(void)
{
    uint8_t temp=0;
    if (Key_Num)
    {
        temp = Key_Num;
        Key_Num = 0;
    }
    return temp;
}

static uint8_t Key_GetState(void)
{
    if (HAL_GPIO_ReadPin(Key1_GPIO_Port, Key1_Pin) == GPIO_PIN_RESET)
        return 1;
    else if (HAL_GPIO_ReadPin(Key2_GPIO_Port, Key2_Pin) == GPIO_PIN_RESET)
        return 2;
    return 0;
}

void KEY_Tick(void)
{
    static uint8_t tick = 0;
    static uint8_t current, prev;

    tick++;
    if (tick > 20)
    {
        tick = 0;
        prev = current;
        current = Key_GetState();

        if (current == 0 && prev != 0)
            Key_Num = prev;
    }
}
