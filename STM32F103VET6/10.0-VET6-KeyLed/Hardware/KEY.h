#ifndef KEY__H
#define KEY__H

#include <stdint.h>
#include "main.h"

uint8_t Key_GetNum(void);
static uint8_t Key_GetState(void);
void KEY_Tick(void);

#endif
