#pragma bank 255

// SpriteSheet: coin

#include "gbs_types.h"
#include "data/spritesheet_11_tiles.h"

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
  .n_metasprites = 2,
  .metasprites = spritesheet_11_metasprites,
  .animations  = {
    // Idle
    { .start = 0, .end = 1 }, // bottom
    { .start = 0, .end = 1 }, // right
    { .start = 0, .end = 1 }, // top
    { .start = 0, .end = 1 }, // left
    // Moving
    { .start = 0, .end = 1 }, // bottom
    { .start = 0, .end = 1 }, // right
    { .start = 0, .end = 1 }, // top
    { .start = 0, .end = 1 }, // left    
  },  
  .tileset = TO_FAR_PTR_T(spritesheet_11_tiles),
  .cgb_tileset = { NULL, NULL },  
};
