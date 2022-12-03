
#ifndef SERVO_H_
#define SERVO_H_


#define FRET_3RD        (3)
#define FRET_4TH        (4)

#define WIRE_1ST        (1)
#define WIRE_2ND        (2)
#define WIRE_3RD        (3)
#define WIRE_4TH        (4)
#define WIRE_5TH        (5)
#define WIRE_6TH        (6)


// Khai bao goc cho cac day gay khoang 3
#define K3_W1_RELEASE       (50)
#define K3_W1_PRESS         (72)

#define K3_W2_RELEASE       (50)
#define K3_W2_PRESS         (73)

#define K3_W3_RELEASE       (70)
#define K3_W3_PRESS         (97)

#define K3_W4_RELEASE       (80)
#define K3_W4_PRESS         (60)

#define K3_W5_RELEASE       (80)
#define K3_W5_PRESS         (53)

#define K3_W6_RELEASE       (80)
#define K3_W6_PRESS         (53)

// Khai bao goc cho cac day gay khoang 4
#define K4_W1_RELEASE       (85)
#define K4_W1_PRESS         (85)

#define K4_W2_RELEASE       (85)
#define K4_W2_PRESS         (85)

#define K4_W3_RELEASE       (85)
#define K4_W3_PRESS         (85)

#define K4_W4_RELEASE       (85)
#define K4_W4_PRESS         (85)

#define K4_W5_RELEASE       (85)
#define K4_W5_PRESS         (85)

#define K4_W6_RELEASE       (85)
#define K4_W6_PRESS         (85)


typedef struct {
    TIM_HandleTypeDef* htim;
    uint32_t channel;
} servo_t;


void Servo_Init(servo_t *servo, TIM_HandleTypeDef *_htim, uint32_t _channel);
void Set_servo_xp(servo_t *servo, uint8_t x);

#endif /* SERVO_H_ */
