#pragma bank 255
// SpriteSheet: savepoint
  
#include "gbs_types.h"
#include "data/tileset_16.h"

BANKREF(spritesheet_6)

#define SPRITE_6_STATE_DEFAULT 0
#define SPRITE_6_STATE_OPEN 0

const metasprite_t spritesheet_6_metasprite_0[]  = {
    { 0, 8, 0, 0 }, { 0, -8, 0, 32 },
    {metasprite_end}
};

const metasprite_t spritesheet_6_metasprite_1[]  = {
    { 0, 8, 2, 0 }, { 0, -8, 2, 32 },
    {metasprite_end}
};

const metasprite_t * const spritesheet_6_metasprites[] = {
    spritesheet_6_metasprite_0,
    spritesheet_6_metasprite_1
};

const struct animation_t spritesheet_6_animations[] = {
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

const UWORD spritesheet_6_animations_lookup[] = {
    SPRITE_6_STATE_DEFAULT
};

const struct spritesheet_t spritesheet_6 = {
    .n_metasprites = 2,
    .metasprites = spritesheet_6_metasprites,
    .animations = spritesheet_6_animations,
    .animations_lookup = spritesheet_6_animations_lookup,
    .bounds = {
        .left = 0,
        .bottom = 7,
        .right = 15,
        .top = -8
    },
    .tileset = TO_FAR_PTR_T(tileset_16),
    .cgb_tileset = { NULL, NULL }
};
