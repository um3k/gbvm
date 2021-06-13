#pragma bank 255
// SpriteSheet: savepoint
  
#include "gbs_types.h"
#include "data/tileset_15.h"

const void __at(255) __bank_spritesheet_5;

#define SPRITE_5_STATE_DEFAULT 0
#define SPRITE_5_STATE_OPEN 0

const metasprite_t spritesheet_5_metasprite_0[]  = {
    { 0, 8, 0, 0 }, { 0, -8, 0, 32 },
    {metasprite_end}
};

const metasprite_t spritesheet_5_metasprite_1[]  = {
    { 0, 8, 2, 0 }, { 0, -8, 2, 32 },
    {metasprite_end}
};

const metasprite_t * const spritesheet_5_metasprites[] = {
    spritesheet_5_metasprite_0,
    spritesheet_5_metasprite_1
};

const struct animation_t spritesheet_5_animations[] = {
    {
        .start = 0,
        .end = 1
    },
    {
        .start = 0,
        .end = 1
    },
    {
        .start = 0,
        .end = 1
    },
    {
        .start = 0,
        .end = 1
    },
    {
        .start = 0,
        .end = 1
    },
    {
        .start = 0,
        .end = 1
    },
    {
        .start = 0,
        .end = 1
    },
    {
        .start = 0,
        .end = 1
    }
};

const UWORD spritesheet_5_animations_lookup[] = {
    SPRITE_5_STATE_DEFAULT
};

const struct spritesheet_t spritesheet_5 = {
    .n_metasprites = 2,
    .metasprites = spritesheet_5_metasprites,
    .animations = spritesheet_5_animations,
    .animations_lookup = spritesheet_5_animations_lookup,
    .bounds = {
        .left = 0,
        .bottom = 7,
        .right = 15,
        .top = -8
    },
    .tileset = TO_FAR_PTR_T(tileset_15),
    .cgb_tileset = { NULL, NULL }
};
