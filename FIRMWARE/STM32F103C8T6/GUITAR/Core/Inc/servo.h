
#ifndef SERVO_H_
#define SERVO_H_

// Khai bao goc cho cac day gay khoang 3
#define K3_W1_RELEASE       ()
#define K3_W1_PRESS         ()

#define K3_W2_RELEASE       ()
#define K3_W2_PRESS         ()

#define K3_W3_RELEASE       ()
#define K3_W3_PRESS         ()

#define K3_W4_RELEASE       ()
#define K3_W4_PRESS         ()

#define K3_W5_RELEASE       ()
#define K3_W5_PRESS         ()

#define K3_W6_RELEASE       ()
#define K3_W6_PRESS         ()

// Khai bao goc cho cac day gay khoang 4
#define K4_W1_RELEASE       ()
#define K4_W1_PRESS         ()

#define K4_W2_RELEASE       ()
#define K4_W2_PRESS         ()

#define K4_W3_RELEASE       ()
#define K4_W3_PRESS         ()

#define K4_W4_RELEASE       ()
#define K4_W4_PRESS         ()

#define K4_W5_RELEASE       ()
#define K4_W5_PRESS         ()

#define K4_W6_RELEASE       ()
#define K4_W6_PRESS         ()


typedef struct {
    TIM_HandleTypeDef* htim;
    uint32_t channel;
} servo_t;


void Servo_Init(servo_t *servo, TIM_HandleTypeDef *_htim, uint32_t _channel);
void Set_servo_xp(servo_t *servo, uint8_t x);

#endif /* SERVO_H_ */
