#pragma bank 255
// SpriteSheet: cursor
  
#include "gbs_types.h"
#include "data/tileset_9.h"

const void __at(255) __bank_spritesheet_5;

const metasprite_t spritesheet_5_metasprite_0[]  = {
    { 0, 8, 0, 0 }, { 0, -8, 2, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_5_metasprite_1[]  = {
    { 0, 8, 4, 0 }, { 0, -8, 6, 0 },
    {metasprite_end}
};

const metasprite_t * const spritesheet_5_metasprites[] = {
    spritesheet_5_metasprite_0,
    spritesheet_5_metasprite_1
};

const struct spritesheet_t spritesheet_5 = {
    .n_metasprites = 2,
    .metasprites = spritesheet_5_metasprites,
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
    .bounds = {
        .left = 0,
        .bottom = 7,
        .right = 15,
        .top = -8
    },
    .tileset = TO_FAR_PTR_T(tileset_9),
    .cgb_tileset = { NULL, NULL }
};
