#include "menu.h"

uint8_t menu1(void)
{
    static uint8_t flag = 1;
    uint8_t flag_last = 1;
    uint8_t Key_num;
    OLED_ShowString(0, 8, "test1     ", OLED_6X8);
    OLED_ShowString(0, 24, "test2     ", OLED_6X8);
    OLED_ShowString(0, 40, "test3     ", OLED_6X8);
    OLED_ShowString(0, 56, "test4     ", OLED_6X8);
    OLED_Update();

    while (1)
    {

        Key_num = Key_GetState();
        if (Key_num == 1)
        {
            flag++;
            flag_last = 1;
            if (flag > 8)
                flag = 1;
        }
        else if (Key_num == 2)
        {
            flag--;
            flag_last = 1;
            if (flag < 1)
                flag = 8;
        }
        else if (Key_num == 3)
        {
            OLED_Clear();
            OLED_Update();
            return flag;
        }

        if (flag_last)
        {
            flag_last = 0;
            OLED_Clear();
            switch (flag)
            {
            case 1:
                OLED_ShowString(0, 8, "test1     ", OLED_6X8);
                OLED_ShowString(0, 24, "test2     ", OLED_6X8);
                OLED_ShowString(0, 40, "test3     ", OLED_6X8);
                OLED_ShowString(0, 56, "test4     ", OLED_6X8);
                OLED_ReverseArea(0, 8, 128, 8);
                break;
            case 2:
                OLED_ShowString(0, 8, "test1     ", OLED_6X8);
                OLED_ShowString(0, 24, "test2     ", OLED_6X8);
                OLED_ShowString(0, 40, "test3     ", OLED_6X8);
                OLED_ShowString(0, 56, "test4     ", OLED_6X8);
                OLED_ReverseArea(0, 24, 128, 8);
                break;
            case 3:
                OLED_ShowString(0, 8, "test1     ", OLED_6X8);
                OLED_ShowString(0, 24, "test2     ", OLED_6X8);
                OLED_ShowString(0, 40, "test3     ", OLED_6X8);
                OLED_ShowString(0, 56, "test4     ", OLED_6X8);
                OLED_ReverseArea(0, 40, 128, 8);
                break;
            case 4:
                OLED_ShowString(0, 8, "test1     ", OLED_6X8);
                OLED_ShowString(0, 24, "test2     ", OLED_6X8);
                OLED_ShowString(0, 40, "test3     ", OLED_6X8);
                OLED_ShowString(0, 56, "test4     ", OLED_6X8);
                OLED_ReverseArea(0, 56, 128, 8);
                break;
            case 5:
                OLED_ShowString(0, 8, "test5     ", OLED_6X8);
                OLED_ShowString(0, 24, "test6     ", OLED_6X8);
                OLED_ShowString(0, 40, "test7     ", OLED_6X8);
                OLED_ShowString(0, 56, "test8     ", OLED_6X8);
                OLED_ReverseArea(0, 8, 128, 8);
                break;
            case 6:
                OLED_ShowString(0, 8, "test5     ", OLED_6X8);
                OLED_ShowString(0, 24, "test6     ", OLED_6X8);
                OLED_ShowString(0, 40, "test7     ", OLED_6X8);
                OLED_ShowString(0, 56, "test8     ", OLED_6X8);
                OLED_ReverseArea(0, 24, 128, 8);
                break;
            case 7:
                OLED_ShowString(0, 8, "test5     ", OLED_6X8);
                OLED_ShowString(0, 24, "test6     ", OLED_6X8);
                OLED_ShowString(0, 40, "test7     ", OLED_6X8);
                OLED_ShowString(0, 56, "test8     ", OLED_6X8);
                OLED_ReverseArea(0, 40, 128, 8);
                break;
            case 8:
                OLED_ShowString(0, 8, "test5     ", OLED_6X8);
                OLED_ShowString(0, 24, "test6     ", OLED_6X8);
                OLED_ShowString(0, 40, "test7     ", OLED_6X8);
                OLED_ShowString(0, 56, "test8     ", OLED_6X8);
                OLED_ReverseArea(0, 56, 128, 8);
                break;
            }
            OLED_Update();
        }
    }
}

uint8_t menu1_x(void)
{
    static uint8_t flag = 1;
    uint8_t flag_last = 1;
    uint8_t Key_num;
    uint8_t menu2 = 0;
    while (1)
    {
        Key_num = Key_GetState();
        if (Key_num == 1)
        {
            flag++;
            flag_last = 1;
            if (flag > 5)
                flag = 1;
        }
        else if (Key_num == 2)
        {
            flag--;
            flag_last = 1;
            if (flag < 1)
                flag = 5;
        }
        else if (Key_num == 3)
        {
            OLED_Clear();
            OLED_Update();
            menu2 = flag;
        }
        switch (menu2)
        {
        case 1:
            return 0;
        default:
            flag_last = 1;
            break;
        }

        if (flag_last)
        {
            flag_last = 0;
            OLED_Clear();
            switch (flag)
            {
            case 1:
                OLED_ShowString(0, 8, "<--   ", OLED_6X8);
                OLED_ShowString(0, 24, "M1-1   ", OLED_6X8);
                OLED_ShowString(0, 40, "M1-2   ", OLED_6X8);
                OLED_ShowString(0, 56, "M1-3   ", OLED_6X8);
                OLED_ReverseArea(0, 8, 128, 8);
                break;
            case 2:
                OLED_ShowString(0, 8, "<--   ", OLED_6X8);
                OLED_ShowString(0, 24, "M1-1   ", OLED_6X8);
                OLED_ShowString(0, 40, "M1-2   ", OLED_6X8);
                OLED_ShowString(0, 56, "M1-3   ", OLED_6X8);
                OLED_ReverseArea(0, 24, 128, 8);
                break;
            case 3:
                OLED_ShowString(0, 8, "<--   ", OLED_6X8);
                OLED_ShowString(0, 24, "M1-1   ", OLED_6X8);
                OLED_ShowString(0, 40, "M1-2   ", OLED_6X8);
                OLED_ShowString(0, 56, "M1-3   ", OLED_6X8);
                OLED_ReverseArea(0, 40, 128, 8);
                break;
            case 4:
                OLED_ShowString(0, 8, "<--   ", OLED_6X8);
                OLED_ShowString(0, 24, "M1-1   ", OLED_6X8);
                OLED_ShowString(0, 40, "M1-2   ", OLED_6X8);
                OLED_ShowString(0, 56, "M1-3   ", OLED_6X8);
                OLED_ReverseArea(0, 56, 128, 8);
                break;
            case 5:
                OLED_ShowString(0, 8, "M1-1   ", OLED_6X8);
                OLED_ShowString(0, 24, "M1-2   ", OLED_6X8);
                OLED_ShowString(0, 40, "M1-3   ", OLED_6X8);
                OLED_ShowString(0, 56, "M1-4   ", OLED_6X8);
                OLED_ReverseArea(0, 56, 128, 8);
                break;
            }
            OLED_Update();
        }
    }
}

uint8_t menu2_x(void)
{
    static uint8_t flag = 1;
    uint8_t Key_num;
    uint8_t menu2 = 0;
    RTC_TimeTypeDef sTime;
    RTC_DateTypeDef sDate;
    while (1)
    {
        Key_num = Key_GetState();
        if (Key_num == 1)
        {
            flag++;
            if (flag > 1)
                flag = 1;
        }
        else if (Key_num == 2)
        {
            flag--;

            if (flag < 1)
                flag = 1;
        }
        else if (Key_num == 3)
        {
            OLED_Clear();
            OLED_Update();
            menu2 = flag;
        }
        switch (menu2)
        {
        case 1:
            return 0;
        default:
            break;
        }

        OLED_Clear();
        switch (flag)
        {
        case 1:
            HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
            HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);

            OLED_ShowString(0, 8, "<--   ", OLED_6X8);
            OLED_Printf(40, 24, 6, "%d-%d-%d", sDate.Year, sDate.Month, sDate.Date);
            OLED_Printf(40, 40, 6, "%d:%d:%d", sTime.Hours, sTime.Minutes, sTime.Seconds);
            OLED_ReverseArea(0, 8, 128, 8);
            break;
        }
        OLED_Update();
    }
}

uint8_t menu3_x_x(uint8_t led1_state, uint8_t led2_state, uint8_t led3_state, uint8_t num_menu)
{
    uint8_t flag_last = 1;
    uint8_t Key_num;

    while (1)
    {
        Key_num = Key_GetState();
        if (Key_num == 1)
        {
            flag_last = 1;
            if (num_menu == 0)
            {
                led1_state = 1;
            }
            else if (num_menu == 1)
            {
                led2_state = 1;
            }
            else
            {
                led3_state = 1;
            }
            LED_ON(num_menu);
        }
        else if (Key_num == 2)
        {
            flag_last = 1;
            if (num_menu == 0)
            {
                led1_state = 0;
            }
            else if (num_menu == 1)
            {
                led2_state = 0;
            }
            else
            {
                led3_state = 0;
            }
            LED_OFF(num_menu);
        }
        else if (Key_num == 3)
        {
            return 0;
        }
        if (flag_last)
        {
            flag_last = 0;
            OLED_Clear();

            OLED_ShowString(0, 8, "<--   ", OLED_6X8);
            if (led1_state == 1)
                OLED_ShowString(0, 24, "LED1:ON", OLED_6X8);
            else
                OLED_ShowString(0, 24, "LED1:OFF", OLED_6X8);
            if (led2_state == 1)
                OLED_ShowString(0, 40, "LED2:ON", OLED_6X8);
            else
                OLED_ShowString(0, 40, "LED2:OFF", OLED_6X8);
            if (led3_state == 1)
                OLED_ShowString(0, 56, "LED3:ON", OLED_6X8);
            else
                OLED_ShowString(0, 56, "LED3:OFF", OLED_6X8);
            OLED_ReverseArea(0, 24 + num_menu * 16, 64, 8);
            OLED_Update();
        }
    }
}

uint8_t menu3_x(void)
{
    static uint8_t flag = 1;
    uint8_t flag_last = 1;
    uint8_t Key_num;
    uint8_t menu2 = 0;
    static uint8_t led1_state = 0;
    static uint8_t led2_state = 0;
    static uint8_t led3_state = 0;

    while (1)
    {
        if (HAL_GPIO_ReadPin(LED1_GPIO_Port, LED1_Pin) == GPIO_PIN_RESET)
            led1_state = 1;
        else
            led1_state = 0;

        if (HAL_GPIO_ReadPin(LED2_GPIO_Port, LED2_Pin) == GPIO_PIN_RESET)
            led2_state = 1;
        else
            led2_state = 0;

        if (HAL_GPIO_ReadPin(LED3_GPIO_Port, LED3_Pin) == GPIO_PIN_RESET)
            led3_state = 1;
        else
            led3_state = 0;
        Key_num = Key_GetState();
        if (Key_num == 1)
        {
            flag++;
            flag_last = 1;
            if (flag > 4)
                flag = 1;
        }
        else if (Key_num == 2)
        {
            flag--;
            flag_last = 1;
            if (flag < 1)
                flag = 4;
        }
        else if (Key_num == 3)
        {
            OLED_Clear();
            OLED_Update();
            menu2 = flag;
        }
        switch (menu2)
        {
        case 1:
            return 0;

        case 2:
            // flag_last = 1;
            menu2 = 0;
            menu3_x_x(led1_state, led2_state, led3_state, 0);
            break;
        case 3:
            menu2 = 0;
            menu3_x_x(led1_state, led2_state, led3_state, 1);
            break;
        case 4:
            menu2 = 0;
            menu3_x_x(led1_state, led2_state, led3_state, 2);
            break;
        default:
            flag_last = 1;
            break;
        }

        if (flag_last)
        {
            flag_last = 0;
            OLED_Clear();
            switch (flag)
            {
            case 1:
                OLED_ShowString(0, 8, "<--   ", OLED_6X8);
                if (led1_state == 1)
                    OLED_ShowString(0, 24, "LED1:ON", OLED_6X8);
                else
                    OLED_ShowString(0, 24, "LED1:OFF", OLED_6X8);
                if (led2_state == 1)
                    OLED_ShowString(0, 40, "LED2:ON", OLED_6X8);
                else
                    OLED_ShowString(0, 40, "LED2:OFF", OLED_6X8);
                if (led3_state == 1)
                    OLED_ShowString(0, 56, "LED3:ON", OLED_6X8);
                else
                    OLED_ShowString(0, 56, "LED3:OFF", OLED_6X8);
                OLED_ReverseArea(0, 8, 128, 8);
                break;
            case 2:
                OLED_ShowString(0, 8, "<--   ", OLED_6X8);
                if (led1_state == 1)
                    OLED_ShowString(0, 24, "LED1:ON", OLED_6X8);
                else
                    OLED_ShowString(0, 24, "LED1:OFF", OLED_6X8);
                if (led2_state == 1)
                    OLED_ShowString(0, 40, "LED2:ON", OLED_6X8);
                else
                    OLED_ShowString(0, 40, "LED2:OFF", OLED_6X8);
                if (led3_state == 1)
                    OLED_ShowString(0, 56, "LED3:ON", OLED_6X8);
                else
                    OLED_ShowString(0, 56, "LED3:OFF", OLED_6X8);
                OLED_ReverseArea(0, 24, 128, 8);
                break;
            case 3:
                OLED_ShowString(0, 8, "<--   ", OLED_6X8);
                if (led1_state == 1)
                    OLED_ShowString(0, 24, "LED1:ON", OLED_6X8);
                else
                    OLED_ShowString(0, 24, "LED1:OFF", OLED_6X8);
                if (led2_state == 1)
                    OLED_ShowString(0, 40, "LED2:ON", OLED_6X8);
                else
                    OLED_ShowString(0, 40, "LED2:OFF", OLED_6X8);
                if (led3_state == 1)
                    OLED_ShowString(0, 56, "LED3:ON", OLED_6X8);
                else
                    OLED_ShowString(0, 56, "LED3:OFF", OLED_6X8);
                OLED_ReverseArea(0, 40, 128, 8);
                break;
            case 4:
                OLED_ShowString(0, 8, "<--   ", OLED_6X8);
                if (led1_state == 1)
                    OLED_ShowString(0, 24, "LED1:ON", OLED_6X8);
                else
                    OLED_ShowString(0, 24, "LED1:OFF", OLED_6X8);
                if (led2_state == 1)
                    OLED_ShowString(0, 40, "LED2:ON", OLED_6X8);
                else
                    OLED_ShowString(0, 40, "LED2:OFF", OLED_6X8);
                if (led3_state == 1)
                    OLED_ShowString(0, 56, "LED3:ON", OLED_6X8);
                else
                    OLED_ShowString(0, 56, "LED3:OFF", OLED_6X8);
                OLED_ReverseArea(0, 56, 128, 8);
                break;
            }
            OLED_Update();
        }
    }
}

uint8_t menu4_x(void)
{
    static uint8_t flag = 1;
    uint8_t flag_last = 1;
    uint8_t Key_num;
    uint8_t menu2 = 0;
    while (1)
    {
        Key_num = Key_GetState();
        if (Key_num == 1)
        {
            flag++;
            flag_last = 1;
            if (flag > 5)
                flag = 1;
        }
        else if (Key_num == 2)
        {
            flag--;
            flag_last = 1;
            if (flag < 1)
                flag = 5;
        }
        else if (Key_num == 3)
        {
            OLED_Clear();
            OLED_Update();
            menu2 = flag;
        }
        switch (menu2)
        {
        case 1:
            return 0;
        default:
            flag_last = 1;
            break;
        }

        if (flag_last)
        {
            flag_last = 0;
            OLED_Clear();
            switch (flag)
            {
            case 1:
                OLED_ShowString(0, 8, "<--   ", OLED_6X8);
                OLED_ShowString(0, 24, "M4-1   ", OLED_6X8);
                OLED_ShowString(0, 40, "M4-2   ", OLED_6X8);
                OLED_ShowString(0, 56, "M4-3   ", OLED_6X8);
                OLED_ReverseArea(0, 8, 128, 8);
                break;
            case 2:
                OLED_ShowString(0, 8, "<--   ", OLED_6X8);
                OLED_ShowString(0, 24, "M4-1   ", OLED_6X8);
                OLED_ShowString(0, 40, "M4-2   ", OLED_6X8);
                OLED_ShowString(0, 56, "M4-3   ", OLED_6X8);
                OLED_ReverseArea(0, 24, 128, 8);
                break;
            case 3:
                OLED_ShowString(0, 8, "<--   ", OLED_6X8);
                OLED_ShowString(0, 24, "M4-1   ", OLED_6X8);
                OLED_ShowString(0, 40, "M4-2   ", OLED_6X8);
                OLED_ShowString(0, 56, "M4-3   ", OLED_6X8);
                OLED_ReverseArea(0, 40, 128, 8);
                break;
            case 4:
                OLED_ShowString(0, 8, "<--   ", OLED_6X8);
                OLED_ShowString(0, 24, "M4-1   ", OLED_6X8);
                OLED_ShowString(0, 40, "M4-2   ", OLED_6X8);
                OLED_ShowString(0, 56, "M4-3   ", OLED_6X8);
                OLED_ReverseArea(0, 56, 128, 8);
                break;
            case 5:
                OLED_ShowString(0, 8, "M4-1   ", OLED_6X8);
                OLED_ShowString(0, 24, "M4-2   ", OLED_6X8);
                OLED_ShowString(0, 40, "M4-3   ", OLED_6X8);
                OLED_ShowString(0, 56, "M4-4   ", OLED_6X8);
                OLED_ReverseArea(0, 56, 128, 8);
                break;
            }
            OLED_Update();
        }
    }
}

uint8_t menu5_x(void)
{
    static uint8_t flag = 1;
    uint8_t flag_last = 1;
    uint8_t Key_num;
    uint8_t menu2 = 0;
    while (1)
    {
        Key_num = Key_GetState();
        if (Key_num == 1)
        {
            flag++;
            flag_last = 1;
            if (flag > 5)
                flag = 1;
        }
        else if (Key_num == 2)
        {
            flag--;
            flag_last = 1;
            if (flag < 1)
                flag = 5;
        }
        else if (Key_num == 3)
        {
            OLED_Clear();
            OLED_Update();
            menu2 = flag;
        }
        switch (menu2)
        {
        case 1:
            return 0;
        default:
            flag_last = 1;
            break;
        }

        if (flag_last)
        {
            flag_last = 0;
            OLED_Clear();
            switch (flag)
            {
            case 1:
                OLED_ShowString(0, 8, "<--   ", OLED_6X8);
                OLED_ShowString(0, 24, "M5-1   ", OLED_6X8);
                OLED_ShowString(0, 40, "M5-2   ", OLED_6X8);
                OLED_ShowString(0, 56, "M5-3   ", OLED_6X8);
                OLED_ReverseArea(0, 8, 128, 8);
                break;
            case 2:
                OLED_ShowString(0, 8, "<--   ", OLED_6X8);
                OLED_ShowString(0, 24, "M5-1   ", OLED_6X8);
                OLED_ShowString(0, 40, "M5-2   ", OLED_6X8);
                OLED_ShowString(0, 56, "M5-3   ", OLED_6X8);
                OLED_ReverseArea(0, 24, 128, 8);
                break;
            case 3:
                OLED_ShowString(0, 8, "<--   ", OLED_6X8);
                OLED_ShowString(0, 24, "M5-1   ", OLED_6X8);
                OLED_ShowString(0, 40, "M5-2   ", OLED_6X8);
                OLED_ShowString(0, 56, "M5-3   ", OLED_6X8);
                OLED_ReverseArea(0, 40, 128, 8);
                break;
            case 4:
                OLED_ShowString(0, 8, "<--   ", OLED_6X8);
                OLED_ShowString(0, 24, "M5-1   ", OLED_6X8);
                OLED_ShowString(0, 40, "M5-2   ", OLED_6X8);
                OLED_ShowString(0, 56, "M5-3   ", OLED_6X8);
                OLED_ReverseArea(0, 56, 128, 8);
                break;
            case 5:
                OLED_ShowString(0, 8, "M5-1   ", OLED_6X8);
                OLED_ShowString(0, 24, "M5-2   ", OLED_6X8);
                OLED_ShowString(0, 40, "M5-3   ", OLED_6X8);
                OLED_ShowString(0, 56, "M5-4   ", OLED_6X8);
                OLED_ReverseArea(0, 56, 128, 8);
                break;
            }
            OLED_Update();
        }
    }
}

uint8_t menu6_x(void)
{
    static uint8_t flag = 1;
    uint8_t flag_last = 1;
    uint8_t Key_num;
    uint8_t menu2 = 0;
    while (1)
    {
        Key_num = Key_GetState();
        if (Key_num == 1)
        {
            flag++;
            flag_last = 1;
            if (flag > 5)
                flag = 1;
        }
        else if (Key_num == 2)
        {
            flag--;
            flag_last = 1;
            if (flag < 1)
                flag = 5;
        }
        else if (Key_num == 3)
        {
            OLED_Clear();
            OLED_Update();
            menu2 = flag;
        }
        switch (menu2)
        {
        case 1:
            return 0;
        default:
            flag_last = 1;
            break;
        }

        if (flag_last)
        {
            flag_last = 0;
            OLED_Clear();
            switch (flag)
            {
            case 1:
                OLED_ShowString(0, 8, "<--   ", OLED_6X8);
                OLED_ShowString(0, 24, "M6-1   ", OLED_6X8);
                OLED_ShowString(0, 40, "M6-2   ", OLED_6X8);
                OLED_ShowString(0, 56, "M6-3   ", OLED_6X8);
                OLED_ReverseArea(0, 8, 128, 8);
                break;
            case 2:
                OLED_ShowString(0, 8, "<--   ", OLED_6X8);
                OLED_ShowString(0, 24, "M6-1   ", OLED_6X8);
                OLED_ShowString(0, 40, "M6-2   ", OLED_6X8);
                OLED_ShowString(0, 56, "M6-3   ", OLED_6X8);
                OLED_ReverseArea(0, 24, 128, 8);
                break;
            case 3:
                OLED_ShowString(0, 8, "<--   ", OLED_6X8);
                OLED_ShowString(0, 24, "M6-1   ", OLED_6X8);
                OLED_ShowString(0, 40, "M6-2   ", OLED_6X8);
                OLED_ShowString(0, 56, "M6-3   ", OLED_6X8);
                OLED_ReverseArea(0, 40, 128, 8);
                break;
            case 4:
                OLED_ShowString(0, 8, "<--   ", OLED_6X8);
                OLED_ShowString(0, 24, "M6-1   ", OLED_6X8);
                OLED_ShowString(0, 40, "M6-2   ", OLED_6X8);
                OLED_ShowString(0, 56, "M6-3   ", OLED_6X8);
                OLED_ReverseArea(0, 56, 128, 8);
                break;
            case 5:
                OLED_ShowString(0, 8, "M6-1   ", OLED_6X8);
                OLED_ShowString(0, 24, "M6-2   ", OLED_6X8);
                OLED_ShowString(0, 40, "M6-3   ", OLED_6X8);
                OLED_ShowString(0, 56, "M6-4   ", OLED_6X8);
                OLED_ReverseArea(0, 56, 128, 8);
                break;
            }
            OLED_Update();
        }
    }
}

uint8_t menu7_x(void)
{
    static uint8_t flag = 1;
    uint8_t flag_last = 1;
    uint8_t Key_num;
    uint8_t menu2 = 0;
    while (1)
    {
        Key_num = Key_GetState();
        if (Key_num == 1)
        {
            flag++;
            flag_last = 1;
            if (flag > 5)
                flag = 1;
        }
        else if (Key_num == 2)
        {
            flag--;
            flag_last = 1;
            if (flag < 1)
                flag = 5;
        }
        else if (Key_num == 3)
        {
            OLED_Clear();
            OLED_Update();
            menu2 = flag;
        }
        switch (menu2)
        {
        case 1:
            return 0;
        default:
            flag_last = 1;
            break;
        }

        if (flag_last)
        {
            flag_last = 0;
            OLED_Clear();
            switch (flag)
            {
            case 1:
                OLED_ShowString(0, 8, "<--   ", OLED_6X8);
                OLED_ShowString(0, 24, "M7-1   ", OLED_6X8);
                OLED_ShowString(0, 40, "M7-2   ", OLED_6X8);
                OLED_ShowString(0, 56, "M7-3   ", OLED_6X8);
                OLED_ReverseArea(0, 8, 128, 8);
                break;
            case 2:
                OLED_ShowString(0, 8, "<--   ", OLED_6X8);
                OLED_ShowString(0, 24, "M7-1   ", OLED_6X8);
                OLED_ShowString(0, 40, "M7-2   ", OLED_6X8);
                OLED_ShowString(0, 56, "M7-3   ", OLED_6X8);
                OLED_ReverseArea(0, 24, 128, 8);
                break;
            case 3:
                OLED_ShowString(0, 8, "<--   ", OLED_6X8);
                OLED_ShowString(0, 24, "M7-1   ", OLED_6X8);
                OLED_ShowString(0, 40, "M7-2   ", OLED_6X8);
                OLED_ShowString(0, 56, "M7-3   ", OLED_6X8);
                OLED_ReverseArea(0, 40, 128, 8);
                break;
            case 4:
                OLED_ShowString(0, 8, "<--   ", OLED_6X8);
                OLED_ShowString(0, 24, "M7-1   ", OLED_6X8);
                OLED_ShowString(0, 40, "M7-2   ", OLED_6X8);
                OLED_ShowString(0, 56, "M7-3   ", OLED_6X8);
                OLED_ReverseArea(0, 56, 128, 8);
                break;
            case 5:
                OLED_ShowString(0, 8, "M7-1   ", OLED_6X8);
                OLED_ShowString(0, 24, "M7-2   ", OLED_6X8);
                OLED_ShowString(0, 40, "M7-3   ", OLED_6X8);
                OLED_ShowString(0, 56, "M7-4   ", OLED_6X8);
                OLED_ReverseArea(0, 56, 128, 8);
                break;
            }
            OLED_Update();
        }
    }
}

uint8_t menu8_x(void)
{
    static uint8_t flag = 1;
    uint8_t flag_last = 1;
    uint8_t Key_num;
    uint8_t menu2 = 0;
    while (1)
    {
        Key_num = Key_GetState();
        if (Key_num == 1)
        {
            flag++;
            flag_last = 1;
            if (flag > 5)
                flag = 1;
        }
        else if (Key_num == 2)
        {
            flag--;
            flag_last = 1;
            if (flag < 1)
                flag = 5;
        }
        else if (Key_num == 3)
        {
            OLED_Clear();
            OLED_Update();
            menu2 = flag;
        }
        switch (menu2)
        {
        case 1:
            return 0;
        default:
            flag_last = 1;
            break;
        }

        if (flag_last)
        {
            flag_last = 0;
            OLED_Clear();
            switch (flag)
            {
            case 1:
                OLED_ShowString(0, 8, "<--   ", OLED_6X8);
                OLED_ShowString(0, 24, "M8-1   ", OLED_6X8);
                OLED_ShowString(0, 40, "M8-2   ", OLED_6X8);
                OLED_ShowString(0, 56, "M8-3   ", OLED_6X8);
                OLED_ReverseArea(0, 8, 128, 8);
                break;
            case 2:
                OLED_ShowString(0, 8, "<--   ", OLED_6X8);
                OLED_ShowString(0, 24, "M8-1   ", OLED_6X8);
                OLED_ShowString(0, 40, "M8-2   ", OLED_6X8);
                OLED_ShowString(0, 56, "M8-3   ", OLED_6X8);
                OLED_ReverseArea(0, 24, 128, 8);
                break;
            case 3:
                OLED_ShowString(0, 8, "<--   ", OLED_6X8);
                OLED_ShowString(0, 24, "M8-1   ", OLED_6X8);
                OLED_ShowString(0, 40, "M8-2   ", OLED_6X8);
                OLED_ShowString(0, 56, "M8-3   ", OLED_6X8);
                OLED_ReverseArea(0, 40, 128, 8);
                break;
            case 4:
                OLED_ShowString(0, 8, "<--   ", OLED_6X8);
                OLED_ShowString(0, 24, "M8-1   ", OLED_6X8);
                OLED_ShowString(0, 40, "M8-2   ", OLED_6X8);
                OLED_ShowString(0, 56, "M8-3   ", OLED_6X8);
                OLED_ReverseArea(0, 56, 128, 8);
                break;
            case 5:
                OLED_ShowString(0, 8, "M8-1   ", OLED_6X8);
                OLED_ShowString(0, 24, "M8-2   ", OLED_6X8);
                OLED_ShowString(0, 40, "M8-3   ", OLED_6X8);
                OLED_ShowString(0, 56, "M8-4   ", OLED_6X8);
                OLED_ReverseArea(0, 56, 128, 8);
                break;
            }
            OLED_Update();
        }
    }
}
