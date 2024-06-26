#pragma once
#include "dance.h"

enum layers{
	DEF_LY = 0,
	NUM_LY,
	NAV_LY,
	TIL_LY,
	GRV_LY,
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
  LSFT = OSM(MOD_LSFT),
  RSFT = OSM(MOD_RSFT),
  CTL = OSM(MOD_LCTL),
  ALT = OSM(MOD_LALT),
  GUI = OSM(MOD_LGUI),
  JWIN = LGUI_T(KC_J),
  FWIN = LGUI_T(KC_F),
  NAV = LT(NAV_LY, KC_SPC),
  NUM = LT(NUM_LY, KC_ENT),
  GAME = TO(GAM_LY),
  DEF = TO(DEF_LY),
  EXIT = A(KC_F4),
};

static bool grave = false;
static bool tilde = false;