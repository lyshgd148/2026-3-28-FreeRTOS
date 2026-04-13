#include "key.h"
#include "main.h"

struct Struct_Key key;

void Key_Tick(void)
{
	static uint8_t Count = 0;
	static uint8_t state = 1;

	if (HAL_GPIO_ReadPin(key_GPIO_Port, key_Pin) == GPIO_PIN_RESET)
	{
		if (Count < 40)
			Count++;

		if (Count == 20 && state == 1)
		{
			state = 0;
			key.RunFlag = !key.RunFlag;
		}
	}
	else
	{
		state = 1;
		Count = 0;
	}
}
