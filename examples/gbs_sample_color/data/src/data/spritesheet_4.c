#pragma bank 255
// SpriteSheet: fire
  
#include "gbs_types.h"
#include "data/tileset_12.h"

BANKREF(spritesheet_4)

#define SPRITE_4_STATE_DEFAULT 0

const metasprite_t spritesheet_4_metasprite_0[]  = {
    { 0, 8, 0, 0 }, { 0, -8, 2, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_4_metasprite_1[]  = {
    { 0, 8, 4, 0 }, { 0, -8, 6, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_4_metasprite_2[]  = {
    { 0, 8, 8, 0 }, { 0, -8, 10, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_4_metasprite_3[]  = {
    { 0, 8, 12, 0 }, { 0, -8, 14, 0 },
    {metasprite_end}
};

const metasprite_t * const spritesheet_4_metasprites[] = {
    spritesheet_4_metasprite_0,
    spritesheet_4_metasprite_1,
    spritesheet_4_metasprite_2,
    spritesheet_4_metasprite_3
};

const struct animation_t spritesheet_4_animations[] = {
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
};

const UWORD spritesheet_4_animations_lookup[] = {
    SPRITE_4_STATE_DEFAULT
};

const struct spritesheet_t spritesheet_4 = {
    .n_metasprites = 4,
    .metasprites = spritesheet_4_metasprites,
    .animations = spritesheet_4_animations,
    .animations_lookup = spritesheet_4_animations_lookup,
    .bounds = {
        .left = 0,
        .bottom = 7,
        .right = 15,
        .top = -8
    },
    .tileset = TO_FAR_PTR_T(tileset_12),
    .cgb_tileset = { NULL, NULL }
};
