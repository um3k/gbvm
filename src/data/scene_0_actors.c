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
      .y = 56 * 16,
    },
    .dir = DIR_DOWN,
    .sprite = TO_FAR_PTR_T(spritesheet_2),
    .palette = 1,
    .animate = FALSE,
    .move_speed = 1,
    .anim_tick = 7,
    .pinned = FALSE,
    .collision_group = COLLISION_GROUP_NONE,
    .collision_enabled = TRUE
  },
  {
    // Fire,
    .pos = {    
      .x = 32 * 16,
      .y = 40 * 16,
    },
    .dir = DIR_DOWN,
    .sprite = TO_FAR_PTR_T(spritesheet_3),
    .palette = 0,
    .animate = TRUE,
    .move_speed = 1,
    .anim_tick = 7,
    .pinned = FALSE,
    .collision_group = COLLISION_GROUP_NONE,
    .collision_enabled = TRUE
  },
  {
    // Sage,
    .pos = {
      .x = 72 * 16,
      .y = 64 * 16,
    },
    .dir = DIR_DOWN,
    .sprite = TO_FAR_PTR_T(spritesheet_4),
    .palette = 1,
    .animate = FALSE,
    .move_speed = 1,
    .anim_tick = 7,
    .pinned = FALSE,
    .collision_group = COLLISION_GROUP_NONE,
    .collision_enabled = TRUE,
    .script = TO_FAR_PTR_T(script_s0a2_interact)
  },
  {
    // Actor 4,
    .pos = {    
      .x = 112 * 16,
      .y = 56 * 16,
    },
    .dir = DIR_DOWN,
    .sprite = TO_FAR_PTR_T(spritesheet_2),
    .palette = 1,
    .animate = FALSE,
    .move_speed = 1,
    .anim_tick = 7,
    .pinned = FALSE,
    .collision_group = COLLISION_GROUP_NONE,
    .collision_enabled = TRUE
  },
  {
    // Fire,
    .pos = {
      .x = 112 * 16,
      .y = 40 * 16,
    },
    .dir = DIR_DOWN,
    .sprite = TO_FAR_PTR_T(spritesheet_3),
    .palette = 0,
    .animate = TRUE,
    .move_speed = 1,
    .anim_tick = 7,
    .pinned = FALSE,
    .collision_group = COLLISION_GROUP_NONE,
    .collision_enabled = TRUE
  },
  {
    // Savepoint,
    .pos = {
      .x = 104 * 16,
      .y = 96 * 16,
    },
    .dir = DIR_DOWN,
    .sprite = TO_FAR_PTR_T(spritesheet_5),
    .palette = 0,
    .animate = TRUE,
    .move_speed = 1,
    .anim_tick = 31,
    .pinned = FALSE,
    .collision_group = 0,
    .collision_enabled = TRUE,
    .script = TO_FAR_PTR_T(script_s0a5_interact)
  }
};
