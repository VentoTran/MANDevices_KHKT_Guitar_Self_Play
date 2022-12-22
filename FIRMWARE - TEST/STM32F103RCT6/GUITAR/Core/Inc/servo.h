
#ifndef SERVO_H_
#define SERVO_H_


#define SERVO_MARK_0    30
#define SERVO_MARK_1    50

#define SERVO_RELEASE   0
#define SERVO_PRESS     1

#define FRET_3RD        (3)
#define FRET_4TH        (4)

#define WIRE_1ST        (1)
#define WIRE_2ND        (2)
#define WIRE_3RD        (3)
#define WIRE_4TH        (4)
#define WIRE_5TH        (5)
#define WIRE_6TH        (6)

#define W1_S1   (SERVO_MARK_0+7)
#define W1_S2   (SERVO_MARK_1+4)
#define W2_S1   (SERVO_MARK_0+7)
#define W2_S2   (SERVO_MARK_1+3)
#define W3_S1   (SERVO_MARK_0+2)
#define W3_S2   (SERVO_MARK_1-1)
#define W4_S1   (SERVO_MARK_0+4)
#define W4_S2   (SERVO_MARK_1-2)
#define W5_S1   (SERVO_MARK_0+0)
#define W5_S2   (SERVO_MARK_1-7)
#define W6_S1   (SERVO_MARK_0+4)
#define W6_S2   (SERVO_MARK_1+4)



#define K1_W1_RELEASE       (85)
#define K1_W1_PRESS         (85)
#define K1_W2_RELEASE       (85)
#define K1_W2_PRESS         (85)
#define K1_W3_RELEASE       (85)
#define K1_W3_PRESS         (85)
#define K1_W4_RELEASE       (85)
#define K1_W4_PRESS         (85)
#define K1_W5_RELEASE       (85)
#define K1_W5_PRESS         (85)
#define K1_W6_RELEASE       (85)
#define K1_W6_PRESS         (85)

#define K2_W1_RELEASE       (85)
#define K2_W1_PRESS         (85)
#define K2_W2_RELEASE       (85)
#define K2_W2_PRESS         (85)
#define K2_W3_RELEASE       (85)
#define K2_W3_PRESS         (85)
#define K2_W4_RELEASE       (85)
#define K2_W4_PRESS         (85)
#define K2_W5_RELEASE       (85)
#define K2_W5_PRESS         (85)
#define K2_W6_RELEASE       (85)
#define K2_W6_PRESS         (85)


typedef struct {
    TIM_HandleTypeDef* htim;
    uint32_t channel;
} servo_t;


void Servo_Init(servo_t *servo, TIM_HandleTypeDef *_htim, uint32_t _channel);

void Set_servo_xp(servo_t *servo, uint8_t x);

// void Set_servo(uint32_t t);

#endif /* SERVO_H_ */
