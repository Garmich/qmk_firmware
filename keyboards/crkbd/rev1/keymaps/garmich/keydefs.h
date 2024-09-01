#pragma once
#include "dance.h"

enum layers{
	DEF_LY = 0,
	NUM_LY,
	NAV_LY,
	TIL_LY,
  GAM_LY,
};

enum custom_keycodes {
  NULL_KEY = SAFE_RANGE,
  SWITCH,
  COMMA = TD(TD_COMMA),
  DOT = TD(TD_DOT),
  TOP = KC_PGUP,
  LOW = KC_PGDN,
  HOM = C(KC_LEFT),
  END = C(KC_RIGHT),
  LSFT = TD(TD_SFT_CAPS),
  // LSFT = OSM(MOD_LSFT),
  RSFT = OSM(MOD_RSFT),
  CTL = OSM(MOD_LCTL),
  ALT = OSM(MOD_LALT),
  GUI = OSM(MOD_LGUI),
  NAV1 = LT(NAV_LY, KC_SPC),
  NAV2 = LT(NAV_LY, KC_ENT),
  GAME = TO(GAM_LY),
  DEF = TO(DEF_LY),
  EXIT = A(KC_F4),
};