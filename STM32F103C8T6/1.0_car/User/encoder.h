#ifndef _ENCODER_H
#define _ENCODER_H


struct Struct_encoder
{
    int dataR;    //右轮脉冲数
    int dataL;	  //左轮脉冲数
};

extern struct Struct_encoder encoder;

void read_encoder(struct Struct_encoder *encoder);

#endif
