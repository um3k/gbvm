#pragma bank 255

// Background: stars

#include "gbs_types.h"
#include "data/tileset_3.h"
#include "data/tilemap_5.h"

const void __at(255) __bank_background_5;

const struct background_t background_5 = {
    .width = 32,
    .height = 32,
    .tileset = TO_FAR_PTR_T(tileset_3),
    .cgb_tileset = { NULL, NULL },
    .tilemap = TO_FAR_PTR_T(tilemap_5),
    .cgb_tilemap_attr = { NULL, NULL }
};
