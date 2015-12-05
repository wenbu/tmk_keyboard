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

void backlight_set(uint8_t r, uint8_t g, uint8_t b) {
    //print("Setting color to ("); phex(r); print(" "); phex(g); print(" "); phex(b); print(")\n");

    uint8_t rData[9] = { DEVICE_ADDRESS_WRITE, 0x34, r, r, r, r, r, r, r };
    uint8_t gData[9] = { DEVICE_ADDRESS_WRITE, 0x44, g, g, g, g, g, g, g };
    uint8_t bData[9] = { DEVICE_ADDRESS_WRITE, 0x24, b, b, b, b, b, b, b };

    issi_send_data(rData, sizeof(rData), 0);
    issi_send_data(gData, sizeof(gData), 0);
    issi_send_data(bData, sizeof(bData), 0);
}

void backlight_enable() {
}

void backlight_disable() {
}

void backlight_brighten() {
}

void backlight_dim() {
}