#pragma bank 255
// SpriteSheet: space_mine
  
#include "gbs_types.h"
#include "data/tileset_34.h"

const void __at(255) __bank_spritesheet_26;

#define SPRITE_26_STATE_DEFAULT 0

const metasprite_t spritesheet_26_metasprite_0[]  = {
    { 0, 8, 0, 0 }, { 0, -8, 2, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_26_metasprite_1[]  = {
    { 0, 8, 4, 0 }, { 0, -8, 6, 0 },
    {metasprite_end}
};

const metasprite_t * const spritesheet_26_metasprites[] = {
    spritesheet_26_metasprite_0,
    spritesheet_26_metasprite_1
};

const struct animation_t spritesheet_26_animations[] = {
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

const UWORD spritesheet_26_animations_lookup[] = {
    SPRITE_26_STATE_DEFAULT
};

const struct spritesheet_t spritesheet_26 = {
    .n_metasprites = 2,
    .metasprites = spritesheet_26_metasprites,
    .animations = spritesheet_26_animations,
    .animations_lookup = spritesheet_26_animations_lookup,
    .bounds = {
        .left = 0,
        .bottom = 7,
        .right = 15,
        .top = -8
    },
    .tileset = TO_FAR_PTR_T(tileset_34),
    .cgb_tileset = { NULL, NULL }
};
