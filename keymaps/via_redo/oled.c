#include "quantum.h"
#include "oled_assets.h"

#ifdef OLED_ENABLE

/* KEYBOARD PET START */
/* Keyboard Pet Settings */
//#define MIN_WALK_SPEED      10
//#define MIN_RUN_SPEED       60
//#define ANIM_FRAME_DURATION 400  // how long each frame lasts in ms

//uint32_t anim_timer = 0;	// Timer
//uint8_t current_frame = 0;	// Current frame

int   current_wpm = 0;		// Current wpm status variable
led_t led_usb_state;		// USB state status variable

bool isSneaking = false;
bool isJumping  = false;
bool showedJump = true;
int jumpOffset = 0;

/* Luna Logic */
// static void render_luna(int LUNA_X, int LUNA_Y) {
// 	/* animation */
// 	void animate_luna(void) {
// 		/* jump */
// 		if ((isJumping || !showedJump) && (current_wpm >= MIN_WALK_SPEED)) {
// 			/* clear */
// 			oled_set_cursor(LUNA_X, LUNA_Y + 2);
// 			oled_write("     ", false);

// 			oled_set_cursor(LUNA_X, LUNA_Y - 1);
// 			jumpOffset = -1;
// 			showedJump = true;
// 		} else {
// 			/* clear */
// 			oled_set_cursor(LUNA_X, LUNA_Y - 1);
// 			oled_write("     ", false);

// 			oled_set_cursor(LUNA_X, LUNA_Y);
// 			jumpOffset = 0;
// 		}

// 		/* switch frame */
// 		current_frame = (current_frame + 1) % 2;

// 		/* current status */
// 		if (led_usb_state.caps_lock) {
// 			oled_write_raw_P(bark1[current_frame], ANIM_SIZE);
// 			oled_set_cursor(LUNA_X, LUNA_Y + 1 + jumpOffset);
// 			oled_write_raw_P(bark2[current_frame], ANIM_SIZE);
// 			oled_set_cursor(LUNA_X, LUNA_Y + 2 + jumpOffset);
// 			oled_write_raw_P(bark3[current_frame], ANIM_SIZE);
// 			oled_set_cursor(LUNA_X, LUNA_Y);

// 		} else if (isSneaking) {
// 			oled_write_raw_P(sneak1[current_frame], ANIM_SIZE);
// 			oled_set_cursor(LUNA_X, LUNA_Y + 1 + jumpOffset);
// 			oled_write_raw_P(sneak2[current_frame], ANIM_SIZE);
// 			oled_set_cursor(LUNA_X, LUNA_Y + 2 + jumpOffset);
// 			oled_write_raw_P(sneak3[current_frame], ANIM_SIZE);
// 			oled_set_cursor(LUNA_X, LUNA_Y);

// 		} else if (current_wpm <= MIN_WALK_SPEED) {
// 			oled_write_raw_P(sit1[current_frame], ANIM_SIZE);
// 			oled_set_cursor(LUNA_X, LUNA_Y + 1 + jumpOffset);
// 			oled_write_raw_P(sit2[current_frame], ANIM_SIZE);
// 			oled_set_cursor(LUNA_X, LUNA_Y + 2 + jumpOffset);
// 			oled_write_raw_P(sit3[current_frame], ANIM_SIZE);
// 			oled_set_cursor(LUNA_X, LUNA_Y);
								
// 		} else if (current_wpm <= MIN_RUN_SPEED) {
// 			oled_write_raw_P(walk1[current_frame], ANIM_SIZE);
// 			oled_set_cursor(LUNA_X, LUNA_Y + 1 + jumpOffset);
// 			oled_write_raw_P(walk2[current_frame], ANIM_SIZE);
// 			oled_set_cursor(LUNA_X, LUNA_Y + 2 + jumpOffset);
// 			oled_write_raw_P(walk3[current_frame], ANIM_SIZE);
// 			oled_set_cursor(LUNA_X, LUNA_Y);

// 		} else {
// 			oled_write_raw_P(run1[current_frame], ANIM_SIZE);
// 			oled_set_cursor(LUNA_X, LUNA_Y + 1 + jumpOffset);
// 			oled_write_raw_P(run2[current_frame], ANIM_SIZE);
// 			oled_set_cursor(LUNA_X, LUNA_Y + 2 + jumpOffset);
// 			oled_write_raw_P(run3[current_frame], ANIM_SIZE);
// 			oled_set_cursor(LUNA_X, LUNA_Y);
// 		}
// 	}

// 	#if OLED_TIMEOUT > 0
// 	/* the animation prevents the normal timeout from occuring */
// 	if (last_input_activity_elapsed() > OLED_TIMEOUT && last_led_activity_elapsed() > OLED_TIMEOUT) {
// 		oled_off();
// 		return;
// 	} else {
// 		oled_on();
// 	}
// 	#endif

// 	/* animation timer */
// 	if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
// 		anim_timer = timer_read32();
// 		animate_luna();
// 	}
// }
/* KEYBOARD PET END */

// Set coordinates for visualizer to show

// #define MATRIX_DISPLAY_X 7
// #define MATRIX_DISPLAY_Y 35

// Function to draw pixels when keys are pressed. Call this in oled_task_user
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
	// for (uint8_t y = 0; y < 8; y++) {
	// 	oled_write_pixel(MATRIX_DISPLAY_X - 1, MATRIX_DISPLAY_Y + y + 1, true); oled_write_pixel(MATRIX_DISPLAY_X + 18, MATRIX_DISPLAY_Y + y + 1, true);
	// }

}

// Splash: Initialize the splash timer functions
static uint32_t oled_splash_timer = 0;
static bool clear_splash = true;

// Splash: Function to render the splash screen
static void render_splash(void) {
    oled_write_raw_P(splash, sizeof(splash));
	oled_set_cursor(5,5);
	oled_write_P(PSTR("Version 0.45"), false);
}

// Splash: Function to clear the splash screen
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

// Splash: Create the function for the timer
void init_timer(void){
   oled_splash_timer = timer_read32();
};

// Splash: Run the Initialize timer function when the keyboard starts
void keyboard_post_init_kb(void) {
    init_timer();

    keyboard_post_init_user();
}

void render_tavern_logo(int LOGO_X, int LOGO_Y) {
	oled_set_cursor(LOGO_X, LOGO_Y);
	oled_write_raw_P(tavern_logo_top, sizeof(tavern_logo_top));
	oled_set_cursor(LOGO_X, LOGO_Y + 1);	
	oled_write_raw_P(tavern_logo_bottom, sizeof(tavern_logo_bottom));	

	oled_set_cursor(LOGO_X, LOGO_Y + 2);
	oled_write_P(wing_left, false);	
	oled_set_cursor(LOGO_X + 10, LOGO_Y + 2);
	oled_write_P(wing_right, false);	
}

void wpm_counter(int COUNTER_X, int COUNTER_Y){
	/* wpm counter */
		uint8_t n = get_current_wpm();
		char    wpm_str[4];
		oled_set_cursor(COUNTER_X, COUNTER_Y);
		wpm_str[3] = '\0';
		wpm_str[2] = '0' + n % 10;
		wpm_str[1] = '0' + (n /= 10) % 10;
		wpm_str[0] = '0' + n / 10;
		oled_write(wpm_str, false);
}

// My custom WPM meter code
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

// Boombox Animation Code
static uint8_t boombox_frame = 0;
uint32_t b_anim_timer = 0;	// Timer
#define BOOMBOX_FRAME_DURATION 150  // how long each frame lasts in ms

void render_boombox(uint8_t col, uint8_t line){

	void animate_boombox(void){
		/* switch frame */
		boombox_frame = (boombox_frame + 1) % BOOMBOX_ANIM_FRAMES;

		for (uint8_t i = 0; i < 6; i++) {	// Run this code for each row
			oled_set_cursor(col, line + i);
			oled_write_raw_P(boombox[i][boombox_frame], BOOMBOX_ANIM_SIZE);
		}
	}

	#if OLED_TIMEOUT > 0
	/* the animation prevents the normal timeout from occuring */
	if (last_input_activity_elapsed() > OLED_TIMEOUT && last_led_activity_elapsed() > OLED_TIMEOUT) {
		oled_off();
			return;
		} else {
			oled_on();
		}
		#endif

	/* animation timer */
	if (timer_elapsed32(b_anim_timer) > BOOMBOX_FRAME_DURATION) {
		b_anim_timer = timer_read32();
		animate_boombox();
	}
}

// New reformatted Calcifer code
static uint8_t calcifer_frame = 0;
uint32_t c_anim_timer = 0;	// Timer
//static uint8_t c_anim_frame = 0;
static uint8_t c_anim_type  = 0;
bool isHiding = false;
// led_t led_usb_state;		// USB state status variable (not needed for calcifer)
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
		if (isHiding) {		// Hiding Animation
			c_anim_type = 3;
		} else if (current_wpm <= CALC_MIN_WALK_SPEED) {	// Idle Animation
			c_anim_type = 0;
		} else if (current_wpm <= CALC_MIN_RUN_SPEED) {		// Walk Animation
			c_anim_type = 1;
		} else {	// Run Animation
			c_anim_type = 2;
		}
	}

	#if OLED_TIMEOUT > 0
	/* the animation prevents the normal timeout from occuring */
	if (last_input_activity_elapsed() > OLED_TIMEOUT && last_led_activity_elapsed() > OLED_TIMEOUT) {
		oled_off();
			return;
		} else {
			oled_on();
		}
		#endif

	/* animation timer */
	if (timer_elapsed32(c_anim_timer) > CALCIFER_FRAME_DURATION) {
		c_anim_timer = timer_read32();
		animate_calcifer();
	}
}


// Render HSV code from drashna
void render_rgb_hsv(uint8_t col, uint8_t line) {
    oled_set_cursor(col, line - 1);
    oled_write_P(PSTR("HSV:"), false);
	oled_set_cursor(col, line);
#ifdef RGB_MATRIX_ENABLE
    oled_write(get_u8_str(rgb_matrix_get_hue(), ' '), false);
    oled_write_P(PSTR(","), false);
    oled_write(get_u8_str(rgb_matrix_get_sat(), ' '), false);
    oled_write_P(PSTR(","), false);
    oled_write(get_u8_str(rgb_matrix_get_val(), ' '), false);
#elif RGBLIGHT_ENABLE
    if (is_rgblight_startup_running()) {
        oled_write_P(PSTR("Start Animation"), false);
    } else {
        oled_write(get_u8_str(rgblight_get_hue(), ' '), false);
        oled_write_P(PSTR(","), false);
        oled_write(get_u8_str(rgblight_get_sat(), ' '), false);
        oled_write_P(PSTR(","), false);
        oled_write(get_u8_str(rgblight_get_val(), ' '), false);
    }
#endif
}

// Render RGB mode code from drashna
	// void render_rgb_mode(uint8_t col, uint8_t line) {
	// 	oled_set_cursor(col, line);
	// 	__attribute__((unused)) static uint8_t mode;
	// 	bool                                   need_update = false;
	// 	static char                            buf[21]     = {0};

	// #ifdef RGB_MATRIX_ENABLE
	// 	if (mode != rgb_matrix_get_mode()) {
	// 		snprintf(buf, sizeof(buf), "%-20s", rgb_matrix_name(rgb_matrix_get_mode()));
	// 		mode        = rgb_matrix_get_mode();
	// 		need_update = true;
	// 	}
	// #elif RGBLIGHT_ENABLE
	// 	if (mode != rgblight_get_mode()) {
	// 		snprintf(buf, sizeof(buf), "%-20s", rgblight_name(rgblight_get_mode()));
	// 		mode        = rgblight_get_mode();
	// 		need_update = true;
	// 	}
	// #endif
	// 	if (need_update) {
	// 		for (uint8_t i = 1; i < sizeof(buf); ++i) {
	// 			if (buf[i] == 0)
	// 				break;
	// 			else if (buf[i] == '_')
	// 				buf[i] = ' ';
	// 			else if (buf[i - 1] == ' ')
	// 				buf[i] = toupper(buf[i]);
	// 			else if (buf[i - 1] != ' ')
	// 				buf[i] = tolower(buf[i]);
	// 		}
	// 	}

	// 	oled_write(buf, false);
	// }



// Render OLED function. Use this instead of oled_task_user
static void render_oled(void) {
    current_wpm   = get_current_wpm();		// Used for the wpm counter
    led_usb_state = host_keyboard_led_state();	// Used by the keyboard pet to find the caps lock state
    //led_t led_state = host_keyboard_led_state();
/*
    render_luna(0, 1);	// Render keyboard pet
	

	oled_set_cursor(6,0);
    oled_write_raw_P(logo1, sizeof(logo1));		// Render logo line 1
	oled_set_cursor(6,1);
	oled_write_raw_P(logo2, sizeof(logo2));		// Render logo line 2
	oled_set_cursor(6,2);
	oled_write_raw_P(logo3, sizeof(logo3));		// Render logo line 3
	oled_set_cursor(16,3);
	oled_write_P(PSTR("V.06"), false);			// Print Text
	
*/	
	render_tavern_logo(8,0);

	// clear line first
		oled_set_cursor(8,3);
		oled_advance_page(true);
	// clear line first
		oled_set_cursor(8,4);
		oled_advance_page(true);
	// clear line first
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

    // Host Keyboard Layer Status
    switch (get_highest_layer(layer_state)) {
        case 0:
			render_calcifer(0,0);
			oled_set_cursor(11,2);
            oled_write_P(PSTR("PRIMARY"), false);
            break;
        case 1:
			render_calcifer(0,0);
			oled_set_cursor(11,2);
            oled_write_P(PSTR(" WORK  "), false);
            break;
        case 2:
			render_calcifer(0,0);
			oled_set_cursor(11,2);
            oled_write_P(PSTR(" GAMES "), false);
            break;
		case 3:
			render_boombox(0,0);
			oled_set_cursor(11,2);
			oled_write_P(PSTR(" MUSIC "), false);
			// clear line first
				oled_set_cursor(8,4);
				oled_advance_page(true);
			//render_rgb_mode(8,5);
			render_rgb_hsv(8,4);
			break;
		case 4:
			oled_set_cursor(11,2);
			oled_write_P(PSTR(" PIANO "), false);
			break;
		case 5:
			oled_set_cursor(11,2);
            oled_write_P(PSTR(" FUNC  "), false);
			break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_set_cursor(11,2);
			oled_write_ln_P(PSTR("UNDEF"), false);
    }

	#if OLED_TIMEOUT > 0
	/* the animation prevents the normal timeout from occuring */
	if (last_input_activity_elapsed() > OLED_TIMEOUT && last_led_activity_elapsed() > OLED_TIMEOUT) {
		oled_off();
			return;
		} else {
			oled_on();
		}
		#endif
		
}

#ifndef SHOW_SPLASH
#    define SHOW_SPLASH 1000
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

// Splash screen ends

#endif