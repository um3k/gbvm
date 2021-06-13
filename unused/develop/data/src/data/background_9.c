#pragma bank 255

// Background: room

#include "gbs_types.h"
#include "data/tileset_8.h"
#include "data/background_9_map.h"
#include "data/scene_9_colors.h"

const void __at(255) __bank_background_9;

const struct background_t background_9 = {
  .width = 20,
  .height = 18,
  .tileset = TO_FAR_PTR_T(tileset_8),
  .cgb_tileset = {NULL, NULL},
  .tilemap = TO_FAR_PTR_T(background_9_map),
  .cgb_tilemap_attr = TO_FAR_PTR_T(scene_9_colors)
};
