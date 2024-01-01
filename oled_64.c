#include "quantum.h"
#include "oled_assets.h"
#include <stdio.h>

#ifdef OLED_ENABLE


int   current_wpm = 0;						// Current wpm status variable
led_t led_usb_state;						// USB state status variable
static uint32_t oled_splash_timer = 0;		// Splash Screen
static bool clear_splash = true;			// Splash Screen
static uint8_t oled_brightness_val = 255;	// Splash Screen
bool isCtrl = false;						// For animations

// Splash Screen
static void render_splash(void) {
    oled_write_raw_P(splash, sizeof(splash));
	oled_set_cursor(5,5);
	oled_write_P(PSTR("Version 0.46"), false);
}

// Clear Splash Screen
void clear_screen(void) {
    if (clear_splash){
      for (uint8_t i = 0; i < OLED_DISPLAY_HEIGHT; ++i) {
        for (uint8_t j = 0; j < OLED_DISPLAY_WIDTH; ++j) {
          oled_write_raw_byte(0x0, i*OLED_DISPLAY_WIDTH + j);
        }
      }
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

// //Adjust brightness
// static void oled_brightness_up(int amount){
// 	if((oled_get_brightness() + amount) > 255){
// 		oled_brightness_val = 255;
// 	}
// 	else{
// 		oled_brightness_val = oled_brightness_val + amount;
// 	}
// }

// static void oled_brightness_down(int amount){
// 	if(amount > oled_get_brightness()){
// 		oled_brightness_val = 1;
// 	}
// 	else{
// 		oled_brightness_val = oled_brightness_val - amount;
// 	}
// }

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

	if(oled_brightness_val != oled_get_brightness()){
		oled_set_brightness(oled_brightness_val);
	}

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
	// 	oled_set_cursor(0,7);
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
            break;
        case 1:
			render_neencat(0,0);
			oled_set_cursor(11,2);
            oled_write_P(PSTR(" WORK  "), false);
            break;
        case 2:
			render_calcifer(0,0);
			oled_set_cursor(11,2);
            oled_write_P(PSTR(" GAMES "), false);
            break;
		case 3:
			m_anim_type  = 0;
			render_musicbox(0,0);
			oled_set_cursor(11,2);
			oled_write_P(PSTR(" MUSIC "), false);
			break;
		case 4:
			m_anim_type  = 1;
			render_musicbox(0,0);
			oled_set_cursor(11,2);
			oled_write_P(PSTR(" PIANO "), false);
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