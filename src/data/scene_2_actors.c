#pragma bank 255

// Scene: Scene 3
// Actors

#include "data/data_types.h"
#include "data/script_s2a0_interact.h"
#include "data/script_s2a0_update.h"

const void __at(255) __bank_scene_2_actors;

const struct actor_t scene_2_actors[] = {
  {
    // Actor 1,
    .x = 21,
    .y = 13,
    .sprite = 6,
    .sprite_type = 2,
    .palette = 0,
    .n_frames = 2,
    .initial_frame = 0,
    .animate = FALSE,
    .direction = 1,
    .move_speed = 1,
    .anim_speed = 3,
    .pinned = FALSE,
    .collision_group = 0,
    .script = TO_FAR_PTR_T(script_s2a0_interact),
    .script_update = TO_FAR_PTR_T(script_s2a0_update)
  }
};
