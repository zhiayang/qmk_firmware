// keymap.c
// Copyright (c) 2019, zhiayang, Apache License 2.0.

#include "iris.h"
#include "rev3/config.h"

#include <string.h>

#include "zhiayang.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
	// layer_base_win
	LAYOUT(
	//┌────────┬────────┬────────┬────────┬────────┬────────┐                      ┌────────┬────────┬────────┬────────┬────────┬────────┐
	    CST_ESC,  KC_1  ,  KC_2  ,  KC_3  ,  KC_4  ,  KC_5  ,                         KC_6  ,  KC_7  ,  KC_8  ,  KC_9  ,  KC_0  , KC_MINS,
	//├────────┼────────┼────────┼────────┼────────┼────────┤                      ├────────┼────────┼────────┼────────┼────────┼────────┤
	    KC_TAB ,  KC_Q  ,  KC_W  ,  KC_E  ,  KC_R  ,  KC_T  ,                         KC_Y  ,  KC_U  ,  KC_I  ,  KC_O  ,  KC_P  , KC_BSLS,
	//├────────┼────────┼────────┼────────┼────────┼────────┤                      ├────────┼────────┼────────┼────────┼────────┼────────┤
	   CST_CAPS,  KC_A  ,  KC_S  ,  KC_D  ,  KC_F  ,  KC_G  ,                         KC_H  ,  KC_J  ,  KC_K  ,  KC_L  , KC_SCLN, KC_QUOT,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐    ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	    KC_LSFT,  KC_Z  ,  KC_X  ,  KC_C  ,  KC_V  ,  KC_B  ,  NOKEY ,       NOKEY ,  KC_N  ,  KC_M  , KC_COMM, KC_DOT , KC_SLSH, KC_ENT ,
	//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘    └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
	                                  KC_LCTRL, KC_LALT, KC_SPC ,               KC_ENT , KC_SPC , CST_FN
	//                               └────────┴────────┴────────┘             └────────┴────────┴────────┘
	),

	// layer_base_osx
	LAYOUT(
	//┌────────┬────────┬────────┬────────┬────────┬────────┐                      ┌────────┬────────┬────────┬────────┬────────┬────────┐
	    CST_ESC,  KC_1  ,  KC_2  ,  KC_3  ,  KC_4  ,  KC_5  ,                         KC_6  ,  KC_7  ,  KC_8  ,  KC_9  ,  KC_0  , KC_MINS,
	//├────────┼────────┼────────┼────────┼────────┼────────┤                      ├────────┼────────┼────────┼────────┼────────┼────────┤
	    KC_TAB ,  KC_Q  ,  KC_W  ,  KC_E  ,  KC_R  ,  KC_T  ,                         KC_Y  ,  KC_U  ,  KC_I  ,  KC_O  ,  KC_P  , KC_BSLS,
	//├────────┼────────┼────────┼────────┼────────┼────────┤                      ├────────┼────────┼────────┼────────┼────────┼────────┤
	   CST_CAPS,  KC_A  ,  KC_S  ,  KC_D  ,  KC_F  ,  KC_G  ,                         KC_H  ,  KC_J  ,  KC_K  ,  KC_L  , KC_SCLN, KC_QUOT,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐    ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	    KC_LSFT,  KC_Z  ,  KC_X  ,  KC_C  ,  KC_V  ,  KC_B  ,  NOKEY ,       NOKEY ,  KC_N  ,  KC_M  , KC_COMM, KC_DOT , KC_SLSH, KC_ENT ,
	//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘    └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
	                                  KC_LCTRL, KC_LGUI, KC_SPC ,               KC_ENT , KC_LALT, CST_FN
	//                               └────────┴────────┴────────┘             └────────┴────────┴────────┘
	),



	// layer_fn.
	// note: we put some of the keys as _____ (transparent) so we can do things like win+E or win+L or win+R.
	LAYOUT(
	//┌────────┬────────┬────────┬────────┬────────┬────────┐                      ┌────────┬────────┬────────┬────────┬────────┬────────┐
	    KC_F12 ,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 ,  KC_F5 ,                         KC_F6 ,  KC_F7 ,  KC_F8 ,  KC_F9 , KC_F10 , KC_EQL ,
	//├────────┼────────┼────────┼────────┼────────┼────────┤                      ├────────┼────────┼────────┼────────┼────────┼────────┤
	    KC_F11 , KC_BSPC,  KC_UP ,  _____ ,  _____ ,  __X__ ,                         __X__ ,  __X__ ,  __X__ , KC_LBRC, KC_RBRC,KC_GRAVE,
	//├────────┼────────┼────────┼────────┼────────┼────────┤                      ├────────┼────────┼────────┼────────┼────────┼────────┤
	    _____  , KC_LEFT, KC_DOWN,KC_RIGHT,  __X__ ,  __X__ ,                        KC_PGUP,  __X__ , KC_BSPC, _____,   KC_HOME, KC_END ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐    ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	    _____  ,  __X__ ,  __X__ ,  __X__ ,  __X__ ,  __X__ ,  __X__ ,       __X__ , KC_PGDN,  __X__ ,  __X__ , __X__,    __X__ ,  __X__ ,
	//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘    └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
	                                    _____ ,  _____ ,  _____ ,                __X__ , KC_LGUI, CST_FN
	//                               └────────┴────────┴────────┘             └────────┴────────┴────────┘
	),

	// layer_macro
	LAYOUT(
	//┌────────┬────────┬────────┬────────┬────────┬────────┐                      ┌────────┬────────┬────────┬────────┬────────┬────────┐
CST_QUIT_MACRO ,  __X__ ,  __X__ ,  __X__ ,  __X__ ,  __X__ ,                         __X__ ,  __X__ ,  __X__ ,  __X__ , KC_DEL ,CST_RESET,
	//├────────┼────────┼────────┼────────┼────────┼────────┤                      ├────────┼────────┼────────┼────────┼────────┼────────┤
	    __X__  ,  __X__ ,  __X__ ,  __X__ ,  __X__ ,  __X__ ,                         __X__ ,  __X__ ,  __X__ ,  __X__ ,CST_UG_SWT,KC_VOLU,
	//├────────┼────────┼────────┼────────┼────────┼────────┤                      ├────────┼────────┼────────┼────────┼────────┼────────┤
	    _____  ,  __X__ ,  __X__ ,  __X__ ,  __X__ ,  __X__ ,                         __X__ ,  __X__ ,  __X__ ,  __X__ ,CST_UG_TOG,KC_VOLD,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐    ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	    _____  ,  __X__ ,  __X__ ,  __X__ ,  __X__ ,  __X__ ,  __X__ ,       __X__ ,  __X__ ,  __X__ ,  __X__ ,  __X__ ,  __X__ ,CST_SEL_MACRO,
	//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘    └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
	                                    __X__ ,  __X__ ,  __X__ ,                __X__ ,  __X__ ,  _____
	//                               └────────┴────────┴────────┘             └────────┴────────┴────────┘
	),
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































