#pragma bank 255
// SpriteSheet: 6-colors
  
#include "gbs_types.h"
#include "data/tileset_2.h"

BANKREF(spritesheet_0)

#define SPRITE_0_STATE_DEFAULT 0

const metasprite_t spritesheet_0_metasprite_0[]  = {
    { -16, 8, 0, 7 }, { 0, -8, 2, 7 }, { 0, 8, 4, 6 }, { 0, -8, 6, 6 }, { 16, 8, 8, 7 }, { 0, -8, 8, 39 }, { 0, 8, 10, 6 }, { 0, -8, 10, 38 },
    {metasprite_end}
};

const metasprite_t spritesheet_0_metasprite_1[]  = {
    { 0, 8, 12, 7 }, { -16, 0, 14, 7 }, { 16, -8, 16, 7 }, { -16, 0, 18, 7 }, { 16, 8, 20, 6 }, { -16, 0, 22, 6 }, { 16, -8, 24, 6 }, { -16, 0, 26, 6 },
    {metasprite_end}
};

const metasprite_t spritesheet_0_metasprite_2[]  = {
    { 0, 8, 8, 7 }, { -16, 0, 0, 7 }, { 16, -8, 8, 39 }, { -16, 0, 2, 7 }, { 16, 8, 10, 6 }, { -16, 0, 4, 6 }, { 16, -8, 10, 38 }, { -16, 0, 6, 6 },
    {metasprite_end}
};

const metasprite_t spritesheet_0_metasprite_3[]  = {
    { 0, 0, 12, 39 }, { 0, 8, 16, 39 }, { 0, -8, 20, 38 }, { 0, 8, 24, 38 }, { -16, 0, 14, 7 }, { 0, -8, 18, 7 }, { 0, 8, 22, 6 }, { 0, -8, 26, 6 },
    {metasprite_end}
};

const metasprite_t * const spritesheet_0_metasprites[] = {
    spritesheet_0_metasprite_0,
    spritesheet_0_metasprite_1,
    spritesheet_0_metasprite_2,
    spritesheet_0_metasprite_3
};

const struct animation_t spritesheet_0_animations[] = {
    {
        .start = 0,
        .end = 3
    },
    {
        .start = 0,
        .end = 3
    },
    {
        .start = 0,
        .end = 3
    },
    {
        .start = 0,
        .end = 3
    },
    {
        .start = 0,
        .end = 3
    },
    {
        .start = 0,
        .end = 3
    },
    {
        .start = 0,
        .end = 3
    },
    {
        .start = 0,
        .end = 3
    }
};

const UWORD spritesheet_0_animations_lookup[] = {
    SPRITE_0_STATE_DEFAULT
};

const struct spritesheet_t spritesheet_0 = {
    .n_metasprites = 4,
    .emote_origin = {
        .x = 0,
        .y = -32
    },
    .metasprites = spritesheet_0_metasprites,
    .animations = spritesheet_0_animations,
    .animations_lookup = spritesheet_0_animations_lookup,
    .bounds = {
        .left = 0,
        .bottom = -1,
        .right = 15,
        .top = -8
    },
    .tileset = TO_FAR_PTR_T(tileset_2),
    .cgb_tileset = { NULL, NULL }
};
