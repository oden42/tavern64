#include "quantum.h"
#include "oled_assets.h"
#include <stdio.h>

#ifdef OLED_ENABLE

// Defines for displaying each song name. Must match what is set in the keymap.c
#define SONG1_NAME "Portal Chime"
#define SONG2_NAME "X-Men Theme"
#define SONG3_NAME "Everquest Theme"
#define SONG4_NAME "Megalovania"
#define SONG5_NAME "Imperial March"
#define SONG6_NAME "Mario Coin"
#define SONG7_NAME "FF Prelude"
#define SONG8_NAME "Zelda Puzzle"
#define SONG9_NAME "Mario 1up"
#define SONG10_NAME "Mario Mushroom"
#define SONG11_NAME "Terras Theme"
#define SONG12_NAME "Rick Roll"
#define SONG13_NAME "Kirby Greens"
#define SONG14_NAME "Old Spice"
#define SONG15_NAME "Disney Song"
#define SONG16_NAME "Totoro"
#define SONG17_NAME "Danger Zone"
#define SONG18_NAME "Sonic Ring"
#define SONG19_NAME "Zelda Treasure"
#define SONG20_NAME "Mario Theme"
#define SONG21_NAME "Mario Game Over"
#define SONG22_NAME "E1M1 Doom"
#define SONG23_NAME "Campanella"
#define SONG24_NAME "Zelda Fairy WIP"

int   current_wpm = 0;						// Current wpm status variable
led_t led_usb_state;						// USB state status variable
static uint32_t oled_splash_timer = 0;		// Splash Screen
static bool clear_splash = true;			// Splash Screen
static bool oled_dim = false;				// Splash Screen
// static int splash_phrase = 0;				// Splash Screen Phrase
// static bool clear_phrase = true;			// Splash Screen Phrase
bool isCtrl = false;						// For animations

// // Splash Screen Phrase
// static void render_phrase(void) {
// 	oled_set_cursor(0,5);
// 	// Each phrase can be a max of 20 chars per line
// 	// This is 20: "                    "
// 	switch (splash_phrase) {
// 		case 1:
// 			oled_write_P(PSTR("      Now with\n"), false);
// 			oled_write_P(PSTR("    more pixels!    "), false);
// 			break;
// 		case 2:
// 			oled_write_P(PSTR("       Cheers!      "), false);
// 			break;
// 		case 3:
// 			oled_write_P(PSTR("   Let's Goooooo!   "), false);
// 			break;
// 		case 4:
// 			oled_write_P(PSTR(" Handmade with love\n"), false);
// 			oled_write_P(PSTR("  by Jacob Thompson "), false);
// 			break;
// 		case 5:
// 			oled_write_P(PSTR("  Now I have a cat! "), false);
// 			break;
// 		case 6:
// 			oled_write_P(PSTR("  I'm a scary and\n"), false);
// 			oled_write_P(PSTR("powerful fire demon!"), false);
// 			break;
// 		case 7:
// 			oled_write_P(PSTR("    No on else\n"), false);
// 			oled_write_P(PSTR("   does any work\n"), false);
// 			oled_write_P(PSTR("    around here.   "), false);
// 			break;
// 		case 8:
// 			oled_write_P(PSTR("   Demons don't\n"), false);
// 			oled_write_P(PSTR("   make promises.   "), false);
// 			break;
// 		case 9:
// 			oled_write_P(PSTR("     She likes\n"), false);
// 			oled_write_P(PSTR("     my spark!!     "), false);
// 			break;
// 		case 10:
// 			oled_write_P(PSTR(" Fine, like moving\n"), false);
// 			oled_write_P(PSTR("  the castle isn't\n"), false);
// 			oled_write_P(PSTR("    hard enough!    "), false);
// 			break;
// 		case 11:
// 			oled_write_P(PSTR("        Thocc       "), false);
// 			break;
// 		case 12:
// 			oled_write_P(PSTR(" click clack goes "), false);
// 			break;
// 		case 13:
// 			oled_write_P(PSTR("     That's one\n"), false);
// 			oled_write_P(PSTR(" fucking nice kitty\n"), false);
// 			oled_write_P(PSTR("    right there.    "), false);
// 			break;
// 		case 14:
// 			oled_write_P(PSTR("      Atodaso.      "), false);

// 			break;
// 		case 15:
// 			oled_write_P(PSTR("   Get two birds    "), false);
// 			oled_write_P(PSTR("   stoned at once   "), false);
// 			break;
// 		default:
// 			oled_write_P(PSTR("Missing Phrase Data!"), false);
// 			break;
// 	}
// }

// Splash Screen
static void render_splash(void) {

    oled_write_raw_P(splash, sizeof(splash));
	// if (clear_phrase) {
	// 	splash_phrase = rand() % 15;
	// 	// splash_phrase = splash_phrase + 1;
	// 	clear_phrase = false;
	// } 
	// render_phrase();
}

// Clear Splash Screen
void clear_screen(void) {
    if (clear_splash){
      for (uint8_t i = 0; i < OLED_DISPLAY_HEIGHT; ++i) {
        for (uint8_t j = 0; j < OLED_DISPLAY_WIDTH; ++j) {
          oled_write_raw_byte(0x0, i*OLED_DISPLAY_WIDTH + j);
        }
      }
	  // clear_phrase = true;
      clear_splash = false;
    }
}

// Splash Screen: Create the function for the timer
void init_timer(void){
   oled_splash_timer = timer_read32();
};

// Splash Screen: Run the Initialize timer function when the keyboard starts
void keyboard_post_init_kb(void) {
    init_timer();

    keyboard_post_init_user();
}

// Render the Tavern64 logo with layer wings below it
void render_tavern_logo(int col, int line) {
	oled_set_cursor(col, line);
	oled_write_raw_P(tavern_logo_top, sizeof(tavern_logo_top));
	oled_set_cursor(col, line + 1);	
	oled_write_raw_P(tavern_logo_bottom, sizeof(tavern_logo_bottom));	

	oled_set_cursor(col, line + 2);
	oled_write_P(wing_left, false);	
	oled_set_cursor(col + 10, line + 2);
	oled_write_P(wing_right, false);	
}

// Write Words Per Minute in 3 digits
void wpm_counter(int col, int line){
	/* wpm counter */
		uint8_t n = get_current_wpm();
		char    wpm_str[4];
		oled_set_cursor(col, line);
		wpm_str[3] = '\0';
		wpm_str[2] = '0' + n % 10;
		wpm_str[1] = '0' + (n /= 10) % 10;
		wpm_str[0] = '0' + n / 10;
		oled_write(wpm_str, false);
}

// Render a miniature Tavern64 and display active keypresses
static void print_matrix(int MATRIX_DISPLAY_X, int MATRIX_DISPLAY_Y){
	oled_set_cursor(12,4);
	oled_write_P(keyboard_icon, false);	

	for (uint8_t x = 0; x < MATRIX_ROWS; x++) {
		for (uint8_t y = 0; y < MATRIX_COLS; y++) {
			if (x >= 5){
				oled_write_pixel(MATRIX_DISPLAY_X - y + 14, MATRIX_DISPLAY_Y + x - 3,(matrix_get_row(x) & (1 << y))> 0);
			}
			else{
				oled_write_pixel(MATRIX_DISPLAY_X + y + 2, MATRIX_DISPLAY_Y + x + 2,(matrix_get_row(x) & (1 << y))> 0);
			}
		}
	}

	// This creates a line under the keyboard
	for (uint8_t x = 0; x < 17; x++) {
		oled_write_pixel(MATRIX_DISPLAY_X + x, MATRIX_DISPLAY_Y + 9,true);
	}
}

// Render a bar that fills up with WPM
void wpm_bar(void){
    current_wpm   = get_current_wpm();
	
	oled_set_cursor(0,6);
	oled_write_P(wpm_meter, false);	

	for (uint8_t y = 51; y < 53; y++) { 
		for (uint8_t x = 2; x < 120; x++) {
			if(current_wpm > x){
				oled_write_pixel(x, y,true);
			}
			else{
				oled_write_pixel(x, y,false);
			}
		}
	}
}

/* Animation Code Start */ 
	// Music Animation Code
	static uint8_t musicbox_frame = 0;
	static uint8_t m_anim_type  = 0;
	uint32_t m_anim_timer = 0;	// Timer
	#define MUSICBOX_FRAME_DURATION 200  // how long each frame lasts in ms

	void render_musicbox(uint8_t col, uint8_t line){
		for (uint8_t i = 0; i < 6; i++) {	// Run this code for each row
			oled_set_cursor(col, line + i);
			oled_write_raw_P(musicbox[m_anim_type][musicbox_frame][i], MUSICBOX_ANIM_SIZE);
		}

		void animate_musicbox(void){
			/* switch frame */
			musicbox_frame = (musicbox_frame + 1) % MUSICBOX_ANIM_FRAMES;
		}

		/* animation timer */
		if (timer_elapsed32(m_anim_timer) > MUSICBOX_FRAME_DURATION) {
			m_anim_timer = timer_read32();
			animate_musicbox();
		}
	}

	// Calcifer Animation Code
	static uint8_t calcifer_frame = 0;
	uint32_t c_anim_timer = 0;	// Timer
	static uint8_t c_anim_type  = 0;
	#define CALC_MIN_WALK_SPEED      10
	#define CALC_MIN_RUN_SPEED       80
	#define CALCIFER_FRAME_DURATION 150  // how long each frame lasts in ms

	void render_calcifer(uint8_t col, uint8_t line){
		for (uint8_t i = 0; i < 6; i++) {
			oled_set_cursor(col, line + i);
			oled_write_raw_P(calcifer[c_anim_type][calcifer_frame][i], CALCIFER_ANIM_SIZE);
		}

		void animate_calcifer(void){
			/* switch frame */
			calcifer_frame = (calcifer_frame + 1) % CALCIFER_ANIM_FRAMES;

			/* current status */
			if (isCtrl) {		// Hiding Animation
				c_anim_type = 3;
			} else if (current_wpm <= CALC_MIN_WALK_SPEED) {	// Idle Animation
				c_anim_type = 0;
			} else if (current_wpm <= CALC_MIN_RUN_SPEED) {		// Walk Animation
				c_anim_type = 1;
			} else {	// Run Animation
				c_anim_type = 2;
			}
		}

		/* animation timer */
		if (timer_elapsed32(c_anim_timer) > CALCIFER_FRAME_DURATION) {
			c_anim_timer = timer_read32();
			animate_calcifer();
		}
	}

	// Neencat Animation Code
	static uint8_t neencat_frame = 0;
	uint32_t n_anim_timer = 0;	// Timer
	static uint8_t n_anim_type  = 0;

	//bool isJumping  = false;
	//bool showedJump = true;
	//int jumpOffset = 0;

	#define NEENCAT_MIN_WALK_SPEED      10
	#define NEENCAT_MIN_WALK_FAST_SPEED 40
	#define NEENCAT_MIN_RUN_SPEED       70
	#define NEENCAT_MIN_RUN_FAST_SPEED  100
	#define NEENCAT_MIN_RUN_SUPER_SPEED  120
	static int neencat_frame_duration = 300;

	void render_neencat(uint8_t col, uint8_t line){
		for (uint8_t i = 0; i < 6; i++) {
			oled_set_cursor(col, line + i);
			oled_write_raw_P(neencat[n_anim_type][neencat_frame][i], NEENCAT_ANIM_SIZE);
		}

		void animate_neencat(void){
			/* switch frame */
			neencat_frame = (neencat_frame + 1) % NEENCAT_ANIM_FRAMES;

			/* current status */
			if (led_usb_state.caps_lock) {	// Meowing Animation
				n_anim_type = 4;
				neencat_frame_duration = 300;
			} else if (isCtrl) {		// Sneaking Animation
				n_anim_type = 3;
				neencat_frame_duration = 300;
			} else if (current_wpm <= NEENCAT_MIN_WALK_SPEED) {	// Sleep Animation
				n_anim_type = 0;
				neencat_frame_duration = 300;
			} else if (current_wpm <= NEENCAT_MIN_WALK_FAST_SPEED) {	// Walk Animation
				n_anim_type = 1;
				neencat_frame_duration = 300;
			} else if (current_wpm <= NEENCAT_MIN_RUN_SPEED) {		// Walk Fast Animation
				n_anim_type = 1;
				neencat_frame_duration = 200;
			} else if (current_wpm <= NEENCAT_MIN_RUN_FAST_SPEED) {		// Run Animation
				n_anim_type = 2;
				neencat_frame_duration = 300;
			} else if (current_wpm <= NEENCAT_MIN_RUN_SUPER_SPEED) {		// Run Fast Animation
				n_anim_type = 2;
				neencat_frame_duration = 200;
			} else {	// Run Super Fast Animation
				n_anim_type = 2;
				neencat_frame_duration = 100;
			}
		}

		/* animation timer */
		if (timer_elapsed32(n_anim_timer) > neencat_frame_duration) {
			n_anim_timer = timer_read32();
			animate_neencat();
		}
	}
/* Animation Code End */ 

// Test Info code
void test_info(void){
	oled_set_cursor(15,3);
    oled_write_P(PSTR("SP:"), false);
    oled_write(get_u8_str(rgb_matrix_get_speed(), ' '), false);

	oled_set_cursor(16,5);
	oled_write_P(PSTR("B:"), false);
	oled_write(get_u8_str(oled_get_brightness(), ' '), false);
}

// Modified render HSV code from drashna
void render_rgb_hsv(uint8_t col, uint8_t line) {
#ifdef RGB_MATRIX_ENABLE
    oled_set_cursor(col, line);
    oled_write_P(PSTR("H:"), false);
    oled_write(get_u8_str(rgb_matrix_get_hue(), ' '), false);
	oled_set_cursor(col, line + 1);
    oled_write_P(PSTR("S:"), false);
    oled_write(get_u8_str(rgb_matrix_get_sat(), ' '), false);
	oled_set_cursor(col, line + 2);
    oled_write_P(PSTR("V:"), false);
    oled_write(get_u8_str(rgb_matrix_get_val(), ' '), false);
// #elif RGBLIGHT_ENABLE
//     if (is_rgblight_startup_running()) {
//         oled_write_P(PSTR("Start Animation"), false);
//     } else {
//         oled_write(get_u8_str(rgblight_get_hue(), ' '), false);
//         oled_write_P(PSTR(","), false);
//         oled_write(get_u8_str(rgblight_get_sat(), ' '), false);
//         oled_write_P(PSTR(","), false);
//         oled_write(get_u8_str(rgblight_get_val(), ' '), false);
//     }
#endif
}

// Toggle OLED brightness
static void oled_brightness_toggle(void){
	if (oled_dim){
		oled_dim = false;
		oled_set_brightness(255);
	} else {
		oled_dim = true;
		oled_set_brightness(10);
	}
}

#define SONG_TIMEOUT 2000
uint32_t song_timer = 0;
static int song_played = 0;
static bool song_display = false;

// Display song name at the bottom of the screen for a short period of time
static void oled_display_song(void){
	void display_song(void){
		switch (song_played) {
			case 1:
				oled_write_P(PSTR(SONG1_NAME), false);
				break;
			case 2:
				oled_write_P(PSTR(SONG2_NAME), false);
				break;
			case 3:
				oled_write_P(PSTR(SONG3_NAME), false);
				break;
			case 4:
				oled_write_P(PSTR(SONG4_NAME), false);
				break;
			case 5:
				oled_write_P(PSTR(SONG5_NAME), false);
				break;
			case 6:
				oled_write_P(PSTR(SONG6_NAME), false);
				break;
			case 7:
				oled_write_P(PSTR(SONG7_NAME), false);
				break;
			case 8:
				oled_write_P(PSTR(SONG8_NAME), false);
				break;
			case 9:
				oled_write_P(PSTR(SONG9_NAME), false);
				break;
			case 10:
				oled_write_P(PSTR(SONG10_NAME), false);
				break;
			case 11:
				oled_write_P(PSTR(SONG11_NAME), false);
				break;
			case 12:
				oled_write_P(PSTR(SONG12_NAME), false);
				break;
			case 13:
				oled_write_P(PSTR(SONG13_NAME), false);
				break;
			case 14:
				oled_write_P(PSTR(SONG14_NAME), false);
				break;
			case 15:
				oled_write_P(PSTR(SONG15_NAME), false);
				break;
			case 16:
				oled_write_P(PSTR(SONG16_NAME), false);
				break;
			case 17:
				oled_write_P(PSTR(SONG17_NAME), false);
				break;
			case 18:
				oled_write_P(PSTR(SONG18_NAME), false);
				break;
			case 19:
				oled_write_P(PSTR(SONG19_NAME), false);
				break;
			case 20:
				oled_write_P(PSTR(SONG20_NAME), false);
				break;
			case 21:
				oled_write_P(PSTR(SONG21_NAME), false);
				break;
			case 22:
				oled_write_P(PSTR(SONG22_NAME), false);
				break;
			case 23:
				oled_write_P(PSTR(SONG23_NAME), false);
				break;
			case 24:
				oled_write_P(PSTR(SONG24_NAME), false);
				break;																							
			default:
				oled_write_P(PSTR("Unknown"), false);
				break;
		}
	}

	oled_set_cursor(0,7);
		if (song_display){
			if (song_timer && timer_expired(timer_read(), song_timer)) {
				oled_set_cursor(0,7);
				oled_advance_page(true);
				song_display = false;
			} else {
				oled_set_cursor(0,7);
				oled_advance_page(true);
				oled_set_cursor(0,7);
				display_song();
			}
		}
}

// Render OLED function. Use this instead of oled_task_user
static void render_oled(void) {
    current_wpm   = get_current_wpm();		// Used for the wpm counter
    led_usb_state = host_keyboard_led_state();	// Used by the keyboard pet to find the caps lock state
    //led_t led_state = host_keyboard_led_state();

	// Code to turn off OLED after the timeout, since animations break the default timeout code
	#if OLED_TIMEOUT > 0
	if (last_input_activity_elapsed() > OLED_TIMEOUT && last_led_activity_elapsed() > OLED_TIMEOUT) {
		oled_off();
			return;
		} else {
			oled_on();
		}
	#endif

	render_tavern_logo(8,0);

	// clear lines first
		oled_set_cursor(8,3);
		oled_advance_page(true);
		oled_set_cursor(8,4);
		oled_advance_page(true);
		oled_set_cursor(8,5);
		oled_advance_page(true);

	wpm_counter(9,4);
	print_matrix(78,31);

	// 	Host Keyboard LED Status
		oled_set_cursor(17,4);
		oled_write_P(led_usb_state.caps_lock ? caps_lock_on : caps_lock_off, false);
		oled_set_cursor(19,4);
		oled_write_P(led_usb_state.num_lock ? num_lock_on : num_lock_off, false);

	wpm_bar();

	// // TEST INFO
	// oled_set_cursor(16,7);
	// oled_write(get_u16_str(splash_phrase, ' '), false);
	// 	oled_write_P(PSTR("I: "), false);
	// 	oled_write(get_u16_str(last_input_activity_elapsed(), ' '), false);
	// 	oled_set_cursor(12,7);
	// 	oled_write_P(PSTR("L: "), false);
	// 	oled_write(get_u16_str(last_led_activity_elapsed(), ' '), false);

    // Host Keyboard Layer Status
    switch (get_highest_layer(layer_state)) {
        case 0:
			render_calcifer(0,0);
			oled_set_cursor(11,2);
            oled_write_P(PSTR("PRIMARY"), false);
			// Clear bottom line
			oled_set_cursor(0,7);
			oled_advance_page(true);
            break;
        case 1:
			render_neencat(0,0);
			oled_set_cursor(11,2);
            oled_write_P(PSTR(" WORK  "), false);
			// Clear bottom line
			oled_set_cursor(0,7);
			oled_advance_page(true);
            break;
        case 2:
			render_calcifer(0,0);
			oled_set_cursor(11,2);
            oled_write_P(PSTR(" GAMES "), false);
			// Clear bottom line
			oled_set_cursor(0,7);
			oled_advance_page(true);
            break;
		case 3:
			m_anim_type  = 0;
			render_musicbox(0,0);
			oled_set_cursor(11,2);
			oled_write_P(PSTR(" MUSIC "), false);
			oled_display_song();
			break;
		case 4:
			m_anim_type  = 1;
			render_musicbox(0,0);
			oled_set_cursor(11,2);
			oled_write_P(PSTR(" PIANO "), false);
			// Clear bottom line
			oled_set_cursor(0,7);
			oled_advance_page(true);
			break;
		case 5:
			oled_set_cursor(11,2);
            oled_write_P(PSTR("FN/INFO"), false);
			// clear line first
				oled_set_cursor(8,3);
				oled_advance_page(true);
			// clear line first
				oled_set_cursor(8,4);
				oled_advance_page(true);
			// clear line first
				oled_set_cursor(8,5);
				oled_advance_page(true);
			test_info();
			render_rgb_hsv(9,3);
			// Clear bottom line
			oled_set_cursor(0,7);
			oled_advance_page(true);
			break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_set_cursor(11,2);
			oled_write_ln_P(PSTR("UNDEF"), false);
    }
}

#ifndef SHOW_SPLASH
#    define SHOW_SPLASH 3000
#endif
bool oled_task_kb(void) {
    if (!oled_task_user()) { return false; }
    if ((timer_elapsed32(oled_splash_timer) < SHOW_SPLASH)){
        render_splash();
    }else{
      clear_screen();
	  render_oled();
    }
    return false;
}

#endif