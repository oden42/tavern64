# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = yes       # Enable keyboard RGB underglow
AUDIO_ENABLE = yes          # Audio output
AUDIO_DRIVER = pwm_hardware	# Audio driver (required for RP2040)
# ENCODER_ENABLE = yes
RGB_MATRIX_ENABLE = no		# Enable per-key RGB lighting matrix
# RGB_MATRIX_DRIVER = WS2812
WS2812_DRIVER = vendor		# Required for RP2040
OLED_ENABLE = yes
OLED_DRIVER = SSD1306
WPM_ENABLE = yes
# Project specific files
# SRC += lib/ssd1306_sh1106.c
# QUANTUM_LIB_SRC += spi_master.c