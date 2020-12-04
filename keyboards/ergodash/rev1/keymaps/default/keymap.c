#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

#define LCTRL_CHARACTER_PRESS(x) \
      if (record->event.pressed) { \
        SEND_STRING(SS_LCTL(#x)); \
      } else { \
      } \
      return false; \
      break;


enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  VIM_SWAP_BUFFER,
  VIM_EASYMOTION_LEFT,
  VIM_EASYMOTION_RIGHT,
  VIM_EASYMOTION_UP,
  VIM_EASYMOTION_DOWN,
  VIM_FUZZY_FIND,
  LCTRL_W,
  LCTRL_A,
  LCTRL_Z,
  LCTRL_D,
  LCTRL_R,
  LCTRL_C,
  LCTRL_V,
  LCTRL_F,
  LCTRL_B,
};

#define EISU LALT(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |   `  |   1  |   2  |   3  |   4  |   5  |Custom|                    |   +  |   6  |   7  |   8  |   9  |   0  | ____ |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   [  |                    |   ]  |   Y  |   U  |   I  |   O  |   P  |   "  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | ESC  |   A  |   S  |   D  |   F  |   G  | ____ |                    | ____ |   H  |   J  |   K  |   L  |   ;  | Enter|
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  | Bksp |  Del |      | Enter| Space|   N  |   M  |   ,  |   .  |   /  | Mute |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  ALt | EISU | GUI  |||||||| Lower| Bksp |  Del |||||||| Enter| Space| Raise|||||||| Left | Down |  Up  |Right |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    VIM_SWAP_BUFFER,                            KC_EQL, KC_6, KC_7,    KC_8,    KC_9,    KC_0, KC_MINS, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,                        KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
    _______,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_GRV,                       KC__MUTE, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_BSPC,                        KC_SPC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RALT, \
    KC_LCTL, KC_LALT, RGB_TOG, KC_LGUI,          LOWER,   KC_BSPC,KC_DEL,         KC_ENT,KC_SPC, RAISE, KC_LEFT,            KC_DOWN, KC_UP, KC_RGHT  \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |VolDown|                   | VolUp|  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  ~   |   !  |  Up  |   #  |   $  |   %  | Mute |                    |   +  |   ^  |   &  |   *  |   (  |   )  |  |   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  | Left | Down | Right|   4  |   5  | ____ |                    | ____ |   H  |   J  |   K  |   L  |   :  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   6  |   7  |   8  |   9  |   0  | Space|                    | Enter|   N  |   M  |   <  |   >  |   ?  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt | EISU |||||||| Lower| Space|  Del |||||||| Bksp | Enter| Raise|||||||| Home |PageDn|PageUp|  End |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC__VOLDOWN,                      KC__VOLUP, KC_F6, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12, \
    _______, _______, LCTRL_W, _______, LCTRL_R, _______, KC__MUTE,                          KC_PLUS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, \
    _______, LCTRL_A, _______, LCTRL_D, LCTRL_F, _______, _______,                        _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_COLN, KC_DQT , \
    _______, LCTRL_Z, _______, LCTRL_C, LCTRL_V, LCTRL_B, KC_SPC ,                        KC_ENT , KC_N,    KC_M,    KC_LT,   KC_GT,   KC_QUES, KC_RSFT, \
    _______, KC_LGUI, KC_LALT, EISU,             LOWER,   KC_SPC ,KC_DEL,         KC_BSPC,KC_ENT , RAISE,            KC_HOME, KC_PGDN, KC_PGUP, KC_END   \
  ),

  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  | Prev Track |        | Next Track |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  ~   |   !  |PageUp|   #  |   $  |   %  | Play/Pause |              |   +  |   ^  |   &  |   *  |   (  |   )  |  |   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  | Home |PgDown| End  |   4  |   5  |  Del |                    | Bksp | Home |PageDn|PageUp|  End |   :  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   6  |   7  |   8  |   9  |   0  | Space|                    | Enter|   N  |   M  |   <  |   >  |   ?  |Play/Pause|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt | EISU |||||||| Lower| Space|  Del |||||||| Bksp | Enter| Raise|||||||| Home |PageDn|PageUp|  End |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_RAISE] = LAYOUT(
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_MPRV,                       KC_MNXT, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,  \
    KC_TILD, KC_EXLM, KC_PGUP,   KC_HASH, KC_DLR,  KC_PERC, KC_MPLY,                        KC_PLUS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, \
    KC_TAB,  KC_HOME,    KC_PGDN,    KC_END,    KC_4,    VIM_FUZZY_FIND,    KC_DEL ,                        KC_BSPC, VIM_EASYMOTION_LEFT, VIM_EASYMOTION_DOWN, VIM_EASYMOTION_UP, VIM_EASYMOTION_RIGHT, KC_COLN, KC_DQT , \
    KC_LSFT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_SPC ,                        KC_ENT , KC_N,    KC_M,    KC_LT,   KC_GT,   KC_QUES, KC_MPLY, \
    KC_LCTL, KC_LGUI, KC_LALT, EISU,             LOWER,   KC_SPC ,KC_DEL,         KC_BSPC,KC_ENT , RAISE,            KC_HOME, KC_PGDN, KC_PGUP, KC_END   \
  ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      | BL ON|  BRTG|  INC|   DEC|      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,_______,                       _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______, \
    _______, _______, BL_TOGG, BL_BRTG, BL_INC , BL_DEC ,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, RGB_M_X, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______  \
  )
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
         print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case VIM_SWAP_BUFFER:
      if (record->event.pressed) {
        // Swap buffer command.
        SEND_STRING(SS_LCTL("6"));
      } else {
        // when keycode VIM_SWAP_BUFFER is released.
      }
      return false;
      break;
    case VIM_EASYMOTION_RIGHT:
      if (record->event.pressed) {
        SEND_STRING("`");
        SEND_STRING("l");
      } else {
        // when released.
      }
      return false;
      break;
    case VIM_EASYMOTION_LEFT:
      if (record->event.pressed) {
        SEND_STRING("`");
        SEND_STRING("h");
      } else {
        // when released.
      }
      return false;
      break;
    case VIM_EASYMOTION_DOWN:
      if (record->event.pressed) {
        SEND_STRING("`");
        SEND_STRING("j");
      } else {
        // when released.
      }
      return false;
      break;
    case VIM_EASYMOTION_UP:
      if (record->event.pressed) {
        SEND_STRING("`");
        SEND_STRING("k");
      } else {
        // when released.
      }
      return false;
      break;
    case VIM_FUZZY_FIND:
      if (record->event.pressed) {
        SEND_STRING("`");
        SEND_STRING("g");
      } else {
        // when released.
      }
      return false;
      break;
    case LCTRL_W:
      LCTRL_CHARACTER_PRESS(w)
    case LCTRL_A:
      LCTRL_CHARACTER_PRESS(a)
    case LCTRL_D:
      LCTRL_CHARACTER_PRESS(d)
    case LCTRL_Z:
      LCTRL_CHARACTER_PRESS(z)
    case LCTRL_F:
      LCTRL_CHARACTER_PRESS(f)
    case LCTRL_B:
      LCTRL_CHARACTER_PRESS(b)
    case LCTRL_V:
      LCTRL_CHARACTER_PRESS(v)
    case LCTRL_C:
      LCTRL_CHARACTER_PRESS(c)
    case LCTRL_R:
      LCTRL_CHARACTER_PRESS(r)
  }
  return true;
}
