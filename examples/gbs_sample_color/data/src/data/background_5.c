#pragma bank 255

// Background: leaving_earth

#include "gbs_types.h"
#include "data/tileset_5.h"
#include "data/tilemap_5.h"
#include "data/tilemap_attr_5.h"

BANKREF(background_5)

const struct background_t background_5 = {
    .width = 255,
    .height = 18,
    .tileset = TO_FAR_PTR_T(tileset_5),
    .cgb_tileset = { NULL, NULL },
    .tilemap = TO_FAR_PTR_T(tilemap_5),
    .cgb_tilemap_attr = TO_FAR_PTR_T(tilemap_attr_5)
};
