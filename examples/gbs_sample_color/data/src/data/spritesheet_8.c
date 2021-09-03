#pragma bank 255
// SpriteSheet: rock
  
#include "gbs_types.h"
#include "data/tileset_16.h"

BANKREF(spritesheet_8)

#define SPRITE_8_STATE_DEFAULT 0

const metasprite_t spritesheet_8_metasprite_0[]  = {
    { 0, 8, 0, 0 }, { 0, -8, 2, 0 },
    {metasprite_end}
};

const metasprite_t * const spritesheet_8_metasprites[] = {
    spritesheet_8_metasprite_0
};

const struct animation_t spritesheet_8_animations[] = {
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

const UWORD spritesheet_8_animations_lookup[] = {
    SPRITE_8_STATE_DEFAULT
};

const struct spritesheet_t spritesheet_8 = {
    .n_metasprites = 1,
    .metasprites = spritesheet_8_metasprites,
    .animations = spritesheet_8_animations,
    .animations_lookup = spritesheet_8_animations_lookup,
    .bounds = {
        .left = 0,
        .bottom = 7,
        .right = 15,
        .top = -8
    },
    .tileset = TO_FAR_PTR_T(tileset_16),
    .cgb_tileset = { NULL, NULL }
};
