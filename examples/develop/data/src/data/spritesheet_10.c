#pragma bank 255
// SpriteSheet: cursor
  
#include "gbs_types.h"
#include "data/tileset_20.h"

const void __at(255) __bank_spritesheet_10;

#define SPRITE_10_STATE_DEFAULT 0
#define SPRITE_10_STATE_OPEN 0

const metasprite_t spritesheet_10_metasprite_0[]  = {
    { 0, 8, 0, 0 }, { 0, -8, 2, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_10_metasprite_1[]  = {
    {metasprite_end}
};

const metasprite_t * const spritesheet_10_metasprites[] = {
    spritesheet_10_metasprite_0,
    spritesheet_10_metasprite_1
};

const struct animation_t spritesheet_10_animations[] = {
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
    }
};

const UWORD spritesheet_10_animations_lookup[] = {
    SPRITE_10_STATE_DEFAULT
};

const struct spritesheet_t spritesheet_10 = {
    .n_metasprites = 2,
    .metasprites = spritesheet_10_metasprites,
    .animations = spritesheet_10_animations,
    .animations_lookup = spritesheet_10_animations_lookup,
    .bounds = {
        .left = 0,
        .bottom = 7,
        .right = 15,
        .top = -8
    },
    .tileset = TO_FAR_PTR_T(tileset_20),
    .cgb_tileset = { NULL, NULL }
};
