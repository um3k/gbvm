#pragma bank 255

// Scene: Underground
// Actors

#include "gbs_types.h"
#include "data/spritesheet_13.h"
#include "data/script_s5a0_interact.h"
#include "data/spritesheet_21.h"
#include "data/script_s5a1_interact.h"
#include "data/spritesheet_8.h"
#include "data/script_s5a2_interact.h"
#include "data/spritesheet_8.h"
#include "data/script_s5a3_interact.h"
#include "data/spritesheet_8.h"
#include "data/script_s5a4_interact.h"
#include "data/spritesheet_22.h"

BANKREF(scene_5_actors)

const struct actor_t scene_5_actors[] = {
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
        .sprite = TO_FAR_PTR_T(spritesheet_13),
        .move_speed = 16,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s5a0_interact)
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
        .sprite = TO_FAR_PTR_T(spritesheet_21),
        .move_speed = 32,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s5a1_interact)
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
        .script = TO_FAR_PTR_T(script_s5a2_interact)
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
        .script = TO_FAR_PTR_T(script_s5a3_interact)
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
        .script = TO_FAR_PTR_T(script_s5a4_interact)
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
        .sprite = TO_FAR_PTR_T(spritesheet_22),
        .move_speed = 16,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE
    }
};
