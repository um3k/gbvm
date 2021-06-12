#pragma bank 255
// SpriteSheet: npc002
  
#include "gbs_types.h"
#include "data/tileset_27.h"

const void __at(255) __bank_spritesheet_19;

#define SPRITE_19_STATE_DEFAULT 0

const metasprite_t spritesheet_19_metasprite_0[]  = {
    { 0, 8, 8, 0 }, { 0, -8, 10, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_19_metasprite_1[]  = {
    { 0, 8, 0, 0 }, { 0, -8, 2, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_19_metasprite_2[]  = {
    { 0, 8, 4, 0 }, { 0, -8, 6, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_19_metasprite_3[]  = {
    { 0, 0, 0, 32 }, { 0, 8, 2, 32 },
    {metasprite_end}
};

const metasprite_t * const spritesheet_19_metasprites[] = {
    spritesheet_19_metasprite_0,
    spritesheet_19_metasprite_1,
    spritesheet_19_metasprite_2,
    spritesheet_19_metasprite_3
};

const struct animation_t spritesheet_19_animations[] = {
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

const UWORD spritesheet_19_animations_lookup[] = {
    SPRITE_19_STATE_DEFAULT
};

const struct spritesheet_t spritesheet_19 = {
    .n_metasprites = 4,
    .metasprites = spritesheet_19_metasprites,
    .animations = spritesheet_19_animations,
    .animations_lookup = spritesheet_19_animations_lookup,
    .bounds = {
        .left = 0,
        .bottom = 7,
        .right = 15,
        .top = -8
    },
    .tileset = TO_FAR_PTR_T(tileset_27),
    .cgb_tileset = { NULL, NULL }
};
