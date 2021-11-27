#pragma bank 255

// Scene: Outside
// Actors

#include "gbs_types.h"
#include "data/spritesheet_15.h"
#include "data/script_s7a0_interact.h"
#include "data/script_s7a0_update.h"
#include "data/script_s7a0_hit1.h"
#include "data/spritesheet_3.h"
#include "data/script_s7a1_update.h"

BANKREF(scene_7_actors)

const struct actor_t scene_7_actors[] = {
    {
        // Actor 1,
        .pos = {
            .x = 168 * 16,
            .y = 80 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_15),
        .move_speed = 12,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_1,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s7a0_interact),
        .script_update = TO_FAR_PTR_T(script_s7a0_update),
        .script_hit1 = TO_FAR_PTR_T(script_s7a0_hit1),
        .exclusive_sprite = 0
    },
    {
        // Actor 2,
        .pos = {
            .x = 24 * 16,
            .y = 64 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(spritesheet_3),
        .move_speed = 16,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script_update = TO_FAR_PTR_T(script_s7a1_update),
        .exclusive_sprite = 0
    }
};
