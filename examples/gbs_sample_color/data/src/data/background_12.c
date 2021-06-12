#pragma bank 255

// Background: stars

#include "gbs_types.h"
#include "data/tileset_5.h"
#include "data/tilemap_12.h"
#include "data/tilemap_attr_9.h"

const void __at(255) __bank_background_12;

const struct background_t background_12 = {
    .width = 32,
    .height = 32,
    .tileset = TO_FAR_PTR_T(tileset_5),
    .cgb_tileset = { NULL, NULL },
    .tilemap = TO_FAR_PTR_T(tilemap_12),
    .cgb_tilemap_attr = TO_FAR_PTR_T(tilemap_attr_9)
};
