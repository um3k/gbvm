#pragma bank 255

// Scene: Dancefloor
// Actors

#include "gbs_types.h"


const void __at(255) __bank_scene_6_actors;

const struct actor_t scene_6_actors[] = {
  {
    // Actor 1,
    .x = 48,
    .y = 104,
    .dir_x = 0,
    .dir_y = 1,
    .sprite_no = 0,
    .sprite = 6,
    .sprite_type = 2,
    .palette = 0,
    .n_frames = 2,
    .animate = FALSE,
    .move_speed = 1,
    .anim_tick = 7,
    .frame = 24,
    .frame_start = 24,
    .frame_end = 32,
    .pinned = FALSE,
    .collision_group = COLLISION_GROUP_NONE,
    .collision_enabled = TRUE
  },
  {
    // Actor 2,
    .x = 96,
    .y = 104,
    .dir_x = 0,
    .dir_y = 1,
    .sprite_no = 0,
    .sprite = 6,
    .sprite_type = 2,
    .palette = 0,
    .n_frames = 2,
    .animate = FALSE,
    .move_speed = 1,
    .anim_tick = 7,
    .frame = 24,
    .frame_start = 24,
    .frame_end = 32,
    .pinned = FALSE,
    .collision_group = COLLISION_GROUP_NONE,
    .collision_enabled = TRUE
  }
};
