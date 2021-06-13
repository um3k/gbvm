#pragma bank 255

// Scene: Dancefloor
// Actors

#include "gbs_types.h"
#include "data/spritesheet_16.h"
#include "data/spritesheet_14.h"

const void __at(255) __bank_scene_9_actors;

const struct actor_t scene_9_actors[] = {
    {
        // Actor 1,
        .pos = {
            .x = 32 * 16,
            .y = 104 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_16),
        .move_speed = 16,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE
    },
    {
        // Actor 2,
        .pos = {
            .x = 112 * 16,
            .y = 104 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_14),
        .move_speed = 16,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE
    }
};
