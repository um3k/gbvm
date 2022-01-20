#pragma bank 255
// SpriteSheet: npc005
  
#include "gbs_types.h"
#include "data/tileset_40.h"

BANKREF(spritesheet_32)

#define SPRITE_32_STATE_DEFAULT 0

const metasprite_t spritesheet_32_metasprite_0[]  = {
    { 0, 8, 8, 0 }, { 0, -8, 10, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_32_metasprite_1[]  = {
    { 0, 8, 0, 0 }, { 0, -8, 2, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_32_metasprite_2[]  = {
    { 0, 8, 4, 0 }, { 0, -8, 6, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_32_metasprite_3[]  = {
    { 0, 0, 0, 32 }, { 0, 8, 2, 32 },
    {metasprite_end}
};

const metasprite_t spritesheet_32_metasprite_4[]  = {
    { 0, 8, 20, 0 }, { 0, -8, 22, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_32_metasprite_5[]  = {
    { 0, 8, 12, 0 }, { 0, -8, 14, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_32_metasprite_6[]  = {
    { 0, 8, 16, 0 }, { 0, -8, 18, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_32_metasprite_7[]  = {
    { 0, 0, 12, 32 }, { 0, 8, 14, 32 },
    {metasprite_end}
};

const metasprite_t * const spritesheet_32_metasprites[] = {
    spritesheet_32_metasprite_0,
    spritesheet_32_metasprite_1,
    spritesheet_32_metasprite_2,
    spritesheet_32_metasprite_3,
    spritesheet_32_metasprite_4,
    spritesheet_32_metasprite_0,
    spritesheet_32_metasprite_5,
    spritesheet_32_metasprite_1,
    spritesheet_32_metasprite_6,
    spritesheet_32_metasprite_2,
    spritesheet_32_metasprite_7,
    spritesheet_32_metasprite_3
};

const struct animation_t spritesheet_32_animations[] = {
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
        .start = 4,
        .end = 5
    },
    {
        .start = 6,
        .end = 7
    },
    {
        .start = 8,
        .end = 9
    },
    {
        .start = 10,
        .end = 11
    }
};

const UWORD spritesheet_32_animations_lookup[] = {
    SPRITE_32_STATE_DEFAULT
};

const struct spritesheet_t spritesheet_32 = {
    .n_metasprites = 12,
    .emote_origin = {
        .x = 0,
        .y = -16
    },
    .metasprites = spritesheet_32_metasprites,
    .animations = spritesheet_32_animations,
    .animations_lookup = spritesheet_32_animations_lookup,
    .bounds = {
        .left = 0,
        .bottom = 7,
        .right = 15,
        .top = -8
    },
    .tileset = TO_FAR_PTR_T(tileset_40),
    .cgb_tileset = { NULL, NULL }
};
