#ifndef COMMON_H_
#define COMMON_H_

extern TIM_HandleTypeDef* GLOBAL_TIMER;

typedef struct {
	GPIO_TypeDef* gpio;
	uint16_t port_number;
} PORT;

void delay350Microseconds(uint8_t amount)
{
    uint32_t delay_us = amount * 35;

    __HAL_TIM_SET_COUNTER(GLOBAL_TIMER, 0);
    HAL_TIM_Base_Start(GLOBAL_TIMER);

    while(__HAL_TIM_GET_COUNTER(GLOBAL_TIMER) < delay_us);

    HAL_TIM_Base_Stop(GLOBAL_TIMER);
}

#endif COMMON_H_
