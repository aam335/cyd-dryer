#include "dryer.h"

int esm_status = 0;

#ifdef crStaticVar
#undef crStaticVar
#endif
#define crStaticVar crStaticVar_sushka
uint16_t crStaticVar = 0;

char *crState = NULL;

bool start_me = false;

void set_cooler_pwm();

typedef struct
{
    uint32_t preheating_start_ms;
    int32_t undertemp_ms;
    float preheating_prev_temp;
    uint32_t bangbang_cycle;
    int algo_fan_pwm;
    float back_temperature;
} esm_t;

esm_t esm = {.algo_fan_pwm = 0,
             .bangbang_cycle = 0,
             .preheating_prev_temp = 0,
             .preheating_start_ms = 0,
             .bangbang_cycle = 0,
             .undertemp_ms = MAX_UNDERTEMP_MS};

#define ESM_NEXT_STATE true
#define ESM_CONTINUE_STATE false

bool _esm_at_start()
{
    set_cooler_pwm(); // защита нагревателя
    if (!start_me)
    {
        esm_status = STATUS_STANDBY;
        stop_esm();
        return ESM_CONTINUE_STATE;
    }
    esm.back_temperature = current_temperature;
    if (esm.back_temperature == ERRORED_SENSOR)
    {
        esm_status = STATUS_SENSOR_ERROR;
        stop_esm();
        return ESM_CONTINUE_STATE;
    }
    return ESM_NEXT_STATE;
}

bool _esm_precooling()
{
    if (esm.back_temperature > target_temperature)
    {
        return ESM_CONTINUE_STATE;
    }
    return ESM_NEXT_STATE;
}
bool _esm_heater_check()
{
    if (esm.back_temperature < esm.preheating_prev_temp)
    {
        esm.preheating_prev_temp = esm.back_temperature;
    }
    if (esm.back_temperature - esm.preheating_prev_temp < CHECK_HEATER_MIN_DELTA)
    {
        if (system_millis - esm.preheating_start_ms > CHECK_HEATER_MS)
        {
            set_failure(FAIL_PREHEAT);
            stop_esm();
        }
        return ESM_CONTINUE_STATE;
    }
    return ESM_NEXT_STATE;
}
bool _esm_preheating_dumb()
{
    if (esm.back_temperature < target_temperature)
    {
        return ESM_CONTINUE_STATE;
    }
    return ESM_NEXT_STATE;
}

bool _esm_preheating()
{
    switch (esm.bangbang_cycle & 1)
    {
    case 0: // heating
        if (esm.back_temperature < (target_temperature))
        {
            return ESM_CONTINUE_STATE;
        }
        break;
    case 1: // cooling
        if (esm.back_temperature > (target_temperature - PREHEATING_TARGET_TEMP_MAX_DELTA))
        {
            return ESM_CONTINUE_STATE;
        }
        break;
    }

    if (esm.bangbang_cycle & 1) // if cooling done and time or iterations count done
    {
       return ESM_NEXT_STATE;
    }

    esm.bangbang_cycle++;
    set_pwm(PWM_HEATER, esm.bangbang_cycle & 1 ? 0 : PWM_FULL_CYCLE);

    return ESM_CONTINUE_STATE;
}
bool _esm_autopid()
{
    if (!autopid_finished())
    {
        // state pid_calibrate
        int pwm = autopid_tune_pid(esm.back_temperature, system_millis);
        set_pwm(PWM_HEATER, (int)pwm);

        log_i("kp=%f ki=%f kp=%f", autopid.kp * 1000, autopid.ki * 1000, autopid.kd * 1000);

        seconds_left -= ESM_POLL_INTERVAL / 1000;
        if (!autopid_finished())
        {
            return ESM_CONTINUE_STATE;
        }
        log_i("autopid done!");
        save_pid(&autopid);
    }
    return ESM_NEXT_STATE;
}

bool _esm_on_air()
{
    // on overheating we restarts esm
    if (target_temperature + MAX_OVERTEMP < esm.back_temperature)
    {
        crStaticVar = 0;
        return ESM_CONTINUE_STATE;
    }
    // stop esm on chamber door is opened!
    if (target_temperature - MAX_UNDERTEMP > esm.back_temperature)
    {
        esm.undertemp_ms -= ESM_POLL_INTERVAL;
        if (esm.undertemp_ms <= 0)
        {
            set_failure(FAIL_DOOR_OPENED);
            stop_esm();
        }
    }
    else
    {
        esm.undertemp_ms = MAX_UNDERTEMP_MS;
    }
    int pwm = autopid_run(esm.back_temperature, system_millis);
    set_pwm(PWM_HEATER, pwm);
    if (seconds_left > 0)
    {
        return ESM_CONTINUE_STATE;
    }
    return ESM_NEXT_STATE;
}

uint32_t poll_esm()
{
    // state standby
    if (_esm_at_start() != ESM_NEXT_STATE)
    {
        return ESM_POLL_INTERVAL;
    }
    crBegin;
    esm_status = STATUS_PRECOOLING;
    esm.algo_fan_pwm = MAX_FAN_PWM;
    set_pwm(PWM_HEATER, 0);

    crNext();

    { // precooling

        if (_esm_precooling() != ESM_NEXT_STATE)
        {
            return ESM_POLL_INTERVAL;
        }

        esm_status = STATUS_CHECK_HEATER; // check heater
        esm.preheating_start_ms = system_millis;
        esm.preheating_prev_temp = esm.back_temperature;
        set_pwm(PWM_HEATER, PWM_FULL_CYCLE);
        esm.algo_fan_pwm = NORMAL_FAN_PWM;
        esm.bangbang_cycle = 0;
    }

    crNext();

    { // heater check
        if (_esm_heater_check() != ESM_NEXT_STATE)
        {
            return ESM_POLL_INTERVAL;
        }

        esm_status = STATUS_PREHEATING;
        esm.preheating_start_ms = system_millis;
        esm.bangbang_cycle = 0;
        config_t *c = get_config();
        autopid_init(0, PWM_FULL_CYCLE, target_temperature, c->zn_mode);
    }

    crNext();

    { // preheating && stabilizing
        seconds_left -= ESM_POLL_INTERVAL / 1000;

        if (_esm_preheating() != ESM_NEXT_STATE)
        {
            return ESM_POLL_INTERVAL;
        }

        esm_status = STATUS_AUTOPID_RUNNING;
        esm.algo_fan_pwm = 0;
    }

    crNext();

    { // autopid learning
        seconds_left -= ESM_POLL_INTERVAL / 1000;
        if (_esm_autopid() != ESM_NEXT_STATE)
        {
            return ESM_POLL_INTERVAL;
        }
        esm_status = STATUS_ON_WORK;
    }

    crNext();

    {
        seconds_left -= ESM_POLL_INTERVAL / 1000;
        if (_esm_on_air() != ESM_NEXT_STATE)
        {
            return ESM_POLL_INTERVAL;
        }
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
    // int cooler_pwm = PWM_FULL_CYCLE * fan_pwm / 100;
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
    if (esm.algo_fan_pwm > 0)
    {
        set_pwm_percents(PWM_FAN, esm.algo_fan_pwm);
        return;
    }
    set_pwm_percents(PWM_FAN, fan_pwm);
}

uint16_t status_esm()
{
    return start_me;
}