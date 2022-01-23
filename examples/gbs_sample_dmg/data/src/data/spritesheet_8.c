#pragma bank 255
// SpriteSheet: fire
  
#include "gbs_types.h"
#include "data/tileset_14.h"

BANKREF(spritesheet_8)

#define SPRITE_8_STATE_DEFAULT 0

const metasprite_t spritesheet_8_metasprite_0[]  = {
    { 0, 8, 0, 0 }, { 0, -8, 2, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_8_metasprite_1[]  = {
    { 0, 8, 4, 0 }, { 0, -8, 6, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_8_metasprite_2[]  = {
    { 0, 8, 8, 0 }, { 0, -8, 10, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_8_metasprite_3[]  = {
    { 0, 8, 12, 0 }, { 0, -8, 14, 0 },
    {metasprite_end}
};

const metasprite_t * const spritesheet_8_metasprites[] = {
    spritesheet_8_metasprite_0,
    spritesheet_8_metasprite_1,
    spritesheet_8_metasprite_2,
    spritesheet_8_metasprite_3
};

const struct animation_t spritesheet_8_animations[] = {
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

const UWORD spritesheet_8_animations_lookup[] = {
    SPRITE_8_STATE_DEFAULT
};

const struct spritesheet_t spritesheet_8 = {
    .n_metasprites = 4,
    .emote_origin = {
        .x = 0,
        .y = -16
    },
    .metasprites = spritesheet_8_metasprites,
    .animations = spritesheet_8_animations,
    .animations_lookup = spritesheet_8_animations_lookup,
    .bounds = {
        .left = 0,
        .bottom = 7,
        .right = 15,
        .top = -8
    },
    .tileset = TO_FAR_PTR_T(tileset_14),
    .cgb_tileset = { NULL, NULL }
};
