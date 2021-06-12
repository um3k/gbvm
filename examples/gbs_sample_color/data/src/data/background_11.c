#pragma bank 255

// Background: sample_town

#include "gbs_types.h"
#include "data/tileset_4.h"
#include "data/tilemap_11.h"
#include "data/tilemap_attr_8.h"

const void __at(255) __bank_background_11;

const struct background_t background_11 = {
    .width = 56,
    .height = 56,
    .tileset = TO_FAR_PTR_T(tileset_4),
    .cgb_tileset = { NULL, NULL },
    .tilemap = TO_FAR_PTR_T(tilemap_11),
    .cgb_tilemap_attr = TO_FAR_PTR_T(tilemap_attr_8)
};
