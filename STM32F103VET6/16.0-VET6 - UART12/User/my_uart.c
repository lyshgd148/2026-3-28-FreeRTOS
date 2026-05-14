#include "my_uart.h"

USART_Data *usartDataHead_handle = NULL;

static int USART_DataAttach(USART_Data *this)
{
    USART_Data *target = usartDataHead_handle;
    while (target)
    {
        if (target == this)
        {
            return 1;
        }
        target = target->next;
    }
    this->next = usartDataHead_handle;
    usartDataHead_handle = this;
    return 0;
}

#if USART_MALOC == 1
uint8_t USART_DataTypeInit(USART_Data *me, UART_HandleTypeDef *huart, uint16_t rxSize_Max, UsartMode receiveMode, uartCallBack callback)
{
    USART_Data *target = usartDataHead_handle;

    while (target)
    {
        if (target->huart == huart)
        {
            return 1;
        }
        target = target->next;
    }

    me->usart_rx_buffer = (uint8_t *)malloc(sizeof(uint8_t) * rxSize_Max);
    if (me->usart_rx_buffer == NULL)
        return 2;

    me->rxSize_Max = rxSize_Max;
    me->huart = huart;
    me->callback = callback;

    int ret = USART_DataAttach(me);
    if (ret != 0)
    {
        free(me->usart_rx_buffer);
        return 1;
    }

    if (receiveMode == DMA_MODE)
    {
        HAL_UARTEx_ReceiveToIdle_DMA(me->huart, me->usart_rx_buffer, me->rxSize_Max);
        __HAL_DMA_DISABLE_IT(me->huart->hdmarx, DMA_IT_HT);
    }
    else if (receiveMode == IT_MODE)
    {
        HAL_UART_Receive_IT(me->huart, &me->rxBuffer, 1);
    }
    return 0;
}

#else
uint8_t USART_DataTypeInit(USART_Data *me, UART_HandleTypeDef *huart, uint8_t *rxBuffer, uint16_t rxSize_Max, UsartMode receiveMode, uartCallBack callback)
{
    USART_Data *target = usartDataHead_handle;

    while (target)
    {
        if (target->huart == huart)
        {
            return 1;
        }
        target = target->next;
    }

    int ret = USART_DataAttach(me);
    if (ret != 0)
    {
        return 1;
    }

    me->usart_rx_buffer = rxBuffer;
    me->rxSize_Max = rxSize_Max;
    me->huart = huart;
    me->callback = callback;

    if (receiveMode == DMA_MODE)
    {
        HAL_UARTEx_ReceiveToIdle_DMA(me->huart, me->usart_rx_buffer, me->rxSize_Max);
        __HAL_DMA_DISABLE_IT(me->huart->hdmarx, DMA_IT_HT);
    }
    else if (receiveMode == IT_MODE)
    {
        HAL_UART_Receive_IT(me->huart, &me->rxBuffer, 1);
    }
    return 0;
}

#endif

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    USART_Data *this = usartDataHead_handle;
    while (this)
    {
        if (huart->Instance == this->huart->Instance)
        {
            if ((this->usart_rx_sta & 0x8000) == 0) /* 接收未完成 */
            {
                if (this->usart_rx_sta & 0x4000) /* 接收到了0x0d（即回车键） */
                {
                    if (this->rxBuffer != 0x0a) /* 接收到的不是0x0a（即不是换行键） */
                    {
                        this->usart_rx_sta = 0; /* 接收错误,重新开始 */
                    }
                    else /* 接收到的是0x0a（即换行键） */
                    {
                        this->usart_rx_sta |= 0x8000; /* 接收完成了 */
                        if (this->callback != NULL)
                        { // 执行回调函数
                            this->callback(this);
                        }
                    }
                }
                else /* 还没收到0X0d（即回车键） */
                {
                    if (this->rxBuffer == 0x0d)
                        this->usart_rx_sta |= 0x4000;
                    else
                    {
                        this->usart_rx_buffer[this->usart_rx_sta & 0X3FFF] = this->rxBuffer;
                        this->usart_rx_sta++;

                        if (this->usart_rx_sta > (this->rxSize_Max - 1))
                        {
                            this->usart_rx_sta = 0; /* 接收数据错误,重新开始接收 */
                        }
                    }
                }
            }
            HAL_UART_Receive_IT(this->huart, &this->rxBuffer, 1);
        }
        this = this->next;
    }
}

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
    USART_Data *this = usartDataHead_handle;
    while (this)
    {
        if (huart->Instance == this->huart->Instance)
        {
            this->usart_rx_sta = Size;
            this->usart_rx_sta |= 0x8000;
            if (this->callback != NULL)
                this->callback(this);
            HAL_UARTEx_ReceiveToIdle_DMA(this->huart, this->usart_rx_buffer, this->rxSize_Max);
            __HAL_DMA_DISABLE_IT(huart->hdmarx, DMA_IT_HT);
        }
        this = this->next;
    }
}
