#ifndef __MPU6050_H
#define __MPU6050_H

#include <stdint.h>

struct Struct_MPU6050
{
	int16_t accX;
	int16_t accY;
	int16_t accZ;
	int16_t gyroX;
	int16_t gyroY;
	int16_t gyroZ;
};

extern struct Struct_MPU6050 mpu6050;

void MPU6050_WriteReg(uint8_t RegAddress, uint8_t Data);
uint8_t MPU6050_ReadReg(uint8_t RegAddress);
void MPU6050_ReadRegs(uint8_t RegAddress, uint8_t *DataArray, uint8_t Count);

void MPU6050_Init(void);
uint8_t MPU6050_GetID(void);
// void MPU6050_GetData(int16_t *AccX, int16_t *AccY, int16_t *AccZ,
//						int16_t *GyroX, int16_t *GyroY, int16_t *GyroZ);
void MPU6050_GetData(struct Struct_MPU6050 *mpu6050);

#endif
