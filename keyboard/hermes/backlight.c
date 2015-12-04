#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "backlight.h"
#include "print.h"
#include "i2c_soft.h"
#include "issi.h"

void backlight_init() {
    issi_init();
}

void backlight_set(color_t level) {
    // TODO
}

void backlight_enable() {
}

void backlight_disable() {
}

void backlight_brighten() {
}

void backlight_dim() {
}