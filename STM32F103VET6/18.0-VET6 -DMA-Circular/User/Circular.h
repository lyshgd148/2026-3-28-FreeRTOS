#ifndef CIRCULAR_H
#define CIRCULAR_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "main.h"
extern DMA_HandleTypeDef hdma_usart1_rx;


#define BUFFER_LEN 3072

extern uint8_t RingBuffer[BUFFER_LEN];

typedef struct
{
    uint16_t front;
    uint16_t rear;
    uint16_t len;
    uint8_t *buffer;
    uint16_t buffersize;
} CircularBuffer;


int circular_buffer_init(CircularBuffer *circular, uint8_t *Buffer, uint16_t Buffersize);
int circular_Write(CircularBuffer *circular);
int circular_Read_Size(CircularBuffer *circular, uint16_t size, uint8_t *dest, uint16_t pos);

#endif
