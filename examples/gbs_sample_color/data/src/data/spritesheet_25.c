#pragma bank 255
// SpriteSheet: enemy_ship
  
#include "gbs_types.h"
#include "data/tileset_29.h"

const void __at(255) __bank_spritesheet_25;

const metasprite_t spritesheet_25_metasprite_0[]  = {
    { 0, 8, 0, 0 }, { 0, -8, 2, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_25_metasprite_1[]  = {
    { 0, 8, 4, 0 }, { 0, -8, 2, 0 },
    {metasprite_end}
};

const metasprite_t * const spritesheet_25_metasprites[] = {
    spritesheet_25_metasprite_0,
    spritesheet_25_metasprite_1
};

const struct spritesheet_t spritesheet_25 = {
    .n_metasprites = 2,
    .metasprites = spritesheet_25_metasprites,
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
    .tileset = TO_FAR_PTR_T(tileset_29),
    .cgb_tileset = { NULL, NULL }
};
