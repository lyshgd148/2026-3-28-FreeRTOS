#include "Circular.h"

uint8_t RingBuffer[BUFFER_LEN];

int circular_buffer_init(CircularBuffer *circular, uint8_t *Buffer, uint16_t Buffersize)
{
    if (circular == NULL)
        return -1;
    circular->front = 0;
    circular->rear = 0;
    circular->len = 0;
    circular->buffer = Buffer;
    circular->buffersize = Buffersize;
    return 0;
}

void circular_Write(CircularBuffer *circular)
{

    static uint16_t pos = 0;
    uint16_t size;
    uint16_t temp;

    temp = circular->buffersize - __HAL_DMA_GET_COUNTER(&hdma_usart1_rx);
    size = (temp - pos + circular->buffersize) % BUFFER_LEN;
    pos = temp;
    circular->rear = (circular->rear + size) % BUFFER_LEN;
    circular->len += size;
}

int circular_Read_Size(CircularBuffer *circular, uint16_t size, uint8_t *dest, uint16_t pos)
{
    if (circular->len < size)
        return -1;

    for (int i = 0; i < size; i++)
    {
        dest[pos + i] = circular->buffer[circular->front];
        circular->front = (circular->front + 1) % BUFFER_LEN;
    }

    circular->len -= size;

    return 0;
}
