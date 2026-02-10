/*
 * button.h
 *
 * Created on: 2026. 1. 23.
 * Author: user24
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "stm32f4xx_hal.h"
#include <stdbool.h>

typedef struct
{
	GPIO_TypeDef *port;
	uint16_t		number;
	GPIO_PinState	onState;
} BUTTON_CONTROL;

/* * 인터럽트 핀(GPIO_Pin)을 입력받아 몇 층(1, 2, 3)인지 반환하는 함수
 * 반환값: 1~3 (유효한 버튼), -1 (유효하지 않거나 채터링)
 */
int8_t Button_ISR_Handler(uint16_t GPIO_Pin);

#endif /* INC_BUTTON_H_ */
