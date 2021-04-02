#pragma bank 255

// Spritesheet Tileset: 10

#include "gbs_types.h"

const void __at(255) __bank_spritesheet_10_tiles;

const struct tileset_t spritesheet_10_tiles = {
  .n_tiles = 56,
  .tiles = {
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x03,0x0d,0x0e,0x1f,0x10,0x3f,0x20,0x3f,0x20,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x03,0xfd,0xfe,0x3f,0xc0,0xff,0x0c,0xff,0x13,0xf7,0x08,0xc1,0x3e,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7f,0x7f,0x9f,0xe0,0xff,0x00,0xff,0x00,0xff,0x00,0xff,0x00,0xff,0x80,0xff,0x40,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0xf0,0xcf,0x3f,0xff,0x00,0xff,0x00,0xff,0x00,0xff,0x00,0xff,0x00,0xff,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xc0,0xc0,0x3c,0xfc,0xf3,0x0f,0xff,0x00,0xff,0x00,0xff,0x00,0xff,0x00,
        0x3f,0x20,0x3f,0x20,0x3f,0x20,0x3f,0x20,0x3f,0x20,0x3f,0x23,0x3d,0x23,0x5e,0x61,0x5e,0x61,0x7c,0x43,0x78,0x47,0x79,0x47,0xbb,0xc7,0xb3,0xcf,0xf2,0x8e,0xf4,0x8c,
        0xc0,0x3f,0xc0,0x3f,0xc0,0x3f,0xcf,0x30,0xff,0x08,0xbf,0xc4,0xe7,0xdc,0x07,0xfc,0x02,0xff,0x03,0xff,0x00,0xff,0x87,0xff,0xff,0xff,0xc1,0xc1,0x01,0x01,0x00,0x00,
        0xff,0x20,0x7f,0xa0,0x7f,0x90,0xff,0x10,0xff,0x10,0xdf,0x30,0xff,0x60,0xbf,0xc0,0xbd,0xc2,0x3c,0xc3,0x7e,0x81,0xff,0x80,0xff,0x80,0xbf,0xc0,0xff,0xc0,0xff,0xc0,
        0xff,0x00,0xff,0x00,0xff,0x00,0xff,0x00,0xff,0x00,0xff,0x00,0xff,0x00,0x3f,0xc0,0x07,0xf8,0x00,0xff,0x00,0xff,0x00,0xff,0x00,0xff,0x00,0xff,0x40,0xff,0x40,0xff,
        0xfe,0x02,0xfe,0x02,0xfd,0x03,0xff,0x01,0xff,0x01,0xff,0x01,0xff,0x00,0x7f,0x80,0x7f,0x80,0xff,0x00,0xfe,0x01,0xff,0x01,0xfd,0x03,0xfd,0x03,0x79,0x87,0x71,0x8f,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,0x40,0xc0,0xc0,0x40,0xc0,0x40,0xc0,0x40,0xe0,0x20,0x60,0xa0,0x60,0xa0,0xa0,0xe0,
        0xf4,0x8c,0xf4,0x8c,0xb4,0xcc,0xb8,0xc8,0xb8,0xc8,0x78,0x48,0x78,0x48,0x78,0x48,0x74,0x4c,0x5c,0x64,0x3c,0x24,0x3e,0x22,0x19,0x17,0x0b,0x0f,0x06,0x06,0x00,0x00,
        0xdf,0xe0,0x7f,0x60,0x7e,0x61,0x6e,0x71,0x7e,0x71,0x7c,0x73,0x70,0x7f,0x78,0x7f,0x78,0x7f,0x78,0x7f,0x7c,0x7f,0x7c,0x7f,0x7c,0x7f,0xfb,0xfc,0xfb,0xfc,0x0f,0x0f,
        0x70,0xff,0x4f,0xcf,0x41,0xc1,0x40,0xc0,0x40,0xc0,0x40,0xc0,0x20,0xe0,0x20,0xe0,0x20,0xe0,0x20,0xe0,0x20,0xe0,0x10,0xf0,0x10,0xf0,0x90,0x70,0xd0,0x30,0xe0,0xe0,
        0x02,0xff,0xfe,0xff,0xfe,0xff,0x3f,0x3f,0x3f,0x3f,0x3f,0x3f,0x3f,0x3f,0x1f,0x1f,0x1f,0x1f,0x1f,0x1f,0x1f,0x1f,0x1f,0x1f,0x3f,0x3f,0x3f,0x3f,0x3f,0x3f,0x00,0x00,
        0x01,0xff,0x01,0xff,0x01,0xff,0x01,0xff,0x01,0xff,0x82,0xfe,0x82,0xfe,0xc2,0xfe,0xc2,0xfe,0x42,0x7e,0x42,0x7e,0x42,0x7e,0x81,0xff,0xb9,0xc7,0xfd,0x83,0xfe,0xfe,
        0x50,0x70,0x50,0x70,0x50,0x70,0x50,0x70,0x30,0x30,0x20,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,0x40,0xc0,0xc0,0x40,0xc0,0x40,0xe0,0x20,0x60,0xa0,0xb0,0xd0,0x70,0x50,0x50,0x70,
        0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0xf4,0x8c,0xf4,0x8c,0xf4,0x8c,0x78,0x88,0xe8,0x18,0xf0,0x10,0xf0,0x10,0xf0,0x10,0x70,0x90,0xf0,0x90,0xe8,0x98,0x78,0x48,0x64,0x5c,0x2c,0x3c,0x18,0x18,0x00,0x00,
        0x38,0x28,0x38,0x28,0x28,0x38,0x18,0x18,0x18,0x18,0x08,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,0x40,0xc0,0xc0,0x40,0xe0,0x20,0xe0,0x20,0xf0,0x90,0xb0,0xd0,0x78,0x48,0x34,0x2c,
        0x01,0x01,0x01,0x01,0x01,0x01,0x02,0x03,0x03,0x02,0x03,0x02,0x05,0x06,0x07,0x04,0x07,0x04,0x07,0x04,0x07,0x04,0x05,0x06,0x03,0x02,0x02,0x03,0x01,0x01,0x00,0x00,
        0x74,0x8c,0xf4,0x0c,0xe8,0x18,0xf8,0x18,0xd0,0x30,0xe0,0x20,0xc0,0x40,0x40,0xc0,0x80,0x80,0x80,0x80,0x80,0x80,0x40,0xc0,0x40,0xc0,0x40,0xc0,0xc0,0xc0,0x00,0x00,
        0x1c,0x14,0x0e,0x0a,0x07,0x05,0x03,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x01,0x01,0x01,0x01,0x01,0x01,0x02,0x03,0x03,0x02,0x07,0x04,0x07,0x04,0x0f,0x08,0x0f,0x09,0x15,0x1b,0x1e,0x12,0x1e,0x12,0x1a,0x16,0x12,0x1e,0x1e,0x1e,0x00,0x00,
        0x74,0x8c,0xf4,0x0c,0xe8,0x18,0xf8,0x18,0xd0,0x30,0xe0,0x20,0xc0,0x40,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x01,0x01,0x01,0x01,0x01,0x01,0x02,0x03,0x03,0x02,0x07,0x04,0x0b,0x0c,0x0f,0x08,0x1f,0x11,0x1e,0x12,0x2a,0x36,0x3c,0x24,0x24,0x3c,0x28,0x38,0x38,0x38,0x00,0x00,
  }
};
