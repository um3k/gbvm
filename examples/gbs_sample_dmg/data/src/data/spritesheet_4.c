#pragma bank 255
// SpriteSheet: npc003
  
#include "gbs_types.h"
#include "data/tileset_6.h"

const void __at(255) __bank_spritesheet_4;

const metasprite_t spritesheet_4_metasprite_0[]  = {
    { 0, 8, 8, 0 }, { 0, -8, 10, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_4_metasprite_1[]  = {
    { 0, 8, 0, 0 }, { 0, -8, 2, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_4_metasprite_2[]  = {
    { 0, 8, 4, 0 }, { 0, -8, 6, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_4_metasprite_3[]  = {
    { 0, 0, 0, 32 }, { 0, 8, 2, 32 },
    {metasprite_end}
};

const metasprite_t spritesheet_4_metasprite_4[]  = {
    { 0, 8, 20, 0 }, { 0, -8, 22, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_4_metasprite_5[]  = {
    { 0, 8, 12, 0 }, { 0, -8, 14, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_4_metasprite_6[]  = {
    { 0, 8, 16, 0 }, { 0, -8, 18, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_4_metasprite_7[]  = {
    { 0, 0, 12, 32 }, { 0, 8, 14, 32 },
    {metasprite_end}
};

const metasprite_t * const spritesheet_4_metasprites[] = {
    spritesheet_4_metasprite_0,
    spritesheet_4_metasprite_1,
    spritesheet_4_metasprite_2,
    spritesheet_4_metasprite_3,
    spritesheet_4_metasprite_4,
    spritesheet_4_metasprite_0,
    spritesheet_4_metasprite_5,
    spritesheet_4_metasprite_1,
    spritesheet_4_metasprite_6,
    spritesheet_4_metasprite_2,
    spritesheet_4_metasprite_7,
    spritesheet_4_metasprite_3
};

const struct spritesheet_t spritesheet_4 = {
    .n_metasprites = 12,
    .metasprites = spritesheet_4_metasprites,
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
            .start = 4,
            .end = 5
        },
        {
            .start = 6,
            .end = 7
        },
        {
            .start = 8,
            .end = 9
        },
        {
            .start = 10,
            .end = 11
        }
    },
    .bounds = {
        .left = 0,
        .bottom = 7,
        .right = 15,
        .top = -8
    },
    .tileset = TO_FAR_PTR_T(tileset_6),
    .cgb_tileset = { NULL, NULL }
};
