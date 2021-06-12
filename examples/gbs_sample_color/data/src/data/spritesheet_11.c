#pragma bank 255
// SpriteSheet: cat
  
#include "gbs_types.h"
#include "data/tileset_19.h"

const void __at(255) __bank_spritesheet_11;

#define SPRITE_11_STATE_DEFAULT 0

const metasprite_t spritesheet_11_metasprite_0[]  = {
    { 0, 8, 0, 0 }, { 0, -8, 2, 0 },
    {metasprite_end}
};

const metasprite_t * const spritesheet_11_metasprites[] = {
    spritesheet_11_metasprite_0
};

const struct animation_t spritesheet_11_animations[] = {
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
    }
};

const UWORD spritesheet_11_animations_lookup[] = {
    SPRITE_11_STATE_DEFAULT
};

const struct spritesheet_t spritesheet_11 = {
    .n_metasprites = 1,
    .metasprites = spritesheet_11_metasprites,
    .animations = spritesheet_11_animations,
    .animations_lookup = spritesheet_11_animations_lookup,
    .bounds = {
        .left = 0,
        .bottom = 7,
        .right = 15,
        .top = -8
    },
    .tileset = TO_FAR_PTR_T(tileset_19),
    .cgb_tileset = { NULL, NULL }
};
