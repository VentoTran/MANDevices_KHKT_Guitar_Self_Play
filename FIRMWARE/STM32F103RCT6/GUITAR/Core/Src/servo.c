<<<<<<< HEAD
/*
 * servo.c
 *
 *		
 *  Created on: 07/11/2022
 *		Author: BUI TRUONG
 *		https://dzuytrwong692oo2.github.io/?fbclid=IwAR1tQka1WgbBDyqUL7SSbqSHuvBkutKe5nRBK-IS4bqUYpJZz-QERoZ48fI
 *		Truong.bvd202543@sis.hust.edu.vn
 *
 */
=======
>>>>>>> 7838645ba1edd9e342754fca7a753f44d7a3da7a
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

<<<<<<< HEAD
//
//	map help function
//
long map(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

//
//	Servo set angle function
//
void Servo_SetAngle(servo_t *servo, uint16_t angle)
{
	if(angle < 0) angle = 0;
	if(angle > 180) angle = 180;

	  uint16_t tmp = map(angle, ANGLE_MIN, ANGLE_MAX, SERVO_MIN, SERVO_MAX);
	  __HAL_TIM_SET_COMPARE(servo->htim, servo->channel, tmp);
}

//
//	Servo set angle fine function
//
void Servo_SetAngleFine(servo_t *servo, float angle)
{
	if(angle < 0) angle = 0;
	if(angle > 180) angle = 180;

	  uint16_t tmp = map(angle, ANGLE_MIN, ANGLE_MAX, SERVO_MIN, SERVO_MAX);
	  __HAL_TIM_SET_COMPARE(servo->htim, servo->channel, tmp);
}

=======
void Set_servo_5p(servo_t *servo)
{
    __HAL_TIM_SET_COMPARE(servo->htim, servo->channel, 5);
}

void Set_servo_9p(servo_t *servo)
{
    __HAL_TIM_SET_COMPARE(servo->htim, servo->channel, 9);
}
>>>>>>> 7838645ba1edd9e342754fca7a753f44d7a3da7a
