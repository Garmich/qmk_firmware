#include "keydefs.h"

bool process_tilde(uint16_t keycode, keyrecord_t *record);
bool process_grave(uint16_t keycode, keyrecord_t *record);
bool process_normal(uint16_t keycode, keyrecord_t *record);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  if (tilde) return process_tilde(keycode, record);
  else if (grave) return process_grave(keycode, record);
  else return process_normal(keycode, record);

}

bool process_normal(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SWITCH:
      if (record->event.pressed) {
        register_code(KC_LALT);
        tap_code(KC_TAB);
      } else unregister_code(KC_LALT);
      break;

    case TOP:
      if (record->event.pressed) {
        if ((get_oneshot_mods() & MOD_LCTL) || (get_mods() & MOD_MASK_CTRL)) {
          tap_code16(KC_HOME);
          return false;
        }
      }
      break;

    case LOW:
      if (record->event.pressed) {
        if ((get_oneshot_mods() & MOD_LCTL) || (get_mods() & MOD_MASK_CTRL)) {
          tap_code16(KC_END);
          return false;
        }
      }
      break;

    case INI:
      if ((get_oneshot_mods() & MOD_LCTL) || (get_mods() & MOD_LCTL)) {
        if (record->event.pressed) {
          del_mods(MOD_LCTL);
          del_oneshot_mods(MOD_LCTL);
          tap_code(KC_HOME);
          return false;
        }
      }
      break;

    case END:
      if ((get_oneshot_mods() & MOD_LCTL) || (get_mods() & MOD_LCTL)) {
        if (record->event.pressed) {
          del_mods(MOD_LCTL);
          del_oneshot_mods(MOD_LCTL);
          tap_code(KC_END);
          return false;
        }
      }
      break;

    case TIL:
      if ((get_oneshot_mods() & MOD_BIT(KC_RSFT)) || (get_mods() & MOD_BIT(KC_RSFT))) {
        if (record->event.pressed) {
          del_mods(MOD_BIT(KC_RSFT));
          del_oneshot_mods(MOD_BIT(KC_RSFT));
          tap_code(KC_GRV);
          tap_code(KC_SPC);
          return false;
        }
      }

    case GRV:
      if ((get_oneshot_mods() & MOD_LSFT || (get_mods() & MOD_LSFT))) {
        if (record->event.pressed) {
          del_mods(MOD_LSFT);
          del_oneshot_mods(MOD_LSFT);
          tap_code16(ALGR(KC_GRV));
          tap_code(KC_SPC);
          return false;
        }
      }

    case LT(NUM_LY, KC_BSPC):
      if (record->event.pressed) {
        if ((get_oneshot_mods() & MOD_LSFT) || (get_mods() & MOD_LSFT)) {
          tilde = true;
          return false;

        } else if ((get_oneshot_mods() & MOD_BIT(KC_RSFT)) || (get_mods() & MOD_BIT(KC_RSFT))) {
          grave = true;
          return false;
        }
      }
      break;

    case LT(NAVI_LY, KC_SPC):
      if (record->event.pressed) {
        if ((get_oneshot_mods() & MOD_LSFT) || (get_mods() & MOD_LSFT)) {
          del_mods(MOD_LSFT);
          del_oneshot_mods(MOD_LSFT);
          tap_code(KC_QUOT);

        } else if ((get_oneshot_mods() & MOD_BIT(KC_RSFT)) || (get_mods() & MOD_BIT(KC_RSFT))) {
          tap_code(KC_QUOT);
        }
      }
      break;
  }

  return true;
}

bool process_tilde(uint16_t keycode, keyrecord_t *record) {
  del_mods(MOD_LSFT);
  del_oneshot_mods(MOD_LSFT);
  switch(keycode) {
    case KC_A:
    case KC_E:
    case KC_I:
    case KC_O:
    case KC_U:
    case KC_C:
      if (record->event.pressed) tap_code(KC_QUOT);
      break;

    case KC_N:
      if (record->event.pressed) tap_code16(S(KC_GRV));
      break;

    case LT(NUM_LY, KC_BSPC):
      return false;

    default:
      break;
  }

  tilde = false;
  return true;
}

bool process_grave(uint16_t keycode, keyrecord_t *record) {
  del_mods(MOD_BIT(KC_RSFT));
  del_oneshot_mods(MOD_BIT(KC_RSFT));
  switch(keycode) {
    case KC_A:
    case KC_E:
    case KC_O:
      if (record->event.pressed) tap_code16(KC_GRV);
      break;

    case KC_I:
    case KC_U:
      if (record->event.pressed) tap_code16(S(KC_QUOT));
      break;

    case LT(NUM_LY, KC_BSPC):
      return false;

    default:
      break;
  }

  grave = false;
  return true;
}

   /*  if ((get_oneshot_mods() & MOD_LSFT) || (get_mods() & MOD_LSFT)) {
        if (record->event.pressed) tap_code(KC_A);
        else tap_code(KC_C);
        return false;
      } else if ((get_oneshot_mods() & MOD_BIT(KC_RSFT)) || (get_mods() & MOD_BIT(KC_RSFT))) {
        if (record->event.pressed) tap_code(KC_B);
        else tap_code(KC_D);
        return false;
      }
      break; */
/*
      if (!record->event.pressed) {
        if(til_prs) tilde = true;
        else if (grv_prs) grave = true;
      }
      return !til_prs && !grv_prs;
*/
/*
      if (record->event.pressed) {
        return !til_prs && !grv_prs;
      } else {
        if(til_prs) {
          til_prs = false;
          tilde = true;
        } else if (grv_prs) {
          grv_prs = false;
          grave = true;
        }
        return !til_prs && !grv_prs;
      }
*/
/*
    case TIL:
      if (record->event.pressed) {
        // add_oneshot_mods(MOD_LSFT);
        til_prs = true;
      }
      break;

    case GRV:
      if (record->event.pressed) {
        // add_oneshot_mods(MOD_LSFT);
        grv_prs = true;
      }
      break;
 */
/*
    case LT(NAVI_LY, KC_SPC):
      if (record->event.pressed) {
        if (til_prs) tap_code(KC_QUOT);
        else if (grv_prs) tap_code16(S(KC_QUOT));
      } else {
        til_prs = false;
        grv_prs = false;
      }
      break;
*/
/*
    default:
      if (record->event.pressed) {
        til_prs = false;
        grv_prs = false;
        add_oneshot_mods(MOD_LSFT);
      }
      break;
*/