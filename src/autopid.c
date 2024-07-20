// Based on PID automated tuning (Ziegler-Nichols/relay method) for Arduino and compatible boards
// Copyright (c) 2016-2020 jackw01
// This code is distrubuted under the MIT License, see LICENSE for details
// See README for more details - https://github.com/jackw01/arduino-pid-autotuner/blob/master/README.md

#include "dryer.h"
autopid_t autopid;

void autopid_init(int min_output, int max_output, float target, uint8_t zn_mode)
{
    memset(&autopid, 0, sizeof(autopid_t));
    autopid.zn_mode = zn_mode;
    autopid.loop_interval = DEFAULT_LOOP_INTERVAL;
    autopid.min_output = min_output;
    autopid.max_output = max_output;
    autopid.cycles = DEFAULT_TUNING_CYCLES;
    autopid.target_input_value = target;

    autopid.i = 0;
    autopid.output = true;
    autopid.output_value = autopid.max_output;
    autopid.t1 = autopid.t2 = PWM_FULL_CYCLE;
    autopid.microseconds = autopid.t_high = autopid.t_low = 0;
    autopid.max = -1000000000000;
    autopid.min = 1000000000000;
    autopid.p_average = autopid.i_average = autopid.d_average = 0;
}

float autopid_tune_pid(float input, uint32_t ms)
{
    autopid.microseconds = ms;
    autopid.max = (autopid.max > input) ? autopid.max : input;
    autopid.min = (autopid.min < input) ? autopid.min : input;

    if (autopid.output && input > autopid.target_input_value)
    {
        autopid.output = false;
        autopid.output_value = autopid.min_output;
        autopid.t1 = ms;
        autopid.t_high = autopid.t1 - autopid.t2;
        autopid.max = autopid.target_input_value;
    }

    if (!autopid.output && input < autopid.target_input_value)
    {
        autopid.output = true;
        autopid.output_value = autopid.max_output;
        autopid.t2 = ms;
        autopid.t_low = autopid.t2 - autopid.t1;

        float ku = (4.0 * ((autopid.max_output - autopid.min_output) / 2.0)) / (M_PI * (autopid.max - autopid.min) / 2.0);

        float tu = autopid.t_low + autopid.t_high;

        float kp_constant, ti_constant, td_constant;
        switch (autopid.zn_mode)
        {
        case ZN_MODE_BASIC_PID:
            kp_constant = 0.6;
            ti_constant = 0.5;
            td_constant = 0.125;
            break;
        case ZN_MODE_LESS_OVERSHOOT:
            kp_constant = 0.33;
            ti_constant = 0.5;
            td_constant = 0.33;
            break;
        default: // Default to No Overshoot mode as it is the safest
            kp_constant = 0.2;
            ti_constant = 0.5;
            td_constant = 0.33;
        }

        autopid.kp = kp_constant * ku;
        autopid.ki = (autopid.kp / (ti_constant * tu)) * autopid.loop_interval;
        autopid.kd = (td_constant * autopid.kp * tu) / autopid.loop_interval;

        if (autopid.i > 1)
        {
            autopid.p_average += autopid.kp;
            autopid.i_average += autopid.ki;
            autopid.d_average += autopid.kd;
        }
        autopid.min = autopid.target_input_value;
        autopid.i++;
    }

    if (autopid.i >= autopid.cycles)
    {
        autopid.output = false;
        autopid.output_value = autopid.min_output;
        autopid.kp = autopid.p_average / (autopid.i - 1);
        autopid.ki = autopid.i_average / (autopid.i - 1);
        autopid.kd = autopid.d_average / (autopid.i - 1);
    }

    return autopid.output_value;
}

bool autopid_finished()
{
    return autopid.i > autopid.cycles;
}

float autopid_run(float input, uint32_t ms)
{
    if (!autopid_finished())
        return 0;

    // DL("t=%i\n", (int)(input * 1000));

    uint32_t time_change = (ms - autopid.microseconds) / 1000;
    float error = autopid.target_input_value - input;

    autopid.err_sum += (error * time_change);
    float d_err = (error - autopid.last_err) / time_change;

    autopid.last_err = error;
    autopid.microseconds = ms;

    float output = autopid.kp * error + autopid.ki * autopid.err_sum + autopid.kd * d_err;
    // output = output * (autopid.max_output - autopid.min_output) / 100 + autopid.min_output;
    if (output < 0)
    {
        return autopid.min_output;
    }
    if (output > autopid.max_output)
    {
        return autopid.max_output;
    }
    return output;
}