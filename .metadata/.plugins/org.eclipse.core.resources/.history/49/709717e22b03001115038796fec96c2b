/*
 * button.h
 *
 *  Created on: 2026. 1. 23.
 *      Author: junwoo
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "stm32f4xx_hal.h"
#include "stdbool.h"

typedef struct
{
	GPIO_TypeDef *port;
	uint16_t 	number;
	GPIO_PinState onState;
}BUTTON_CONTROL;

bool buttonGetPressed(uint8_t num);


#endif /* INC_BUTTON_H_ */
