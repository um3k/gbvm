#pragma bank 255
// SpriteSheet: checkbox
  
#include "gbs_types.h"
#include "data/tileset_31.h"

const void __at(255) __bank_spritesheet_23;

#define SPRITE_23_STATE_DEFAULT 0

const metasprite_t spritesheet_23_metasprite_0[]  = {
    { 0, 0, 0, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_23_metasprite_1[]  = {
    { 0, 0, 2, 0 },
    {metasprite_end}
};

const metasprite_t * const spritesheet_23_metasprites[] = {
    spritesheet_23_metasprite_0,
    spritesheet_23_metasprite_1
};

const struct animation_t spritesheet_23_animations[] = {
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

const UWORD spritesheet_23_animations_lookup[] = {
    SPRITE_23_STATE_DEFAULT
};

const struct spritesheet_t spritesheet_23 = {
    .n_metasprites = 2,
    .metasprites = spritesheet_23_metasprites,
    .animations = spritesheet_23_animations,
    .animations_lookup = spritesheet_23_animations_lookup,
    .bounds = {
        .left = 0,
        .bottom = 7,
        .right = 15,
        .top = -8
    },
    .tileset = TO_FAR_PTR_T(tileset_31),
    .cgb_tileset = { NULL, NULL }
};
