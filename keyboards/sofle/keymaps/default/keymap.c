// -*- whitespace-line-column: 200 -*-
// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _GALLIUM,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_SPOT = QK_USER,
    KC_DICT,
    KC_DND,
    KC_LOCK
};

#define KC_QWERTY PDF(_QWERTY)
#define KC_GALLIUM PDF(_GALLIUM)

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
           'L', 'L', 'L', 'L', 'L', 'L',            'R', 'R', 'R', 'R', 'R', 'R',
           'L', 'L', 'L', 'L', 'L', 'L',            'R', 'R', 'R', 'R', 'R', 'R',
           'L', 'L', 'L', 'L', 'L', 'L',            'R', 'R', 'R', 'R', 'R', 'R',
           'L', 'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R', 'R',
                     '*', '*', '*', '*', '*',  '*', '*', '*', '*', '*'
    );

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT(
  KC_GRV,           KC_1,         KC_2,         KC_3,         KC_4,    KC_5,                      KC_6,         KC_7,         KC_8,         KC_9,            KC_0,  KC_MINS,
  KC_TAB,           KC_Q,         KC_W,         KC_E,         KC_R,    KC_T,                      KC_Y,         KC_U,         KC_I,         KC_O,            KC_P,  KC_BSPC,
  KC_ESC,   LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F),    KC_G,                      KC_H, RSFT_T(KC_J), RCTL_T(KC_K), LALT_T(KC_L), RGUI_T(KC_SCLN),  KC_QUOT,
  LSFT_T(CW_TOGG),  KC_Z,         KC_X,         KC_C,         KC_V,    KC_B, KC_MUTE,     XXXXXXX,KC_N,         KC_M,      KC_COMM,       KC_DOT,         KC_SLSH,  RSFT_T(CW_TOGG),
                            KC_LGUI,      KC_LALT,      KC_LCTL, TT(_LOWER),  KC_ENT,      KC_SPC,  TT(_RAISE), KC_RCTL,      KC_LALT,      KC_RGUI
),
/*
 * GALLIUM
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   B  |   L  |   D  |   C  |   V  |                    |   J  |   Y  |   O  |   U  |   ,  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  |   N  |   R  |   T  |   S  |   G  |-------.    ,-------|   P  |   H  |   A  |   E  |   I  |  /   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   X  |   Q  |   M  |   W  |   Z  |-------|    |-------|   K  |   F  |   '  |   ;  |   .  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_GALLIUM] = LAYOUT(
  KC_GRV,         KC_1,         KC_2,         KC_3,         KC_4,    KC_5,                        KC_6,         KC_7,         KC_8,         KC_9,         KC_0,  KC_MINS,
  KC_TAB,         KC_B,         KC_L,         KC_D,         KC_C,    KC_V,                        KC_J,         KC_Y,         KC_O,         KC_U,      KC_COMM,  KC_BSPC,
  KC_ESC, LGUI_T(KC_N), LALT_T(KC_R), LCTL_T(KC_T), LSFT_T(KC_S),    KC_G,                        KC_P, RSFT_T(KC_H), RCTL_T(KC_A), LALT_T(KC_E), RGUI_T(KC_I),  KC_SLSH,
  LSFT_T(CW_TOGG),KC_X,         KC_Q,         KC_M,         KC_W,    KC_Z, KC_MUTE,      XXXXXXX, KC_K,         KC_F,      KC_QUOT,      KC_SCLN,       KC_DOT,  RSFT_T(CW_TOGG),
                                      KC_LGUI, KC_LALT, TT(_LOWER), KC_ENT, KC_ENT,       KC_SPC, KC_SPC, TT(_RAISE), KC_LALT, KC_RGUI
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   ^  |   &  |   *  |   (  |   )  |                    |   <  |   7  |   8  |   9  |   [  |   ]  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  :   |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   +  |   4  |   5  |   6  |   {  |   }  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |  ;   |  =   |  -   |   |  |   >  |   ~  |-------|    |-------|   0  |   1  |   2  |   3  |   \  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
  _______,         _______,       _______,         _______,        _______,  _______,                         _______,         _______,         _______,         _______,        _______,  _______,
   KC_GRV,         KC_CIRC,       KC_AMPR,         KC_ASTR,        KC_LPRN,  KC_RPRN,                           KC_LT,            KC_7,            KC_8,            KC_9,         KC_LBRC, KC_RBRC,
  KC_COLN, LGUI_T(KC_EXLM), LALT_T(KC_AT), LCTL_T(KC_HASH), LSFT_T(KC_DLR),  KC_PERC,                         KC_PLUS,    RSFT_T(KC_4),    RCTL_T(KC_5),    LALT_T(KC_6), RGUI_T(KC_LCBR), KC_RCBR,
  KC_SCLN,          KC_EQL,       KC_MINS,         KC_PIPE,          KC_GT, KC_TILDE, _______,       _______,    KC_0,            KC_1,            KC_2,            KC_3,         KC_BSLS, _______,
                                                  _______, _______, _______, _______, _______,       _______, _______, MO(_ADJUST), _______, _______
),
/* RAISE
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CTab |  F7  |  F8  |  F9  | F10  |      |                    | Redo | Past | Copy | Cut  | Undo |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | KTab |  F4  |  F5  |  F6  | F11  | Caps |-------.    ,-------| Left | Down |  Up  | Right|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  | F12  |      |-------|    |-------|  Strt| PgDn | PgUp |  End |  D   |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
  _______,      _______,        _______,       _______,        _______,  _______,                           _______,         _______,       _______,         _______,        _______, _______,
G(KC_TAB),         KC_F7,         KC_F8,         KC_F9,         KC_F10,  XXXXXXX,                        S(KC_UNDO),        KC_PASTE,       KC_COPY,          KC_CUT,        KC_UNDO, _______,
  C(KC_W), LGUI_T(KC_F4), LALT_T(KC_F5), LCTL_T(KC_F6), LSFT_T(KC_F11),  CW_TOGG,                           KC_LEFT, RSFT_T(KC_DOWN), RCTL_T(KC_UP), LALT_T(KC_RGHT), RGUI_T(KC_DEL), KC_BSPC,
  _______,         KC_F1,         KC_F2,         KC_F3,         KC_F12,  XXXXXXX,  _______,       _______,  KC_HOME,         KC_PGDN,       KC_PGUP,          KC_END,           KC_D, _______,
                                           _______, _______, MO(_ADJUST), _______, _______,       _______, _______, _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | QK_BOOT|    |      |      |      |      |                    | BRID | BRIU | MCTL | SPOT | DICT | DND  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      | QWER | GALL |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX , XXXXXXX,   XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  QK_BOOT , XXXXXXX,   XXXXXXX,    XXXXXXX, CG_TOGG, XXXXXXX,                   KC_BRID, KC_BRIU, KC_MCTL, KC_SPOT, KC_DICT,  KC_DND,
  XXXXXXX , XXXXXXX,   CG_TOGG,    XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX, KC_QWERTY, KC_GALLIUM, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_SPOT:
            if (record->event.pressed) {
                host_consumer_send(0x221);
            } else {
                host_consumer_send(0);
            }
            return false;
        case KC_DICT:
            if (record->event.pressed) {
                host_consumer_send(0xcf);
            } else {
                host_consumer_send(0);
            }
            return false;
        case KC_DND:
            if (record->event.pressed) {
                host_system_send(0x9b);
            } else {
                host_system_send(0);
            }
            return false;
        case KC_LOCK:
            if (record->event.pressed) {
                host_consumer_send(0x19e);
            } else {
                host_consumer_send(0);
            }
            return false;
        case KC_LPAD:
            if (record->event.pressed) {
                host_consumer_send(0x2a0);
            } else {
                host_consumer_send(0);
            }
            return false;
        case LGUI_T(KC_EXLM):
            if (record->tap.count == 1 && !record->tap.interrupted) {
                if (record->event.pressed) {
                    register_mods(mod_config(MOD_LSFT));
                } else {
                    unregister_mods(mod_config(MOD_LSFT));
                }
            }
            break;
        case LALT_T(KC_AT):
            if (record->tap.count == 1 && !record->tap.interrupted) {
                if (record->event.pressed) {
                    register_mods(mod_config(MOD_LSFT));
                } else {
                    unregister_mods(mod_config(MOD_LSFT));
                }
            }
            break;
        case LCTL_T(KC_HASH):
            if (record->tap.count == 1 && !record->tap.interrupted) {
                if (record->event.pressed) {
                    register_mods(mod_config(MOD_LSFT));
                } else {
                    unregister_mods(mod_config(MOD_LSFT));
                }
            }
            break;
        case LSFT_T(KC_DLR):
            if (record->tap.count == 1 && !record->tap.interrupted) {
                if (record->event.pressed) {
                    register_mods(mod_config(MOD_LSFT));
                } else {
                    unregister_mods(mod_config(MOD_LSFT));
                }
            }
            break;
        case RGUI_T(KC_LCBR):
            if (record->tap.count == 1 && !record->tap.interrupted) {
                if (record->event.pressed) {
                    register_mods(mod_config(MOD_LSFT));
                } else {
                    unregister_mods(mod_config(MOD_LSFT));
                }
            }
            break;
        case LSFT_T(CW_TOGG):
        case RSFT_T(CW_TOGG):
            if (record->tap.count == 1 && !record->tap.interrupted) {
                if (record->event.pressed) {
                    caps_word_toggle();
                }
                return false;
            }
    }

    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    keymap_config.swap_lctl_lgui = true;
    keymap_config.swap_rctl_rgui = true;

    return state;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TT(_LOWER):
        case TT(_RAISE):
        case LSFT_T(CW_TOGG):
        case RSFT_T(CW_TOGG):
            return 150;
        /* case RCTL_T(KC_K): */
        /* case LCTL_T(KC_D): */
        /* case RCTL_T(KC_A): */
        /* case LCTL_T(KC_T): */
        /* case RCTL_T(KC_5): */
        /* case LCTL_T(KC_HASH): */
        /* case RCTL_T(KC_UP): */
        /* case LCTL_T(KC_F6): */
        /*      return 160; */
        /* case LALT_T(KC_S): */
        /* case LALT_T(KC_L): */
        /* case LALT_T(KC_E): */
        /* case LALT_T(KC_R): */
        /* case LALT_T(KC_AT): */
        /* case LALT_T(KC_6): */
        /* case LALT_T(KC_F5): */
        /* case LALT_T(KC_RGHT): */
        /*     return 180; */
        /* case RGUI_T(KC_SCLN): */
        /* case LGUI_T(KC_K): */
        /* case RGUI_T(KC_I): */
        /* case LGUI_T(KC_N): */
        /* case RGUI_T(KC_LCBR): */
        /* case LGUI_T(KC_EXLM): */
        /* case RGUI_T(KC_DEL): */
        /* case LGUI_T(KC_F4): */
        /*     return 200; */
        default:
            return TAPPING_TERM;
    }
}

bool sentence_case_check_ending(const uint16_t* buffer) {
    // Don't consider the abbreviations "vs." and "etc." to end the sentence.
    if (SENTENCE_CASE_JUST_TYPED(KC_SPC, KC_V, KC_S, KC_DOT) ||
        SENTENCE_CASE_JUST_TYPED(KC_SPC, KC_E, KC_T, KC_C, KC_DOT) ||
        SENTENCE_CASE_JUST_TYPED(KC_I, KC_DOT, KC_E, KC_DOT) ||
        SENTENCE_CASE_JUST_TYPED(KC_E, KC_DOT, KC_G, KC_DOT)) {
        return false;  // Not a real sentence ending.
    }

    return true;  // Real sentence ending; capitalize next letter.
}
