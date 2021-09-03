#pragma bank 255

// Scene: Sample Town
// Actors

#include "gbs_types.h"
#include "data/spritesheet_8.h"
#include "data/script_s0a0_interact.h"
#include "data/spritesheet_9.h"
#include "data/spritesheet_10.h"
#include "data/script_s0a2_interact.h"
#include "data/script_s0a2_update.h"
#include "data/spritesheet_11.h"
#include "data/script_s0a3_interact.h"
#include "data/spritesheet_12.h"
#include "data/script_s0a4_interact.h"
#include "data/spritesheet_12.h"
#include "data/script_s0a5_interact.h"
#include "data/spritesheet_13.h"
#include "data/script_s0a6_interact.h"
#include "data/spritesheet_14.h"
#include "data/script_s0a7_interact.h"
#include "data/spritesheet_15.h"

BANKREF(scene_0_actors)

const struct actor_t scene_0_actors[] = {
    {
        // Rock,
        .pos = {
            .x = 200 * 16,
            .y = 112 * 16
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
        .script = TO_FAR_PTR_T(script_s0a0_interact)
    },
    {
        // Duck,
        .pos = {
            .x = 168 * 16,
            .y = 144 * 16
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
        .anim_tick = 63,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE
    },
    {
        // Pet Owner,
        .pos = {
            .x = 192 * 16,
            .y = 352 * 16
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
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s0a2_interact),
        .script_update = TO_FAR_PTR_T(script_s0a2_update)
    },
    {
        // Cat,
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
        .sprite = TO_FAR_PTR_T(spritesheet_11),
        .move_speed = 16,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s0a3_interact)
    },
    {
        // Angry Guy,
        .pos = {
            .x = 168 * 16,
            .y = 192 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_UP,
        .sprite = TO_FAR_PTR_T(spritesheet_12),
        .move_speed = 16,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s0a4_interact)
    },
    {
        // Oblivious Guy,
        .pos = {
            .x = 168 * 16,
            .y = 128 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_12),
        .move_speed = 16,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s0a5_interact)
    },
    {
        // Sign Post,
        .pos = {
            .x = 224 * 16,
            .y = 184 * 16
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
        .script = TO_FAR_PTR_T(script_s0a6_interact)
    },
    {
        // Hider,
        .pos = {
            .x = 288 * 16,
            .y = 192 * 16
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
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s0a7_interact)
    },
    {
        // Florist,
        .pos = {
            .x = 376 * 16,
            .y = 376 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_15),
        .move_speed = 16,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE
    }
};
