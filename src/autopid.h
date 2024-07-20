#pragma once
#include "dryer.h"

typedef struct
{
    float target_input_value;
    float loop_interval;
    float min_output, max_output;
    uint8_t zn_mode;
    int cycles;

    int i;
    bool output;
    float output_value;
    long microseconds, t1, t2, t_high, t_low;
    float max, min;
    float p_average, i_average, d_average;

    float kp, ki, kd;

    float err_sum, last_err;
    
} autopid_t;

enum
{
    ZN_MODE_BASIC_PID,
    ZN_MODE_LESS_OVERSHOOT,
    ZN_MODE_NO_OVERSHOOT,
};

#define M_PI 3.14159265358979323846

#define DEFAULT_LOOP_INTERVAL ESM_POLL_INTERVAL
#define DEFAULT_TUNING_CYCLES 3

extern autopid_t autopid;
#ifdef __cplusplus
extern "C"
{
#endif
void autopid_init(int min_output, int max_output, float target, uint8_t zn_mode);
float autopid_tune_pid(float input, uint32_t us);
bool autopid_finished();
float autopid_run(float input, uint32_t ms);
#ifdef __cplusplus
} /*extern "C"*/
#endif