// zhiayang.h
// Copyright (c) 2019, zhiayang, Apache License 2.0.

#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

#define NOKEY   KC_NO
#define __X__   KC_NO
#define _____   KC_TRNS

enum custom_keycodes
{
	CST_ESC = SAFE_RANGE,
	CST_CAPS,
	CST_FN,

	CST_SEL_MACRO,
	CST_QUIT_MACRO,

	CST_RESET,
	CST_CMD_CTRL_SW,

	CST_UG_SWT,
	CST_UG_TOG,

	NEW_SAFE_RANGE
};

enum macro_list
{
	NO_MACRO = 0,
	CYCLE_CASE_MACRO,

	MACROS_END,

	WAIT_FOR_MACRO
};

enum layer_list
{
	LAYER_BASE_WIN = 0,
	LAYER_BASE_OSX,
	LAYER_FN,
	LAYER_MACRO
};

typedef struct
{
	bool is_caps;
	bool is_rgb_enabled;
	bool is_ctrl_as_cmd;

	int macro_mode;
	int layer_mode;

	int rgb_brightness;

	int macro_data;

} kbstate_t;

// we do not currently do nested layers, so we don't need both enter *and* leave.
void enter_fn_layer(void);
void enter_macro_layer(void);
void enter_base_layer(void);
void toggle_capslock(void);

bool is_shifting(void);

void update_rgb(void);
void enter_flashing_mode(void);

kbstate_t* kbst(void);

bool process_record_macro(uint16_t keycode, bool is_pressed);
bool process_record_default(uint16_t keycode, bool is_pressed);
void toggle_bool(bool* b);

#endif

























