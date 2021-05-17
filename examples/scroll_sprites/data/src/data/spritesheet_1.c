#pragma bank 255
// SpriteSheet: panacea
  
#include "gbs_types.h"
#include "data/tileset_2.h"

const void __at(255) __bank_spritesheet_1;

const metasprite_t spritesheet_1_metasprite_0[]  = {
    { 0, 0, 4, 32 }, { 0, 8, 6, 32 },
    {metasprite_end}
};

const metasprite_t spritesheet_1_metasprite_1[]  = {
    { 0, 8, 0, 0 }, { 0, -8, 2, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_1_metasprite_2[]  = {
    { 0, 8, 4, 0 }, { 0, -8, 6, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_1_metasprite_3[]  = {
    { 0, 0, 0, 32 }, { 0, 8, 2, 32 },
    {metasprite_end}
};

const metasprite_t spritesheet_1_metasprite_4[]  = {
    { 0, 8, 8, 0 }, { 0, -8, 10, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_1_metasprite_5[]  = {
    { 0, 0, 8, 32 }, { 0, 8, 10, 32 },
    {metasprite_end}
};

const metasprite_t * const spritesheet_1_metasprites[] = {
    spritesheet_1_metasprite_0,
    spritesheet_1_metasprite_1,
    spritesheet_1_metasprite_2,
    spritesheet_1_metasprite_3,
    spritesheet_1_metasprite_4,
    spritesheet_1_metasprite_1,
    spritesheet_1_metasprite_2,
    spritesheet_1_metasprite_1,
    spritesheet_1_metasprite_5,
    spritesheet_1_metasprite_3,
    spritesheet_1_metasprite_0,
    spritesheet_1_metasprite_3
};

const struct spritesheet_t spritesheet_1 = {
    .n_metasprites = 12,
    .metasprites = spritesheet_1_metasprites,
    .animations = {
        {
            .start = 0,
            .end = 0
        },
        {
            .start = 1,
            .end = 1
        },
        {
            .start = 2,
            .end = 2
        },
        {
            .start = 3,
            .end = 3
        },
        {
            .start = 0,
            .end = 0
        },
        {
            .start = 4,
            .end = 7
        },
        {
            .start = 2,
            .end = 2
        },
        {
            .start = 8,
            .end = 11
        }
    },
    .bounds = {
        .left = 0,
        .bottom = 7,
        .right = 15,
        .top = -8
    },
    .tileset = TO_FAR_PTR_T(tileset_2),
    .cgb_tileset = { NULL, NULL }
};
