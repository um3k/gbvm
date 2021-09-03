#pragma bank 255

// Background: outside

#include "gbs_types.h"
#include "data/tileset_2.h"
#include "data/tilemap_4.h"

BANKREF(background_4)

const struct background_t background_4 = {
    .width = 32,
    .height = 32,
    .tileset = TO_FAR_PTR_T(tileset_2),
    .cgb_tileset = { NULL, NULL },
    .tilemap = TO_FAR_PTR_T(tilemap_4),
    .cgb_tilemap_attr = { NULL, NULL }
};
