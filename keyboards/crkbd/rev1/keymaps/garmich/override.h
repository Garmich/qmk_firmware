const key_override_t comma_ko = ko_make_with_layers_and_negmods(MOD_BIT(KC_RSFT), COMMA, KC_SCLN, ~0, MOD_MASK_CAG);

// const key_override_t comma_ko_ = ko_make_with_layers_and_negmods(MOD_BIT(KC_LSFT), COMMA, KC_GRV, ~0, MOD_MASK_CAG);

const key_override_t dot_ko = ko_make_with_layers_and_negmods(MOD_BIT(KC_LSFT), DOT, KC_COLN, ~0, MOD_MASK_CAG);

// const key_override_t dot_ko_ = ko_make_with_layers_and_negmods(MOD_BIT(KC_RSFT), DOT, ALGR(KC_QUOT), ~0, MOD_MASK_CAG);


const key_override_t bracket_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_RBRC, KC_LBRC, ~0, MOD_MASK_CAG);

const key_override_t parent_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_RPRN, KC_LPRN, ~0, MOD_MASK_CAG);

const key_override_t brace_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_RCBR, KC_LCBR, ~0, MOD_MASK_CAG);


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

const key_override_t five_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_5, KC_EXLM, ~0, MOD_MASK_CAG);

const key_override_t six_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_6, KC_PIPE, ~0, MOD_MASK_CAG);

const key_override_t seven_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_7, KC_LT, ~0, MOD_MASK_CAG);

const key_override_t eight_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_8, KC_EQL, ~0, MOD_MASK_CAG);

const key_override_t nine_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_9, KC_GT, ~0, MOD_MASK_CAG);

const key_override_t zero_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_0, KC_BSLS, ~0, MOD_MASK_CAG);


const key_override_t delete_ko = ko_make_with_layers_and_negmods(MOD_MASK_CTRL, NAV, C(KC_BSPC), ~0, MOD_MASK_SAG);


const key_override_t home_ko = {.trigger_mods           = MOD_MASK_AG,
                                .layers                 = ~0,
                                .suppressed_mods        = 0,
                                .options                = ko_option_one_mod,
                                .negative_mod_mask      = 0,
                                .custom_action          = NULL,
                                .context                = NULL,
                                .trigger                = HOM,
                                .replacement            = KC_LEFT,
                                .enabled                = NULL};

const key_override_t left_ko = ko_make_with_layers_and_negmods(MOD_MASK_CTRL, HOM, KC_LEFT, ~0, MOD_MASK_AG);

const key_override_t end_ko = { .trigger_mods           = MOD_MASK_AG,
                                .layers                 = ~0,
                                .suppressed_mods        = 0,
                                .options                = ko_option_one_mod,
                                .negative_mod_mask      = 0,
                                .custom_action          = NULL,
                                .context                = NULL,
                                .trigger                = END,
                                .replacement            = KC_RIGHT,
                                .enabled                = NULL};

const key_override_t rght_ko = ko_make_with_layers_and_negmods(MOD_MASK_CTRL, END, KC_RIGHT, ~0, MOD_MASK_AG);

const key_override_t clip_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, SWITCH, G(KC_V), ~0, MOD_MASK_CAG);
/*
const key_override_t top_ko = { .trigger_mods           = MOD_MASK_CSAG,
                                .layers                 = ~0,
                                .suppressed_mods        = 0,
                                .options                = ko_option_one_mod,
                                .negative_mod_mask      = 0,
                                .custom_action          = NULL,
                                .context                = NULL,
                                .trigger                = TOP,
                                .replacement            = KC_UP,
                                .enabled                = NULL};

const key_override_t low_ko = { .trigger_mods           = MOD_MASK_CSAG,
                                .layers                 = ~0,
                                .suppressed_mods        = 0,
                                .options                = ko_option_one_mod,
                                .negative_mod_mask      = 0,
                                .custom_action          = NULL,
                                .context                = NULL,
                                .trigger                = LOW,
                                .replacement            = KC_DOWN,
                                .enabled                = NULL};

const key_override_t up_ko = {  .trigger_mods           = MOD_MASK_CSAG,
                                .layers                 = ~0,
                                .suppressed_mods        = 0,
                                .options                = ko_option_one_mod,
                                .negative_mod_mask      = 0,
                                .custom_action          = NULL,
                                .context                = NULL,
                                .trigger                = KC_UP,
                                .replacement            = KC_PGUP,
                                .enabled                = NULL};

const key_override_t dw_ko = {  .trigger_mods           = MOD_MASK_CSAG,
                                .layers                 = ~0,
                                .suppressed_mods        = 0,
                                .options                = ko_option_one_mod,
                                .negative_mod_mask      = 0,
                                .custom_action          = NULL,
                                .context                = NULL,
                                .trigger                = KC_DOWN,
                                .replacement            = KC_PGDN,
                                .enabled                = NULL};

const key_override_t home_ko = {.trigger_mods           = MOD_MASK_CSAG,
                                .layers                 = ~0,
                                .suppressed_mods        = 0,
                                .options                = ko_option_one_mod,
                                .negative_mod_mask      = 0,
                                .custom_action          = NULL,
                                .context                = NULL,
                                .trigger                = HOM,
                                .replacement            = KC_HOME,
                                .enabled                = NULL};

const key_override_t end_ko = { .trigger_mods           = MOD_MASK_CSAG,
                                .layers                 = ~0,
                                .suppressed_mods        = 0,
                                .options                = ko_option_one_mod,
                                .negative_mod_mask      = 0,
                                .custom_action          = NULL,
                                .context                = NULL,
                                .trigger                = END,
                                .replacement            = KC_END,
                                .enabled                = NULL};

const key_override_t left_ko = {.trigger_mods           = MOD_MASK_CTRL,
                                .layers                 = ~0,
                                .suppressed_mods        = MOD_MASK_CTRL,
                                .options                = ko_option_one_mod,
                                .negative_mod_mask      = MOD_MASK_SAG,
                                .custom_action          = NULL,
                                .context                = NULL,
                                .trigger                = KC_LEFT,
                                .replacement            = KC_HOME,
                                .enabled                = NULL};

const key_override_t rght_ko = {.trigger_mods           = MOD_MASK_CTRL,
                                .layers                 = ~0,
                                .suppressed_mods        = MOD_MASK_CTRL,
                                .options                = ko_option_one_mod,
                                .negative_mod_mask      = MOD_MASK_SAG,
                                .custom_action          = NULL,
                                .context                = NULL,
                                .trigger                = KC_RIGHT,
                                .replacement            = KC_END,
                                .enabled                = NULL};
*/


// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &comma_ko,
    // &comma_ko_,
    &dot_ko,
    // &dot_ko_,

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

    &delete_ko,

    // &up_ko,
    // &dw_ko,
    //&top_ko,
    //&low_ko,
    &end_ko,
    &home_ko,
    &left_ko,
    &rght_ko,

    &clip_ko,
    NULL // Null terminate the array of overrides!
};