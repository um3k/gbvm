#pragma bank 255

// Palette: 2

#include "gbs_types.h"

const void __at(255) __bank_palette_2;

const palette_t palette_2 = {
    0x01,
    {
        DMG_PALETTE(DMG_WHITE, DMG_LITE_GRAY, DMG_DARK_GRAY, DMG_BLACK)
    }
};
