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
    .tileset = TO_FAR_PTR_T(tileset_2),
    .cgb_tileset = { NULL, NULL }
};
