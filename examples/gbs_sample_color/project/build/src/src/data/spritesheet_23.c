#pragma bank 255
// SpriteSheet: checkbox
  
#include "gbs_types.h"
#include "data/tileset_27.h"

const void __at(255) __bank_spritesheet_23;

const metasprite_t spritesheet_23_metasprite_0[]  = {
    { 0, 0, 0, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_23_metasprite_1[]  = {
    { 0, 0, 2, 0 },
    {metasprite_end}
};

const metasprite_t * const spritesheet_23_metasprites[] = {
    spritesheet_23_metasprite_0,
    spritesheet_23_metasprite_1
};

const struct spritesheet_t spritesheet_23 = {
    .n_metasprites = 2,
    .metasprites = spritesheet_23_metasprites,
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
    .tileset = TO_FAR_PTR_T(tileset_27),
    .cgb_tileset = { NULL, NULL }
};
