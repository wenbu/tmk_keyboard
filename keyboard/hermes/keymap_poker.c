#include "keymap_common.h"
#include "backlight.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    KEYMAP(1, 2, FN0, \
           4, 5, FN1, \
           7, 8, 9),	   
};

enum backlight_action {
    BACKLIGHT_BRIGHTEN,
    BACKLIGHT_DIM
};

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
};
