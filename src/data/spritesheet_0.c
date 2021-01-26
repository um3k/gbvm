#pragma bank 255

// SpriteSheet: player

#include "gbs_types.h"

const void __at(255) __bank_spritesheet_0;

const metasprite_t spritesheet_0_metasprite_0[]  = {
    {0, 0, 0, 0}, {0, 8, 2, 0}, {metasprite_end}
};

const metasprite_t spritesheet_0_metasprite_1[]  = {
    {0, 0, 4, 0}, {0, 8, 6, 0}, {metasprite_end}
};

const metasprite_t spritesheet_0_metasprite_2[]  = {
    {0, 0, 8,  0}, {0, 8, 10, 0}, {metasprite_end}
};

const metasprite_t spritesheet_0_metasprite_3[]  = {
    {0, 0, 12, 0}, {0, 8, 14, 0}, {metasprite_end}
};

const metasprite_t spritesheet_0_metasprite_4[]  = {
    {0, 0, 16, 0}, {0, 8, 18, 0}, {metasprite_end}
};

const metasprite_t spritesheet_0_metasprite_5[]  = {
    {0, 0, 20, 0}, {0, 8, 22, 0}, {metasprite_end}
};

const metasprite_t spritesheet_0_metasprite_6[]  = {
    {0, 0, 18, 32}, {0, 8, 16, 32}, {metasprite_end}
};

const metasprite_t spritesheet_0_metasprite_7[]  = {
    {0, 0, 22, 32}, {0, 8, 20, 32}, {metasprite_end}
};

const metasprite_t * const spritesheet_0_metasprites[] = {
    spritesheet_0_metasprite_0,
    spritesheet_0_metasprite_1,
    spritesheet_0_metasprite_2,
    spritesheet_0_metasprite_3,
    spritesheet_0_metasprite_4,
    spritesheet_0_metasprite_5,
    spritesheet_0_metasprite_6,
    spritesheet_0_metasprite_7
};

const struct spritesheet_t spritesheet_0 = {
    .n_tiles = 24,
    .n_metasprites = 6,
    .metasprites = spritesheet_0_metasprites,
    .tiles = {
      0,0,7,7,8,15,16,31,61,35,34,63,45,62,43,60,43,62,47,58,63,44,111,95,127,127,57,63,29,27,14,14,
      0,0,224,224,16,240,56,200,92,164,172,212,66,254,190,126,212,124,244,92,244,60,250,254,60,228,
      252,228,248,248,112,112,0,0,7,7,8,15,16,31,61,35,34,63,45,62,43,60,43,62,47,58,63,44,111,95,
      124,127,63,39,31,31,14,14,0,0,224,224,16,240,56,200,92,164,172,212,66,254,190,126,212,124,244,
      92,244,60,242,254,254,254,156,252,184,216,112,112,0,0,7,7,8,15,22,25,33,62,96,127,32,63,32,63,
      41,54,41,54,41,54,85,106,126,125,63,39,31,31,0,0,0,0,224,224,16,240,104,152,132,124,4,252,4,252,
      4,252,36,220,36,220,36,220,162,222,158,254,248,248,176,208,112,112,0,0,7,7,8,15,22,25,33,62,32,
      63,96,127,32,63,41,54,41,54,41,54,85,106,126,125,63,63,13,11,14,14,0,0,224,224,16,240,104,152,
      132,124,4,252,4,252,4,252,36,220,36,220,36,220,162,222,158,254,252,228,248,248,0,0,0,0,3,3,12,
      15,22,25,42,55,36,63,41,62,39,63,34,63,51,46,51,47,124,71,57,63,31,19,15,15,6,6,0,0,240,240,56,
      200,12,244,98,190,210,126,172,220,56,200,248,40,252,36,248,8,240,240,48,208,248,232,92,100,56,
      56,0,0,3,3,12,15,22,25,42,55,36,63,41,62,39,63,34,63,51,46,49,47,126,67,62,63,55,63,23,25,14,
      14,0,0,240,240,56,200,12,244,98,190,210,126,172,220,56,200,248,40,252,36,248,8,240,240,80,240,
      252,60,252,252,48,48
    }
};
