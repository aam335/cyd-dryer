// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.2
// LVGL version: 9.1.0
// Project name: sushka_prj

#include "../ui.h"

void ui_Screen1_screen_init(void)
{
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_remove_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_mainscreen = lv_obj_create(ui_Screen1);
    lv_obj_set_width(ui_mainscreen, lv_pct(100));
    lv_obj_set_height(ui_mainscreen, lv_pct(100));
    lv_obj_set_align(ui_mainscreen, LV_ALIGN_CENTER);
    lv_obj_remove_flag(ui_mainscreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_mainscreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_mainscreen, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_mainscreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_mainscreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_mainscreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_mainscreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_temeratureindicator = lv_obj_create(ui_mainscreen);
    lv_obj_set_width(ui_temeratureindicator, 180);
    lv_obj_set_height(ui_temeratureindicator, 180);
    lv_obj_set_align(ui_temeratureindicator, LV_ALIGN_TOP_MID);
    lv_obj_remove_flag(ui_temeratureindicator, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_temeratureindicator, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_temeratureindicator, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_temeratureindicator, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_temeratureindicator, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_temeratureindicator, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_temeratureindicator, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_temperature = lv_arc_create(ui_temeratureindicator);
    lv_obj_set_width(ui_temperature, lv_pct(90));
    lv_obj_set_height(ui_temperature, lv_pct(90));
    lv_obj_set_align(ui_temperature, LV_ALIGN_CENTER);
    lv_arc_set_range(ui_temperature, 65, 110);
    lv_arc_set_value(ui_temperature, 95);
    lv_obj_set_style_arc_color(ui_temperature, lv_color_hex(0x4040FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_temperature, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_pad_left(ui_temperature, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_temperature, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_temperature, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_temperature, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_temperature, 8, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_shadow_color(ui_temperature, lv_color_hex(0x000000), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_temperature, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_temperature, 1, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_temperature, 1, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_targettemp = lv_label_create(ui_temperature);
    lv_obj_set_width(ui_targettemp, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_targettemp, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_targettemp, 0);
    lv_obj_set_y(ui_targettemp, -27);
    lv_obj_set_align(ui_targettemp, LV_ALIGN_CENTER);
    lv_label_set_text(ui_targettemp, "95");
    lv_obj_set_style_text_font(ui_targettemp, &lv_font_montserrat_34, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_timeft = lv_label_create(ui_temperature);
    lv_obj_set_width(ui_timeft, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_timeft, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_timeft, 1);
    lv_obj_set_y(ui_timeft, 14);
    lv_obj_set_align(ui_timeft, LV_ALIGN_CENTER);
    lv_label_set_text(ui_timeft, "00:00");
    lv_obj_set_style_text_font(ui_timeft, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_onoffarea = lv_obj_create(ui_temeratureindicator);
    lv_obj_set_width(ui_onoffarea, lv_pct(71));
    lv_obj_set_height(ui_onoffarea, lv_pct(71));
    lv_obj_set_align(ui_onoffarea, LV_ALIGN_CENTER);
    lv_obj_remove_flag(ui_onoffarea, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_onoffarea, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_onoffarea, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_onoffarea, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    ui_object_set_themeable_style_property(ui_onoffarea, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BORDER_COLOR,
                                           _ui_theme_color_button);
    ui_object_set_themeable_style_property(ui_onoffarea, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BORDER_OPA,
                                           _ui_theme_alpha_button);

    ui_mintemp = lv_label_create(ui_temeratureindicator);
    lv_obj_set_width(ui_mintemp, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_mintemp, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_mintemp, LV_ALIGN_BOTTOM_LEFT);
    lv_label_set_text(ui_mintemp, "min");

    ui_maxtemp = lv_label_create(ui_temeratureindicator);
    lv_obj_set_width(ui_maxtemp, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_maxtemp, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_maxtemp, LV_ALIGN_BOTTOM_RIGHT);
    lv_label_set_text(ui_maxtemp, "max");

    ui_online = lv_spinner_create(ui_temeratureindicator);
    //lv_spinner_set_anim_params(ui_online, 1000, 90);
    lv_obj_set_width(ui_online, lv_pct(70));
    lv_obj_set_height(ui_online, lv_pct(70));
    lv_obj_set_align(ui_online, LV_ALIGN_CENTER);
    lv_obj_remove_flag(ui_online, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE |
                       LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_arc_color(ui_online, lv_color_hex(0x4040FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_online, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_online, 6, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_object_set_themeable_style_property(ui_online, LV_PART_INDICATOR | LV_STATE_DEFAULT, LV_STYLE_ARC_COLOR,
                                           _ui_theme_color_button);
    ui_object_set_themeable_style_property(ui_online, LV_PART_INDICATOR | LV_STATE_DEFAULT, LV_STYLE_ARC_OPA,
                                           _ui_theme_alpha_button);

    ui_minus60 = lv_button_create(ui_mainscreen);
    lv_obj_set_width(ui_minus60, 50);
    lv_obj_set_height(ui_minus60, 50);
    lv_obj_add_flag(ui_minus60, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_remove_flag(ui_minus60, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    ui_object_set_themeable_style_property(ui_minus60, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_COLOR,
                                           _ui_theme_color_button);
    ui_object_set_themeable_style_property(ui_minus60, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_OPA,
                                           _ui_theme_alpha_button);
    ui_object_set_themeable_style_property(ui_minus60, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_SHADOW_COLOR,
                                           _ui_theme_color_buttonshadow);
    ui_object_set_themeable_style_property(ui_minus60, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_SHADOW_OPA,
                                           _ui_theme_alpha_buttonshadow);
    lv_obj_set_style_shadow_width(ui_minus60, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_minus60, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui_minus60, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui_minus60, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label1 = lv_label_create(ui_minus60);
    lv_obj_set_width(ui_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label1, "-1H");
    ui_object_set_themeable_style_property(ui_Label1, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_TEXT_COLOR,
                                           _ui_theme_color_bubbttontext);
    ui_object_set_themeable_style_property(ui_Label1, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_TEXT_OPA,
                                           _ui_theme_alpha_bubbttontext);

    ui_minus30m = lv_button_create(ui_mainscreen);
    lv_obj_set_width(ui_minus30m, 50);
    lv_obj_set_height(ui_minus30m, 125);
    lv_obj_set_x(ui_minus30m, 0);
    lv_obj_set_y(ui_minus30m, 55);
    lv_obj_add_flag(ui_minus30m, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_remove_flag(ui_minus30m, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    ui_object_set_themeable_style_property(ui_minus30m, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_COLOR,
                                           _ui_theme_color_button);
    ui_object_set_themeable_style_property(ui_minus30m, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_OPA,
                                           _ui_theme_alpha_button);
    ui_object_set_themeable_style_property(ui_minus30m, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_SHADOW_COLOR,
                                           _ui_theme_color_buttonshadow);
    ui_object_set_themeable_style_property(ui_minus30m, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_SHADOW_OPA,
                                           _ui_theme_alpha_buttonshadow);
    lv_obj_set_style_shadow_width(ui_minus30m, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_minus30m, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui_minus30m, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui_minus30m, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_minus30m, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_minus30m, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label2 = lv_label_create(ui_minus30m);
    lv_obj_set_width(ui_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label2, "-30m");
    ui_object_set_themeable_style_property(ui_Label2, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_TEXT_COLOR,
                                           _ui_theme_color_bubbttontext);
    ui_object_set_themeable_style_property(ui_Label2, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_TEXT_OPA,
                                           _ui_theme_alpha_bubbttontext);

    ui_plus1h = lv_button_create(ui_mainscreen);
    lv_obj_set_width(ui_plus1h, 50);
    lv_obj_set_height(ui_plus1h, 50);
    lv_obj_set_align(ui_plus1h, LV_ALIGN_TOP_RIGHT);
    lv_obj_add_flag(ui_plus1h, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_remove_flag(ui_plus1h, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    ui_object_set_themeable_style_property(ui_plus1h, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_COLOR,
                                           _ui_theme_color_button);
    ui_object_set_themeable_style_property(ui_plus1h, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_OPA,
                                           _ui_theme_alpha_button);
    ui_object_set_themeable_style_property(ui_plus1h, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_SHADOW_COLOR,
                                           _ui_theme_color_buttonshadow);
    ui_object_set_themeable_style_property(ui_plus1h, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_SHADOW_OPA,
                                           _ui_theme_alpha_buttonshadow);
    lv_obj_set_style_shadow_width(ui_plus1h, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_plus1h, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui_plus1h, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui_plus1h, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_plus1h, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_plus1h, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label3 = lv_label_create(ui_plus1h);
    lv_obj_set_width(ui_Label3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label3, "+1H");
    ui_object_set_themeable_style_property(ui_Label3, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_TEXT_COLOR,
                                           _ui_theme_color_bubbttontext);
    ui_object_set_themeable_style_property(ui_Label3, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_TEXT_OPA,
                                           _ui_theme_alpha_bubbttontext);

    ui_plus30m = lv_button_create(ui_mainscreen);
    lv_obj_set_width(ui_plus30m, 50);
    lv_obj_set_height(ui_plus30m, 125);
    lv_obj_set_x(ui_plus30m, 0);
    lv_obj_set_y(ui_plus30m, 55);
    lv_obj_set_align(ui_plus30m, LV_ALIGN_TOP_RIGHT);
    lv_obj_add_flag(ui_plus30m, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_remove_flag(ui_plus30m, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    ui_object_set_themeable_style_property(ui_plus30m, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_COLOR,
                                           _ui_theme_color_button);
    ui_object_set_themeable_style_property(ui_plus30m, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_OPA,
                                           _ui_theme_alpha_button);
    ui_object_set_themeable_style_property(ui_plus30m, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_SHADOW_COLOR,
                                           _ui_theme_color_buttonshadow);
    ui_object_set_themeable_style_property(ui_plus30m, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_SHADOW_OPA,
                                           _ui_theme_alpha_buttonshadow);
    lv_obj_set_style_shadow_width(ui_plus30m, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_plus30m, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui_plus30m, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui_plus30m, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_plus30m, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_plus30m, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label4 = lv_label_create(ui_plus30m);
    lv_obj_set_width(ui_Label4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label4, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label4, "+30m");
    ui_object_set_themeable_style_property(ui_Label4, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_TEXT_COLOR,
                                           _ui_theme_color_bubbttontext);
    ui_object_set_themeable_style_property(ui_Label4, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_TEXT_OPA,
                                           _ui_theme_alpha_bubbttontext);

    ui_fanpanel = lv_obj_create(ui_Screen1);
    lv_obj_set_width(ui_fanpanel, lv_pct(100));
    lv_obj_set_height(ui_fanpanel, lv_pct(9));
    lv_obj_set_x(ui_fanpanel, 0);
    lv_obj_set_y(ui_fanpanel, lv_pct(-13));
    lv_obj_set_align(ui_fanpanel, LV_ALIGN_BOTTOM_MID);
    lv_obj_remove_flag(ui_fanpanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_fanpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_fanpanel, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_fanpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_fanpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_fanpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_fanpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label7 = lv_label_create(ui_fanpanel);
    lv_obj_set_width(ui_Label7, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label7, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label7, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_Label7, "fan");

    ui_fanspeed = lv_label_create(ui_fanpanel);
    lv_obj_set_width(ui_fanspeed, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_fanspeed, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_fanspeed, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_fanspeed, "80%");

    ui_setfanspeed = lv_slider_create(ui_fanpanel);
    lv_slider_set_range(ui_setfanspeed, 25, 100);
    lv_slider_set_value(ui_setfanspeed, 50, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_setfanspeed) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_setfanspeed, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_setfanspeed, lv_pct(60));
    lv_obj_set_height(ui_setfanspeed, lv_pct(70));
    lv_obj_set_align(ui_setfanspeed, LV_ALIGN_CENTER);


    //Compensating for LVGL9.1 draw crash with bar/slider max value when top-padding is nonzero and right-padding is 0
    if(lv_obj_get_style_pad_top(ui_setfanspeed, LV_PART_MAIN) > 0) lv_obj_set_style_pad_right(ui_setfanspeed,
                                                                                                  lv_obj_get_style_pad_right(ui_setfanspeed, LV_PART_MAIN) + 1, LV_PART_MAIN);
    ui_sensor = lv_obj_create(ui_Screen1);
    lv_obj_set_width(ui_sensor, lv_pct(100));
    lv_obj_set_height(ui_sensor, lv_pct(8));
    lv_obj_set_align(ui_sensor, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_remove_flag(ui_sensor, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_sensor, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_sensor, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_sensor, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_sensor, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_sensor, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_sensor, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_crrettemp = lv_label_create(ui_sensor);
    lv_obj_set_width(ui_crrettemp, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_crrettemp, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_crrettemp, LV_ALIGN_BOTTOM_LEFT);
    lv_label_set_text(ui_crrettemp, "63");

    ui_Button3 = lv_button_create(ui_sensor);
    lv_obj_set_width(ui_Button3, LV_SIZE_CONTENT);   /// 100
    lv_obj_set_height(ui_Button3, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_align(ui_Button3, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(ui_Button3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_remove_flag(ui_Button3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label18 = lv_label_create(ui_Button3);
    lv_obj_set_width(ui_Label18, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label18, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label18, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label18, "...");

    ui_status = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_status, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_status, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_status, LV_ALIGN_BOTTOM_MID);
    lv_label_set_text(ui_status, "Text");

    ui_errormodal = lv_obj_create(ui_Screen1);
    lv_obj_set_width(ui_errormodal, lv_pct(80));
    lv_obj_set_height(ui_errormodal, lv_pct(80));
    lv_obj_set_align(ui_errormodal, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_errormodal, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_remove_flag(ui_errormodal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Button1 = lv_button_create(ui_errormodal);
    lv_obj_set_width(ui_Button1, 100);
    lv_obj_set_height(ui_Button1, 50);
    lv_obj_set_x(ui_Button1, 0);
    lv_obj_set_y(ui_Button1, 55);
    lv_obj_set_align(ui_Button1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_remove_flag(ui_Button1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_errortext = lv_label_create(ui_errormodal);
    lv_obj_set_width(ui_errortext, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_errortext, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_errortext, -6);
    lv_obj_set_y(ui_errortext, -28);
    lv_obj_set_align(ui_errortext, LV_ALIGN_CENTER);
    lv_label_set_text(ui_errortext, "Text");

    ui_Label6 = lv_label_create(ui_errormodal);
    lv_obj_set_width(ui_Label6, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label6, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label6, -4);
    lv_obj_set_y(ui_Label6, 55);
    lv_obj_set_align(ui_Label6, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label6, "contine");

    lv_obj_add_event_cb(ui_temperature, ui_event_temperature, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_onoffarea, ui_event_onoffarea, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_minus60, ui_event_minus60, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_minus30m, ui_event_minus30m, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_plus1h, ui_event_plus1h, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_plus30m, ui_event_plus30m, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_setfanspeed, ui_event_setfanspeed, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button3, ui_event_Button3, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button1, ui_event_Button1, LV_EVENT_ALL, NULL);

}
