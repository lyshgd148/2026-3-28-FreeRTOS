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
uint8_t USART_DataTypeInit(USART_Data *this, UART_HandleTypeDef *huart, uint16_t rxSize_Max, UsartMode receiveMode, uartCallBack callback)
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

#ifdef UART_DATA_LIFO
    uint8_t *Buffer = (uint8_t *)malloc(sizeof(uint8_t) * rxSize_Max);
    if (Buffer == NULL)
    {
        return 2;
    }
    int ret = USART_DataAttach(this);
    if (ret != 0)
    {
        free(Buffer);
        return 1;
    }

    this->rxSize_Max = rxSize_Max / 3;
    this->usart_rx_buffer[0] = Buffer;
    this->usart_rx_buffer[1] = Buffer + rxSize_Max / 3;
    this->usart_rx_buffer[2] = Buffer + 2 * rxSize_Max / 3;

    this->ReadyPtr = NULL;
    this->processPtr = NULL;
    this->writePtr = this->usart_rx_buffer[0];

#else
    this->usart_rx_buffer = (uint8_t *)malloc(sizeof(uint8_t) * rxSize_Max);
    if (this->usart_rx_buffer == NULL)
        return 2;

    int ret = USART_DataAttach(this);
    if (ret != 0)
    {
        free(this->usart_rx_buffer);
        return 1;
    }

    this->rxSize_Max = rxSize_Max;

#endif
    this->huart = huart;
    this->callback = callback;

    if (receiveMode == DMA_MODE)
    {
#ifdef UART_DATA_LIFO
        HAL_UARTEx_ReceiveToIdle_DMA(this->huart, this->writePtr, this->rxSize_Max);
#else
        HAL_UARTEx_ReceiveToIdle_DMA(this->huart, this->usart_rx_buffer, this->rxSize_Max);
#endif
        __HAL_DMA_DISABLE_IT(this->huart->hdmarx, DMA_IT_HT);
    }
    else if (receiveMode == IT_MODE)
    {
        HAL_UART_Receive_IT(this->huart, &this->rxBuffer, 1);
    }
    return 0;
}

#else
uint8_t USART_DataTypeInit(USART_Data *this, UART_HandleTypeDef *huart, uint8_t *rxBuffer, uint16_t rxSize_Max, UsartMode receiveMode, uartCallBack callback)
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
    int ret = USART_DataAttach(this);
    if (ret != 0)
    {
        return 1;
    }
#ifdef UART_DATA_LIFO

    this->rxSize_Max = rxSize_Max / 3;
    this->usart_rx_buffer[0] = rxBuffer;
    this->usart_rx_buffer[1] = rxBuffer + rxSize_Max / 3;
    this->usart_rx_buffer[2] = rxBuffer + 2 * rxSize_Max / 3;

    this->ReadyPtr = NULL;
    this->processPtr = NULL;
    this->writePtr = this->usart_rx_buffer[0];
#else
    this->usart_rx_buffer = rxBuffer;
    this->rxSize_Max = rxSize_Max;
#endif
    this->huart = huart;
    this->callback = callback;

    if (receiveMode == DMA_MODE)
    {
#ifdef UART_DATA_LIFO
        HAL_UARTEx_ReceiveToIdle_DMA(this->huart, this->writePtr, this->rxSize_Max);
#else
        HAL_UARTEx_ReceiveToIdle_DMA(this->huart, this->usart_rx_buffer, this->rxSize_Max);
#endif
        __HAL_DMA_DISABLE_IT(this->huart->hdmarx, DMA_IT_HT);
    }
    else if (receiveMode == IT_MODE)
    {
        HAL_UART_Receive_IT(this->huart, &this->rxBuffer, 1);
    }
    return 0;
}

#endif

#ifdef UART_DATA_LIFO
static uint8_t *getNextWritePtr(USART_Data *this)
{
    uint8_t *temp = NULL;

    for (int i = 0; i < 3; i++)
    {
        if (this->usart_rx_buffer[i] != this->ReadyPtr && this->usart_rx_buffer[i] != this->processPtr)
        {
            temp = this->usart_rx_buffer[i];
            break;
        }
    }
    return temp;
}

uint8_t *uartDataProcessLock(USART_Data *this)
{

    this->processPtr = this->ReadyPtr;
    this->processDataSize = this->ReadyDataSize;
    this->ReadyPtr = NULL;
    return this->processPtr;
}

void uartDataProcessUnlock(USART_Data *this)
{
    memset(this->processPtr, 0, sizeof(uint8_t) * this->rxSize_Max);
    this->processPtr = NULL;
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
#ifdef UART_DATA_LIFO
                        this->ReadyPtr = this->writePtr;
                        this->ReadyDataSize = this->usart_rx_sta & 0x3fff;
                        this->usart_rx_sta = 0;
                        this->writePtr = getNextWritePtr(this);
#endif
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
#ifdef UART_DATA_LIFO
                        this->writePtr[this->usart_rx_sta & 0X3FFF] = this->rxBuffer;
#else
                        this->usart_rx_buffer[this->usart_rx_sta & 0X3FFF] = this->rxBuffer;
#endif
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
            if (this->callback != NULL)
                this->callback(this);

            this->usart_rx_sta = Size;
            this->usart_rx_sta |= 0x8000;

#ifdef UART_DATA_LIFO
            this->ReadyPtr = this->writePtr;
            this->ReadyDataSize = Size;
            this->writePtr = getNextWritePtr(this);
            HAL_UARTEx_ReceiveToIdle_DMA(this->huart, this->writePtr, this->rxSize_Max);

#else
            HAL_UARTEx_ReceiveToIdle_DMA(this->huart, this->usart_rx_buffer, this->rxSize_Max);
#endif
            __HAL_DMA_DISABLE_IT(huart->hdmarx, DMA_IT_HT);
        }
        this = this->next;
    }
}
