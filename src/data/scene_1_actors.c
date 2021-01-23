#pragma bank 255

// Scene: Underground
// Actors

#include "gbs_types.h"
#include "data/spritesheet_6.h"
#include "data/spritesheet_1.h"
#include "data/spritesheet_7.h"
#include "data/spritesheet_8.h"
#include "data/script_s1a0_interact.h"
#include "data/script_s1a1_interact.h"
#include "data/script_s1a2_interact.h"
#include "data/script_s1a3_interact.h"
#include "data/script_s1a4_interact.h"

const void __at(255) __bank_scene_1_actors;

const struct actor_t scene_1_actors[] = {
  {
    // Sign Post,
    .pos = {
      .x = 56 * 16,
      .y = 200 * 16,
    },
    .dir_x = 0,
    .dir_y = 1,
    .sprite = TO_FAR_PTR_T(spritesheet_6),
    .sprite_type = 0,
    .base_tile = 24,
    .palette = 0,
    .n_frames = 1,
    .animate = FALSE,
    .move_speed = 1,
    .anim_tick = 7,
    .frame = 0,
    .frame_start = 0,
    .frame_end = 1,
    .pinned = FALSE,
    .collision_group = COLLISION_GROUP_NONE,
    .collision_enabled = TRUE,
    .script = TO_FAR_PTR_T(script_s1a0_interact)
  },
  {
    // Ice Block,
    .pos = {
      .x = 192 * 16,
      .y = 144 * 16,
    },
    .dir_x = 0,
    .dir_y = 1,
    .sprite = TO_FAR_PTR_T(spritesheet_1),
    .sprite_type = 0,
    .base_tile = 28,
    .palette = 0,
    .n_frames = 1,
    .animate = FALSE,
    .move_speed = 2,
    .anim_tick = 7,
    .frame = 0,
    .frame_start = 0,
    .frame_end = 0,
    .pinned = FALSE,
    .collision_group = COLLISION_GROUP_NONE,
    .collision_enabled = TRUE,
    .script = TO_FAR_PTR_T(script_s1a1_interact)
  },
  {
    // Rock 3,
    .pos = {
      .x = 184 * 16,
      .y = 216 * 16,
    },
    .dir_x = 0,
    .dir_y = 1,
    .sprite = TO_FAR_PTR_T(spritesheet_7),
    .sprite_type = 0,
    .base_tile = 32,
    .palette = 0,
    .n_frames = 1,
    .animate = FALSE,
    .move_speed = 0,
    .anim_tick = 7,
    .frame = 0,
    .frame_start = 0,
    .frame_end = 0,
    .pinned = FALSE,
    .collision_group = COLLISION_GROUP_NONE,
    .collision_enabled = TRUE,
    .script = TO_FAR_PTR_T(script_s1a2_interact)
  },
  {
    // Rock 2,
    .pos = {
      .x = 168 * 16,
      .y = 216 * 16,
    },
    .dir_x = 0,
    .dir_y = 1,
    .sprite = TO_FAR_PTR_T(spritesheet_7),
    .sprite_type = 0,
    .base_tile = 32,
    .palette = 0,
    .n_frames = 1,
    .animate = FALSE,
    .move_speed = 0,
    .anim_tick = 7,
    .frame = 0,
    .frame_start = 0,
    .frame_end = 0,
    .pinned = FALSE,
    .collision_group = COLLISION_GROUP_NONE,
    .collision_enabled = TRUE,
    .script = TO_FAR_PTR_T(script_s1a3_interact)
  },
  {
    // Rock 1,
    .pos = {
      .x = 152 * 16,
      .y = 216 * 16,
    },
    .dir_x = 0,
    .dir_y = 1,
    .sprite = TO_FAR_PTR_T(spritesheet_7),
    .sprite_type = 0,
    .base_tile = 32,
    .palette = 0,
    .n_frames = 1,
    .animate = FALSE,
    .move_speed = 0,
    .anim_tick = 7,
    .frame = 0,
    .frame_start = 0,
    .frame_end = 0,
    .pinned = FALSE,
    .collision_group = COLLISION_GROUP_NONE,
    .collision_enabled = TRUE,
    .script = TO_FAR_PTR_T(script_s1a4_interact)
  },
  {
    // Hidden Stairs,
    .pos = {
      .x = 88 * 16,
      .y = 96 * 16,
    },
    .dir_x = 0,
    .dir_y = 1,
    .sprite = TO_FAR_PTR_T(spritesheet_8),
    .sprite_type = 0,
    .base_tile = 36,
    .palette = 0,
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
  }
};
