#include <ui/ui.h>
#include "dryer.h"
#include <Arduino.h>

unsigned long system_millis;
int32_t seconds_left;
float target_temperature, current_temperature;
int32_t fan_pwm;

void apply_temperature(float temperature, float humidity)
{
    current_temperature = temperature;

    if (temperature > SENSOR_MAX_TEMP || temperature < SENSOR_MIN_TEMP)
    {
        lv_label_set_text_fmt(ui_crrettemp, "-- °C");
    }
    else
    {
        lv_label_set_text_fmt(ui_crrettemp, "%d °C", (int)(temperature + 0.5));
    }
}
void show_pid_status()
{
    if (autopid_finished())
    {
        lv_obj_clear_flag(ui_resetpid, LV_OBJ_FLAG_HIDDEN);

        return;
    }
    lv_obj_add_flag(ui_resetpid, LV_OBJ_FLAG_HIDDEN);
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
    if (status_esm())
    {
        start_esm();
    }
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
    if (status_esm())
    {
        start_esm();
    }
}

void show_onoff()
{
    if (status_esm() == 0)
    {
        lv_obj_add_flag(ui_online, LV_OBJ_FLAG_HIDDEN);
        return;
    }
    lv_obj_clear_flag(ui_online, LV_OBJ_FLAG_HIDDEN);
}

void apply_onoff()
{
    turn_on_off();
    log_i("status_esm=%i", status_esm());
    show_onoff();
}

void apply_emergency_stop()
{
    stop_esm();
    // log_i("STOP!!! status_esm=%i", status_esm());
    show_onoff();
}
static char debug_text[200];

void init_values()
{
    seconds_left = START_TIMER;
    target_temperature = START_TEMPERATURE;
    lv_arc_set_range(ui_temperature, MIN_TEMP, MAX_TEMP);
    check_and_update_timer(0);
    check_and_update_target_temperature(START_TEMPERATURE);
    check_and_update_fan_pwm(START_FAN_PWM);
    lv_label_set_text_fmt(ui_mintemp, "%d", MIN_TEMP);
    lv_label_set_text_fmt(ui_maxtemp, "%d", MAX_TEMP);
    lv_obj_add_flag(ui_online, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_errormodal, LV_OBJ_FLAG_HIDDEN);
    show_text_status();
    debug_text[0] = '\0';
}
void set_debug_text(char *s)
{
    snprintf(debug_text, 20, "%s", s);
}
void clear_debug_text()
{
    debug_text[0] = '\0';
}

void show_text_status()
{
    if (debug_text[0] != '\0')
    {
        lv_label_set_text_fmt(ui_status, "%s %d/%d", debug_text, get_pwm(PWM_HEATER), get_pwm(PWM_FAN));
        return;
    }
    const char *s = "-unknown-";
    switch (esm_status)
    {
    case STATUS_STANDBY:
        s = "standby";
        break;
    case STATUS_CHECK_HEATER:
        s = "heater check";
        break;
    case STATUS_PREHEATING:
        s = "preheating";
        break;
    case STATUS_PRECOOLING:
        s = "precooling";
        break;
    case STATUS_AUTOPID_RUNNING:
        s = "auto pid";
        break;
    case STATUS_ON_WORK:
        s = "on air";
        break;
    case STATUS_SENSOR_ERROR:
        s = "err: no sensor";
        break;
    }

    lv_label_set_text_fmt(ui_status, "%s h:%d f:%d", s, get_pwm(PWM_HEATER), get_pwm(PWM_FAN));
}
