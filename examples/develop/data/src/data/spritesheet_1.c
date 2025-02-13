#pragma bank 255
// SpriteSheet: bullet_directional
  
#include "gbs_types.h"
#include "data/tileset_11.h"

BANKREF(spritesheet_1)

#define SPRITE_1_STATE_DEFAULT 0
#define SPRITE_1_STATE_OPEN 0

const metasprite_t spritesheet_1_metasprite_0[]  = {
    { 0, 8, 8, 64 }, { 0, -8, 10, 64 },
    {metasprite_end}
};

const metasprite_t spritesheet_1_metasprite_1[]  = {
    { 0, 8, 12, 64 }, { 0, -8, 14, 64 },
    {metasprite_end}
};

const metasprite_t spritesheet_1_metasprite_2[]  = {
    { 0, 0, 0, 0 }, { 0, 8, 2, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_1_metasprite_3[]  = {
    { 0, 0, 4, 0 }, { 0, 8, 6, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_1_metasprite_4[]  = {
    { 0, 8, 8, 0 }, { 0, -8, 10, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_1_metasprite_5[]  = {
    { 0, 8, 12, 0 }, { 0, -8, 14, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_1_metasprite_6[]  = {
    { 0, 8, 0, 32 }, { 0, -8, 2, 32 },
    {metasprite_end}
};

const metasprite_t spritesheet_1_metasprite_7[]  = {
    { 0, 8, 4, 32 }, { 0, -8, 6, 32 },
    {metasprite_end}
};

const metasprite_t * const spritesheet_1_metasprites[] = {
    spritesheet_1_metasprite_0,
    spritesheet_1_metasprite_1,
    spritesheet_1_metasprite_2,
    spritesheet_1_metasprite_3,
    spritesheet_1_metasprite_4,
    spritesheet_1_metasprite_5,
    spritesheet_1_metasprite_6,
    spritesheet_1_metasprite_7
};

const struct animation_t spritesheet_1_animations[] = {
    {
        .start = 0,
        .end = 1
    },
    {
        .start = 2,
        .end = 3
    },
    {
        .start = 4,
        .end = 5
    },
    {
        .start = 6,
        .end = 7
    },
    {
        .start = 0,
        .end = 1
    },
    {
        .start = 2,
        .end = 3
    },
    {
        .start = 4,
        .end = 5
    },
    {
        .start = 6,
        .end = 7
    }
};

const UWORD spritesheet_1_animations_lookup[] = {
    SPRITE_1_STATE_DEFAULT
};

const struct spritesheet_t spritesheet_1 = {
    .n_metasprites = 8,
    .emote_origin = {
        .x = 0,
        .y = -16
    },
    .metasprites = spritesheet_1_metasprites,
    .animations = spritesheet_1_animations,
    .animations_lookup = spritesheet_1_animations_lookup,
    .bounds = {
        .left = 0,
        .bottom = 7,
        .right = 15,
        .top = -8
    },
    .tileset = TO_FAR_PTR_T(tileset_11),
    .cgb_tileset = { NULL, NULL }
};
