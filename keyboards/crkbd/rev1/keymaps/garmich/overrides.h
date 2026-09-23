#pragma once
#include "keys.h"
#include QMK_KEYBOARD_H

const key_override_t comma_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_COMM, KC_SCLN, ~0, MOD_MASK_CAG);

const key_override_t dot_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_DOT, KC_COLN, ~0, MOD_MASK_CAG);

const key_override_t delete_ko = ko_make_with_layers_and_negmods(MOD_MASK_CA, KC_BSPC, LCA(KC_DEL), ~0, MOD_MASK_SG);

const key_override_t kvm_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KVM, MEH(KC_COMM), ~0, MOD_MASK_CAG);


const key_override_t **key_overrides = (const key_override_t *[]){
    &comma_ko,
    &dot_ko,
    &delete_ko,
    &kvm_ko,
};