#pragma bank 255

// Scene: Outside
// Actors

#include "gbs_types.h"
#include "data/spritesheet_14.h"
#include "data/script_s7a0_update.h"

const void __at(255) __bank_scene_7_actors;

const struct actor_t scene_7_actors[] = {
    {
        // Actor 1,
        .pos = {
            .x = 168 * 16,
            .y = 80 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_14),
        .move_speed = 12,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script_update = TO_FAR_PTR_T(script_s7a0_update)
    }
};
