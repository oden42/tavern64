#include "quantum.h"

#ifdef OLED_ENABLE


/* KEYBOARD PET START */

		/* settings */
		#    define MIN_WALK_SPEED      10
		#    define MIN_RUN_SPEED       60

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
		int jumpOffset = 0;

		/* logic */
		static void render_luna(int LUNA_X, int LUNA_Y) {
			/* Sit 1 */
			static const char PROGMEM sit1[2][ANIM_SIZE] = {
					/* 'cat_sleep_1', 32x24px */
				{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x32, 0x2a, 
				 0x26, 0x02, 0x00, 0x00, 0x10, 0x19, 0x1d, 0x17, 0x13, 0x01, 0x00, 0x40, 0xc0, 0x40, 0x00, 0x00,},
					/* 'cat_sleep_2', 32x24px */
				{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x62, 0x72, 0x5a, 0x4e, 0x46, 0x02, 
				 0x00, 0x00, 0x00, 0x09, 0x0d, 0x0b, 0x09, 0x00, 0x00, 0x90, 0xd0, 0xb0, 0x90, 0x00, 0x00, 0x00,}
			};
			/* Sit 2 */
			static const char PROGMEM sit2[2][ANIM_SIZE] = {
					/* 'cat_sleep_1', 32x24px */
				{0x00, 0x00, 0xc0, 0x60, 0x30, 0x98, 0x0c, 0x04, 0x06, 0x02, 0x22, 0xc3, 0x01, 0x01, 0x01, 0x01, 
				 0x01, 0xf9, 0xc9, 0x59, 0x72, 0x62, 0x22, 0x24, 0x24, 0x68, 0x70, 0x59, 0xc9, 0xf9, 0x00, 0x00,},
					/* 'cat_sleep_2', 32x24px */
				{0x00, 0x00, 0xc0, 0x60, 0x30, 0x98, 0x08, 0x0c, 0x04, 0x04, 0x46, 0x82, 0x02, 0x02, 0x02, 0x02, 
				 0x02, 0xfa, 0xca, 0x5a, 0x72, 0x62, 0x26, 0x24, 0x24, 0x68, 0x70, 0x58, 0xc8, 0xf8, 0x00, 0x00,}
			};
			/* Sit 3 */
			static const char PROGMEM sit3[2][ANIM_SIZE] = {
					/* 'cat_sleep_1', 32x24px */
				{0x00, 0x1f, 0x30, 0x20, 0x20, 0x41, 0x72, 0x7c, 0x7c, 0x78, 0x30, 0x20, 0x21, 0x3e, 0x20, 0x24, 
				 0x24, 0x4f, 0x38, 0x50, 0x64, 0x48, 0x40, 0x50, 0x40, 0x48, 0x64, 0x30, 0x18, 0x2f, 0x44, 0x04,},
					/* 'cat_sleep_2', 32x24px */
				{0x00, 0x1f, 0x30, 0x20, 0x20, 0x41, 0x72, 0x7c, 0x7c, 0x78, 0x30, 0x20, 0x21, 0x3e, 0x20, 0x24, 
				 0x24, 0x4f, 0x38, 0x50, 0x64, 0x48, 0x40, 0x50, 0x40, 0x48, 0x64, 0x30, 0x18, 0x2f, 0x44, 0x04,}
			};
			/* Walk 1 */
			static const char PROGMEM walk1[2][ANIM_SIZE] = {
					/* 'cat_walk_1', 32x24px */
				{0x00, 0x00, 0x00, 0xfc, 0x0e, 0x1f, 0x1f, 0xff, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 
				 0xd8, 0x98, 0xf0, 0x60, 0x20, 0x20, 0x20, 0x38, 0x38, 0x70, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,},
					/* 'cat_walk_2', 32x24px */
				{0x00, 0x00, 0xfc, 0x0e, 0x1f, 0x1f, 0xff, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 
				 0xec, 0x4c, 0x78, 0x30, 0x10, 0x10, 0x10, 0x1c, 0x1c, 0x38, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00,}	
			};
			/* Walk 2 */
			static const char PROGMEM walk2[2][ANIM_SIZE] = {
					/* 'cat_walk_1', 32x24px */
				{0x00, 0x00, 0x00, 0x0f, 0x18, 0xf0, 0x00, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x09, 0x49, 
				 0x25, 0x14, 0x10, 0x20, 0x00, 0x02, 0x40, 0xc0, 0xc8, 0x22, 0x11, 0x1f, 0x24, 0x24, 0x00, 0x00,},
					/* 'cat_walk_2', 32x24px */
				{0x00, 0x00, 0x03, 0x0e, 0x18, 0xe0, 0x00, 0x01, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x05, 0x15, 
				 0x12, 0x0a, 0x08, 0x10, 0x00, 0x01, 0x20, 0xe0, 0x24, 0x11, 0x08, 0x0f, 0x0a, 0x0a, 0x00, 0x00,}	
			};
			/* Walk 3 */
			static const char PROGMEM walk3[2][ANIM_SIZE] = {
					/* 'cat_walk_1', 32x24px */
				{0x00, 0x00, 0x00, 0x00, 0x3e, 0x63, 0x40, 0x40, 0x30, 0x18, 0x0c, 0x1e, 0x3e, 0x3e, 0x36, 0x04, 
				 0x04, 0x04, 0x1c, 0x3c, 0x38, 0x30, 0x20, 0x43, 0x47, 0x48, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00,},
					/* 'cat_walk_2', 32x24px */
				{0x00, 0x00, 0x00, 0x00, 0x00, 0x1d, 0x3f, 0x3c, 0x30, 0x40, 0x40, 0x46, 0x3f, 0x02, 0x02, 0x02, 
				 0x3e, 0x43, 0x40, 0x40, 0x38, 0x1e, 0x3f, 0x3f, 0x3e, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,}	
			};
			/* Run 1 */
			static const char PROGMEM run1[2][ANIM_SIZE] = {
					/* 'cat_run_1', 32x24px */
				{0x3c, 0x7e, 0xde, 0x8e, 0x0c, 0x18, 0x30, 0x60, 0x40, 0xc0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 
				 0x00, 0x60, 0xe0, 0x60, 0x60, 0xc0, 0xc0, 0x60, 0x60, 0x60, 0x40, 0xc0, 0x80, 0x00, 0x00, 0x00,},
					/* 'cat_run_2', 32x24px */
				{0x00, 0x7c, 0xfe, 0x1e, 0x0e, 0x3c, 0x60, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
				 0xe0, 0xe0, 0x60, 0x40, 0xc0, 0x80, 0x80, 0xe0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,}
			};
			/* Run 2 */
			static const char PROGMEM run2[2][ANIM_SIZE] = {
					/* 'cat_run_1', 32x24px */
				{0x00, 0xc0, 0x60, 0x31, 0x1b, 0x0e, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x21, 
				 0x11, 0x91, 0x49, 0x4b, 0x21, 0x41, 0x00, 0x84, 0x80, 0x80, 0x90, 0x44, 0x23, 0x3e, 0x48, 0x90,},
					/* 'cat_run_2', 32x24px */
				{0x00, 0x00, 0x01, 0x03, 0x06, 0x0c, 0xf8, 0x00, 0x00, 0x01, 0x01, 0x01, 0x02, 0x02, 0x22, 0x22, 
				 0x92, 0x93, 0x57, 0x42, 0x83, 0x01, 0x08, 0x00, 0x00, 0x20, 0x89, 0x47, 0x7c, 0x90, 0x90, 0x00,}
			};
			/* Run 3 */
			static const char PROGMEM run3[2][ANIM_SIZE] = {
					/* 'cat_run_1', 32x24px */
				{0x03, 0x0c, 0x08, 0x08, 0x0c, 0x06, 0x03, 0x07, 0x07, 0x07, 0x03, 0x01, 0x01, 0x01, 0x01, 0x03, 
				 0x06, 0x04, 0x04, 0x08, 0x18, 0x10, 0x20, 0x41, 0x43, 0x43, 0x67, 0x3e, 0x3c, 0x38, 0x00, 0x00,},
					/* 'cat_run_2', 32x24px */
				{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0e, 0x18, 0x30, 0x60, 0x40, 0x43, 0x66, 0x3e, 0x63, 
				 0x40, 0x40, 0x40, 0x78, 0x3e, 0x3e, 0x1b, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,}
			};
			/* Bark 1 */
			static const char PROGMEM bark1[2][ANIM_SIZE] = {
					/* 'cat_meow_1', 32x24px */
				{0x00, 0xc0, 0xe0, 0xe0, 0xc0, 0x80, 0x00, 0x20, 0x20, 0x2f, 0xbb, 0x93, 0x1e, 0x0c, 0x04, 0x44, 
				 0x04, 0x07, 0x07, 0x4e, 0x38, 0xe0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},
					/* 'cat_meow_2', 32x24px */
				{0x00, 0x00, 0xc0, 0xe0, 0xe0, 0xe0, 0xc0, 0x20, 0x20, 0x2f, 0xbb, 0x93, 0x1e, 0x0c, 0x04, 0x44, 
				 0x04, 0x07, 0x07, 0x4e, 0x38, 0xe0, 0x80, 0x80, 0x08, 0x04, 0x40, 0x40, 0x20, 0x00, 0x00, 0x00,}
			};
			/* Bark 2 */
			static const char PROGMEM bark2[2][ANIM_SIZE] = {
					/* 'cat_meow_1', 32x24px */
				{0x00, 0xc3, 0x7f, 0x03, 0x01, 0xe3, 0x1e, 0x00, 0xc1, 0x69, 0x34, 0x02, 0x02, 0x04, 0x00, 0x00, 
				 0x08, 0x08, 0x09, 0x3c, 0xc2, 0x03, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},
					/* 'cat_meow_2', 32x24px */
				{0x00, 0xff, 0x03, 0x01, 0x01, 0xff, 0x03, 0x00, 0xc1, 0x69, 0x34, 0x02, 0x06, 0x04, 0x00, 0x08, 
				 0x10, 0x0c, 0x15, 0x38, 0xcc, 0x07, 0x08, 0x88, 0x00, 0x00, 0x22, 0x42, 0x02, 0x04, 0x00, 0x00,}
			};
			/* Bark 3 */
			static const char PROGMEM bark3[2][ANIM_SIZE] = {
					/* 'cat_meow_1', 32x24px */
				{0x00, 0x07, 0x1c, 0x30, 0x60, 0x41, 0x43, 0x5e, 0x71, 0x60, 0xc0, 0x80, 0x8c, 0x98, 0xe0, 0x80, 
				 0x80, 0x8f, 0xf0, 0x80, 0xc7, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},
					/* 'cat_meow_2', 32x24px */
				{0x00, 0x07, 0x1c, 0x30, 0x60, 0x41, 0x43, 0x5e, 0x71, 0x60, 0xc0, 0x80, 0x8c, 0x98, 0xe0, 0x80, 
				 0x80, 0x8f, 0xf0, 0x80, 0xc7, 0x78, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,}
			};
			/* Sneak 1 */
			static const char PROGMEM sneak1[2][ANIM_SIZE] = {
					/* 'cat_sneak_1', 32x24px */
				{0xfe, 0x0f, 0x0f, 0x1f, 0x7e, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 
				 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},
					/* 'cat_sneak_2', 32x24px */
				{0xfc, 0x9e, 0x1e, 0x1e, 0x3c, 0x60, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
				 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,}
			};
			/* Sneak 2 */
			static const char PROGMEM sneak2[2][ANIM_SIZE] = {
					/* 'cat_sneak_1', 32x24px */
				{0x01, 0x03, 0x86, 0xcc, 0x78, 0x10, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x42, 0x43, 
				 0x23, 0x2d, 0xa9, 0x87, 0x07, 0x03, 0x11, 0x01, 0x01, 0x41, 0x13, 0x8e, 0xf8, 0x20, 0x20, 0x00,},
					/* 'cat_sneak_2', 32x24px */
				{0x00, 0x03, 0x06, 0x0c, 0x18, 0xf0, 0x80, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x42, 
				 0x43, 0x27, 0x2d, 0xa9, 0x87, 0x07, 0x03, 0x11, 0x01, 0x01, 0x41, 0x13, 0x8e, 0xf8, 0x20, 0x20,}
			};
			/* Sneak 3 */
			static const char PROGMEM sneak3[2][ANIM_SIZE] = {
					/* 'cat_sneak_1', 32x24px */
				{0x00, 0x3c, 0x63, 0x40, 0x40, 0x30, 0x18, 0x0c, 0x04, 0x04, 0x06, 0x0e, 0x1e, 0x3e, 0x3e, 0x34, 
				 0x1d, 0x3d, 0x3c, 0x3c, 0x19, 0x10, 0x20, 0x42, 0x42, 0x46, 0x49, 0x30, 0x00, 0x01, 0x01, 0x00,},
					/* 'cat_sneak_2', 32x24px */
				{0x00, 0x00, 0x1c, 0x3e, 0x3f, 0x3f, 0x1f, 0x0f, 0x0e, 0x1c, 0x10, 0x20, 0x60, 0x41, 0x46, 0x7c, 
				 0x46, 0x41, 0x41, 0x40, 0x30, 0x19, 0x1c, 0x3c, 0x3e, 0x3e, 0x1a, 0x01, 0x00, 0x00, 0x01, 0x01,}
			};

			/* animation */
			void animate_luna(void) {
				/* jump */
				if ((isJumping || !showedJump) && (current_wpm >= MIN_WALK_SPEED)) {
					/* clear */
					oled_set_cursor(LUNA_X, LUNA_Y + 2);
					oled_write("     ", false);

					oled_set_cursor(LUNA_X, LUNA_Y - 1);
					jumpOffset = -1;
					showedJump = true;
				} else {
					/* clear */
					oled_set_cursor(LUNA_X, LUNA_Y - 1);
					oled_write("     ", false);

					oled_set_cursor(LUNA_X, LUNA_Y);
					jumpOffset = 0;
				}

				/* switch frame */
				current_frame = (current_frame + 1) % 2;

				/* current status */
				if (led_usb_state.caps_lock) {
					oled_write_raw_P(bark1[current_frame], ANIM_SIZE);
					oled_set_cursor(LUNA_X, LUNA_Y + 1 + jumpOffset);
					oled_write_raw_P(bark2[current_frame], ANIM_SIZE);
					oled_set_cursor(LUNA_X, LUNA_Y + 2 + jumpOffset);
					oled_write_raw_P(bark3[current_frame], ANIM_SIZE);
					oled_set_cursor(LUNA_X, LUNA_Y);

				} else if (isSneaking) {
					oled_write_raw_P(sneak1[current_frame], ANIM_SIZE);
					oled_set_cursor(LUNA_X, LUNA_Y + 1 + jumpOffset);
					oled_write_raw_P(sneak2[current_frame], ANIM_SIZE);
					oled_set_cursor(LUNA_X, LUNA_Y + 2 + jumpOffset);
					oled_write_raw_P(sneak3[current_frame], ANIM_SIZE);
					oled_set_cursor(LUNA_X, LUNA_Y);

				} else if (current_wpm <= MIN_WALK_SPEED) {
					oled_write_raw_P(sit1[current_frame], ANIM_SIZE);
					oled_set_cursor(LUNA_X, LUNA_Y + 1 + jumpOffset);
					oled_write_raw_P(sit2[current_frame], ANIM_SIZE);
					oled_set_cursor(LUNA_X, LUNA_Y + 2 + jumpOffset);
					oled_write_raw_P(sit3[current_frame], ANIM_SIZE);
					oled_set_cursor(LUNA_X, LUNA_Y);
										
				} else if (current_wpm <= MIN_RUN_SPEED) {
					oled_write_raw_P(walk1[current_frame], ANIM_SIZE);
					oled_set_cursor(LUNA_X, LUNA_Y + 1 + jumpOffset);
					oled_write_raw_P(walk2[current_frame], ANIM_SIZE);
					oled_set_cursor(LUNA_X, LUNA_Y + 2 + jumpOffset);
					oled_write_raw_P(walk3[current_frame], ANIM_SIZE);
					oled_set_cursor(LUNA_X, LUNA_Y);

				} else {
					oled_write_raw_P(run1[current_frame], ANIM_SIZE);
					oled_set_cursor(LUNA_X, LUNA_Y + 1 + jumpOffset);
					oled_write_raw_P(run2[current_frame], ANIM_SIZE);
					oled_set_cursor(LUNA_X, LUNA_Y + 2 + jumpOffset);
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

// Set coordinates for visualizer to show

#define MATRIX_DISPLAY_X 100
#define MATRIX_DISPLAY_Y 50

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
		oled_write_pixel(MATRIX_DISPLAY_X + x, MATRIX_DISPLAY_Y - 2,true); oled_write_pixel(MATRIX_DISPLAY_X + x, MATRIX_DISPLAY_Y + 9,true);
	}
	for (uint8_t y = 0; y < 9; y++) {
		oled_write_pixel(MATRIX_DISPLAY_X - 1, MATRIX_DISPLAY_Y + y - 1, true); oled_write_pixel(MATRIX_DISPLAY_X + 18, MATRIX_DISPLAY_Y + y - 1, true);
	}
}

// Start Splash Screen
static uint32_t oled_splash_timer = 0;
static bool clear_splash = true;

static void render_splash(void) {
    static const char PROGMEM splash[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,192,224,224,240,240,240,240,240,240,224,224,224,192,192,224,240, 32,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,192,192,192,224, 96, 96, 96,224,224,192,128,  0,  0,  0,  0,  0,  0,  0,128,192,224,240,240,240,240,240,  0,  0, 
        0,128,227,227,243,249, 57,249,249,249,255,255,255,247,199,135,  7,  3,  1,  0,192,224,240,248,248,252, 60, 62,254,254,252,252,252, 56, 16,  0, 24,252,252,254,254,252,120,112, 56, 60,254,254,252,252,248,  0,192,240,248,248,252,252, 62,126,254,252,252,248,240, 56,252,254,254,254,252,248, 28,252,254,254,124,  0, 48,240,248,252,252,248, 48, 48, 56,248,252,252,248,248,112,  0,128,240,252,254,255,255,255,255,243,240,248,248,250,247,199,  7,  3,  0,192,224,240,252, 62, 31,143,255,255,255,255,255, 63, 
        1,128,128,127,255,255,255,255,255,248,224,225,227,255,191,191,159,207,199,224,224,  0,255,255,255,255,255,255,192,128,224,255,255,255,255,135,128,  0,128,240,255,255,255,255,135,  0,  0,  0,255,255,255,255,255, 63,248,255,255,255,255,255,208,152,140,143,199,199,195,128,248,255,255,255,255,255,128,131,131,129,192,192,  0,192,255,255,255,255,  7,  0,  0,192,255,255,255,255,255,  0,  0, 63,255,255,255,255,255,128,  0,  3,255,255,255,255,127, 31,  0, 14, 15, 31, 31, 31, 30, 30,254,255,255,255,255,255, 31, 31,
        15,  7,  1,  0,  1,  3,  3,  7,  7, 15, 15, 15, 15, 15,  7,  7,  7,  3,  3,  1,  0,  0,  0,  3,  7,143,143,135,131,131,131,  7, 15, 15,  7,131,129,128,129,  3,  7,  7,  7, 15, 15, 15, 15,  7,  7,  3,129,129,128,128,129,131,  7,  7, 15, 15,143,135,135,131,131,129,  0,  3,  3,  3,  7,135,143,143, 15,  7,  7,  3,129,128,131,135,135, 15, 15,  7,131,131,128,  3,  7, 15, 15,  7,131,129,128,128,  0,  1,  3,  7,  7,135,134,134,  7,  3,131,129,128,  0,  0,  0,  0,  0,  6,  6,  6,  7,  7,  7,  7,  7,  7,  7,  7,  6, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 65, 96, 80, 76, 66, 65, 48,  0,  0, 30, 33, 64, 64, 64, 64, 33, 30,  0,  0,  0,  0,  0,  0,  0,  0,  0, 64,127, 68, 68, 78, 64, 49,  0,  0,  0, 64,127, 64, 64, 64, 64, 33, 30,  0,  0,  0, 64,127, 64,  0,  0,  0,  1,  0, 64,127, 64,  0,  1,  0,  0, 64,127, 64,  0,  0,  0, 30, 33, 64, 64, 64, 64, 33, 30,  0,  0,  0, 64,127, 65,  6,  8, 48,127,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,
    };
    oled_write_raw_P(splash, sizeof(splash));
}

	static const char PROGMEM logo1[] = {32, 56, 60,156,158,222,222,254,254,188, 60, 60, 28, 12,  0,128,128,192,192,224,224,224,192,192,128,192,224,224,224,192,192,224,224,192,128,  0,  0,128,192,192,224,224,224,192,128,  0,192,192,224,224,192,224,224,192,  0,192,224,224,192,128,192,224,224,192,128,  0,192,240,248,252, 60, 14,134,134, 30, 30, 28,  0,  0,192,224,112,248,252,254,254,126,  0,  0,};
	static const char PROGMEM logo2[] = {252,254,255,255,193,135,159,255,127, 63,158,128,128,252,255,255,255,193,128,255,255,255, 15,  1,128,249,255,255,135,  0,252,255,255,127,  0,240,255,255,255, 99, 32, 49,159,143,  7,  0,224,255,255,255,  0,  7,  7,  1,128,249,255,255, 15,  1,192,255,255,255,  1,127,255,255,255,131,  3,  7,255,255,255, 62, 28, 30, 31, 31, 25,248,255,255,255, 63, 28, 30,  4,};
	static const char PROGMEM logo3[] = {0,  1,  3,  3,  7,  7,  7,  7,  3,  3,  3,  1,  0,  1,  3,  7,  7,  3,  1,  3,  7,  7,  3,  1,  1,  3,  3,  7,  7,  7,  3,  1,  0,  0,  0,  1,  3,  3,  7,  7,  3,  3,  1,  1,  0,  1,  3,  3,  3,  7,  7,  3,  1,  0,  1,  3,  7,  7,  3,  1,  3,  7,  7,  3,  1,  0,  0,  1,  3,  3,  2,  3,  3,  1,  0,  0,  0,  0,  2,  3,  3,  3,  3,  3,  3,  3,  2,  0,  0,};

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

void init_timer(void){
   oled_splash_timer = timer_read32();
};

void keyboard_post_init_kb(void) {
    init_timer();

    keyboard_post_init_user();
}

static void render_oled(void) {
    current_wpm   = get_current_wpm();
    led_usb_state = host_keyboard_led_state();

    /* KEYBOARD PET VARIABLES END */	

	/* KEYBOARD PET RENDER START */

    render_luna(0, 1);

    /* KEYBOARD PET RENDER END */

	oled_set_cursor(6,0);
    oled_write_raw_P(logo1, sizeof(logo1));
	oled_set_cursor(6,1);
	oled_write_raw_P(logo2, sizeof(logo2));
	oled_set_cursor(6,2);
	oled_write_raw_P(logo3, sizeof(logo3));
	
	oled_set_cursor(16,3);
	oled_write_P(PSTR("V.04"), false);
	
	oled_set_cursor(7,3);
    // Host Keyboard Layer Status
    // oled_write_P(PSTR("Layer"), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("BASE    "), false);
            break;
        case 1:
            oled_write_P(PSTR("WORK    "), false);
            break;
        case 2:
			oled_write_P(PSTR("GAME FPS"), false);
            break;
		case 3:
			oled_write_P(PSTR("GAME RPG"), false);
			break;
		case 4:
			oled_write_P(PSTR("CREATIVE"), false);
			break;
		case 5:
			oled_write_P(PSTR("LIGHTING"), false);
			break;
		case 6:
			oled_write_P(PSTR("AUDIO   "), false);
			break;
		case 7:
			oled_write_P(PSTR("MUSIC   "), false);
			break;
		case 8:
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
		print_matrix();
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

/* OLED SCREEN START */

// static const char PROGMEM republic_logo[] = {
        // 0x80, 0x81, 0x82, 0x83, 0x84, 0x00,
        // 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0x00,
        // 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0x00,
		// 0x85, 0x86, 0x87, 0x88, 0x89, 0x00,
    // };
	

	
/* oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    return OLED_ROTATION_180;       // flips the display 180 degrees
	} */



/* OLED SCREEN END */

#endif