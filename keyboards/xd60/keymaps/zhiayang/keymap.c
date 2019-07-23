// keymap.c
// Copyright (c) 2014 - 2017, zhiayang@gmail.com
// Licensed under the Apache License Version 2.0.

#include "xd60.h"
#include "string.h"
#include "config.h"
#include "rgblight.h"
#include "util/delay.h"

#include "print.h"

// #include "process_tap_dance.h"

enum custom_keycodes
{
    CST_ESC = SAFE_RANGE,
    CST_CAPS,
    CST_FN,

    CST_NRIC,

    CST_RESET,
    CST_CMD_CTRL_SW,

    CST_GRAVE,

    CST_UG_SWT,
    CST_UG_TOG,
};

// static void handle_dance_caps(qk_tap_dance_state_t* state, void* user_data);
// static void reset_dance_caps(qk_tap_dance_state_t* state, void* user_data);

// qk_tap_dance_action_t tap_dance_actions[] = {
// 	[0] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, handle_dance_caps, reset_dance_caps),
// };

#define NOT_THERE	KC_NO
#define __X__		KC_NO
#define _____		KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	LAYOUT_all(
		CST_ESC,            KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,    KC_EQL,    KC_NO,   NOT_THERE,
		KC_TAB,             KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,    KC_RBRC,   KC_BSLS,
		CST_CAPS,           KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,    NOT_THERE, KC_ENT,
		KC_LSFT, NOT_THERE, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,   KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_DEL,     KC_UP,     KC_NO,
		KC_RCTL,            KC_LALT, KC_LCTL,                  KC_SPC,                           CST_FN,  KC_LGUI, KC_LEFT,    KC_DOWN,   KC_RIGHT),

	LAYOUT_all(
		CST_ESC,            KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,    KC_EQL,    KC_NO,   NOT_THERE,
		KC_TAB,             KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,    KC_RBRC,   KC_BSLS,
		CST_CAPS,           KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,    NOT_THERE, KC_ENT,
		KC_LSFT, NOT_THERE, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,   KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_DEL,     KC_UP,     KC_NO,
		KC_LCTL,            KC_LALT, KC_LGUI,                  KC_SPC,                           CST_FN,  KC_LCTL, KC_LEFT,    KC_DOWN,   KC_RIGHT),

	LAYOUT_all(
		_____,              KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,  KC_F7,   KC_F8,    KC_F9,   KC_F10,  KC_F11,     KC_F12,   _____,   NOT_THERE,
		_____,              KC_BSPC, KC_UP,   KC_BSPC, __X__,  __X__,  __X__,  __X__,   __X__,   __X__,   __X__,   __X__,      __X__,     CST_GRAVE,
		_____,              KC_LEFT, KC_DOWN, KC_RGHT, __X__,  __X__,  __X__,  __X__,  KC_BSPC,  __X__,   __X__,   __X__,      __X__,     __X__,
		_____, NOT_THERE,   __X__,   __X__,   __X__,   __X__,  __X__,  __X__,  __X__,   __X__,   __X__,   __X__,   _____,      KC_PGUP,   __X__,
		_____,              _____,   _____,                    KC_SPC,                           _____,   _____,   KC_HOME,    KC_PGDOWN, KC_END),

	LAYOUT_all(
		_____,              __X__,   __X__,   __X__,   __X__,  __X__,  __X__,  __X__,   __X__,    __X__,  __X__,   __X__,      __X__,      _____,   NOT_THERE,
		_____,              __X__,   __X__,   __X__,   __X__,  __X__,  __X__,  __X__,   __X__,   __X__,   __X__,   __X__,      __X__,     __X__,
		_____,              __X__,   __X__,   __X__,   __X__,  __X__,  __X__,  __X__,   __X__,   __X__,   __X__,   __X__,      __X__,       __X__,
		_____, NOT_THERE,   __X__,   __X__,   __X__,   __X__,  __X__,  __X__,  __X__,   __X__,   __X__,   __X__,   CST_NRIC,   KC_VOLU,   CST_RESET,
		_____,              _____,   _____,                    __X__,                            _____,   _____,   CST_UG_TOG, KC_VOLD,   CST_UG_SWT)
};

enum LIST_OF_MACROS
{
	NO_MACRO = 0,
	NRIC_MACRO
};

static int macro_mode = 0;





static bool is_fn = false;
static bool is_caps = false;
// static bool _is_shifting = false;
static bool is_rgb_enabled = false;
static bool is_ctrl_as_cmd = false;

static bool is_shifting(void)
{
	// return _is_shifting;
	return get_mods() & MOD_BIT(KC_LSFT);
}


static int brightness_index = 7;
static uint8_t brightness_table[8] = {
	32, 64, 96, 128, 160, 192, 224, 255
};

static void update_rgb(void)
{
	// default: white
	// fn: green-ish
	// caps: pink-ish
	// ctrl-as-cmd: blue-ish

	if(is_rgb_enabled)
	{
		uint8_t val  = brightness_table[brightness_index];
		uint8_t sat = 0;
		uint16_t hue = 0;

		if(macro_mode != NO_MACRO)
			sat = 255, hue = 30;

		else if(is_fn)
			sat = 210, hue = 230;

		else if(is_caps)
			sat = 165, hue = 0;

		else if(is_ctrl_as_cmd)
			sat = 255, hue = 160;

		rgblight_sethsv(hue, sat, val);
	}
}


static void enter_fn_layer(void)
{
	is_fn = true;
	layer_move(2);
	update_rgb();
}

static void leave_fn_layer(void)
{
	is_fn = false;
	layer_move(is_ctrl_as_cmd ? 1 : 0);
	update_rgb();
}

static void enter_fn2_layer(void)
{
	is_fn = true;
	layer_move(3);
	update_rgb();
}

static void leave_fn2_layer(void)
{
	is_fn = false;
	layer_move(is_ctrl_as_cmd ? 1 : 0);
	update_rgb();
}


// static void toggle_fn_layer(void)
// {
// 	is_fn = !is_fn;

// 	if(is_fn)	layer_move(2);
// 	else		layer_move(is_ctrl_as_cmd ? 1 : 0);

// 	update_rgb();
// }

static void toggle_caps(void)
{
	register_code16(KC_CAPS);
	unregister_code16(KC_CAPS);
	is_caps = !is_caps;
	update_rgb();
}














void matrix_init_user(void)
{
	rgblight_enable();
	rgblight_sethsv(0, 0, 255);
	rgblight_disable();

	debug_enable = true;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record)
{
	// here's what we aim to do:
	// when we press 'CST_SHIFT' (which is shift), we send the shift key as usual.
	// but we also set a global flag.

	bool is_pressed = record->event.pressed;
	switch(keycode)
	{
		case KC_LSFT: {
			// _is_shifting = is_pressed;
			return true;
		}

		case CST_ESC: {
			if(macro_mode == NRIC_MACRO)
			{
				// quit the macro.

				// global_nric_macro_state.cur_digits = 0;

				macro_mode = NO_MACRO;
				leave_fn_layer();
			}
			else
			{
				(is_pressed ? register_code16 : unregister_code16)(!(get_mods() & MOD_BIT(KC_LCTL)) && is_shifting() ? KC_TILDE : KC_ESC);
			}
			return false;
		}

		case CST_GRAVE: {
			(is_pressed ? register_code16 : unregister_code16)(KC_GRV);
			return false;
		}


		case CST_CAPS: {
			if(is_pressed)
				enter_fn_layer();

			else
				leave_fn_layer();

			return true;
		}

		case CST_FN: {
			if(is_pressed && (get_mods() & MOD_BIT(KC_LCTL)) && (get_mods() & MOD_BIT(KC_LALT)))
			{
				toggle_caps();
				return false;
			}

			if(is_pressed)
				enter_fn2_layer();

			else
				leave_fn2_layer();

			return true;
		}

		case CST_RESET: {
			if(is_pressed)
			{
				if(is_shifting())
				{
					bool turn_off = !is_rgb_enabled;
					rgblight_enable();

					for(int i = 0; i < 5; i++)
					{
						rgblight_setrgb(255, 255, 0);
						_delay_ms(100);
						rgblight_setrgb(0, 0, 0);
						_delay_ms(100);
					}

					if(turn_off) rgblight_disable();

					// soft reset

					is_fn = false;
					is_caps = false;
					is_rgb_enabled = false;
					is_ctrl_as_cmd = false;

					brightness_index = 7;
					macro_mode = NO_MACRO;
					leave_fn_layer();
					update_rgb();

					reset_keyboard();
				}
				else
				{
					is_ctrl_as_cmd = !is_ctrl_as_cmd;
					update_rgb();

					if(is_ctrl_as_cmd)	layer_move(1);
					else				layer_move(0);

					// unset all the modifiers
					clear_mods();
				}
			}
			return true;
		}

		case CST_UG_SWT: {
			if(is_pressed)
			{
				brightness_index = (brightness_index + 1) % 8;
				update_rgb();
			}
			return true;
		}

		case CST_UG_TOG: {
			if(is_pressed)
			{
				if(is_rgb_enabled)	rgblight_disable();
				else				rgblight_enable();

				is_rgb_enabled = !is_rgb_enabled;
			}
			return true;
		}

		default: {
			return true;
		}
	}
}






