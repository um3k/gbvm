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
      .y = 208 * 16,
    },
    .dir = DIR_DOWN,
    .sprite = TO_FAR_PTR_T(spritesheet_6),
    .palette = 0,
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
      .y = 152 * 16,
    },
    .dir = DIR_DOWN,
    .sprite = TO_FAR_PTR_T(spritesheet_1),
    .palette = 0,
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
      .y = 224 * 16,
    },
    .dir = DIR_DOWN,
    .sprite = TO_FAR_PTR_T(spritesheet_7),
    .palette = 0,
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
      .y = 224 * 16,
    },
    .dir = DIR_DOWN,
    .sprite = TO_FAR_PTR_T(spritesheet_7),
    .palette = 0,
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
      .y = 224 * 16,
    },
    .dir = DIR_DOWN,
    .sprite = TO_FAR_PTR_T(spritesheet_7),
    .palette = 0,
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
      .y = 104 * 16,
    },
    .dir = DIR_DOWN,
    .sprite = TO_FAR_PTR_T(spritesheet_8),
    .palette = 0,
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
