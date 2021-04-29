#pragma bank 255
// SpriteSheet: hidden_stairs
  
#include "gbs_types.h"
#include "data/tileset_26.h"

const void __at(255) __bank_spritesheet_22;

const metasprite_t spritesheet_22_metasprite_0[]  = {
    { 0, 8, 0, 0 }, { 0, -8, 0, 32 },
    {metasprite_end}
};

const metasprite_t * const spritesheet_22_metasprites[] = {
    spritesheet_22_metasprite_0
};

const struct spritesheet_t spritesheet_22 = {
    .n_metasprites = 1,
    .metasprites = spritesheet_22_metasprites,
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
    .tileset = TO_FAR_PTR_T(tileset_26),
    .cgb_tileset = { NULL, NULL }
};
