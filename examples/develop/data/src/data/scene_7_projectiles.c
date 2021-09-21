#pragma bank 255

// Scene: Outside
// Projectiles

#include "gbs_types.h"
#include "data/spritesheet_1.h"

BANKREF(scene_7_projectiles)

const struct projectile_def_t scene_7_projectiles[] = {
    {
        // Projectile 0,
        .sprite = TO_FAR_PTR_T(spritesheet_1),
        .move_speed = 32,
        .life_time = 180,
        .collision_group = COLLISION_GROUP_1,
        .collision_mask = COLLISION_GROUP_1 | COLLISION_GROUP_2 | COLLISION_GROUP_3 | COLLISION_GROUP_PLAYER,
        .bounds = {
            .left = 4,
            .bottom = 3,
            .right = 11,
            .top = -4
        },
        .anim_tick = 15,
        .frame = 0,
        .frame_start = 0,
        .frame_end = 1
    }
};
