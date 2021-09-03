#pragma bank 255
// SpriteSheet: checkbox
  
#include "gbs_types.h"
#include "data/tileset_22.h"

BANKREF(spritesheet_16)

#define SPRITE_16_STATE_DEFAULT 0

const metasprite_t spritesheet_16_metasprite_0[]  = {
    { 0, 0, 2, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_16_metasprite_1[]  = {
    {metasprite_end}
};

const metasprite_t spritesheet_16_metasprite_2[]  = {
    { 0, 0, 0, 0 },
    {metasprite_end}
};

const metasprite_t * const spritesheet_16_metasprites[] = {
    spritesheet_16_metasprite_0,
    spritesheet_16_metasprite_1,
    spritesheet_16_metasprite_2
};

const struct animation_t spritesheet_16_animations[] = {
    {
        .start = 0,
        .end = 0
    },
    {
        .start = 1,
        .end = 1
    },
    {
        .start = 2,
        .end = 2
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
        .start = 1,
        .end = 1
    },
    {
        .start = 2,
        .end = 2
    },
    {
        .start = 1,
        .end = 1
    }
};

const UWORD spritesheet_16_animations_lookup[] = {
    SPRITE_16_STATE_DEFAULT
};

const struct spritesheet_t spritesheet_16 = {
    .n_metasprites = 3,
    .metasprites = spritesheet_16_metasprites,
    .animations = spritesheet_16_animations,
    .animations_lookup = spritesheet_16_animations_lookup,
    .bounds = {
        .left = 0,
        .bottom = 7,
        .right = 15,
        .top = -8
    },
    .tileset = TO_FAR_PTR_T(tileset_22),
    .cgb_tileset = { NULL, NULL }
};
