#pragma bank 255

// Background: logo_test

#include "gbs_types.h"
#include "data/tileset_3.h"
#include "data/tilemap_4.h"
#include "data/tilemap_attr_4.h"

const void __at(255) __bank_background_4;

const struct background_t background_4 = {
    .width = 20,
    .height = 18,
    .tileset = TO_FAR_PTR_T(tileset_3),
    .cgb_tileset = { NULL, NULL },
    .tilemap = TO_FAR_PTR_T(tilemap_4),
    .cgb_tilemap_attr = TO_FAR_PTR_T(tilemap_attr_4)
};
