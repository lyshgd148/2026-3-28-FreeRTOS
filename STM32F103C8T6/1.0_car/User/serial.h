#ifndef _SERIAL_H
#define _SERIAL_H

#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define rx_len 100

struct Struct_key{
	char *name ;
	char *operation;
};

struct Struct_slider{
	char *name;
	float value;
};

struct Struct_joystick{
	int8_t lh;
	int8_t lv;
	int8_t rh;	
	int8_t rv;
};

struct Struct_SerialRx{
		uint8_t rx_buf[rx_len];
		uint8_t recv_len;
		uint8_t recv_done;
		char * data_token;
		struct Struct_key key;
		struct Struct_slider slider;
		struct Struct_joystick joystick;
	
};

extern struct Struct_SerialRx rx;

void SerialGetData( struct Struct_SerialRx * rx );

#endif
