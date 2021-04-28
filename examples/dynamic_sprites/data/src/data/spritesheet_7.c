#pragma bank 255
// SpriteSheet: elephant
  
#include "gbs_types.h"
#include "data/tileset_8.h"

const void __at(255) __bank_spritesheet_7;

const metasprite_t spritesheet_7_metasprite_0[]  = {
    { -10, 32, 0, 0 }, { -22, -48, 2, 0 }, { 0, 40, 2, 32 }, { 0, -32, 4, 0 }, { 0, 8, 6, 0 }, { 0, 8, 8, 0 }, { 0, 8, 10, 0 }, { 16, -32, 12, 0 }, { 0, 8, 14, 0 }, { 0, 8, 16, 0 }, { 0, 8, 18, 0 }, { 0, 8, 18, 32 }, { 0, 8, 20, 0 }, { 16, -40, 22, 0 }, { 0, 16, 24, 0 }, { 0, 8, 26, 0 }, { 0, 8, 28, 0 }, { 0, 8, 30, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_7_metasprite_1[]  = {
    { 0, -17, 32, 0 }, { -10, 49, 34, 0 }, { -22, -48, 2, 0 }, { 0, 40, 2, 32 }, { 0, -32, 4, 0 }, { 0, 8, 6, 0 }, { 0, 8, 8, 0 }, { 0, 8, 10, 0 }, { 16, -32, 12, 0 }, { 0, 8, 14, 0 }, { 0, 8, 16, 0 }, { 0, 8, 18, 0 }, { 0, 8, 18, 32 }, { 0, 8, 20, 0 }, { 16, -24, 24, 0 }, { 0, 8, 26, 0 }, { 0, 8, 28, 0 }, { 0, 8, 30, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_7_metasprite_2[]  = {
    { -10, 32, 36, 0 }, { -22, -48, 2, 0 }, { 0, 40, 2, 32 }, { 0, -32, 4, 0 }, { 0, 8, 6, 0 }, { 0, 8, 8, 0 }, { 0, 8, 10, 0 }, { 16, -32, 12, 0 }, { 0, 8, 14, 0 }, { 0, 8, 16, 0 }, { 0, 8, 18, 0 }, { 0, 8, 18, 32 }, { 0, 8, 20, 0 }, { 16, -24, 24, 0 }, { 0, 8, 26, 0 }, { 0, 8, 28, 0 }, { 0, 8, 30, 0 }, { 0, -48, 38, 0 }, { 0, 8, 40, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_7_metasprite_3[]  = {
    { -10, 32, 42, 0 }, { -22, -48, 2, 0 }, { 0, 40, 2, 32 }, { 0, -32, 4, 0 }, { 0, 8, 6, 0 }, { 0, 8, 8, 0 }, { 0, 8, 10, 0 }, { 16, -32, 12, 0 }, { 0, 8, 14, 0 }, { 0, 8, 16, 0 }, { 0, 8, 18, 0 }, { 0, 8, 18, 32 }, { 0, 8, 20, 0 }, { 16, -24, 24, 0 }, { 0, 8, 26, 0 }, { 0, 8, 28, 0 }, { 0, 8, 30, 0 }, { 0, -48, 44, 0 }, { 0, 8, 46, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_7_metasprite_4[]  = {
    { -10, 32, 48, 0 }, { -22, -48, 2, 0 }, { 0, 40, 2, 32 }, { 0, -32, 4, 0 }, { 0, 8, 6, 0 }, { 0, 8, 8, 0 }, { 0, 8, 10, 0 }, { 16, -32, 12, 0 }, { 0, 8, 14, 0 }, { 0, 8, 16, 0 }, { 0, 8, 18, 0 }, { 0, 8, 18, 32 }, { 0, 8, 20, 0 }, { 16, -24, 24, 0 }, { 0, 8, 26, 0 }, { 0, 8, 28, 0 }, { 0, 8, 30, 0 }, { 0, -40, 46, 0 }, { 0, -8, 50, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_7_metasprite_5[]  = {
    { -10, 32, 34, 0 }, { -22, -48, 2, 0 }, { 0, 40, 2, 32 }, { 0, -32, 4, 0 }, { 0, 8, 6, 0 }, { 0, 8, 8, 0 }, { 0, 8, 10, 0 }, { 16, -32, 12, 0 }, { 0, 8, 14, 0 }, { 0, 8, 16, 0 }, { 0, 8, 18, 0 }, { 0, 8, 18, 32 }, { 0, 8, 20, 0 }, { 16, -24, 24, 0 }, { 0, 8, 26, 0 }, { 0, 8, 28, 0 }, { 0, 8, 30, 0 }, { 0, -48, 44, 0 }, { 0, 8, 46, 0 },
    {metasprite_end}
};

const metasprite_t * const spritesheet_7_metasprites[] = {
    spritesheet_7_metasprite_0,
    spritesheet_7_metasprite_1,
    spritesheet_7_metasprite_2,
    spritesheet_7_metasprite_3,
    spritesheet_7_metasprite_4,
    spritesheet_7_metasprite_5,
    spritesheet_7_metasprite_2
};

const struct spritesheet_t spritesheet_7 = {
    .n_metasprites = 7,
    .metasprites = spritesheet_7_metasprites,
    .animations = {
        {
            .start = 0,
            .end = 6
        },
        {
            .start = 0,
            .end = 6
        },
        {
            .start = 0,
            .end = 6
        },
        {
            .start = 0,
            .end = 6
        },
        {
            .start = 0,
            .end = 6
        },
        {
            .start = 0,
            .end = 6
        },
        {
            .start = 0,
            .end = 6
        },
        {
            .start = 0,
            .end = 6
        }
    },
    .bounds = {
        .left = -16,
        .bottom = 7,
        .right = 35,
        .top = -32
    },
    .tileset = TO_FAR_PTR_T(tileset_8),
    .cgb_tileset = { NULL, NULL }
};
