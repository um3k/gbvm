#pragma bank 255
// SpriteSheet: sage
  
#include "gbs_types.h"
#include "data/tileset_25.h"

BANKREF(spritesheet_17)

#define SPRITE_17_STATE_DEFAULT 0

const metasprite_t spritesheet_17_metasprite_0[]  = {
    { 0, 8, 0, 0 }, { 0, -8, 2, 0 },
    {metasprite_end}
};

const metasprite_t * const spritesheet_17_metasprites[] = {
    spritesheet_17_metasprite_0
};

const struct animation_t spritesheet_17_animations[] = {
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

const UWORD spritesheet_17_animations_lookup[] = {
    SPRITE_17_STATE_DEFAULT
};

const struct spritesheet_t spritesheet_17 = {
    .n_metasprites = 1,
    .metasprites = spritesheet_17_metasprites,
    .animations = spritesheet_17_animations,
    .animations_lookup = spritesheet_17_animations_lookup,
    .bounds = {
        .left = 0,
        .bottom = 7,
        .right = 15,
        .top = -8
    },
    .tileset = TO_FAR_PTR_T(tileset_25),
    .cgb_tileset = { NULL, NULL }
};
