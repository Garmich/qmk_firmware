#pragma once
#include "keys.h"
#include QMK_KEYBOARD_H

// Alphabet layout overrides
const key_override_t comma_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_COMM, KC_SCLN, ~0, MOD_MASK_CAG);

const key_override_t dot_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_DOT, KC_COLN, ~0, MOD_MASK_CAG);

const key_override_t delete_ko = ko_make_with_layers_and_negmods(MOD_MASK_CA, KC_BSPC, LCA(KC_DEL), ~0, MOD_MASK_SG);

const key_override_t exit_ko = ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_F5, A(KC_F4), ~0, MOD_MASK_CSG);

// Number layout overrides
const key_override_t zero_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_0, KC_CIRC, ~0, MOD_MASK_CAG);

const key_override_t one_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_1, KC_DLR, ~0, MOD_MASK_CAG);

const key_override_t two_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_2, KC_TILD, ~0, MOD_MASK_CAG);

const key_override_t three_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_3, KC_PERC, ~0, MOD_MASK_CAG);

const key_override_t four_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_4, KC_LT, ~0, MOD_MASK_CAG);

const key_override_t five_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_5, KC_EQL, ~0, MOD_MASK_CAG);

const key_override_t six_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_6, KC_GT, ~0, MOD_MASK_CAG);

const key_override_t seven_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_7, KC_GRV, ~0, MOD_MASK_CAG);

const key_override_t eight_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_8, KC_EXLM, ~0, MOD_MASK_CAG);

const key_override_t nine_ko =  {.trigger_mods           = MOD_MASK_SHIFT,
                                 .layers                 = ~0,
                                 .suppressed_mods        = MOD_MASK_SHIFT,
                                 .options                = ko_options_default,
                                 .negative_mod_mask      = MOD_MASK_CAG,
                                 .custom_action          = NULL,
                                 .context                = NULL,
                                 .trigger                = KC_9,
                                 .replacement            = SAGR(KC_QUOT),
                                 .enabled                = NULL};

// Other overrides
const key_override_t amp_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_MINS, KC_AT, ~0, MOD_MASK_CAG);

const key_override_t pipe_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_UNDS, KC_HASH, ~0, MOD_MASK_CAG);

const key_override_t hash_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_EXLM, KC_PIPE, ~0, MOD_MASK_CAG);

const key_override_t at_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_QUES, KC_AMPR, ~0, MOD_MASK_CAG);


const key_override_t plus_ko =  {.trigger_mods           = MOD_MASK_CAG,
                                 .layers                 = ~0,
                                 .suppressed_mods        = 0,
                                 .options                = ko_option_one_mod,
                                 .negative_mod_mask      = 0,
                                 .custom_action          = NULL,
                                 .context                = NULL,
                                 .trigger                = KC_UNDS,
                                 .replacement            = KC_PLUS,
                                 .enabled                = NULL};

const key_override_t comen_ko = {.trigger_mods           = MOD_MASK_CS,
                                 .layers                 = ~0,
                                 .suppressed_mods        = 0,
                                 .options                = ko_option_one_mod,
                                 .negative_mod_mask      = MOD_MASK_AG,
                                 .custom_action          = NULL,
                                 .context                = NULL,
                                 .trigger                = C(KC_C),
                                 .replacement            = KC_PSLS,
                                 .enabled                = NULL};


const key_override_t bracket_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_LBRC, KC_RBRC, ~0, MOD_MASK_CAG);

const key_override_t parent_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_LPRN, KC_RPRN, ~0, MOD_MASK_CAG);

const key_override_t brace_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_LCBR, KC_RCBR, ~0, MOD_MASK_CAG);


const key_override_t slash_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_PSLS, KC_BSLS, ~0, MOD_MASK_CAG);

const key_override_t mins_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_PLUS, KC_MINS, ~0, MOD_MASK_CAG);

/*
const key_override_t left_ko = ko_make_with_layers_and_negmods(MOD_MASK_CTRL, KC_LEFT, KC_LEFT, ~0, MOD_MASK_AG);

const key_override_t left_word_ko = ko_make_with_layers_and_negmods(0, KC_LEFT, C(KC_LEFT), ~0, MOD_MASK_CAG);

const key_override_t right_ko = ko_make_with_layers_and_negmods(MOD_MASK_CTRL, KC_RIGHT, KC_RIGHT, ~0, MOD_MASK_AG);

const key_override_t right_word_ko = ko_make_with_layers_and_negmods(0, KC_RIGHT, C(KC_RIGHT), ~0, MOD_MASK_CAG);
*/

const key_override_t **key_overrides = (const key_override_t *[]){
    &exit_ko,

    &comma_ko,
    &dot_ko,
    &amp_ko,
    &pipe_ko,
    &hash_ko,
    &at_ko,

    &plus_ko,
    &comen_ko,

    &bracket_ko,
    &parent_ko,
    &brace_ko,

    &slash_ko,
    &mins_ko,


    &zero_ko,
    &one_ko,
    &two_ko,
    &three_ko,
    &four_ko,
    &five_ko,
    &six_ko,
    &seven_ko,
    &eight_ko,
    &nine_ko,

    &delete_ko,
/*
    &left_ko,
    &left_word_ko,

    &right_ko,
    &right_word_ko,
 */
    NULL // Null terminate the array of overrides!
};