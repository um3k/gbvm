#pragma bank 255
// SpriteSheet: player
  
#include "gbs_types.h"
#include "data/tileset_1.h"

const void __at(255) __bank_spritesheet_0;

const metasprite_t spritesheet_0_metasprite_0[]  = {
  { 0, 8, 8, 0 }, { 0, -8, 10, 0 },
{metasprite_end}
};

const metasprite_t spritesheet_0_metasprite_1[]  = {
  { 0, 8, 0, 0 }, { 0, -8, 2, 0 },
{metasprite_end}
};

const metasprite_t spritesheet_0_metasprite_2[]  = {
  { 0, 8, 4, 0 }, { 0, -8, 6, 0 },
{metasprite_end}
};

const metasprite_t spritesheet_0_metasprite_3[]  = {
  { 0, 0, 0, 32 }, { 0, 8, 2, 32 },
{metasprite_end}
};

const metasprite_t spritesheet_0_metasprite_4[]  = {
  { 0, 8, 20, 0 }, { 0, -8, 22, 0 },
{metasprite_end}
};

const metasprite_t spritesheet_0_metasprite_5[]  = {
  { 0, 8, 12, 0 }, { 0, -8, 14, 0 },
{metasprite_end}
};

const metasprite_t spritesheet_0_metasprite_6[]  = {
  { 0, 8, 16, 0 }, { 0, -8, 18, 0 },
{metasprite_end}
};

const metasprite_t spritesheet_0_metasprite_7[]  = {
  { 0, 0, 12, 32 }, { 0, 8, 14, 32 },
{metasprite_end}
};

const metasprite_t * const spritesheet_0_metasprites[] = {
    spritesheet_0_metasprite_0,
    spritesheet_0_metasprite_1,
    spritesheet_0_metasprite_2,
    spritesheet_0_metasprite_3,
    spritesheet_0_metasprite_4,
    spritesheet_0_metasprite_0,
    spritesheet_0_metasprite_5,
    spritesheet_0_metasprite_1,
    spritesheet_0_metasprite_6,
    spritesheet_0_metasprite_2,
    spritesheet_0_metasprite_7,
    spritesheet_0_metasprite_3
};

const struct spritesheet_t spritesheet_0 = {
    .n_tiles = 24,
    .n_metasprites = 12,
    .metasprites = spritesheet_0_metasprites,
    .animations = {
        {
            .start = 0,
            .end = 0
        },
        {
            .start = 1,
            .end = 1
        },
        {
            .start = 2,
            .end = 2
        },
        {
            .start = 3,
            .end = 3
        },
        {
            .start = 4,
            .end = 5
        },
        {
            .start = 6,
            .end = 7
        },
        {
            .start = 8,
            .end = 9
        },
        {
            .start = 10,
            .end = 11
        }
    },
    .tiles = {
        0x00, 0x00, 0xF0, 0xF0, 0x38, 0xC8, 0x0C, 0xF4, 0x62, 0xBE, 0xD2, 0x7E, 0xAC, 0xDC, 0x38, 0xC8,
        0xF8, 0x28, 0xFC, 0x24, 0xF8, 0x08, 0xF0, 0xF0, 0x30, 0xD0, 0xF8, 0xE8, 0x5C, 0x64, 0x38, 0x38,
        0x00, 0x00, 0x03, 0x03, 0x0C, 0x0F, 0x16, 0x19, 0x2A, 0x37, 0x24, 0x3F, 0x29, 0x3E, 0x27, 0x3F,
        0x22, 0x3F, 0x33, 0x2E, 0x33, 0x2F, 0x7C, 0x47, 0x39, 0x3F, 0x1F, 0x13, 0x0F, 0x0F, 0x06, 0x06,
        0x00, 0x00, 0xE0, 0xE0, 0x10, 0xF0, 0x68, 0x98, 0x84, 0x7C, 0x04, 0xFC, 0x04, 0xFC, 0x04, 0xFC,
        0x24, 0xDC, 0x24, 0xDC, 0x24, 0xDC, 0xA2, 0xDE, 0x9E, 0xFE, 0xF8, 0xF8, 0xB0, 0xD0, 0x70, 0x70,
        0x00, 0x00, 0x07, 0x07, 0x08, 0x0F, 0x16, 0x19, 0x21, 0x3E, 0x60, 0x7F, 0x20, 0x3F, 0x20, 0x3F,
        0x29, 0x36, 0x29, 0x36, 0x29, 0x36, 0x55, 0x6A, 0x7E, 0x7D, 0x3F, 0x27, 0x1F, 0x1F, 0x00, 0x00,
        0x00, 0x00, 0xE0, 0xE0, 0x10, 0xF0, 0x38, 0xC8, 0x5C, 0xA4, 0xAC, 0xD4, 0x42, 0xFE, 0xBE, 0x7E,
        0xD4, 0x7C, 0xF4, 0x5C, 0xF4, 0x3C, 0xFA, 0xFE, 0x3C, 0xE4, 0xFC, 0xE4, 0xF8, 0xF8, 0x70, 0x70,
        0x00, 0x00, 0x07, 0x07, 0x08, 0x0F, 0x10, 0x1F, 0x3D, 0x23, 0x22, 0x3F, 0x2D, 0x3E, 0x2B, 0x3C,
        0x2B, 0x3E, 0x2F, 0x3A, 0x3F, 0x2C, 0x6F, 0x5F, 0x7F, 0x7F, 0x39, 0x3F, 0x1D, 0x1B, 0x0E, 0x0E,
        0x00, 0x00, 0xF0, 0xF0, 0x38, 0xC8, 0x0C, 0xF4, 0x62, 0xBE, 0xD2, 0x7E, 0xAC, 0xDC, 0x38, 0xC8,
        0xF8, 0x28, 0xFC, 0x24, 0xF8, 0x08, 0xF0, 0xF0, 0x50, 0xF0, 0xFC, 0x3C, 0xFC, 0xFC, 0x30, 0x30,
        0x00, 0x00, 0x03, 0x03, 0x0C, 0x0F, 0x16, 0x19, 0x2A, 0x37, 0x24, 0x3F, 0x29, 0x3E, 0x27, 0x3F,
        0x22, 0x3F, 0x33, 0x2E, 0x31, 0x2F, 0x7E, 0x43, 0x3E, 0x3F, 0x37, 0x3F, 0x17, 0x19, 0x0E, 0x0E,
        0x00, 0x00, 0xE0, 0xE0, 0x10, 0xF0, 0x68, 0x98, 0x84, 0x7C, 0x04, 0xFC, 0x04, 0xFC, 0x04, 0xFC,
        0x24, 0xDC, 0x24, 0xDC, 0x24, 0xDC, 0xA2, 0xDE, 0x9E, 0xFE, 0xFC, 0xE4, 0xF8, 0xF8, 0x00, 0x00,
        0x00, 0x00, 0x07, 0x07, 0x08, 0x0F, 0x16, 0x19, 0x21, 0x3E, 0x20, 0x3F, 0x60, 0x7F, 0x20, 0x3F,
        0x29, 0x36, 0x29, 0x36, 0x29, 0x36, 0x55, 0x6A, 0x7E, 0x7D, 0x3F, 0x3F, 0x0D, 0x0B, 0x0E, 0x0E,
        0x00, 0x00, 0xE0, 0xE0, 0x10, 0xF0, 0x38, 0xC8, 0x5C, 0xA4, 0xAC, 0xD4, 0x42, 0xFE, 0xBE, 0x7E,
        0xD4, 0x7C, 0xF4, 0x5C, 0xF4, 0x3C, 0xF2, 0xFE, 0xFE, 0xFE, 0x9C, 0xFC, 0xB8, 0xD8, 0x70, 0x70,
        0x00, 0x00, 0x07, 0x07, 0x08, 0x0F, 0x10, 0x1F, 0x3D, 0x23, 0x22, 0x3F, 0x2D, 0x3E, 0x2B, 0x3C,
        0x2B, 0x3E, 0x2F, 0x3A, 0x3F, 0x2C, 0x6F, 0x5F, 0x7C, 0x7F, 0x3F, 0x27, 0x1F, 0x1F, 0x0E, 0x0E
    },
    .tileset = TO_FAR_PTR_T(tileset_1)
};
