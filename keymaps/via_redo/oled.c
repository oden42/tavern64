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

#define MATRIX_DISPLAY_X 7
#define MATRIX_DISPLAY_Y 35

// Function to draw pixels when keys are pressed. Call this in oled_task_user
static void print_matrix(void){
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

	// This creates the box around the drawn pixels
	for (uint8_t x = 0; x < 18; x++) {
		oled_write_pixel(MATRIX_DISPLAY_X + x, MATRIX_DISPLAY_Y - 0,true); oled_write_pixel(MATRIX_DISPLAY_X + x, MATRIX_DISPLAY_Y + 8,true);
	}
	for (uint8_t y = 0; y < 8; y++) {
		oled_write_pixel(MATRIX_DISPLAY_X - 1, MATRIX_DISPLAY_Y + y + 1, true); oled_write_pixel(MATRIX_DISPLAY_X + 18, MATRIX_DISPLAY_Y + y + 1, true);
	}
}

// Splash: Initialize the splash timer functions
static uint32_t oled_splash_timer = 0;
static bool clear_splash = true;

// Splash: Function to render the splash screen
static void render_splash(void) {
    oled_write_raw_P(splash, sizeof(splash));
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

// My new code
void wpm_bar(void){
    current_wpm   = get_current_wpm();
	for (uint8_t y = 58; y < 62; y++) { 
		for (uint8_t x = 0; x < 128; x++) {
			if(current_wpm > x){
				oled_write_pixel(x, y,true);
			}
			else{
				oled_write_pixel(x, y,false);
			}
		}
	}
}

// Render OLED function. Use this instead of oled_task_user
static void render_oled(void) {
    current_wpm   = get_current_wpm();		// Used for the wpm counter
    led_usb_state = host_keyboard_led_state();	// Used by the keyboard pet to find the caps lock state

render_calcifer(0,0);
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
	oled_set_cursor(12,3);
	
    // Host Keyboard Layer Status
    // oled_write_P(PSTR("Layer"), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
			//clear_splash = true;
			//clear_screen();
            oled_write_P(PSTR("Base    "), false);
			wpm_bar();	//needs to clear after switching
            break;
        case 1:
			//clear_splash = true;
			//clear_screen();
            oled_write_P(PSTR("WORK    "), false);
			print_matrix();	//needs to clear after switching
            break;
        case 2:
			oled_write_P(PSTR("GAMING"), false);
            break;
		case 3:
			oled_write_P(PSTR("AUDIO   "), false);
			break;
		case 4:
            oled_write_P(PSTR("FUNCTION"), false);
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
		
		oled_set_cursor(8, 4);

}

#ifndef SHOW_SPLASH
#    define SHOW_SPLASH 5000
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