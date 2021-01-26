#pragma bank 255

// SpriteSheet: ice

#include "gbs_types.h"

const void __at(255) __bank_spritesheet_1;

const metasprite_t spritesheet_1_metasprite_0[]  = {
    {0, 0, 0, 0}, {0, 8, 2, 0}, {metasprite_end}
};

const metasprite_t spritesheet_1_metasprite_1[]  = {
    {0, 0, 4, 0}, {0, 8, 6, 0}, {metasprite_end}
};

const metasprite_t spritesheet_1_metasprite_2[]  = {
    {0, 0, 8,  0}, {0, 8, 10, 0}, {metasprite_end}
};

const metasprite_t spritesheet_1_metasprite_3[]  = {
    {0, 0, 12, 0}, {0, 8, 14, 0}, {metasprite_end}
};

const metasprite_t spritesheet_1_metasprite_4[]  = {
    {0, 0, 16, 0}, {0, 8, 18, 0}, {metasprite_end}
};

const metasprite_t spritesheet_1_metasprite_5[]  = {
    {0, 0, 20, 0}, {0, 8, 22, 0}, {metasprite_end}
};

const metasprite_t spritesheet_1_metasprite_6[]  = {
    {0, 0, 18, 32}, {0, 8, 16, 32}, {metasprite_end}
};

const metasprite_t spritesheet_1_metasprite_7[]  = {
    {0, 0, 22, 32}, {0, 8, 20, 32}, {metasprite_end}
};

const metasprite_t * const spritesheet_1_metasprites[] = {
    spritesheet_1_metasprite_0,
    spritesheet_1_metasprite_1,
    spritesheet_1_metasprite_2,
    spritesheet_1_metasprite_3,
    spritesheet_1_metasprite_4,
    spritesheet_1_metasprite_5,
    spritesheet_1_metasprite_6,
    spritesheet_1_metasprite_7
};

const struct spritesheet_t spritesheet_1 = {
  .n_tiles = 4,
  .n_metasprites = 6,
  .metasprites = spritesheet_1_metasprites,
  .tiles = {
    127,127,255,128,255,128,252,130,217,164,178,201,229,146,202,165,148,202,169,148,211,168,166,209,205,162,154,196,127,255,0,127,
    254,254,255,1,255,1,167,81,79,161,159,65,55,137,111,17,215,33,167,73,79,145,159,33,55,73,111,145,254,255,0,254
  }
};
