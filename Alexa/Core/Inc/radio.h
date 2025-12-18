#ifndef RADIO_H_
#define RADIO_H_

#include "common.h"

#define NUM_OF_LIGHTS 10

PORT RADIO_TRANSMIT_PORT = {GPIOF, GPIO_PIN_13};

uint8_t SIGNAL_REPEAT = 10;

void TransmitSignal(uint8_t numberHighPulses, uint8_t numberLowPulses)
{
	HAL_GPIO_WritePin(RADIO_TRANSMIT_PORT.gpio, RADIO_TRANSMIT_PORT.port_number, GPIO_PIN_RESET);
	delay350Microseconds(numberHighPulses);
	HAL_GPIO_WritePin(RADIO_TRANSMIT_PORT.gpio, RADIO_TRANSMIT_PORT.port_number, GPIO_PIN_SET);
	delay350Microseconds(numberLowPulses);}

void sendSequence(uint16_t bitSequence)
{
	bitSequence = bitSequence << 4;
	auto saveOriginal = bitSequence;
	for(uint8_t tryToSend = 0; tryToSend < SIGNAL_REPEAT; tryToSend ++)
	{
		bitSequence = saveOriginal;
		for(uint8_t bit = 0; bit < 12; bit++)
		{
			TransmitSignal(1, 3);
			uint16_t testFirstBit = bitSequence & 0x8000;
			if (testFirstBit == 0x8000)
			{
				TransmitSignal(1, 3);
			}
			else
			{
				TransmitSignal(3, 1);
			}
			bitSequence = bitSequence << 1;
		}
		TransmitSignal(1,31);
	}
}

#endif RADIO_H_
