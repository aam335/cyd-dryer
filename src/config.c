#include "dryer.h"
#include "Arduino.h"

extern autopid_t autopid;
config_t config = {0};

void pid2config(autopid_t *a)
{
    if (!autopid_finished())
        return;
    config.ku = a->ku;
    config.tu = a->tu;

    config.ki = a->ki;
    config.kp = a->kp;
    config.kd = a->kd;

    config.i = a->i;
    config.zn_mode = a->zn_mode;
}

void config2pid()
{
    autopid.ku = config.ku;
    autopid.tu = config.tu;

    autopid.ki = config.ki;
    autopid.kp = config.kp;
    autopid.kd = config.kd;

    autopid.i = config.i;
    autopid.zn_mode = config.zn_mode;
}

void load_config()
{
    load_data(&config, sizeof(config), PREFERENCES_CONFIG_NAME);
    log_i("load_config %i %i", config.is_initialized, config.tmin);
    if (!config.is_initialized)
    {
        memset(&config, 0, sizeof(config_t));
        config.is_initialized = true;
        config.tmax = MAX_TEMP;
        config.tmin = MIN_TEMP;
        config.tstart = START_TEMP;
        config.fan_start = START_FAN_PWM;
        config.zn_mode = ZN_MODE_BASIC_PID;

        config.tu = 0;
        config.ku = 0;

        config.r25 = NTC_R25;
        config.r_div = NTC_RDIV;
        config.beta = NTC_BETA;

        save_data(&config, sizeof(config), PREFERENCES_CONFIG_NAME);
    }
    config2pid();
    return;
}

void save_config()
{
    save_data(&config, sizeof(config), PREFERENCES_CONFIG_NAME);
}

config_t *get_config()
{
    if (!config.is_initialized)
    {
        load_config();
    }
    return &config;
}

void save_pid(autopid_t *a)
{
    pid2config(a);
    save_config();
}