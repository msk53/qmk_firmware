/*
Copyright 2022 aki27

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

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "quantum.h"
#include "keymap_japanese.h"

// NICOLA親指シフト
#include "nicola.h"
NGKEYS nicola_keys;
// NICOLA親指シフト

// Defines names for use in layer keycodes and the keymap
enum layer_number {
    _BASE = 0,
// NICOLA親指シフト
    _NICOLA, // NICOLA親指シフト入力レイヤー
// NICOLA親指シフト
    _LOWER,
    _RAISE,
    _TRACKBALL,
    _Layer5,
    _Layer6,
};


#define LW_MHEN LT(_LOWER,JP_MHEN)  // lower
#define RS_HENK LT(_RAISE,JP_HENK)  // raise
#define LR_MOUSE TT(_TRACKBALL)
#define DEL_ALT ALT_T(KC_DEL)


enum custom_keycodes {
/*
#define CPI_SW QK_KB_0
#define SCRL_SW QK_KB_1
#define ROT_R15 QK_KB_2
#define ROT_L15 QK_KB_3
#define SCRL_MO QK_KB_4
#define SCRL_TO QK_KB_5
#define SCRL_IN QK_KB_6
*/
// NICOLA親指シフト
  NG_OFF = COCOT_SAFE_RANGE,
  NG_ON,
// NICOLA親指シフト
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
       KC_TAB,    JP_Q,    JP_W,    JP_E,    JP_R,    JP_T,                                          JP_Y,    JP_U,    JP_I,    JP_O,   JP_P,  KC_BSPC,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      KC_LCTL,    JP_A,    JP_S,    JP_D,    JP_F,    JP_G,                                          JP_H,    JP_J,    JP_K,    JP_L, JP_SCLN, JP_QUOT,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      KC_LSFT,    JP_Z,    JP_X,    JP_C,    JP_V,    JP_B,                                          JP_N,    JP_M, JP_COMM,  JP_DOT, JP_SLSH, JP_MINS,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        KC_LGUI, DEL_ALT,   LW_MHEN,  KC_SPC,    MS_BTN1,                MS_BTN2,  KC_ENT, RS_HENK, KC_BSPC,  KC_ESC,
                                                                 KC_PGUP,    MS_BTN3,    KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_NICOLA] = LAYOUT(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      _______,    NG_Q,    NG_W,    NG_E,    NG_R,    NG_T,                                          NG_Y,    NG_U,    NG_I,    NG_O,   NG_P,  KC_BSPC,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      _______,    NG_A,    NG_S,    NG_D,    NG_F,    NG_G,                                          NG_H,    NG_J,    NG_K,    NG_L, NG_SCLN, NG_QUOT,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      _______,    NG_Z,    NG_X,    NG_C,    NG_V,    NG_B,                                          NG_N,    NG_M, NG_COMM,  NG_DOT, NG_SLSH, NG_MINS,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        _______, _______,  KC_TRNS, NG_SHFTL,  _______,                _______,  NG_SHFTR, KC_TRNS, _______,  _______,
                                                               _______,    _______,    _______,  XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_LOWER] = LAYOUT(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
       KC_ESC, JP_EXLM,   JP_AT, JP_HASH,  JP_DLR, JP_PERC,                                       JP_CIRC, JP_AMPR, JP_ASTR, JP_LPRN, JP_RPRN, KC_BSPC,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       JP_LCBR, JP_RCBR, JP_LBRC, JP_RBRC, JP_COLN, JP_DQUO,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      KC_LSFT,  JP_GRV, JP_TILD, JP_BSLS, JP_PIPE, XXXXXXX,                                        JP_EQL, JP_PLUS, JP_LABK, JP_RABK, JP_QUES, JP_UNDS,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        KC_LGUI, DEL_ALT, KC_TRNS,  _______,     MS_BTN4,                MS_BTN5,  NG_ON,  LR_MOUSE, KC_BSPC,  KC_ESC,
                                                                 KC_PGUP,    MS_BTN3,    KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_RAISE] = LAYOUT(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
       KC_ESC,    JP_1,    JP_2,    JP_3,    JP_4,    JP_5,                                          JP_6,    JP_7,    JP_8,    JP_9,   JP_0,  KC_BSPC,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      KC_LCTL,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                        KC_APP,   KC_UP, KC_INT1, JP_UNDS, JP_DQUO, JP_COLN,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      KC_LSFT,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                                       KC_LEFT, KC_DOWN, KC_RGHT,  JP_DOT, JP_SLSH, JP_MINS,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        KC_LGUI, DEL_ALT, LR_MOUSE, NG_OFF,      MS_BTN4,                MS_BTN5, _______, KC_TRNS, KC_BSPC,  KC_ESC,
                                                                 KC_PGUP,    MS_BTN3,    KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_TRACKBALL] = LAYOUT(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, UG_TOGG,                                       SCRL_TO,  CPI_SW, SCRL_SW, ROT_L15, ROT_R15, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, UG_VALU, UG_SATU, UG_HUEU, UG_NEXT,                                       SCRL_MO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, UG_VALD, UG_SATD, UG_HUED, UG_PREV,                                       SCRL_IN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        KC_LGUI, DEL_ALT, KC_TRNS,  KC_SPC,      MS_BTN1,                MS_BTN2,  KC_ENT, RS_HENK, KC_BSPC,  KC_ESC,
                                                                 KC_PGUP,    MS_BTN3,    KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_Layer5] = LAYOUT(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX,             XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
                                                                 XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_Layer6] = LAYOUT(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX,             XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
                                                                 XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [1] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [2] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [3] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [4] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [5] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [6] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
};
#endif



layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _LOWER:
        rgblight_sethsv_range(HSV_BLUE, 0, 2);
        cocot_set_scroll_mode(true);
        break;
    case _RAISE:
        rgblight_sethsv_range(HSV_RED, 0, 2);
        cocot_set_scroll_mode(true);
        break;
    case _TRACKBALL:
        rgblight_sethsv_range(HSV_GREEN, 0, 2);
        cocot_set_scroll_mode(false);
        break;
    case _NICOLA:
        rgblight_sethsv_range(HSV_YELLOW, 0, 2);
        cocot_set_scroll_mode(false);
        break;
    case _Layer5:
        rgblight_sethsv_range(HSV_CYAN, 0, 2);
        cocot_set_scroll_mode(false);
        break;
    case _Layer6:
        rgblight_sethsv_range(HSV_ORANGE, 0, 2);
        cocot_set_scroll_mode(false);
        break;
    default:
        rgblight_sethsv_range( 0, 0, 0, 0, 2);
        cocot_set_scroll_mode(false);
        break;
    }
    rgblight_set_effect_range( 2, 10);
      return state;
};


#ifdef OLED_ENABLE
bool oled_task_user(void) {
    render_logo();
    oled_write_layer_state();
    return false;
}
#endif

void matrix_init_user(void) {
  // NICOLA親指シフト
  set_nicola(_NICOLA);
  // NICOLA親指シフト
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // NICOLA親指シフト
    case NG_OFF:
      if (record->event.pressed) {
        // IME OFF
        tap_code(KC_LANGUAGE_2); // Mac, Win11以降
        nicola_off();
      }
      return false;
      break;
    case NG_ON:
      if (record->event.pressed) {
        // IME ON
        tap_code(KC_LANGUAGE_1); // Mac, Win11以降
        nicola_on();
      }
      return false;
      break;
    // NICOLA親指シフト
    default:
      /* 何もしない */
      break;
  }

  // NICOLA親指シフト
  bool a = true;
  if (nicola_state()) {
    nicola_mode(keycode, record);
    a = process_nicola(keycode, record);
  }
  if (a == false) return false;
  // NICOLA親指シフト

  return true;
}
