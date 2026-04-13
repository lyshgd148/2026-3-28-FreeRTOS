#ifndef _KEY_H
#define _KEY_H

#include <stdint.h>

struct Struct_Key
{
	uint8_t RunFlag;
};

extern struct Struct_Key key;

void Key_Tick(void);
#endif
