// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.2
// LVGL version: 8.3.11
// Project name: sushka_prj

#include "ui.h"

const ui_theme_variable_t _ui_theme_color_button[1] = {0x484681};
const ui_theme_variable_t _ui_theme_alpha_button[1] = {255};

const ui_theme_variable_t _ui_theme_color_bubbttontext[1] = {0xFFFFFF};
const ui_theme_variable_t _ui_theme_alpha_bubbttontext[1] = {255};

const ui_theme_variable_t _ui_theme_color_buttonshadow[1] = {0x161616};
const ui_theme_variable_t _ui_theme_alpha_buttonshadow[1] = {255};

const ui_theme_variable_t _ui_theme_color_drying[1] = {0xDF9E85};
const ui_theme_variable_t _ui_theme_alpha_drying[1] = {255};

const ui_theme_variable_t _ui_theme_color_onoffcircle[1] = {0x4A4483};
const ui_theme_variable_t _ui_theme_alpha_onoffcircle[1] = {255};
uint8_t ui_theme_idx = UI_THEME_DEFAULT;

void ui_theme_set(uint8_t theme_idx)
{
    ui_theme_idx = theme_idx;
    _ui_theme_set_variable_styles(UI_VARIABLE_STYLES_MODE_FOLLOW);
}

