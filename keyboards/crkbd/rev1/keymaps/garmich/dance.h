#pragma once

/*
static td_state_t td_state;
td_state_t cur_dance(tap_dance_state_t *state);

void til_finished(tap_dance_state_t *state, void *user_data);
void til_reset(tap_dance_state_t *state, void *user_data);
void grv_finished(tap_dance_state_t *state, void *user_data);
void grv_reset(tap_dance_state_t *state, void *user_data);
 */

enum td_keycodes {
	TDNULL = 0,
  DOT,
  COM,
};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP,
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;
