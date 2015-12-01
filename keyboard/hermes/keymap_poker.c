#include "keymap_common.h"
//#include "backlight.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    KEYMAP(LCTL, LSFT, GRV,  TAB,  ESC, \
           LGUI, SCLN, A,    QUOT, 1,   \
           LALT, Q,    O,    COMM, 2,   \
           FN2,  J,    E,    DOT,  3,   \
                 K,    U,    P,    4,   \
           BSPC, X,    I,    Y,    5,   \
           SPC,  DEL,  END,  HOME, FN0, \
                 INS,  PGDN, PGUP, FN1, \
           ENT,  B,    D,    F,    6,   \
                 M,    H,    G,    7,   \
           FN3,  W,    T,    C,    8,   \
           RALT, V,    N,    R,    9,   \
           RGUI, Z,    S,    L,    0,   \
           RCTL, RSFT, MINS, SLSH, EQL  )
};

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
