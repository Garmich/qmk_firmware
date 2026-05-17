#pragma once

#include "enums.h"

typedef struct {
    td_state_t state;
    uint8_t count;
} td_tap_t;

td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        // Si otra tecla fue pulsada mientras mantienes (interrupted),
        // o si el temporizador TAPPING_TERM expiró con la tecla aún presionada,
        // actuamos como PERMISSIVE_HOLD y devolvemos SINGLE_HOLD (Modificador).
        if (state->interrupted || state->pressed) return TD_SINGLE_HOLD;
        else return TD_SINGLE_TAP;
    } else if (state->count == 2) {
        // Regla 4: Double Hold (segunda pulsación retenida)
        if (state->pressed) return TD_DOUBLE_HOLD;
        // Regla 3: Dos toques rápidos
        else return TD_MULTI_TAP;
    } else if (state->count >= 3) {
        // Regla 5: Triple hold o superior retenido
        if (state->pressed) return TD_MULTI_HOLD;
        // Regla 3 continuada: Tres o más taps rápidos continuos
        else return TD_MULTI_TAP;
    }
    return TD_NONE;
}