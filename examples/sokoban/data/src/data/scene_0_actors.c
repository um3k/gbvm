#pragma bank 255

// Scene: Level 1
// Actors

#include "gbs_types.h"
#include "data/spritesheet_1.h"
#include "data/script_s0a0_interact.h"
#include "data/spritesheet_1.h"
#include "data/script_s0a1_interact.h"

const void __at(255) __bank_scene_0_actors;

const struct actor_t scene_0_actors[] = {
    {
        // Box,
        .pos = {
            .x = 80 * 16,
            .y = 48 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 0,
            .right = 16,
            .top = -16
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_1),
        .palette = 0,
        .move_speed = 16,
        .anim_tick = 3,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s0a0_interact)
    },
    {
        // Box,
        .pos = {
            .x = 80 * 16,
            .y = 96 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 0,
            .right = 16,
            .top = -16
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_1),
        .palette = 0,
        .move_speed = 16,
        .anim_tick = 3,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s0a1_interact)
    }
};
