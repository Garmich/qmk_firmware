#pragma once
#include "dance.h"

enum layers{
	DEF_LY = 0,
	TIL_LY,
	NUM_LY,
	NAV_LY,
};

enum custom_keycodes {
  NULL_KEY = SAFE_RANGE,
  SWITCH,
  EXIT    =   A(KC_F4),
  DEF     =   TO(DEF_LY),
  TIL     =   TO(TIL_LY),
  TILOSL  =   OSL(TIL_LY),
  NAVOSL  =   OSL(NAV_LY),
  NUMOSL  =   OSL(NUM_LY),
  SFT     =   OSM(MOD_LSFT),
  CTL     =   OSM(MOD_LCTL),
  ALT     =   OSM(MOD_LALT),
  GUI     =   OSM(MOD_LGUI),
  SPCNAV  =   LT(NUM_LY, KC_SPC),
  ENTNAV  =   LT(NAV_LY, KC_ENT),
};