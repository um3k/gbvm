#pragma bank 255

// SpriteSheet: fire

#include "gbs_types.h"

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
  .n_tiles = 16,
  .n_metasprites = 6,
  .metasprites = spritesheet_3_metasprites,
  .tiles = {
    0,0,0,0,0,0,0,2,0,4,0,0,2,0,0,0,0,1,0,8,35,0,6,0,6,0,15,0,15,0,15,0,0,0,0,0,0,0,16,0,16,0,0,0,16,0,24,128,24,0,24,128,28,0,28,0,216,0,204,0,252,0,252,0,0,0,0,0,0,0,0,0,32,4,0,0,1,0,0,0,4,1,4,0,12,0,12,0,6,0,7,0,7,0,7,0,0,0,0,0,0,0,8,64,0,128,128,64,132,0,148,0,180,0,60,0,120,0,106,16,114,8,250,0,254,0,254,0,0,0,0,0,0,0,2,8,6,0,0,0,65,4,35,0,51,0,55,0,39,8,7,0,67,0,39,0,31,0,15,0,0,0,0,0,0,0,0,64,4,32,4,0,0,64,0,128,24,64,152,64,144,0,56,0,248,0,248,0,252,0,252,0,0,0,0,0,0,0,0,0,8,0,24,2,16,4,17,0,27,0,15,0,31,0,95,0,59,4,63,0,15,0,15,0,0,0,0,0,0,0,4,0,68,16,192,0,200,0,200,0,156,0,12,0,88,0,178,0,130,0,248,0,252,0,252,0
  }
};
