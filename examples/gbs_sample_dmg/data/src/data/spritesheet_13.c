#pragma bank 255
// SpriteSheet: radio
  
#include "gbs_types.h"
#include "data/tileset_19.h"

const void __at(255) __bank_spritesheet_13;

#define SPRITE_13_STATE_DEFAULT 0

const metasprite_t spritesheet_13_metasprite_0[]  = {
    { 0, 8, 0, 0 }, { 0, -8, 2, 0 },
    {metasprite_end}
};

const metasprite_t * const spritesheet_13_metasprites[] = {
    spritesheet_13_metasprite_0
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
    }
};

const UWORD spritesheet_13_animations_lookup[] = {
    SPRITE_13_STATE_DEFAULT
};

const struct spritesheet_t spritesheet_13 = {
    .n_metasprites = 1,
    .metasprites = spritesheet_13_metasprites,
    .animations = spritesheet_13_animations,
    .animations_lookup = spritesheet_13_animations_lookup,
    .bounds = {
        .left = 0,
        .bottom = 7,
        .right = 15,
        .top = -8
    },
    .tileset = TO_FAR_PTR_T(tileset_19),
    .cgb_tileset = { NULL, NULL }
};
