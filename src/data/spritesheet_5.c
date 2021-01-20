#pragma bank 255

// SpriteSheet: savepoint

#include "gbs_types.h"

const void __at(255) __bank_spritesheet_5;

const metasprite_t spritesheet_5_metasprite_0  = {
    .count = 2,
    .items = {{0, 0, 0, 0, 0}, {1, 0, 8, 2, 0}, {metasprite_end}}
};

const metasprite_t spritesheet_5_metasprite_1  = {
    .count = 2,
    .items = {{0, 0, 0, 4, 0}, {1, 0, 8, 6, 0}, {metasprite_end}}
};

const metasprite_t spritesheet_5_metasprite_2  = {
    .count = 2,
    .items = {{0, 0, 0, 8,  0}, {1, 0, 8, 10, 0}, {metasprite_end}}
};

const metasprite_t spritesheet_5_metasprite_3  = {
    .count = 2,
    .items = {{0, 0, 0, 12, 0}, {1, 0, 8, 14, 0}, {metasprite_end}}
};

const metasprite_t spritesheet_5_metasprite_4  = {
    .count = 2,
    .items = {{0, 0, 0, 16, 0}, {1, 0, 8, 18, 0}, {metasprite_end}}
};

const metasprite_t spritesheet_5_metasprite_5  = {
    .count = 2,
    .items = {{0, 0, 0, 20, 0}, {1, 0, 8, 22, 0}, {metasprite_end}}
};

const metasprite_t spritesheet_5_metasprite_6  = {
    .count = 2,
    .items = {{0, 0, 0, 18, 32}, {1, 0, 8, 16, 32}, {metasprite_end}}
};

const metasprite_t spritesheet_5_metasprite_7  = {
    .count = 2,
    .items = {{0, 0, 0, 22, 32}, {1, 0, 8, 20, 32}, {metasprite_end}}
};

const metasprite_t *spritesheet_5_metasprites[] = {
    &spritesheet_5_metasprite_0,
    &spritesheet_5_metasprite_1,
    &spritesheet_5_metasprite_2,
    &spritesheet_5_metasprite_3,
    &spritesheet_5_metasprite_4,
    &spritesheet_5_metasprite_5,
    &spritesheet_5_metasprite_6,
    &spritesheet_5_metasprite_7
};

const struct spritesheet_t spritesheet_5 = {
  .n_tiles = 2,
  .n_metasprites = 6,
  .metasprites = &spritesheet_5_metasprites,
  .tiles = {
    1,1,3,2,5,6,9,14,25,22,23,24,9,14,9,14,5,6,5,6,3,2,3,2,1,1,1,3,0,15,0,3,128,128,192,64,160,96,144,112,152,104,232,24,144,112,144,112,160,96,160,96,192,64,192,64,128,128,128,192,0,240,0,192,0,0,1,1,3,2,5,6,9,14,25,22,23,24,9,14,9,14,5,6,5,6,3,2,3,2,1,3,1,15,0,3,0,0,128,128,192,64,160,96,144,112,152,104,232,24,144,112,144,112,160,96,160,96,192,64,192,64,128,192,128,240,0,192
  }
};
