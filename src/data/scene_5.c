#pragma bank 255

// Scene: Parallax Test

#include "gbs_types.h"
#include "data/background_5.h"
#include "data/scene_5_collisions.h"
#include "data/scene_5_colors.h"
#include "data/palette_2.h"
#include "data/palette_4.h"
#include "data/scene_5_triggers.h"

const void __at(255) __bank_scene_5;

const struct scene_t scene_5 = {
  .width = 80,
  .height = 18,
  .type = SCENE_TYPE_PLATFORM,
  .background = TO_FAR_PTR_T(background_5),
  .collisions = TO_FAR_PTR_T(scene_5_collisions),
  .colors = TO_FAR_PTR_T(scene_5_colors),
  .palette = TO_FAR_PTR_T(palette_2),
  .sprite_palette = TO_FAR_PTR_T(palette_4),
  .parallax_rows = {
    PARALLAX_STEP(0, 10, 7),
    PARALLAX_STEP(10, 13, 3),
    PARALLAX_STEP(13, 0, 0)
  },  
  .n_actors = 0,
  .n_triggers = 2,
  .n_sprites = 0,
  .triggers = TO_FAR_PTR_T(scene_5_triggers)
};
