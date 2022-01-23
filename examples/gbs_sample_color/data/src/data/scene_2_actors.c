#pragma bank 255

// Scene: Top House
// Actors

#include "gbs_types.h"
#include "data/spritesheet_19.h"
#include "data/script_s2a0_interact.h"
#include "data/spritesheet_20.h"
#include "data/script_s2a1_interact.h"
#include "data/spritesheet_13.h"
#include "data/script_s2a2_interact.h"
#include "data/spritesheet_13.h"
#include "data/script_s2a3_interact.h"
#include "data/spritesheet_13.h"
#include "data/script_s2a4_interact.h"

BANKREF(scene_2_actors)

const struct actor_t scene_2_actors[] = {
    {
        // Radio Guy,
        .pos = {
            .x = 96 * 16,
            .y = 40 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_19),
        .move_speed = 16,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s2a0_interact),
        .reserve_tiles = 0
    },
    {
        // Radio,
        .pos = {
            .x = 120 * 16,
            .y = 40 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_20),
        .move_speed = 16,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s2a1_interact),
        .reserve_tiles = 0
    },
    {
        // Sign Post 3,
        .pos = {
            .x = 120 * 16,
            .y = 88 * 16
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
        .script = TO_FAR_PTR_T(script_s2a2_interact),
        .reserve_tiles = 0
    },
    {
        // Sign Post 2,
        .pos = {
            .x = 24 * 16,
            .y = 88 * 16
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
        .script = TO_FAR_PTR_T(script_s2a3_interact),
        .reserve_tiles = 0
    },
    {
        // Sign Post 1,
        .pos = {
            .x = 24 * 16,
            .y = 40 * 16
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
        .script = TO_FAR_PTR_T(script_s2a4_interact),
        .reserve_tiles = 0
    }
};
