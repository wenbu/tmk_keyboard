#include "keymap_common.h"
#include "action_layer.h"
#include "backlight.h"

#define KC_DVQW KC_FN0
#define KC_LCBR KC_FN1
#define KC_RCBR KC_FN2
#define KC_DVFN KC_FN3
#define KC_QWFN KC_FN4
#define KC_PIPE KC_FN5

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // default dvorak
    KEYMAP(ESC, 1,   2,   3,   4,   5,   DVQW,FN6, 6,   7,   8,   9,   0,   EQL,  \
           TAB, QUOT,COMM,DOT, P,   Y,   DEL, INS, F,   G,   C,   R,   L,   SLSH, \
           GRV, A,   O,   E,   U,   I,   HOME,PGUP,D,   H,   T,   N,   S,   MINS, \
           LSFT,SCLN,Q,   J,   K,   X,   END, PGDN,B,   M,   W,   V,   Z,   RSFT, \
           LCTL,LGUI,LALT,DVFN,     BSPC,ENT,      SPC,      DVFN,RALT,RGUI,RCTL  ),

    // dvorak fn
    KEYMAP(NO,  F1,  F2,  F3,  F4,  F5,  NO,  NO,  F6,  F7,  F8,  F9,  F10, NO,   \
           NO,  NO,  NO,  UP,  NO,  NO,  NO,  NO,  NO,  NO,  EQL, LBRC,RBRC,BSLS, \
           NO,  NO,  LEFT,DOWN,RGHT,NO,  NO,  NO,  NO,  NO,  NO,  LCBR,RCBR,PIPE, \
           TRNS,NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  TRNS, \
           TRNS,TRNS,TRNS,DVFN,     TRNS,TRNS,     TRNS,     DVFN,TRNS,TRNS,TRNS  ),

    // qwerty
    KEYMAP(ESC, 1,   2,   3,   4,   5,   DVQW,TRNS,6,   7,   8,   9,   0,   MINS, \
           TAB, Q,   W,   E,   R,   T,   DEL, INS, Y,   U,   I,   O,   P,   EQL,  \
           GRV, A,   S,   D,   F,   G,   HOME,PGUP,H,   J,   K,   L,   SCLN,QUOT, \
           LSFT,Z,   X,   C,   V,   B,   END, PGDN,N,   M,   COMM,DOT, SLSH,RSFT, \
           TRNS,TRNS,TRNS,QWFN,     TRNS,TRNS,     TRNS,     QWFN,TRNS,TRNS,TRNS  ),

    // qwerty fn
    KEYMAP(NO,  F1,  F2,  F3,  F4,  F5,  NO,  NO,  F6,  F7,  F8,  F9,  F10, NO,   \
           NO,  NO,  NO,  UP,  NO,  NO,  NO,  NO,  NO,  NO,  EQL, LBRC,RBRC,BSLS, \
           NO,  NO,  LEFT,DOWN,RGHT,NO,  NO,  NO,  NO,  NO,  NO,  LCBR,RCBR,PIPE, \
           TRNS,NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  TRNS, \
           TRNS,TRNS,TRNS,QWFN,     TRNS,TRNS,     TRNS,     QWFN,TRNS,TRNS,TRNS  ),

    // numpad
    // TODO
};

enum function_action {
    BACKLIGHT_BRIGHTNESS
};

void action_function(keyrecord_t* record, uint8_t id, uint8_t opt) {
    switch (id) {
        case BACKLIGHT_BRIGHTNESS:
            if (record->event.pressed)
                backlight_adjust();
            break;
    }
}

const uint16_t PROGMEM fn_actions[] = {
    ACTION_LAYER_TOGGLE(2),              // toggle qwerty
    ACTION_MODS_KEY(MOD_LSFT, KC_LBRC),  // left curly brace '{'
    ACTION_MODS_KEY(MOD_LSFT, KC_RBRC),  // right curly brace '}'
    ACTION_LAYER_MOMENTARY(1),           // fn layer for dvorak
    ACTION_LAYER_MOMENTARY(3),           // fn layer for qwerty
    ACTION_MODS_KEY(MOD_LSFT, KC_BSLS),  // pipe '|'
    ACTION_FUNCTION(BACKLIGHT_BRIGHTNESS)// light brightness
};