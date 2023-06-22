#include QMK_KEYBOARD_H
#include "oled.c"

enum layer_names {
    _BASE,
    _ONE,
    _TWO,
    _THREE
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKSONG1 = SAFE_RANGE,
    QMKSONG2,
    QMKSONG3,
    QMKSONG4,
    QMKSONG5,
    QMKSONG6,
    QMKSONG7,
    QMKSONG8,
    QMKSONG9,
    QMKSONG10
};

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
	//  ------- ==================================    DEFAULT LAYOUT    ===================================
	//  ------- ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬───────────┐
	//  ------- │ESC  │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │  =  │ BACKSPACE │ 
	//  ------- ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┤
	//  ------- │TAB     │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │BSPC    │
	//  ┌─────┐ ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴────────┤
	//  │ENC1 │ │CAPS     │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │ENTER        │
	//  ├─────┤ ├─────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬─────┬────┘
	//  │ENC2 │ │LSHFT       │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │UP   │DEL  │ 
	//  ├─────┤ ├──────┬─────┴─┬───┴──┬──┴─────┴────┬┴─────┼─────┴─────┴────┬┴─────┼─────┼─────┼─────┤
	//  │ENC3 │ │LCTRL │L_GUI  │L_ALT │SPC          │FN1   │SPC             │FN2   │LEFT │DOWN │RIGHT│
	//  └─────┘ └──────┴───────┴──────┴─────────────┴──────┴────────────────┴──────┴─────┴─────┴─────┘
	//			
	//  COL 0,	1,	2,	3,	4,	5,	6,	7,	8,	9,	10,	11,	12,	13		ROW
	    QK_GESC, KC_1  , KC_2  , KC_3  , KC_4  , KC_5  , KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_MINS, KC_EQL,KC_BSPC,	// 	0
	    KC_TAB, KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  , KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_LBRC,KC_RBRC,KC_BSLS, //	1
	    TO(1) ,KC_CAPS, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  , KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT, KC_ENT, //	2
	    KC_P2 ,KC_LSFT, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  , KC_N  , KC_M  ,KC_COMM, KC_DOT,KC_SLSH, KC_UP ,KC_RSFT, //	3
	    KC_P3 ,KC_LCTL,KC_LGUI,KC_LALT, KC_SPC, 	KC_SPC, KC_SPC, 	MO(1) ,KC_LEFT,KC_DOWN,KC_RGHT 		//	4
	  ),

	  [_ONE] = LAYOUT(
	//  ------- ==================================    DEFAULT LAYOUT    ===================================
	//  ------- ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬───────────┐
	//  ------- │  `  │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │ DEL	      │ 
	//  ------- ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┤
	//  ------- │TAB     │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │BSPC    │
	//  ┌─────┐ ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴────────┤
	//  │ENC1 │ │CAPS     │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │ENTER        │
	//  ├─────┤ ├─────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬─────┬────┘
	//  │ENC2 │ │LSHFT       │ S1  │ S2  │ S3  │ S4  │ S5  │ S6  │ S7  │ S8  │ S9  │ S10 │UP   │DEL  │ 
	//  ├─────┤ ├──────┬─────┴─┬───┴──┬──┴─────┴────┬┴─────┼─────┴─────┴────┬┴─────┼─────┼─────┼─────┤
	//  │ENC3 │ │LCTRL │L_GUI  │L_ALT │SPC          │FN1   │SPC             │FN2   │LEFT │DOWN │RIGHT│
	//  └─────┘ └──────┴───────┴──────┴─────────────┴──────┴────────────────┴──────┴─────┴─────┴─────┘
	//			
	// COL 0,	1,	2,	3,	4,	5,	6,	7,	8,	9,	10,	11,	12,	13		ROW
	    KC_GRV, KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6 , KC_F7 , KC_F8 , KC_F9 , KC_F10, KC_F11, KC_F12, KC_DEL,	// 	0
	    MU_NEXT, KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  , KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,CK_UP,CK_DOWN,CK_TOGG, 	//	1
	    TO(0) ,KC_CAPS, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  , KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,CK_RST, 	//	2
	    AU_TOGG,KC_LSFT,QMKSONG1,QMKSONG2,QMKSONG3,QMKSONG4,QMKSONG5,QMKSONG6,QMKSONG7,QMKSONG8,QMKSONG9,QMKSONG10, RGB_MOD , RGB_TOG, //	3
	    MU_TOGG,KC_LCTL,KC_LGUI,KC_LALT, KC_SPC, 	KC_SPC, KC_SPC, 	KC_TRNS ,RGB_VAI,RGB_SAI,RGB_HUI 		//	4
	  ),
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

	//  ------- ==================================    DEFAULT LAYOUT    ===================================
	//  ------- ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬───────────┐ <Grave key - Esc, Shift to ~ and Win to `
	//  ------- │ESC  │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │  =  │ BACKSPACE │ <Add smart backspace. Hold shift to Del
	//  ------- ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┤
	//  ------- │TAB     │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │BSPC    │
	//  ┌─────┐ ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴────────┤
	//  │ENC1 │ │CAPS     │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │ENTER        │
	//  ├─────┤ ├─────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬─────┬────┘
	//  │ENC2 │ │LSHFT       │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │UP   │RSHFT│ <Change to Right shift
	//  ├─────┤ ├──────┬─────┴─┬───┴──┬──┴─────┴────┬┴─────┼─────┴─────┴────┬┴─────┼─────┼─────┼─────┤
	//  │ENC3 │ │LCTRL │L_GUI  │L_ALT │SPC          │FN1   │SPC             │FN2   │LEFT │DOWN │RIGHT│
	//  └─────┘ └──────┴───────┴──────┴─────────────┴──────┴────────────────┴──────┴─────┴─────┴─────┘
	//  Large knob should cycle through layers, and the button should set back to default layer

	//  ------- ==================================    FUNCTION LAYER    ===================================
	//  ------- ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬───────────┐
	//  ------- │ESC  │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │  0  │  -  │  =  │ BACKSPACE │ <Change to F1-F12
	//  ------- ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┤
	//  ------- │TAB     │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │BSPC    │ <Change to F13-24?
	//  ┌─────┐ ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴────────┤
	//  │ENC1 │ │CAPS     │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │ENTER        │
	//  ├─────┤ ├─────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬─────┬────┘
	//  │ENC2 │ │LSHFT       │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │UP   │DEL  │ 
	//  ├─────┤ ├──────┬─────┴─┬───┴──┬──┴─────┴────┬┴─────┼─────┴─────┴────┬┴─────┼─────┼─────┼─────┤
	//  │ENC3 │ │LCTRL │L_GUI  │L_ALT │SPC          │FN1   │SPC             │FN2   │LEFT │DOWN │RIGHT│
	//  └─────┘ └──────┴───────┴──────┴─────────────┴──────┴────────────────┴──────┴─────┴─────┴─────┘
	//  Potentially add functions for enabling Music mode, Clicky mode

	//  ------- ==================================    LIGHTING LAYER    ===================================
	//  ------- ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬───────────┐
	//  ------- │ESC  │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │  =  │ BACKSPACE │ <Add lighting modes to 1 though =
	//  ------- ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┤
	//  ------- │TAB     │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │BSPC    │
	//  ┌─────┐ ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴────────┤
	//  │ENC1 │ │CAPS     │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │ENTER        │
	//  ├─────┤ ├─────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬─────┬────┘
	//  │ENC2 │ │LSHFT       │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │UP   │DEL  │ 
	//  ├─────┤ ├──────┬─────┴─┬───┴──┬──┴─────┴────┬┴─────┼─────┴─────┴────┬┴─────┼─────┼─────┼─────┤
	//  │ENC3 │ │LCTRL │L_GUI  │L_ALT │SPC          │FN1   │SPC             │FN2   │LEFT │DOWN │RIGHT│
	//  └─────┘ └──────┴───────┴──────┴─────────────┴──────┴────────────────┴──────┴─────┴─────┴─────┘
	//  Encoders should control Hue and Brightness

	//  ------- ==================================    MUSIC LAYER      ===================================
	//  ------- ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬───────────┐
	//  ------- │ESC  │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │  =  │ BACKSPACE │ <Set to different songs
	//  ------- ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┤
	//  ------- │TAB     │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │BSPC    │ <Set to different songs
	//  ┌─────┐ ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴────────┤
	//  │ENC1 │ │CAPS     │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │ENTER        │ <Set to different songs
	//  ├─────┤ ├─────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬─────┬────┘
	//  │ENC2 │ │LSHFT       │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │UP   │DEL  │ 
	//  ├─────┤ ├──────┬─────┴─┬───┴──┬──┴─────┴────┬┴─────┼─────┴─────┴────┬┴─────┼─────┼─────┼─────┤
	//  │ENC3 │ │LCTRL │L_GUI  │L_ALT │SPC          │FN1   │SPC             │FN2   │LEFT │DOWN │RIGHT│
	//  └─────┘ └──────┴───────┴──────┴─────────────┴──────┴────────────────┴──────┴─────┴─────┴─────┘

	//  ------- ==================================    GAMING FPS        ===================================
	//  ------- ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬───────────┐
	//  ------- │ESC  │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │  =  │ BACKSPACE │ 
	//  ------- ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┤
	//  ------- │TAB     │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │BSPC    │
	//  ┌─────┐ ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴────────┤
	//  │ENC1 │ │CAPS     │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │ENTER        │
	//  ├─────┤ ├─────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬─────┬────┘
	//  │ENC2 │ │LSHFT       │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │UP   │DEL  │ 
	//  ├─────┤ ├──────┬─────┴─┬───┴──┬──┴─────┴────┬┴─────┼─────┴─────┴────┬┴─────┼─────┼─────┼─────┤
	//  │ENC3 │ │LCTRL │L_GUI  │L_ALT │SPC          │FN1   │SPC             │FN2   │LEFT │DOWN │RIGHT│
	//  └─────┘ └──────┴───────┴──────┴─────────────┴──────┴────────────────┴──────┴─────┴─────┴─────┘
	//  Set lighting to highlight WASD

	//  ------- ==================================    GAMING ARPG       ===================================
	//  ------- ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬───────────┐
	//  ------- │ESC  │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │  =  │ BACKSPACE │ 
	//  ------- ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┤
	//  ------- │TAB     │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │BSPC    │
	//  ┌─────┐ ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴────────┤
	//  │ENC1 │ │CAPS     │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │ENTER        │
	//  ├─────┤ ├─────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬─────┬────┘
	//  │ENC2 │ │LSHFT       │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │UP   │DEL  │ 
	//  ├─────┤ ├──────┬─────┴─┬───┴──┬──┴─────┴────┬┴─────┼─────┴─────┴────┬┴─────┼─────┼─────┼─────┤
	//  │ENC3 │ │LCTRL │L_GUI  │L_ALT │SPC          │FN1   │SPC             │FN2   │LEFT │DOWN │RIGHT│
	//  └─────┘ └──────┴───────┴──────┴─────────────┴──────┴────────────────┴──────┴─────┴─────┴─────┘
	//  Set lighting to highlight QWER

	//  ------- ==================================    CREATIVE APPS     ===================================
	//  ------- ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬───────────┐
	//  ------- │ESC  │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │  =  │ BACKSPACE │ 
	//  ------- ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┤
	//  ------- │TAB     │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │BSPC    │
	//  ┌─────┐ ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴────────┤
	//  │ENC1 │ │CAPS     │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │ENTER        │
	//  ├─────┤ ├─────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬─────┬────┘
	//  │ENC2 │ │LSHFT       │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │UP   │DEL  │ 
	//  ├─────┤ ├──────┬─────┴─┬───┴──┬──┴─────┴────┬┴─────┼─────┴─────┴────┬┴─────┼─────┼─────┼─────┤
	//  │ENC3 │ │LCTRL │L_GUI  │L_ALT │SPC          │FN1   │SPC             │FN2   │LEFT │DOWN │RIGHT│
	//  └─────┘ └──────┴───────┴──────┴─────────────┴──────┴────────────────┴──────┴─────┴─────┴─────┘
	//  Encoders can control Hue/Sat/Brightness and Undo/Redo?

	//  ------- ==================================    NUMPAD LAYER    ===================================
	//  ------- ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬───────────┐
	//  ------- │ESC  │  1  │  2  │  3  │  4  │  5  │  6  │ NUM │  /  │  *  │  -  │  -  │  =  │ BACKSPACE │ 
	//  ------- ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┤
	//  ------- │TAB     │  Q  │  W  │  E  │  R  │  T  │  Y  │ N7  │ N8  │ N9  │  +  │  [  │  ]  │BSPC    │
	//  ┌─────┐ ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴────────┤
	//  │ENC1 │ │CAPS     │  A  │  S  │  D  │  F  │  G  │  H  │ N4  │ N5  │ N6  │  ;  │  '  │ENTER        │
	//  ├─────┤ ├─────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬─────┬────┘
	//  │ENC2 │ │LSHFT       │  Z  │  X  │  C  │  V  │  B  │  N  │ N1  │ N2  │ N3  │  /  │UP   │DEL  │ 
	//  ├─────┤ ├──────┬─────┴─┬───┴──┬──┴─────┴────┬┴─────┼─────┴─────┴────┬┴─────┼─────┼─────┼─────┤
	//  │ENC3 │ │LCTRL │L_GUI  │L_ALT │SPC          │FN1   │ N0             │  N.  │LEFT │DOWN │RIGHT│
	//  └─────┘ └──────┴───────┴──────┴─────────────┴──────┴────────────────┴──────┴─────┴─────┴─────┘
	//  Calculator mode. Should have buttons to launch and clear the calculator

	//  ------- ==================================      WORK LAYOUT     ===================================
	//  ------- ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬───────────┐
	//  ------- │ESC  │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │  =  │ BACKSPACE │ 
	//  ------- ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┤
	//  ------- │TAB     │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │BSPC    │
	//  ┌─────┐ ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴────────┤
	//  │ENC1 │ │CAPS     │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │ENTER        │
	//  ├─────┤ ├─────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬─────┬────┘
	//  │ENC2 │ │LSHFT       │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │UP   │DEL  │ 
	//  ├─────┤ ├──────┬─────┴─┬───┴──┬──┴─────┴────┬┴─────┼─────┴─────┴────┬┴─────┼─────┼─────┼─────┤
	//  │ENC3 │ │LCTRL │L_GUI  │L_ALT │SPC          │FN1   │SPC             │FN2   │LEFT │DOWN │RIGHT│
	//  └─────┘ └──────┴───────┴──────┴─────────────┴──────┴────────────────┴──────┴─────┴─────┴─────┘
	//  Can include shortcuts to NextGen, Calculator


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
/*
float song11[][2] = SONG(ODE_TO_JOY);
float song12[][2] = SONG(ROCK_A_BYE_BABY);
float song13[][2] = SONG(CAMPANELLA);
float song14[][2] = SONG(FANTASIE_IMPROMPTU);
float song15[][2] = SONG(NOCTURNE_OP_9_NO_1);
*/

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


#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
//			Encoder 1 (2,0)			Encoder 2 (3,0)			Encoder 3 (4,0)
    [_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),	ENCODER_CCW_CW(KC_1, KC_2),	ENCODER_CCW_CW(KC_3, KC_4) },
    [_ONE] =  { ENCODER_CCW_CW(KC_5, KC_6),		ENCODER_CCW_CW(KC_7, KC_8),	ENCODER_CCW_CW(KC_9, KC_0) },
    // [_ARRW] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    // [_RGB]  = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
};
#endif

/*
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	keyevent_t event = record->event;

	switch (id) {

	}
	return MACRO_NONE;
}
*/

/* ENABLES SHIFT + BACKSPACE TO DELETE */
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    NULL // Null terminate the array of overrides!
};

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
				/* AUDIO BUTTIONS */
			case QMKSONG1:
				if (record->event.pressed) {
					// when keycode QMKSONG1 is pressed
					PLAY_SONG(song1);
				}
				break;
			case QMKSONG2:
				if (record->event.pressed) {
					// when keycode QMKSONG2 is pressed
					PLAY_SONG(song2);
				}
				break; 
			case QMKSONG3:
				if (record->event.pressed) {
					// when keycode QMKSONG3 is pressed
					PLAY_SONG(song3);
				}
				break;
			case QMKSONG4:
				if (record->event.pressed) {
					// when keycode QMKSONG4 is pressed
					PLAY_SONG(song4);
				}
				break;
			case QMKSONG5:
				if (record->event.pressed) {
					// when keycode QMKSONG5 is pressed
					PLAY_SONG(song5);
				}
				break;
			case QMKSONG6:
				if (record->event.pressed) {
					// when keycode QMKSONG6 is pressed
					PLAY_SONG(song6);
				}
				break;
			case QMKSONG7:
				if (record->event.pressed) {
					// when keycode QMKSONG7 is pressed
					PLAY_SONG(song7);
				}
				break;
			case QMKSONG8:
				if (record->event.pressed) {
					// when keycode QMKSONG8 is pressed
					PLAY_SONG(song8);
				}
				break;
			case QMKSONG9:
				if (record->event.pressed) {
					// when keycode QMKSONG9 is pressed
					PLAY_SONG(song9);
				}
				break;
			case QMKSONG10:
				if (record->event.pressed) {
					// when keycode QMKSONG10 is pressed
					PLAY_SONG(song10);
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
        led_state.num_lock ? PLAY_SONG(num_on) : PLAY_SONG(num_off);
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
