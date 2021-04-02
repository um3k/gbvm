#pragma bank 255

// Background: outside

#include "gbs_types.h"
#include "data/tileset_1.h"
#include "data/background_1_map.h"
#include "data/scene_1_colors.h"

const void __at(255) __bank_background_1;

const struct background_t background_1 = {
  .width = 32,
  .height = 32,
  .tileset = TO_FAR_PTR_T(tileset_1),
  .cgb_tileset = {NULL, NULL},
  .tilemap = TO_FAR_PTR_T(background_1_map),
  .cgb_tilemap_attr = TO_FAR_PTR_T(scene_1_colors)
};
