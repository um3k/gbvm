#pragma bank 255
// SpriteSheet: signpost
  
#include "gbs_types.h"
#include "data/tileset_6.h"

BANKREF(spritesheet_5)

#define SPRITE_5_STATE_DEFAULT 0

const metasprite_t spritesheet_5_metasprite_0[]  = {
    { 0, 8, 0, 0 }, { 0, -8, 2, 0 },
    {metasprite_end}
};

const metasprite_t * const spritesheet_5_metasprites[] = {
    spritesheet_5_metasprite_0
};

const struct animation_t spritesheet_5_animations[] = {
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

const UWORD spritesheet_5_animations_lookup[] = {
    SPRITE_5_STATE_DEFAULT
};

const struct spritesheet_t spritesheet_5 = {
    .n_metasprites = 1,
    .emote_origin = {
        .x = 0,
        .y = -16
    },
    .metasprites = spritesheet_5_metasprites,
    .animations = spritesheet_5_animations,
    .animations_lookup = spritesheet_5_animations_lookup,
    .bounds = {
        .left = 0,
        .bottom = 7,
        .right = 15,
        .top = -8
    },
    .tileset = TO_FAR_PTR_T(tileset_6),
    .cgb_tileset = { NULL, NULL }
};
