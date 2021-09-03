#pragma bank 255

// Background: logo

#include "gbs_types.h"
#include "data/tileset_1.h"
#include "data/tilemap_6.h"
#include "data/tilemap_attr_0.h"

BANKREF(background_6)

const struct background_t background_6 = {
    .width = 20,
    .height = 18,
    .tileset = TO_FAR_PTR_T(tileset_1),
    .cgb_tileset = { NULL, NULL },
    .tilemap = TO_FAR_PTR_T(tilemap_6),
    .cgb_tilemap_attr = TO_FAR_PTR_T(tilemap_attr_0)
};
