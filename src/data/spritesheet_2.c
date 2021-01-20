#pragma bank 255

// SpriteSheet: torch

#include "gbs_types.h"

const void __at(255) __bank_spritesheet_2;

const metasprite_t spritesheet_2_metasprite_0  = {
    .count = 2,
    .items = {{0, 0, 0, 0, 0}, {1, 0, 8, 2, 0}, {metasprite_end}}
};

const metasprite_t spritesheet_2_metasprite_1  = {
    .count = 2,
    .items = {{0, 0, 0, 4, 0}, {1, 0, 8, 6, 0}, {metasprite_end}}
};

const metasprite_t spritesheet_2_metasprite_2  = {
    .count = 2,
    .items = {{0, 0, 0, 8,  0}, {1, 0, 8, 10, 0}, {metasprite_end}}
};

const metasprite_t spritesheet_2_metasprite_3  = {
    .count = 2,
    .items = {{0, 0, 0, 12, 0}, {1, 0, 8, 14, 0}, {metasprite_end}}
};

const metasprite_t spritesheet_2_metasprite_4  = {
    .count = 2,
    .items = {{0, 0, 0, 16, 0}, {1, 0, 8, 18, 0}, {metasprite_end}}
};

const metasprite_t spritesheet_2_metasprite_5  = {
    .count = 2,
    .items = {{0, 0, 0, 20, 0}, {1, 0, 8, 22, 0}, {metasprite_end}}
};

const metasprite_t spritesheet_2_metasprite_6  = {
    .count = 2,
    .items = {{0, 0, 0, 18, 32}, {1, 0, 8, 16, 32}, {metasprite_end}}
};

const metasprite_t spritesheet_2_metasprite_7  = {
    .count = 2,
    .items = {{0, 0, 0, 22, 32}, {1, 0, 8, 20, 32}, {metasprite_end}}
};

const metasprite_t *spritesheet_2_metasprites[] = {
    &spritesheet_2_metasprite_0,
    &spritesheet_2_metasprite_1,
    &spritesheet_2_metasprite_2,
    &spritesheet_2_metasprite_3,
    &spritesheet_2_metasprite_4,
    &spritesheet_2_metasprite_5,
    &spritesheet_2_metasprite_6,
    &spritesheet_2_metasprite_7
};

const struct spritesheet_t spritesheet_2 = {
  .n_tiles = 1,
  .n_metasprites = 6,
  .metasprites = &spritesheet_2_metasprites,  
  .tiles = {
    127,127,105,126,116,127,42,63,20,31,10,15,4,7,3,3,2,3,3,3,2,3,3,3,14,15,51,63,71,120,49,62,254,254,250,6,50,206,100,156,72,184,144,112,160,96,192,192,64,192,192,64,192,64,192,64,240,112,204,124,242,14,204,60
  }
};
