/*
 * button.c
 *
 *  Created on: 2026. 1. 23.
 *      Author: junwoo
 */


#include "button.h"


BUTTON_CONTROL button[3]=
{

		{GPIOC, GPIO_PIN_9,0},
		{GPIOB, GPIO_PIN_8,0},
		{GPIOB, GPIO_PIN_9,0},

};



bool buttonGetPressed(uint8_t num)
{
	static uint32_t prevTime = 0;
	bool ret = false;

	if(HAL_GPIO_ReadPin(button[num].port,button[num].number) == button[num].onState)
	{
		uint32_t currTime = HAL_GetTick();
		if(currTime - prevTime >200)
		{
			if(HAL_GPIO_ReadPin(button[num].port,button[num].number) == button[num].onState)
					{
						ret = true;
					}
			prevTime = currTime;
		}
	}
	return ret;
}
