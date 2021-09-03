#pragma bank 255

// Scene: Alt Player Sprite
// Actors

#include "gbs_types.h"
#include "data/spritesheet_4.h"
#include "data/script_s1a0_interact.h"
#include "data/spritesheet_5.h"
#include "data/script_s1a1_interact.h"

BANKREF(scene_1_actors)

const struct actor_t scene_1_actors[] = {
    {
        // Portal,
        .pos = {
            .x = 64 * 16,
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
        .script = TO_FAR_PTR_T(script_s1a0_interact)
    },
    {
        // Signpost,
        .pos = {
            .x = 48 * 16,
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
        .script = TO_FAR_PTR_T(script_s1a1_interact)
    }
};
