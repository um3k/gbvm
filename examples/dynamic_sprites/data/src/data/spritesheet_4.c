#pragma bank 255
// SpriteSheet: portal
  
#include "gbs_types.h"
#include "data/tileset_5.h"

const void __at(255) __bank_spritesheet_4;

const metasprite_t spritesheet_4_metasprite_0[]  = {
  { 0, 8, 0, 0 }, { 0, -8, 2, 0 },
{metasprite_end}
};

const metasprite_t spritesheet_4_metasprite_1[]  = {
  { 0, 8, 4, 0 }, { 0, -8, 6, 0 },
{metasprite_end}
};

const metasprite_t spritesheet_4_metasprite_2[]  = {
  { 0, 8, 8, 0 }, { 0, -8, 10, 0 },
{metasprite_end}
};

const metasprite_t * const spritesheet_4_metasprites[] = {
    spritesheet_4_metasprite_0,
    spritesheet_4_metasprite_1,
    spritesheet_4_metasprite_2
};

const struct spritesheet_t spritesheet_4 = {
    .n_metasprites = 3,
    .metasprites = spritesheet_4_metasprites,
    .animations = {
        {
            .start = 0,
            .end = 2
        },
        {
            .start = 0,
            .end = 2
        },
        {
            .start = 0,
            .end = 2
        },
        {
            .start = 0,
            .end = 2
        },
        {
            .start = 0,
            .end = 2
        },
        {
            .start = 0,
            .end = 2
        },
        {
            .start = 0,
            .end = 2
        },
        {
            .start = 0,
            .end = 2
        }
    },
    .tileset = TO_FAR_PTR_T(tileset_5),
    .cgb_tileset = { NULL, NULL }
};
