#include "quantum.h"
#include "dance.h"

void dot_finished(tap_dance_state_t *state, void *user_data);
void dot_reset(tap_dance_state_t *state, void *user_data);
void comma_finished(tap_dance_state_t *state, void *user_data);
void comma_reset(tap_dance_state_t *state, void *user_data);
void sftc_finished(tap_dance_state_t *state, void *user_data);
void sftc_reset(tap_dance_state_t *state, void *user_data);

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
  [TD_COMMA] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, comma_finished, comma_reset),
  [TD_DOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dot_finished, dot_reset),
  [TD_SFT_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sftc_finished, sftc_reset),
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
            layer_on(NUM_LY);
            break;

        case TD_SINGLE_TAP:
            set_oneshot_layer(NUM_LY, ONESHOT_START);
            clear_oneshot_layer_state(ONESHOT_PRESSED);
            break;

        default:
            layer_on(NUM_LY);
            break;
    }
}

void comma_reset(tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (tap_state.state == TD_SINGLE_HOLD) {
        layer_off(NUM_LY);
    }
    tap_state.state = TD_NONE;
}

void dot_finished(tap_dance_state_t *state, void *user_data) {
    tap_state.state  = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_HOLD:
            layer_on(TIL_LY);
            break;

        case TD_SINGLE_TAP:
            set_oneshot_layer(TIL_LY, ONESHOT_START);
            clear_oneshot_layer_state(ONESHOT_PRESSED);
            break;
        default:
            layer_on(TIL_LY);
            break;
    }
}

void dot_reset(tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (tap_state.state == TD_SINGLE_HOLD) {
        layer_off(TIL_LY);
    }
    tap_state.state = TD_NONE;
}

void sftc_finished(tap_dance_state_t *state, void *user_data) {
    tap_state.state  = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_HOLD:
            add_mods(MOD_BIT(KC_LSFT));
            break;

        case TD_SINGLE_TAP:
            add_oneshot_mods(MOD_BIT(KC_LSFT));
            break;

        default:
            tap_code16(KC_No);
            break;
    }
}

void sftc_reset(tap_dance_state_t *state, void *user_data) {
    tap_state.state = TD_NONE;
}