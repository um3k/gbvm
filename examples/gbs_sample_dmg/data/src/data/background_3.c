#pragma bank 255

// Background: menu

#include "gbs_types.h"
#include "data/tileset_1.h"
#include "data/tilemap_3.h"

BANKREF(background_3)

const struct background_t background_3 = {
    .width = 20,
    .height = 18,
    .tileset = TO_FAR_PTR_T(tileset_1),
    .cgb_tileset = { NULL, NULL },
    .tilemap = TO_FAR_PTR_T(tilemap_3),
    .cgb_tilemap_attr = { NULL, NULL }
};
