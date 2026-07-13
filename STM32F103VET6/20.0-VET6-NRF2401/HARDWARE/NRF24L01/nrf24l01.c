#include "nrf24l01.h"

typedef struct
{
    uint8_t reg;
    const uint8_t *data;
    uint8_t len;

} NRF24L01_Config_t;

const uint8_t NRF24L01_RxADDR[6][5] = {{0x11, 0x22, 0x33, 0x44, 0x55}};
const uint8_t NRF24L01_RxWidth[6] = {4};
const uint8_t NRF24L01_TxADDR[6][5] = {{0x11, 0x22, 0x33, 0x44, 0x55}};
const uint8_t NRF24L01_TxWidth[6] = {4};

uint8_t NRF24L01_TxPacket[4] = {0x00};
uint8_t NRF24L01_RxPacket[4] = {0x00};

const uint8_t NRF24L01_ConfigData[] =
    {
        0x08,
        0x3f,
        0x01,
        0x03,
        0x03,
        0x02,
        0x0e};

const NRF24L01_Config_t NRF24L01_InitTable[] =
    {
        {NRF24L01_CONFIG, &NRF24L01_ConfigData[0], 1},

        {NRF24L01_EN_AA, &NRF24L01_ConfigData[1], 1},

        {NRF24L01_EN_RXADDR, &NRF24L01_ConfigData[2], 1},

        {NRF24L01_SETUP_AW, &NRF24L01_ConfigData[3], 1},

        {NRF24L01_SETUP_RETR, &NRF24L01_ConfigData[4], 1},

        {NRF24L01_RF_CH, &NRF24L01_ConfigData[5], 1},

        {NRF24L01_RF_SETUP, &NRF24L01_ConfigData[6], 1},

        {NRF24L01_RX_ADDR_P0, NRF24L01_RxADDR[0], sizeof(NRF24L01_RxADDR[0])},

        {NRF24L01_RX_PW_P0, &NRF24L01_RxWidth[0], 1}};

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

uint8_t NRF24L01_ReadStatus(void)
{
    uint8_t status;
    uint8_t command = NRF24L01_NOP; // 读状态命令

    NRF24L01_W_CSN(GPIO_PIN_RESET);
    HAL_SPI_TransmitReceive(&hspi1, &command, &status, 1, 100);
    NRF24L01_W_CSN(GPIO_PIN_SET);
    return status;
}

/* 工作模式*/
/////////////////////////////////////////////

void NRF24L01_PowerDown(void)
{
    uint8_t config;
    NRF24L01_W_CE(GPIO_PIN_RESET);
    NRF24L01_ReadReg(NRF24L01_CONFIG, &config, 1);
    config &= ~0x02;
    NRF24L01_WriteReg(NRF24L01_CONFIG, &config, 1);
}

void NRF24L01_StandbyI(void)
{
    uint8_t config;
    NRF24L01_W_CE(GPIO_PIN_RESET);
    NRF24L01_ReadReg(NRF24L01_CONFIG, &config, 1);
    config |= 0x02;
    NRF24L01_WriteReg(NRF24L01_CONFIG, &config, 1);
}

void NRF24L01_RxMode(void)
{
    uint8_t config;
    NRF24L01_W_CE(GPIO_PIN_RESET);
    NRF24L01_ReadReg(NRF24L01_CONFIG, &config, 1);
    config |= 0x03;
    NRF24L01_WriteReg(NRF24L01_CONFIG, &config, 1);
    NRF24L01_W_CE(GPIO_PIN_SET);
}
void NRF24L01_TxMode(void)
{
    uint8_t config;
    NRF24L01_W_CE(GPIO_PIN_RESET);
    NRF24L01_ReadReg(NRF24L01_CONFIG, &config, 1);
    config |= 0x02;
    config &= ~0x01;
    NRF24L01_WriteReg(NRF24L01_CONFIG, &config, 1);
    NRF24L01_W_CE(GPIO_PIN_SET);
}

void NRF24L01_SetMode(NRF24L01_Mode_t mode)
{
    uint8_t config;
    NRF24L01_W_CE(GPIO_PIN_RESET);
    NRF24L01_ReadReg(NRF24L01_CONFIG, &config, 1);
    if (mode == NRF24L01_MODE_RX)
    {
        config |= 0x03;
    }
    else if (mode == NRF24L01_MODE_TX)
    {
        config |= 0x02;
        config &= ~0x01;
    }
    else if (mode == NRF24L01_MODE_STDBY_I)
    {
        config |= 0x02;
    }
    else if (mode == NRF24L01_MODE_POWER_DOWN)
    {
        config &= ~0x02;
    }
    NRF24L01_WriteReg(NRF24L01_CONFIG, &config, 1);

    if (mode == NRF24L01_MODE_RX || mode == NRF24L01_MODE_TX)
    {
        NRF24L01_W_CE(GPIO_PIN_SET);
    }
}

void NRF24L01_Init(void)
{
    for (uint8_t i = 0; i < sizeof(NRF24L01_InitTable) / sizeof(NRF24L01_InitTable[0]); i++)
    {
        NRF24L01_WriteReg(
            NRF24L01_InitTable[i].reg,
            (uint8_t *)NRF24L01_InitTable[i].data,
            NRF24L01_InitTable[i].len);
    }
    NRF24L01_SetMode(NRF24L01_MODE_RX);
}

void NRF24L01_Send(void)
{
    uint8_t status;

    NRF24L01_WriteReg(NRF24L01_TX_ADDR, (uint8_t *)NRF24L01_TxADDR[0], 5);
    NRF24L01_WriteTxPayload(NRF24L01_TxPacket, sizeof(NRF24L01_TxPacket));
    NRF24L01_WriteReg(NRF24L01_RX_ADDR_P0, (uint8_t *)NRF24L01_TxADDR[0], 5);

    NRF24L01_SetMode(NRF24L01_MODE_TX);

    uint32_t timeout = 0xFFFFF;
    while (timeout--)
    {
        status = NRF24L01_ReadStatus();
        if (status & 0x20)
        {
            break;
        }
        else if (status & 0x10)
        {
            break;
        }
    }
    NRF24L01_WriteReg(NRF24L01_STATUS, (uint8_t[]){0x30}, 1);
    NRF24L01_FlushTx();
    NRF24L01_WriteReg(NRF24L01_RX_ADDR_P0, (uint8_t *)NRF24L01_RxADDR[0], 5);
    NRF24L01_SetMode(NRF24L01_MODE_RX);
}

uint8_t NRF24L01_Receive(void)
{
    uint8_t status;

    status = NRF24L01_ReadStatus();

    if (status & 0x40)
    {
        NRF24L01_ReadRxPayload(NRF24L01_RxPacket, NRF24L01_RxWidth[0]);
        NRF24L01_WriteReg(NRF24L01_STATUS, (uint8_t[]){0x40}, 1);
        NRF24L01_FlushRx();
        return 0;
    }
    return 1;
}