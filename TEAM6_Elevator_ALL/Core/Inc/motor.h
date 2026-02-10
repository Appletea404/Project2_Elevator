/* motor.h */
#ifndef MOTOR_H
#define MOTOR_H

#include "main.h"
#include "tim.h"

// === 문 각도 설정 ===
// 왼쪽 문: 0도(열림) <-> 90도(닫힘)
#define LEFT_DOOR_OPEN   20  // 0.5ms
#define LEFT_DOOR_CLOSE  130  // 1.5ms

// 오른쪽 문: 180도(열림) <-> 90도(닫힘)
// (서로 반대 방향으로 움직여야 문이 열리는 효과가 남)
#define RIGHT_DOOR_OPEN  130  // 2.5ms
#define RIGHT_DOOR_CLOSE 20  // 1.5ms

// 함수 이름표
//void Elevator_Init(TIM_HandleTypeDef *htim); // 초기화
void Elevator_Open(void);  // 문 열기
void Elevator_Close(void); // 문 닫기

#endif
