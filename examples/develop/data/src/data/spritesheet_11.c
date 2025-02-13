#pragma bank 255
// SpriteSheet: cursor
  
#include "gbs_types.h"
#include "data/tileset_21.h"

BANKREF(spritesheet_11)

#define SPRITE_11_STATE_DEFAULT 0
#define SPRITE_11_STATE_OPEN 0

const metasprite_t spritesheet_11_metasprite_0[]  = {
    { 0, 8, 0, 0 }, { 0, -8, 2, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_11_metasprite_1[]  = {
    {metasprite_end}
};

const metasprite_t * const spritesheet_11_metasprites[] = {
    spritesheet_11_metasprite_0,
    spritesheet_11_metasprite_1
};

const struct animation_t spritesheet_11_animations[] = {
    {
        .start = 0,
        .end = 0
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
        .start = 1,
        .end = 1
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
        .start = 1,
        .end = 1
    },
    {
        .start = 1,
        .end = 1
    }
};

const UWORD spritesheet_11_animations_lookup[] = {
    SPRITE_11_STATE_DEFAULT
};

const struct spritesheet_t spritesheet_11 = {
    .n_metasprites = 2,
    .emote_origin = {
        .x = 0,
        .y = -16
    },
    .metasprites = spritesheet_11_metasprites,
    .animations = spritesheet_11_animations,
    .animations_lookup = spritesheet_11_animations_lookup,
    .bounds = {
        .left = 0,
        .bottom = 7,
        .right = 15,
        .top = -8
    },
    .tileset = TO_FAR_PTR_T(tileset_21),
    .cgb_tileset = { NULL, NULL }
};
