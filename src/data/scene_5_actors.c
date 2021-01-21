#pragma bank 255

// Scene: Scene 5
// Actors

#include "gbs_types.h"
#include "data/spritesheet_9.h"
#include "data/spritesheet_10.h"

const void __at(255) __bank_scene_5_actors;

const struct actor_t scene_5_actors[] = {
  {
    // Actor 1,
    .x = 128 * 16,
    .y = 104 * 16,
    .dir_x = -1,
    .dir_y = 0,
    .sprite = TO_FAR_PTR_T(spritesheet_9),
    .sprite_type = SPRITE_TYPE_ACTOR,
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
    .collision_group = COLLISION_GROUP_1,
    .collision_enabled = TRUE
  },
  {
    // elephant,
    .x = 32 * 16,
    .y = 72 * 16,
    .dir_x = 0,
    .dir_y = 0,
    .sprite = TO_FAR_PTR_T(spritesheet_10),
    .sprite_type = SPRITE_TYPE_ACTOR,
    .base_tile = 0x30,
    .palette = 0,
    .n_frames = 1,
    .animate = TRUE,
    .move_speed = 1,
    .anim_tick = 7,
    .frame = 0,
    .frame_start = 0,
    .frame_end = 7,
    .pinned = FALSE,
    .collision_group = COLLISION_GROUP_1,
    .collision_enabled = TRUE
  }  
};
