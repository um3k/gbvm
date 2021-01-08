#pragma bank 255

// Scene: Underground
// Actors

#include "gbs_types.h"
#include "data/script_s1a0_interact.h"
#include "data/script_s1a1_interact.h"
#include "data/script_s1a2_interact.h"
#include "data/script_s1a3_interact.h"
#include "data/script_s1a4_interact.h"

const void __at(255) __bank_scene_1_actors;

const struct actor_t scene_1_actors[] = {
  {
    // Sign Post,
    .x = 56,
    .y = 200,
    .dir_x = 0,
    .dir_y = 1,
    .sprite_no = 0,
    .sprite = 6,
    .sprite_type = 0,
    .palette = 0,
    .n_frames = 1,
    .animate = FALSE,
    .move_speed = 1,
    .anim_tick = 7,
    .frame = 24,
    .frame_start = 24,
    .frame_end = 28,
    .pinned = FALSE,
    .collision_group = 0,
    .collision_enabled = TRUE,    
    .script = TO_FAR_PTR_T(script_s1a0_interact)
  },
  {
    // Ice Block,
    .x = 192,
    .y = 144,
    .dir_x = 0,
    .dir_y = 1,
    .sprite_no = 0,
    .sprite = 7,
    .sprite_type = 0,
    .palette = 0,
    .n_frames = 1,
    .animate = FALSE,
    .move_speed = 2,
    .anim_tick = 7,
    .frame = 28,
    .frame_start = 28,
    .frame_end = 32,
    .pinned = FALSE,
    .collision_group = 0,
    .collision_enabled = TRUE,    
    .script = TO_FAR_PTR_T(script_s1a1_interact)
  },
  {
    // Rock 3,
    .x = 184,
    .y = 216,
    .dir_x = 0,
    .dir_y = 1,
    .sprite_no = 0,
    .sprite = 8,
    .sprite_type = 0,
    .palette = 0,
    .n_frames = 1,
    .animate = FALSE,
    .move_speed = 0,
    .anim_tick = 7,
    .frame = 32,
    .frame_start = 32,
    .frame_end = 36,
    .pinned = FALSE,
    .collision_group = 0,
    .collision_enabled = TRUE,    
    .script = TO_FAR_PTR_T(script_s1a2_interact)
  },
  {
    // Rock 2,
    .x = 168,
    .y = 216,
    .dir_x = 0,
    .dir_y = 1,
    .sprite_no = 0,
    .sprite = 8,
    .sprite_type = 0,
    .palette = 0,
    .n_frames = 1,
    .animate = FALSE,
    .move_speed = 0,
    .anim_tick = 7,
    .frame = 32,
    .frame_start = 32,
    .frame_end = 36,
    .pinned = FALSE,
    .collision_group = 0,
    .collision_enabled = TRUE,    
    .script = TO_FAR_PTR_T(script_s1a3_interact)
  },
  {
    // Rock 1,
    .x = 152,
    .y = 216,
    .dir_x = 0,
    .dir_y = 1,
    .sprite_no = 0,
    .sprite = 8,
    .sprite_type = 0,
    .palette = 0,
    .n_frames = 1,
    .animate = FALSE,
    .move_speed = 0,
    .anim_tick = 7,
    .frame = 32,
    .frame_start = 32,
    .frame_end = 36,
    .pinned = FALSE,
    .collision_group = 0,
    .collision_enabled = TRUE,    
    .script = TO_FAR_PTR_T(script_s1a4_interact)
  },
  {
    // Hidden Stairs,
    .x = 88,
    .y = 96,
    .dir_x = 0,
    .dir_y = 1,
    .sprite_no = 0,
    .sprite = 9,
    .sprite_type = 0,
    .palette = 0,
    .n_frames = 1,
    .animate = FALSE,
    .move_speed = 1,
    .anim_tick = 7,
    .frame = 36,
    .frame_start = 36,
    .frame_end = 40,
    .pinned = FALSE,
    .collision_group = 0,
    .collision_enabled = TRUE    
  }
};
