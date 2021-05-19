#include QMK_KEYBOARD_H

enum layer_names {
    L_COLEMAK,
    L_QWERTY,
    L_SYMBOLS,
    L_FN,
};

#define LAYOUT_split_3x5( \
  L00, L01, L02, L03, L04,           R00, R01, R02, R03, R04, \
  L10, L11, L12, L13, L14,           R10, R11, R12, R13, R14, \
  L20, L21, L22, L23, L24,           R20, R21, R22, R23, R24 \
  ) \
  { \
    { KC_NO, L00, L01, L02, L03, L04 }, \
    { KC_NO, L10, L11, L12, L13, L14 }, \
    { KC_NO, L20, L21, L22, L23, L24 }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { KC_NO, R04, R03, R02, R01, R00 }, \
    { KC_NO, R14, R13, R12, R11, R10 }, \
    { KC_NO, R24, R23, R22, R21, R20 }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
  }

#define LS(K) LSFT_T(KC_##K)
#define LC(K) LCTL_T(KC_##K)
#define LA(K) LALT_T(KC_##K)
#define LG(K) LGUI_T(KC_##K)
#define RS(K) RSFT_T(KC_##K)
#define RC(K) RCTL_T(KC_##K)
#define RA(K) RALT_T(KC_##K)
#define RG(K) RGUI_T(KC_##K)

#define YS(K) LT(L_SYMBOLS,KC_##K)
#define YF(K) LT(L_FN,KC_##K)

#define SW_QWTY TG(L_QWERTY)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_COLEMAK] = LAYOUT_split_3x5(
    KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,     KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,
    LA(A),    LC(R),    LS(S),    YS(T),    YF(G),    YF(M),    YS(N),    RS(E),    RC(I),    RA(O),
    LG(Z),    KC_X,     KC_C,     KC_D,     KC_V,     KC_K,     KC_H,     KC_COMM,  KC_DOT,   RG(SLSH)
  ),
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
    LA(0),    LC(4),    LS(5),    YS(6),    YF(CAPS), SW_QWTY,  YS(F5),   RS(F6),   RC(F7),   RA(F8),
    LG(DOT),  KC_1,     KC_2,     KC_3,     KC_PSCR,  XXXXXXX,  KC_F9,    KC_F10,   KC_F11,   RG(F12)
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
        {0, 0, 0, 0, 0}
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
    rgblight_set_layer_state(RGBLAYER_NUMBERS, layer_state_cmp(state, L_FN));
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
