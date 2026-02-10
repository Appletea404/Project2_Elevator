/* button.c */
#include "button.h"

void Button_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* ★★★ 여기가 제일 중요합니다! ★★★ */
  /* A포트(GPIOA) 시계가 아니라 C포트(GPIOC) 시계를 켜야 합니다. */
  __HAL_RCC_GPIOC_CLK_ENABLE();

  /* PC1, PC2, PC3 설정 */
  GPIO_InitStruct.Pin = GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING; // 누를 때 감지
  GPIO_InitStruct.Pull = GPIO_PULLUP;          // 풀업 저항 (평소 1, 누르면 0)
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);      // (주의: GPIOC로 변경됨)

  /* 인터럽트 라인 열기 (PC1 -> EXTI1, PC2 -> EXTI2, PC3 -> EXTI3) */

  // 1번 라인 (PC1)
  HAL_NVIC_SetPriority(EXTI1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI1_IRQn);

  // 2번 라인 (PC2)
  HAL_NVIC_SetPriority(EXTI2_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI2_IRQn);

  // 3번 라인 (PC3)
  HAL_NVIC_SetPriority(EXTI3_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI3_IRQn);
}
