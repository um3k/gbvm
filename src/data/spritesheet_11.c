#pragma bank 255

// SpriteSheet: coon

#include "gbs_types.h"

const void __at(255) __bank_spritesheet_11;

const metasprite_t spritesheet_11_metasprite_0[]  = {
    {0,  0,  0,  0x10}, {0,  8,  2,  0x10}, 
    {0, -8,  4,     0}, {0,  8,  6,     0}, 
    {metasprite_end}
};
const metasprite_t spritesheet_11_metasprite_1[]  = {
    {0,  4,  8,  0x10}, {0,  0, 10,     0}, 
    {metasprite_end}
};

const metasprite_t * const spritesheet_11_metasprites[] = {
    spritesheet_11_metasprite_0, 
    spritesheet_11_metasprite_1
};

const struct spritesheet_t spritesheet_11 = {
  .n_tiles = 12,
  .n_metasprites = 2,
  .metasprites = spritesheet_11_metasprites,
  .tiles = {
    0x00,0x00,0x07,0x07,0x18,0x18,0x27,0x20,0x2D,0x20,0x5A,0x64,0x5A,0x64,0x5A,0x64,0x5A,0x64,0x2D,0x32,0x27,0x38,0x18,0x1F,0x07,0x07,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0xC0,0xC0,0x20,0x20,0xA0,0x20,0xD0,0x10,0xD0,0x10,0xD0,0x10,0xD0,0x10,0xA0,0x60,0x20,0xE0,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x07,0x07,0x1F,0x18,0x38,0x20,0x32,0x20,0x41,0x40,0x41,0x40,0x41,0x40,0x41,0x40,0x20,0x20,0x20,0x20,0x18,0x18,0x07,0x07,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0xC0,0xC0,0xE0,0x20,0x60,0x20,0x30,0x10,0x30,0x10,0x30,0x10,0x30,0x10,0x20,0x20,0x20,0x20,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x38,0x38,0x44,0x44,0x64,0x54,0x54,0x64,0x64,0x54,0x54,0x64,0x64,0x54,0x54,0x64,0x6C,0x54,0x5C,0x64,0x44,0x7C,0x38,0x38,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x38,0x38,0x7C,0x44,0x4C,0x44,0x4C,0x44,0x4C,0x44,0x4C,0x44,0x4C,0x44,0x4C,0x44,0x4C,0x44,0x44,0x44,0x44,0x44,0x38,0x38,0x00,0x00,0x00,0x00,0x00,0x00
  }
};
