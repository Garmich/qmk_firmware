#pragma once

#include QMK_KEYBOARD_H
#include "taps.h"

// ==========================================
// 3. MACRO PLANTILLA (El motor unificado)
// ==========================================
// Define dinámicamente las variables, la función _finished y la función _reset para cualquier tecla.
#define ACTION_TAP_DANCE_VOCAL(name, kc, hold_type, hold_value) \
    static td_tap_t name##_tap_state; \
    void name##_finished(tap_dance_state_t *state, void *user_data) { \
        name##_tap_state.state = cur_dance(state); \
        name##_tap_state.count = state->count; /* Guardamos los taps para el reset */ \
        switch (name##_tap_state.state) { \
            case TD_SINGLE_TAP: \
                tap_code(kc); \
                break; \
            case TD_SINGLE_HOLD: \
                if (hold_type == HOLD_IS_MOD || hold_type == HOLD_IS_KEY) { register_mods(MOD_BIT(hold_value)); } \
                else { layer_on(hold_value); } \
                break; \
            case TD_MULTI_TAP: \
                /* Ejecuta el bucle tantas veces como pulsaciones se hayan hecho */ \
                for (uint8_t i = 0; i < state->count; i++) { \
                    tap_code(kc); \
                } \
                break; \
            case TD_DOUBLE_HOLD: \
                if (hold_type == HOLD_IS_KEY) { tap_code16(KC_TILDE); } /* Tecla física para hacerla ñ en mapa español */ \
                else { tap_code(KC_QUOT); } /* Tecla física del acento en mapa español */ \
                tap_code(kc);  /* Presiona la vocal después del acento */ \
                break; \
            case TD_MULTI_HOLD: \
                register_code(kc); \
                break; \
            default: break; \
        } \
    } \
    void name##_reset(tap_dance_state_t *state, void *user_data) { \
        switch (name##_tap_state.state) { \
            case TD_SINGLE_HOLD: \
                if (hold_type == HOLD_IS_MOD || hold_type == HOLD_IS_KEY) { unregister_mods(MOD_BIT(hold_value)); } \
                else { layer_off(hold_value); } \
                break; \
            case TD_MULTI_HOLD: \
                unregister_code(kc); \
                break; \
            default: break; \
        } \
        name##_tap_state.state = TD_NONE; \
    }

// Generación automática del código para cada vocal usando la plantilla
// Parámetros: (Prefijo único, Código de tecla, Modificador en Hold, Índice Unicode)

ACTION_TAP_DANCE_VOCAL(vocal_a, KC_A, HOLD_IS_LAYER, NAV_LY)  // A -> Layer de navegación
ACTION_TAP_DANCE_VOCAL(vocal_e, KC_E, HOLD_IS_LAYER, MOU_LY)  // E -> Layer de mouse
ACTION_TAP_DANCE_VOCAL(vocal_i, KC_I, HOLD_IS_MOD, KC_LALT)   // I -> Alt
ACTION_TAP_DANCE_VOCAL(vocal_o, KC_O, HOLD_IS_MOD, KC_LGUI)   // O -> Tecla Windows/Cmd Derecha
ACTION_TAP_DANCE_VOCAL(vocal_u, KC_U, HOLD_IS_MOD, KC_LCTL)   // U -> Control Derecho
ACTION_TAP_DANCE_VOCAL(til_n, KC_N, HOLD_IS_KEY, KC_RSFT)     // N -> Shift Izquierdo


// 3. Tabla de acciones Tap Dance asignando vocal normal y su acento Unicode
tap_dance_action_t tap_dance_actions[] = {
    [A_FN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, vocal_a_finished, vocal_a_reset),
    [E_FN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, vocal_e_finished, vocal_e_reset),
    [I_FN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, vocal_i_finished, vocal_i_reset),
    [O_FN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, vocal_o_finished, vocal_o_reset),
    [U_FN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, vocal_u_finished, vocal_u_reset),
    [N_FN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, til_n_finished, til_n_reset)
};




/*
void nav_num_finished(tap_dance_state_t *state, void *user_data) {
    tap_state.state  = cur_dance(state);
    if (tap_state.state == TD_SINGLE_TAP) layer_move(NAV_LY);
    else layer_on(NUM_LY);
}

void nav_num_reset(tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (tap_state.state != TD_SINGLE_TAP) layer_off(NUM_LY);
    tap_state.state = TD_NONE;
}

void alp_sym_finished(tap_dance_state_t *state, void *user_data) {
    tap_state.state  = cur_dance(state);
    if (tap_state.state == TD_SINGLE_TAP) layer_move(ALP_LY);
    else layer_on(SYM_LY);
}

void alp_sym_reset(tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (tap_state.state != TD_SINGLE_TAP) layer_off(SYM_LY);
    tap_state.state = TD_NONE;
}

void nav_sym_finished(tap_dance_state_t *state, void *user_data) {
    tap_state.state  = cur_dance(state);
    if (tap_state.state == TD_SINGLE_TAP) layer_move(NAV_LY);
    else layer_on(SYM_LY);
}

void nav_sym_reset(tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (tap_state.state != TD_SINGLE_TAP) layer_off(SYM_LY);
    tap_state.state = TD_NONE;
}

void alp_num_finished(tap_dance_state_t *state, void *user_data) {
    tap_state.state  = cur_dance(state);
    if (tap_state.state == TD_SINGLE_TAP) layer_move(ALP_LY);
    else layer_on(NUM_LY);
}

void alp_num_reset(tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (tap_state.state != TD_SINGLE_TAP) layer_off(NUM_LY);
    tap_state.state = TD_NONE;
}
*/