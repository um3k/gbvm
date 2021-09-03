#pragma bank 255
// SpriteSheet: pod_door
  
#include "gbs_types.h"
#include "data/tileset_39.h"

BANKREF(spritesheet_31)

#define SPRITE_31_STATE_DEFAULT 0

const metasprite_t spritesheet_31_metasprite_0[]  = {
    { 0, 8, 4, 0 }, { 0, -8, 4, 32 },
    {metasprite_end}
};

const metasprite_t spritesheet_31_metasprite_1[]  = {
    { 0, 8, 0, 0 }, { 0, -8, 0, 32 },
    {metasprite_end}
};

const metasprite_t spritesheet_31_metasprite_2[]  = {
    { 0, 8, 2, 0 }, { 0, -8, 2, 32 },
    {metasprite_end}
};

const metasprite_t spritesheet_31_metasprite_3[]  = {
    { 0, 0, 0, 32 }, { 0, 8, 0, 0 },
    {metasprite_end}
};

const metasprite_t * const spritesheet_31_metasprites[] = {
    spritesheet_31_metasprite_0,
    spritesheet_31_metasprite_1,
    spritesheet_31_metasprite_2,
    spritesheet_31_metasprite_3
};

const struct animation_t spritesheet_31_animations[] = {
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
        .start = 3,
        .end = 3
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
        .start = 3,
        .end = 3
    }
};

const UWORD spritesheet_31_animations_lookup[] = {
    SPRITE_31_STATE_DEFAULT
};

const struct spritesheet_t spritesheet_31 = {
    .n_metasprites = 4,
    .metasprites = spritesheet_31_metasprites,
    .animations = spritesheet_31_animations,
    .animations_lookup = spritesheet_31_animations_lookup,
    .bounds = {
        .left = 0,
        .bottom = 7,
        .right = 15,
        .top = -8
    },
    .tileset = TO_FAR_PTR_T(tileset_39),
    .cgb_tileset = { NULL, NULL }
};
