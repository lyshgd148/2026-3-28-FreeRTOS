#include "nrf24l01.h"

void NRF24L01_W_CE(GPIO_PinState PINState)
{
    // 写入CE引脚
    HAL_GPIO_WritePin(W_CE_GPIO_Port, W_CE_Pin, PINState);
}

void NRF24L01_W_CSN(GPIO_PinState PINState)
{
    // 写入CSN引脚
    HAL_GPIO_WritePin(W_CSN_GPIO_Port, W_CSN_Pin, PINState);
}

// HAL_SPI_TransmitReceive(&hspi1,&tx,&rx,1,100);
// HAL_SPI_Transmit(&hspi1,data,len,100);

uint8_t NRF24L01_WriteReg(uint8_t reg, uint8_t *data, uint16_t len)
{
    uint8_t status;
    reg = NRF24L01_W_REGISTER | (reg & 0x1F); // 写寄存器命令

    NRF24L01_W_CSN(GPIO_PIN_RESET);
    HAL_SPI_TransmitReceive(&hspi1, &reg, &status, 1, 100);

    if (len > 0)
    {
        if (HAL_SPI_Transmit(&hspi1, data, len, 100) != HAL_OK)
            return 0xff;
    }
    else
    {
        NRF24L01_W_CSN(GPIO_PIN_SET);
        return 0xff;
    }
    NRF24L01_W_CSN(GPIO_PIN_SET);

    return status;
}

uint8_t NRF24L01_ReadReg(uint8_t reg, uint8_t *data, uint16_t len)
{
    uint8_t status;
    uint8_t tx = NRF24L01_NOP;
    reg = NRF24L01_R_REGISTER | (reg & 0x1F);

    NRF24L01_W_CSN(GPIO_PIN_RESET);
    HAL_SPI_TransmitReceive(&hspi1, &reg, &status, 1, 100);
    if (len > 0)
        HAL_SPI_TransmitReceive(&hspi1, &tx, data, len, 100);
    else
    {
        NRF24L01_W_CSN(GPIO_PIN_SET);
        return 0xff;
    }

    NRF24L01_W_CSN(GPIO_PIN_SET);
    return status;
}

uint8_t NRF24L01_WriteTxPayload(uint8_t *data, uint16_t len)
{
    uint8_t status;
    uint8_t command = NRF24L01_W_TX_PAYLOAD; // 写有效载荷命令

    NRF24L01_W_CSN(GPIO_PIN_RESET);
    HAL_SPI_TransmitReceive(&hspi1, &command, &status, 1, 100);

    if (len > 0)
    {
        if (HAL_SPI_Transmit(&hspi1, data, len, 100) != HAL_OK)
            return 0xff;
    }
    else
    {
        NRF24L01_W_CSN(GPIO_PIN_SET);
        return 0xff;
    }
    NRF24L01_W_CSN(GPIO_PIN_SET);

    return status;
}

uint8_t NRF24L01_ReadRxPayload(uint8_t *data, uint16_t len)
{
    uint8_t status;
    uint8_t tx = NRF24L01_NOP;
    uint8_t command = NRF24L01_R_RX_PAYLOAD; // 读有效载荷命令

    NRF24L01_W_CSN(GPIO_PIN_RESET);
    HAL_SPI_TransmitReceive(&hspi1, &command, &status, 1, 100);
    if (len > 0)
        HAL_SPI_TransmitReceive(&hspi1, &tx, data, len, 100);
    else
    {
        NRF24L01_W_CSN(GPIO_PIN_SET);
        return 0xff;
    }

    NRF24L01_W_CSN(GPIO_PIN_SET);
    return status;
}

void NRF24L01_FlushTx(void)
{
    uint8_t status;
    uint8_t command = NRF24L01_FLUSH_TX; // 刷新有效载荷命令

    NRF24L01_W_CSN(GPIO_PIN_RESET);
    HAL_SPI_TransmitReceive(&hspi1, &command, &status, 1, 100);
    NRF24L01_W_CSN(GPIO_PIN_SET);
}

void NRF24L01_FlushRx(void)
{
    uint8_t status;
    uint8_t command = NRF24L01_FLUSH_RX; // 刷新接收命令

    NRF24L01_W_CSN(GPIO_PIN_RESET);
    HAL_SPI_TransmitReceive(&hspi1, &command, &status, 1, 100);
    NRF24L01_W_CSN(GPIO_PIN_SET);
} 

void NRF24L01_Init(void)
{
    // 初始化NRF24L01
}
