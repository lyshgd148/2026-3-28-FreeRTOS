#include "PID.h"

struct Struct_pid AnglePID = {.Kp = 3,
                              .Ki = 0.1,
                              .Kd = 3,
                              .ErrorIntMax = 1000,
                              .ErrorIntMin = -1000,
                              .OutMax = 100,
                              .OutMin = -100};
struct Struct_pid SpeedPID = {
    .Kp = 8,
    .Ki = 0.2,
    .Kd = 4,
    .ErrorIntMax = 1000,
    .ErrorIntMin = -1000,
    .OutMax = 20,
    .OutMin = -20};
struct Struct_pid TurnPID;

void PID_Init(struct Struct_pid *pid)
{
    pid->Target = 0;
    pid->Actual = 0;
    pid->Actual1 = 0;

    pid->Out = 0;

    pid->Error0 = 0;
    pid->Error1 = 0;
    pid->ErrorInt = 0;
}

void PID_Update(struct Struct_pid *pid)
{
    pid->Error1 = pid->Error0;
    pid->Error0 = pid->Target - pid->Actual;

    if (pid->Ki != 0)
    {
        pid->ErrorInt += pid->Error0;
        if (pid->ErrorInt > pid->ErrorIntMax) // 积分限幅
            pid->ErrorInt = pid->ErrorIntMax;
        else if (pid->ErrorInt < pid->ErrorIntMin)
            pid->ErrorInt = pid->ErrorIntMin;
    }
    else
    {
        pid->ErrorInt = 0;
    }

    pid->Out = pid->Kp * pid->Error0 + pid->Ki * pid->ErrorInt - pid->Kd * (pid->Actual - pid->Actual1); // 微分先行 实际值代替误差

    if (pid->Out > pid->OutMax) // 输出限幅度
        pid->Out = pid->OutMax;
    else if (pid->Out < pid->OutMin)
        pid->Out = pid->OutMin;

    pid->Actual1 = pid->Actual;
}
