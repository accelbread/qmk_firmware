#pragma once

#define EE_HANDS
#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
#undef  RGBLED_NUM
#define RGBLED_NUM 27
#define RGBLIGHT_LAYERS
#define RGBLIGHT_SLEEP
#define RGBLIGHT_DISABLE_KEYCODES
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD
#define NO_ACTION_ONESHOT
#define AUTO_SHIFT_TIMEOUT 200
#define AUTO_SHIFT_REPEAT
#define AUTO_SHIFT_NO_AUTO_REPEAT
#define OLED_TIMEOUT 300000 //5 mins
