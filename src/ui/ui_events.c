#include <ui/ui.h>
#include "dryer.h"

static bool reset_pid;

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

void reset_menu_pid(lv_event_t *e)
{
	lv_textarea_set_text(ui_pid_ki, "0.0");
	lv_textarea_set_text(ui_pid_kp, "0.0");
	lv_textarea_set_text(ui_pid_kd, "0.0");

	lv_obj_clear_flag(ui_pid_ki, LV_OBJ_FLAG_CLICK_FOCUSABLE);
	lv_obj_clear_flag(ui_pid_kp, LV_OBJ_FLAG_CLICK_FOCUSABLE);
	lv_obj_clear_flag(ui_pid_kd, LV_OBJ_FLAG_CLICK_FOCUSABLE);

	lv_label_set_text(ui_ku_value, "--");
	lv_label_set_text(ui_tu_value, "--");
	reset_pid = true;
}

void set_dropdown_active_value(lv_obj_t *obj, const char *value)
{
	const char *opts = lv_dropdown_get_options(obj);
	int index = 0;
	int value_len = strlen(value);
	while (1)
	{
		if (strncmp(opts, value, value_len) == 0 && opts[value_len] == '\n')
		{
			lv_dropdown_set_selected(obj, index);
			return;
		}
		opts = strchr(opts, '\n');
		if (opts == NULL)
		{
			return;
		}
		opts++;
		index++;
	}
}
void set_dropdown_active_value_int(lv_obj_t *obj, int i)
{
	char s[10];
	snprintf(s, sizeof(s) - 1, "%i", i);
	set_dropdown_active_value(obj, &s[0]);
}
#define ACCEPTED_CHARS_FLOAT "0123456789."
#define ACCEPTED_CHARS_INT "0123456789"

#define TMP_SIZE 10
static char tmpstr[TMP_SIZE + 1];

void morph_numeric_string(char *s, int n)
{
	char *p;
	int count;

	p = strchr(s, '.'); // Find decimal point, if any.
	if (p != NULL)
	{
		count = n; // Adjust for more or less decimals.
		while (count >= 0)
		{ // Maximum decimals allowed.
			count--;
			if (*p == '\0') // If there's less than desired.
				break;
			p++; // Next character.
		}

		*p-- = '\0';	  // Truncate string.
		while (*p == '0') // Remove trailing zeros.
			*p-- = '\0';

		if (*p == '.')
		{ // If all decimals were zeros, remove ".".
			*p = '\0';
		}
	}
}

static inline char *tftoa(float f)
{
	if (f == 0)
	{
		strcpy(tmpstr, "0.0");
		return tmpstr;
	}
	snprintf(tmpstr, TMP_SIZE, "%f", f);
	morph_numeric_string(tmpstr, 5);
	return tmpstr;
}
static inline char *titoa(int i)
{
	snprintf(tmpstr, TMP_SIZE, "%i", i);
	return tmpstr;
}

void load_menu_config(lv_event_t *e)
{
	config_t *c = get_config();
	reset_pid = false;
	lv_obj_add_flag(ui_Keyboard1, LV_OBJ_FLAG_HIDDEN);
	log_i("loadconfig %f %f",c->ku,c->tu);

	if (c->ku == 0)
	{
		lv_label_set_text(ui_ku_value, "--");
		lv_label_set_text(ui_tu_value, "--");
	}
	else
	{
		lv_label_set_text(ui_ku_value, tftoa(c->ku));
		lv_label_set_text(ui_tu_value, tftoa(c->tu));
	}
	set_dropdown_active_value_int(ui_mincelsius, c->tmin);
	set_dropdown_active_value_int(ui_maxcelsius, c->tmax);
	set_dropdown_active_value_int(ui_tgtcelsius, c->tstart);
	set_dropdown_active_value_int(ui_fanstart, c->fan_start);

	lv_textarea_set_accepted_chars(ui_pid_ki, ACCEPTED_CHARS_FLOAT);
	lv_textarea_set_accepted_chars(ui_pid_kp, ACCEPTED_CHARS_FLOAT);
	lv_textarea_set_accepted_chars(ui_pid_kd, ACCEPTED_CHARS_FLOAT);

	lv_obj_add_flag(ui_pid_ki, LV_OBJ_FLAG_CLICK_FOCUSABLE);
	lv_obj_add_flag(ui_pid_kp, LV_OBJ_FLAG_CLICK_FOCUSABLE);
	lv_obj_add_flag(ui_pid_kd, LV_OBJ_FLAG_CLICK_FOCUSABLE);

	lv_textarea_set_text(ui_pid_ki, tftoa(c->ki));
	lv_textarea_set_text(ui_pid_kp, tftoa(c->kp));
	lv_textarea_set_text(ui_pid_kd, tftoa(c->kd));

	lv_textarea_set_accepted_chars(ui_R25_Ohm, ACCEPTED_CHARS_INT);
	lv_textarea_set_accepted_chars(ui_R_div_Ohm, ACCEPTED_CHARS_INT);
	lv_textarea_set_accepted_chars(ui_beta, ACCEPTED_CHARS_INT);

	lv_textarea_set_text(ui_R25_Ohm, titoa(c->r25));
	lv_textarea_set_text(ui_R_div_Ohm, titoa(c->r_div));
	lv_textarea_set_text(ui_beta, titoa(c->beta));
}
int get_value_dropdown(lv_obj_t *obj)
{
	char s[10];
	lv_dropdown_get_selected_str(obj, s, sizeof(s) - 1);
	return atoi(s);
}

float get_value_textareaf(lv_obj_t *obj)
{
	const char *s = lv_textarea_get_text(obj);
	double d = atof(s);
	log_i("%s -> %f ->%.4f", s, d, d);
	return d;
}

int get_value_textareai(lv_obj_t *obj)
{
	const char *s = lv_textarea_get_text(obj);
	return atoi(s);
}

void save_menu_data(lv_event_t *e)
{
	config_t *c = get_config();
	c->tmin = get_value_dropdown(ui_mincelsius);
	c->tmax = get_value_dropdown(ui_maxcelsius);
	c->tstart = get_value_dropdown(ui_tgtcelsius);
	if (c->tstart > c->tmax)
		c->tstart = c->tmax;
	if (c->tstart < c->tmin)
		c->tstart = c->tmin;

	c->fan_start = get_value_dropdown(ui_fanstart);

	c->zn_mode = lv_dropdown_get_selected(ui_pidselect);
	c->ki = get_value_textareaf(ui_pid_ki);
	c->kp = get_value_textareaf(ui_pid_kp);
	c->kd = get_value_textareaf(ui_pid_kd);

	c->r25 = get_value_textareai(ui_R25_Ohm);
	c->r_div = get_value_textareai(ui_R_div_Ohm);
	c->beta = get_value_textareai(ui_beta);

	if (reset_pid)
	{
		c->ku = 0;
		c->tu = 0;
		c->ki = 0;
		c->kp = 0;
		c->kd = 0;
	}

	save_config();
	init_values();
}

void pidselected(lv_event_t *e)
{
	config_t *c = get_config();
	if (c->tu == 0)
		return;
	autopid_t a = {
		.zn_mode = lv_dropdown_get_selected(ui_pidselect),
		.i = DEFAULT_TUNING_CYCLES,
		.cycles = DEFAULT_TUNING_CYCLES,
		.ku = c->ku,
		.tu = c->ku,
		.loop_interval = DEFAULT_LOOP_INTERVAL};
	autopid_refresh_pids(&a);

	lv_textarea_set_text(ui_pid_ki, tftoa(a.ki));
	lv_textarea_set_text(ui_pid_kp, tftoa(a.kp));
	lv_textarea_set_text(ui_pid_kd, tftoa(a.kd));
}

void beta_click(lv_event_t *e)
{
	log_i("beta called");
	config_t *c = get_config();
	c->ku = 10;
	c->tu = 20;
	load_menu_config(NULL);
	log_i("beta called2");
}
