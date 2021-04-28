#pragma bank 255
// SpriteSheet: actor
  
#include "gbs_types.h"
#include "data/tileset_1.h"

const void __at(255) __bank_spritesheet_0;

const metasprite_t spritesheet_0_metasprite_0[]  = {
  { 0, 8, 4, 64 }, { 0, -8, 4, 96 },
{metasprite_end}
};

const metasprite_t spritesheet_0_metasprite_1[]  = {
  { 0, 8, 0, 0 }, { 0, -8, 2, 0 },
{metasprite_end}
};

const metasprite_t spritesheet_0_metasprite_2[]  = {
  { 0, 8, 4, 0 }, { 0, -8, 4, 32 },
{metasprite_end}
};

const metasprite_t spritesheet_0_metasprite_3[]  = {
  { 0, 0, 0, 32 }, { 0, 8, 2, 32 },
{metasprite_end}
};

const metasprite_t * const spritesheet_0_metasprites[] = {
    spritesheet_0_metasprite_0,
    spritesheet_0_metasprite_1,
    spritesheet_0_metasprite_2,
    spritesheet_0_metasprite_3
};

const struct spritesheet_t spritesheet_0 = {
    .n_metasprites = 4,
    .metasprites = spritesheet_0_metasprites,
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
    .bounds = {
        .left = 0,
        .bottom = 7,
        .right = 15,
        .top = 0
    },    
    .tileset = TO_FAR_PTR_T(tileset_1),
    .cgb_tileset = { NULL, NULL }
};
