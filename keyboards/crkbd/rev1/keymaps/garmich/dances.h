#pragma once

#include QMK_KEYBOARD_H
#include "taps.h"

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