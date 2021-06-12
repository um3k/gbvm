#pragma bank 255

// Background: hidden_cave

#include "gbs_types.h"
#include "data/tileset_4.h"
#include "data/tilemap_2.h"
#include "data/tilemap_attr_2.h"

const void __at(255) __bank_background_2;

const struct background_t background_2 = {
    .width = 32,
    .height = 18,
    .tileset = TO_FAR_PTR_T(tileset_4),
    .cgb_tileset = { NULL, NULL },
    .tilemap = TO_FAR_PTR_T(tilemap_2),
    .cgb_tilemap_attr = TO_FAR_PTR_T(tilemap_attr_2)
};
