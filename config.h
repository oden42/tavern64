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
	#define OLED_TIMEOUT 120000
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

/* Audio Options */
#ifdef AUDIO_ENABLE
#define AUDIO_PIN GP26
#define AUDIO_PWM_DRIVER PWMD5 						// Required for RP2040
#define AUDIO_PWM_CHANNEL RP2040_PWM_CHANNEL_A 		// Required for RP2040
#define AUDIO_INIT_DELAY
// #define AUDIO_ENABLE_TONE_MULTIPLEXING
// #define AUDIO_TONE_MULTIPLEXING_RATE_DEFAULT 10
#define AUDIO_CLICKY
#endif

/* RGB Underglow Settings */
#define RGB_DI_PIN GP27							// MOVE TO JSON
#define RGBLED_NUM 100							// MOVE TO JSON
#define WS2812_PIO_USE_PIO1 						// Required for RP2040

#ifdef RGB_DI_PIN
	#define RGBLIGHT_HUE_STEP 8					// MOVE TO JSON
	#define RGBLIGHT_SAT_STEP 8					// MOVE TO JSON
	#define RGBLIGHT_VAL_STEP 8					// MOVE TO JSON
	#define RGBLIGHT_EFFECT_BREATHING			// MOVE TO JSON
	#define RGBLIGHT_EFFECT_RAINBOW_MOOD		// MOVE TO JSON
	#define RGBLIGHT_EFFECT_RAINBOW_SWIRL		// MOVE TO JSON
	#define RGBLIGHT_EFFECT_SNAKE				// MOVE TO JSON
	#define RGBLIGHT_EFFECT_KNIGHT				// MOVE TO JSON
	#define RGBLIGHT_EFFECT_CHRISTMAS			// MOVE TO JSON
	#define RGBLIGHT_EFFECT_STATIC_GRADIENT		// MOVE TO JSON
	#define RGBLIGHT_EFFECT_RGB_TEST			// MOVE TO JSON
	#define RGBLIGHT_EFFECT_ALTERNATING			// MOVE TO JSON
	#define RGBLIGHT_EFFECT_TWINKLE				// MOVE TO JSON
#endif
