#ifndef __NRF24L01_CONFIG_H
#define __NRF24L01_CONFIG_H

// ======== 寄存器地址 ========
#define NRF24L01_CONFIG        0x00  // 配置寄存器
#define NRF24L01_EN_AA         0x01  // 自动应答使能
#define NRF24L01_EN_RXADDR     0x02  // 接收地址使能
#define NRF24L01_SETUP_AW      0x03  // 地址宽度设置
#define NRF24L01_SETUP_RETR    0x04  // 自动重传设置
#define NRF24L01_RF_CH         0x05  // 射频通道
#define NRF24L01_RF_SETUP      0x06  // 射频设置
#define NRF24L01_STATUS        0x07  // 状态寄存器
#define NRF24L01_OBSERVE_TX    0x08  // 发送观测
#define NRF24L01_RPD           0x09  // 接收功率检测
#define NRF24L01_RX_ADDR_P0    0x0A  // 接收地址通道0
#define NRF24L01_RX_ADDR_P1    0x0B  // 接收地址通道1
#define NRF24L01_RX_ADDR_P2    0x0C  // 接收地址通道2
#define NRF24L01_RX_ADDR_P3    0x0D  // 接收地址通道3
#define NRF24L01_RX_ADDR_P4    0x0E  // 接收地址通道4
#define NRF24L01_RX_ADDR_P5    0x0F  // 接收地址通道5
#define NRF24L01_TX_ADDR       0x10  // 发送地址
#define NRF24L01_RX_PW_P0      0x11  // 负载宽度通道0
#define NRF24L01_RX_PW_P1      0x12  // 负载宽度通道1
#define NRF24L01_RX_PW_P2      0x13  // 负载宽度通道2
#define NRF24L01_RX_PW_P3      0x14  // 负载宽度通道3
#define NRF24L01_RX_PW_P4      0x15  // 负载宽度通道4
#define NRF24L01_RX_PW_P5      0x16  // 负载宽度通道5
#define NRF24L01_FIFO_STATUS   0x17  // FIFO状态
#define NRF24L01_DYNPD         0x1C  // 动态负载长度使能
#define NRF24L01_FEATURE       0x1D  // 特性寄存器

// ======== SPI命令 ========
#define NRF24L01_R_REGISTER            0x00  // 读寄存器
#define NRF24L01_W_REGISTER            0x20  // 写寄存器
#define NRF24L01_R_RX_PAYLOAD          0x61  // 读RX负载
#define NRF24L01_W_TX_PAYLOAD          0xA0  // 写TX负载
#define NRF24L01_FLUSH_TX              0xE1  // 清空TX FIFO
#define NRF24L01_FLUSH_RX              0xE2  // 清空RX FIFO
#define NRF24L01_REUSE_TX_PL           0xE3  // 重复使用上次负载
#define NRF24L01_R_RX_PL_WID           0x60  // 读RX负载宽度
#define NRF24L01_W_ACK_PAYLOAD         0xA8  // 写ACK负载
#define NRF24L01_W_TX_PAYLOAD_NO_ACK   0xB0  // 写TX负载无ACK
#define NRF24L01_NOP                    0xFF  // NOP命令

#endif
