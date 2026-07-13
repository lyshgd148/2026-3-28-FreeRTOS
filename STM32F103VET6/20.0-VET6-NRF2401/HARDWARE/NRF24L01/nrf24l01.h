#ifndef __NRF24L01_H__
#define __NRF24L01_H__

#include <stdint.h>
#include "main.h"
#include "spi.h"
#include "nrf24l01Config.h"

void NRF24L01_W_CE(GPIO_PinState PINState);
void NRF24L01_W_CSN(GPIO_PinState PINState);
uint8_t NRF24L01_WriteReg(uint8_t reg, uint8_t *data, uint16_t len);
uint8_t NRF24L01_ReadReg(uint8_t reg, uint8_t *data, uint16_t len);
void NRF24L01_Init(void);

#endif
