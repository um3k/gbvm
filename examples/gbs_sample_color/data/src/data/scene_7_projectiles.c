#pragma bank 255

// Scene: Space Battle
// Projectiles

#include "gbs_types.h"
#include "data/spritesheet_0.h"
#include "data/spritesheet_2.h"

BANKREF(scene_7_projectiles)

const struct projectile_def_t scene_7_projectiles[] = {
    {
        // Projectile 0,
        .sprite = TO_FAR_PTR_T(spritesheet_0),
        .move_speed = 48,
        .life_time = NaN,
        .collision_group = COLLISION_GROUP_1,
        .collision_mask = COLLISION_GROUP_1,
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .animations = {
            {
                .start = 0,
                .end = 1
            },
            {
                .start = 0,
                .end = 1
            },
            {
                .start = 0,
                .end = 1
            },
            {
                .start = 0,
                .end = 1
            }
        },
        .initial_offset = 0
    },
    {
        // Projectile 1,
        .sprite = TO_FAR_PTR_T(spritesheet_2),
        .move_speed = 16,
        .life_time = NaN,
        .collision_group = COLLISION_GROUP_1,
        .collision_mask = COLLISION_GROUP_PLAYER,
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .animations = {
            {
                .start = 0,
                .end = 1
            },
            {
                .start = 0,
                .end = 1
            },
            {
                .start = 0,
                .end = 1
            },
            {
                .start = 0,
                .end = 1
            }
        },
        .initial_offset = 0
    }
};
