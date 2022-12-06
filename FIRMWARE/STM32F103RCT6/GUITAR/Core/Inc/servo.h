
#ifndef SERVO_H_
#define SERVO_H_

#define SERVO_MARK_0    30
#define SERVO_MARK_1    50

#define W1_S1   (SERVO_MARK_0+7)
#define W1_S2   (SERVO_MARK_1+4)
#define W2_S1   (SERVO_MARK_0+6)
#define W2_S2   (SERVO_MARK_1+9)
#define W3_S1   (SERVO_MARK_0+6)
#define W3_S2   (SERVO_MARK_1+4)
#define W4_S1   (SERVO_MARK_0+6)
#define W4_S2   (SERVO_MARK_1+2)
#define W5_S1   (SERVO_MARK_0)
#define W5_S2   (SERVO_MARK_1-7)
#define W6_S1   (SERVO_MARK_0+4)
#define W6_S2   (SERVO_MARK_1+4)

// Khai bao goc cho cac day gay khoang 1
#define K1_W1_RELEASE       (95)
#define K1_W1_PRESS         (75)

#define K1_W2_RELEASE       (95)
#define K1_W2_PRESS         (65)

#define K1_W3_RELEASE       (95)
#define K1_W3_PRESS         (57)

#define K1_W4_RELEASE       (75)
#define K1_W4_PRESS         (110)

#define K1_W5_RELEASE       (75)
#define K1_W5_PRESS         (110)

#define K1_W6_RELEASE       (75)
#define K1_W6_PRESS         (105)

// Khai bao goc cho cac day gay khoang 2
#define K2_W1_RELEASE       (95)
#define K2_W1_PRESS         (75)

#define K2_W2_RELEASE       (85)
#define K2_W2_PRESS         (65)

#define K2_W3_RELEASE       (90)
#define K2_W3_PRESS         (67)

#define K2_W4_RELEASE       (90)   
#define K2_W4_PRESS         (107)


#define K2_W5_RELEASE       (90)
#define K2_W5_PRESS         (110)

#define K2_W6_RELEASE       (85)
#define K2_W6_PRESS         (110)

typedef struct {
    TIM_HandleTypeDef* htim;
    uint32_t channel;
} servo_t;


void Servo_Init(servo_t *servo, TIM_HandleTypeDef *_htim, uint32_t _channel);
void Set_servo_xp(servo_t *servo, uint8_t x);
#endif /* SERVO_H_ */
