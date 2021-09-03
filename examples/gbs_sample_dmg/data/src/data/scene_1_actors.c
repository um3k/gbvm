#pragma bank 255

// Scene: Cave
// Actors

#include "gbs_types.h"
#include "data/spritesheet_7.h"
#include "data/spritesheet_8.h"
#include "data/spritesheet_9.h"
#include "data/script_s1a2_interact.h"
#include "data/spritesheet_7.h"
#include "data/spritesheet_8.h"
#include "data/spritesheet_10.h"
#include "data/script_s1a5_interact.h"
#include "data/spritesheet_11.h"

BANKREF(scene_1_actors)

const struct actor_t scene_1_actors[] = {
    {
        // Actor 1,
        .pos = {
            .x = 32 * 16,
            .y = 48 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_7),
        .move_speed = 16,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE
    },
    {
        // Actor 2,
        .pos = {
            .x = 32 * 16,
            .y = 32 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_8),
        .move_speed = 16,
        .anim_tick = 7,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE
    },
    {
        // Actor 3,
        .pos = {
            .x = 72 * 16,
            .y = 56 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_9),
        .move_speed = 16,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s1a2_interact)
    },
    {
        // Actor 4,
        .pos = {
            .x = 112 * 16,
            .y = 48 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_7),
        .move_speed = 16,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE
    },
    {
        // Actor 5,
        .pos = {
            .x = 112 * 16,
            .y = 32 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_8),
        .move_speed = 16,
        .anim_tick = 7,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE
    },
    {
        // Actor 6,
        .pos = {
            .x = 112 * 16,
            .y = 88 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_10),
        .move_speed = 16,
        .anim_tick = 31,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s1a5_interact)
    },
    {
        // Actor 7,
        .pos = {
            .x = 32 * 16,
            .y = 88 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_11),
        .move_speed = 16,
        .anim_tick = 3,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE
    }
};
