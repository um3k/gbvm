#pragma bank 255
// SpriteSheet: ice
  
#include "gbs_types.h"
#include "data/tileset_29.h"

BANKREF(spritesheet_21)

#define SPRITE_21_STATE_DEFAULT 0

const metasprite_t spritesheet_21_metasprite_0[]  = {
    { 0, 8, 0, 0 }, { 0, -8, 2, 0 },
    {metasprite_end}
};

const metasprite_t * const spritesheet_21_metasprites[] = {
    spritesheet_21_metasprite_0
};

const struct animation_t spritesheet_21_animations[] = {
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

const UWORD spritesheet_21_animations_lookup[] = {
    SPRITE_21_STATE_DEFAULT
};

const struct spritesheet_t spritesheet_21 = {
    .n_metasprites = 1,
    .metasprites = spritesheet_21_metasprites,
    .animations = spritesheet_21_animations,
    .animations_lookup = spritesheet_21_animations_lookup,
    .bounds = {
        .left = 0,
        .bottom = 7,
        .right = 15,
        .top = -8
    },
    .tileset = TO_FAR_PTR_T(tileset_29),
    .cgb_tileset = { NULL, NULL }
};
