#include "KEY.h"

volatile uint8_t Key_Flag[KEY_NUM];

static uint8_t Key_GetState(uint8_t n)
{
    if (n == KEY1)
    {
        if (HAL_GPIO_ReadPin(Key1_GPIO_Port, Key1_Pin) == GPIO_PIN_RESET)
            return KEY_PRESSED;
    }
    else if (n == KEY2)
    {
        if (HAL_GPIO_ReadPin(Key2_GPIO_Port, Key2_Pin) == GPIO_PIN_RESET)
            return KEY_PRESSED;
    }
    else if (n == KEY3)
    {
        if (HAL_GPIO_ReadPin(Key3_GPIO_Port, Key3_Pin) == GPIO_PIN_RESET)
            return KEY_PRESSED;
    }
    return KEY_UNPRESSED;
}

uint8_t Key_Check(uint8_t Flag, uint8_t n)
{
    if (Flag & Key_Flag[n])
    {
        if (Flag != KEY_HOLD)
        {
            Key_Flag[n] &= ~Flag;
        }
        return 1;
    }
    return 0;
}

// void KEY_Tick(void)
// {
//     static uint8_t tick = 0, i;

//     static uint16_t Time[KEY_NUM];
//     static uint8_t current[KEY_NUM], prev[KEY_NUM];
//     static uint8_t S[KEY_NUM] = {0};

//     tick++;
//     for (i = 0; i < KEY_NUM; i++)
//     {
//         if (Time > 0)
//         {
//             Time[i]--;
//         }
//     }

//     if (tick > 20)
//     {
//         tick = 0;

//         for (i = 0; i < KEY_NUM; i++)
//         {
//             prev[i] = current;
//             current[i] = Key_GetState();
//             if (current[] == KEY_PRESSED)
//             {
//                 Key_Flag |= KEY_HOLD;
//             }
//             else
//             {
//                 Key_Flag &= ~KEY_HOLD;
//             }
//             if (current == KEY_PRESSED && prev == KEY_UNPRESSED)
//             {
//                 Key_Flag |= KEY_DOWN;
//             }
//             if (current == KEY_UNPRESSED && prev == KEY_PRESSED)
//             {
//                 Key_Flag |= KEY_UP;
//             }

//             if (S == 0)
//             {
//                 if (current == KEY_PRESSED)
//                 {
//                     Time = KEY_TIME_LONG;
//                     S = 1;
//                 }
//             }
//             else if (S == 1)
//             {
//                 if (current == KEY_UNPRESSED)
//                 {
//                     Time = KEY_TIME_DOUBLE;
//                     S = 2;
//                 }
//                 else if (Time == 0)
//                 {
//                     Key_Flag |= KEY_LONG;
//                     Time = KEY_TIME_REPEAT;
//                     S = 4;
//                 }
//             }
//             else if (S == 2)
//             {
//                 if (current == KEY_PRESSED)
//                 {
//                     Key_Flag |= KEY_DOUBLE;
//                     S = 3;
//                 }
//                 else if (Time == 0)
//                 {
//                     Key_Flag |= KEY_SINGLE;
//                     S = 0;
//                 }
//             }
//             else if (S == 3)
//             {
//                 if (current == KEY_UNPRESSED)
//                 {
//                     S = 0;
//                 }
//             }
//             else if (S == 4)
//             {
//                 if (current == KEY_UNPRESSED)
//                 {
//                     S = 0;
//                 }
//                 else if (Time == 0)
//                 {
//                     Time = KEY_TIME_REPEAT;
//                     Key_Flag |= KEY_REPEAT;
//                     S = 4;
//                 }
//             }
//         }
//     }
// }


void KEY_Tick(void)
{
    static uint8_t tick = 0, i;

    static uint16_t Time[KEY_NUM];
    static uint8_t current[KEY_NUM], prev[KEY_NUM];
    static uint8_t S[KEY_NUM] = {0};

    tick++;

    for (i = 0; i < KEY_NUM; i++)
    {
        if (Time[i] > 0)
        {
            Time[i]--;
        }
    }

    if (tick > 20)
    {
        tick = 0;

        for (i = 0; i < KEY_NUM; i++)
        {
            prev[i] = current[i];
            current[i] = Key_GetState(i);

            if (current[i] == KEY_PRESSED)
            {
                Key_Flag[i] |= KEY_HOLD;
            }
            else
            {
                Key_Flag[i] &= ~KEY_HOLD;
            }

            if (current[i] == KEY_PRESSED && prev[i] == KEY_UNPRESSED)
            {
                Key_Flag[i] |= KEY_DOWN;
            }

            if (current[i] == KEY_UNPRESSED && prev[i] == KEY_PRESSED)
            {
                Key_Flag[i] |= KEY_UP;
            }

            if (S[i] == 0)
            {
                if (current[i] == KEY_PRESSED)
                {
                    Time[i] = KEY_TIME_LONG;
                    S[i] = 1;
                }
            }
            else if (S[i] == 1)
            {
                if (current[i] == KEY_UNPRESSED)
                {
                    Time[i] = KEY_TIME_DOUBLE;
                    S[i] = 2;
                }
                else if (Time[i] == 0)
                {
                    Key_Flag[i] |= KEY_LONG;
                    Time[i] = KEY_TIME_REPEAT;
                    S[i] = 4;
                }
            }
            else if (S[i] == 2)
            {
                if (current[i] == KEY_PRESSED)
                {
                    Key_Flag[i] |= KEY_DOUBLE;
                    S[i] = 3;
                }
                else if (Time[i] == 0)
                {
                    Key_Flag[i] |= KEY_SINGLE;
                    S[i] = 0;
                }
            }
            else if (S[i] == 3)
            {
                if (current[i] == KEY_UNPRESSED)
                {
                    S[i] = 0;
                }
            }
            else if (S[i] == 4)
            {
                if (current[i] == KEY_UNPRESSED)
                {
                    S[i] = 0;
                }
                else if (Time[i] == 0)
                {
                    Time[i] = KEY_TIME_REPEAT;
                    Key_Flag[i] |= KEY_REPEAT;
                    S[i] = 4;
                }
            }
        }
    }
}
