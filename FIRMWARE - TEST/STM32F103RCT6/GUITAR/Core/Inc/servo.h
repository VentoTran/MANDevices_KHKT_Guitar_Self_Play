
#ifndef SERVO_H_
#define SERVO_H_


#define SERVO_MARK_0    30
#define SERVO_MARK_1    50

#define W1_S1   (SERVO_MARK_0)
#define W1_S2   (SERVO_MARK_1-3)
#define W2_S1   (SERVO_MARK_0+2)
#define W2_S2   (SERVO_MARK_1-3)
#define W3_S1   (SERVO_MARK_0)
#define W3_S2   (SERVO_MARK_1)
#define W4_S1   (SERVO_MARK_0-2)
#define W4_S2   (SERVO_MARK_1-2)
#define W5_S1   (SERVO_MARK_0)
#define W5_S2   (SERVO_MARK_1-5)
#define W6_S1   (SERVO_MARK_0)
#define W6_S2   (SERVO_MARK_1-2)



#define K3_W1_RELEASE       (50)
#define K3_W1_PRESS         (70)
#define K3_W2_RELEASE       (50)
#define K3_W2_PRESS         (70)
#define K3_W3_RELEASE       (70)
#define K3_W3_PRESS         (95)
#define K3_W4_RELEASE       (80)
#define K3_W4_PRESS         (58)
#define K3_W5_RELEASE       (80)
#define K3_W5_PRESS         (53)
#define K3_W6_RELEASE       (80)
#define K3_W6_PRESS         (53)







typedef struct {
    TIM_HandleTypeDef* htim;
    uint32_t channel;
} servo_t;


void Servo_Init(servo_t *servo, TIM_HandleTypeDef *_htim, uint32_t _channel);

void Set_servo_xp(servo_t *servo, uint8_t x);

// void Set_servo(uint32_t t);

#endif /* SERVO_H_ */
