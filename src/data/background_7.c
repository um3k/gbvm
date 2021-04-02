#pragma bank 255

// Background: logo

#include "gbs_types.h"
#include "data/tileset_4.h"
#include "data/background_7_map.h"
#include "data/scene_3_colors.h"

const void __at(255) __bank_background_7;
const struct background_t background_7 = {
  .width = 20,
  .height = 18,
  .tileset = TO_FAR_PTR_T(tileset_4),
  .cgb_tileset = {NULL, NULL},
  .tilemap = TO_FAR_PTR_T(background_7_map),
  .cgb_tilemap_attr = TO_FAR_PTR_T(scene_3_colors)
};
