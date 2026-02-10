/* motor.c */
#include "motor.h"

// static 변수 삭제됨 (저장소 없음)

// 1. 엘리베이터 초기화
// 이제는 저장을 안 하니까, 그냥 PWM 켜고 닫기만 시킴
//void Elevator_Init(TIM_HandleTypeDef *htim)
//{
//    // PWM 신호 발생 시작 (들어온 htim을 바로 사용)
//    HAL_TIM_PWM_Start(htim, TIM_CHANNEL_1);
//    HAL_TIM_PWM_Start(htim, TIM_CHANNEL_2);
//
//    // 초기화 할 때 문을 닫아야 하니, 여기서도 htim을 넘겨줘야 함!
//    Elevator_Close();
//}

// 2. 문 열기 (레지스터 직접 제어)
void Elevator_Open(void)
{
    // Instance는 TIM3 같은 타이머 기지의 주소를 가리킵니다.

    TIM3 -> CCR1 = LEFT_DOOR_OPEN;
    TIM3 -> CCR2 = RIGHT_DOOR_OPEN;

}

// 3. 문 닫기 (레지스터 직접 제어)
void Elevator_Close(void)
{

    TIM3 -> CCR1 = LEFT_DOOR_CLOSE;
    TIM3 -> CCR2 = RIGHT_DOOR_CLOSE;


}
