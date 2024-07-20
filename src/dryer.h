#pragma once
#include <Arduino.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

#include "pwm.h"
#include "esm.h"
#include "coroutine.h"
#include "autopid.h"

#ifdef __cplusplus
extern "C"
{
#endif
    void init_values();
    void apply_onoff();
    void apply_sensor_ht(float temperature, float humidity);
    void check_and_update_target_temperature(int target);
    void check_and_update_timer(int delta);
    void check_and_update_fan_pwm(int target);

    uint32_t poll_esm();

    extern unsigned long system_millis;
    extern int32_t seconds_left;
    extern float target_temperature, current_temperature;
    extern int32_t fan_pwm;

#ifdef __cplusplus
} /*extern "C"*/
#endif


#define ESM_POLL_INTERVAL PWM_INTERVAL
#define MOTOR_OFF_DELAY 15000

#define HOUR 3600
#define HALF_HOUR 1800
#define MAX_TIMER (24 * HOUR)
#define START_TIMER (6 * HOUR)
#define START_TEMPERATURE 95
#define MAX_TEMP 100
#define MIN_TEMP 60
#define MAX_FAN_PWM 100
#define MIN_FAN_PWM 25
#define START_FAN_PWM 50

#define HEATER_PIN GPIO_NUM_12
#define FAN_PIN GPIO_NUM_18

#define ERRORED_SENSOR (-10000)
#define SENSOR_MAX_TEMP 125
#define SENSOR_MIN_TEMP -40

#define SENSORS_POLL_INTERVAL 250
