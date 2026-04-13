#include "MyI2C.h"
#include "MPU6050_Reg.h"
#include "MPU6050.h"

#define MPU6050_ADDRESS 0xD0

struct Struct_MPU6050 mpu6050;

void MPU6050_WriteReg(uint8_t RegAddress, uint8_t Data)
{
	MyI2C_Start();
	MyI2C_SendByte(MPU6050_ADDRESS);
	MyI2C_ReceiveAck();
	MyI2C_SendByte(RegAddress);
	MyI2C_ReceiveAck();
	MyI2C_SendByte(Data);
	MyI2C_ReceiveAck();
	MyI2C_Stop();
}

uint8_t MPU6050_ReadReg(uint8_t RegAddress)
{
	uint8_t Data;

	MyI2C_Start();
	MyI2C_SendByte(MPU6050_ADDRESS);
	MyI2C_ReceiveAck();
	MyI2C_SendByte(RegAddress);
	MyI2C_ReceiveAck();

	MyI2C_Start();
	MyI2C_SendByte(MPU6050_ADDRESS | 0x01);
	MyI2C_ReceiveAck();
	Data = MyI2C_ReceiveByte();
	MyI2C_SendAck(1);
	MyI2C_Stop();

	return Data;
}

void MPU6050_ReadRegs(uint8_t RegAddress, uint8_t *DataArray, uint8_t Count)
{
	uint8_t i;

	MyI2C_Start();
	MyI2C_SendByte(MPU6050_ADDRESS);
	MyI2C_ReceiveAck();
	MyI2C_SendByte(RegAddress);
	MyI2C_ReceiveAck();

	MyI2C_Start();
	MyI2C_SendByte(MPU6050_ADDRESS | 0x01);
	MyI2C_ReceiveAck();
	for (i = 0; i < Count; i++)
	{
		DataArray[i] = MyI2C_ReceiveByte();
		if (i < Count - 1)
		{
			MyI2C_SendAck(0);
		}
		else
		{
			MyI2C_SendAck(1);
		}
	}
	MyI2C_Stop();
}

void MPU6050_Init(void)
{
	//	MyI2C_Init();
	// MPU6050_WriteReg(MPU6050_PWR_MGMT_1, 0x01);
	// MPU6050_WriteReg(MPU6050_PWR_MGMT_2, 0x00);
	// MPU6050_WriteReg(MPU6050_SMPLRT_DIV, 0x09);
	// MPU6050_WriteReg(MPU6050_CONFIG, 0x06);
	// MPU6050_WriteReg(MPU6050_GYRO_CONFIG, 0x18);
	// MPU6050_WriteReg(MPU6050_ACCEL_CONFIG, 0x18);
	MPU6050_WriteReg(MPU6050_PWR_MGMT_1, 0x01);
	MPU6050_WriteReg(MPU6050_PWR_MGMT_2, 0x00);
	MPU6050_WriteReg(MPU6050_SMPLRT_DIV, 0x07);	  // sampleFrequence = 8K / MPU6050_SMPLRT_DIV
	MPU6050_WriteReg(MPU6050_CONFIG, 0x00);		  // 滤波器配置位0 减小延时
	MPU6050_WriteReg(MPU6050_GYRO_CONFIG, 0x18);  // 2000 °/s
	MPU6050_WriteReg(MPU6050_ACCEL_CONFIG, 0x18); // 16g
}

uint8_t MPU6050_GetID(void)
{
	return MPU6050_ReadReg(MPU6050_WHO_AM_I);
}

// void MPU6050_GetData(int16_t *AccX, int16_t *AccY, int16_t *AccZ,
//						int16_t *GyroX, int16_t *GyroY, int16_t *GyroZ)
//  void MPU6050_GetData(struct Struct_MPU6050 * mpu6050)
//  {
//  	uint8_t DataH, DataL;

// 	DataH = MPU6050_ReadReg(MPU6050_ACCEL_XOUT_H);
// 	DataL = MPU6050_ReadReg(MPU6050_ACCEL_XOUT_L);
// 	mpu6050->accX = (DataH << 8) | DataL;

// 	DataH = MPU6050_ReadReg(MPU6050_ACCEL_YOUT_H);
// 	DataL = MPU6050_ReadReg(MPU6050_ACCEL_YOUT_L);
// 	mpu6050->accY = (DataH << 8) | DataL;

// 	DataH = MPU6050_ReadReg(MPU6050_ACCEL_ZOUT_H);
// 	DataL = MPU6050_ReadReg(MPU6050_ACCEL_ZOUT_L);
// 	mpu6050->accZ  = (DataH << 8) | DataL;

// 	DataH = MPU6050_ReadReg(MPU6050_GYRO_XOUT_H);
// 	DataL = MPU6050_ReadReg(MPU6050_GYRO_XOUT_L);
// 	mpu6050->gyroX  = (DataH << 8) | DataL;

// 	DataH = MPU6050_ReadReg(MPU6050_GYRO_YOUT_H);
// 	DataL = MPU6050_ReadReg(MPU6050_GYRO_YOUT_L);
// 	mpu6050->gyroY = (DataH << 8) | DataL;

// 	DataH = MPU6050_ReadReg(MPU6050_GYRO_ZOUT_H);
// 	DataL = MPU6050_ReadReg(MPU6050_GYRO_ZOUT_L);
// 	mpu6050->gyroZ = (DataH << 8) | DataL;
// }

void MPU6050_GetData(struct Struct_MPU6050 *mpu6050)
{
	uint8_t Data[14];

	MPU6050_ReadRegs(MPU6050_ACCEL_XOUT_H, Data, 14);

	mpu6050->accX = (Data[0] << 8) | Data[1];
	mpu6050->accY = (Data[2] << 8) | Data[3];
	mpu6050->accZ = (Data[4] << 8) | Data[5];

	mpu6050->gyroX = (Data[8] << 8) | Data[9];
	mpu6050->gyroY = (Data[10] << 8) | Data[11];
	mpu6050->gyroZ = (Data[12] << 8) | Data[13];
}
