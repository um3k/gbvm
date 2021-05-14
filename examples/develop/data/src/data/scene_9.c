#pragma bank 255

// Scene: Scene 10

#include "gbs_types.h"
#include "data/background_9.h"
#include "data/spritesheet_13.h"
#include "data/scene_9_collisions.h"
#include "data/scene_9_colors.h"
#include "data/palette_2.h"
#include "data/palette_0.h"
#include "data/scene_9_actors.h"
#include "data/scene_9_triggers.h"
#include "data/scene_9_sprites.h"

const void __at(255) __bank_scene_9;

const struct scene_t scene_9 = {
  .width = 20,
  .height = 18,
  .type = SCENE_TYPE_POINTNCLICK,
  .background = TO_FAR_PTR_T(background_9),
  .collisions = TO_FAR_PTR_T(scene_9_collisions),
  .palette = TO_FAR_PTR_T(palette_2),
  .sprite_palette = TO_FAR_PTR_T(palette_0),
  .player_sprite = TO_FAR_PTR_T(spritesheet_13),
  .parallax_rows = {
    PARALLAX_STEP(0, 0, 0)
  },  
  .n_actors = 1,
  .n_triggers = 2,
  .n_sprites = 1,
  .actors = TO_FAR_PTR_T(scene_9_actors),
  .triggers = TO_FAR_PTR_T(scene_9_triggers),
  .sprites = TO_FAR_PTR_T(scene_9_sprites)
};
