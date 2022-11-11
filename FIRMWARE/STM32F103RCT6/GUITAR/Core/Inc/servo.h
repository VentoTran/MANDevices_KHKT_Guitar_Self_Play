<<<<<<< HEAD
/*
 * servo.h
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

#ifndef SERVO_H_
#define SERVO_H_

//
//	Servo
//
#define TURNIGY_TG9E

//
//	Defines
//

// For Turnigy TG9e
#ifdef	TURNIGY_TG9E
<<<<<<< HEAD
#define SERVO_MIN 550
#define SERVO_MAX 2430
#define ANGLE_MIN 0
#define ANGLE_MAX 180
=======
>>>>>>> 7838645ba1edd9e342754fca7a753f44d7a3da7a
#endif

typedef struct {
    TIM_HandleTypeDef* htim;
    uint32_t channel;
} servo_t;

<<<<<<< HEAD
void Servo_Init(servo_t *servo, TIM_HandleTypeDef *_htim, uint32_t _channel);
void Servo_SetAngle(servo_t *servo, uint16_t angle);
void Servo_SetAngleFine(servo_t *servo, float angle);
=======
void Set_servo_5p(servo_t *servo);
void Servo_Init(servo_t *servo, TIM_HandleTypeDef *_htim, uint32_t _channel);
void Set_servo_9p(servo_t *servo);
>>>>>>> 7838645ba1edd9e342754fca7a753f44d7a3da7a

#endif /* SERVO_H_ */
