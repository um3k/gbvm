#pragma bank 255

// Scene: Launch Site
// Actors

#include "gbs_types.h"
#include "data/spritesheet_31.h"
#include "data/spritesheet_32.h"
#include "data/script_s12a1_interact.h"
#include "data/script_s12a1_update.h"
#include "data/spritesheet_33.h"
#include "data/script_s12a2_interact.h"
#include "data/spritesheet_33.h"
#include "data/script_s12a3_interact.h"
#include "data/spritesheet_33.h"
#include "data/script_s12a4_interact.h"
#include "data/spritesheet_33.h"
#include "data/script_s12a5_interact.h"

BANKREF(scene_12_actors)

const struct actor_t scene_12_actors[] = {
    {
        // Pod Door,
        .pos = {
            .x = 120 * 16,
            .y = 72 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_31),
        .move_speed = 16,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE
    },
    {
        // Scientist,
        .pos = {
            .x = 64 * 16,
            .y = 96 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_UP,
        .sprite = TO_FAR_PTR_T(spritesheet_32),
        .move_speed = 16,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s12a1_interact),
        .script_update = TO_FAR_PTR_T(script_s12a1_update)
    },
    {
        // Machine,
        .pos = {
            .x = 32 * 16,
            .y = 64 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_33),
        .move_speed = 16,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s12a2_interact)
    },
    {
        // Machine,
        .pos = {
            .x = 16 * 16,
            .y = 64 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_33),
        .move_speed = 16,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s12a3_interact)
    },
    {
        // Machine,
        .pos = {
            .x = 48 * 16,
            .y = 80 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_33),
        .move_speed = 16,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s12a4_interact)
    },
    {
        // Machine,
        .pos = {
            .x = 64 * 16,
            .y = 80 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_33),
        .move_speed = 16,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s12a5_interact)
    }
};
