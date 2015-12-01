/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef KEYMAP_COMMON_H
#define KEYMAP_COMMON_H

#include <stdint.h>
#include <stdbool.h>
#include <avr/pgmspace.h>
#include "keycode.h"
#include "action.h"
#include "action_macro.h"
#include "report.h"
#include "host.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"


extern const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS];
extern const uint16_t fn_actions[];

#define KEYMAP( \
    K00, K01, K02, K03, K04, \
    K10, K11, K12, K13, K14, \
    K20, K21, K22, K23, K24, \
    K30, K31, K32, K33, K34, \
         K41, K42, K43, K44, \
    K50, K51, K52, K53, K54, \
    K60, K61, K62, K63, K64, \
         K71, K72, K73, K74, \
    K80, K81, K82, K83, K84, \
         K91, K92, K93, K94, \
    KA0, KA1, KA2, KA3, KA4, \
    KB0, KB1, KB2, KB3, KB4, \
    KC0, KC1, KC2, KC3, KC4, \
    KD0, KD1, KD2, KD3, KD4  \
) { \
    { KC_##K00, KC_##K01, KC_##K02, KC_##K03, KC_##K04 }, \
    { KC_##K10, KC_##K11, KC_##K12, KC_##K13, KC_##K14 }, \
    { KC_##K20, KC_##K21, KC_##K22, KC_##K23, KC_##K24 }, \
    { KC_##K30, KC_##K31, KC_##K32, KC_##K33, KC_##K34 }, \
    { KC_NO,    KC_##K41, KC_##K42, KC_##K43, KC_##K44 }, \
    { KC_##K50, KC_##K51, KC_##K52, KC_##K53, KC_##K54 }, \
    { KC_##K60, KC_##K61, KC_##K62, KC_##K63, KC_##K64 }, \
    { KC_NO,    KC_##K71, KC_##K72, KC_##K73, KC_##K74 }, \
    { KC_##K80, KC_##K81, KC_##K82, KC_##K83, KC_##K84 }, \
    { KC_NO,    KC_##K91, KC_##K92, KC_##K93, KC_##K94 }, \
    { KC_##KA0, KC_##KA1, KC_##KA2, KC_##KA3, KC_##KA4 }, \
    { KC_##KB0, KC_##KB1, KC_##KB2, KC_##KB3, KC_##KB4 }, \
    { KC_##KC0, KC_##KC1, KC_##KC2, KC_##KC3, KC_##KC4 }, \
    { KC_##KD0, KC_##KD1, KC_##KD2, KC_##KD3, KC_##KD4 }  \
}

#endif
