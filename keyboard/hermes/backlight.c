#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "backlight.h"
#include "print.h"
#include "i2c_soft.h"
#include "issi.h"

struct color_t {
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

struct backlight_state_t {
    struct color_t color[7];
    uint8_t brightness;
    uint8_t dirty;
};

static struct backlight_state_t backlight_state = { .brightness = 1 };
static uint8_t brightness_lut[BACKLIGHT_LEVELS + 1];
static const uint8_t gamma_lut[32] PROGMEM = { 0, 1, 2, 4, 6, 10, 13, 18, 22, 28, 33, 39, 46, 53, 61, 69, 78, 86, 96, 106, 116, 126, 138, 149, 161, 173, 186, 199, 212, 226, 240, 255 };

void backlight_init() {
    issi_init();

    for (uint8_t i = 0; i < BACKLIGHT_LEVELS + 1; i++) {
        brightness_lut[i] = i * 255 / BACKLIGHT_LEVELS;
    }
}

static void backlight_refresh() {
    uint8_t brightnessFactor = pgm_read_byte( &gamma_lut[brightness_lut[backlight_state.brightness] / 8] );

    uint8_t rData[9];
    uint8_t gData[9];
    uint8_t bData[9];

    for (int i = 0; i < 7; i++) {
        rData[i+2] = backlight_state.color[i].r * brightnessFactor / 255;
        gData[i+2] = backlight_state.color[i].g * brightnessFactor / 255;
        bData[i+2] = backlight_state.color[i].b * brightnessFactor / 255;
    }
    rData[0] = DEVICE_ADDRESS_WRITE;
    gData[0] = DEVICE_ADDRESS_WRITE;
    bData[0] = DEVICE_ADDRESS_WRITE;
    rData[1] = 0x34;
    gData[1] = 0x44;
    bData[1] = 0x24;

    issi_send_data(rData, sizeof(rData), 0);
    issi_send_data(gData, sizeof(gData), 0);
    issi_send_data(bData, sizeof(bData), 0);
}

void backlight_set(uint8_t r, uint8_t g, uint8_t b) {
    for (int i = 0; i < 7; i++) {
        backlight_state.color[i].r = r;
        backlight_state.color[i].g = g;
        backlight_state.color[i].b = b;
    }
    backlight_refresh();
}

// TODO would be nice to be able to set colors with a color_t[] instead
// of three uint8_t[]
void backlight_set_array(uint8_t* r, uint8_t* g, uint8_t* b) {
    // assume each array is of size 7
    for (int i = 0; i < 7; i++) {
        backlight_state.color[i].r = r[i];
        backlight_state.color[i].g = g[i];
        backlight_state.color[i].b = b[i];
    }
    backlight_refresh();
}

void backlight_adjust() {
    backlight_state.brightness = (backlight_state.brightness + 1) % (BACKLIGHT_LEVELS + 1);

    backlight_refresh();
}
