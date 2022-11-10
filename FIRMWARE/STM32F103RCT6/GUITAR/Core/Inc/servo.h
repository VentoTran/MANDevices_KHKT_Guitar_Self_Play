
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
#endif

typedef struct {
    TIM_HandleTypeDef* htim;
    uint32_t channel;
} servo_t;

void Set_servo_5p(servo_t *servo);
void Servo_Init(servo_t *servo, TIM_HandleTypeDef *_htim, uint32_t _channel);
void Set_servo_9p(servo_t *servo);

#endif /* SERVO_H_ */
