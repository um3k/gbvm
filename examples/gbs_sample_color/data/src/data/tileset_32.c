#pragma bank 255

// Tileset: 32

#include "gbs_types.h"

BANKREF(tileset_32)

const struct tileset_t tileset_32 = {
    .n_tiles = 4,
    .tiles = {
        0x1E, 0x1E, 0x1F, 0x11, 0x5F, 0x1D, 0x47, 0x05, 0x77, 0x07, 0xE0, 0x00, 0xB0, 0x00, 0xF8, 0x28,
        0xC8, 0x78, 0xE8, 0x18, 0x50, 0xB0, 0x27, 0xE7, 0xC7, 0xC5, 0x1F, 0x1D, 0x1F, 0x11, 0x1E, 0x1E,
        0x78, 0x78, 0xF8, 0x88, 0xF0, 0xB2, 0xE0, 0xA9, 0xE4, 0xE0, 0x05, 0x00, 0x0F, 0x00, 0x1F, 0x14,
        0x13, 0x1E, 0x17, 0x18, 0x0A, 0x0D, 0xE6, 0xE5, 0xE3, 0xA3, 0xF8, 0xB8, 0xF8, 0x88, 0x78, 0x78
    }
};
