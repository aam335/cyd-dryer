// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.2
// LVGL version: 8.3.11
// Project name: sushka_prj

#ifndef _UI_EVENTS_H
#define _UI_EVENTS_H

#ifdef __cplusplus
extern "C" {
#endif

void settemp_cb(lv_event_t * e);
void onoff_cb(lv_event_t * e);
void minus1h_cb(lv_event_t * e);
void minuns30m_cb(lv_event_t * e);
void plus1h_cb(lv_event_t * e);
void plus30m_cb(lv_event_t * e);
void setfanspeed_cb(lv_event_t * e);
void load_menu_config(lv_event_t * e);
void continue_cb(lv_event_t * e);
void pidselected(lv_event_t * e);
void save_menu_data(lv_event_t * e);
void reset_menu_pid(lv_event_t * e);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
