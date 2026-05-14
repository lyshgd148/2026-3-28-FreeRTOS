#ifndef MYUART_H
#define MYUART_H

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include "main.h"

#define USART_MALOC 1 //1-malloc 0-静态分配

typedef enum
{
    DMA_MODE = 0,
    IT_MODE
} UsartMode;

typedef struct USART_Data USART_Data;

typedef void (*uartCallBack)(struct USART_Data *);

typedef struct USART_Data
{
    UART_HandleTypeDef *huart;
    uint8_t rxBuffer;

    uint16_t usart_rx_sta;
    uint16_t rxSize_Max;

    uint8_t *usart_rx_buffer;

    uartCallBack callback;

    struct USART_Data *next;

} USART_Data;

#if USART_MALOC == 1
uint8_t USART_DataTypeInit(USART_Data *me, UART_HandleTypeDef *huart, uint16_t rxSize_Max, UsartMode receiveMode, uartCallBack callback);

#else
uint8_t USART_DataTypeInit(USART_Data *me, UART_HandleTypeDef *huart, uint8_t *rxBuffer, uint16_t rxSize_Max, UsartMode receiveMode, uartCallBack callback);
#endif

static inline bool USART_DataIsReceived(USART_Data *me)
{
    return (me->usart_rx_sta & 0x8000);
}

static inline uint16_t USART_DataGetReceivedLen(USART_Data *me)
{
    return (me->usart_rx_sta & 0x3fff);
}

static inline void USART_DataResetReceivedFlag(USART_Data *me)
{
    me->usart_rx_sta &= 0x3fff;
}

static inline uint8_t* USART_GetData(USART_Data *me)
{
    return me->usart_rx_buffer;
}

#endif
