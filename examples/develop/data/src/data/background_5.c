#pragma bank 255

// Background: parallax4

#include "gbs_types.h"
#include "data/tileset_2.h"
#include "data/background_5_map.h"
#include "data/scene_5_colors.h"

const void __at(255) __bank_background_5;

const struct background_t background_5 = {
  .width = 80,
  .height = 18,
  .tileset = TO_FAR_PTR_T(tileset_2),
  .cgb_tileset = {NULL, NULL},
  .tilemap = TO_FAR_PTR_T(background_5_map),
  .cgb_tilemap_attr = TO_FAR_PTR_T(scene_5_colors)
};
