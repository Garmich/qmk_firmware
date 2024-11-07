const key_override_t comma_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_COMM, KC_SCLN, ~0, MOD_MASK_CAG);

const key_override_t dot_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_DOT, KC_COLN, ~0, MOD_MASK_CAG);


const key_override_t bracket_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_LBRC, KC_RBRC, ~0, MOD_MASK_CAG);

const key_override_t parent_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_LPRN, KC_RPRN, ~0, MOD_MASK_CAG);

const key_override_t brace_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_LCBR, KC_RCBR, ~0, MOD_MASK_CAG);


const key_override_t slash_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_QUES, KC_PSLS, ~0, MOD_MASK_CAG);

const key_override_t comen_ko = {.trigger_mods           = MOD_MASK_CAG,
                                 .layers                 = ~0,
                                 .suppressed_mods        = 0,
                                 .options                = ko_option_one_mod,
                                 .negative_mod_mask      = 0,
                                 .custom_action          = NULL,
                                 .context                = NULL,
                                 .trigger                = KC_QUES,
                                 .replacement            = KC_PSLS,
                                 .enabled                = NULL};


const key_override_t one_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_1, KC_ASTR, ~0, MOD_MASK_CAG);

const key_override_t four_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_4, KC_AMPR, ~0, MOD_MASK_CAG);

const key_override_t five_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_5, KC_EQL, ~0, MOD_MASK_CAG);

const key_override_t six_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_6, KC_PIPE, ~0, MOD_MASK_CAG);

const key_override_t seven_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_7, KC_LT, ~0, MOD_MASK_CAG);

const key_override_t eight_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_8, KC_EXLM, ~0, MOD_MASK_CAG);

const key_override_t nine_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_9, KC_GT, ~0, MOD_MASK_CAG);

const key_override_t zero_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_0, KC_BSLS, ~0, MOD_MASK_CAG);


const key_override_t enter_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_BSPC, S(KC_ENT), ~0, MOD_MASK_CAG);

/*
const key_override_t delete_ko = ko_make_with_layers_and_negmods(MOD_MASK_CA, KC_BSPC, LCA(KC_BSPC), ~0, MOD_MASK_SG);


const key_override_t mod_left_ko = ko_make_with_layers_and_negmods(MOD_MASK_CTRL, LEFT, KC_LEFT, ~0, MOD_MASK_AG);

const key_override_t mod_right_ko = ko_make_with_layers_and_negmods(MOD_MASK_CTRL, RIGHT, KC_RIGHT, ~0, MOD_MASK_AG);

const key_override_t left_ko = {.trigger_mods           = MOD_MASK_AG,
                                .layers                 = ~0,
                                .suppressed_mods        = 0,
                                .options                = ko_option_one_mod,
                                .negative_mod_mask      = 0,
                                .custom_action          = NULL,
                                .context                = NULL,
                                .trigger                = LEFT,
                                .replacement            = KC_LEFT,
                                .enabled                = NULL};

const key_override_t right_ko = {.trigger_mods           = MOD_MASK_AG,
                                .layers                 = ~0,
                                .suppressed_mods        = 0,
                                .options                = ko_option_one_mod,
                                .negative_mod_mask      = 0,
                                .custom_action          = NULL,
                                .context                = NULL,
                                .trigger                = RIGHT,
                                .replacement            = KC_RIGHT,
                                .enabled                = NULL};

*/


// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &comma_ko,
    &dot_ko,

    &bracket_ko,
    &parent_ko,
    &brace_ko,

    &slash_ko,
    &comen_ko,

    &one_ko,
    &four_ko,
    &five_ko,
    &six_ko,
    &seven_ko,
    &eight_ko,
    &nine_ko,
    &zero_ko,

    &enter_ko,
/*
    &delete_ko,

    &left_ko,
    &mod_left_ko,

    &right_ko,
    &mod_right_ko,
*/
    NULL // Null terminate the array of overrides!
};