#pragma bank 255
// SpriteSheet: chest
  
#include "gbs_types.h"
#include "data/tileset_23.h"

BANKREF(spritesheet_13)

#define SPRITE_13_STATE_DEFAULT 0
#define SPRITE_13_STATE_OPEN 8

const metasprite_t spritesheet_13_metasprite_0[]  = {
    { 0, 8, 0, 0 }, { 0, -8, 0, 32 },
    {metasprite_end}
};

const metasprite_t spritesheet_13_metasprite_1[]  = {
    { 0, 8, 2, 0 }, { 0, -8, 2, 32 },
    {metasprite_end}
};

const metasprite_t * const spritesheet_13_metasprites[] = {
    spritesheet_13_metasprite_0,
    spritesheet_13_metasprite_1
};

const struct animation_t spritesheet_13_animations[] = {
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
    },
    {
        .start = 1,
        .end = 1
    },
    {
        .start = 1,
        .end = 1
    },
    {
        .start = 1,
        .end = 1
    },
    {
        .start = 1,
        .end = 1
    },
    {
        .start = 1,
        .end = 1
    },
    {
        .start = 1,
        .end = 1
    },
    {
        .start = 1,
        .end = 1
    },
    {
        .start = 1,
        .end = 1
    }
};

const UWORD spritesheet_13_animations_lookup[] = {
    SPRITE_13_STATE_DEFAULT,
    SPRITE_13_STATE_OPEN
};

const struct spritesheet_t spritesheet_13 = {
    .n_metasprites = 2,
    .metasprites = spritesheet_13_metasprites,
    .animations = spritesheet_13_animations,
    .animations_lookup = spritesheet_13_animations_lookup,
    .bounds = {
        .left = 0,
        .bottom = 7,
        .right = 15,
        .top = -8
    },
    .tileset = TO_FAR_PTR_T(tileset_23),
    .cgb_tileset = { NULL, NULL }
};
