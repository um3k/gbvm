#pragma bank 255
// SpriteSheet: machine
  
#include "gbs_types.h"
#include "data/tileset_41.h"

const void __at(255) __bank_spritesheet_33;

#define SPRITE_33_STATE_DEFAULT 0

const metasprite_t spritesheet_33_metasprite_0[]  = {
    { 0, 8, 0, 0 }, { 0, -8, 2, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_33_metasprite_1[]  = {
    { 0, 8, 4, 0 }, { 0, -8, 6, 0 },
    {metasprite_end}
};

const metasprite_t * const spritesheet_33_metasprites[] = {
    spritesheet_33_metasprite_0,
    spritesheet_33_metasprite_1
};

const struct animation_t spritesheet_33_animations[] = {
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

const UWORD spritesheet_33_animations_lookup[] = {
    SPRITE_33_STATE_DEFAULT
};

const struct spritesheet_t spritesheet_33 = {
    .n_metasprites = 2,
    .metasprites = spritesheet_33_metasprites,
    .animations = spritesheet_33_animations,
    .animations_lookup = spritesheet_33_animations_lookup,
    .bounds = {
        .left = 0,
        .bottom = 7,
        .right = 15,
        .top = -8
    },
    .tileset = TO_FAR_PTR_T(tileset_41),
    .cgb_tileset = { NULL, NULL }
};
