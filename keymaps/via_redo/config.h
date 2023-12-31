#define DYNAMIC_KEYMAP_LAYER_COUNT 6

#ifdef STARTUP_SONG
	#undef STARTUP_SONG
#endif
	#define STARTUP_SONG SONG(MARIO_MUSHROOM)

#ifdef OLED_FONT_H
	#undef OLED_FONT_H
#endif
	#define OLED_FONT_H "keymaps/via_redo/tavern_font.h"
	#define OLED_FONT_5X5