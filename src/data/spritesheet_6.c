#pragma bank 255

// SpriteSheet: signpost

#include "gbs_types.h"

const void __at(255) __bank_spritesheet_6;

const metasprite_t spritesheet_6_metasprite_0  = {
    .count = 2,
    .items = {{0, 0, 0, 0, 0}, {1, 0, 8, 2, 0}, {metasprite_end}}
};

const metasprite_t spritesheet_6_metasprite_1  = {
    .count = 2,
    .items = {{0, 0, 0, 4, 0}, {1, 0, 8, 6, 0}, {metasprite_end}}
};

const metasprite_t spritesheet_6_metasprite_2  = {
    .count = 2,
    .items = {{0, 0, 0, 8,  0}, {1, 0, 8, 10, 0}, {metasprite_end}}
};

const metasprite_t spritesheet_6_metasprite_3  = {
    .count = 2,
    .items = {{0, 0, 0, 12, 0}, {1, 0, 8, 14, 0}, {metasprite_end}}
};

const metasprite_t spritesheet_6_metasprite_4  = {
    .count = 2,
    .items = {{0, 0, 0, 16, 0}, {1, 0, 8, 18, 0}, {metasprite_end}}
};

const metasprite_t spritesheet_6_metasprite_5  = {
    .count = 2,
    .items = {{0, 0, 0, 20, 0}, {1, 0, 8, 22, 0}, {metasprite_end}}
};

const metasprite_t spritesheet_6_metasprite_6  = {
    .count = 2,
    .items = {{0, 0, 0, 18, 32}, {1, 0, 8, 16, 32}, {metasprite_end}}
};

const metasprite_t spritesheet_6_metasprite_7  = {
    .count = 2,
    .items = {{0, 0, 0, 22, 32}, {1, 0, 8, 20, 32}, {metasprite_end}}
};

const metasprite_t * const spritesheet_6_metasprites[] = {
    &spritesheet_6_metasprite_0,
    &spritesheet_6_metasprite_1,
    &spritesheet_6_metasprite_2,
    &spritesheet_6_metasprite_3,
    &spritesheet_6_metasprite_4,
    &spritesheet_6_metasprite_5,
    &spritesheet_6_metasprite_6,
    &spritesheet_6_metasprite_7
};

const struct spritesheet_t spritesheet_6 = {
  .n_tiles = 1,
  .n_metasprites = 6,
  .metasprites = spritesheet_6_metasprites,  
  .tiles = {
    0,0,0,0,63,63,64,127,95,96,95,110,95,106,95,109,95,96,64,127,63,63,2,3,2,3,2,3,2,3,3,3,0,0,0,0,252,252,2,254,250,6,250,214,250,182,250,86,250,6,2,254,252,252,64,192,192,64,192,64,192,64,192,192
  }
};
