#pragma bank 255
// SpriteSheet: savepoint
  
#include "gbs_types.h"
#include "data/tileset_12.h"

const void __at(255) __bank_spritesheet_10;

const metasprite_t spritesheet_10_metasprite_0[]  = {
    { 0, 8, 0, 0 }, { 0, -8, 0, 32 },
    {metasprite_end}
};

const metasprite_t spritesheet_10_metasprite_1[]  = {
    { 0, 8, 2, 0 }, { 0, -8, 2, 32 },
    {metasprite_end}
};

const metasprite_t * const spritesheet_10_metasprites[] = {
    spritesheet_10_metasprite_0,
    spritesheet_10_metasprite_1
};

const struct spritesheet_t spritesheet_10 = {
    .n_metasprites = 2,
    .metasprites = spritesheet_10_metasprites,
    .animations = {
        {
            .start = 0,
            .end = 1
        },
        {
            .start = 0,
            .end = 1
        },
        {
            .start = 0,
            .end = 1
        },
        {
            .start = 0,
            .end = 1
        },
        {
            .start = 0,
            .end = 1
        },
        {
            .start = 0,
            .end = 1
        },
        {
            .start = 0,
            .end = 1
        },
        {
            .start = 0,
            .end = 1
        }
    },
    .tileset = TO_FAR_PTR_T(tileset_12),
    .cgb_tileset = { NULL, NULL }
};
