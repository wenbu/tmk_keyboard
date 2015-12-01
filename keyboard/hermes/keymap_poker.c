#include "keymap_common.h"
//#include "backlight.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    KEYMAP(A, 1,    2,    3,   4, 5,    NO,   1,  6,   7, 8,    9,   0,    EQL,  \
           B, QUOT, COMM, DOT, P, Y,    HOME, 2,  F,   G, C,    R,   L,    SLSH, \
           C, A,    O,    E,   U, I,    END,  3,  D,   H, T,    N,   S,    MINS, \
           D, SCLN, Q,    J,   K, X,    DEL,  4,  B,   M, W,    V,   Z,    RSFT, \
           E, LGUI, LALT, NO,     BSPC, SPC,      ENT,    NO,   RALT,RGUI, RCTL )
};

/*
const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    KEYMAP(ESC,  1,    2,    3,   4, 5,    FN0,  FN1,  6,   7, 8,    9,   0,    EQL,  \
           TAB,  QUOT, COMM, DOT, P, Y,    HOME, PGUP, F,   G, C,    R,   L,    SLSH, \
           GRV,  A,    O,    E,   U, I,    END,  PGDN, D,   H, T,    N,   S,    MINS, \
           LSFT, SCLN, Q,    J,   K, X,    DEL,  INS,  B,   M, W,    V,   Z,    RSFT, \
           LCTL, LGUI, LALT, FN2,    BSPC, SPC,        ENT,    FN3, RALT, RGUI, RCTL ),
};
*/

enum backlight_action {
    BACKLIGHT_BRIGHTEN,
    BACKLIGHT_DIM
};

void backlight_brighten(void) {}
void backlight_dim(void) {}

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch (id) {
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
    ACTION_FUNCTION(BACKLIGHT_BRIGHTEN), //FN0
    ACTION_FUNCTION(BACKLIGHT_DIM), //FN1
    ACTION_FUNCTION(BACKLIGHT_BRIGHTEN), //FN2; placeholder
    ACTION_FUNCTION(BACKLIGHT_DIM), //FN3; placeholder
};
