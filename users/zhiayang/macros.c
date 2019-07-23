// macros.c
// Copyright (c) 2019, zhiayang, Apache License 2.0.

#include "zhiayang.h"

bool process_record_macro(uint16_t keycode, bool is_pressed)
{
	switch(keycode)
	{
		// nice gcc extension
		case KC_1 ... KC_9: {
			if(is_pressed && kbst()->macro_mode == WAIT_FOR_MACRO)
			{
				int macro_num = 1 + (keycode - KC_1);

				if(macro_num < MACROS_END)  kbst()->macro_mode = macro_num;
				else                        kbst()->macro_mode = NO_MACRO;

				update_rgb();
				return false;
			}
			else
			{
				return true;
			}
		}

		// and again
		case KC_A ... KC_Z: {
			if(kbst()->macro_mode == CYCLE_CASE_MACRO)
			{
				if(is_pressed)
				{
					if(kbst()->macro_data)  tap_code16(LSFT(keycode));
					else                    tap_code16(keycode);

					kbst()->macro_data = !kbst()->macro_data;
				}

				return false;
			}
			else
			{
				return true;
			}
		}

		case KC_TAB:
		case KC_SPACE:
		case KC_RETURN: {
			if(kbst()->macro_mode == CYCLE_CASE_MACRO && is_pressed)
				kbst()->macro_data = 0;

			return true;
		}
	}

	return true;
}
































