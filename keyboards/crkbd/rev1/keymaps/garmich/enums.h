#pragma once

enum {
	ALP_LY = 0,
	NAV_LY,
	MOU_LY,
	NUM_LY,
	SYM_LY,
	GAM_LY,
};

typedef enum {
    HOLD_IS_MOD,
    HOLD_IS_LAYER,
    HOLD_IS_KEY
} hold_type_t;

typedef enum {
    TD_NONE,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_MULTI_TAP,
    TD_MULTI_HOLD
} td_state_t;