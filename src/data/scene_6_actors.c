#pragma bank 255

// Scene: Dancefloor
// Actors

#include "gbs_types.h"
#include "data/spritesheet_9.h"

const void __at(255) __bank_scene_6_actors;

const struct actor_t scene_6_actors[] = {
  {
    // Actor 1,
    .pos = {
      .x = 48 * 16,
      .y = 104 * 16,
    },
    .dir_x = 0,
    .dir_y = 1,
    .sprite = TO_FAR_PTR_T(spritesheet_9),
    .sprite_type = 2,
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
    .collision_enabled = TRUE
  },
  {
    // Actor 2,
    .pos = {
      .x = 96 * 16,
      .y = 104 * 16,
    },
    .dir_x = 0,
    .dir_y = 1,
    .sprite = TO_FAR_PTR_T(spritesheet_9),
    .sprite_type = 2,
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
    .collision_enabled = TRUE
  }
};
