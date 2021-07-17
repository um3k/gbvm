#pragma bank 255

// Scene: Deeper Underground
// Actors

#include "gbs_types.h"
#include "data/spritesheet_13.h"
#include "data/script_s6a0_interact.h"

BANKREF(scene_6_actors)

const struct actor_t scene_6_actors[] = {
    {
        // Chest,
        .pos = {
            .x = 216 * 16,
            .y = 120 * 16
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
        .script = TO_FAR_PTR_T(script_s6a0_interact)
    }
};
