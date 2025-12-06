#ifndef COMMON_H_
#define COMMON_H_

void delay350Microseconds(uint8_t amount)
{
	for (uint8_t i = 0; i < amount; i ++)
	{
		HAL_Delay(350);
	}
}

#endif LED_H_
