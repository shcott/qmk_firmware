#include QMK_KEYBOARD_H

#define _LY_0 0
#define _LY_1 1
#define _LY_2 2

enum custom_keycodes {
    MC_HEWO = SAFE_RANGE,
    MC_CTLX,
    MC_I,
    MC_J,
    MC_K,
    MC_L
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
		[_LY_0] = LAYOUT_65_ansi_blocker( /* Base */
			KC_GESC,     KC_1,     KC_2,     KC_3,  KC_4,  KC_5,  KC_6,    KC_7,  KC_8,    KC_9,     KC_0,     KC_MINS,  KC_EQL,  KC_BSLASH, KC_GRAVE,\
		    KC_TAB,      KC_Q,     KC_W,     KC_E,  KC_R,  KC_T,  KC_Y,    KC_U,  MC_I,    KC_O,     KC_P,     KC_LBRC,  KC_RBRC, KC_BSPC,   KC_HOME,\
			MC_CTLX,     KC_A,     KC_S,     KC_D,  KC_F,  KC_G,  KC_H,    MC_J,  MC_K,    MC_L,     KC_SCLN,  KC_QUOT,           KC_ENT,    KC_END,\
		    KC_LSFT,     KC_Z,     KC_X,     KC_C,  KC_V,  KC_B,  KC_N,    KC_M,  KC_COMM, KC_DOT,   KC_SLSH,  KC_RSFT,           KC_UP,     MO(_LY_1),\
		    KC_LCTL,     KC_LGUI,  KC_LALT,                   KC_SPC,                      MO(_LY_2),   KC_RCTL,   KC_LEFT,     KC_DOWN,   KC_RIGHT),
		[_LY_1] = LAYOUT_65_ansi_blocker( /* FN 1 */
			RESET,       KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,  KC_TRNS,  KC_TRNS,\
		    KC_TRNS,     RGB_VAD,  RGB_VAI, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_SLCK,  KC_PAUS, KC_TRNS,  KC_PGUP,\
			KC_CAPS,     RGB_RMOD, RGB_MOD, RGB_SPD, RGB_SPI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,          EEP_RST,  KC_PGDN,\
		    KC_TRNS,     RGB_TOG,  RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_MUTE,          KC_VOLU,  KC_TRNS,\
		    KC_TRNS,     KC_TRNS,  KC_TRNS,                   KC_TRNS,                   KC_TRNS,          KC_TRNS,  KC_MPRV,          KC_VOLD,  KC_MNXT),
		[_LY_2] = LAYOUT_65_ansi_blocker( /* FN 2 */
			KC_TRNS,     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_DEL,   KC_TRNS,\
		    KC_TRNS,     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_DEL,   KC_PGUP,\
			KC_TRNS,     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,          KC_PSCR,  KC_PGDN,\
		    KC_TRNS,     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,          KC_TRNS,  KC_TRNS,\
		    KC_TRNS,     KC_TRNS,  KC_TRNS,                   KC_TRNS,                   KC_TRNS,          KC_TRNS,  KC_TRNS,          KC_TRNS,  KC_TRNS),
};

static uint8_t ctlx_tracker = 0;

void matrix_init_user(void) {
    //user initialization
}

void matrix_scan_user(void) {
    //user matrix
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
    case MC_CTLX:
        if(record->event.pressed) {
            ctlx_tracker++;
            register_code(KC_RCTL);
        } else {
            ctlx_tracker--;
            unregister_code(KC_RCTL);
        }
        break;
    case MC_I:
        if(record->event.pressed) {
            if(ctlx_tracker > 0) {
                unregister_code(KC_RCTL);
                SEND_STRING(SS_DOWN(X_UP));
            } else {
                register_code(KC_I);
            }
        } else {
            unregister_code(KC_I);
            SEND_STRING(SS_UP(X_UP));
            if(ctlx_tracker > 0) {
                register_code(KC_RCTL);
            }
        }
        break;
    case MC_J:
        if(record->event.pressed) {
            if(ctlx_tracker > 0) {
                unregister_code(KC_RCTL);
                SEND_STRING(SS_DOWN(X_LEFT));
            } else {
                register_code(KC_J);
            }
        } else {
            unregister_code(KC_J);
            SEND_STRING(SS_UP(X_LEFT));
            if(ctlx_tracker > 0) {
                register_code(KC_RCTL);
            }
        }
        break;
    case MC_K:
        if(record->event.pressed) {
            if(ctlx_tracker > 0) {
                unregister_code(KC_RCTL);
                SEND_STRING(SS_DOWN(X_DOWN));
            } else {
                register_code(KC_K);
            }
        } else {
            unregister_code(KC_K);
            SEND_STRING(SS_UP(X_DOWN));
            if(ctlx_tracker > 0) {
                register_code(KC_RCTL);
            }
        }
        break;
    case MC_L:
        if(record->event.pressed) {
            if(ctlx_tracker > 0) {
                unregister_code(KC_RCTL);
                SEND_STRING(SS_DOWN(X_RIGHT));
            } else {
                register_code(KC_L);
            }
        } else {
            unregister_code(KC_L);
            SEND_STRING(SS_UP(X_RIGHT));
            if(ctlx_tracker > 0) {
                register_code(KC_RCTL);
            }
        }
        break;
    }
    return true;
}
