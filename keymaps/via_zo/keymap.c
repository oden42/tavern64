#include QMK_KEYBOARD_H
#include "oled.c"

enum layer_names {
    _BASE,
    _WORK,
    _GAMING1,
	_GAMING2,
	_CREATIVE,
	_LIGHTING,
	_AUDIO,
	_MUSIC,
    _FN,
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QS_1 = SAFE_RANGE,
    QS_2,
    QS_3,
    QS_4,
    QS_5,
    QS_6,
    QS_7,
    QS_8,
    QS_9,
    QS_10,
    QS_11,
    QS_12,
    QS_13,
    QS_14,
    QS_15,
};

// Tap Dance declarations
// enum {
// 	TD_CK_ENC = 0,
//	TD_FN = 0
// };

// Tap Dance definitions
// qk_tap_dance_action_t tap_dance_actions[] = {
	// Tap once for Escape, twice for Caps Lock
	//[TD_CK_ENC] = ACTION_TAP_DANCE_DOUBLE(CK_TOGG, CK_RST),
	//[TD_FN] = ACTION_TAP_DANCE_DOUBLE(MO(_FN),TO(_BASE)),
// };

float caps_on[][2] = SONG(CAPS_LOCK_ON_SOUND);
float caps_off[][2] = SONG(CAPS_LOCK_OFF_SOUND);
float num_on[][2] = SONG(NUM_LOCK_ON_SOUND);
float num_off[][2] = SONG(NUM_LOCK_OFF_SOUND);

float song1[][2] = SONG(PORTAL);
float song2[][2] = SONG(XMEN_FULL);
float song3[][2] = SONG(EVERQUEST_FULL);
float song4[][2] = SONG(MEGALOVANIA);
float song5[][2] = SONG(IMPERIAL_MARCH);
float song6[][2] = SONG(COIN_SOUND);
float song7[][2] = SONG(FF_PRELUDE);
float song8[][2] = SONG(ZELDA_PUZZLE);
float song9[][2] = SONG(ONE_UP_SOUND);
float song10[][2] = SONG(MARIO_MUSHROOM);
float song11[][2] = SONG(TERRAS_THEME);
float song12[][2] = SONG(RICK_ROLL);
float song13[][2] = SONG(KIRBY_DREAM);
float song14[][2] = SONG(OLD_SPICE);
float song15[][2] = SONG(DISNEY_SONG);


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	//  ------- ===================================    MATRIX LAYOUT    ===================================
	//  ------- ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬───────────┐
	//  ------- │ 0,0 │ 0,1 │ 0,2 │ 0,3 │ 0,4 │ 0,5 │ 0,6 │ 0,7 │ 0,8 │ 0,9 │0,10 │0,11 │0,12 │ 0,13      │ 
	//  ------- ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┤
	//  ------- │ 1,0    │ 1,1 │ 1,2 │ 1,3 │ 1,4 │ 1,5 │ 1,6 │ 1,7 │ 1,8 │ 1,9 │1,10 │1,11 │1,12 │ 1,13   │
	//  ┌─────┐ ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴────────┤
	//  │ 2,0 │ │ 2,1     │ 2,2 │ 2,3 │ 2,4 │ 2,5 │ 2,6 │ 2,7 │ 2,8 │ 2,9 │2,10 │2,11 │2,12 │   2,13      │
	//  ├─────┤ ├─────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬─────┬────┘
	//  │ 3,0 │ │ 3,1        │ 3,2 │ 3,3 │ 3,4 │ 3,5 │ 3,6 │ 3,7 │ 3,8 │ 3,9 │3,10 │3,11 │3,12 │3,13 │ 
	//  ├─────┤ ├──────┬─────┴─┬───┴──┬──┴─────┴────┬┴─────┼─────┴─────┴────┬┴─────┼─────┼─────┼─────┤
	//  │ 4,0 │ │ 4,1  │ 4,2   │ 4,3  │ 4,4         │ 4,6  │ 4,7            │ 4,9  │4,10 │4,11 │4,12 │
	//  └─────┘ └──────┴───────┴──────┴─────────────┴──────┴────────────────┴──────┴─────┴─────┴─────┘
	//  ------- =======================================  ROW , COL  =======================================
	
	  [_BASE] = LAYOUT(
/*
	 ------- ==================================    DEFAULT LAYOUT    ===================================
	 ------- ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬───────────┐
	 ------- │ESC  │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │  =  │ BACKSPACE │ 
	 ------- ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┤
	 ------- │TAB     │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │BSPC    │
	 ┌─────┐ ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴────────┤
	 │MUTE │ │CAPS     │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │ENTER        │
	 ├─────┤ ├─────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬─────┬────┘
	 │+F23 │ │LSHFT       │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │UP   │RSHFT│ <-Tap to Delete
	 ├─────┤ ├──────┬─────┴─┬───┴──┬──┴─────┴────┬┴─────┼─────┴─────┴────┬┴─────┼─────┼─────┼─────┤
	 │^F23 │ │LCTRL │L_GUI  │L_ALT │SPC          │SPC   │SPC             │FN    │LEFT │DOWN │RIGHT│
	 └─────┘ └──────┴───────┴──────┴─────────────┴──────┴────────────────┴──────┴─────┴─────┴─────┘
*/
	//  COL 0,	1,	2,	3,	4,	5,	6,	7,	8,	9,	10,	11,	12,	13		ROW
	    QK_GESC, KC_1, KC_2  , KC_3  , KC_4  , KC_5  , KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_MINS, KC_EQL,KC_BSPC,	// 	0
	    KC_TAB,  KC_Q, KC_W  , KC_E  , KC_R  , KC_T  , KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_LBRC,KC_RBRC,KC_BSLS, //	1
	    KC_MUTE,KC_CAPS,KC_A , KC_S  , KC_D  , KC_F  , KC_G  , KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT, KC_ENT, //	2
	    S(KC_F23),KC_LSFT,KC_Z, KC_X , KC_C  , KC_V  , KC_B  , KC_N  , KC_M  ,KC_COMM, KC_DOT,KC_SLSH, KC_UP ,RSFT_T(KC_DEL), //	3
	    C(KC_F23),KC_LCTL,KC_LGUI,KC_LALT, KC_SPC, KC_SPC, KC_SPC, MO(_FN) ,KC_LEFT,KC_DOWN,KC_RGHT 							//	4
	  ),
	  [_WORK] = LAYOUT(
/*
	 ------- ==================================    WORK LAYOUT    ===================================
	 ------- ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬───────────┐
	 ------- │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼        │ 
	 ------- ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┤
	 ------- │  ▼     │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼     │
	 ┌─────┐ ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴────────┤
	 │  ▼  │ │  ▼      │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼          │
	 ├─────┤ ├─────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬─────┬────┘
	 │  ▼  │ │  ▼         │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │ 
	 ├─────┤ ├──────┬─────┴─┬───┴──┬──┴─────┴────┬┴─────┼─────┴─────┴────┬┴─────┼─────┼─────┼─────┤
	 │  ▼  │ │  ▼   │  ▼    │  ▼   │  ▼          │  ▼   │  ▼             │  ▼   │  ▼  │  ▼  │  ▼  │
	 └─────┘ └──────┴───────┴──────┴─────────────┴──────┴────────────────┴──────┴─────┴─────┴─────┘
*/
	//  COL 0,	1,	2,	3,	4,	5,	6,	7,	8,	9,	10,	11,	12,	13		ROW
	    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,	// 	0
	    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, //	1
	    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, //	2
	    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, //	3
	    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS 	 					//	4
	  ),
	  [_GAMING1] = LAYOUT(
/*
	 ------- ==================================    GAMING 1 LAYOUT    ===================================
	 ------- ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬───────────┐
	 ------- │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼        │ 
	 ------- ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┤
	 ------- │  ▼     │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼     │
	 ┌─────┐ ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴────────┤
	 │  ▼  │ │  ▼      │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼          │
	 ├─────┤ ├─────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬─────┬────┘
	 │  ▼  │ │  ▼         │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │ 
	 ├─────┤ ├──────┬─────┴─┬───┴──┬──┴─────┴────┬┴─────┼─────┴─────┴────┬┴─────┼─────┼─────┼─────┤
	 │  ▼  │ │  ▼   │  ▼    │  ▼   │  ▼          │  ▼   │  ▼             │  ▼   │  ▼  │  ▼  │  ▼  │
	 └─────┘ └──────┴───────┴──────┴─────────────┴──────┴────────────────┴──────┴─────┴─────┴─────┘
*/
	//  COL 0,	1,	2,	3,	4,	5,	6,	7,	8,	9,	10,	11,	12,	13		ROW
	    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,	// 	0
	    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, //	1
	    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, //	2
	    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, //	3
	    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS 	 					//	4
	  ),
	  [_GAMING2] = LAYOUT(
/*
	 ------- ==================================    GAMING 2 LAYOUT    ===================================
	 ------- ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬───────────┐
	 ------- │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼        │ 
	 ------- ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┤
	 ------- │  ▼     │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼     │
	 ┌─────┐ ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴────────┤
	 │  ▼  │ │  ▼      │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼          │
	 ├─────┤ ├─────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬─────┬────┘
	 │  ▼  │ │  ▼         │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │ 
	 ├─────┤ ├──────┬─────┴─┬───┴──┬──┴─────┴────┬┴─────┼─────┴─────┴────┬┴─────┼─────┼─────┼─────┤
	 │  ▼  │ │  ▼   │  ▼    │  ▼   │  ▼          │  ▼   │  ▼             │  ▼   │  ▼  │  ▼  │  ▼  │
	 └─────┘ └──────┴───────┴──────┴─────────────┴──────┴────────────────┴──────┴─────┴─────┴─────┘
*/	  
	//  COL 0,	1,	2,	3,	4,	5,	6,	7,	8,	9,	10,	11,	12,	13		ROW
	    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,	// 	0
	    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, //	1
	    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, //	2
	    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, //	3
	    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS 						//	4
	  ),
	  [_CREATIVE] = LAYOUT(
/*
	 ------- ==================================    CREATIVE LAYOUT    ===================================
	 ------- ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬───────────┐
	 ------- │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼        │ 
	 ------- ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┤
	 ------- │  ▼     │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼     │
	 ┌─────┐ ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴────────┤
	 │  ▼  │ │  ▼      │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼          │
	 ├─────┤ ├─────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬─────┬────┘
	 │  ▼  │ │  ▼         │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │ 
	 ├─────┤ ├──────┬─────┴─┬───┴──┬──┴─────┴────┬┴─────┼─────┴─────┴────┬┴─────┼─────┼─────┼─────┤
	 │  ▼  │ │  ▼   │  ▼    │  ▼   │  ▼          │  ▼   │  ▼             │  ▼   │  ▼  │  ▼  │  ▼  │
	 └─────┘ └──────┴───────┴──────┴─────────────┴──────┴────────────────┴──────┴─────┴─────┴─────┘
*/
	//  COL 0,	1,	2,	3,	4,	5,	6,	7,	8,	9,	10,	11,	12,	13		ROW
	    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,	// 	0
	    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, //	1
	    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, //	2
	    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, //	3
	    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS 						//	4
	  ),
	  [_LIGHTING] = LAYOUT(
/*
	 ------- ==================================    LIGHTING LAYOUT    ===================================
	 ------- ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬───────────┐
	 ------- │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼        │ 
	 ------- ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┤
	 ------- │  ▼     │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼     │
	 ┌─────┐ ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴────────┤
	 RGB TOG │  ▼      │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼          │
	 ├─────┤ ├─────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬─────┬────┘
	 RGB STA │  ▼         │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │SA-UP│  ▼  │ 
	 ├─────┤ ├──────┬─────┴─┬───┴──┬──┴─────┴────┬┴─────┼─────┴─────┴────┬┴─────┼─────┼─────┼─────┤
	 RGB RBW │  ▼   │  ▼    │  ▼   │  ▼          │  ▼   │  ▼             │  ▼   │SP-DN│SA-DN│SP-UP│
	 └─────┘ └──────┴───────┴──────┴─────────────┴──────┴────────────────┴──────┴─────┴─────┴─────┘
*/
	//  COL 0,	1,	2,	3,	4,	5,	6,	7,	8,	9,	10,	11,	12,	13		ROW
	    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,	// 	0
	    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, //	1
	    RGB_TOG,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, //	2
	    RGB_M_P,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,RGB_SAI,KC_TRNS, //	3
	    RGB_M_R,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,RGB_SPD,RGB_SAD,RGB_SPI 						//	4
	  ),
	  [_AUDIO] = LAYOUT(
/*
	 ------- ==================================    AUDIO LAYOUT    ===================================
	 ------- ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬───────────┐
	 ------- │  ▼  │ S1  │ S2  │ S3  │ S4  │ S5  │ S6  │ S7  │ S8  │ S9  │ S10 │ S11 │ S12 │  ▼        │ 
	 ------- ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┤
	 ------- │  ▼     │ S13 │ S14 │ S15 │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼     │
	 ┌─────┐ ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴────────┤
	 AUD TOG │  ▼      │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼          │
	 ├─────┤ ├─────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬─────┬────┘
	 MUSI ON │  ▼         │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │ 
	 ├─────┤ ├──────┬─────┴─┬───┴──┬──┴─────┴────┬┴─────┼─────┴─────┴────┬┴─────┼─────┼─────┼─────┤
	 CLK TOG │  ▼   │  ▼    │  ▼   │  ▼          │  ▼   │  ▼             │  ▼   │  ▼  │  ▼  │  ▼  │
	 └─────┘ └──────┴───────┴──────┴─────────────┴──────┴────────────────┴──────┴─────┴─────┴─────┘
*/
	//  COL 0,	1,	2,	3,	4,	5,	6,	7,	8,	9,	10,	11,	12,	13		ROW
	    KC_TRNS,QS_1,QS_2,QS_3,QS_4,QS_5,QS_6,QS_7,QS_8,QS_9,QS_10,QS_11,QS_12,KC_TRNS,	// 	0
	    KC_TRNS,QS_13,QS_14,QS_15,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, //	1
	    AU_TOGG,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, //	2
	    MU_ON,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, //	3
	    CK_TOGG,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS 					//	4
	  ),	  
	  [_MUSIC] = LAYOUT(
/*
	 ------- ==================================     MUSIC LAYOUT    ===================================
	 ------- ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬───────────┐
	 ------- │     │     │     │     │     │     │     │     │     │     │     │     │     │           │ 
	 ------- ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┤
	 ------- │        │     │     │     │     │     │     │     │     │     │     │     │     │        │
	 ┌─────┐ ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴────────┤
	 │ OFF │ │         │     │     │     │     │     │     │     │     │     │     │     │             │
	 ├─────┤ ├─────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬─────┬────┘
	 │     │ │            │     │     │     │     │     │     │     │     │     │     │SP UP│     │ 
	 ├─────┤ ├──────┬─────┴─┬───┴──┬──┴─────┴────┬┴─────┼─────┴─────┴────┬┴─────┼─────┼─────┼─────┤
	 │     │ │RECORD│ STOP  │ PLAY │             │      │                │      │     │SP DN│     │
	 └─────┘ └──────┴───────┴──────┴─────────────┴──────┴────────────────┴──────┴─────┴─────┴─────┘
*/
	//  COL 0,	1,	2,	3,	4,	5,	6,	7,	8,	9,	10,	11,	12,	13		ROW
	    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,	// 	0
	    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, //	1
		MU_OFF, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, //	2
	    MU_OFF, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_UP,  KC_NO, //	3
	    MU_OFF,KC_LCTL,KC_LGUI,KC_LALT, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_DOWN,  KC_NO							//	4
	  ),	
	  [_FN] = LAYOUT(	
/*
	 ------- ==================================    FUNCTION LAYOUT    ===================================
	 ------- ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬───────────┐
	 ------- │  ▼  │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │  ▼        │ 
	 ------- ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┤
	 ------- │  ▼     │ F13 │ F14 │ F15 │ F16 │ F17 │ F18 │ F19 │ F20 │ F21 │ F22 │ F23 │ F24 │  ▼     │
	 ┌─────┐ ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴────────┤
	 │BOOT │ │  ▼      │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │  ▼          │
	 ├─────┤ ├─────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬─────┬────┘
	 │  ▼  │ │  ▼         │TO 0 │TO 2 │TO 3 │TO 4 │TO 5 │TO 6 │TO 7 │  ▼  │  ▼  │  ▼  │  ▼  │  ▼  │ 
	 ├─────┤ ├──────┬─────┴─┬───┴──┬──┴─────┴────┬┴─────┼─────┴─────┴────┬┴─────┼─────┼─────┼─────┤
	 │  ▼  │ │  ▼   │  ▼    │  ▼   │  ▼          │  ▼   │  ▼             │  ▼   │  ▼  │  ▼  │  ▼  │
	 └─────┘ └──────┴───────┴──────┴─────────────┴──────┴────────────────┴──────┴─────┴─────┴─────┘
*/
	//  COL 0,	1,	2,	3,	4,	5,	6,	7,	8,	9,	10,	11,	12,	13		ROW
	    KC_TRNS, KC_F1, KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6 , KC_F7 , KC_F8 , KC_F9 , KC_F10, KC_F11, KC_F12,KC_TRNS,	// 	0
	    KC_TRNS, KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_F21, KC_F22, KC_F23, KC_F24,KC_TRNS, //	1
	    QK_BOOT,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, //	2
	    KC_TRNS,KC_TRNS,TO(_BASE),TO(_WORK),TO(_GAMING1),TO(_GAMING2),TO(_CREATIVE),TO(_LIGHTING),TO(_AUDIO),KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, //	3
	    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS 						//	4
	  )
};
	  
		// ------- ===================================    2U SPACEBARS    ====================================
		// ------- ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬───────────┐
		// ------- │ESC  │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │  =  │ BACKSPACE │ 
		// ------- ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┤
		// ------- │TAB     │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │BSPC    │
		// ┌─────┐ ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴────────┤
		// │ENC1 │ │CAPS     │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │ENTER        │
		// ├─────┤ ├─────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬─────┬────┘
		// │ENC2 │ │LSHFT       │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │UP   │DEL  │ 
		// ├─────┤ ├──────┬─────┴─┬───┴──┬──┴─────┴──┬──┴─────┴──┬──┴─────┴───┬─┴─────┼─────┼─────┼─────┤
		// │ENC3 │ │LCTRL │L_GUI  │L_ALT │SPC        │FN1        │SPC         │FN2    │LEFT │DOWN │RIGHT│
		// └─────┘ └──────┴───────┴──────┴───────────┴───────────┴────────────┴───────┴─────┴─────┴─────┘

/*
#ifdef ENCODER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
        return false;
    }

    switch (index) {
        case 0:
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        break;
//        case 1:
//            if (clockwise) {
//                tap_code(KC_BRIU);
//            } else {
//                tap_code(KC_BRID);
//            }
//        break;
    }
    return true;
}
#endif
*/

/* #ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
	//				Encoder 1 (2,0)						Encoder 2 (3,0)							Encoder 3 (4,0)
    [_BASE] = 		{ ENCODER_CCW_CW(KC_VOLD,KC_VOLU),	ENCODER_CCW_CW(S(KC_F22),S(KC_F21)), 	ENCODER_CCW_CW(C(KC_F22),C(KC_F21)) },
    [_WORK] =  		{ ENCODER_CCW_CW(KC_VOLD,KC_VOLU),	ENCODER_CCW_CW(S(KC_F22),S(KC_F21)),	ENCODER_CCW_CW(KC_NO, KC_NO) },
    [_GAMING1] =  	{ ENCODER_CCW_CW(KC_VOLD,KC_VOLU),	ENCODER_CCW_CW(KC_NO, KC_NO), 			ENCODER_CCW_CW(C(KC_F22),C(KC_F21)) },
    [_GAMING2] =  	{ ENCODER_CCW_CW(KC_VOLD,KC_VOLU),	ENCODER_CCW_CW(KC_NO, KC_NO), 			ENCODER_CCW_CW(C(KC_F22),C(KC_F21)) },
    [_CREATIVE] =  	{ ENCODER_CCW_CW(KC_NO, KC_NO),		ENCODER_CCW_CW(KC_NO, KC_NO), 			ENCODER_CCW_CW(KC_NO, KC_NO) },
    [_LIGHTING] =  	{ ENCODER_CCW_CW(RGB_RMOD,RGB_MOD),	ENCODER_CCW_CW(RGB_HUD,RGB_HUI), 		ENCODER_CCW_CW(RGB_VAD,RGB_VAI) },
    [_AUDIO] =  	{ ENCODER_CCW_CW(AU_PREV,AU_NEXT),	ENCODER_CCW_CW(MU_NEXT,MU_NEXT), 		ENCODER_CCW_CW(CK_DOWN,CK_UP) },
    [_MUSIC] =  	{ ENCODER_CCW_CW(AU_PREV,AU_NEXT),	ENCODER_CCW_CW(MU_NEXT,MU_NEXT), 		ENCODER_CCW_CW(KC_NO, KC_NO) },
    [_FN] =  		{ ENCODER_CCW_CW( KC_1,  KC_2),		ENCODER_CCW_CW(KC_3, KC_4), 			ENCODER_CCW_CW(KC_5, KC_6) },
};
#endif */



/*
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	keyevent_t event = record->event;

	switch (id) {

	}
	return MACRO_NONE;
}
*/

// /* ENABLES SHIFT + BACKSPACE TO DELETE */
// const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

// /* This globally defines all key overrides to be used */
// const key_override_t **key_overrides = (const key_override_t *[]){
    // &delete_key_override,
    // NULL // Null terminate the array of overrides!
// };

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
		
	           /* KEYBOARD PET STATUS */
		switch (keycode) {
			case KC_LCTL:
			case KC_RCTL:
				if (record->event.pressed) {
					isSneaking = true;
				} else {
					isSneaking = false;
				}
				break;
			case KC_SPC:
				if (record->event.pressed) {
					isJumping  = true;
					showedJump = false;
				} else {
					isJumping = false;
				}
				break;
			case MU_ON:
				if (record->event.pressed) {
					layer_move(_MUSIC);
				}
				break;
			case MU_OFF:
				if (record->event.pressed) {
					layer_move(_AUDIO);
				}
				break;
				/* AUDIO BUTTIONS */
			case QS_1:
				if (record->event.pressed) {
					// when keycode QS_1 is pressed
					PLAY_SONG(song1);
				}
				break;
			case QS_2:
				if (record->event.pressed) {
					// when keycode QS_2 is pressed
					PLAY_SONG(song2);
				}
				break; 
			case QS_3:
				if (record->event.pressed) {
					// when keycode QS_3 is pressed
					PLAY_SONG(song3);
				}
				break;
			case QS_4:
				if (record->event.pressed) {
					// when keycode QS_4 is pressed
					PLAY_SONG(song4);
				}
				break;
			case QS_5:
				if (record->event.pressed) {
					// when keycode QS_5 is pressed
					PLAY_SONG(song5);
				}
				break;
			case QS_6:
				if (record->event.pressed) {
					// when keycode QS_6 is pressed
					PLAY_SONG(song6);
				}
				break;
			case QS_7:
				if (record->event.pressed) {
					// when keycode QS_7 is pressed
					PLAY_SONG(song7);
				}
				break;
			case QS_8:
				if (record->event.pressed) {
					// when keycode QS_8 is pressed
					PLAY_SONG(song8);
				}
				break;
			case QS_9:
				if (record->event.pressed) {
					// when keycode QS_9 is pressed
					PLAY_SONG(song9);
				}
				break;
			case QS_10:
				if (record->event.pressed) {
					// when keycode QS_10 is pressed
					PLAY_SONG(song10);
				}
				break;
			case QS_11:
				if (record->event.pressed) {
					// when keycode QS_11 is pressed
					PLAY_SONG(song11);
				}
				break;
			case QS_12:
				if (record->event.pressed) {
					// when keycode QS_12 is pressed
					PLAY_SONG(song12);
				}
				break;
			case QS_13:
				if (record->event.pressed) {
					// when keycode QS_13 is pressed
					PLAY_SONG(song13);
				}
				break;
			case QS_14:
				if (record->event.pressed) {
					// when keycode QS_14 is pressed
					PLAY_SONG(song14);
				}
				break;
			case QS_15:
				if (record->event.pressed) {
					// when keycode QS_15 is pressed
					PLAY_SONG(song15);
				}
				break;
		}
	return true;
}

bool led_update_user(led_t led_state) {
    #ifdef AUDIO_ENABLE
    static uint8_t caps_state = 0;
	static uint8_t num_state = 0;
    if (caps_state != led_state.caps_lock) {
        led_state.caps_lock ? PLAY_SONG(caps_on) : PLAY_SONG(caps_off);
		writePin(GP24, led_state.caps_lock);
        caps_state = led_state.caps_lock;
    }
	if (num_state != led_state.num_lock) {
        //led_state.num_lock ? PLAY_SONG(num_on) : PLAY_SONG(num_off);
		//writePin(GP25, !led_state.caps_lock);
        num_state = led_state.num_lock;
    }
    #endif
    return true;
}

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if(res) {
        // Inverts LED indicator behavior for Num lock so it is off when Num lock is on
		writePin(GP25, !led_state.num_lock);
		//writePin(GP24, led_state.num_lock);
    }
    return res;
}

void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_KANA)) {
		
	} else {
		
	}

}
