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
    .dir_x = 0,
    .dir_y = 1,
    .bounds = {
      .left = 2,
      .right = 14,
      .top = -14,
      .bottom = 0
    },
    .sprite = TO_FAR_PTR_T(spritesheet_1),
    .sprite_type = 0,
    .base_tile = 24,
    .palette = 0,
    .n_frames = 2,
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
