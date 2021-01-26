#pragma bank 255

// SpriteSheet: sage

#include "gbs_types.h"

const void __at(255) __bank_spritesheet_4;

const metasprite_t spritesheet_4_metasprite_0  = {
    .count = 2,
    .items = {{0, 0, 0, 0}, {0, 8, 2, 0}, {metasprite_end}}
};

const metasprite_t spritesheet_4_metasprite_1  = {
    .count = 2,
    .items = {{0, 0, 4, 0}, {0, 8, 6, 0}, {metasprite_end}}
};

const metasprite_t spritesheet_4_metasprite_2  = {
    .count = 2,
    .items = {{0, 0, 8,  0}, {0, 8, 10, 0}, {metasprite_end}}
};

const metasprite_t spritesheet_4_metasprite_3  = {
    .count = 2,
    .items = {{0, 0, 12, 0}, {0, 8, 14, 0}, {metasprite_end}}
};

const metasprite_t spritesheet_4_metasprite_4  = {
    .count = 2,
    .items = {{0, 0, 16, 0}, {0, 8, 18, 0}, {metasprite_end}}
};

const metasprite_t spritesheet_4_metasprite_5  = {
    .count = 2,
    .items = {{0, 0, 20, 0}, {0, 8, 22, 0}, {metasprite_end}}
};

const metasprite_t spritesheet_4_metasprite_6  = {
    .count = 2,
    .items = {{0, 0, 18, 32}, {0, 8, 16, 32}, {metasprite_end}}
};

const metasprite_t spritesheet_4_metasprite_7  = {
    .count = 2,
    .items = {{0, 0, 22, 32}, {0, 8, 20, 32}, {metasprite_end}}
};

const metasprite_t * const spritesheet_4_metasprites[] = {
    &spritesheet_4_metasprite_0,
    &spritesheet_4_metasprite_1,
    &spritesheet_4_metasprite_2,
    &spritesheet_4_metasprite_3,
    &spritesheet_4_metasprite_4,
    &spritesheet_4_metasprite_5,
    &spritesheet_4_metasprite_6,
    &spritesheet_4_metasprite_7
};

const struct spritesheet_t spritesheet_4 = {
  .n_tiles = 4,
  .n_metasprites = 6,
  .metasprites = spritesheet_4_metasprites,  
  .tiles = {
    7,7,8,15,17,30,32,63,32,63,46,63,63,48,63,63,58,63,57,54,63,56,47,57,47,52,111,116,71,123,129,255,224,224,16,240,232,24,100,156,28,252,220,228,244,28,252,252,92,252,156,108,252,28,244,156,244,44,244,44,226,222,129,127
  }
};
