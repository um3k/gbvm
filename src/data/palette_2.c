#pragma bank 255

// Palette: 2

#include "gbs_types.h"
#include <gb/cgb.h>

const void __at(255) __bank_palette_2;

const palette_t palette_2 = {
    0xF1,
    {
        DMG_PALETTE(DMG_WHITE, DMG_LITE_GRAY, DMG_DARK_GRAY, DMG_BLACK),
        CGB_PALETTE(RGB_WHITE, RGB_GREEN, RGB_DARKGREEN, RGB_BLACK),
        CGB_PALETTE(RGB_WHITE, RGB_GREEN, RGB_DARKGREEN, RGB_BLACK),
        CGB_PALETTE(RGB_WHITE, RGB_GREEN, RGB_DARKGREEN, RGB_BLACK),
        CGB_PALETTE(RGB_WHITE, RGB_GREEN, RGB_DARKGREEN, RGB_BLACK)
    }
};
