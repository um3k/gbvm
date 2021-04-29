#pragma bank 255

// Background: platform_path

#include "gbs_types.h"
#include "data/tileset_0.h"
#include "data/tilemap_9.h"
#include "data/tilemap_attr_6.h"

const void __at(255) __bank_background_9;

const struct background_t background_9 = {
    .width = 161,
    .height = 18,
    .tileset = TO_FAR_PTR_T(tileset_0),
    .cgb_tileset = { NULL, NULL },
    .tilemap = TO_FAR_PTR_T(tilemap_9),
    .cgb_tilemap_attr = TO_FAR_PTR_T(tilemap_attr_6)
};
