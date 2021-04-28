#pragma bank 255
// SpriteSheet: portal
  
#include "gbs_types.h"
#include "data/tileset_13.h"

const void __at(255) __bank_spritesheet_11;

const metasprite_t spritesheet_11_metasprite_0[]  = {
    { 0, 8, 0, 0 }, { 0, -8, 2, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_11_metasprite_1[]  = {
    { 0, 8, 4, 0 }, { 0, -8, 6, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_11_metasprite_2[]  = {
    { 0, 8, 8, 0 }, { 0, -8, 10, 0 },
    {metasprite_end}
};

const metasprite_t * const spritesheet_11_metasprites[] = {
    spritesheet_11_metasprite_0,
    spritesheet_11_metasprite_1,
    spritesheet_11_metasprite_2
};

const struct spritesheet_t spritesheet_11 = {
    .n_metasprites = 3,
    .metasprites = spritesheet_11_metasprites,
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
    .bounds = {
        .left = 0,
        .bottom = 7,
        .right = 15,
        .top = -8
    },
    .tileset = TO_FAR_PTR_T(tileset_13),
    .cgb_tileset = { NULL, NULL }
};
