#pragma bank 255

// Scene: Scene 3
// Actors

#include "gbs_types.h"
#include "data/spritesheet_9.h"
#include "data/script_s2a0_interact.h"
#include "data/script_s2a0_update.h"

const void __at(255) __bank_scene_2_actors;

const struct actor_t scene_2_actors[] = {
  {
    // Actor 1,
    .pos = {
      .x = 168 * 16,
      .y = 104 * 16,
    },
    .dir = DIR_DOWN,
    .bounds = {
      .left = 0,
      .bottom = 7,
      .right = 15,
      .top = -8
    },  
    .sprite = TO_FAR_PTR_T(spritesheet_9),
    .palette = 0,
    .move_speed = 8,
    .anim_tick = 7,
    .frame = 0,
    .frame_start = 0,
    .frame_end = 2,
    .pinned = FALSE,
    .collision_group = COLLISION_GROUP_1,
    .collision_enabled = TRUE,
    .script = TO_FAR_PTR_T(script_s2a0_interact),
    .script_update = TO_FAR_PTR_T(script_s2a0_update)
  }
};
