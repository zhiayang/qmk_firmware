// layers.c
// Copyright (c) 2019, zhiayang, Apache License 2.0.

#include "zhiayang.h"

void enter_fn_layer(void)
{
	kbst()->layer_mode = LAYER_FN;
	layer_move(LAYER_FN);

	update_rgb();
}

void enter_macro_layer(void)
{
	kbst()->layer_mode = LAYER_MACRO;
	layer_move(LAYER_MACRO);

	update_rgb();
}

void enter_base_layer(void)
{
	kbst()->layer_mode = 0;

	if(kbst()->is_ctrl_as_cmd) layer_move(LAYER_BASE_OSX);
	else                       layer_move(LAYER_BASE_WIN);

	update_rgb();
}

void toggle_capslock(void)
{
	// manually send a capslock keydown-keyup combo
	register_code16(KC_CAPS);
	unregister_code16(KC_CAPS);

	toggle_bool(&kbst()->is_caps);
	update_rgb();
}







