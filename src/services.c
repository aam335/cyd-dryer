#include <ui/ui.h>
#include "dryer.h"
#include <Arduino.h>

unsigned long system_millis;
int32_t seconds_left;
float target_temperature, current_temperature;
int32_t fan_pwm;

void apply_sensor_ht(float temperature, float humidity)
{
    bool error_temp = false;
    if (temperature > SENSOR_MAX_TEMP || temperature < SENSOR_MIN_TEMP)
    {
        current_temperature = temperature;
        lv_label_set_text_fmt(ui_crrettemp, "-- °C");
        error_temp = true;
    }
    else
    {
        lv_label_set_text_fmt(ui_crrettemp, "%d °C", (int)(temperature + 0.5));
    }
    if (error_temp || humidity < 0 || humidity > 100)
    {
        lv_label_set_text_fmt(ui_humidity, "-- %%");
    }
    else
    {
        lv_label_set_text_fmt(ui_humidity, "%d %%", (int)(humidity + 0.5));
    }
}

void check_and_update_timer(int delta)
{
    seconds_left += delta;
    if (seconds_left > MAX_TIMER)
    {
        seconds_left = MAX_TIMER;
    }
    if (seconds_left < 0)
    {
        seconds_left = 0;
    }
    int minutes = seconds_left % 3600 / 60;
    int hours = seconds_left / 3600;
    lv_label_set_text_fmt(ui_timeft, "%02d:%02d", hours, minutes);
}

void check_and_update_target_temperature(int target)
{
    if (target > MAX_TEMP)
    {
        target = MAX_TEMP;
    }
    if (target < MIN_TEMP)
    {
        target = MIN_TEMP;
    }
    target_temperature = target;
    lv_label_set_text_fmt(ui_targettemp, "%d", target);
    lv_arc_set_value(ui_temperature, target_temperature);
}

void check_and_update_fan_pwm(int target)
{
    if (target > MAX_FAN_PWM)
    {
        target = MAX_FAN_PWM;
    }
    if (target < MIN_FAN_PWM)
    {
        target = MIN_FAN_PWM;
    }
    fan_pwm = target;
    lv_label_set_text_fmt(ui_fanspeed, "%d%%", target);
}

void apply_onoff()
{
    turn_on_off();
    log_i("status_esm=%i",status_esm());
    if (status_esm() == 0)
    {
        lv_obj_add_flag(ui_online, LV_OBJ_FLAG_HIDDEN);
        return;
    }
    lv_obj_clear_flag(ui_online, LV_OBJ_FLAG_HIDDEN);
}

void init_values()
{
    seconds_left = START_TIMER;
    target_temperature = START_TEMPERATURE;

    check_and_update_timer(0);
    check_and_update_target_temperature(START_TEMPERATURE);
    check_and_update_fan_pwm(START_FAN_PWM);
    lv_label_set_text_fmt(ui_mintemp, "%d", MIN_TEMP);
    lv_label_set_text_fmt(ui_maxtemp, "%d", MAX_TEMP);
    lv_obj_add_flag(ui_online, LV_OBJ_FLAG_HIDDEN);
}
