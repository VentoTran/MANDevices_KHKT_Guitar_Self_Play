
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

// Khai bao goc cho cac day gay khoang 1
#define K1_W1_RELEASE       ()
#define K1_W1_PRESS         ()

#define K1_W2_RELEASE       ()
#define K1_W2_PRESS         ()

#define K1_W3_RELEASE       ()
#define K1_W3_PRESS         ()

#define K1_W4_RELEASE       ()
#define K1_W4_PRESS         ()

#define K1_W5_RELEASE       ()
#define K1_W5_PRESS         ()

#define K1_W6_RELEASE       ()
#define K1_W6_PRESS         ()

// Khai bao goc cho cac day gay khoang 2
#define K2_W1_RELEASE       ()
#define K2_W1_PRESS         ()

#define K2_W2_RELEASE       ()
#define K2_W2_PRESS         ()

#define K2_W3_RELEASE       ()
#define K2_W3_PRESS         ()

#define K2_W4_RELEASE       ()
#define K2_W4_PRESS         ()

#define K2_W5_RELEASE       ()
#define K2_W5_PRESS         ()

#define K2_W6_RELEASE       ()
#define K2_W6_PRESS         ()

typedef struct {
    TIM_HandleTypeDef* htim;
    uint32_t channel;
} servo_t;


void Servo_Init(servo_t *servo, TIM_HandleTypeDef *_htim, uint32_t _channel);
void Set_servo_xp(servo_t *servo, uint8_t x);
#endif /* SERVO_H_ */
