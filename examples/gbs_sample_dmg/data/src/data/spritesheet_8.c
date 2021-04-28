#pragma bank 255
// SpriteSheet: fire
  
#include "gbs_types.h"
#include "data/tileset_10.h"

const void __at(255) __bank_spritesheet_8;

const metasprite_t spritesheet_8_metasprite_0[]  = {
    { 0, 8, 0, 0 }, { 0, -8, 2, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_8_metasprite_1[]  = {
    { 0, 8, 4, 0 }, { 0, -8, 6, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_8_metasprite_2[]  = {
    { 0, 8, 8, 0 }, { 0, -8, 10, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_8_metasprite_3[]  = {
    { 0, 8, 12, 0 }, { 0, -8, 14, 0 },
    {metasprite_end}
};

const metasprite_t * const spritesheet_8_metasprites[] = {
    spritesheet_8_metasprite_0,
    spritesheet_8_metasprite_1,
    spritesheet_8_metasprite_2,
    spritesheet_8_metasprite_3
};

const struct spritesheet_t spritesheet_8 = {
    .n_metasprites = 4,
    .metasprites = spritesheet_8_metasprites,
    .animations = {
        {
            .start = 0,
            .end = 3
        },
        {
            .start = 0,
            .end = 3
        },
        {
            .start = 0,
            .end = 3
        },
        {
            .start = 0,
            .end = 3
        },
        {
            .start = 0,
            .end = 3
        },
        {
            .start = 0,
            .end = 3
        },
        {
            .start = 0,
            .end = 3
        },
        {
            .start = 0,
            .end = 3
        }
    },
    .tileset = TO_FAR_PTR_T(tileset_10),
    .cgb_tileset = { NULL, NULL }
};
