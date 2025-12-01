#ifndef LED_H_
#define LED_H_

typedef struct {
	GPIO_TypeDef* gpio;
	uint16_t port_number;
} PORT;

#define NUM_OF_LIGHTS 10

PORT ports[NUM_OF_LIGHTS] = {
		{GPIOC, GPIO_PIN_6},
		{GPIOB, GPIO_PIN_15},
		{GPIOA, GPIO_PIN_3},
		{GPIOB, GPIO_PIN_12},
		{GPIOA, GPIO_PIN_15},
		{GPIOC, GPIO_PIN_7},
		{GPIOB, GPIO_PIN_5},
		{GPIOB, GPIO_PIN_3},
		{GPIOA, GPIO_PIN_4},
		{GPIOB, GPIO_PIN_4}
};

void LightLEDs(uint8_t toLight)
{
	for(uint8_t i = 0 ; i < NUM_OF_LIGHTS; i++)
	{
		HAL_GPIO_WritePin(ports[i].gpio, ports[i].port_number, GPIO_PIN_RESET);
	}

	for(uint8_t i = 0; i < toLight; i++)
	{
		HAL_GPIO_WritePin(ports[i].gpio, ports[i].port_number, GPIO_PIN_SET);
	}
}

#endif LED_H_
