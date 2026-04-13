#ifndef _PID_H
#define _PID_H

struct Struct_pid
{
    float Target;
    float Actual;
    float Actual1; // 微分先行 微分项替换为对实际值的微分
    float Out;

    float Kp;
    float Ki;
    float Kd;

    float Error0;
    float Error1;
    float ErrorInt;

    float ErrorIntMax;
    float ErrorIntMin;

    float OutMax;
    float OutMin;

    float OutOffset;
};

extern struct Struct_pid AnglePID;
extern struct Struct_pid SpeedPID;
extern struct Struct_pid TurnPID;

void PID_Init(struct Struct_pid *pid);
void PID_Update(struct Struct_pid *pid);

#endif
