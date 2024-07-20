#include "dryer.h"

#ifdef crStaticVar
#undef crStaticVar
#endif
#define crStaticVar crStaticVar_sushka
uint16_t crStaticVar = 0;

char *crState = NULL;

bool start_me = false;

void set_cooler_pwm();

uint32_t poll_esm()
{
    unsigned long system_millis = millis();
    set_cooler_pwm(); // защита нагревателя
    // state standby
    if (!start_me)
    {
        stop_esm();
        return ESM_POLL_INTERVAL;
    }
    float back_temperature = current_temperature;
    float pwm = 0;

    crBegin;
    set_pwm(PWM_HEATER, PWM_FULL_CYCLE);
    crReturn(ESM_POLL_INTERVAL);
    if (back_temperature < target_temperature)
    {
        return ESM_POLL_INTERVAL;
    }
    crReturn(ESM_POLL_INTERVAL);
    autopid_init(0, PWM_FULL_CYCLE, target_temperature, ZN_MODE_BASIC_PID);
    crReturn(ESM_POLL_INTERVAL);
    // state pid_calibrate
    pwm = autopid_tune_pid(back_temperature, system_millis);
    set_pwm(PWM_HEATER, (int)pwm);

    // set_pwm(PWM_MOTOR, 0); // mode there
    log_i("kp=%f ki=%f kp=%f", autopid.kp * 1000, autopid.ki * 1000, autopid.kd * 1000);

    seconds_left -= ESM_POLL_INTERVAL / 1000;
    if (!autopid_finished())
    {
        return ESM_POLL_INTERVAL;
    }
    log_i("autopid done!");
    crReturn(ESM_POLL_INTERVAL);
    pwm = autopid_run(back_temperature, system_millis);
    set_pwm(PWM_HEATER, (int)pwm);
    seconds_left -= ESM_POLL_INTERVAL / 1000;
    log_i("pwm=%f", (int)pwm);
    if (seconds_left > 0)
    {
        return ESM_POLL_INTERVAL;
    }
    crFinish;
    stop_esm();
    return ESM_POLL_INTERVAL;
}

void turn_on_off()
{
    if (start_me)
    {
        start_me = false;
        stop_esm();
        return;
    }
    start_me = true;
    start_esm();
}

void start_esm()
{
    crStaticVar = 0;
    start_me = true;
}

void stop_esm()
{
    crStaticVar = 0;
    start_me = false;
    set_pwm(PWM_HEATER, 0);
}

void esm_error(char *error)
{
    log_i("error:%s\n", error);
    stop_esm();
}

static uint32_t switch_off_delay_start = 0;

void set_cooler_pwm()
{
    int cooler_pwm = PWM_FULL_CYCLE * fan_pwm / 100;
    if (start_me == true)
    {
        switch_off_delay_start = system_millis;
    }
    else if (((switch_off_delay_start != 0 && system_millis -
                                                      switch_off_delay_start >
                                                  MOTOR_OFF_DELAY) ||
              switch_off_delay_start == 0))
    {
        switch_off_delay_start = 0;
        set_pwm(PWM_FAN, 0);
        return;
    }
    set_pwm(PWM_FAN, cooler_pwm);
}

uint16_t status_esm()
{
    return start_me;
}