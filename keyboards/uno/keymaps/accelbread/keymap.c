#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[0] = LAYOUT(KC_A)};

#define MINT 100, 255, 255
#define AMETHYST 192, 239, 255

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool state = true;

    switch (keycode) {
        case KC_A:
            if (record->event.pressed) {
                state = !state;
                register_code16(KC_LALT);
                register_code16(KC_LSFT);
                register_code16(KC_GRV);
                register_code16(state ? KC_1 : KC_2);
                unregister_code16(state ? KC_1 : KC_2);
                unregister_code16(KC_GRV);
                unregister_code16(KC_LSFT);
                unregister_code16(KC_LALT);
                if (state) {
                    rgblight_sethsv_noeeprom(AMETHYST);
                } else {
                    rgblight_sethsv_noeeprom(MINT);
                }
            }
    }
    return false;
}

void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    rgblight_mode(1);
    rgblight_sethsv_noeeprom(AMETHYST);
}
