#pragma once

#define EE_HANDS

#define OLED_TIMEOUT 300000 // 5 mins
#define OLED_FONT_H "keyboards/crkbd/keymaps/accelbread/font.c"
#define OLED_FONT_START 32
#define OLED_FONT_END 169
#define OLED_FONT_WIDTH 6
#define OLED_FONT_HEIGHT 8

#undef RGBLED_NUM
#define RGBLED_NUM 27
#define RGBLIGHT_LAYERS
#define RGBLIGHT_DISABLE_KEYCODES

#define TAPPING_TERM 400
#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD

#define AUTO_SHIFT_TIMEOUT 200
#define AUTO_SHIFT_REPEAT
#define AUTO_SHIFT_NO_AUTO_REPEAT

#define MK_3_SPEED
#define MK_MOMENTARY_ACCEL
#define MK_C_OFFSET_UNMOD   8
#define MK_C_INTERVAL_UNMOD 8
#define MK_C_OFFSET_0       2
#define MK_C_INTERVAL_0     8
#define MK_C_OFFSET_1       24
#define MK_C_INTERVAL_1     8
#define MK_W_OFFSET_UNMOD   1
#define MK_W_INTERVAL_UNMOD 48
#define MK_W_OFFSET_0       1
#define MK_W_INTERVAL_0     96
#define MK_W_OFFSET_1       1
#define MK_W_INTERVAL_1     24

#define NO_ACTION_ONESHOT
