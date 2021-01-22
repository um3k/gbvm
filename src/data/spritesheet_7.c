#pragma bank 255

// SpriteSheet: rock

#include "gbs_types.h"

const void __at(255) __bank_spritesheet_7;

const metasprite_t spritesheet_7_metasprite_0  = {
    .count = 2,
    .items = {{0, 0, 0, 0, 0}, {1, 0, 8, 2, 0}, {metasprite_end}}
};

const metasprite_t spritesheet_7_metasprite_1  = {
    .count = 2,
    .items = {{0, 0, 0, 4, 0}, {1, 0, 8, 6, 0}, {metasprite_end}}
};

const metasprite_t spritesheet_7_metasprite_2  = {
    .count = 2,
    .items = {{0, 0, 0, 8,  0}, {1, 0, 8, 10, 0}, {metasprite_end}}
};

const metasprite_t spritesheet_7_metasprite_3  = {
    .count = 2,
    .items = {{0, 0, 0, 12, 0}, {1, 0, 8, 14, 0}, {metasprite_end}}
};

const metasprite_t spritesheet_7_metasprite_4  = {
    .count = 2,
    .items = {{0, 0, 0, 16, 0}, {1, 0, 8, 18, 0}, {metasprite_end}}
};

const metasprite_t spritesheet_7_metasprite_5  = {
    .count = 2,
    .items = {{0, 0, 0, 20, 0}, {1, 0, 8, 22, 0}, {metasprite_end}}
};

const metasprite_t spritesheet_7_metasprite_6  = {
    .count = 2,
    .items = {{0, 0, 0, 18, 32}, {1, 0, 8, 16, 32}, {metasprite_end}}
};

const metasprite_t spritesheet_7_metasprite_7  = {
    .count = 2,
    .items = {{0, 0, 0, 22, 32}, {1, 0, 8, 20, 32}, {metasprite_end}}
};

const metasprite_t * const spritesheet_7_metasprites[] = {
    &spritesheet_7_metasprite_0,
    &spritesheet_7_metasprite_1,
    &spritesheet_7_metasprite_2,
    &spritesheet_7_metasprite_3,
    &spritesheet_7_metasprite_4,
    &spritesheet_7_metasprite_5,
    &spritesheet_7_metasprite_6,
    &spritesheet_7_metasprite_7
};

const struct spritesheet_t spritesheet_7 = {
  .n_tiles = 1,
  .n_metasprites = 6,
  .metasprites = spritesheet_7_metasprites,   
  .tiles = {
    0,0,3,3,12,15,19,28,111,112,159,224,159,224,159,224,191,192,220,227,193,254,100,127,126,127,63,63,31,127,0,63,0,0,240,240,108,156,250,6,253,3,255,1,255,1,255,1,253,3,255,1,255,1,253,3,113,143,2,254,252,255,0,254
  }
};
