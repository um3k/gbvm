#pragma bank 255

// Scene: Platform Scene

#include "gbs_types.h"
#include "data/background_2.h"
#include "data/spritesheet_12.h"
#include "data/scene_4_collisions.h"
#include "data/scene_4_colors.h"
#include "data/palette_2.h"
#include "data/palette_4.h"
#include "data/scene_4_triggers.h"
#include "data/script_s4_init.h"

const void __at(255) __bank_scene_4;

const struct scene_t scene_4 = {
  .width = 161,
  .height = 18,
  .type = SCENE_TYPE_PLATFORM,
  .background = TO_FAR_PTR_T(background_2),
  .collisions = TO_FAR_PTR_T(scene_4_collisions),
  .palette = TO_FAR_PTR_T(palette_2),
  .sprite_palette = TO_FAR_PTR_T(palette_4),
  .player_sprite = TO_FAR_PTR_T(spritesheet_12),
  .parallax_rows = {
    PARALLAX_STEP(0, 0, 0)
  },  
  .n_actors = 0,
  .n_triggers = 5,
  .n_sprites = 0,
  .triggers = TO_FAR_PTR_T(scene_4_triggers),
  .script_init = TO_FAR_PTR_T(script_s4_init)
};
