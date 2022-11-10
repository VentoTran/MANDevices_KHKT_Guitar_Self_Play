#include "main.h"
#include "tim.h"

#include "servo.h"

//
//	Servo innitialization
//
void Servo_Init(servo_t *servo, TIM_HandleTypeDef *_htim, uint32_t _channel)
{
	servo->htim = _htim;
	servo->channel = _channel;

	HAL_TIM_PWM_Start(servo->htim, servo->channel);
}

void Set_servo_5p(servo_t *servo)
{
    __HAL_TIM_SET_COMPARE(servo->htim, servo->channel, 5);
}

void Set_servo_9p(servo_t *servo)
{
    __HAL_TIM_SET_COMPARE(servo->htim, servo->channel, 9);
}
