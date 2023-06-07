#include QMK_KEYBOARD_H

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
	//		===================================    MATRIX LAYOUT    ===================================
	//		┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬───────────┐
	//		│ 0,0 │ 0,1 │ 0,2 │ 0,3 │ 0,4 │ 0,5 │ 0,6 │ 0,7 │ 0,8 │ 0,9 │0,10 │0,11 │0,12 │ 0,13      │ 
	//		├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┤
	//		│ 1,0    │ 1,1 │ 1,2 │ 1,3 │ 1,4 │ 1,5 │ 1,6 │ 1,7 │ 1,8 │ 1,9 │1,10 │1,11 │1,12 │ 1,13   │
	//	┌─────┐	├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴────────┤
	//	│ 2,0 │ │ 2,1     │ 2,2 │ 2,3 │ 2,4 │ 2,5 │ 2,6 │ 2,7 │ 2,8 │ 2,9 │2,10 │2,11 │2,12 │   2,13      │
	//	├─────┤	├─────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬─────┬────┘
	//	│ 3,0 │	│ 3,1        │ 3,2 │ 3,3 │ 3,4 │ 3,5 │ 3,6 │ 3,7 │ 3,8 │ 3,9 │3,10 │3,11 │3,12 │3,13 │ 
	//	├─────┤	├──────┬─────┴─┬───┴──┬──┴─────┴────┬┴─────┼─────┴─────┴────┬┴─────┼─────┼─────┼─────┤
	//	│ 4,0 │	│ 4,1  │ 4,2   │ 4,3  │ 4,4         │ 4,6  │ 4,7            │ 4,9  │4,10 │4,11 │4,12 │
	//	└─────┘	└──────┴───────┴──────┴─────────────┴──────┴────────────────┴──────┴─────┴─────┴─────┘
	//		=======================================  ROW , COL  =======================================
	
	  [_BASE] = LAYOUT(
	//		==================================    DEFAULT LAYOUT    ===================================
	//		┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬───────────┐
	//		│ESC  │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │  =  │ BACKSPACE │ 
	//		├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┤
	//		│TAB     │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │BSPC    │
	//	┌─────┐	├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴────────┤
	//	│ENC1 │ │CAPS     │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │ENTER        │
	//	├─────┤	├─────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬─────┬────┘
	//	│ENC2 │	│LSHFT       │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │UP   │DEL  │ 
	//	├─────┤	├──────┬─────┴─┬───┴──┬──┴─────┴────┬┴─────┼─────┴─────┴────┬┴─────┼─────┼─────┼─────┤
	//	│ENC3 │	│LCTRL │L_GUI  │L_ALT │SPC          │FN1   │SPC             │FN2   │LEFT │DOWN │RIGHT│
	//	└─────┘	└──────┴───────┴──────┴─────────────┴──────┴────────────────┴──────┴─────┴─────┴─────┘
	//			
	//	 	COL 0,	1,	2,	3,	4,	5,	6,	7,	8,	9,	10,	11,	12,	13		ROW
			KC_ESC, KC_1  , KC_2  , KC_3  , KC_4  , KC_5  , KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_MINS, KC_EQL,KC_BSPC,	// 	0
			KC_TAB, KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  , KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_LBRC,KC_RBRC,KC_BSLS, //	1
			TO(1) ,KC_CAPS, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  , KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT, KC_ENT, //	2
			KC_P2 ,KC_LSFT, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  , KC_N  , KC_M  ,KC_COMM, KC_DOT,KC_SLSH, KC_UP , KC_DEL, //	3
			KC_P3 ,KC_LCTL,KC_LGUI,KC_LALT, KC_SPC, 	KC_SPC, KC_SPC, 	KC_P4 ,KC_LEFT,KC_DOWN,KC_RGHT 		//	4
	  ),
	  [_ONE] = LAYOUT(
	//		==================================    DEFAULT LAYOUT    ===================================
	//		┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬───────────┐
	//		│  `  │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │ DEL	  │ 
	//		├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┤
	//		│TAB     │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │BSPC    │
	//	┌─────┐	├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴────────┤
	//	│ENC1 │ │CAPS     │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │ENTER        │
	//	├─────┤	├─────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬─────┬────┘
	//	│ENC2 │	│LSHFT       │ S1  │ S2  │ S3  │ S4  │ S5  │ S6  │ S7  │ S8  │ S9  │ S10 │UP   │DEL  │ 
	//	├─────┤	├──────┬─────┴─┬───┴──┬──┴─────┴────┬┴─────┼─────┴─────┴────┬┴─────┼─────┼─────┼─────┤
	//	│ENC3 │	│LCTRL │L_GUI  │L_ALT │SPC          │FN1   │SPC             │FN2   │LEFT │DOWN │RIGHT│
	//	└─────┘	└──────┴───────┴──────┴─────────────┴──────┴────────────────┴──────┴─────┴─────┴─────┘
	//			
	// 		COL 0,	1,	2,	3,	4,	5,	6,	7,	8,	9,	10,	11,	12,	13		ROW
			KC_GRV, KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6 , KC_F7 , KC_F8 , KC_F9 , KC_F10, KC_F11, KC_F12, KC_DEL,	// 	0
			MU_NEXT, KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  , KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,CK_UP,CK_DOWN,CK_TOGG, //	1
			TO(0) ,KC_CAPS, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  , KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,CK_RST, //	2
			AU_TOGG,KC_LSFT,QMKSONG1,QMKSONG2,QMKSONG3,QMKSONG4,QMKSONG5,QMKSONG6,QMKSONG7,QMKSONG8,QMKSONG9,QMKSONG10, KC_UP , KC_DEL, //	3
			MU_TOGG,KC_LCTL,KC_LGUI,KC_LALT, KC_SPC, 	KC_SPC, KC_SPC, 	KC_P4 ,KC_LEFT,KC_DOWN,KC_RGHT 		//	4
	  ),
};

	//		===================================    2U SPACEBARS    ====================================
	//		┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬───────────┐
	//		│ESC  │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │  =  │ BACKSPACE │ 
	//		├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┤
	//		│TAB     │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │BSPC    │
	//	┌─────┐	├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴────────┤
	//	│ENC1 │ │CAPS     │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │ENTER        │
	//	├─────┤	├─────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬─────┬────┘
	//	│ENC2 │	│LSHFT       │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │UP   │DEL  │ 
	//	├─────┤	├──────┬─────┴─┬───┴──┬──┴─────┴──┬──┴─────┴──┬──┴─────┴───┬─┴─────┼─────┼─────┼─────┤
	//	│ENC3 │	│LCTRL │L_GUI  │L_ALT │SPC        │FN1        │SPC         │FN2    │LEFT │DOWN │RIGHT│
	//	└─────┘	└──────┴───────┴──────┴───────────┴───────────┴────────────┴───────┴─────┴─────┴─────┘


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

#ifdef OLED_ENABLE

/* KEYBOARD PET START */

		/* settings */
		#    define MIN_WALK_SPEED      10
		#    define MIN_RUN_SPEED       40

		/* advanced settings */
		#    define ANIM_FRAME_DURATION 400  // how long each frame lasts in ms
		#    define ANIM_SIZE           32   // number of bytes in array. If you change sprites, minimize for adequate firmware size. max is 1024

		/* timers */
		uint32_t anim_timer = 0;

		/* current frame */
		uint8_t current_frame = 0;

		/* status variables */
		int   current_wpm = 0;
		led_t led_usb_state;

		bool isSneaking = false;
		bool isJumping  = false;
		bool showedJump = true;

		/* logic */
		static void render_luna(int LUNA_X, int LUNA_Y) {
			/* Sit 1 */
			static const char PROGMEM sit1[2][ANIM_SIZE] = {
					/* 'cat_sleep_1', 32x24px */
				{
					0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x32, 0x2a, 
					0x26, 0x02, 0x00, 0x00, 0x10, 0x19, 0x1d, 0x17, 0x13, 0x01, 0x00, 0x40, 0xc0, 0x40, 0x00, 0x00, 
					// 0x00, 0x00, 0xc0, 0x60, 0x30, 0x98, 0x0c, 0x04, 0x06, 0x02, 0x22, 0xc3, 0x01, 0x01, 0x01, 0x01, 
					// 0x01, 0xf9, 0xc9, 0x59, 0x72, 0x62, 0x22, 0x24, 0x24, 0x68, 0x70, 0x59, 0xc9, 0xf9, 0x00, 0x00, 
					// 0x00, 0x1f, 0x30, 0x20, 0x20, 0x41, 0x72, 0x7c, 0x7c, 0x78, 0x30, 0x20, 0x21, 0x3e, 0x20, 0x24, 
					// 0x24, 0x4f, 0x38, 0x50, 0x64, 0x48, 0x40, 0x50, 0x40, 0x48, 0x64, 0x30, 0x18, 0x2f, 0x44, 0x04,
				},
			   
					/* 'cat_sleep_2', 32x24px */
				{
				   	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x62, 0x72, 0x5a, 0x4e, 0x46, 0x02, 
					0x00, 0x00, 0x00, 0x09, 0x0d, 0x0b, 0x09, 0x00, 0x00, 0x90, 0xd0, 0xb0, 0x90, 0x00, 0x00, 0x00, 
					// 0x00, 0x00, 0xc0, 0x60, 0x30, 0x98, 0x08, 0x0c, 0x04, 0x04, 0x46, 0x82, 0x02, 0x02, 0x02, 0x02, 
					// 0x02, 0xfa, 0xca, 0x5a, 0x72, 0x62, 0x26, 0x24, 0x24, 0x68, 0x70, 0x58, 0xc8, 0xf8, 0x00, 0x00, 
					// 0x00, 0x1f, 0x30, 0x20, 0x20, 0x41, 0x72, 0x7c, 0x7c, 0x78, 0x30, 0x20, 0x21, 0x3e, 0x20, 0x24, 
					// 0x24, 0x4f, 0x38, 0x50, 0x64, 0x48, 0x40, 0x50, 0x40, 0x48, 0x64, 0x30, 0x18, 0x2f, 0x44, 0x04,
				}
			};
			
			/* Sit 2 */
			static const char PROGMEM sit2[2][ANIM_SIZE] = {
					/* 'cat_sleep_1', 32x24px */
				{
					// 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x32, 0x2a, 
					// 0x26, 0x02, 0x00, 0x00, 0x10, 0x19, 0x1d, 0x17, 0x13, 0x01, 0x00, 0x40, 0xc0, 0x40, 0x00, 0x00, 
					0x00, 0x00, 0xc0, 0x60, 0x30, 0x98, 0x0c, 0x04, 0x06, 0x02, 0x22, 0xc3, 0x01, 0x01, 0x01, 0x01, 
					0x01, 0xf9, 0xc9, 0x59, 0x72, 0x62, 0x22, 0x24, 0x24, 0x68, 0x70, 0x59, 0xc9, 0xf9, 0x00, 0x00, 
					// 0x00, 0x1f, 0x30, 0x20, 0x20, 0x41, 0x72, 0x7c, 0x7c, 0x78, 0x30, 0x20, 0x21, 0x3e, 0x20, 0x24, 
					// 0x24, 0x4f, 0x38, 0x50, 0x64, 0x48, 0x40, 0x50, 0x40, 0x48, 0x64, 0x30, 0x18, 0x2f, 0x44, 0x04,
				},
			   
					/* 'cat_sleep_2', 32x24px */
				{
				   	// 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x62, 0x72, 0x5a, 0x4e, 0x46, 0x02, 
					// 0x00, 0x00, 0x00, 0x09, 0x0d, 0x0b, 0x09, 0x00, 0x00, 0x90, 0xd0, 0xb0, 0x90, 0x00, 0x00, 0x00, 
					0x00, 0x00, 0xc0, 0x60, 0x30, 0x98, 0x08, 0x0c, 0x04, 0x04, 0x46, 0x82, 0x02, 0x02, 0x02, 0x02, 
					0x02, 0xfa, 0xca, 0x5a, 0x72, 0x62, 0x26, 0x24, 0x24, 0x68, 0x70, 0x58, 0xc8, 0xf8, 0x00, 0x00, 
					// 0x00, 0x1f, 0x30, 0x20, 0x20, 0x41, 0x72, 0x7c, 0x7c, 0x78, 0x30, 0x20, 0x21, 0x3e, 0x20, 0x24, 
					// 0x24, 0x4f, 0x38, 0x50, 0x64, 0x48, 0x40, 0x50, 0x40, 0x48, 0x64, 0x30, 0x18, 0x2f, 0x44, 0x04,
				}
			};

			/* Sit 3 */
			static const char PROGMEM sit3[2][ANIM_SIZE] = {
					/* 'cat_sleep_1', 32x24px */
				{
					// 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x32, 0x2a, 
					// 0x26, 0x02, 0x00, 0x00, 0x10, 0x19, 0x1d, 0x17, 0x13, 0x01, 0x00, 0x40, 0xc0, 0x40, 0x00, 0x00, 
					// 0x00, 0x00, 0xc0, 0x60, 0x30, 0x98, 0x0c, 0x04, 0x06, 0x02, 0x22, 0xc3, 0x01, 0x01, 0x01, 0x01, 
					// 0x01, 0xf9, 0xc9, 0x59, 0x72, 0x62, 0x22, 0x24, 0x24, 0x68, 0x70, 0x59, 0xc9, 0xf9, 0x00, 0x00, 
					0x00, 0x1f, 0x30, 0x20, 0x20, 0x41, 0x72, 0x7c, 0x7c, 0x78, 0x30, 0x20, 0x21, 0x3e, 0x20, 0x24, 
					0x24, 0x4f, 0x38, 0x50, 0x64, 0x48, 0x40, 0x50, 0x40, 0x48, 0x64, 0x30, 0x18, 0x2f, 0x44, 0x04,
				},
			   
					/* 'cat_sleep_2', 32x24px */
				{
				   	// 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x62, 0x72, 0x5a, 0x4e, 0x46, 0x02, 
					// 0x00, 0x00, 0x00, 0x09, 0x0d, 0x0b, 0x09, 0x00, 0x00, 0x90, 0xd0, 0xb0, 0x90, 0x00, 0x00, 0x00, 
					// 0x00, 0x00, 0xc0, 0x60, 0x30, 0x98, 0x08, 0x0c, 0x04, 0x04, 0x46, 0x82, 0x02, 0x02, 0x02, 0x02, 
					// 0x02, 0xfa, 0xca, 0x5a, 0x72, 0x62, 0x26, 0x24, 0x24, 0x68, 0x70, 0x58, 0xc8, 0xf8, 0x00, 0x00, 
					0x00, 0x1f, 0x30, 0x20, 0x20, 0x41, 0x72, 0x7c, 0x7c, 0x78, 0x30, 0x20, 0x21, 0x3e, 0x20, 0x24, 
					0x24, 0x4f, 0x38, 0x50, 0x64, 0x48, 0x40, 0x50, 0x40, 0x48, 0x64, 0x30, 0x18, 0x2f, 0x44, 0x04,
				}
			};			

			/* Walk 1 */
			static const char PROGMEM walk1[2][ANIM_SIZE] = {
					/* 'cat_walk_1', 32x24px */
				{
					0x00, 0x00, 0x00, 0xfc, 0x0e, 0x1f, 0x1f, 0xff, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 
					0xd8, 0x98, 0xf0, 0x60, 0x20, 0x20, 0x20, 0x38, 0x38, 0x70, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
					// 0x00, 0x00, 0x00, 0x0f, 0x18, 0xf0, 0x00, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x09, 0x49, 
					// 0x25, 0x14, 0x10, 0x20, 0x00, 0x02, 0x40, 0xc0, 0xc8, 0x22, 0x11, 0x1f, 0x24, 0x24, 0x00, 0x00, 
					// 0x00, 0x00, 0x00, 0x00, 0x3e, 0x63, 0x40, 0x40, 0x30, 0x18, 0x0c, 0x1e, 0x3e, 0x3e, 0x36, 0x04, 
					// 0x04, 0x04, 0x1c, 0x3c, 0x38, 0x30, 0x20, 0x43, 0x47, 0x48, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00,
				},

					/* 'cat_walk_2', 32x24px */
				{
					0x00, 0x00, 0xfc, 0x0e, 0x1f, 0x1f, 0xff, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 
					0xec, 0x4c, 0x78, 0x30, 0x10, 0x10, 0x10, 0x1c, 0x1c, 0x38, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 
					// 0x00, 0x00, 0x03, 0x0e, 0x18, 0xe0, 0x00, 0x01, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x05, 0x15, 
					// 0x12, 0x0a, 0x08, 0x10, 0x00, 0x01, 0x20, 0xe0, 0x24, 0x11, 0x08, 0x0f, 0x0a, 0x0a, 0x00, 0x00, 
					// 0x00, 0x00, 0x00, 0x00, 0x00, 0x1d, 0x3f, 0x3c, 0x30, 0x40, 0x40, 0x46, 0x3f, 0x02, 0x02, 0x02, 
					// 0x3e, 0x43, 0x40, 0x40, 0x38, 0x1e, 0x3f, 0x3f, 0x3e, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
				}	
			};
			
			/* Walk 2 */
			static const char PROGMEM walk2[2][ANIM_SIZE] = {
					/* 'cat_walk_1', 32x24px */
				{
					// 0x00, 0x00, 0x00, 0xfc, 0x0e, 0x1f, 0x1f, 0xff, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 
					// 0xd8, 0x98, 0xf0, 0x60, 0x20, 0x20, 0x20, 0x38, 0x38, 0x70, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
					0x00, 0x00, 0x00, 0x0f, 0x18, 0xf0, 0x00, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x09, 0x49, 
					0x25, 0x14, 0x10, 0x20, 0x00, 0x02, 0x40, 0xc0, 0xc8, 0x22, 0x11, 0x1f, 0x24, 0x24, 0x00, 0x00, 
					// 0x00, 0x00, 0x00, 0x00, 0x3e, 0x63, 0x40, 0x40, 0x30, 0x18, 0x0c, 0x1e, 0x3e, 0x3e, 0x36, 0x04, 
					// 0x04, 0x04, 0x1c, 0x3c, 0x38, 0x30, 0x20, 0x43, 0x47, 0x48, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00,
				},

					/* 'cat_walk_2', 32x24px */
				{
					// 0x00, 0x00, 0xfc, 0x0e, 0x1f, 0x1f, 0xff, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 
					// 0xec, 0x4c, 0x78, 0x30, 0x10, 0x10, 0x10, 0x1c, 0x1c, 0x38, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 
					0x00, 0x00, 0x03, 0x0e, 0x18, 0xe0, 0x00, 0x01, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x05, 0x15, 
					0x12, 0x0a, 0x08, 0x10, 0x00, 0x01, 0x20, 0xe0, 0x24, 0x11, 0x08, 0x0f, 0x0a, 0x0a, 0x00, 0x00, 
					// 0x00, 0x00, 0x00, 0x00, 0x00, 0x1d, 0x3f, 0x3c, 0x30, 0x40, 0x40, 0x46, 0x3f, 0x02, 0x02, 0x02, 
					// 0x3e, 0x43, 0x40, 0x40, 0x38, 0x1e, 0x3f, 0x3f, 0x3e, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
				}	
			};
			
			/* Walk 3 */
			static const char PROGMEM walk3[2][ANIM_SIZE] = {
					/* 'cat_walk_1', 32x24px */
				{
					// 0x00, 0x00, 0x00, 0xfc, 0x0e, 0x1f, 0x1f, 0xff, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 
					// 0xd8, 0x98, 0xf0, 0x60, 0x20, 0x20, 0x20, 0x38, 0x38, 0x70, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
					// 0x00, 0x00, 0x00, 0x0f, 0x18, 0xf0, 0x00, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x09, 0x49, 
					// 0x25, 0x14, 0x10, 0x20, 0x00, 0x02, 0x40, 0xc0, 0xc8, 0x22, 0x11, 0x1f, 0x24, 0x24, 0x00, 0x00, 
					0x00, 0x00, 0x00, 0x00, 0x3e, 0x63, 0x40, 0x40, 0x30, 0x18, 0x0c, 0x1e, 0x3e, 0x3e, 0x36, 0x04, 
					0x04, 0x04, 0x1c, 0x3c, 0x38, 0x30, 0x20, 0x43, 0x47, 0x48, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00,
				},

					/* 'cat_walk_2', 32x24px */
				{
					// 0x00, 0x00, 0xfc, 0x0e, 0x1f, 0x1f, 0xff, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 
					// 0xec, 0x4c, 0x78, 0x30, 0x10, 0x10, 0x10, 0x1c, 0x1c, 0x38, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 
					// 0x00, 0x00, 0x03, 0x0e, 0x18, 0xe0, 0x00, 0x01, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x05, 0x15, 
					// 0x12, 0x0a, 0x08, 0x10, 0x00, 0x01, 0x20, 0xe0, 0x24, 0x11, 0x08, 0x0f, 0x0a, 0x0a, 0x00, 0x00, 
					0x00, 0x00, 0x00, 0x00, 0x00, 0x1d, 0x3f, 0x3c, 0x30, 0x40, 0x40, 0x46, 0x3f, 0x02, 0x02, 0x02, 
					0x3e, 0x43, 0x40, 0x40, 0x38, 0x1e, 0x3f, 0x3f, 0x3e, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
				}	
			};

			/* Run 1 */
			static const char PROGMEM run1[2][ANIM_SIZE] = {
					/* 'cat_run_1', 32x24px */
				{
					0x3c, 0x7e, 0xde, 0x8e, 0x0c, 0x18, 0x30, 0x60, 0x40, 0xc0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 
					0x00, 0x60, 0xe0, 0x60, 0x60, 0xc0, 0xc0, 0x60, 0x60, 0x60, 0x40, 0xc0, 0x80, 0x00, 0x00, 0x00, 
					// 0x00, 0xc0, 0x60, 0x31, 0x1b, 0x0e, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x21, 
					// 0x11, 0x91, 0x49, 0x4b, 0x21, 0x41, 0x00, 0x84, 0x80, 0x80, 0x90, 0x44, 0x23, 0x3e, 0x48, 0x90, 
					// 0x03, 0x0c, 0x08, 0x08, 0x0c, 0x06, 0x03, 0x07, 0x07, 0x07, 0x03, 0x01, 0x01, 0x01, 0x01, 0x03, 
					// 0x06, 0x04, 0x04, 0x08, 0x18, 0x10, 0x20, 0x41, 0x43, 0x43, 0x67, 0x3e, 0x3c, 0x38, 0x00, 0x00,
				},

					/* 'cat_run_2', 32x24px */
				{
					0x00, 0x7c, 0xfe, 0x1e, 0x0e, 0x3c, 0x60, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					0xe0, 0xe0, 0x60, 0x40, 0xc0, 0x80, 0x80, 0xe0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
					// 0x00, 0x00, 0x01, 0x03, 0x06, 0x0c, 0xf8, 0x00, 0x00, 0x01, 0x01, 0x01, 0x02, 0x02, 0x22, 0x22, 
					// 0x92, 0x93, 0x57, 0x42, 0x83, 0x01, 0x08, 0x00, 0x00, 0x20, 0x89, 0x47, 0x7c, 0x90, 0x90, 0x00, 
					// 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0e, 0x18, 0x30, 0x60, 0x40, 0x43, 0x66, 0x3e, 0x63, 
					// 0x40, 0x40, 0x40, 0x78, 0x3e, 0x3e, 0x1b, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
				}
			};

			/* Run 2 */
			static const char PROGMEM run2[2][ANIM_SIZE] = {
					/* 'cat_run_1', 32x24px */
				{
					// 0x3c, 0x7e, 0xde, 0x8e, 0x0c, 0x18, 0x30, 0x60, 0x40, 0xc0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 
					// 0x00, 0x60, 0xe0, 0x60, 0x60, 0xc0, 0xc0, 0x60, 0x60, 0x60, 0x40, 0xc0, 0x80, 0x00, 0x00, 0x00, 
					0x00, 0xc0, 0x60, 0x31, 0x1b, 0x0e, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x21, 
					0x11, 0x91, 0x49, 0x4b, 0x21, 0x41, 0x00, 0x84, 0x80, 0x80, 0x90, 0x44, 0x23, 0x3e, 0x48, 0x90, 
					// 0x03, 0x0c, 0x08, 0x08, 0x0c, 0x06, 0x03, 0x07, 0x07, 0x07, 0x03, 0x01, 0x01, 0x01, 0x01, 0x03, 
					// 0x06, 0x04, 0x04, 0x08, 0x18, 0x10, 0x20, 0x41, 0x43, 0x43, 0x67, 0x3e, 0x3c, 0x38, 0x00, 0x00,
				},

					/* 'cat_run_2', 32x24px */
				{
					// 0x00, 0x7c, 0xfe, 0x1e, 0x0e, 0x3c, 0x60, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					// 0xe0, 0xe0, 0x60, 0x40, 0xc0, 0x80, 0x80, 0xe0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
					0x00, 0x00, 0x01, 0x03, 0x06, 0x0c, 0xf8, 0x00, 0x00, 0x01, 0x01, 0x01, 0x02, 0x02, 0x22, 0x22, 
					0x92, 0x93, 0x57, 0x42, 0x83, 0x01, 0x08, 0x00, 0x00, 0x20, 0x89, 0x47, 0x7c, 0x90, 0x90, 0x00, 
					// 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0e, 0x18, 0x30, 0x60, 0x40, 0x43, 0x66, 0x3e, 0x63, 
					// 0x40, 0x40, 0x40, 0x78, 0x3e, 0x3e, 0x1b, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
				}
			};
			
			/* Run 3 */
			static const char PROGMEM run3[2][ANIM_SIZE] = {
					/* 'cat_run_1', 32x24px */
				{
					// 0x3c, 0x7e, 0xde, 0x8e, 0x0c, 0x18, 0x30, 0x60, 0x40, 0xc0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 
					// 0x00, 0x60, 0xe0, 0x60, 0x60, 0xc0, 0xc0, 0x60, 0x60, 0x60, 0x40, 0xc0, 0x80, 0x00, 0x00, 0x00, 
					// 0x00, 0xc0, 0x60, 0x31, 0x1b, 0x0e, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x21, 
					// 0x11, 0x91, 0x49, 0x4b, 0x21, 0x41, 0x00, 0x84, 0x80, 0x80, 0x90, 0x44, 0x23, 0x3e, 0x48, 0x90, 
					0x03, 0x0c, 0x08, 0x08, 0x0c, 0x06, 0x03, 0x07, 0x07, 0x07, 0x03, 0x01, 0x01, 0x01, 0x01, 0x03, 
					0x06, 0x04, 0x04, 0x08, 0x18, 0x10, 0x20, 0x41, 0x43, 0x43, 0x67, 0x3e, 0x3c, 0x38, 0x00, 0x00,
				},

					/* 'cat_run_2', 32x24px */
				{
					// 0x00, 0x7c, 0xfe, 0x1e, 0x0e, 0x3c, 0x60, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					// 0xe0, 0xe0, 0x60, 0x40, 0xc0, 0x80, 0x80, 0xe0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
					// 0x00, 0x00, 0x01, 0x03, 0x06, 0x0c, 0xf8, 0x00, 0x00, 0x01, 0x01, 0x01, 0x02, 0x02, 0x22, 0x22, 
					// 0x92, 0x93, 0x57, 0x42, 0x83, 0x01, 0x08, 0x00, 0x00, 0x20, 0x89, 0x47, 0x7c, 0x90, 0x90, 0x00, 
					0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0e, 0x18, 0x30, 0x60, 0x40, 0x43, 0x66, 0x3e, 0x63, 
					0x40, 0x40, 0x40, 0x78, 0x3e, 0x3e, 0x1b, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
				}
			};
			
			/* Bark 1 */
			static const char PROGMEM bark1[2][ANIM_SIZE] = {
					/* 'cat_meow_1', 32x24px */
				{
					0x00, 0xc0, 0xe0, 0xe0, 0xc0, 0x80, 0x00, 0x20, 0x20, 0x2f, 0xbb, 0x93, 0x1e, 0x0c, 0x04, 0x44, 
					0x04, 0x07, 0x07, 0x4e, 0x38, 0xe0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					// 0x00, 0xc3, 0x7f, 0x03, 0x01, 0xe3, 0x1e, 0x00, 0xc1, 0x69, 0x34, 0x02, 0x02, 0x04, 0x00, 0x00, 
					// 0x08, 0x08, 0x09, 0x3c, 0xc2, 0x03, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					// 0x00, 0x07, 0x1c, 0x30, 0x60, 0x41, 0x43, 0x5e, 0x71, 0x60, 0xc0, 0x80, 0x8c, 0x98, 0xe0, 0x80, 
					// 0x80, 0x8f, 0xf0, 0x80, 0xc7, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
				},

					/* 'cat_meow_2', 32x24px */
				{
					0x00, 0x00, 0xc0, 0xe0, 0xe0, 0xe0, 0xc0, 0x20, 0x20, 0x2f, 0xbb, 0x93, 0x1e, 0x0c, 0x04, 0x44, 
					0x04, 0x07, 0x07, 0x4e, 0x38, 0xe0, 0x80, 0x80, 0x08, 0x04, 0x40, 0x40, 0x20, 0x00, 0x00, 0x00, 
					// 0x00, 0xff, 0x03, 0x01, 0x01, 0xff, 0x03, 0x00, 0xc1, 0x69, 0x34, 0x02, 0x06, 0x04, 0x00, 0x08, 
					// 0x10, 0x0c, 0x15, 0x38, 0xcc, 0x07, 0x08, 0x88, 0x00, 0x00, 0x22, 0x42, 0x02, 0x04, 0x00, 0x00, 
					// 0x00, 0x07, 0x1c, 0x30, 0x60, 0x41, 0x43, 0x5e, 0x71, 0x60, 0xc0, 0x80, 0x8c, 0x98, 0xe0, 0x80, 
					// 0x80, 0x8f, 0xf0, 0x80, 0xc7, 0x78, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
				}
			};
			
			/* Bark 2 */
			static const char PROGMEM bark2[2][ANIM_SIZE] = {
					/* 'cat_meow_1', 32x24px */
				{
					// 0x00, 0xc0, 0xe0, 0xe0, 0xc0, 0x80, 0x00, 0x20, 0x20, 0x2f, 0xbb, 0x93, 0x1e, 0x0c, 0x04, 0x44, 
					// 0x04, 0x07, 0x07, 0x4e, 0x38, 0xe0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					0x00, 0xc3, 0x7f, 0x03, 0x01, 0xe3, 0x1e, 0x00, 0xc1, 0x69, 0x34, 0x02, 0x02, 0x04, 0x00, 0x00, 
					0x08, 0x08, 0x09, 0x3c, 0xc2, 0x03, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					// 0x00, 0x07, 0x1c, 0x30, 0x60, 0x41, 0x43, 0x5e, 0x71, 0x60, 0xc0, 0x80, 0x8c, 0x98, 0xe0, 0x80, 
					// 0x80, 0x8f, 0xf0, 0x80, 0xc7, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
				},

					/* 'cat_meow_2', 32x24px */
				{
					// 0x00, 0x00, 0xc0, 0xe0, 0xe0, 0xe0, 0xc0, 0x20, 0x20, 0x2f, 0xbb, 0x93, 0x1e, 0x0c, 0x04, 0x44, 
					// 0x04, 0x07, 0x07, 0x4e, 0x38, 0xe0, 0x80, 0x80, 0x08, 0x04, 0x40, 0x40, 0x20, 0x00, 0x00, 0x00, 
					0x00, 0xff, 0x03, 0x01, 0x01, 0xff, 0x03, 0x00, 0xc1, 0x69, 0x34, 0x02, 0x06, 0x04, 0x00, 0x08, 
					0x10, 0x0c, 0x15, 0x38, 0xcc, 0x07, 0x08, 0x88, 0x00, 0x00, 0x22, 0x42, 0x02, 0x04, 0x00, 0x00, 
					// 0x00, 0x07, 0x1c, 0x30, 0x60, 0x41, 0x43, 0x5e, 0x71, 0x60, 0xc0, 0x80, 0x8c, 0x98, 0xe0, 0x80, 
					// 0x80, 0x8f, 0xf0, 0x80, 0xc7, 0x78, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
				}
			};
			
			/* Bark 3 */
			static const char PROGMEM bark3[2][ANIM_SIZE] = {
					/* 'cat_meow_1', 32x24px */
				{
					// 0x00, 0xc0, 0xe0, 0xe0, 0xc0, 0x80, 0x00, 0x20, 0x20, 0x2f, 0xbb, 0x93, 0x1e, 0x0c, 0x04, 0x44, 
					// 0x04, 0x07, 0x07, 0x4e, 0x38, 0xe0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					// 0x00, 0xc3, 0x7f, 0x03, 0x01, 0xe3, 0x1e, 0x00, 0xc1, 0x69, 0x34, 0x02, 0x02, 0x04, 0x00, 0x00, 
					// 0x08, 0x08, 0x09, 0x3c, 0xc2, 0x03, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					0x00, 0x07, 0x1c, 0x30, 0x60, 0x41, 0x43, 0x5e, 0x71, 0x60, 0xc0, 0x80, 0x8c, 0x98, 0xe0, 0x80, 
					0x80, 0x8f, 0xf0, 0x80, 0xc7, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
				},

					/* 'cat_meow_2', 32x24px */
				{
					// 0x00, 0x00, 0xc0, 0xe0, 0xe0, 0xe0, 0xc0, 0x20, 0x20, 0x2f, 0xbb, 0x93, 0x1e, 0x0c, 0x04, 0x44, 
					// 0x04, 0x07, 0x07, 0x4e, 0x38, 0xe0, 0x80, 0x80, 0x08, 0x04, 0x40, 0x40, 0x20, 0x00, 0x00, 0x00, 
					// 0x00, 0xff, 0x03, 0x01, 0x01, 0xff, 0x03, 0x00, 0xc1, 0x69, 0x34, 0x02, 0x06, 0x04, 0x00, 0x08, 
					// 0x10, 0x0c, 0x15, 0x38, 0xcc, 0x07, 0x08, 0x88, 0x00, 0x00, 0x22, 0x42, 0x02, 0x04, 0x00, 0x00, 
					0x00, 0x07, 0x1c, 0x30, 0x60, 0x41, 0x43, 0x5e, 0x71, 0x60, 0xc0, 0x80, 0x8c, 0x98, 0xe0, 0x80, 
					0x80, 0x8f, 0xf0, 0x80, 0xc7, 0x78, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
				}
			};

			/* Sneak 1 */
			static const char PROGMEM sneak1[2][ANIM_SIZE] = {
					/* 'cat_sneak_1', 32x24px */
				{
					0xfe, 0x0f, 0x0f, 0x1f, 0x7e, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 
					0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					// 0x01, 0x03, 0x86, 0xcc, 0x78, 0x10, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x42, 0x43, 
					// 0x23, 0x2d, 0xa9, 0x87, 0x07, 0x03, 0x11, 0x01, 0x01, 0x41, 0x13, 0x8e, 0xf8, 0x20, 0x20, 0x00, 
					// 0x00, 0x3c, 0x63, 0x40, 0x40, 0x30, 0x18, 0x0c, 0x04, 0x04, 0x06, 0x0e, 0x1e, 0x3e, 0x3e, 0x34, 
					// 0x1d, 0x3d, 0x3c, 0x3c, 0x19, 0x10, 0x20, 0x42, 0x42, 0x46, 0x49, 0x30, 0x00, 0x01, 0x01, 0x00,
				},

					/* 'cat_sneak_2', 32x24px */
				{
					0xfc, 0x9e, 0x1e, 0x1e, 0x3c, 0x60, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
					// 0x00, 0x03, 0x06, 0x0c, 0x18, 0xf0, 0x80, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x42, 
					// 0x43, 0x27, 0x2d, 0xa9, 0x87, 0x07, 0x03, 0x11, 0x01, 0x01, 0x41, 0x13, 0x8e, 0xf8, 0x20, 0x20, 
					// 0x00, 0x00, 0x1c, 0x3e, 0x3f, 0x3f, 0x1f, 0x0f, 0x0e, 0x1c, 0x10, 0x20, 0x60, 0x41, 0x46, 0x7c, 
					// 0x46, 0x41, 0x41, 0x40, 0x30, 0x19, 0x1c, 0x3c, 0x3e, 0x3e, 0x1a, 0x01, 0x00, 0x00, 0x01, 0x01,
				}
			};
			
			/* Sneak 2 */
			static const char PROGMEM sneak2[2][ANIM_SIZE] = {
					/* 'cat_sneak_1', 32x24px */
				{
					// 0xfe, 0x0f, 0x0f, 0x1f, 0x7e, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 
					// 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					0x01, 0x03, 0x86, 0xcc, 0x78, 0x10, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x42, 0x43, 
					0x23, 0x2d, 0xa9, 0x87, 0x07, 0x03, 0x11, 0x01, 0x01, 0x41, 0x13, 0x8e, 0xf8, 0x20, 0x20, 0x00, 
					// 0x00, 0x3c, 0x63, 0x40, 0x40, 0x30, 0x18, 0x0c, 0x04, 0x04, 0x06, 0x0e, 0x1e, 0x3e, 0x3e, 0x34, 
					// 0x1d, 0x3d, 0x3c, 0x3c, 0x19, 0x10, 0x20, 0x42, 0x42, 0x46, 0x49, 0x30, 0x00, 0x01, 0x01, 0x00,
				},

					/* 'cat_sneak_2', 32x24px */
				{
					// 0xfc, 0x9e, 0x1e, 0x1e, 0x3c, 0x60, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					// 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
					0x00, 0x03, 0x06, 0x0c, 0x18, 0xf0, 0x80, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x42, 
					0x43, 0x27, 0x2d, 0xa9, 0x87, 0x07, 0x03, 0x11, 0x01, 0x01, 0x41, 0x13, 0x8e, 0xf8, 0x20, 0x20, 
					// 0x00, 0x00, 0x1c, 0x3e, 0x3f, 0x3f, 0x1f, 0x0f, 0x0e, 0x1c, 0x10, 0x20, 0x60, 0x41, 0x46, 0x7c, 
					// 0x46, 0x41, 0x41, 0x40, 0x30, 0x19, 0x1c, 0x3c, 0x3e, 0x3e, 0x1a, 0x01, 0x00, 0x00, 0x01, 0x01,
				}
			};
			
			/* Sneak 3 */
			static const char PROGMEM sneak3[2][ANIM_SIZE] = {
					/* 'cat_sneak_1', 32x24px */
				{
					// 0xfe, 0x0f, 0x0f, 0x1f, 0x7e, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 
					// 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					// 0x01, 0x03, 0x86, 0xcc, 0x78, 0x10, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x42, 0x43, 
					// 0x23, 0x2d, 0xa9, 0x87, 0x07, 0x03, 0x11, 0x01, 0x01, 0x41, 0x13, 0x8e, 0xf8, 0x20, 0x20, 0x00, 
					0x00, 0x3c, 0x63, 0x40, 0x40, 0x30, 0x18, 0x0c, 0x04, 0x04, 0x06, 0x0e, 0x1e, 0x3e, 0x3e, 0x34, 
					0x1d, 0x3d, 0x3c, 0x3c, 0x19, 0x10, 0x20, 0x42, 0x42, 0x46, 0x49, 0x30, 0x00, 0x01, 0x01, 0x00,
				},

					/* 'cat_sneak_2', 32x24px */
				{
					// 0xfc, 0x9e, 0x1e, 0x1e, 0x3c, 0x60, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					// 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
					// 0x00, 0x03, 0x06, 0x0c, 0x18, 0xf0, 0x80, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x42, 
					// 0x43, 0x27, 0x2d, 0xa9, 0x87, 0x07, 0x03, 0x11, 0x01, 0x01, 0x41, 0x13, 0x8e, 0xf8, 0x20, 0x20, 
					0x00, 0x00, 0x1c, 0x3e, 0x3f, 0x3f, 0x1f, 0x0f, 0x0e, 0x1c, 0x10, 0x20, 0x60, 0x41, 0x46, 0x7c, 
					0x46, 0x41, 0x41, 0x40, 0x30, 0x19, 0x1c, 0x3c, 0x3e, 0x3e, 0x1a, 0x01, 0x00, 0x00, 0x01, 0x01,
				}
			};

			/* animation */
			void animate_luna(void) {
				/* jump */
				if (isJumping || !showedJump) {
					/* clear */
					oled_set_cursor(LUNA_X, LUNA_Y + 2);
					oled_write("     ", false);

					oled_set_cursor(LUNA_X, LUNA_Y - 1);

					showedJump = true;
				} else {
					/* clear */
					oled_set_cursor(LUNA_X, LUNA_Y - 1);
					oled_write("     ", false);

					oled_set_cursor(LUNA_X, LUNA_Y);
				}

				/* switch frame */
				current_frame = (current_frame + 1) % 2;

				/* current status */
				if (led_usb_state.caps_lock) {
					oled_write_raw_P(bark1[current_frame], ANIM_SIZE);
					oled_set_cursor(LUNA_X, LUNA_Y + 1);
					oled_write_raw_P(bark2[current_frame], ANIM_SIZE);
					oled_set_cursor(LUNA_X, LUNA_Y + 2);
					oled_write_raw_P(bark3[current_frame], ANIM_SIZE);
					oled_set_cursor(LUNA_X, LUNA_Y);

				} else if (isSneaking) {
					oled_write_raw_P(sneak1[current_frame], ANIM_SIZE);
					oled_set_cursor(LUNA_X, LUNA_Y + 1);
					oled_write_raw_P(sneak2[current_frame], ANIM_SIZE);
					oled_set_cursor(LUNA_X, LUNA_Y + 2);
					oled_write_raw_P(sneak3[current_frame], ANIM_SIZE);
					oled_set_cursor(LUNA_X, LUNA_Y);

				} else if (current_wpm <= MIN_WALK_SPEED) {
					oled_write_raw_P(sit1[current_frame], ANIM_SIZE);
					oled_set_cursor(LUNA_X, LUNA_Y + 1);
					oled_write_raw_P(sit2[current_frame], ANIM_SIZE);
					oled_set_cursor(LUNA_X, LUNA_Y + 2);
					oled_write_raw_P(sit3[current_frame], ANIM_SIZE);
					oled_set_cursor(LUNA_X, LUNA_Y);
										
				} else if (current_wpm <= MIN_RUN_SPEED) {
					oled_write_raw_P(walk1[current_frame], ANIM_SIZE);
					oled_set_cursor(LUNA_X, LUNA_Y + 1);
					oled_write_raw_P(walk2[current_frame], ANIM_SIZE);
					oled_set_cursor(LUNA_X, LUNA_Y + 2);
					oled_write_raw_P(walk3[current_frame], ANIM_SIZE);
					oled_set_cursor(LUNA_X, LUNA_Y);

				} else {
					oled_write_raw_P(run1[current_frame], ANIM_SIZE);
					oled_set_cursor(LUNA_X, LUNA_Y + 1);
					oled_write_raw_P(run2[current_frame], ANIM_SIZE);
					oled_set_cursor(LUNA_X, LUNA_Y + 2);
					oled_write_raw_P(run3[current_frame], ANIM_SIZE);
					oled_set_cursor(LUNA_X, LUNA_Y);
				}
			}

		#    if OLED_TIMEOUT > 0
			/* the animation prevents the normal timeout from occuring */
			if (last_input_activity_elapsed() > OLED_TIMEOUT && last_led_activity_elapsed() > OLED_TIMEOUT) {
				oled_off();
				return;
			} else {
				oled_on();
			}
		#    endif

			/* animation timer */
			if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
				anim_timer = timer_read32();
				animate_luna();
			}
		}

/* KEYBOARD PET END */

/* OLED SCREEN START */

// static const char PROGMEM republic_logo[] = {
        // 0x80, 0x81, 0x82, 0x83, 0x84, 0x00,
        // 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0x00,
        // 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0x00,
		// 0x85, 0x86, 0x87, 0x88, 0x89, 0x00,
    // };
	
	static const char PROGMEM republic_logo1[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x00};
	static const char PROGMEM republic_logo2[] = {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0x00};
	static const char PROGMEM republic_logo3[] = {0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0x00};
	static const char PROGMEM republic_logo4[] = {0x85, 0x86, 0x87, 0x88, 0x89, 0x00};
	
oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    return OLED_ROTATION_180;       // flips the display 180 degrees
	}

bool oled_task_user(void) {
	
    /* KEYBOARD PET VARIABLES START */

    current_wpm   = get_current_wpm();
    led_usb_state = host_keyboard_led_state();

    /* KEYBOARD PET VARIABLES END */	

	/* KEYBOARD PET RENDER START */

    render_luna(0, 1);

    /* KEYBOARD PET RENDER END */

	oled_set_cursor(13,0);
    oled_write_P(republic_logo1, false);
	oled_set_cursor(13,1);
	oled_write_P(republic_logo2, false);
	oled_set_cursor(13,2);
	oled_write_P(republic_logo3, false);
	oled_set_cursor(13,3);
	oled_write_P(republic_logo4, false);
	
	oled_set_cursor(6,0);
	oled_write_P(PSTR("V.010"), false);
	
	oled_set_cursor(6,1);
    // Host Keyboard Layer Status
    // oled_write_P(PSTR("Layer"), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("BASE\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("ONE\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("TWO\n"), false);
            break;
		case 3:
			oled_write_P(PSTR("THREE\n"), false);
			break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("UNDEF"), false);
    }

	// oled_set_cursor(0,2);
    // Host Keyboard LED Status
    // led_t led_state = host_keyboard_led_state();
    // oled_write_P(led_state.num_lock ? PSTR("NUM\n") : PSTR("\n"), false);
    // oled_write_P(led_state.caps_lock ? PSTR("CAP\n") : PSTR("\n"), false);
    // oled_write_P(led_state.scroll_lock ? PSTR(" SCR\n") : PSTR("\n"), false);
		
    
	/* wpm counter */
		uint8_t n = get_current_wpm();
		char    wpm_str[4];
		oled_set_cursor(4, 6);
		wpm_str[3] = '\0';
		wpm_str[2] = '0' + n % 10;
		wpm_str[1] = '0' + (n /= 10) % 10;
		wpm_str[0] = '0' + n / 10;
		oled_write(wpm_str, false);

		oled_set_cursor(0, 6);
		oled_write("wpm", false);
	
    return false;
}

/* OLED SCREEN END */

#endif

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
