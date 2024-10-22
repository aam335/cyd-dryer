// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.2
// LVGL version: 8.3.11
// Project name: sushka_prj

#include "../ui.h"

void ui_config_screen_init(void)
{
    ui_config = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_config, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_config, lv_color_hex(0x292831), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_config, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Container3 = lv_obj_create(ui_config);
    lv_obj_remove_style_all(ui_Container3);
    lv_obj_set_height(ui_Container3, 41);
    lv_obj_set_width(ui_Container3, lv_pct(100));
    lv_obj_set_x(ui_Container3, 0);
    lv_obj_set_y(ui_Container3, 139);
    lv_obj_clear_flag(ui_Container3, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_maxmenutemp = lv_obj_create(ui_Container3);
    lv_obj_remove_style_all(ui_maxmenutemp);
    lv_obj_set_width(ui_maxmenutemp, lv_pct(33));
    lv_obj_set_height(ui_maxmenutemp, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_align(ui_maxmenutemp, LV_ALIGN_BOTTOM_MID);
    lv_obj_clear_flag(ui_maxmenutemp, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label5 = lv_label_create(ui_maxmenutemp);
    lv_obj_set_width(ui_Label5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label5, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_Label5, "°C max");

    ui_maxcelsius = lv_dropdown_create(ui_maxmenutemp);
    lv_dropdown_set_options(ui_maxcelsius, "80\n90\n100\n110");
    lv_obj_set_width(ui_maxcelsius, 60);
    lv_obj_set_height(ui_maxcelsius, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_maxcelsius, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_maxcelsius, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_pad_left(ui_maxcelsius, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_maxcelsius, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_maxcelsius, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_maxcelsius, 0, LV_PART_MAIN | LV_STATE_DEFAULT);



    ui_minmenutemp = lv_obj_create(ui_Container3);
    lv_obj_remove_style_all(ui_minmenutemp);
    lv_obj_set_width(ui_minmenutemp, lv_pct(33));
    lv_obj_set_height(ui_minmenutemp, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_align(ui_minmenutemp, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_clear_flag(ui_minmenutemp, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label8 = lv_label_create(ui_minmenutemp);
    lv_obj_set_width(ui_Label8, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label8, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label8, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_Label8, "°C min");

    ui_mincelsius = lv_dropdown_create(ui_minmenutemp);
    lv_dropdown_set_options(ui_mincelsius, "50\n60\n70\n80\n");
    lv_obj_set_width(ui_mincelsius, 50);
    lv_obj_set_height(ui_mincelsius, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_mincelsius, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_mincelsius, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_pad_left(ui_mincelsius, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_mincelsius, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_mincelsius, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_mincelsius, 0, LV_PART_MAIN | LV_STATE_DEFAULT);



    ui_Label9 = lv_label_create(ui_Container3);
    lv_obj_set_width(ui_Label9, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label9, LV_SIZE_CONTENT);    /// 1
    lv_label_set_text(ui_Label9, "temperature and fan");

    ui_fan = lv_obj_create(ui_Container3);
    lv_obj_remove_style_all(ui_fan);
    lv_obj_set_width(ui_fan, lv_pct(30));
    lv_obj_set_height(ui_fan, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_align(ui_fan, LV_ALIGN_TOP_RIGHT);
    lv_obj_clear_flag(ui_fan, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label17 = lv_label_create(ui_fan);
    lv_obj_set_width(ui_Label17, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label17, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label17, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_Label17, "% fan");

    ui_fanstart = lv_dropdown_create(ui_fan);
    lv_dropdown_set_options(ui_fanstart, "25\n50\n75\n100");
    lv_obj_set_width(ui_fanstart, 50);
    lv_obj_set_height(ui_fanstart, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_fanstart, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_fanstart, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_pad_left(ui_fanstart, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_fanstart, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_fanstart, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_fanstart, 0, LV_PART_MAIN | LV_STATE_DEFAULT);



    ui_minmenutemp2 = lv_obj_create(ui_Container3);
    lv_obj_remove_style_all(ui_minmenutemp2);
    lv_obj_set_width(ui_minmenutemp2, lv_pct(33));
    lv_obj_set_height(ui_minmenutemp2, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_align(ui_minmenutemp2, LV_ALIGN_BOTTOM_RIGHT);
    lv_obj_clear_flag(ui_minmenutemp2, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label19 = lv_label_create(ui_minmenutemp2);
    lv_obj_set_width(ui_Label19, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label19, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label19, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_Label19, "°C tgt");

    ui_tgtcelsius = lv_dropdown_create(ui_minmenutemp2);
    lv_dropdown_set_options(ui_tgtcelsius, "60\n65\n70\n75\n80\n85\n90\n95\n100\n105\n");
    lv_obj_set_width(ui_tgtcelsius, 60);
    lv_obj_set_height(ui_tgtcelsius, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_tgtcelsius, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_tgtcelsius, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_pad_left(ui_tgtcelsius, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_tgtcelsius, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_tgtcelsius, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_tgtcelsius, 0, LV_PART_MAIN | LV_STATE_DEFAULT);



    ui_pids = lv_obj_create(ui_config);
    lv_obj_remove_style_all(ui_pids);
    lv_obj_set_height(ui_pids, 64);
    lv_obj_set_width(ui_pids, lv_pct(100));
    lv_obj_set_x(ui_pids, 0);
    lv_obj_set_y(ui_pids, 57);
    lv_obj_clear_flag(ui_pids, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_pid_ki = lv_textarea_create(ui_pids);
    lv_obj_set_width(ui_pid_ki, 103);
    lv_obj_set_height(ui_pid_ki, LV_SIZE_CONTENT);    /// 24
    lv_obj_set_align(ui_pid_ki, LV_ALIGN_BOTTOM_LEFT);
    lv_textarea_set_max_length(ui_pid_ki, 10);
    lv_textarea_set_text(ui_pid_ki, "0.0");
    lv_textarea_set_placeholder_text(ui_pid_ki, "Placeholder...");
    lv_textarea_set_one_line(ui_pid_ki, true);
    lv_obj_set_style_pad_left(ui_pid_ki, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_pid_ki, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_pid_ki, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_pid_ki, 0, LV_PART_MAIN | LV_STATE_DEFAULT);



    ui_pid_kp = lv_textarea_create(ui_pids);
    lv_obj_set_width(ui_pid_kp, 103);
    lv_obj_set_height(ui_pid_kp, LV_SIZE_CONTENT);    /// 24
    lv_obj_set_align(ui_pid_kp, LV_ALIGN_BOTTOM_MID);
    lv_textarea_set_max_length(ui_pid_kp, 10);
    lv_textarea_set_text(ui_pid_kp, "0.0");
    lv_textarea_set_placeholder_text(ui_pid_kp, "Placeholder...");
    lv_textarea_set_one_line(ui_pid_kp, true);
    lv_obj_set_style_pad_left(ui_pid_kp, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_pid_kp, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_pid_kp, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_pid_kp, 0, LV_PART_MAIN | LV_STATE_DEFAULT);



    ui_pid_kd = lv_textarea_create(ui_pids);
    lv_obj_set_width(ui_pid_kd, 103);
    lv_obj_set_height(ui_pid_kd, LV_SIZE_CONTENT);    /// 24
    lv_obj_set_align(ui_pid_kd, LV_ALIGN_BOTTOM_RIGHT);
    lv_textarea_set_max_length(ui_pid_kd, 10);
    lv_textarea_set_text(ui_pid_kd, "0.0");
    lv_textarea_set_placeholder_text(ui_pid_kd, "Placeholder...");
    lv_textarea_set_one_line(ui_pid_kd, true);
    lv_obj_set_style_pad_left(ui_pid_kd, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_pid_kd, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_pid_kd, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_pid_kd, 0, LV_PART_MAIN | LV_STATE_DEFAULT);



    ui_Label11 = lv_label_create(ui_pids);
    lv_obj_set_width(ui_Label11, 103);
    lv_obj_set_height(ui_Label11, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label11, 0);
    lv_obj_set_y(ui_Label11, 25);
    lv_label_set_text(ui_Label11, "Ki");
    lv_obj_set_style_text_align(ui_Label11, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label12 = lv_label_create(ui_pids);
    lv_obj_set_width(ui_Label12, 103);
    lv_obj_set_height(ui_Label12, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label12, 0);
    lv_obj_set_y(ui_Label12, 25);
    lv_obj_set_align(ui_Label12, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_Label12, "Kp");
    lv_obj_set_style_text_align(ui_Label12, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label13 = lv_label_create(ui_pids);
    lv_obj_set_width(ui_Label13, 103);
    lv_obj_set_height(ui_Label13, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label13, 0);
    lv_obj_set_y(ui_Label13, 25);
    lv_obj_set_align(ui_Label13, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_Label13, "Kd");
    lv_obj_set_style_text_align(ui_Label13, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ku_Container1 = lv_obj_create(ui_pids);
    lv_obj_remove_style_all(ui_ku_Container1);
    lv_obj_set_width(ui_ku_Container1, lv_pct(30));
    lv_obj_set_height(ui_ku_Container1, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_align(ui_ku_Container1, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_ku_Container1, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label20 = lv_label_create(ui_ku_Container1);
    lv_obj_set_width(ui_Label20, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label20, LV_SIZE_CONTENT);    /// 1
    lv_label_set_text(ui_Label20, "ku");

    ui_ku_value = lv_label_create(ui_ku_Container1);
    lv_obj_set_width(ui_ku_value, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ku_value, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ku_value, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_ku_value, "--");

    ui_tu_Container2 = lv_obj_create(ui_pids);
    lv_obj_remove_style_all(ui_tu_Container2);
    lv_obj_set_width(ui_tu_Container2, lv_pct(30));
    lv_obj_set_height(ui_tu_Container2, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_align(ui_tu_Container2, LV_ALIGN_TOP_RIGHT);
    lv_obj_clear_flag(ui_tu_Container2, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label21 = lv_label_create(ui_tu_Container2);
    lv_obj_set_width(ui_Label21, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label21, LV_SIZE_CONTENT);    /// 1
    lv_label_set_text(ui_Label21, "tu");

    ui_tu_value = lv_label_create(ui_tu_Container2);
    lv_obj_set_width(ui_tu_value, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_tu_value, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_tu_value, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_tu_value, "--");

    ui_pidselect = lv_dropdown_create(ui_pids);
    lv_dropdown_set_options(ui_pidselect, "PID basic\nPID less ovsh\nPID no ovsh");
    lv_obj_set_width(ui_pidselect, lv_pct(33));
    lv_obj_set_height(ui_pidselect, LV_SIZE_CONTENT);    /// 25
    lv_obj_add_flag(ui_pidselect, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_pad_left(ui_pidselect, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_pidselect, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_pidselect, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_pidselect, 0, LV_PART_MAIN | LV_STATE_DEFAULT);



    ui_reset_pid_button = lv_btn_create(ui_config);
    lv_obj_set_width(ui_reset_pid_button, 100);
    lv_obj_set_height(ui_reset_pid_button, 34);
    lv_obj_set_align(ui_reset_pid_button, LV_ALIGN_BOTTOM_MID);
    lv_obj_add_flag(ui_reset_pid_button, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_reset_pid_button, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    ui_object_set_themeable_style_property(ui_reset_pid_button, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_COLOR,
                                           _ui_theme_color_button);
    ui_object_set_themeable_style_property(ui_reset_pid_button, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_OPA,
                                           _ui_theme_alpha_button);

    ui_Label14 = lv_label_create(ui_reset_pid_button);
    lv_obj_set_width(ui_Label14, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label14, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label14, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label14, "exit");

    ui_return = lv_btn_create(ui_config);
    lv_obj_set_width(ui_return, 100);
    lv_obj_set_height(ui_return, 34);
    lv_obj_set_align(ui_return, LV_ALIGN_BOTTOM_RIGHT);
    lv_obj_add_flag(ui_return, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_return, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    ui_object_set_themeable_style_property(ui_return, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_COLOR,
                                           _ui_theme_color_button);
    ui_object_set_themeable_style_property(ui_return, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_OPA,
                                           _ui_theme_alpha_button);

    ui_Label15 = lv_label_create(ui_return);
    lv_obj_set_width(ui_Label15, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label15, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label15, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label15, "save and exit");

    ui_reset_pid = lv_btn_create(ui_config);
    lv_obj_set_width(ui_reset_pid, 100);
    lv_obj_set_height(ui_reset_pid, 34);
    lv_obj_set_align(ui_reset_pid, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_add_flag(ui_reset_pid, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_reset_pid, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    ui_object_set_themeable_style_property(ui_reset_pid, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_COLOR,
                                           _ui_theme_color_button);
    ui_object_set_themeable_style_property(ui_reset_pid, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_OPA,
                                           _ui_theme_alpha_button);

    ui_Label16 = lv_label_create(ui_reset_pid);
    lv_obj_set_width(ui_Label16, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label16, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label16, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label16, "reset PID");

    ui_Container5 = lv_obj_create(ui_config);
    lv_obj_remove_style_all(ui_Container5);
    lv_obj_set_height(ui_Container5, 38);
    lv_obj_set_width(ui_Container5, lv_pct(100));
    lv_obj_clear_flag(ui_Container5, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_R25_Ohm = lv_textarea_create(ui_Container5);
    lv_obj_set_width(ui_R25_Ohm, 103);
    lv_obj_set_height(ui_R25_Ohm, LV_SIZE_CONTENT);    /// 24
    lv_obj_set_x(ui_R25_Ohm, 3);
    lv_obj_set_y(ui_R25_Ohm, 3);
    lv_obj_set_align(ui_R25_Ohm, LV_ALIGN_BOTTOM_LEFT);
    lv_textarea_set_max_length(ui_R25_Ohm, 10);
    lv_textarea_set_text(ui_R25_Ohm, "10000");
    lv_textarea_set_placeholder_text(ui_R25_Ohm, "Placeholder...");
    lv_textarea_set_one_line(ui_R25_Ohm, true);
    lv_obj_set_style_pad_left(ui_R25_Ohm, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_R25_Ohm, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_R25_Ohm, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_R25_Ohm, 0, LV_PART_MAIN | LV_STATE_DEFAULT);



    ui_R_div_Ohm = lv_textarea_create(ui_Container5);
    lv_obj_set_width(ui_R_div_Ohm, 103);
    lv_obj_set_height(ui_R_div_Ohm, LV_SIZE_CONTENT);    /// 24
    lv_obj_set_x(ui_R_div_Ohm, 3);
    lv_obj_set_y(ui_R_div_Ohm, 3);
    lv_obj_set_align(ui_R_div_Ohm, LV_ALIGN_BOTTOM_MID);
    lv_textarea_set_max_length(ui_R_div_Ohm, 10);
    lv_textarea_set_text(ui_R_div_Ohm, "10000");
    lv_textarea_set_placeholder_text(ui_R_div_Ohm, "Placeholder...");
    lv_textarea_set_one_line(ui_R_div_Ohm, true);
    lv_obj_set_style_pad_left(ui_R_div_Ohm, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_R_div_Ohm, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_R_div_Ohm, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_R_div_Ohm, 0, LV_PART_MAIN | LV_STATE_DEFAULT);



    ui_beta = lv_textarea_create(ui_Container5);
    lv_obj_set_width(ui_beta, 103);
    lv_obj_set_height(ui_beta, LV_SIZE_CONTENT);    /// 24
    lv_obj_set_x(ui_beta, 3);
    lv_obj_set_y(ui_beta, 3);
    lv_obj_set_align(ui_beta, LV_ALIGN_BOTTOM_RIGHT);
    lv_textarea_set_max_length(ui_beta, 10);
    lv_textarea_set_text(ui_beta, "3950");
    lv_textarea_set_placeholder_text(ui_beta, "Placeholder...");
    lv_textarea_set_one_line(ui_beta, true);
    lv_obj_set_style_pad_left(ui_beta, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_beta, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_beta, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_beta, 0, LV_PART_MAIN | LV_STATE_DEFAULT);



    ui_Label10 = lv_label_create(ui_Container5);
    lv_obj_set_width(ui_Label10, lv_pct(33));
    lv_obj_set_height(ui_Label10, LV_SIZE_CONTENT);    /// 1
    lv_label_set_text(ui_Label10, "R Ohm 25°C ");
    lv_obj_set_style_text_align(ui_Label10, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label22 = lv_label_create(ui_Container5);
    lv_obj_set_width(ui_Label22, lv_pct(33));
    lv_obj_set_height(ui_Label22, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label22, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_Label22, "R div Ohm");
    lv_obj_set_style_text_align(ui_Label22, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label23 = lv_label_create(ui_Container5);
    lv_obj_set_width(ui_Label23, lv_pct(33));
    lv_obj_set_height(ui_Label23, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label23, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_Label23, "Beta");
    lv_obj_add_flag(ui_Label23, LV_OBJ_FLAG_CHECKABLE);     /// Flags
    lv_obj_set_style_text_align(ui_Label23, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Keyboard1 = lv_keyboard_create(ui_config);
    lv_keyboard_set_mode(ui_Keyboard1, LV_KEYBOARD_MODE_NUMBER);
    lv_obj_set_height(ui_Keyboard1, 110);
    lv_obj_set_width(ui_Keyboard1, lv_pct(100));
    lv_obj_set_align(ui_Keyboard1, LV_ALIGN_BOTTOM_MID);
    lv_obj_add_flag(ui_Keyboard1, LV_OBJ_FLAG_HIDDEN);     /// Flags
    ui_object_set_themeable_style_property(ui_Keyboard1, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_COLOR,
                                           _ui_theme_color_button);
    ui_object_set_themeable_style_property(ui_Keyboard1, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_OPA,
                                           _ui_theme_alpha_button);

    ui_version = lv_label_create(ui_config);
    lv_obj_set_width(ui_version, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_version, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_version, -5);
    lv_obj_set_y(ui_version, 74);
    lv_obj_set_align(ui_version, LV_ALIGN_CENTER);
    lv_label_set_text(ui_version, "ver");

    lv_obj_add_event_cb(ui_pid_ki, ui_event_pid_ki, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_pid_kp, ui_event_pid_kp, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_pid_kd, ui_event_pid_kd, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_pidselect, ui_event_pidselect, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_reset_pid_button, ui_event_reset_pid_button, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_return, ui_event_return, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_reset_pid, ui_event_reset_pid, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_R25_Ohm, ui_event_R25_Ohm, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_R_div_Ohm, ui_event_R_div_Ohm, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_beta, ui_event_beta, LV_EVENT_ALL, NULL);
    lv_keyboard_set_textarea(ui_Keyboard1, ui_pid_ki);
    lv_obj_add_event_cb(ui_Keyboard1, ui_event_Keyboard1, LV_EVENT_ALL, NULL);

}
