#pragma bank 255

// Scene: Path to Sample Town
// Actors

#include "gbs_types.h"
#include "data/spritesheet_13.h"
#include "data/script_s10a0_interact.h"
#include "data/spritesheet_27.h"
#include "data/script_s10a1_interact.h"
#include "data/script_s10a1_update.h"
#include "data/spritesheet_28.h"
#include "data/script_s10a2_interact.h"
#include "data/spritesheet_27.h"
#include "data/script_s10a3_interact.h"
#include "data/script_s10a3_update.h"
#include "data/spritesheet_27.h"
#include "data/script_s10a4_interact.h"
#include "data/script_s10a4_update.h"
#include "data/spritesheet_13.h"
#include "data/script_s10a5_interact.h"
#include "data/spritesheet_18.h"
#include "data/script_s10a6_interact.h"

const void __at(255) __bank_scene_10_actors;

const struct actor_t scene_10_actors[] = {
    {
        // Sign Post,
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
        .sprite = TO_FAR_PTR_T(spritesheet_13),
        .move_speed = 16,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s10a0_interact)
    },
    {
        // Turnip 1,
        .pos = {
            .x = 576 * 16,
            .y = 104 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_27),
        .move_speed = 8,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_1,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s10a1_interact),
        .script_update = TO_FAR_PTR_T(script_s10a1_update)
    },
    {
        // Gardener,
        .pos = {
            .x = 368 * 16,
            .y = 104 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_RIGHT,
        .sprite = TO_FAR_PTR_T(spritesheet_28),
        .move_speed = 16,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s10a2_interact)
    },
    {
        // Turnip 2,
        .pos = {
            .x = 760 * 16,
            .y = 104 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_27),
        .move_speed = 8,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_1,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s10a3_interact),
        .script_update = TO_FAR_PTR_T(script_s10a3_update)
    },
    {
        // Turnip 3,
        .pos = {
            .x = 824 * 16,
            .y = 104 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_27),
        .move_speed = 8,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_1,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s10a4_interact),
        .script_update = TO_FAR_PTR_T(script_s10a4_update)
    },
    {
        // Sign Post,
        .pos = {
            .x = 1072 * 16,
            .y = 104 * 16
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
        .script = TO_FAR_PTR_T(script_s10a5_interact)
    },
    {
        // Save Point,
        .pos = {
            .x = 936 * 16,
            .y = 104 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_18),
        .move_speed = 16,
        .anim_tick = 31,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s10a6_interact)
    }
};
