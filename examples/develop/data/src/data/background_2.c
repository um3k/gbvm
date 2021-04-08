#pragma bank 255

// Background: platform_path

#include "gbs_types.h"
#include "data/tileset_7.h"
#include "data/background_2_map.h"
#include "data/scene_2_colors.h"

const void __at(255) __bank_background_2;

const struct background_t background_2 = {
  .width = 161,
  .height = 18,
  .tileset = TO_FAR_PTR_T(tileset_7),
  .cgb_tileset = {NULL, NULL},
  .tilemap = TO_FAR_PTR_T(background_2_map),
  .cgb_tilemap_attr = TO_FAR_PTR_T(scene_2_colors)
};
