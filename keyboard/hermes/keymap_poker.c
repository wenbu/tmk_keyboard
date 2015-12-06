#include "keymap_common.h"
#include "action_layer.h"
#include "backlight.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // default dvorak
    KEYMAP(ESC, 1,   2,   3,   4,   5,   FN0, FN1, 6,   7,   8,   9,   0,   EQL,  \
           TAB, QUOT,COMM,DOT, P,   Y,   HOME,PGUP,F,   G,   C,   R,   L,   SLSH, \
           GRV, A,   O,   E,   U,   I,   END, PGDN,D,   H,   T,   N,   S,   MINS, \
           LSFT,SCLN,Q,   J,   K,   X,   DEL, INS, B,   M,   W,   V,   Z,   RSFT, \
           LCTL,LGUI,LALT,FN2,      BSPC,ENT,      SPC,      FN3, RALT,RGUI,RCTL  ),

    // dvorak fn
    // qwerty
    KEYMAP(ESC, 1,   2,   3,   4,   5,   FN4, TRNS,6,   7,   8,   9,   0,   MINS, \
           TAB, Q,   W,   E,   R,   T,   HOME,PGUP,Y,   U,   I,   O,   P,   EQL,  \
           GRV, A,   S,   D,   F,   G,   END, PGDN,H,   J,   K,   L,   SCLN,QUOT, \
           LSFT,Z,   X,   C,   V,   B,   DEL, INS, N,   M,   COMM,DOT, SLSH,RSFT, \
           TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,     TRNS,     TRNS,TRNS,TRNS,TRNS  ),
    // qwerty fn
    // numpad
};

enum function_action {
    QWERTY_ON,
    DVORAK_ON,
    BACKLIGHT_BRIGHTEN,
    BACKLIGHT_DIM
};

void action_function(keyrecord_t* record, uint8_t id, uint8_t opt) {
    switch (id) {
        case QWERTY_ON:
            if (!record->event.pressed) {
                layer_move(1);
                backlight_set(255, 0, 0);
            }
            break;
        case DVORAK_ON:
            if (!record->event.pressed) {
                layer_move(0);
                backlight_set(0, 78, 255);
            }
            break;
        case BACKLIGHT_BRIGHTEN:
            if (record->event.pressed)
                backlight_brighten();
            break;
        case BACKLIGHT_DIM:
            if (record->event.pressed)
                backlight_dim();
            break;
    }
}

const uint16_t PROGMEM fn_actions[] = {
    ACTION_FUNCTION(QWERTY_ON),          //FN0
    ACTION_FUNCTION(BACKLIGHT_DIM),      //FN1
    ACTION_FUNCTION(BACKLIGHT_BRIGHTEN), //FN2; placeholder
    ACTION_FUNCTION(BACKLIGHT_DIM),      //FN3; placeholder
    ACTION_FUNCTION(DVORAK_ON)           //FN4
};