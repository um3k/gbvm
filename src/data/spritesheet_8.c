#pragma bank 255

// SpriteSheet: hidden_stairs

#include "gbs_types.h"

const void __at(255) __bank_spritesheet_8;

const metasprite_t spritesheet_8_metasprite_0  = {
    .count = 2,
    .items = {{0, 0, 0, 0}, {0, 8, 2, 0}, {metasprite_end}}
};

const metasprite_t spritesheet_8_metasprite_1  = {
    .count = 2,
    .items = {{0, 0, 4, 0}, {0, 8, 6, 0}, {metasprite_end}}
};

const metasprite_t spritesheet_8_metasprite_2  = {
    .count = 2,
    .items = {{0, 0, 8,  0}, {0, 8, 10, 0}, {metasprite_end}}
};

const metasprite_t spritesheet_8_metasprite_3  = {
    .count = 2,
    .items = {{0, 0, 12, 0}, {0, 8, 14, 0}, {metasprite_end}}
};

const metasprite_t spritesheet_8_metasprite_4  = {
    .count = 2,
    .items = {{0, 0, 16, 0}, {0, 8, 18, 0}, {metasprite_end}}
};

const metasprite_t spritesheet_8_metasprite_5  = {
    .count = 2,
    .items = {{0, 0, 20, 0}, {0, 8, 22, 0}, {metasprite_end}}
};

const metasprite_t spritesheet_8_metasprite_6  = {
    .count = 2,
    .items = {{0, 0, 18, 32}, {0, 8, 16, 32}, {metasprite_end}}
};

const metasprite_t spritesheet_8_metasprite_7  = {
    .count = 2,
    .items = {{0, 0, 22, 32}, {0, 8, 20, 32}, {metasprite_end}}
};

const metasprite_t * const spritesheet_8_metasprites[] = {
    &spritesheet_8_metasprite_0,
    &spritesheet_8_metasprite_1,
    &spritesheet_8_metasprite_2,
    &spritesheet_8_metasprite_3,
    &spritesheet_8_metasprite_4,
    &spritesheet_8_metasprite_5,
    &spritesheet_8_metasprite_6,
    &spritesheet_8_metasprite_7
};

const struct spritesheet_t spritesheet_8 = {
  .n_tiles = 1,
  .n_metasprites = 6,
  .metasprites = spritesheet_8_metasprites,
  .tiles = {
    0,0,0,0,63,63,56,63,61,62,63,63,55,56,59,60,63,63,31,32,47,48,47,48,63,63,0,63,0,0,0,0,0,0,0,0,252,252,28,252,188,124,252,252,236,28,220,60,252,252,248,4,244,12,244,12,252,252,0,252,0,0,0,0
  }
};
