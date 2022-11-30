
#ifndef SERVO_H_
#define SERVO_H_

#define W1_S1   (125)
#define W1_S2   (140)
#define W2_S1   (115)
#define W2_S2   (135)
#define W3_S1   (115)
#define W3_S2   (130)
#define W4_S1   (120)
#define W4_S2   (140)
#define W5_S1   (105)
#define W5_S2   (122)
#define W6_S1   (135)
#define W6_S2   (158)

typedef struct {
    TIM_HandleTypeDef* htim;
    uint32_t channel;
} servo_t;


void Servo_Init(servo_t *servo, TIM_HandleTypeDef *_htim, uint32_t _channel);

void Set_servo_xp(servo_t *servo, uint8_t x);

// void Set_servo(uint32_t t);

#endif /* SERVO_H_ */
