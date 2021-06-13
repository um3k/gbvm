#pragma bank 255

// Scene: Underground
// Actors

#include "gbs_types.h"
#include "data/spritesheet_6.h"
#include "data/script_s3a0_interact.h"
#include "data/spritesheet_7.h"
#include "data/script_s3a1_interact.h"
#include "data/spritesheet_8.h"
#include "data/script_s3a2_interact.h"
#include "data/spritesheet_8.h"
#include "data/script_s3a3_interact.h"
#include "data/spritesheet_8.h"
#include "data/script_s3a4_interact.h"
#include "data/spritesheet_9.h"

const void __at(255) __bank_scene_3_actors;

const struct actor_t scene_3_actors[] = {
    {
        // Sign Post,
        .pos = {
            .x = 56 * 16,
            .y = 200 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_6),
        .move_speed = 16,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s3a0_interact)
    },
    {
        // Ice Block,
        .pos = {
            .x = 192 * 16,
            .y = 144 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_7),
        .move_speed = 32,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s3a1_interact)
    },
    {
        // Rock 3,
        .pos = {
            .x = 184 * 16,
            .y = 216 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_8),
        .move_speed = 8,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s3a2_interact)
    },
    {
        // Rock 2,
        .pos = {
            .x = 168 * 16,
            .y = 216 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_8),
        .move_speed = 8,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s3a3_interact)
    },
    {
        // Rock 1,
        .pos = {
            .x = 152 * 16,
            .y = 216 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_8),
        .move_speed = 8,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s3a4_interact)
    },
    {
        // Hidden Stairs,
        .pos = {
            .x = 88 * 16,
            .y = 96 * 16
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
        .collision_enabled = TRUE
    }
};
