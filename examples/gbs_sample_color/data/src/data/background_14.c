#pragma bank 255

// Background: underground

#include "gbs_types.h"
#include "data/tileset_7.h"
#include "data/tilemap_14.h"
#include "data/tilemap_attr_11.h"

BANKREF(background_14)

const struct background_t background_14 = {
    .width = 32,
    .height = 32,
    .tileset = TO_FAR_PTR_T(tileset_7),
    .cgb_tileset = { NULL, NULL },
    .tilemap = TO_FAR_PTR_T(tilemap_14),
    .cgb_tilemap_attr = TO_FAR_PTR_T(tilemap_attr_11)
};
