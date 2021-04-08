#pragma bank 255

// Background: underground

#include "gbs_types.h"
#include "data/tileset_1.h"
#include "data/background_4_map.h"
#include "data/scene_4_colors.h"

const void __at(255) __bank_background_4;

const struct background_t background_4 = {
  .width = 32,
  .height = 32,
  .tileset = TO_FAR_PTR_T(tileset_1),
  .cgb_tileset = {NULL, NULL},
  .tilemap = TO_FAR_PTR_T(background_4_map),
  .cgb_tilemap_attr = TO_FAR_PTR_T(scene_4_colors)
};
