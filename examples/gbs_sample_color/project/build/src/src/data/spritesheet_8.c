#pragma bank 255
// SpriteSheet: rock
  
#include "gbs_types.h"
#include "data/tileset_12.h"

const void __at(255) __bank_spritesheet_8;

const metasprite_t spritesheet_8_metasprite_0[]  = {
    { 0, 8, 0, 0 }, { 0, -8, 2, 0 },
    {metasprite_end}
};

const metasprite_t * const spritesheet_8_metasprites[] = {
    spritesheet_8_metasprite_0
};

const struct spritesheet_t spritesheet_8 = {
    .n_metasprites = 1,
    .metasprites = spritesheet_8_metasprites,
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
    .bounds = {
        .left = 0,
        .bottom = 7,
        .right = 15,
        .top = -8
    },
    .tileset = TO_FAR_PTR_T(tileset_12),
    .cgb_tileset = { NULL, NULL }
};
