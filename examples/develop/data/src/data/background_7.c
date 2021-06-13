#pragma bank 255

// Background: platform_path

#include "gbs_types.h"
#include "data/tileset_6.h"
#include "data/tilemap_7.h"
#include "data/tilemap_attr_7.h"

const void __at(255) __bank_background_7;

const struct background_t background_7 = {
    .width = 161,
    .height = 18,
    .tileset = TO_FAR_PTR_T(tileset_6),
    .cgb_tileset = { NULL, NULL },
    .tilemap = TO_FAR_PTR_T(tilemap_7),
    .cgb_tilemap_attr = TO_FAR_PTR_T(tilemap_attr_7)
};
