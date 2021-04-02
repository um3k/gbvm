#pragma bank 255

// Background: cave

#include "gbs_types.h"
#include "data/tileset_1.h"
#include "data/background_0_map.h"
#include "data/scene_0_colors.h"

const void __at(255) __bank_background_0;

const struct background_t background_0 = {
  .width = 20,
  .height = 18,
  .tileset = TO_FAR_PTR_T(tileset_1),
  .cgb_tileset = {NULL, NULL},
  .tilemap = TO_FAR_PTR_T(background_0_map),
  .cgb_tilemap_attr = TO_FAR_PTR_T(scene_0_colors)
};
