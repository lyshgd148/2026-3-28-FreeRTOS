#include "tim.h"
#include "encoder.h"

struct Struct_encoder encoder;

void read_encoder(struct Struct_encoder *encoder)
{
    encoder->dataR = -1*(short)TIM4->CNT;
    encoder->dataL = -1*(short)TIM3->CNT;
    TIM4->CNT = 0;
    TIM3->CNT = 0;
}
