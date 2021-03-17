#include QMK_KEYBOARD_H

enum layer_names {
    L_COLEMAK,
    L_QWERTY,
    L_SYMBOLS,
    L_NUMBERS,
    L_MOUSE
};

#define HRMC_A LGUI_T(KC_A)
#define HRMC_R LALT_T(KC_R)
#define HRMC_S LCTL_T(KC_S)
#define HRMC_T LSFT_T(KC_T)
#define HRMC_N RSFT_T(KC_N)
#define HRMC_E RCTL_T(KC_E)
#define HRMC_I RALT_T(KC_I)
#define HRMC_O RGUI_T(KC_O)

#define HRMQ_A LGUI_T(KC_A)
#define HRMQ_S LALT_T(KC_S)
#define HRMQ_D LCTL_T(KC_D)
#define HRMQ_F LSFT_T(KC_F)
#define HRMQ_J RSFT_T(KC_J)
#define HRMQ_K RCTL_T(KC_K)
#define HRMQ_L RALT_T(KC_L)
#define HRMQ_SN GUI_T(KC_SCLN)

#define HRMS_GV LGUI_T(KC_GRV)
#define HRMS_LB LALT_T(KC_LBRC)
#define HRMS_RB LCTL_T(KC_RBRC)
#define HRMS_MS LSFT_T(KC_MINS)
#define HRMS_DN RSFT_T(KC_DOWN)
#define HRMS_UP RCTL_T(KC_UP)
#define HRMS_RT RALT_T(KC_RIGHT)
#define HRMS_QT GUI_T(KC_QUOT)

#define TMB_0 LT(L_MOUSE,KC_BSPC)
#define TMB_1 LT(L_SYMBOLS,KC_SPC)
#define TMB_2 LT(L_SYMBOLS,KC_ENT)
#define TMB_3 LT(L_NUMBERS,KC_ESC)

#define SW_QWTY TG(L_QWERTY)


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_COLEMAK] = LAYOUT_split_3x5_3(
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
    HRMC_A,  HRMC_R,  HRMC_S,  HRMC_T,  KC_G,    KC_M,    HRMC_N,  HRMC_E,  HRMC_I,  HRMC_O,
    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
    /*       */       XXXXXXX, TMB_0,   TMB_1,   TMB_2,   TMB_3,   XXXXXXX  /*       */
  ),
  [L_QWERTY] = LAYOUT_split_3x5_3(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    HRMQ_A,  HRMQ_S,  HRMQ_D,  HRMQ_F,  KC_G,    KC_H,    HRMQ_J,  HRMQ_K,  HRMQ_L,  HRMQ_SN,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    /*       */       XXXXXXX, TMB_0,   TMB_1,   TMB_2,   TMB_3,   XXXXXXX  /*       */
  ),
  [L_SYMBOLS] = LAYOUT_split_3x5_3(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    HRMS_GV, HRMS_LB, HRMS_RB, HRMS_MS, KC_EQL,  KC_LEFT, HRMS_DN, HRMS_UP, HRMS_RT, HRMS_QT,
    SW_QWTY, XXXXXXX, KC_INS,  KC_CAPS, KC_PSCR, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_BSLS,
    /*       */       XXXXXXX, XXXXXXX, XXXXXXX, KC_TAB,  KC_DEL,  XXXXXXX  /*       */
  ),
  [L_NUMBERS] = LAYOUT_split_3x5_3(
    XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,
    XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    KC_F11,  KC_F11,  KC_F12,  KC_F13,  KC_F14,
    /*       */       XXXXXXX, KC_0,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  /*       */
  ),
  [L_MOUSE] = LAYOUT_split_3x5_3(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX,
    XXXXXXX, KC_BTN3, KC_BTN2, KC_BTN1, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    /*       */       XXXXXXX, XXXXXXX, XXXXXXX, KC_ACL0, KC_ACL1, XXXXXXX  /*       */
  )
};

#define HS_MINT     100, 255
#define HS_AMETHYST 192, 239
#define HS_WHITE    0,   0
#define HS_AQUA     130, 255
#define V_BACKLIGHT 150
#define BACKLIGHT(HS) {6, 21, HS, V_BACKLIGHT}
#define UNDERGLOW(HS) {0, 6, HS, 240}

// Default
const rgblight_segment_t PROGMEM rgblayer_default[] =
    RGBLIGHT_LAYER_SEGMENTS(BACKLIGHT(HS_MINT),
                            UNDERGLOW(HS_MINT));

// Color schemes for programatic usage by using compose/kana led state.
const rgblight_segment_t PROGMEM rgblayer_compose[] =
    RGBLIGHT_LAYER_SEGMENTS(BACKLIGHT(HS_AMETHYST),
                            UNDERGLOW(HS_AMETHYST));

// Layers
const rgblight_segment_t PROGMEM rgblayer_qwerty[] =
    RGBLIGHT_LAYER_SEGMENTS({7, 3, 170, 255, V_BACKLIGHT},
                            {10, 3, 170, 255, V_BACKLIGHT},
                            {15, 9, 170, 255, V_BACKLIGHT});

const rgblight_segment_t PROGMEM rgblayer_symbols[] =
    RGBLIGHT_LAYER_SEGMENTS({0, 0, 0, 0, 0});

const rgblight_segment_t PROGMEM rgblayer_numbers[] =
    RGBLIGHT_LAYER_SEGMENTS(
#ifndef RIGHT
        {7, 11, HS_AQUA, V_BACKLIGHT}
#else
        {0, 0, 0, 0, 0}
#endif
    );

// Indicator leds
const rgblight_segment_t PROGMEM rgblayer_capslock[] =
    RGBLIGHT_LAYER_SEGMENTS({6, 1, HS_WHITE, V_BACKLIGHT});

const rgblight_segment_t PROGMEM rgblayer_numlock[] =
    RGBLIGHT_LAYER_SEGMENTS({13, 1, HS_WHITE, V_BACKLIGHT});

const rgblight_segment_t PROGMEM rgblayer_scrolllock[] =
    RGBLIGHT_LAYER_SEGMENTS({14, 1, HS_WHITE, V_BACKLIGHT});

const rgblight_segment_t *const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgblayer_default,
    rgblayer_compose,
    rgblayer_qwerty,
    rgblayer_symbols,
    rgblayer_numbers,
    rgblayer_numlock,
    rgblayer_scrolllock,
    rgblayer_capslock);

// clang-format on

enum rgb_layer_names {
    RGBLAYER_DEFAULT,
    RGBLAYER_COMPOSE,
    RGBLAYER_QWERTY,
    RGBLAYER_SYMBOLS,
    RGBLAYER_NUMBERS,
    RGBLAYER_NUMLOCK,
    RGBLAYER_SCROLLLOCK,
    RGBLAYER_CAPSLOCK,
};

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
    rgblight_set_layer_state(RGBLAYER_DEFAULT, true);
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(RGBLAYER_CAPSLOCK, led_state.caps_lock);
    rgblight_set_layer_state(RGBLAYER_NUMLOCK, led_state.num_lock);
    rgblight_set_layer_state(RGBLAYER_SCROLLLOCK, led_state.scroll_lock);
    rgblight_set_layer_state(RGBLAYER_COMPOSE, led_state.compose);
    return false;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(RGBLAYER_QWERTY,  layer_state_cmp(state, L_QWERTY));
    rgblight_set_layer_state(RGBLAYER_SYMBOLS, layer_state_cmp(state, L_SYMBOLS));
    rgblight_set_layer_state(RGBLAYER_NUMBERS, layer_state_cmp(state, L_NUMBERS));
    return state;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

#ifndef RIGHT
const char PROGMEM colemak_str[] =
                      "QWFPB"
                      "ARSTG"
                      "ZXCDV"
                      "  \x92\x80\x8C"
                      ;
const char PROGMEM qwerty_str[] =
                      "QWERT"
                      "ASDFG"
                      "ZXCVB"
                      "  \x92\x80\x8C"
                      ;

const char PROGMEM symbols_str[] =
                      "!@#$%"
                      "`[]-="
                      "   \x94\x93"
                      "     "
                      ;

const char PROGMEM numbers_str[] =
                      " \x9B\x9C\x9D\x9E"
                      " \x9F\xA0\xA1\xA2"
                      " \xA3\xA4\xA5\xA6"
                      "     "
                      ;

#else
const char PROGMEM colemak_str[] =
                      "JLUY;"
                      "MNEIO"
                      "KH,./"
                      "\x8D\x82\x7F"
                      ;
const char PROGMEM qwerty_str[] =
                      "YUIOP"
                      "HJKL;"
                      "NM,./"
                      "\x8D\x82\x7F"
                      ;

const char PROGMEM symbols_str[] =
                      "^&*()"
                      "\x84\x85\x86\x87'"
                      "\x8A\x89\x88\x8B\\"
                      " \x83\xA9  "
                      ;

const char PROGMEM numbers_str[] =
                      "789AB"
                      "456CD"
                      "123EF"
                      " 0.  "
                      ;
#endif

void oled_task_user(void) {
    if (rgblight_get_layer_state(RGBLAYER_NUMBERS)){
        oled_write_P(numbers_str, false);
    } else
    if (rgblight_get_layer_state(RGBLAYER_SYMBOLS)){
        oled_write_P(symbols_str, false);
    } else
    if (rgblight_get_layer_state(RGBLAYER_QWERTY)){
        oled_write_P(qwerty_str, false);
    } else {
        oled_write_P(colemak_str, false);
    }
}
