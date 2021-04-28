#pragma bank 255
// SpriteSheet: npc001
  
#include "gbs_types.h"
#include "data/tileset_8.h"

const void __at(255) __bank_spritesheet_6;

const metasprite_t spritesheet_6_metasprite_0[]  = {
    { 0, 8, 8, 0 }, { 0, -8, 10, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_6_metasprite_1[]  = {
    { 0, 8, 0, 0 }, { 0, -8, 2, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_6_metasprite_2[]  = {
    { 0, 8, 4, 0 }, { 0, -8, 6, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_6_metasprite_3[]  = {
    { 0, 0, 0, 32 }, { 0, 8, 2, 32 },
    {metasprite_end}
};

const metasprite_t * const spritesheet_6_metasprites[] = {
    spritesheet_6_metasprite_0,
    spritesheet_6_metasprite_1,
    spritesheet_6_metasprite_2,
    spritesheet_6_metasprite_3
};

const struct spritesheet_t spritesheet_6 = {
    .n_metasprites = 4,
    .metasprites = spritesheet_6_metasprites,
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
        }
    },
    .tileset = TO_FAR_PTR_T(tileset_8),
    .cgb_tileset = { NULL, NULL }
};
