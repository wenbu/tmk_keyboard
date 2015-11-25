#include <avr/io.h>
#include <avr/interrupt.h>
#include "backlight.h"
#include "print.h"

// G: B3
// R: B2
// B: B1
void backlight_init_ports() {
    //DDRD |= (1<<1);
    DDRB |= (1<<1 | 1<<2 | 1<<3);
}

/* Software PWM
 *  ______           ______           __
 * |  ON  |___OFF___|  ON  |___OFF___|   ....
 * |<-------------->|<-------------->|<- ....
 *     PWM period       PWM period
 *
 * 256              interrupts/period[resolution]
 * 64               periods/second[frequency]
 * 256*64           interrupts/second
 * F_CPU/(256*64)   clocks/interrupt
 */
#define LED_TIMER_TOP F_CPU/(256*128)

void backlight_init_pwm(void)
{
    /* Timer1 setup */
    /* CTC mode */
    // TCCR1B: Timer/Counter Control Register 1B
    // set WGM12 -> CTC (Clear Timer on Compare) mode 4
    // CTC4 -> clear when timer reaches value in OCR1A
    // WGM: Waveform Generation Mode
    TCCR1B |= _BV(WGM12);
    /* Clock select: clk/1 (i.e. no scale) */
    TCCR1B |= _BV(CS10);

    /* Set TOP value */
    uint8_t sreg = SREG;
    cli();
    // OCR1A: Output Compare Register 1A (high/low, 16bit)
    OCR1AH = (LED_TIMER_TOP>>8) & 0xff;
    OCR1AL = LED_TIMER_TOP & 0xff;

    SREG = sreg;

    // set interrupt on compare match
    TIMSK1 |= _BV(OCIE1A);
}

void backlight_set(uint8_t level) {
    level ? backlight_enable() : backlight_disable();
}

bool led_enabled_r = true;
bool led_enabled_g = true;
bool led_enabled_b = true;

void backlight_enable() {
    backlight_enable_r();
    backlight_enable_g();
    backlight_enable_b();
}

void backlight_disable() {
    backlight_disable_r();
    backlight_disable_g();
    backlight_disable_b();
}

void backlight_disable_r() {
    PORTB &= ~(1<<2);
    led_enabled_r = false;
}

void backlight_enable_r() {
    PORTB |= (1<<2);
    led_enabled_r = true;
}

void backlight_disable_g() {
    PORTB &= ~(1<<3);
    led_enabled_g = false;
}

void backlight_enable_g() {
    PORTB |= (1<<3);
    led_enabled_g = true;
}

void backlight_disable_b() {
    PORTB &= ~(1<<1);
    led_enabled_b = false;
}

void backlight_enable_b() {
    PORTB |= (1<<1);
    led_enabled_b = true;
}

uint8_t threshold_lut_index_r = 6;
uint8_t threshold_lut_index_g = 7;
uint8_t threshold_lut_index_b = 8;
//static const uint8_t threshold_lut[9] PROGMEM = { 0, 1, 2, 4, 8, 16, 32, 64, 128 };
static const uint8_t threshold_lut[9] PROGMEM = { 0, 1, 2, 4, 8, 16, 128, 80, 40 };
//static const uint8_t threshold_lut[3] PROGMEM = { 128, 128, 128 };

// TODO: update brighten/dim functions
void backlight_brighten() {
    if (threshold_lut_index_r < 8) {
        threshold_lut_index_r++;
    }
}

void backlight_dim() {
    if (threshold_lut_index_r > 8) {
        threshold_lut_index_r--;
    }
}

// TODO: issue: backlight threshold appears to be reversed
ISR(TIMER1_COMPA_vect)
{
    // interrupt handler for timer set up in init_pwm()
    static struct {
        uint8_t row;
    } timer = { .row = 0 };

    timer.row++;

    if (timer.row == 0 && threshold_lut_index_r > 0 && !led_enabled_r) {
        backlight_enable_r();
    }

    if (timer.row == 0 && threshold_lut_index_g > 0 && !led_enabled_g) {
        backlight_enable_g();
    }

    if (timer.row == 0 && threshold_lut_index_b > 0 && !led_enabled_b) {
        backlight_enable_b();
    }

    if (timer.row >= pgm_read_byte(&threshold_lut[threshold_lut_index_r]) && led_enabled_r) {
        backlight_disable_r();
    }

    if (timer.row >= pgm_read_byte(&threshold_lut[threshold_lut_index_g]) && led_enabled_g) {
        backlight_disable_g();
    }

    if (timer.row >= pgm_read_byte(&threshold_lut[threshold_lut_index_b]) && led_enabled_b) {
        backlight_disable_b();
    }
}
