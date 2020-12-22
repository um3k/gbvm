#pragma bank 255

// Scene: Underground
// Actors

#include "data/data_types.h"
#include "data/script_s1a0_interact.h"
#include "data/script_s1a1_interact.h"
#include "data/script_s1a2_interact.h"
#include "data/script_s1a3_interact.h"
#include "data/script_s1a4_interact.h"

const void __at(255) __bank_scene_1_actors;

const struct actor_t scene_1_actors[] = {
  {
    // Sign Post,
    .x = 7,
    .y = 25,
    .sprite = 6,
    .sprite_type = 0,
    .palette = 0,
    .n_frames = 1,
    .initial_frame = 0,
    .animate = FALSE,
    .direction = 1,
    .move_speed = 1,
    .anim_speed = 3,
    .pinned = FALSE,
    .collision_group = 0,
    .script = TO_FAR_PTR_T(script_s1a0_interact)
  },
  {
    // Ice Block,
    .x = 24,
    .y = 18,
    .sprite = 7,
    .sprite_type = 0,
    .palette = 0,
    .n_frames = 1,
    .initial_frame = 0,
    .animate = FALSE,
    .direction = 1,
    .move_speed = 2,
    .anim_speed = 3,
    .pinned = FALSE,
    .collision_group = 0,
    .script = TO_FAR_PTR_T(script_s1a1_interact)
  },
  {
    // Rock 3,
    .x = 23,
    .y = 27,
    .sprite = 8,
    .sprite_type = 0,
    .palette = 0,
    .n_frames = 1,
    .initial_frame = 0,
    .animate = FALSE,
    .direction = 1,
    .move_speed = 0,
    .anim_speed = 3,
    .pinned = FALSE,
    .collision_group = 0,
    .script = TO_FAR_PTR_T(script_s1a2_interact)
  },
  {
    // Rock 2,
    .x = 21,
    .y = 27,
    .sprite = 8,
    .sprite_type = 0,
    .palette = 0,
    .n_frames = 1,
    .initial_frame = 0,
    .animate = FALSE,
    .direction = 1,
    .move_speed = 0,
    .anim_speed = 3,
    .pinned = FALSE,
    .collision_group = 0,
    .script = TO_FAR_PTR_T(script_s1a3_interact)
  },
  {
    // Rock 1,
    .x = 19,
    .y = 27,
    .sprite = 8,
    .sprite_type = 0,
    .palette = 0,
    .n_frames = 1,
    .initial_frame = 0,
    .animate = FALSE,
    .direction = 1,
    .move_speed = 0,
    .anim_speed = 3,
    .pinned = FALSE,
    .collision_group = 0,
    .script = TO_FAR_PTR_T(script_s1a4_interact)
  },
  {
    // Hidden Stairs,
    .x = 11,
    .y = 12,
    .sprite = 9,
    .sprite_type = 0,
    .palette = 0,
    .n_frames = 1,
    .initial_frame = 0,
    .animate = FALSE,
    .direction = 1,
    .move_speed = 1,
    .anim_speed = 3,
    .pinned = FALSE,
    .collision_group = 0
  }
};
