#pragma once

enum layers{
	BASE_LY = 0,
  GAME_LY,
	NAVI_LY,
	NUM_LY,
	SYM_LY,
};

enum custom_keycodes {
  NULL_KEY = SAFE_RANGE,
  SWITCH,
  LOW = KC_PGDN,
  TOP = KC_PGUP,
  INI = C(KC_LEFT),
  END = C(KC_RIGHT),
  TIL = OSM(MOD_LSFT),
  GRV = OSM(MOD_RSFT),
  SFT = OSM(MOD_LSFT),
  CTL = OSM(MOD_LCTL),
  ALT = OSM(MOD_LALT),
  GUI = OSM(MOD_LGUI),
};


static bool tilde = false;
static bool grave = false;
// static bool til_prs = false;
// static bool grv_prs = false;
