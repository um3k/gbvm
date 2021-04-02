#pragma bank 255

// Scene: Dancefloor

#include "gbs_types.h"
#include "data/background_6.h"
#include "data/spritesheet_0.h"
#include "data/scene_6_collisions.h"
#include "data/scene_6_colors.h"
#include "data/palette_2.h"
#include "data/palette_0.h"
#include "data/scene_6_actors.h"
#include "data/scene_6_triggers.h"
#include "data/scene_6_sprites.h"
#include "data/script_s5_init.h"

const void __at(255) __bank_scene_6;

const struct scene_t scene_6 = {
  .width = 20,
  .height = 18,
  .type = SCENE_TYPE_PLATFORM,
  .background = TO_FAR_PTR_T(background_6),
  .collisions = TO_FAR_PTR_T(scene_6_collisions),
  .palette = TO_FAR_PTR_T(palette_2),
  .sprite_palette = TO_FAR_PTR_T(palette_0),
  .player_sprite = TO_FAR_PTR_T(spritesheet_0),  
  .n_actors = 2,
  .n_triggers = 2,
  .n_sprites = 1,
  .actors = TO_FAR_PTR_T(scene_6_actors),
  .triggers = TO_FAR_PTR_T(scene_6_triggers),
  .sprites = TO_FAR_PTR_T(scene_6_sprites),
  .script_init = TO_FAR_PTR_T(script_s5_init),
};
