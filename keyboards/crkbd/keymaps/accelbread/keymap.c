#include QMK_KEYBOARD_H

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,            KC_T,         KC_Y,           KC_U,    KC_I,    KC_O,     KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,            KC_G,         KC_H,           KC_J,    KC_K,    KC_L,     KC_SCLN, KC_QUOT,
    KC_GRV,  KC_Z,    KC_X,    KC_C,    KC_V,            KC_B,         KC_N,           KC_M,    KC_COMM, KC_DOT,   KC_SLSH, KC_BSLS,
    /*       ,        */       MO(2),   LSFT_T(KC_CAPS), LT(1,KC_SPC), LCTL_T(KC_ENT), KC_LALT, KC_LCMD  /*        ,        */
  ),
  [1] = LAYOUT_split_3x6_3(
    XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,            KC_5,         KC_6,           KC_7,    KC_8,    KC_9,     KC_0,    KC_DEL,
    XXXXXXX, KC_PSCR, KC_HOME, KC_PGUP, KC_PGDN,         KC_END,       KC_LEFT,        KC_DOWN, KC_UP,   KC_RIGHT, KC_MINS, KC_EQUAL,
    XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, KC_MINS,         KC_EQUAL,     KC_LBRC,        KC_RBRC, KC_MUTE, KC_VOLD,  KC_VOLU, KC_INS,
    /*       ,        */       XXXXXXX, KC_RSFT,         _______,      RCTL_T(KC_ENT), KC_RALT, KC_RCMD  /*        ,        */
  ),
  [2] = LAYOUT_split_3x6_3(
    XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,           XXXXXXX,      XXXXXXX,        KC_7,    KC_8,    KC_9,     S(KC_A), S(KC_B),
    XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,           XXXXXXX,      XXXXXXX,        KC_4,    KC_5,    KC_6,     S(KC_C), S(KC_D),
    XXXXXXX, KC_F9,   KC_F10,  KC_F11,  KC_F12,          XXXXXXX,      XXXXXXX,        KC_1,    KC_2,    KC_3,     S(KC_E), S(KC_F),
    /*       ,        */       _______, XXXXXXX,         RESET,        XXXXXXX,        KC_0,    KC_DOT   /*        ,        */
  )
};

#define HS_MINT     100, 255
#define HS_AMETHYST 192, 239
#define HS_WHITE    0,   0
#define HS_AQUA     130, 255
#define V_BACKLIGHT 120
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

const rgblight_segment_t PROGMEM rgblayer_kana[] =
    RGBLIGHT_LAYER_SEGMENTS(BACKLIGHT(HS_AQUA),
                            UNDERGLOW(HS_AQUA));

// Layers
const rgblight_segment_t PROGMEM rgblayer_layer1[] =
    RGBLIGHT_LAYER_SEGMENTS({0, 0, 0, 0, 0});

const rgblight_segment_t PROGMEM rgblayer_layer2[] =
    RGBLIGHT_LAYER_SEGMENTS(
#ifndef RIGHT
        {0, 0, 0, 0, 0}
#else
        {10, 11, HS_AQUA, V_BACKLIGHT}
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
    rgblayer_kana,
    rgblayer_layer1,
    rgblayer_layer2,
    rgblayer_numlock,
    rgblayer_scrolllock,
    rgblayer_capslock);

// clang-format on

enum rgb_layer_names {
    RGBLAYER_DEFAULT,
    RGBLAYER_COMPOSE,
    RGBLAYER_KANA,
    RGBLAYER_LAYER1,
    RGBLAYER_LAYER2,
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
    rgblight_set_layer_state(RGBLAYER_KANA, led_state.kana);
    return false;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(RGBLAYER_LAYER1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(RGBLAYER_LAYER2, layer_state_cmp(state, 2));
    return state;
}

void suspend_power_down_user(void) { rgblight_disable_noeeprom(); }

void suspend_wakeup_init_user(void) { rgblight_enable_noeeprom(); }

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_0;
}

void oled_task_user(void) {
    static const char PROGMEM lscrn[] = {
    // clang-format off
#ifndef RIGHT
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x08, 0x00, 0x28, 0x50, 0x00, 0x00,
        0x10, 0x78, 0x10, 0x20, 0x78, 0x20, 0x00, 0x00, 0x00, 0x00, 0x78, 0x48, 0x50, 0x68, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x49, 0x00, 0x21, 0x21, 0x21, 0x63, 0x21, 0xe7, 0x00, 0xc5, 0x00, 0x21, 0x21,
        0x21, 0x63, 0x21, 0xe7, 0x00, 0x41, 0x00, 0x21, 0x21, 0x63, 0x21, 0xe7, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x40, 0xca, 0xcf, 0xca, 0x40, 0x00, 0x00, 0x00, 0x00, 0x2f, 0xaf, 0x69, 0xe9,
        0x0e, 0x00, 0x00, 0x00, 0xef, 0x44, 0x84, 0x04, 0x05, 0x26, 0xc4, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0xc2, 0x20, 0xe2, 0x62, 0xa2, 0x22, 0xc2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 0x21, 0xa2, 0xc2, 0x44, 0x28, 0x2f, 0x00, 0x00,
        0xe9, 0x09, 0x09, 0xcf, 0x29, 0x29, 0xc6, 0x00, 0x00, 0x2a, 0xe5, 0xab, 0x29, 0x29, 0x29, 0x26,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x2d, 0x00, 0x84, 0x84, 0x84, 0x8c, 0x84, 0x9c, 0x00, 0x1c, 0x00, 0x84, 0x84,
        0x84, 0x8c, 0x84, 0x9c, 0x00, 0x0c, 0x00, 0x84, 0x84, 0x8c, 0x84, 0x9c, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x80, 0x80, 0x14, 0x3d, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x99, 0xa4, 0xa4, 0xa5,
        0x3c, 0x00, 0x00, 0x00, 0x19, 0x24, 0x20, 0x99, 0xa1, 0xa5, 0x98, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x29, 0x28, 0x3d, 0x29, 0xbd, 0x29, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00,
        0x00, 0x00, 0x2c, 0x84, 0x24, 0x00, 0x00, 0x19, 0x25, 0x84, 0x84, 0x85, 0xa5, 0x99, 0x00, 0x00,
        0x9c, 0xa5, 0xa5, 0xa4, 0xa4, 0xa4, 0x9d, 0x00, 0x00, 0xbd, 0x85, 0x85, 0x9d, 0x85, 0x85, 0xbd,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x03, 0x00, 0x04, 0x00, 0x00, 0x00,
        0x00, 0x01, 0x00, 0x03, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x07, 0x04, 0x20, 0xf0, 0xa0, 0x80, 0x00, 0x00, 0x00, 0x00, 0xf7, 0xc4, 0xa4, 0x94,
        0x03, 0x00, 0x00, 0x00, 0x74, 0x84, 0x84, 0x77, 0x14, 0x14, 0xf4, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x02, 0x97, 0x26, 0x43, 0x92, 0x07, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf1, 0x91,
        0x01, 0x01, 0x31, 0x13, 0x91, 0x00, 0x00, 0x71, 0x93, 0x94, 0x74, 0x94, 0x94, 0x74, 0x00, 0x00,
        0x60, 0x90, 0x90, 0xd3, 0x10, 0x90, 0x67, 0x00, 0x00, 0x44, 0x44, 0x42, 0x43, 0x44, 0x44, 0xf3,
#else
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x58, 0x48, 0x48, 0x48, 0x48, 0x48, 0x58, 0x00, 0x00, 0x00, 0x00, 0x20, 0x10, 0x20,
        0x00, 0x00, 0x00, 0x00, 0x30, 0x48, 0x48, 0x38, 0x08, 0x48, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x28, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x78,
        0x50, 0x40, 0x00, 0x28, 0x10, 0x00, 0x00, 0x48, 0x68, 0x68, 0x58, 0x58, 0x58, 0x48, 0x00, 0x00,
        0x48, 0x48, 0x48, 0x78, 0x48, 0x48, 0x48, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x50, 0x48, 0x48,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0xef, 0x44, 0x84, 0x04, 0x05, 0x26, 0xc4, 0x00, 0x00, 0xe8, 0x08, 0x08, 0xef,
        0x29, 0x29, 0xe9, 0x00, 0x00, 0xc2, 0x22, 0x24, 0xc4, 0x24, 0x28, 0xcf, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x4b, 0x6a, 0x6a, 0x4a, 0xaa, 0x4a, 0xab, 0x00, 0x00, 0x00, 0x00, 0x02, 0xa5, 0x40,
        0x00, 0x00, 0x00, 0x00, 0xc2, 0x22, 0x24, 0xc4, 0x24, 0x28, 0xcf, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x0a, 0x0d, 0x05, 0x0a, 0xa5, 0x49, 0xa6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xcd, 0xe2, 0xec, 0xc0, 0x00, 0x00, 0x00, 0x29, 0x29, 0x09, 0x89, 0x0d, 0x0f, 0x09, 0x00, 0x00,
        0x26, 0x29, 0xa8, 0x68, 0xa8, 0x28, 0x28, 0x00, 0x00, 0xef, 0x89, 0x89, 0x89, 0x89, 0x89, 0xe9,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x99, 0xa4, 0xa0, 0x99, 0xa1, 0xa5, 0x98, 0x00, 0x00, 0x18, 0xa5, 0xa5, 0x9c,
        0x84, 0xa4, 0x19, 0x00, 0x00, 0xa0, 0xa1, 0xa1, 0xb8, 0xa5, 0xa5, 0x18, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x29, 0xad, 0xad, 0x29, 0x10, 0x08, 0x10, 0x00, 0x00, 0x00, 0x00, 0x08, 0x90, 0x08,
        0x00, 0x00, 0x00, 0x00, 0x20, 0xa1, 0xa1, 0xb8, 0xa5, 0xa5, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x10, 0x08, 0x08, 0x08, 0x08, 0x08, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x84, 0x80, 0x91, 0xa0, 0x91, 0x80, 0x80, 0x00, 0x00,
        0xbd, 0x85, 0x04, 0x04, 0x84, 0x05, 0x05, 0x00, 0x00, 0x99, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0x99,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x17, 0x10, 0x10, 0x73, 0x10, 0x10, 0xf7, 0x00, 0x00, 0x73, 0x94, 0x90, 0x90,
        0x90, 0x94, 0x73, 0x00, 0x00, 0x74, 0x94, 0x94, 0x77, 0x94, 0x94, 0x73, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x25, 0x55, 0x05, 0xb5, 0x52, 0x44, 0x72, 0x00, 0x00, 0x76, 0x00, 0x70, 0x01, 0x40,
        0xe0, 0x40, 0x00, 0x00, 0x03, 0x04, 0x74, 0xf6, 0x75, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa2, 0xa0, 0xa2, 0x12, 0x94, 0x94, 0x96, 0x00, 0x00,
        0x00, 0x02, 0x00, 0x00, 0x02, 0xd0, 0xd0, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf3, 0xe4, 0x04, 0x03
     #endif
        // clang-format on
    };

    oled_write_raw_P(lscrn, sizeof(lscrn));
}
