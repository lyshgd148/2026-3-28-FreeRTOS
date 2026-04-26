#ifndef LED__H
#define LED__H

#include <stdint.h>
#include "main.h"

#define LED_NUM 2



static void LED_ON(uint8_t num);
static void LED_OFF(uint8_t num);
void LED_SetMode(uint8_t mode, uint8_t nb);
static void LED_RunMode(uint8_t *led_mode, uint16_t *lde_tick, uint8_t nb);
void LED_Tick(void);

#endif
