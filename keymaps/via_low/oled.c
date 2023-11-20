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
    return OLED_ROTATION_270;       // flips the display 270 degrees
	}

bool oled_task_user(void) {
	
    /* KEYBOARD PET VARIABLES START */

    current_wpm   = get_current_wpm();
    led_usb_state = host_keyboard_led_state();

    /* KEYBOARD PET VARIABLES END */	

	oled_set_cursor(0,0);
    oled_write_P(republic_logo1, false);
	oled_set_cursor(0,1);
	oled_write_P(republic_logo2, false);
	oled_set_cursor(0,2);
	oled_write_P(republic_logo3, false);
	oled_set_cursor(0,3);
	oled_write_P(republic_logo4, false);
	
	oled_set_cursor(0,5);
	oled_write_P(PSTR("V.015"), false);
	
	oled_set_cursor(0,7);
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
	
	/* KEYBOARD PET RENDER START */
    render_luna(0, 11);
    /* KEYBOARD PET RENDER END */	
    
	/* wpm counter */
		uint8_t n = get_current_wpm();
		char    wpm_str[4];
		oled_set_cursor(1, 15);
		wpm_str[3] = '\0';
		wpm_str[2] = '0' + n % 10;
		wpm_str[1] = '0' + (n /= 10) % 10;
		wpm_str[0] = '0' + n / 10;
		oled_write(wpm_str, false);

		//oled_set_cursor(0, 6);
		//oled_write("wpm", false);
	
    return false;
}

/* OLED SCREEN END */

#endif