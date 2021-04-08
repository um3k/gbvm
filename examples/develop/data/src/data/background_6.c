#pragma bank 255

// Background: underground

#include "gbs_types.h"
#include "data/tileset_3.h"
#include "data/background_6_map.h"
#include "data/scene_6_colors.h"

const void __at(255) __bank_background_6;

const struct background_t background_6 = {
  .width = 20,
  .height = 18,
  .tileset = TO_FAR_PTR_T(tileset_3),
  .cgb_tileset = {NULL, NULL},
  .tilemap = TO_FAR_PTR_T(background_6_map),
  .cgb_tilemap_attr = TO_FAR_PTR_T(scene_6_colors)
};
