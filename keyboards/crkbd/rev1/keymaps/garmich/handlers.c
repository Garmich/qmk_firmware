#include "keydefs.h"

static bool ctl;

bool process_record_tilde(uint16_t keycode, bool pressed);
bool process_record_oneshot(uint16_t keycode, bool pressed);
bool process_record_navigate(uint16_t keycode, bool pressed);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool pressed = record->event.pressed;

  if (is_oneshot_layer_active()) {
    if (IS_LAYER_ON(TIL_LY) && !process_record_tilde(keycode, pressed)) return false;
    else if (!process_record_oneshot(keycode, pressed)) return false;
    // else if (IS_LAYER_ON(NUM_LY) && !process_record_number(keycode, pressed)) return false;
    // else if (IS_LAYER_ON(NAV_LY) && !process_record_navigate(keycode, pressed)) return false;
  } else if (!process_record_navigate(keycode, pressed)) return false;

  return true;
}

bool process_record_tilde(uint16_t keycode, bool pressed) {
  switch(keycode) {
    case KC_N:
      if (pressed) tap_code16(KC_TILD);
      break;

    case KC_SPC:
      if (pressed) tap_code16(KC_DQUO);
      break;

    default:
      if (pressed) tap_code16(KC_QUOT);
      break;
  }

  return true;
}

bool process_record_oneshot(uint16_t keycode, bool pressed) {
  uint8_t layer;
  uint8_t mods = get_mods();
  uint8_t oneshot_mods = get_oneshot_mods();
  uint8_t modifiers = (mods | oneshot_mods);

  if (IS_LAYER_ON(NUM_LY)) layer = NUM_LY;
  else if (IS_LAYER_ON(NAV_LY)) layer = NAV_LY;

  switch(keycode) {
    case GUI:
      if (pressed && (get_oneshot_layer_state() == ONESHOT_OTHER_KEY_PRESSED)) {
        set_oneshot_layer(layer, ONESHOT_TOGGLED);
      }
      else if ((pressed && get_oneshot_layer_state() == ONESHOT_TOGGLED)
      && (modifiers & (MOD_MASK_GUI))) {
        clear_oneshot_layer_state(ONESHOT_TOGGLED);
      }
      break;

    case ALT:
      if (pressed && (get_oneshot_layer_state() == ONESHOT_OTHER_KEY_PRESSED)) {
        set_oneshot_layer(layer, ONESHOT_TOGGLED);
      }
      else if ((pressed && get_oneshot_layer_state() == ONESHOT_TOGGLED)
      && (modifiers & (MOD_MASK_ALT))) {
        clear_oneshot_layer_state(ONESHOT_TOGGLED);
      }
      break;

    case CTL:
      if (pressed && (get_oneshot_layer_state() == ONESHOT_OTHER_KEY_PRESSED)) {
        set_oneshot_layer(layer, ONESHOT_TOGGLED);
      }
      else if ((pressed && get_oneshot_layer_state() == ONESHOT_TOGGLED)
      && (modifiers & (MOD_MASK_CTRL))) {
        clear_oneshot_layer_state(ONESHOT_TOGGLED);
      }
      break;

    case SFT:
      if (pressed && (get_oneshot_layer_state() == ONESHOT_OTHER_KEY_PRESSED)) {
        set_oneshot_layer(layer, ONESHOT_TOGGLED);
      } else if (!pressed && (get_oneshot_layer_state() == ONESHOT_TOGGLED)) {
        clear_oneshot_layer_state(ONESHOT_TOGGLED);
      }
      break;

    default:
      if ((modifiers & (MOD_MASK_CTRL | MOD_MASK_ALT | MOD_MASK_GUI))
      && (get_oneshot_layer_state() == ONESHOT_TOGGLED) && pressed) {
        clear_oneshot_layer_state(ONESHOT_TOGGLED);
      }
      break;
  }

  return true;
}

bool process_record_navigate(uint16_t keycode, bool pressed) {
  uint8_t mods = get_mods();
  uint8_t oneshot_mods = get_oneshot_mods();
  uint8_t modifiers = (mods | oneshot_mods);

  switch(keycode) {
    case CTL:
      if (!pressed && ctl) del_mods(MOD_MASK_CTRL);
      break;

    case SWITCH:
      if (pressed) {
        register_code(KC_LALT);
        tap_code(KC_TAB);
      } else unregister_code(KC_LALT);
      break;

    case KC_LEFT:
    case KC_RIGHT:
      if (!(modifiers & (MOD_MASK_GUI | MOD_MASK_ALT | MOD_MASK_CTRL))) {
        add_mods(MOD_MASK_CTRL);
        ctl = true;
      } else if ((oneshot_mods & MOD_MASK_CTRL) || (oneshot_mods & MOD_MASK_CS)) {
        del_oneshot_mods(MOD_MASK_CTRL);
      } else if ((mods & MOD_MASK_CTRL) || (mods & MOD_MASK_CS)) {
        del_mods(MOD_MASK_CTRL);
        ctl = false;
      }
      break;

  }

  return true;
}

void oneshot_locked_mods_changed_user(uint8_t mods) {
  if (mods) {
    unregister_mods(mods);
    del_oneshot_mods(mods);
    del_oneshot_locked_mods(mods);
  }
  if (mods & MOD_MASK_SHIFT) {
    tap_code(KC_CAPS);
  } else if (mods & MOD_MASK_CTRL) {
    if (get_oneshot_layer_state() == ONESHOT_TOGGLED) {
      clear_oneshot_layer_state(ONESHOT_TOGGLED);
    }
  }
}