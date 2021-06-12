#pragma bank 255
// SpriteSheet: portal
  
#include "gbs_types.h"
#include "data/tileset_38.h"

const void __at(255) __bank_spritesheet_30;

#define SPRITE_30_STATE_DEFAULT 0

const metasprite_t spritesheet_30_metasprite_0[]  = {
    { 0, 8, 8, 0 }, { 0, -8, 10, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_30_metasprite_1[]  = {
    { 0, 8, 0, 0 }, { 0, -8, 2, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_30_metasprite_2[]  = {
    { 0, 8, 4, 0 }, { 0, -8, 6, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_30_metasprite_3[]  = {
    { 0, 0, 0, 32 }, { 0, 8, 2, 32 },
    {metasprite_end}
};

const metasprite_t * const spritesheet_30_metasprites[] = {
    spritesheet_30_metasprite_0,
    spritesheet_30_metasprite_1,
    spritesheet_30_metasprite_2,
    spritesheet_30_metasprite_3
};

const struct animation_t spritesheet_30_animations[] = {
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
};

const UWORD spritesheet_30_animations_lookup[] = {
    SPRITE_30_STATE_DEFAULT
};

const struct spritesheet_t spritesheet_30 = {
    .n_metasprites = 4,
    .metasprites = spritesheet_30_metasprites,
    .animations = spritesheet_30_animations,
    .animations_lookup = spritesheet_30_animations_lookup,
    .bounds = {
        .left = 0,
        .bottom = 7,
        .right = 15,
        .top = -8
    },
    .tileset = TO_FAR_PTR_T(tileset_38),
    .cgb_tileset = { NULL, NULL }
};
