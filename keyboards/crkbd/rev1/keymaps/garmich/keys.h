#pragma once

#include "enums.h"

//  Alias para Layer-Taps
#define SPCL     LT(NAV_LY, KC_SPC)
#define ENTL     LT(SYM_LY, KC_ENT)
#define TABL     LT(NUM_LY, KC_TAB)
#define QUTL     LT(MOU_LY, KC_QUOT)

// Alias para One-Shot Modifiers
#define SHFT     OSM(MOD_LSFT)
#define CTRL     OSM(MOD_LCTL)
#define ALTR     OSM(MOD_LALT)
#define LWIN     OSM(MOD_LGUI)

// Alias para Mod-Taps
#define MT_LT    LSFT_T(KC_LT)
#define MT_GT    LCTL_T(KC_GT)
#define MT_EXLM  LALT_T(KC_EXLM)
#define MT_EQL   LGUI_T(KC_EQL)

#define MT_LBRC  LGUI_T(KC_LBRC)
#define MT_PSLS  LALT_T(KC_PSLS)
#define MT_LCBR  LCTL_T(KC_LCBR)
#define MT_LPRN  LSFT_T(KC_LPRN)

#define MT_RPRN  LSFT_T(KC_RPRN)
#define MT_RCBR  LCTL_T(KC_RCBR)
#define MT_BSLS  LALT_T(KC_BSLS)
#define MT_RBRC  LGUI_T(KC_RBRC)

// Alias para Custom Keys
#define KVM      MEH(KC_DOT)
#define CK_QUES  RALT(KC_QUES)
#define CK_GRV  RALT(KC_QUOT)