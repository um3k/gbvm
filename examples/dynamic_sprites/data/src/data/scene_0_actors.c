#pragma bank 255

// Scene: Start
// Actors

#include "gbs_types.h"
#include "data/spritesheet_4.h"
#include "data/script_s0a0_interact.h"
#include "data/spritesheet_5.h"
#include "data/script_s0a1_interact.h"
#include "data/spritesheet_5.h"
#include "data/script_s0a2_interact.h"
#include "data/spritesheet_5.h"
#include "data/script_s0a3_interact.h"
#include "data/spritesheet_4.h"
#include "data/script_s0a4_interact.h"
#include "data/spritesheet_4.h"
#include "data/script_s0a5_interact.h"
#include "data/spritesheet_5.h"
#include "data/script_s0a6_interact.h"
#include "data/spritesheet_4.h"
#include "data/script_s0a7_interact.h"

BANKREF(scene_0_actors)

const struct actor_t scene_0_actors[] = {
    {
        // PortalLeft,
        .pos = {
            .x = 32 * 16,
            .y = 56 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_4),
        .move_speed = 16,
        .anim_tick = 7,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_1,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s0a0_interact),
        .reserve_tiles = 0
    },
    {
        // SignpostLeft,
        .pos = {
            .x = 16 * 16,
            .y = 56 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_5),
        .move_speed = 16,
        .anim_tick = 3,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s0a1_interact),
        .reserve_tiles = 0
    },
    {
        // SignpostTop,
        .pos = {
            .x = 56 * 16,
            .y = 16 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_5),
        .move_speed = 16,
        .anim_tick = 3,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s0a2_interact),
        .reserve_tiles = 0
    },
    {
        // SignpostRight,
        .pos = {
            .x = 128 * 16,
            .y = 56 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_5),
        .move_speed = 16,
        .anim_tick = 3,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s0a3_interact),
        .reserve_tiles = 0
    },
    {
        // PortalRight,
        .pos = {
            .x = 112 * 16,
            .y = 56 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_4),
        .move_speed = 16,
        .anim_tick = 7,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_1,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s0a4_interact),
        .reserve_tiles = 0
    },
    {
        // PortalTop,
        .pos = {
            .x = 72 * 16,
            .y = 16 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_4),
        .move_speed = 16,
        .anim_tick = 7,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_1,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s0a5_interact),
        .reserve_tiles = 0
    },
    {
        // SignpostBottom,
        .pos = {
            .x = 56 * 16,
            .y = 120 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_5),
        .move_speed = 16,
        .anim_tick = 3,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s0a6_interact),
        .reserve_tiles = 0
    },
    {
        // PortalBottom,
        .pos = {
            .x = 72 * 16,
            .y = 120 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_4),
        .move_speed = 16,
        .anim_tick = 7,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_1,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s0a7_interact),
        .reserve_tiles = 0
    }
};
