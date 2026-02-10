/*
 * button.c
 *
 * Created on: 2026. 1. 23.
 * Author: user24
 */

#include "button.h"

BUTTON_CONTROL button[3]=
{
		{GPIOB, GPIO_PIN_9, 0}, // 1층 버튼
		{GPIOB, GPIO_PIN_8, 0}, // 2층 버튼
		{GPIOB, GPIO_PIN_5, 0}  // 3층 버튼
};

/*
 * 인터럽트 콜백에서 호출되는 함수
 * 기능: 채터링(Debouncing) 제거 후 눌린 버튼에 해당하는 층수 반환
 */
int8_t Button_ISR_Handler(uint16_t GPIO_Pin)
{
	static uint32_t prevTime = 0;
	uint32_t currTime = HAL_GetTick();
	int8_t detected_floor = -1;

	// 1. 디바운싱: 200ms 이내의 중복 입력 무시
	if (currTime - prevTime > 200)
	{
		// 2. 어떤 핀이 눌렸는지 확인
		if (GPIO_Pin == button[0].number) {
			detected_floor = 1;
		}
		else if (GPIO_Pin == button[1].number) {
			detected_floor = 2;
		}
		else if (GPIO_Pin == button[2].number) {
			detected_floor = 3;
		}

		// 유효한 버튼이면 시간 갱신
		if (detected_floor != -1) {
			prevTime = currTime;
		}
	}

	return detected_floor;
}
