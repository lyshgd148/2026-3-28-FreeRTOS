#include "motor.h"
#include "tim.h"



void Motor_SetPWM(uint8_t n, int8_t PWM)
{
    if (n == 1) // 右带电机
    {
        if (PWM >= 0) // PWM>0 向前
        {
            HAL_GPIO_WritePin(Ain1_GPIO_Port, Ain1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(Ain2_GPIO_Port, Ain2_Pin, GPIO_PIN_SET);
            TIM1->CCR4 = PWM;
        }
        else
        {
            HAL_GPIO_WritePin(Ain1_GPIO_Port, Ain1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(Ain2_GPIO_Port, Ain2_Pin, GPIO_PIN_RESET);
            TIM1->CCR4 = (-PWM);
        }
    }
    else if (n == 2)
    {
        if (PWM >= 0) // PWM>0 向前
        {
            HAL_GPIO_WritePin(Bin1_GPIO_Port, Bin1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(Bin2_GPIO_Port, Bin2_Pin, GPIO_PIN_RESET);
            TIM1->CCR1 = PWM;
        }
        else
        {
            HAL_GPIO_WritePin(Bin1_GPIO_Port, Bin1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(Bin2_GPIO_Port, Bin2_Pin, GPIO_PIN_SET);
            TIM1->CCR1 = (-PWM);
        }
    }
}
