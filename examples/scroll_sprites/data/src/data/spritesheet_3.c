#pragma bank 255
// SpriteSheet: static
  
#include "gbs_types.h"
#include "data/tileset_4.h"

const void __at(255) __bank_spritesheet_3;

const metasprite_t spritesheet_3_metasprite_0[]  = {
    { 0, 8, 0, 0 }, { 0, -8, 0, 32 },
    {metasprite_end}
};

const metasprite_t spritesheet_3_metasprite_1[]  = {
    { -10, 8, 0, 0 }, { 0, -8, 0, 32 },
    {metasprite_end}
};

const metasprite_t spritesheet_3_metasprite_2[]  = {
    { -19, 8, 0, 0 }, { 0, -8, 0, 32 },
    {metasprite_end}
};

const metasprite_t spritesheet_3_metasprite_3[]  = {
    { -27, 8, 0, 0 }, { 0, -8, 0, 32 },
    {metasprite_end}
};

const metasprite_t spritesheet_3_metasprite_4[]  = {
    { -34, 8, 0, 0 }, { 0, -8, 0, 32 },
    {metasprite_end}
};

const metasprite_t spritesheet_3_metasprite_5[]  = {
    { -40, 8, 0, 0 }, { 0, -8, 0, 32 },
    {metasprite_end}
};

const metasprite_t spritesheet_3_metasprite_6[]  = {
    { -45, 8, 0, 0 }, { 0, -8, 0, 32 },
    {metasprite_end}
};

const metasprite_t spritesheet_3_metasprite_7[]  = {
    { -49, 8, 0, 0 }, { 0, -8, 0, 32 },
    {metasprite_end}
};

const metasprite_t spritesheet_3_metasprite_8[]  = {
    { -52, 8, 0, 0 }, { 0, -8, 0, 32 },
    {metasprite_end}
};

const metasprite_t spritesheet_3_metasprite_9[]  = {
    { -54, 8, 0, 0 }, { 0, -8, 0, 32 },
    {metasprite_end}
};

const metasprite_t spritesheet_3_metasprite_10[]  = {
    { -55, 8, 0, 0 }, { 0, -8, 0, 32 },
    {metasprite_end}
};

const metasprite_t * const spritesheet_3_metasprites[] = {
    spritesheet_3_metasprite_0,
    spritesheet_3_metasprite_1,
    spritesheet_3_metasprite_2,
    spritesheet_3_metasprite_3,
    spritesheet_3_metasprite_4,
    spritesheet_3_metasprite_5,
    spritesheet_3_metasprite_6,
    spritesheet_3_metasprite_7,
    spritesheet_3_metasprite_8,
    spritesheet_3_metasprite_9,
    spritesheet_3_metasprite_10,
    spritesheet_3_metasprite_10,
    spritesheet_3_metasprite_9,
    spritesheet_3_metasprite_8,
    spritesheet_3_metasprite_7,
    spritesheet_3_metasprite_6,
    spritesheet_3_metasprite_5,
    spritesheet_3_metasprite_4,
    spritesheet_3_metasprite_3,
    spritesheet_3_metasprite_2,
    spritesheet_3_metasprite_1
};

const struct spritesheet_t spritesheet_3 = {
    .n_metasprites = 21,
    .metasprites = spritesheet_3_metasprites,
    .animations = {
        {
            .start = 0,
            .end = 20
        },
        {
            .start = 0,
            .end = 20
        },
        {
            .start = 0,
            .end = 20
        },
        {
            .start = 0,
            .end = 20
        },
        {
            .start = 0,
            .end = 20
        },
        {
            .start = 0,
            .end = 20
        },
        {
            .start = 0,
            .end = 20
        },
        {
            .start = 0,
            .end = 20
        }
    },
    .bounds = {
        .left = 0,
        .bottom = 7,
        .right = 15,
        .top = -8
    },
    .tileset = TO_FAR_PTR_T(tileset_4),
    .cgb_tileset = { NULL, NULL }
};
