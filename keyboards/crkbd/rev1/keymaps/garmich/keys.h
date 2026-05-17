#pragma once

#include "dances.h"

enum custom_keycodes {
  NULL_KEY =  SAFE_RANGE,
  SPCL     =  LT(NUM_LY, KC_SPC),
  ENTL     =  LT(SYM_LY, KC_ENT),
  SHFT     =  OSM(MOD_LSFT),
  CTRL     =  OSM(MOD_LCTL),
  ALTR     =  OSM(MOD_LALT),
  GUIW     =  OSM(MOD_LGUI),


  MT_S     =  LSFT_T(KC_S),
  MT_U     =  LCTL_T(KC_U),
  MT_R     =  LALT_T(KC_R),
  MT_T     =  LGUI_T(KC_T),

  MT_N     =  RSFT_T(KC_N),
  MT_C     =  RCTL_T(KC_C),
  MT_I     =  LALT_T(KC_I),
  MT_O     =  RGUI_T(KC_O),

  LT_A     =  LT(NAV_LY, KC_A),
  LT_E     =  LT(MOU_LY, KC_E),


  MT_LT    =  LGUI_T(KC_LT),
  MT_LBRC  =  LALT_T(KC_LBRC),
  MT_LCBR  =  LSFT_T(KC_LCBR),
  MT_LPRN  =  LCTL_T(KC_LPRN),
  MT_RPRN  =  RCTL_T(KC_RPRN),
  MT_RCBR  =  RSFT_T(KC_RCBR),
  MT_RBRC  =  LALT_T(KC_RBRC),
  MT_GT    =  RGUI_T(KC_GT),


  TD_A     =  TD(A_FN),
  TD_E     =  TD(E_FN),
  TD_I     =  TD(I_FN),
  TD_O     =  TD(O_FN),
  TD_U     =  TD(U_FN),
  TD_N     =  TD(N_FN),
};