#pragma bank 255

// Background: underground

#include "gbs_types.h"
#include "data/tileset_1.h"
#include "data/tilemap_7.h"

const void __at(255) __bank_background_7;

const struct background_t background_7 = {
    .width = 32,
    .height = 32,
    .tileset = TO_FAR_PTR_T(tileset_1),
    .cgb_tileset = { NULL, NULL },
    .tilemap = TO_FAR_PTR_T(tilemap_7),
    .cgb_tilemap_attr = { NULL, NULL }
};
