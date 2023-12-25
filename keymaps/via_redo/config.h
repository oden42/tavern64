#define DYNAMIC_KEYMAP_LAYER_COUNT 5

#ifdef STARTUP_SONG
	#undef STARTUP_SONG
#endif
	#define STARTUP_SONG SONG(MARIO_MUSHROOM)

#ifdef OLED_FONT_H
	#undef OLED_FONT_H
#endif
	#define OLED_FONT_H "keymaps/via_redo/drashna_font.h"
	#define OLED_FONT_END 255
	#define OLED_FONT_5X5
	#define OLED_LOGO_SCIFI