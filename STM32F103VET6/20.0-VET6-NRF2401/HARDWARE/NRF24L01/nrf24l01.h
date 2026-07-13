#ifndef __NRF24L01_H__
#define __NRF24L01_H__

#include <stdint.h>
#include "main.h"
#include "spi.h"
#include "nrf24l01Config.h"

extern uint8_t NRF24L01_TxPacket[4];
extern uint8_t NRF24L01_RxPacket[4];

void NRF24L01_W_CE(GPIO_PinState PINState);
void NRF24L01_W_CSN(GPIO_PinState PINState);
uint8_t NRF24L01_WriteReg(uint8_t reg, uint8_t *data, uint16_t len);
uint8_t NRF24L01_ReadReg(uint8_t reg, uint8_t *data, uint16_t len);
uint8_t NRF24L01_WriteTxPayload(uint8_t *data, uint16_t len);
uint8_t NRF24L01_ReadRxPayload(uint8_t *data, uint16_t len);
void NRF24L01_FlushTx(void);
void NRF24L01_FlushRx(void);
uint8_t NRF24L01_ReadStatus(void);
/* 工作模式*/
/////////////////////////////////////////////
void NRF24L01_PowerDown(void);
void NRF24L01_StandbyI(void);
void NRF24L01_RxMode(void);
void NRF24L01_TxMode(void);
void NRF24L01_SetMode(NRF24L01_Mode_t mode);
void NRF24L01_Init(void);
void NRF24L01_Send(void);
uint8_t NRF24L01_Receive(void);

#endif
