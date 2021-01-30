#pragma bank 255

// Scene: Mine

#include "gbs_types.h"
#include "data/background_8.h"
#include "data/spritesheet_0.h"
#include "data/scene_8_collisions.h"
#include "data/scene_8_colors.h"
#include "data/palette_2.h"
#include "data/palette_5.h"
#include "data/scene_8_actors.h"
#include "data/scene_8_triggers.h"
#include "data/scene_8_sprites.h"

const void __at(255) __bank_scene_8;

const struct scene_t scene_8 = {
  .width = 32,
  .height = 18,
  .type = SCENE_TYPE_PLATFORM,
  .background = TO_FAR_PTR_T(background_8),
  .collisions = TO_FAR_PTR_T(scene_8_collisions),
  .colors = TO_FAR_PTR_T(scene_8_colors),
  .palette = TO_FAR_PTR_T(palette_2),
  .sprite_palette = TO_FAR_PTR_T(palette_5),
  .player_sprite = TO_FAR_PTR_T(spritesheet_0),    
  .n_actors = 1,
  .n_triggers = 1,
  .n_sprites = 1,
  .actors = TO_FAR_PTR_T(scene_8_actors),
  .triggers = TO_FAR_PTR_T(scene_8_triggers),
  .sprites = TO_FAR_PTR_T(scene_8_sprites)
};
