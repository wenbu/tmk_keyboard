#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // qwerty
    KEYMAP( \
      ESC, F1,  F2,  F3,  F4,  F5,       PSCR,SLCK,BRK,      F6,  F7,  F8,  F9,  F10, F11, F12,  \
      GRV, 1,   2,   3,   4,   5,   6,   INS, HOME,PGUP,     7,   8,   9,   0,   MINS,EQL, BSPC, \
      TAB, Q,   W,   E,   R,   T,        DEL, END, PGDN,Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS, \
      CAPS,A,   S,   D,   F,   G,                            H,   J,   K,   L,   SCLN,QUOT,ENT,  \
      LSFT,Z,   X,   C,   V,   B,             UP,                 N,   M,   COMM,DOT, SLSH,RSFT, \
      LCTL,LGUI,LALT,     SPC,           LEFT,DOWN,RGHT,          SPC,      RALT,RGUI,APP, RCTL)
};

const uint16_t PROGMEM fn_actions[] = {};