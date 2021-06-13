#pragma bank 255

// Spritesheet Tileset: 8

#include "gbs_types.h"

const void __at(255) __bank_spritesheet_8_tiles;

const struct tileset_t spritesheet_8_tiles = {
  .n_tiles = 4,
  .tiles = {
    0,0,0,0,63,63,56,63,61,62,63,63,55,56,59,60,63,63,31,32,47,48,47,48,63,63,0,63,0,0,0,
    0,0,0,0,0,252,252,28,252,188,124,252,252,236,28,220,60,252,252,248,4,244,12,244,12,252,252,0,252,0,0,0,0
  }
};
