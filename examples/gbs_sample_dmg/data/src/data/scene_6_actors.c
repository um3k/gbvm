#pragma bank 255

// Scene: Underground
// Actors

#include "gbs_types.h"
#include "data/spritesheet_2.h"
#include "data/script_s6a0_interact.h"
#include "data/spritesheet_15.h"
#include "data/script_s6a1_interact.h"
#include "data/spritesheet_1.h"
#include "data/script_s6a2_interact.h"
#include "data/spritesheet_1.h"
#include "data/script_s6a3_interact.h"
#include "data/spritesheet_1.h"
#include "data/script_s6a4_interact.h"

BANKREF(scene_6_actors)

const struct actor_t scene_6_actors[] = {
    {
        // Actor 1,
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
        .sprite = TO_FAR_PTR_T(spritesheet_2),
        .move_speed = 16,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s6a0_interact),
        .reserve_tiles = 0
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
        .sprite = TO_FAR_PTR_T(spritesheet_15),
        .move_speed = 32,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s6a1_interact),
        .reserve_tiles = 0
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
        .sprite = TO_FAR_PTR_T(spritesheet_1),
        .move_speed = 8,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s6a2_interact),
        .reserve_tiles = 0
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
        .sprite = TO_FAR_PTR_T(spritesheet_1),
        .move_speed = 8,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s6a3_interact),
        .reserve_tiles = 0
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
        .sprite = TO_FAR_PTR_T(spritesheet_1),
        .move_speed = 8,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s6a4_interact),
        .reserve_tiles = 0
    }
};
