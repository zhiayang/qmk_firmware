// utils.c
// Copyright (c) 2019, zhiayang, Apache License 2.0.

#include "zhiayang.h"
#include "rgblight.h"


void toggle_bool(bool* b)
{
	*b = !(*b);
}

bool is_shifting(void)
{
	return get_mods() & MOD_BIT(KC_LSFT);
}

void enter_flashing_mode(void)
{
	bool turn_off = !kbst()->is_rgb_enabled;
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

	kbst()->layer_mode = 0;
	kbst()->is_caps = false;
	kbst()->is_rgb_enabled = false;
	kbst()->is_ctrl_as_cmd = false;

	kbst()->rgb_brightness = 7;
	kbst()->macro_mode = NO_MACRO;

	enter_base_layer();
	update_rgb();

	reset_keyboard();
}

static uint8_t brightness_table[8] = {
	32, 64, 96, 128, 160, 192, 224, 255
};

void update_rgb(void)
{
	// default: white
	// fn: green-ish
	// caps: pink-ish
	// ctrl-as-cmd: blue-ish

	if(kbst()->is_rgb_enabled)
	{
		uint16_t hue = 0;
		uint16_t sat = 0;
		uint8_t val = brightness_table[kbst()->rgb_brightness];

		if(kbst()->macro_mode == WAIT_FOR_MACRO)
			hue = 0,    sat = 70;

		else if(kbst()->macro_mode != NO_MACRO)
			hue = 30,   sat = 100;

		else if(kbst()->layer_mode == LAYER_FN)
			hue = 200,  sat = 85;

		else if(kbst()->layer_mode == LAYER_MACRO)
			hue = 60,   sat = 100;

		else if(kbst()->is_caps)
			hue = 0,    sat = 80;

		else if(kbst()->is_ctrl_as_cmd)
			hue = 160,  sat = 100;

		rgblight_sethsv((uint8_t) ((hue * 255) / 360), (uint8_t) ((sat * 255) / 100), val);
	}
}
















