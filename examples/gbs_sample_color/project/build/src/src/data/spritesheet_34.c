#pragma bank 255
// SpriteSheet: chest
  
#include "gbs_types.h"
#include "data/tileset_38.h"

const void __at(255) __bank_spritesheet_34;

const metasprite_t spritesheet_34_metasprite_0[]  = {
    { 0, 8, 0, 0 }, { 0, -8, 0, 32 },
    {metasprite_end}
};

const metasprite_t spritesheet_34_metasprite_1[]  = {
    { 0, 8, 2, 0 }, { 0, -8, 2, 32 },
    {metasprite_end}
};

const metasprite_t * const spritesheet_34_metasprites[] = {
    spritesheet_34_metasprite_0,
    spritesheet_34_metasprite_1
};

const struct spritesheet_t spritesheet_34 = {
    .n_metasprites = 2,
    .metasprites = spritesheet_34_metasprites,
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
    .tileset = TO_FAR_PTR_T(tileset_38),
    .cgb_tileset = { NULL, NULL }
};
