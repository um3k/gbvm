#pragma bank 255

// SpriteSheet: cursor

#include "gbs_types.h"
#include "data/spritesheet_13_tiles.h"

const void __at(255) __bank_spritesheet_13;

const metasprite_t spritesheet_13_metasprite_0[]  = {
    {0, 0, 0, 0}, {0, 8, 2, 0}, {metasprite_end}
};

const metasprite_t spritesheet_13_metasprite_1[]  = {
    {0, 0, 4, 0}, {0, 8, 6, 0}, {metasprite_end}
};

const metasprite_t * const spritesheet_13_metasprites[] = {
    spritesheet_13_metasprite_0,
    spritesheet_13_metasprite_1,
};

const struct spritesheet_t spritesheet_13 = {
  .n_metasprites = 2,
  .metasprites = spritesheet_13_metasprites,  
  .animations  = {
    // Idle
    { .start = 0, .end = 0 }, // bottom
    { .start = 1, .end = 1 }, // right
  },
  .bounds = {
    .left = 0,
    .bottom = 7,
    .right = 15,
    .top = -8
  },
  .tileset = TO_FAR_PTR_T(spritesheet_13_tiles),
  .cgb_tileset = { NULL, NULL },
};
