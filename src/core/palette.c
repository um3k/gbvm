#pragma bank 3

#include "palette.h"

#include <string.h>

UBYTE palette_update_mask;

UWORD SprPalette[32];
UWORD BkgPalette[32];

UWORD SprPaletteBuffer[32];
UWORD BkgPaletteBuffer[32];

void palette_init() __banked {
    palette_update_mask = 0x3F;

    #ifdef CGB
        if (_cpu == CGB_TYPE) {
            memset(BkgPalette, 0, sizeof(BkgPalette));
            memset(SprPalette, 0, sizeof(SprPalette));
            memset(BkgPaletteBuffer, 0, sizeof(BkgPaletteBuffer));
            memset(SprPaletteBuffer, 0, sizeof(SprPaletteBuffer));
            return;
        }
    #endif
    BkgPalette[0] = SprPalette[0] = 0xE4u; 
    SprPalette[4] = 0xE0u;
}
