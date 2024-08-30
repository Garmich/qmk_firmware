#include "quantum.h"
#include "dance.h"

void dot_finished(tap_dance_state_t *state, void *user_data);
void dot_reset(tap_dance_state_t *state, void *user_data);
void comma_finished(tap_dance_state_t *state, void *user_data);
void comma_reset(tap_dance_state_t *state, void *user_data);

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

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
  [TD_DOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dot_finished, dot_reset),
  [TD_COMMA] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, comma_finished, comma_reset),
};

td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

void comma_finished(tap_dance_state_t *state, void *user_data) {
    tap_state.state  = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_HOLD:
            layer_on(GRV_LY);
            break;

        case TD_SINGLE_TAP:
            grave = true;
            layer_on(GRV_LY);
            break;

        default:
            tap_code16(C(KC_C));
            grave = true;
            layer_on(GRV_LY);
            break;
    }
}

void comma_reset(tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (tap_state.state == TD_SINGLE_HOLD) {
        layer_off(GRV_LY);
    }
    tap_state.state = TD_NONE;
}

void dot_finished(tap_dance_state_t *state, void *user_data) {
    tap_state.state  = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_HOLD:
            layer_on(NUM_LY);
            break;

        case TD_SINGLE_TAP:
            tilde = true;
            layer_on(TIL_LY);
            break;
        default:
            tap_code(KC_COMM);
            // tilde = true;
            break;
    }
}

void dot_reset(tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (tap_state.state == TD_SINGLE_HOLD) {
        layer_off(NUM_LY);
    }
    tap_state.state = TD_NONE;
}