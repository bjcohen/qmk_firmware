// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include "features/achordion.h"

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _GALLIUM,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_PRVWD = QK_USER,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_SPOT,
    KC_DICT,
    KC_DND,
    KC_LOCK
};

#define KC_QWERTY PDF(_QWERTY)
#define KC_GALLIUM PDF(_GALLIUM)

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
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_BSLS,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
  KC_ESC,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,     XXXXXXX,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                 KC_LGUI,KC_LALT,KC_LCTL, TL_LOWR, KC_ENT,      KC_SPC,  TL_UPPR, KC_RCTL, KC_LALT, KC_RGUI
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
  KC_GRV,         KC_1,         KC_2,         KC_3,         KC_4,    KC_5,                        KC_6,         KC_7,         KC_8,         KC_9,         KC_0,  KC_BSLS,
  KC_TAB,         KC_B,         KC_L,         KC_D,         KC_C,    KC_V,                        KC_J,         KC_Y,         KC_O,         KC_U,      KC_COMM,  KC_BSPC,
  KC_ESC, LGUI_T(KC_N), LALT_T(KC_R), LCTL_T(KC_T), LSFT_T(KC_S),    KC_G,                        KC_P, RSFT_T(KC_H), RCTL_T(KC_A), LALT_T(KC_E), RGUI_T(KC_I),  KC_SLSH,
  KC_LSFT,        KC_X,         KC_Q,         KC_M,         KC_W,    KC_Z, KC_MUTE,      XXXXXXX, KC_K,         KC_F,      KC_QUOT,      KC_SCLN,       KC_DOT,  KC_RSFT,
                                       KC_LGUI, KC_LALT, KC_LCTL, TL_LOWR,  KC_ENT,       KC_SPC, TL_UPPR, KC_RCTL, KC_LALT, KC_RGUI
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
  _______,           KC_F1,         KC_F2,           KC_F3,          KC_F4,   KC_F5,                           KC_F6,           KC_F7,           KC_F8,           KC_F9,          KC_F10,  KC_F11,
  KC_GRV,             KC_1,          KC_2,            KC_3,           KC_4,    KC_5,                            KC_6,            KC_7,            KC_8,            KC_9,            KC_0,  KC_F12,
  _______, LGUI_T(KC_EXLM), LALT_T(KC_AT), LCTL_T(KC_HASH), LSFT_T(KC_DLR), KC_PERC,                         KC_CIRC, RSFT_T(KC_AMPR), RCTL_T(KC_ASTR), LALT_T(KC_LPRN), RGUI_T(KC_RPRN), KC_PIPE,
  _______,          KC_EQL,       KC_MINS,         KC_PLUS,        KC_LCBR, KC_RCBR, _______,       _______, KC_LBRC,         KC_RBRC,         KC_SCLN,         KC_COLN,         KC_BSLS, _______,
                       _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
/* RAISE
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | Ins  | Pscr | Menu |      |      |                    |      | PgDn | PgUp |      | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------| Left | Down |  Up  | Right|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE  |    |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|  Strt| PWrd | NWrd |  End |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
  _______,   _______ ,   _______ ,   _______ ,  _______ ,  _______,                       _______,  _______  , _______,  _______ ,  _______ ,_______,
  _______,     KC_INS,    KC_PSCR,     KC_APP,   XXXXXXX,  XXXXXXX,                       XXXXXXX,  KC_PGDN, KC_PGUP, XXXXXXX,C(KC_BSPC), KC_BSPC,
  _______,    KC_LALT,    KC_LCTL,    KC_LSFT,   XXXXXXX,  KC_CAPS,                       KC_LEFT,  KC_DOWN,   KC_UP, KC_RGHT,  KC_DEL, KC_BSPC,
  _______, LGUI(KC_Z), LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), XXXXXXX,  _______,       _______,  KC_HOME, KC_PRVWD, KC_NXTWD, KC_END,   XXXXXXX, _______,
                         _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | QK_BOOT|    |      |      |      |      |                    |      | BRID | BRIU | MCTL |      |      |
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
  QK_BOOT , XXXXXXX,   XXXXXXX,    XXXXXXX, CG_TOGG, XXXXXXX,                   XXXXXXX, KC_BRID, KC_BRIU, KC_MCTL, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX,   CG_TOGG,    XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX, KC_QWERTY, KC_GALLIUM, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_achordion(keycode, record)) {
        return false;
    }

    switch (keycode) {
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_SPOT:
            if (record->event.pressed) {
                host_consumer_send(0x221);
            } else {
                host_consumer_send(0);
            }
            break;
        case KC_DICT:
            if (record->event.pressed) {
                host_consumer_send(0xcf);
            } else {
                host_consumer_send(0);
            }
            break;
        case KC_DND:
            if (record->event.pressed) {
                host_consumer_send(0x9b);
            } else {
                host_consumer_send(0);
            }
            break;
        case KC_LOCK:
            if (record->event.pressed) {
                host_consumer_send(0x19e);
            } else {
                host_consumer_send(0);
            }
            break;
        case KC_LPAD:
            if (record->event.pressed) {
                host_consumer_send(0x2a0);
            } else {
                host_consumer_send(0);
            }
            break;
        case LGUI_T(KC_EXLM):
            if (record->tap.count == 1) {
                if (record->event.pressed) {
                    register_mods(mod_config(MOD_LSFT));
                } else {
                    unregister_mods(mod_config(MOD_LSFT));
                }
            }
            break;
        case LALT_T(KC_AT):
            if (record->tap.count == 1) {
                if (record->event.pressed) {
                    register_mods(mod_config(MOD_LSFT));
                } else {
                    unregister_mods(mod_config(MOD_LSFT));
                }
            }
            break;
        case LCTL_T(KC_HASH):
            if (record->tap.count == 1) {
                if (record->event.pressed) {
                    register_mods(mod_config(MOD_LSFT));
                } else {
                    unregister_mods(mod_config(MOD_LSFT));
                }
            }
            break;
        case LSFT_T(KC_DLR):
            if (record->tap.count == 1) {
                if (record->event.pressed) {
                    register_mods(mod_config(MOD_LSFT));
                } else {
                    unregister_mods(mod_config(MOD_LSFT));
                }
            }
            break;
        case RSFT_T(KC_AMPR):
            if (record->tap.count == 1) {
                if (record->event.pressed) {
                    register_mods(mod_config(MOD_LSFT));
                } else {
                    unregister_mods(mod_config(MOD_LSFT));
                }
            }
            break;
        case RCTL_T(KC_ASTR):
            if (record->tap.count == 1) {
                if (record->event.pressed) {
                    register_mods(mod_config(MOD_LSFT));
                } else {
                    unregister_mods(mod_config(MOD_LSFT));
                }
            }
            break;
        case LALT_T(KC_LPRN):
            if (record->tap.count == 1) {
                if (record->event.pressed) {
                    register_mods(mod_config(MOD_LSFT));
                } else {
                    unregister_mods(mod_config(MOD_LSFT));
                }
            }
            break;
        case RGUI_T(KC_RPRN):
            if (record->tap.count == 1) {
                if (record->event.pressed) {
                    register_mods(mod_config(MOD_LSFT));
                } else {
                    unregister_mods(mod_config(MOD_LSFT));
                }
            }
            break;
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
        case LALT_T(KC_E):
        case LALT_T(KC_R):
        case LALT_T(KC_AT):
        case LALT_T(KC_LPRN):
            return 180;
        case RCTL_T(KC_A):
        case LCTL_T(KC_T):
        case RCTL_T(KC_ASTR):
        case LCTL_T(KC_HASH):
            return 190;
        case RGUI_T(KC_I):
        case LGUI_T(KC_N):
        case RGUI_T(KC_RPRN):
        case LGUI_T(KC_EXLM):
            return 200;
        default:
            return TAPPING_TERM;
    }
}

void matrix_scan_user(void) {
  achordion_task();
}
