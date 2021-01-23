#pragma bank 255

// Scene: Cave
// Actors

#include "gbs_types.h"
#include "data/spritesheet_2.h"
#include "data/spritesheet_3.h"
#include "data/spritesheet_4.h"
#include "data/spritesheet_5.h"
#include "data/script_s0a2_interact.h"
#include "data/script_s0a5_interact.h"

const void __at(255) __bank_scene_0_actors;

const struct actor_t scene_0_actors[] = {
  {
    // Actor 1,
    .pos = {
      .x = 32 * 16,
      .y = 48 * 16,
    },
    .dir_x = 0,
    .dir_y = 1,
    .sprite = TO_FAR_PTR_T(spritesheet_2),
    .sprite_type = 0,
    .base_tile = 24,
    .palette = 1,
    .n_frames = 1,
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
    // Fire,
    .pos = {    
      .x = 32 * 16,
      .y = 32 * 16,
    },
    .dir_x = 0,
    .dir_y = 1,
    .sprite = TO_FAR_PTR_T(spritesheet_3),
    .sprite_type = 0,
    .base_tile = 28,    
    .palette = 0,
    .n_frames = 4,
    .animate = TRUE,
    .move_speed = 1,
    .anim_tick = 7,
    .frame = 0,
    .frame_start = 0,
    .frame_end = 4,
    .pinned = FALSE,
    .collision_group = COLLISION_GROUP_NONE,
    .collision_enabled = TRUE
  },
  {
    // Sage,
    .pos = {
      .x = 72 * 16,
      .y = 56 * 16,
    },
    .dir_x = 0,
    .dir_y = 1,
    .sprite = TO_FAR_PTR_T(spritesheet_4),
    .sprite_type = 0,
    .base_tile = 44,
    .palette = 1,
    .n_frames = 1,
    .animate = FALSE,
    .move_speed = 1,
    .anim_tick = 7,
    .frame = 0,
    .frame_start = 0,
    .frame_end = 0,
    .pinned = FALSE,
    .collision_group = COLLISION_GROUP_NONE,
    .collision_enabled = TRUE,
    .script = TO_FAR_PTR_T(script_s0a2_interact)
  },
  {
    // Actor 4,
    .pos = {    
      .x = 112 * 16,
      .y = 48 * 16,
    },
    .dir_x = 0,
    .dir_y = 1,
    .sprite = TO_FAR_PTR_T(spritesheet_2),
    .sprite_type = 0,
    .base_tile = 24,    
    .palette = 1,
    .n_frames = 1,
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
    // Fire,
    .pos = {
      .x = 112 * 16,
      .y = 32 * 16,
    },
    .dir_x = 0,
    .dir_y = 1,
    .sprite = TO_FAR_PTR_T(spritesheet_3),
    .sprite_type = 0,
    .base_tile = 28,    
    .palette = 0,
    .n_frames = 4,
    .animate = TRUE,
    .move_speed = 1,
    .anim_tick = 7,
    .frame = 0,
    .frame_start = 0,
    .frame_end = 4,
    .pinned = FALSE,
    .collision_group = COLLISION_GROUP_NONE,
    .collision_enabled = TRUE
  },
  {
    // Savepoint,
    .pos = {
      .x = 104 * 16,
      .y = 88 * 16,
    },
    .dir_x = 0,
    .dir_y = 1,
    .sprite = TO_FAR_PTR_T(spritesheet_5),
    .sprite_type = 0,
    .base_tile = 48,
    .palette = 0,
    .n_frames = 2,
    .animate = TRUE,
    .move_speed = 1,
    .anim_tick = 31,
    .frame = 0,
    .frame_start = 0,
    .frame_end = 2,
    .pinned = FALSE,
    .collision_group = 0,
    .collision_enabled = TRUE,
    .script = TO_FAR_PTR_T(script_s0a5_interact)
  }
};
