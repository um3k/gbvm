#pragma bank 255

// Scene: Platform
// Actors

#include "gbs_types.h"
#include "data/spritesheet_13.h"
#include "data/script_s5a0_update.h"
#include "data/script_s5a0_interact.h"
#include "data/spritesheet_7.h"
#include "data/script_s5a1_interact.h"
#include "data/spritesheet_6.h"
#include "data/script_s5a2_interact.h"

BANKREF(scene_5_actors)

const struct actor_t scene_5_actors[] = {
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
        .sprite = TO_FAR_PTR_T(spritesheet_13),
        .move_speed = 8,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_1,
        .collision_enabled = TRUE,
        .script_update = TO_FAR_PTR_T(script_s5a0_update),
        .script = TO_FAR_PTR_T(script_s5a0_interact),
        .reserve_tiles = 4
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
        .sprite = TO_FAR_PTR_T(spritesheet_7),
        .move_speed = 16,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s5a1_interact),
        .reserve_tiles = 0
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
        .sprite = TO_FAR_PTR_T(spritesheet_6),
        .move_speed = 16,
        .anim_tick = 31,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s5a2_interact),
        .reserve_tiles = 0
    }
};
