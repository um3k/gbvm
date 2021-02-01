#pragma bank 255

// SpriteSheet: cursor

#include "gbs_types.h"

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
  .n_tiles = 8,
  .n_metasprites = 2,
  .metasprites = spritesheet_13_metasprites,  
  .animations  = {
    // Idle
    { .start = 0, .end = 0 }, // bottom
    { .start = 1, .end = 1 }, // right
  },  
  .tiles = {
    0,0,0,0,0,0,31,31,31,16,31,16,31,16,28,19,26,23,21,29,8,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,192,192,160,96,64,192,128,128,192,64,96,160,48,208,144,240,96,96,0,0,0,0,0,0,0,0,0,0,0,0,16,16,56,40,56,40,56,40,63,47,127,106,245,170,222,161,106,85,93,99,33,63,63,63,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,128,128,128,128,128,128,0,0,0,0,0,0,0,0,0,0
  }
};
