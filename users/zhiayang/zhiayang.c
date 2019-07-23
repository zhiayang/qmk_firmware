// zhiayang.c
// Copyright (c) 2019, zhiayang, Apache License 2.0.

#include "zhiayang.h"

static kbstate_t kbstate;

kbstate_t* kbst(void)
{
	return &kbstate;
}

bool process_record_default(uint16_t keycode, bool is_pressed)
{
	switch(keycode)
	{
		case CST_ESC: {
			(is_pressed ? register_code16 : unregister_code16)(!(get_mods() & MOD_BIT(KC_LCTL)) && is_shifting() ? KC_TILDE : KC_ESC);
			return false;
		}

		case CST_RESET: {
			if(is_pressed)
			{
				if(is_shifting())
				{
					enter_flashing_mode();
				}
				else
				{
					toggle_bool(&kbst()->is_ctrl_as_cmd);
					enter_base_layer();

					// unset all the modifiers
					clear_mods();
				}
			}
			return false;
		}

		case CST_UG_SWT: {
			if(is_pressed)
			{
				kbst()->rgb_brightness = (kbst()->rgb_brightness + 1) % 8;
				update_rgb();
			}
			return false;
		}

		case CST_UG_TOG: {
			if(is_pressed)
			{
				if(kbst()->is_rgb_enabled)  rgblight_disable();
				else                        rgblight_enable();

				toggle_bool(&kbst()->is_rgb_enabled);
			}
			return false;
		}

		case CST_SEL_MACRO: {
			if(is_pressed)
				kbst()->macro_mode = WAIT_FOR_MACRO;

			return false;
		}

		case CST_QUIT_MACRO: {
			if(is_pressed)
				kbst()->macro_mode = NO_MACRO;

			return false;
		}

		default: {
			if(kbst()->macro_mode != NO_MACRO)
				return process_record_macro(keycode, is_pressed);

			else
				return true;
		}
	}

	return true;
}















