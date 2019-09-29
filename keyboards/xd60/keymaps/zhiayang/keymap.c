// keymap.c
// Copyright (c) 2014 - 2017, zhiayang
// Licensed under the Apache License Version 2.0.

#include "xd60.h"
#include "rev2/config.h"

#include "rgblight.h"

#include <string.h>
#include "zhiayang.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	LAYOUT_all(
		CST_ESC,        KC_1,    KC_2,    KC_3, KC_4, KC_5,   KC_6, KC_7, KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_NO,   NOKEY,
		KC_TAB,         KC_Q,    KC_W,    KC_E, KC_R, KC_T,   KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
		CST_CAPS,       KC_A,    KC_S,    KC_D, KC_F, KC_G,   KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT, NOKEY,   KC_ENT,
		KC_LSFT, NOKEY, KC_Z,    KC_X,    KC_C, KC_V, KC_B,   KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_DEL,  KC_UP,   KC_NO,
		KC_RCTL,        KC_LALT, KC_LCTL,             KC_SPC,                      CST_FN, KC_LGUI, KC_LEFT, KC_DOWN, KC_RIGHT),

	LAYOUT_all(
		CST_ESC,        KC_1,    KC_2,    KC_3, KC_4, KC_5,   KC_6, KC_7, KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_NO,   NOKEY,
		KC_TAB,         KC_Q,    KC_W,    KC_E, KC_R, KC_T,   KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
		CST_CAPS,       KC_A,    KC_S,    KC_D, KC_F, KC_G,   KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT, NOKEY,   KC_ENT,
		KC_LSFT, NOKEY, KC_Z,    KC_X,    KC_C, KC_V, KC_B,   KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_DEL,  KC_UP,   KC_NO,
		KC_LCTL,        KC_LALT, KC_LGUI,             KC_SPC,                      CST_FN, KC_LCTL, KC_LEFT, KC_DOWN, KC_RIGHT),

	LAYOUT_all(
		_____,        KC_F1,   KC_F2,   KC_F3,   KC_F4, KC_F5, KC_F6,  KC_F7, KC_F8,   KC_F9, KC_F10, KC_F11,  KC_F12,    _____,   NOKEY,
		_____,        KC_BSPC, KC_UP,   __X__,   __X__, __X__, __X__,  __X__, __X__,   __X__, __X__,  __X__,   __X__,     KC_GRAVE,
		_____,        KC_LEFT, KC_DOWN, KC_RGHT, __X__, __X__, __X__,  __X__, KC_BSPC, __X__, __X__,  __X__,   __X__,     __X__,
		_____, NOKEY, __X__,   __X__,   __X__,   __X__, __X__, __X__,  __X__, __X__,   __X__, __X__,  _____,   KC_PGUP,   __X__,
		_____,        _____,   _____,                   KC_SPC,                        _____, _____,  KC_HOME, KC_PGDOWN, KC_END),

	LAYOUT_all(
		CST_QUIT_MACRO, __X__, __X__, __X__, __X__, __X__, __X__, __X__, __X__, __X__, __X__, __X__,         __X__,   _____,   NOKEY,
		_____,          __X__, __X__, __X__, __X__, __X__, __X__, __X__, __X__, __X__, __X__, __X__,         __X__,   __X__,
		_____,          __X__, __X__, __X__, __X__, __X__, __X__, __X__, __X__, __X__, __X__, __X__,         __X__,   __X__,
		_____, NOKEY,   __X__, __X__, __X__, __X__, __X__, __X__, __X__, __X__, __X__, __X__, CST_SEL_MACRO, KC_VOLU, CST_RESET,
		_____,          _____, _____,               __X__,                      _____, _____, CST_UG_TOG,    KC_VOLD, CST_UG_SWT)
};



void matrix_init_user(void)
{
	rgblight_enable();
	rgblight_sethsv(0, 0, 255);
	rgblight_disable();

	debug_enable = false;

	memset(kbst(), 0, sizeof(kbstate_t));

	kbst()->rgb_brightness = 7;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record)
{
	bool is_pressed = record->event.pressed;

	switch(keycode)
	{
		case CST_CAPS: {
			if(is_pressed)  enter_fn_layer();
			else            enter_base_layer();

			return true;
		}

		case CST_FN: {
			if(is_pressed && (get_mods() & MOD_BIT(KC_LCTL)) && (get_mods() & MOD_BIT(KC_LALT)))
			{
				toggle_capslock();
				return false;
			}

			if(is_pressed)  enter_macro_layer();
			else            enter_base_layer();

			return true;
		}


		default: {
			return process_record_default(keycode, is_pressed);
		}
	}
}






