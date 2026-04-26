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
            {
                flag = 1;
            }
        }
        else if (Key_num == 2)
        {
            flag--;
            flag_last = 1;
            if (flag < 1)
            {
                flag = 8;
            }
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
            {
                flag = 1;
            }
        }
        else if (Key_num == 2)
        {
            flag--;
            flag_last = 1;
            if (flag < 1)
            {
                flag = 5;
            }
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
            {
                flag = 1;
            }
        }
        else if (Key_num == 2)
        {
            flag--;
            flag_last = 1;
            if (flag < 1)
            {
                flag = 5;
            }
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
                OLED_ShowString(0, 24, "M2-1   ", OLED_6X8);
                OLED_ShowString(0, 40, "M2-2   ", OLED_6X8);
                OLED_ShowString(0, 56, "M2-3   ", OLED_6X8);
                OLED_ReverseArea(0, 8, 128, 8);
                break;
            case 2:
                OLED_ShowString(0, 8, "<--   ", OLED_6X8);
                OLED_ShowString(0, 24, "M2-1   ", OLED_6X8);
                OLED_ShowString(0, 40, "M2-2   ", OLED_6X8);
                OLED_ShowString(0, 56, "M2-3   ", OLED_6X8);
                OLED_ReverseArea(0, 24, 128, 8);
                break;
            case 3:
                OLED_ShowString(0, 8, "<--   ", OLED_6X8);
                OLED_ShowString(0, 24, "M2-1   ", OLED_6X8);
                OLED_ShowString(0, 40, "M2-2   ", OLED_6X8);
                OLED_ShowString(0, 56, "M2-3   ", OLED_6X8);
                OLED_ReverseArea(0, 40, 128, 8);
                break;
            case 4:
                OLED_ShowString(0, 8, "<--   ", OLED_6X8);
                OLED_ShowString(0, 24, "M2-1   ", OLED_6X8);
                OLED_ShowString(0, 40, "M2-2   ", OLED_6X8);
                OLED_ShowString(0, 56, "M2-3   ", OLED_6X8);
                OLED_ReverseArea(0, 56, 128, 8);
                break;
            case 5:
                OLED_ShowString(0, 8, "M2-1   ", OLED_6X8);
                OLED_ShowString(0, 24, "M2-2   ", OLED_6X8);
                OLED_ShowString(0, 40, "M2-3   ", OLED_6X8);
                OLED_ShowString(0, 56, "M2-4   ", OLED_6X8);
                OLED_ReverseArea(0, 56, 128, 8);
                break;
            }
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
    while (1)
    {
        Key_num = Key_GetState();
        if (Key_num == 1)
        {
            flag++;
            flag_last = 1;
            if (flag > 5)
            {
                flag = 1;
            }
        }
        else if (Key_num == 2)
        {
            flag--;
            flag_last = 1;
            if (flag < 1)
            {
                flag = 5;
            }
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
                OLED_ShowString(0, 24, "M3-1   ", OLED_6X8);
                OLED_ShowString(0, 40, "M3-2   ", OLED_6X8);
                OLED_ShowString(0, 56, "M3-3   ", OLED_6X8);
                OLED_ReverseArea(0, 8, 128, 8);
                break;
            case 2:
                OLED_ShowString(0, 8, "<--   ", OLED_6X8);
                OLED_ShowString(0, 24, "M3-1   ", OLED_6X8);
                OLED_ShowString(0, 40, "M3-2   ", OLED_6X8);
                OLED_ShowString(0, 56, "M3-3   ", OLED_6X8);
                OLED_ReverseArea(0, 24, 128, 8);
                break;
            case 3:
                OLED_ShowString(0, 8, "<--   ", OLED_6X8);
                OLED_ShowString(0, 24, "M3-1   ", OLED_6X8);
                OLED_ShowString(0, 40, "M3-2   ", OLED_6X8);
                OLED_ShowString(0, 56, "M3-3   ", OLED_6X8);
                OLED_ReverseArea(0, 40, 128, 8);
                break;
            case 4:
                OLED_ShowString(0, 8, "<--   ", OLED_6X8);
                OLED_ShowString(0, 24, "M3-1   ", OLED_6X8);
                OLED_ShowString(0, 40, "M3-2   ", OLED_6X8);
                OLED_ShowString(0, 56, "M3-3   ", OLED_6X8);
                OLED_ReverseArea(0, 56, 128, 8);
                break;
            case 5:
                OLED_ShowString(0, 8, "M3-1   ", OLED_6X8);
                OLED_ShowString(0, 24, "M3-2   ", OLED_6X8);
                OLED_ShowString(0, 40, "M3-3   ", OLED_6X8);
                OLED_ShowString(0, 56, "M3-4   ", OLED_6X8);
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
            {
                flag = 1;
            }
        }
        else if (Key_num == 2)
        {
            flag--;
            flag_last = 1;
            if (flag < 1)
            {
                flag = 5;
            }
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
            {
                flag = 1;
            }
        }
        else if (Key_num == 2)
        {
            flag--;
            flag_last = 1;
            if (flag < 1)
            {
                flag = 5;
            }
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
            {
                flag = 1;
            }
        }
        else if (Key_num == 2)
        {
            flag--;
            flag_last = 1;
            if (flag < 1)
            {
                flag = 5;
            }
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
            {
                flag = 1;
            }
        }
        else if (Key_num == 2)
        {
            flag--;
            flag_last = 1;
            if (flag < 1)
            {
                flag = 5;
            }
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
            {
                flag = 1;
            }
        }
        else if (Key_num == 2)
        {
            flag--;
            flag_last = 1;
            if (flag < 1)
            {
                flag = 5;
            }
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
