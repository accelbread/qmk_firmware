#include QMK_KEYBOARD_H

#include <stdbool.h>
#include <stdint.h>

enum layer_names {
    L_QWERTY,
    L_SYMBOLS,
    L_FN,
};

#define LAYOUT_split_3x5(L00, L01, L02, L03, L04, R00, R01, R02, R03, R04,     \
                         L10, L11, L12, L13, L14, R10, R11, R12, R13, R14,     \
                         L20, L21, L22, L23, L24, R20, R21, R22, R23, R24)     \
    {                                                                          \
        {KC_NO, L00, L01, L02, L03, L04}, {KC_NO, L10, L11, L12, L13, L14},    \
            {KC_NO, L20, L21, L22, L23, L24},                                  \
            {KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO},                        \
            {KC_NO, R04, R03, R02, R01, R00},                                  \
            {KC_NO, R14, R13, R12, R11, R10},                                  \
            {KC_NO, R24, R23, R22, R21, R20},                                  \
            {KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO},                        \
    }

#define LS(K) LSFT_T(KC_##K)
#define LC(K) LCTL_T(KC_##K)
#define LA(K) LALT_T(KC_##K)
#define LG(K) LGUI_T(KC_##K)
#define RS(K) RSFT_T(KC_##K)
#define RC(K) RCTL_T(KC_##K)
#define RA(K) RALT_T(KC_##K)
#define RG(K) RGUI_T(KC_##K)

#define YS(K) LT(L_SYMBOLS, KC_##K)
#define YF(K) LT(L_FN, KC_##K)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_QWERTY] = LAYOUT_split_3x5(
    KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
    LA(A),    LC(S),    LS(D),    YS(F),    YF(G),    YF(H),    YS(J),    RS(K),    RC(L),    RA(SCLN),
    LG(Z),    KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   RG(SLSH)
  ),
  [L_SYMBOLS] = LAYOUT_split_3x5(
    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
    LA(TAB),  LC(ENT),  LS(BSPC), YS(SPC),  YF(ESC),  YF(LEFT), YS(DOWN), RS(UP),   RC(RGHT), RA(QUOT),
    LG(GRV),  KC_LBRC,  KC_RBRC,  KC_MINS,  KC_EQL,   KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   RG(BSLS)
  ),
  [L_FN] = LAYOUT_split_3x5(
    KC_COMM,  KC_7,     KC_8,     KC_9,     KC_DEL,   KC_INS,   KC_F1,    KC_F2,    KC_F3,    KC_F4,
    LA(0),    LC(4),    LS(5),    YS(6),    YF(CAPS), XXXXXXX,  YS(F5),   RS(F6),   RC(F7),   RA(F8),
    LG(DOT),  KC_1,     KC_2,     KC_3,     KC_PSCR,  XXXXXXX,  KC_F9,    KC_F10,   KC_F11,   RG(F12)
  )
};

#define COLOR_AMETHYST  192, 239, 80
#define COLOR_WHITE     0,   0,   100
#define COLOR_AQUA      130, 255, 50
#define COLOR_UNDERGLOW 192, 239, 0

#define MAIN(COLOR)      {7,  6,  COLOR},                                      \
                         {15, 12, COLOR},                                      \
                         {34, 6,  COLOR},                                      \
                         {42, 12, COLOR}
#define SIDES(COLOR)     {6,  1,  COLOR},                                      \
                         {13, 2,  COLOR},                                      \
                         {24, 3,  COLOR},                                      \
                         {33, 1,  COLOR},                                      \
                         {40, 2,  COLOR},                                      \
                         {52, 3,  COLOR}
#define UNDERGLOW(COLOR) {0,  6,  COLOR},                                      \
                         {27, 6,  COLOR}

// Default
const rgblight_segment_t PROGMEM rgblayer_default[] =
    RGBLIGHT_LAYER_SEGMENTS(MAIN(COLOR_AMETHYST),
                            SIDES(COLOR_AQUA),
                            UNDERGLOW(COLOR_UNDERGLOW));

// Layers
const rgblight_segment_t PROGMEM rgblayer_symbols[] =
    RGBLIGHT_LAYER_SEGMENTS({0, 0, 0, 0, 0});

const rgblight_segment_t PROGMEM rgblayer_fn[] =
    RGBLIGHT_LAYER_SEGMENTS({0, 0, 0, 0, 0});

// Indicator leds
const rgblight_segment_t PROGMEM rgblayer_capslock[] =
    RGBLIGHT_LAYER_SEGMENTS({6, 1, COLOR_WHITE},
                            {33, 1, COLOR_WHITE});

const rgblight_segment_t PROGMEM rgblayer_numlock[] =
    RGBLIGHT_LAYER_SEGMENTS({13, 1, COLOR_WHITE},
                            {40, 1, COLOR_WHITE});

const rgblight_segment_t PROGMEM rgblayer_scrolllock[] =
    RGBLIGHT_LAYER_SEGMENTS({14, 1, COLOR_WHITE},
                            {41, 1, COLOR_WHITE});

const rgblight_segment_t *const PROGMEM my_rgb_layers[] =
    RGBLIGHT_LAYERS_LIST(rgblayer_default,
                         rgblayer_symbols,
                         rgblayer_fn,
                         rgblayer_numlock,
                         rgblayer_scrolllock,
                         rgblayer_capslock);

enum rgb_layer_names {
    RGBLAYER_DEFAULT,
    RGBLAYER_SYMBOLS,
    RGBLAYER_FN,
    RGBLAYER_NUMLOCK,
    RGBLAYER_SCROLLLOCK,
    RGBLAYER_CAPSLOCK,
};

// clang-format on

static uint16_t sleep_timer = 0;
static bool is_sleep = false;

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
    rgblight_set_layer_state(RGBLAYER_DEFAULT, true);
    sleep_timer = timer_read() + 30000;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(RGBLAYER_CAPSLOCK, led_state.caps_lock);
    rgblight_set_layer_state(RGBLAYER_NUMLOCK, led_state.num_lock);
    rgblight_set_layer_state(RGBLAYER_SCROLLLOCK, led_state.scroll_lock);
    return false;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(RGBLAYER_SYMBOLS,
                             layer_state_cmp(state, L_SYMBOLS));
    rgblight_set_layer_state(RGBLAYER_FN, layer_state_cmp(state, L_FN));
    return state;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

#define SKIP_4                                                                 \
    "     "                                                                    \
    "     "                                                                    \
    "     "                                                                    \
    "     "

const char PROGMEM qwerty_str_l[] = SKIP_4 "QWERT"
                                           "ASDFG"
                                           "ZXCVB";

const char PROGMEM qwerty_str_r[] = SKIP_4 "YUIOP"
                                           "HJKL;"
                                           "NM,./";

const char PROGMEM symbols_str_l[] = SKIP_4 "!@#$%"
                                            "\x80\x8D\x82\x8C\x7F"
                                            "`[]-=";

const char PROGMEM symbols_str_r[] = SKIP_4 "^&*()"
                                            "\x84\x85\x86\x87'"
                                            "\x8A\x89\x88\x8B\\";

const char PROGMEM fn_str_l[] = SKIP_4 ".789\x83"
                                       "0456\x92"
                                       ".123\x93";

const char PROGMEM fn_str_r[] = SKIP_4 "\x94\x9B\x9C\x9D\x9E"
                                       " \x9F\xA0\xA1\xA2"
                                       " \xA3\xA4\xA5\xA6";

bool oled_task_user(void) {
    bool left = is_keyboard_left();
    if (rgblight_get_layer_state(RGBLAYER_FN)) {
        oled_write_P(left ? fn_str_l : fn_str_r, false);
    } else if (rgblight_get_layer_state(RGBLAYER_SYMBOLS)) {
        oled_write_P(left ? symbols_str_l : symbols_str_r, false);
    } else {
        oled_write_P(left ? qwerty_str_l : qwerty_str_r, false);
    }
    return false;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        sleep_timer = timer_read() + 30000;
    };
    if (is_sleep) {
        is_sleep = false;
        rgblight_wakeup();
    }
}

void housekeeping_task_user(void) {
    if (!is_sleep && timer_expired(timer_read(), sleep_timer)) {
        is_sleep = true;
        rgblight_suspend();
    }
}
