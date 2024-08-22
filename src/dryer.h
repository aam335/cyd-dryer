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
    void apply_temperature(float temperature, float humidity);
    void check_and_update_target_temperature(int target);
    void check_and_update_timer(int delta);
    void check_and_update_fan_pwm(int target);
    void show_pid_status();
    void show_text_status();
    void apply_emergency_stop();

    float get_median_temp();

    void reset_failure();
    void show_notify_on_failure();
    void set_failure(int fail_id);

    void set_debug_text(char *s);
    void clear_debug_text();

    void load_pid();
    void save_pid();

    float ntc_read();
    void ntc_init(int);

    uint32_t poll_esm();

    extern unsigned long system_millis;
    extern int32_t seconds_left;
    extern float target_temperature, current_temperature;
    extern int32_t fan_pwm;

    extern int esm_status;
    extern const float ADC_LUT[4096];

#ifdef __cplusplus
} /*extern "C"*/
#endif

#define ESM_POLL_INTERVAL PWM_INTERVAL
#define ESM_POLL_INTERVAL_MIN 10
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
#define NORMAL_FAN_PWM 50
#define START_FAN_PWM 50

#define HEATER_PIN GPIO_NUM_21 // GPIO_NUM_12
#define FAN_PIN GPIO_NUM_22    // GPIO_NUM_18
#define THERMISTOR_PIN GPIO_NUM_35

#define ERRORED_SENSOR (-10000)
#define SENSOR_MAX_TEMP 125
#define SENSOR_MIN_TEMP -40

#define SENSORS_POLL_INTERVAL 50
#define SENSORS_MED_COUNT 5

#define NOTIFY_POLL_INTERVAL 1000
#define STATUS_POLL_INTERVAL 1000
#define LED_POLL_INTERVAL 2000

#define MAX_SENSOR_CONTINUOS_ERRORS 5
#define CHECK_HEATER_MS 120000
#define CHECK_HEATER_MIN_DELTA 0.5
#define PREHEATING_TARGET_TEMP_MS 60000
#define PREHEATING_TARGET_TEMP_MAX_DELTA 0.6

#define TUNE_PID_DELTA 0.5 // filter
#define TUNE_PID_WASTE_PEAKS 4

#define PREHEATING_GANGBANG_MIN_CYCLES 10
#define PREHEATING_MIN_PERIOD 10 * 60 * 1000

#define MAX_OVERTEMP 5         // max temperature from target for esm restart
#define MAX_UNDERTEMP 10       // max temperature from target for esm restart
#define MAX_UNDERTEMP_MS 15000 // max time, when temperature is undertarget - chamber is opened?

enum STATUSES
{
    STATUS_STANDBY,
    STATUS_PRECOOLING,
    STATUS_CHECK_HEATER,
    STATUS_PREHEATING,
    STATUS_AUTOPID_RUNNING,
    STATUS_ON_WORK,
    STATUS_SENSOR_ERROR,
};

enum FAILURES
{
    FAIL_NONE,
    FAIL_PREHEAT,
    FAIL_DOOR_OPENED,
    FAIL_SENSOR,
};

typedef struct
{
    bool is_initialized;
    uint8_t zn_mode;
    float ki,kd,kp;
    
} config_t;