/* Copyright 2023 Jacob Thompson (@oden42) <fenix42@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
 #pragma once

#include "config_common.h"

/* I2C Driver */
#define OLED_DISPLAY_128X64
#define I2C_DRIVER I2CD1							// Required for RP2040
#define I2C1_SDA_PIN GP28 							// Required for RP2040
#define I2C1_SCL_PIN GP29							// Required for RP2040


/* OLED Options */
#ifdef OLED_ENABLE
	#define OLED_FONT_H "keyboards/colsonkb/tavern64/lib/tavern64font.c"
	#define OLED_TIMEOUT 300000			// 5 minute timeout
	// #define OLED_TIMEOUT 120000			// 2 minute timeout
	#define OLED_UPDATE_INTERVAL 50
#endif


/* SPI Driver */
// #define SPI_DRIVER SPID0
// #define SPI_SLK_PIN GP18
// #define SPI_MISO_PIN GP20
// #define SPI_MOSI_PIN GP19

/* Double tap the side button to enter bootloader */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U
// #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP25

/* Tap Dance Options */
#define TAPPING_TERM 175

/* Audio Options */
#ifdef AUDIO_ENABLE
#define AUDIO_PIN GP26
#define AUDIO_PWM_DRIVER PWMD5 						// Required for RP2040
#define AUDIO_PWM_CHANNEL RP2040_PWM_CHANNEL_A 		// Required for RP2040
#define AUDIO_INIT_DELAY
// #define AUDIO_ENABLE_TONE_MULTIPLEXING
// #define AUDIO_TONE_MULTIPLEXING_RATE_DEFAULT 10
#define AUDIO_CLICKY
#define AUDIO_VOICES
#define STARTUP_SONG SONG(PORTAL)
#endif

/* RGB Underglow Settings */
#define RGB_DI_PIN GP27
#define RGB_MATRIX_LED_COUNT 75
#define WS2812_PIO_USE_PIO1 					// Required for RP2040

#ifdef RGB_DI_PIN
	#define ENABLE_RGB_MATRIX_ALPHAS_MODS
	#define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
	#define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
	#define ENABLE_RGB_MATRIX_BREATHING
	#define ENABLE_RGB_MATRIX_BAND_SAT
	#define ENABLE_RGB_MATRIX_BAND_VAL
	#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
	#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
	#define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
	#define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
	#define ENABLE_RGB_MATRIX_CYCLE_ALL
	#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
	#define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
	#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
	#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
	#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
	#define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
	#define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
	#define ENABLE_RGB_MATRIX_DUAL_BEACON
	#define ENABLE_RGB_MATRIX_RAINBOW_BEACON
	#define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
	#define ENABLE_RGB_MATRIX_RAINDROPS
	#define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
	#define ENABLE_RGB_MATRIX_HUE_BREATHING
	#define ENABLE_RGB_MATRIX_HUE_PENDULUM
	#define ENABLE_RGB_MATRIX_HUE_WAVE
	#define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
	#define ENABLE_RGB_MATRIX_PIXEL_FLOW
	#define ENABLE_RGB_MATRIX_PIXEL_RAIN
	#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
		#ifdef RGB_MATRIX_FRAMEBUFFER_EFFECTS
			#define ENABLE_RGB_MATRIX_TYPING_HEATMAP
			#define ENABLE_RGB_MATRIX_DIGITAL_RAIN
		#endif
	#define RGB_MATRIX_KEYPRESSES
		#ifdef RGB_MATRIX_KEYPRESSES
			#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
			#define ENABLE_RGB_MATRIX_SOLID_REACTIVE
			#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
			#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
			#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
			#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
			#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
			#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
			#define ENABLE_RGB_MATRIX_SPLASH
			#define ENABLE_RGB_MATRIX_MULTISPLASH
			#define ENABLE_RGB_MATRIX_SOLID_SPLASH
			#define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
		#endif
#endif