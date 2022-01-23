#pragma bank 255
// SpriteSheet: player
  
#include "gbs_types.h"
#include "data/tileset_1.h"

BANKREF(spritesheet_0)

#define SPRITE_0_STATE_DEFAULT 0
#define SPRITE_0_STATE_IN_GRASS 8
#define SPRITE_0_STATE_SURPRISED 16

const metasprite_t spritesheet_0_metasprite_0[]  = {
    { 0, 8, 8, 0 }, { 0, -8, 10, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_0_metasprite_1[]  = {
    { 0, 8, 0, 0 }, { 0, -8, 2, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_0_metasprite_2[]  = {
    { 0, 8, 4, 0 }, { 0, -8, 6, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_0_metasprite_3[]  = {
    { 0, 0, 0, 32 }, { 0, 8, 2, 32 },
    {metasprite_end}
};

const metasprite_t spritesheet_0_metasprite_4[]  = {
    { 0, 8, 20, 0 }, { 0, -8, 22, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_0_metasprite_5[]  = {
    { 0, 8, 12, 0 }, { 0, -8, 14, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_0_metasprite_6[]  = {
    { 0, 8, 16, 0 }, { 0, -8, 18, 0 },
    {metasprite_end}
};

const metasprite_t spritesheet_0_metasprite_7[]  = {
    { 0, 0, 12, 32 }, { 0, 8, 14, 32 },
    {metasprite_end}
};

const metasprite_t spritesheet_0_metasprite_8[]  = {
    { 0, 8, 28, 0 }, { 0, -8, 30, 0 }, { 0, 8, 8, 128 }, { 0, -8, 10, 128 },
    {metasprite_end}
};

const metasprite_t spritesheet_0_metasprite_9[]  = {
    { 0, 8, 24, 0 }, { 0, -8, 26, 0 }, { 0, 8, 0, 128 }, { 0, -8, 2, 128 },
    {metasprite_end}
};

const metasprite_t spritesheet_0_metasprite_10[]  = {
    { 0, 0, 24, 32 }, { 0, 8, 26, 32 }, { 0, -8, 0, 160 }, { 0, 8, 2, 160 },
    {metasprite_end}
};

const metasprite_t spritesheet_0_metasprite_11[]  = {
    { 0, 8, 28, 0 }, { 0, -8, 30, 0 }, { 0, 8, 20, 128 }, { 0, -8, 22, 128 },
    {metasprite_end}
};

const metasprite_t spritesheet_0_metasprite_12[]  = {
    { 0, 8, 24, 0 }, { 0, -8, 26, 0 }, { 0, 8, 12, 128 }, { 0, -8, 14, 128 },
    {metasprite_end}
};

const metasprite_t spritesheet_0_metasprite_13[]  = {
    { 0, 8, 32, 0 }, { 0, -8, 34, 0 }, { 0, 8, 4, 128 }, { 0, -8, 6, 128 },
    {metasprite_end}
};

const metasprite_t spritesheet_0_metasprite_14[]  = {
    { 0, 8, 32, 0 }, { 0, -8, 34, 0 }, { 0, 8, 16, 128 }, { 0, -8, 18, 128 },
    {metasprite_end}
};

const metasprite_t spritesheet_0_metasprite_15[]  = {
    { 0, 0, 24, 32 }, { 0, 8, 26, 32 }, { 0, -8, 12, 160 }, { 0, 8, 14, 160 },
    {metasprite_end}
};

const metasprite_t spritesheet_0_metasprite_16[]  = {
    { 0, 8, 36, 0 }, { 0, -8, 36, 32 }, { 0, 8, 8, 0 }, { 0, -8, 10, 0 },
    {metasprite_end}
};

const metasprite_t * const spritesheet_0_metasprites[] = {
    spritesheet_0_metasprite_0,
    spritesheet_0_metasprite_1,
    spritesheet_0_metasprite_2,
    spritesheet_0_metasprite_3,
    spritesheet_0_metasprite_0,
    spritesheet_0_metasprite_4,
    spritesheet_0_metasprite_1,
    spritesheet_0_metasprite_5,
    spritesheet_0_metasprite_2,
    spritesheet_0_metasprite_6,
    spritesheet_0_metasprite_3,
    spritesheet_0_metasprite_7,
    spritesheet_0_metasprite_8,
    spritesheet_0_metasprite_9,
    spritesheet_0_metasprite_10,
    spritesheet_0_metasprite_8,
    spritesheet_0_metasprite_11,
    spritesheet_0_metasprite_9,
    spritesheet_0_metasprite_12,
    spritesheet_0_metasprite_13,
    spritesheet_0_metasprite_14,
    spritesheet_0_metasprite_10,
    spritesheet_0_metasprite_15,
    spritesheet_0_metasprite_16
};

const struct animation_t spritesheet_0_animations[] = {
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
    },
    {
        .start = 12,
        .end = 12
    },
    {
        .start = 13,
        .end = 13
    },
    {
        .start = 2,
        .end = 2
    },
    {
        .start = 14,
        .end = 14
    },
    {
        .start = 15,
        .end = 16
    },
    {
        .start = 17,
        .end = 18
    },
    {
        .start = 19,
        .end = 20
    },
    {
        .start = 21,
        .end = 22
    },
    {
        .start = 23,
        .end = 23
    },
    {
        .start = 23,
        .end = 23
    },
    {
        .start = 23,
        .end = 23
    },
    {
        .start = 23,
        .end = 23
    },
    {
        .start = 23,
        .end = 23
    },
    {
        .start = 23,
        .end = 23
    },
    {
        .start = 23,
        .end = 23
    },
    {
        .start = 23,
        .end = 23
    }
};

const UWORD spritesheet_0_animations_lookup[] = {
    SPRITE_0_STATE_DEFAULT,
    SPRITE_0_STATE_IN_GRASS,
    SPRITE_0_STATE_SURPRISED
};

const struct spritesheet_t spritesheet_0 = {
    .n_metasprites = 24,
    .emote_origin = {
        .x = 0,
        .y = -32
    },
    .metasprites = spritesheet_0_metasprites,
    .animations = spritesheet_0_animations,
    .animations_lookup = spritesheet_0_animations_lookup,
    .bounds = {
        .left = 0,
        .bottom = 7,
        .right = 15,
        .top = 0
    },
    .tileset = TO_FAR_PTR_T(tileset_1),
    .cgb_tileset = { NULL, NULL }
};
