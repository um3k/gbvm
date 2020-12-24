#pragma bank 255

// Scene: Cave
// Actors

#include "data/data_types.h"
#include "data/script_s0a2_interact.h"

const void __at(255) __bank_scene_0_actors;

const struct actor_t scene_0_actors[] = {
  {
    // Actor 1,
    .x = 4,
    .y = 6,
    .sprite = 6,
    .sprite_type = 0,
    .palette = 1,
    .n_frames = 1,
    .initial_frame = 0,
    .animate = FALSE,
    .direction = 1,
    .move_speed = 1,
    .anim_speed = 3,
    .pinned = FALSE,
    .collision_group = 0
  },
  {
    // Fire,
    .x = 4,
    .y = 4,
    .sprite = 7,
    .sprite_type = 0,
    .palette = 0,
    .n_frames = 4,
    .initial_frame = 0,
    .animate = TRUE,
    .direction = 1,
    .move_speed = 1,
    .anim_speed = 4,
    .pinned = FALSE,
    .collision_group = 0
  },
  {
    // Sage,
    .x = 9,
    .y = 7,
    .sprite = 11,
    .sprite_type = 0,
    .palette = 1,
    .n_frames = 1,
    .initial_frame = 0,
    .animate = FALSE,
    .direction = 1,
    .move_speed = 1,
    .anim_speed = 3,
    .pinned = FALSE,
    .collision_group = 0,
    .script = TO_FAR_PTR_T(script_s0a2_interact)
  },
  {
    // Actor 4,
    .x = 14,
    .y = 6,
    .sprite = 6,
    .sprite_type = 0,
    .palette = 1,
    .n_frames = 1,
    .initial_frame = 0,
    .animate = FALSE,
    .direction = 1,
    .move_speed = 1,
    .anim_speed = 3,
    .pinned = FALSE,
    .collision_group = 0
  },
  {
    // Fire,
    .x = 14,
    .y = 4,
    .sprite = 7,
    .sprite_type = 0,
    .palette = 0,
    .n_frames = 4,
    .initial_frame = 2,
    .animate = TRUE,
    .direction = 1,
    .move_speed = 1,
    .anim_speed = 4,
    .pinned = FALSE,
    .collision_group = 0
  }
};
