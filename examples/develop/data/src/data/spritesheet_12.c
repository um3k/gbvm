#pragma bank 255
// SpriteSheet: turnip
  
#include "gbs_types.h"
#include "data/tileset_22.h"

BANKREF(spritesheet_12)

#define SPRITE_12_STATE_DEFAULT 0
#define SPRITE_12_STATE_OPEN 0

const metasprite_t spritesheet_12_metasprite_0[]  = {
    { 0, 8, 0, 0 }, { 0, -8, 2, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_12_metasprite_1[]  = {
    { 0, 8, 4, 0 }, { 0, -8, 6, 0 },
    {metasprite_end}
};

const metasprite_t * const spritesheet_12_metasprites[] = {
    spritesheet_12_metasprite_0,
    spritesheet_12_metasprite_1
};

const struct animation_t spritesheet_12_animations[] = {
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

const UWORD spritesheet_12_animations_lookup[] = {
    SPRITE_12_STATE_DEFAULT
};

const struct spritesheet_t spritesheet_12 = {
    .n_metasprites = 2,
    .metasprites = spritesheet_12_metasprites,
    .animations = spritesheet_12_animations,
    .animations_lookup = spritesheet_12_animations_lookup,
    .bounds = {
        .left = 0,
        .bottom = 7,
        .right = 15,
        .top = -8
    },
    .tileset = TO_FAR_PTR_T(tileset_22),
    .cgb_tileset = { NULL, NULL }
};
