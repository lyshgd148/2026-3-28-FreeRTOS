#ifndef KEY__H
#define KEY__H

#include <stdint.h>
#include "main.h"

#define KEY_NUM 3
#define KEY1 0
#define KEY2 1
#define KEY3 2


#define KEY_PRESSED 1
#define KEY_UNPRESSED 0

#define KEY_HOLD 0X01
#define KEY_DOWN 0X02
#define KEY_UP 0X04
#define KEY_SINGLE 0X08
#define KEY_DOUBLE 0X10
#define KEY_LONG 0X20
#define KEY_REPEAT 0X40

#define KEY_TIME_DOUBLE 200
#define KEY_TIME_LONG 1000
#define KEY_TIME_REPEAT 50



static uint8_t Key_GetState(uint8_t n);

uint8_t Key_Check(uint8_t Flag, uint8_t n);
void KEY_Tick(void);

#endif
