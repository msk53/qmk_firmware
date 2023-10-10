/* Copyright 2018 ENDO Katsuhiro <ka2hiro@curlybracket.co.jp>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "keymap_japanese.h"

// NICOLA親指シフト
#include "nicola.h"
NGKEYS nicola_keys;
// NICOLA親指シフト

// Defines the keycodes used by our macros in process_record_user
enum layer_names {
    _QWERTY,

// NICOLA親指シフト
    _NICOLA, // NICOLA親指シフト入力レイヤー
// NICOLA親指シフト

    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
  QWERTY = QK_KB_0,
  LOWER,
  RAISE,
  ADJUST,

// NICOLA親指シフト
  NG_OFF,   // Layer OFF
  NG_ON,    // Layer ON
// NICOLA親指シフト
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  |
 * `-------------+------+------+------|           |------+------+------+------+------'
 *           | Ctrl/GUI | LOWER| Spc  |           | Spc  | RAISE|Sft/BkSp |
 *               `--------------------'           `--------------------'
 */
[_QWERTY] = LAYOUT_split_3x5_3(
  JP_Q,    JP_W,    JP_E,    JP_R,    JP_T,         JP_Y,    JP_U,    JP_I,    JP_O,    JP_P,
  JP_A,    JP_S,    JP_D,    JP_F,    JP_G,         JP_H,    JP_J,    JP_K,    JP_L,    JP_SCLN,
  JP_Z,    JP_X,    JP_C,    JP_V,    JP_B,         JP_N,    JP_M,    JP_COMM, JP_DOT,  JP_SLSH,
      MT(MOD_LCTL, KC_LGUI), LOWER,   KC_SPC,       KC_SPC,  RAISE,  MT(MOD_LSFT, KC_BSPC)
),
// NICOLA親指シフト
// デフォルトレイヤーに関係なくQWERTYで
[_NICOLA] = LAYOUT_split_3x5_3(
  NG_Q,    NG_W,    NG_E,    NG_R,    NG_T,         NG_Y,    NG_U,    NG_I,    NG_O,    NG_P,
  NG_A,    NG_S,    NG_D,    NG_F,    NG_G,         NG_H,    NG_J,    NG_K,    NG_L,    NG_SCLN,
  NG_Z,    NG_X,    NG_C,    NG_V,    NG_B,         NG_N,    NG_M,    NG_COMM, NG_DOT,  NG_SLSH,
                    _______, KC_TRNS, NG_SHFTL,     NG_SHFTR,KC_TRNS, _______
),
// NICOLA親指シフト

/* Raise
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |           |   ^  |   &  |   *  |   (  |   )  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Tab |   _  |   +  |  |   |  ~   |           |   :  |   "  |   >  |   {  |   }  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Eisū|   -  |   =  |  \   |  `   |           |   ;  |   '  |   <  |   [  |   ]  |
 * `-------------+------+------+------|           |------+------+------+------+------'
 *               |      | LOWER|      |           |      | RAISE|      |
 *               `--------------------'           `--------------------'
 */
[_RAISE] = LAYOUT_split_3x5_3(
  JP_EXLM, JP_AT,   JP_HASH, JP_DLR,  JP_PERC,      JP_CIRC, JP_AMPR, JP_ASTR, JP_LPRN, JP_RPRN,
  KC_TAB,  JP_UNDS, JP_PLUS, JP_PIPE, JP_TILD,      JP_COLN, JP_DQUO, JP_RABK, JP_LCBR, JP_RCBR,
  KC_LNG2, JP_MINS, JP_EQL,  JP_BSLS, JP_GRV,       JP_SCLN, JP_QUOT, JP_LABK, JP_LBRC, JP_RBRC,
                    _______, KC_TRNS, NG_OFF,       _______, KC_TRNS, _______
),

/* Lower
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Tab |  Alt |      | Enter| Esc  |           | Left | Down |  Up  | Right|      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Kana|   -  |  GUI | Ctrl | Del  |           | BkSp | PgUp | PgDn | Home | End  |
 * `-------------+------+------+------|           |------+------+------+------+------'
 *               |      | LOWER|      |           |      | RAISE|      |
 *               `--------------------'           `--------------------'
 */
[_LOWER] = LAYOUT_split_3x5_3(
  JP_1,    JP_2,    JP_3,    JP_4,    JP_5,         JP_6,     JP_7,    JP_8,    JP_9,    JP_0,
  KC_TAB,  KC_LALT, _______, KC_ENT,  KC_ESC,      KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,
  KC_LNG1, JP_MINS, KC_LGUI, KC_LCTL, KC_DEL,      KC_BSPC,  KC_PGUP, KC_PGDN, KC_HOME, KC_END,
                    _______, KC_TRNS, _______,     NG_ON,    KC_TRNS, _______
),


/* Adjust (Lower + Raise)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |           |   F6 |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |PrtScr|      |      |      |           |      |      |      |  F12 |  F11 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | Reset|      |      |      |      |           |      |      |CA+Del|      |  App |
 * `-------------+------+------+------|           |------+------+------+------+------'
 *               |      | LOWER|      |           |      | RAISE|      |
 *               `--------------------'           `--------------------'
 */
[_ADJUST] =  LAYOUT_split_3x5_3(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8,     KC_F9,   KC_F10,
  _______, KC_PSCR, _______, _______, _______,      _______, _______, _______,   KC_F12,  KC_F11,
  QK_BOOT, _______, _______, _______, _______,      _______, _______,LCA(KC_DEL),_______, KC_APP,
                    _______, KC_TRNS, _______,      _______, KC_TRNS, _______
)
};

void matrix_init_user(void) {
  // NICOLA親指シフト
  set_nicola(_NICOLA);
  // NICOLA親指シフト
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        // persistant_default_layer_set(1UL<<_QWERTY);
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;

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
