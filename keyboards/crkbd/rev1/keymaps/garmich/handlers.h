#pragma once

#include "keys.h"

/*
bool process_record_oneshot(uint16_t keycode, keyrecord_t *record);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (is_oneshot_layer_active() && !process_record_oneshot(keycode, record)) return false;

  switch(keycode) {
    case KC_TILD:
    case KC_QUOT:
    case KC_CAPS:
      if (record->event.pressed && get_highest_layer(layer_state) != ALP_LY) {
        layer_move(ALP_LY);
      }
      break;
  }

  return true;
}

void matrix_scan_user(void) {
  if (get_highest_layer(layer_state) == ALP_LY) {
    if(last_input_activity_elapsed() > NUM_LAYER_TIMEOUT) {
      layer_clear();
    }
  }
}

bool process_record_oneshot(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case E_MT:
    case A_MT:
    case O_MT:
    case I_MT:
    case S_MT:
    case N_MT:
    case D_MT:
    case R_MT:
      if (record->event.pressed && record->tap.count < 1) {
        set_oneshot_layer(ALP_LY, ONESHOT_TOGGLED);
      } else if (!record->event.pressed) {
        uint8_t mods = get_mods() & MOD_MASK_CSAG;
        if (mods && ((mods & (mods - 1)) == 0)) {
          clear_oneshot_layer_state(ONESHOT_TOGGLED);
        }
      }
      break;
    }
  return true;
}
*/