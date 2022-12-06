
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
#define K3_W1_RELEASE       (65)
#define K3_W1_PRESS         (85)

#define K3_W2_RELEASE       (95)    // dang hong
#define K3_W2_PRESS         (135)

#define K3_W3_RELEASE       (130)   
#define K3_W3_PRESS         (153)

#define K3_W4_RELEASE       (70)
#define K3_W4_PRESS         (30)

#define K3_W5_RELEASE       (73)
#define K3_W5_PRESS         (53)    

#define K3_W6_RELEASE       (67)
#define K3_W6_PRESS         (45)

// Khai bao goc cho cac day gay khoang 4
#define K4_W1_RELEASE       (87)
#define K4_W1_PRESS         (115)

#define K4_W2_RELEASE       (77)
#define K4_W2_PRESS         (115)    // dang hong

#define K4_W3_RELEASE       (77)
#define K4_W3_PRESS         (102)  

#define K4_W4_RELEASE       (85)
#define K4_W4_PRESS         (62)

#define K4_W5_RELEASE       (85)
#define K4_W5_PRESS         (60)

#define K4_W6_RELEASE       (50)
#define K4_W6_PRESS         (30)


typedef struct {
    TIM_HandleTypeDef* htim;
    uint32_t channel;
} servo_t;


void Servo_Init(servo_t *servo, TIM_HandleTypeDef *_htim, uint32_t _channel);
void Set_servo_xp(servo_t *servo, uint8_t x);

#endif /* SERVO_H_ */
