#pragma bank 255

// Background: hidden_cave

#include "gbs_types.h"
#include "data/tileset_2.h"
#include "data/tilemap_3.h"
#include "data/tilemap_attr_3.h"

const void __at(255) __bank_background_3;

const struct background_t background_3 = {
    .width = 32,
    .height = 18,
    .tileset = TO_FAR_PTR_T(tileset_2),
    .cgb_tileset = { NULL, NULL },
    .tilemap = TO_FAR_PTR_T(tilemap_3),
    .cgb_tilemap_attr = TO_FAR_PTR_T(tilemap_attr_3)
};
