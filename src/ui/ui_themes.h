// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.2
// LVGL version: 8.3.11
// Project name: sushka_prj

#ifndef _UI_THEMES_H
#define _UI_THEMES_H

#ifdef __cplusplus
extern "C" {
#endif

#define UI_THEME_COLOR_BUTTON 0
#define UI_THEME_COLOR_BUBBTTONTEXT 1
#define UI_THEME_COLOR_BUTTONSHADOW 2
#define UI_THEME_COLOR_DRYING 3
#define UI_THEME_COLOR_ONOFFCIRCLE 4

#define UI_THEME_DEFAULT 0

extern const ui_theme_variable_t _ui_theme_color_button[1];
extern const ui_theme_variable_t _ui_theme_alpha_button[1];

extern const ui_theme_variable_t _ui_theme_color_bubbttontext[1];
extern const ui_theme_variable_t _ui_theme_alpha_bubbttontext[1];

extern const ui_theme_variable_t _ui_theme_color_buttonshadow[1];
extern const ui_theme_variable_t _ui_theme_alpha_buttonshadow[1];

extern const ui_theme_variable_t _ui_theme_color_drying[1];
extern const ui_theme_variable_t _ui_theme_alpha_drying[1];

extern const ui_theme_variable_t _ui_theme_color_onoffcircle[1];
extern const ui_theme_variable_t _ui_theme_alpha_onoffcircle[1];

extern const uint32_t * ui_theme_colors[1];
extern const uint8_t * ui_theme_alphas[1];
extern uint8_t ui_theme_idx;

void ui_theme_set(uint8_t theme_idx);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
