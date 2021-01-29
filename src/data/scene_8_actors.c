#pragma bank 255

// Scene: Mine
// Actors

#include "gbs_types.h"
#include "data/spritesheet_1.h"
#include "data/script_s8a0_interact.h"

const void __at(255) __bank_scene_8_actors;

const struct actor_t scene_8_actors[] = {
  {
    // Actor 1,
    .pos = {
      .x = 216 * 16,
      .y = 128 * 16,
    },
    .dir = DIR_DOWN,
    .bounds = {
      .left = 2,
      .right = 14,
      .top = -14,
      .bottom = 0
    },
    .sprite = TO_FAR_PTR_T(spritesheet_1),
    .palette = 0,
    .animate = FALSE,
    .move_speed = 1,
    .anim_tick = 7,
    .frame = 0,
    .frame_start = 0,
    .frame_end = 0,
    .pinned = FALSE,
    .collision_group = COLLISION_GROUP_NONE,
    .collision_enabled = TRUE,
    .script = TO_FAR_PTR_T(script_s8a0_interact)
  }
};
