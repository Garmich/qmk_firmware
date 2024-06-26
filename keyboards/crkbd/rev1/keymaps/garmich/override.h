const key_override_t comma_ko = ko_make_with_layers_and_negmods(MOD_BIT(KC_RSFT), COMMA, KC_SCLN, ~0, MOD_MASK_CAG);

// const key_override_t comma_ko_ = ko_make_with_layers_and_negmods(MOD_BIT(KC_LSFT), COMMA, KC_GRV, ~0, MOD_MASK_CAG);

const key_override_t dot_ko = ko_make_with_layers_and_negmods(MOD_BIT(KC_LSFT), DOT, KC_COLN, ~0, MOD_MASK_CAG);

// const key_override_t dot_ko_ = ko_make_with_layers_and_negmods(MOD_BIT(KC_RSFT), DOT, ALGR(KC_QUOT), ~0, MOD_MASK_CAG);


const key_override_t bracket_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_PLUS, KC_RBRC, ~0, MOD_MASK_CAG);

const key_override_t parent_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_AMPR, KC_RPRN, ~0, MOD_MASK_CAG);

const key_override_t brace_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_PIPE, KC_RCBR, ~0, MOD_MASK_CAG);


const key_override_t mins_ko = {.trigger_mods           = MOD_MASK_CAG,
                                .layers                 = ~0,
                                .suppressed_mods        = 0,
                                .options                = ko_option_one_mod,
                                .negative_mod_mask      = 0,
                                .custom_action          = NULL,
                                .context                = NULL,
                                .trigger                = KC_PIPE,
                                .replacement            = KC_MINS,
                                .enabled                = NULL};

const key_override_t slas_ko = {.trigger_mods           = MOD_MASK_CAG,
                                .layers                 = ~0,
                                .suppressed_mods        = 0,
                                .options                = ko_option_one_mod,
                                .negative_mod_mask      = 0,
                                .custom_action          = NULL,
                                .context                = NULL,
                                .trigger                = KC_AMPR,
                                .replacement            = KC_PSLS,
                                .enabled                = NULL};


const key_override_t comm_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_COMM, KC_BSLS, ~0, MOD_MASK_CAG);

const key_override_t one_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_1, KC_QUES, ~0, MOD_MASK_CAG);

const key_override_t two_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_2, KC_DLR, ~0, MOD_MASK_CAG);

const key_override_t four_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_4, KC_AT, ~0, MOD_MASK_CAG);

const key_override_t six_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_6, KC_EXLM, ~0, MOD_MASK_CAG);

const key_override_t seven_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_7, KC_EQL, ~0, MOD_MASK_CAG);

const key_override_t eight_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_8, KC_LT, ~0, MOD_MASK_CAG);

const key_override_t nine_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_9, KC_GT, ~0, MOD_MASK_CAG);

const key_override_t zero_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_0, KC_ASTR, ~0, MOD_MASK_CAG);

const key_override_t dquo_ko = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_DQUO, KC_SLSH, ~0, MOD_MASK_CAG);


const key_override_t num_ko = ko_make_with_layers_and_negmods(MOD_MASK_CTRL, NUM, C(KC_BSPC), ~0, MOD_MASK_SAG);


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


// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &comma_ko,
    // &comma_ko_,
    &dot_ko,
    // &dot_ko_,

    &bracket_ko,
    &parent_ko,
    &brace_ko,

    &mins_ko,
    &slas_ko,

    &comm_ko,
    &one_ko,
    &two_ko,
    &four_ko,
    &six_ko,
    &seven_ko,
    &eight_ko,
    &nine_ko,
    &zero_ko,
    &dquo_ko,

    &num_ko,

    &up_ko,
    &dw_ko,
    &top_ko,
    &low_ko,
    &end_ko,
    &home_ko,
    &left_ko,
    &rght_ko,
    NULL // Null terminate the array of overrides!
};