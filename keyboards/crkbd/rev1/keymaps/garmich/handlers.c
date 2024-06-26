#include "keydefs.h"

/*
uint8_t mod_state;
uint8_t mod_one_state;
*/
bool process_record_tilde(uint16_t keycode, keyrecord_t *record, bool pressed);
bool process_record_grave(uint16_t keycode, keyrecord_t *record, bool pressed);
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool pressed = record->event.pressed;

  if (tilde && !process_record_tilde(keycode, record, pressed)) return false;
  else if (grave && !process_record_grave(keycode, record, pressed)) return false;

  switch (keycode) {
    case SWITCH:
      if (pressed) {
        register_code(KC_LALT);
        tap_code(KC_TAB);
      } else unregister_code(KC_LALT);
      break;

    case KC_QUOT:
      if (!pressed) tap_code(KC_SPC);
      break;

    case KC_DQUO:
      if (!pressed) tap_code(KC_SPC);
      break;

    case KC_A:
    case KC_E:
    case KC_I:
    case KC_O:
    case KC_U:
    case KC_C:
      if (pressed && IS_LAYER_ON(TIL_LY)) tap_code16(KC_QUOT);
      break;

    case KC_N:
      if (pressed && IS_LAYER_ON(TIL_LY)) tap_code16(S(KC_GRV));
      break;
  }

  return true;
}

bool process_record_tilde(uint16_t keycode, keyrecord_t *record, bool pressed) {
  switch(keycode) {
    case NAV:
    case NUM:
    case KC_NO:
      tilde = false;
      tap_code(KC_DOT);
      layer_off(TIL_LY);
      break;

    default:
      if(!pressed) {
        tilde = false;
        layer_off(TIL_LY);
      }
      break;
  }

  return true;
}

bool process_record_grave(uint16_t keycode, keyrecord_t *record, bool pressed) {
  switch(keycode) {
    case NAV:
    case NUM:
    case KC_NO:
      grave = false;
      tap_code(KC_COMM);
      layer_off(GRV_LY);
      break;

    case KC_MINS:
      if(!pressed) {
        grave = false;
        layer_off(GRV_LY);
      }
      break;

    case DEF:
      grave = false;
      break;
  }

  return true;
}