#include <ui/ui.h>
#include "dryer.h"

void settemp_cb(lv_event_t *e)
{
	// Your code here
	lv_obj_t *arc = lv_event_get_target(e);
	int value = lv_arc_get_value(arc);
	check_and_update_target_temperature(value);
}

void minus1h_cb(lv_event_t *e)
{
	check_and_update_timer(-HOUR);
}

void minuns30m_cb(lv_event_t *e)
{
	check_and_update_timer(-HALF_HOUR);
}

void plus1h_cb(lv_event_t *e)
{
	check_and_update_timer(HOUR);
}

void plus30m_cb(lv_event_t *e)
{
	check_and_update_timer(HALF_HOUR);
}

void onoff_cb(lv_event_t *e)
{
	apply_onoff();
}

void setfanspeed_cb(lv_event_t *e)
{
	lv_obj_t *slider = lv_event_get_target(e);
	int value = lv_slider_get_value(slider);
	check_and_update_fan_pwm(value);
}

void continue_cb(lv_event_t *e)
{
	reset_failure();
}

void reset_pid_cb(lv_event_t *e)
{
	log_i("resetted pid");
	memset(&autopid, 0, sizeof(autopid_t));
	save_pid();
}

void reset_menu_pid(lv_event_t * e)
{
	// Your code here
}

void save_menu_data(lv_event_t * e)
{
	// Your code here
}

void ki_text_cb(lv_event_t * e)
{
	// Your code here
}

void kp_text_cb(lv_event_t * e)
{
	// Your code here
}

void kd_text_cb(lv_event_t * e)
{
	// Your code here
}

void load_menu_config(lv_event_t * e)
{
	// Your code here
}
