#pragma bank 255

// Scene: Underground

#include "data/data_types.h"
#include "data/background_2.h"
#include "data/scene_1_collisions.h"
#include "data/scene_1_colors.h"
#include "data/palette_2.h"
#include "data/palette_0.h"
#include "data/scene_1_actors.h"
#include "data/scene_1_triggers.h"
#include "data/scene_1_sprites.h"
#include "data/script_s1_init.h"

const void __at(255) __bank_scene_1;

const struct scene_t scene_1 = {
  .width = 32,
  .height = 32,
  .type = SCENE_TYPE_TOPDOWN,
  .background = TO_FAR_PTR_T(background_2),
  .collisions = TO_FAR_PTR_T(scene_1_collisions),
  .colors = TO_FAR_PTR_T(scene_1_colors),
  .palette = TO_FAR_PTR_T(palette_2),
  .sprite_palette = TO_FAR_PTR_T(palette_0),
  .n_actors = 6,
  .n_triggers = 2,
  .n_sprites = 4,
  .actors = TO_FAR_PTR_T(scene_1_actors),
  .triggers = TO_FAR_PTR_T(scene_1_triggers),
  .sprites = TO_FAR_PTR_T(scene_1_sprites),
  .script_init = TO_FAR_PTR_T(script_s1_init)
};
