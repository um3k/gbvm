#pragma bank 255
// SpriteSheet: duck
  
#include "gbs_types.h"
#include "data/tileset_9.h"

BANKREF(spritesheet_3)

#define SPRITE_3_STATE_DEFAULT 0

const metasprite_t spritesheet_3_metasprite_0[]  = {
    { 0, 8, 0, 0 }, { 0, -8, 2, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_3_metasprite_1[]  = {
    { 0, 8, 4, 0 }, { 0, -8, 6, 0 },
    {metasprite_end}
};

const metasprite_t * const spritesheet_3_metasprites[] = {
    spritesheet_3_metasprite_0,
    spritesheet_3_metasprite_1
};

const struct animation_t spritesheet_3_animations[] = {
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

const UWORD spritesheet_3_animations_lookup[] = {
    SPRITE_3_STATE_DEFAULT
};

const struct spritesheet_t spritesheet_3 = {
    .n_metasprites = 2,
    .emote_origin = {
        .x = 0,
        .y = -16
    },
    .metasprites = spritesheet_3_metasprites,
    .animations = spritesheet_3_animations,
    .animations_lookup = spritesheet_3_animations_lookup,
    .bounds = {
        .left = 0,
        .bottom = 7,
        .right = 15,
        .top = -8
    },
    .tileset = TO_FAR_PTR_T(tileset_9),
    .cgb_tileset = { NULL, NULL }
};
