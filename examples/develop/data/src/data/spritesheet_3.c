#pragma bank 255

// SpriteSheet: fire

#include "gbs_types.h"
#include "data/spritesheet_3_tiles.h"

const void __at(255) __bank_spritesheet_3;

const metasprite_t spritesheet_3_metasprite_0[]  = {
    {0, 0, 0, 0}, {0, 8, 2, 0}, {metasprite_end}
};

const metasprite_t spritesheet_3_metasprite_1[]  = {
    {0, 0, 4, 0}, {0, 8, 6, 0}, {metasprite_end}
};

const metasprite_t spritesheet_3_metasprite_2[]  = {
    {0, 0, 8,  0}, {0, 8, 10, 0}, {metasprite_end}
};

const metasprite_t spritesheet_3_metasprite_3[]  = {
    {0, 0, 12, 0}, {0, 8, 14, 0}, {metasprite_end}
};

const metasprite_t * const spritesheet_3_metasprites[] = {
    spritesheet_3_metasprite_0,
    spritesheet_3_metasprite_1,
    spritesheet_3_metasprite_2,
    spritesheet_3_metasprite_3,
};

const struct spritesheet_t spritesheet_3 = {
  .n_metasprites = 4,
  .metasprites = spritesheet_3_metasprites,
  .animations  = {
    { .start = 0, .end = 1 }, // bottom
    { .start = 0, .end = 1 }, // right
    { .start = 0, .end = 1 }, // top
    { .start = 0, .end = 1 }, // left
  },  
  .bounds = {
    .left = 0,
    .bottom = 7,
    .right = 15,
    .top = -8
  },
  .tileset = TO_FAR_PTR_T(spritesheet_3_tiles),
  .cgb_tileset = { NULL, NULL },
};
