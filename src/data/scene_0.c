#pragma bank 255

// Scene: Cave

#include "gbs_types.h"
#include "data/background_0.h"
#include "data/scene_0_collisions.h"
#include "data/scene_0_colors.h"
#include "data/palette_2.h"
#include "data/palette_3.h"
#include "data/scene_0_actors.h"
#include "data/scene_0_triggers.h"
#include "data/scene_0_sprites.h"

const void __at(255) __bank_scene_0;

const struct scene_t scene_0 = {
  .width = 20,
  .height = 18,
  .type = SCENE_TYPE_TOPDOWN,
  .background = TO_FAR_PTR_T(background_0),
  .collisions = TO_FAR_PTR_T(scene_0_collisions),
  .colors = TO_FAR_PTR_T(scene_0_colors),
  .palette = TO_FAR_PTR_T(palette_2),
  .sprite_palette = TO_FAR_PTR_T(palette_3),
  .n_actors = 6,
  .n_triggers = 1,
  .n_sprites = 4,
  .actors = TO_FAR_PTR_T(scene_0_actors),
  .triggers = TO_FAR_PTR_T(scene_0_triggers),
  .sprites = TO_FAR_PTR_T(scene_0_sprites)
};
