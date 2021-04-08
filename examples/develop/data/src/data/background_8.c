#pragma bank 255

// Background: hidden_cave

#include "gbs_types.h"
#include "data/tileset_5.h"
#include "data/background_8_map.h"
#include "data/scene_8_colors.h"

const void __at(255) __bank_background_8;

const struct background_t background_8 = {
  .width = 32,
  .height = 18,
  .tileset = TO_FAR_PTR_T(tileset_5),
  .cgb_tileset = {NULL, NULL},
  .tilemap = TO_FAR_PTR_T(background_8_map),
  .cgb_tilemap_attr = TO_FAR_PTR_T(scene_8_colors)
};
