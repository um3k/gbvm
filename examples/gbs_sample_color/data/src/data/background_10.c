#pragma bank 255

// Background: room

#include "gbs_types.h"
#include "data/tileset_3.h"
#include "data/tilemap_10.h"
#include "data/tilemap_attr_7.h"

BANKREF(background_10)

const struct background_t background_10 = {
    .width = 20,
    .height = 18,
    .tileset = TO_FAR_PTR_T(tileset_3),
    .cgb_tileset = { NULL, NULL },
    .tilemap = TO_FAR_PTR_T(tilemap_10),
    .cgb_tilemap_attr = TO_FAR_PTR_T(tilemap_attr_7)
};
