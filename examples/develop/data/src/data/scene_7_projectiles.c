#pragma bank 255

// Scene: Outside
// Projectiles

#include "gbs_types.h"
#include "data/spritesheet_1.h"
#include "data/spritesheet_1.h"

BANKREF(scene_7_projectiles)

const struct projectile_def_t scene_7_projectiles[] = {
    {
        // Projectile 0,
        .sprite = TO_FAR_PTR_T(spritesheet_1),
        .move_speed = 32,
        .life_time = 60,
        .collision_group = COLLISION_GROUP_3,
        .collision_mask = COLLISION_GROUP_1,
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .anim_tick = 15,
        .animations = {
            {
                .start = 0,
                .end = 1
            },
            {
                .start = 2,
                .end = 3
            },
            {
                .start = 4,
                .end = 5
            },
            {
                .start = 6,
                .end = 7
            }
        },
        .initial_offset = 256
    },
    {
        // Projectile 1,
        .sprite = TO_FAR_PTR_T(spritesheet_1),
        .move_speed = 32,
        .life_time = 180,
        .collision_group = COLLISION_GROUP_1,
        .collision_mask = COLLISION_GROUP_1 | COLLISION_GROUP_2 | COLLISION_GROUP_3 | COLLISION_GROUP_PLAYER,
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .anim_tick = 15,
        .animations = {
            {
                .start = 0,
                .end = 1
            },
            {
                .start = 2,
                .end = 3
            },
            {
                .start = 4,
                .end = 5
            },
            {
                .start = 6,
                .end = 7
            }
        },
        .initial_offset = 0
    }
};
