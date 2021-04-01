#pragma bank 255
// SpriteSheet: box
  
#include "gbs_types.h"
#include "data/tileset_2.h"

const void __at(255) __bank_spritesheet_1;

const metasprite_t spritesheet_1_metasprite_0[]  = {
  { 0, 8, 0, 0 }, { 0, -8, 2, 0 },
{metasprite_end}
};

const metasprite_t * const spritesheet_1_metasprites[] = {
    spritesheet_1_metasprite_0
};

const struct spritesheet_t spritesheet_1 = {
    .n_tiles = 4,
    .n_metasprites = 1,
    .metasprites = spritesheet_1_metasprites,
    .animations = {
        {
            .start = 0,
            .end = 0
        },
        {
            .start = 0,
            .end = 0
        },
        {
            .start = 0,
            .end = 0
        },
        {
            .start = 0,
            .end = 0
        },
        {
            .start = 0,
            .end = 0
        },
        {
            .start = 0,
            .end = 0
        },
        {
            .start = 0,
            .end = 0
        },
        {
            .start = 0,
            .end = 0
        }
    },
    .tiles = {
        0xFF, 0xFF, 0xFF, 0x01, 0x01, 0xFF, 0xF9, 0xFF, 0xE9, 0xDF, 0xC9, 0xBF, 0x99, 0x7F, 0x39, 0xFF,
        0x79, 0xFF, 0xF9, 0xDF, 0x99, 0xEF, 0xC9, 0xFF, 0xF9, 0xFF, 0xF9, 0x07, 0x01, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0x80, 0x80, 0xFF, 0x9F, 0xFF, 0x97, 0xFB, 0x93, 0xFD, 0x9B, 0xFF, 0x9F, 0xFE,
        0x9E, 0xFD, 0x9C, 0xFB, 0x99, 0xF7, 0x93, 0xFF, 0x9F, 0xFF, 0x9F, 0xE0, 0x80, 0xFF, 0xFF, 0xFF
    },
    .tileset = TO_FAR_PTR_T(tileset_2)
};
