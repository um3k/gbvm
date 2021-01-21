#pragma bank 2

#include "states/Adventure.h"

#include "Actor.h"
#include "Camera.h"
#include "Collision.h"
#include "GameTime.h"
#include "Input.h"
#include "Scroll.h"
#include "Trigger.h"
#include "rand.h"

#define ADVENTURE_CAMERA_DEADZONE 8

void adventure_init() __banked {
    // Set camera to follow player
    camera_offset_x = 0;
    camera_offset_y = 0;
    camera_deadzone_x = ADVENTURE_CAMERA_DEADZONE;
    camera_deadzone_y = ADVENTURE_CAMERA_DEADZONE;
}

void adventure_update() __banked {
    actor_t *hit_actor;
    UBYTE tile_x, tile_y;
    UBYTE hit_trigger = 0;
    BYTE backup_dir_x, backup_dir_y;

    player_moving = FALSE;

    UBYTE angle = 0;

    // Move
    if (INPUT_LEFT) {
        actor_set_dir(&PLAYER, -1, 0);
        angle = ANGLE_LEFT;
        player_moving = TRUE;
    } else if (INPUT_RIGHT) {
        actor_set_dir(&PLAYER, 1, 0);
        angle = ANGLE_RIGHT;
        player_moving = TRUE;
    }

    if (INPUT_UP) {
        actor_set_dir(&PLAYER, 0, -1);
        angle = ANGLE_UP;
        player_moving = TRUE;
    } else if (INPUT_DOWN) {
        actor_set_dir(&PLAYER, 0, 1);
        angle = ANGLE_DOWN;
        player_moving = TRUE;
    }

    if ((INPUT_LEFT || INPUT_RIGHT) && !INPUT_UP && !INPUT_DOWN) {
        PLAYER.dir_y = 0;
    } else if ((INPUT_UP || INPUT_DOWN) && !INPUT_LEFT && !INPUT_RIGHT) {
        PLAYER.dir_x = 0;
    }

    if (INPUT_LEFT && INPUT_UP) {
        angle = ANGLE_315DEG;
    } else if (INPUT_LEFT && INPUT_DOWN) {
        angle = ANGLE_225DEG;
    }
    if (INPUT_RIGHT && INPUT_UP) {
        angle = ANGLE_45DEG;
    } else if (INPUT_RIGHT && INPUT_DOWN) {
        angle = ANGLE_135DEG;
    }

    backup_dir_x = PLAYER.dir_x;
    backup_dir_y = PLAYER.dir_y;

    tile_x = (PLAYER.x + 4 + PLAYER.dir_x) >> 7;  // Add Left right Bias for Moving=True
    tile_y = (PLAYER.y + 7) >> 7;

    // if (INPUT_A_PRESSED) {
    //   hit_actor = ActorInFrontOfPlayer(8, TRUE);
    //   if (hit_actor != NO_ACTOR_COLLISON) {
    //     ScriptStart(&actors[hit_actor].events_ptr);
    //   }
    // }

    // Left Collision
    if (PLAYER.dir_x < 0) {
        if (tile_at(tile_x, tile_y)) {
            PLAYER.x = (tile_x << 7) + 4;
            PLAYER.dir_x = 0;
        } else if (tile_at(tile_x, (PLAYER.y) >> 7)) {
            PLAYER.dir_y = 1;
        }
    }

    // Right Collision
    if (PLAYER.dir_x > 0) {
        if (tile_at(tile_x + 1, tile_y)) {
            PLAYER.x = (tile_x << 7) - 5;
            PLAYER.dir_x = 0;
        } else if (tile_at(tile_x + 1, (PLAYER.y) >> 7)) {
            PLAYER.dir_y = 1;
        }
    }

    tile_x = (PLAYER.x + 4 - PLAYER.dir_x) >> 7;  // Remove LeftRight Bias to not stick
    tile_y = (PLAYER.y + PLAYER.dir_y) >> 7;

    // Up Collision
    if (PLAYER.dir_y < 0) {
        if (tile_at(tile_x, tile_y) ||     // Left Edge
            (tile_at(tile_x + 1, tile_y))  // Right edge
        ) {
            PLAYER.y = (tile_y + 1 << 7);
            PLAYER.dir_y = 0;
        }
    }

    // Down Collision
    if (PLAYER.dir_y > 0) {
        if (tile_at(tile_x, tile_y + 1) ||     // Left Edge
            (tile_at(tile_x + 1, tile_y + 1))  // Right edge
        ) {
            PLAYER.y = (tile_y << 7);
            PLAYER.dir_y = 0;
        }
    }

    if (player_moving) {
        if (!(PLAYER.dir_x > 0 | PLAYER.dir_x<0 | PLAYER.dir_y> 0 |
              PLAYER.dir_y < 0)) {
            player_moving = FALSE;
            PLAYER.dir_x = backup_dir_x;
            PLAYER.dir_y = backup_dir_y;
        }
    }

    tile_x = (PLAYER.x + 4) >> 7;
    tile_y = (PLAYER.y) >> 7;

    actor_set_anim(&PLAYER, player_moving);

    // Check for trigger collisions
    if (trigger_activate_at(tile_x, tile_y, FALSE)) {
        // If landed on a trigger don't update movement this frame
        return;
    }

    // Actor Collisions
    hit_actor = actor_overlapping_player(FALSE);
    if (hit_actor != NULL && hit_actor->collision_group) {
        player_register_collision_with(hit_actor);
    }
    
    if (player_moving) actor_move_angle(&PLAYER, angle, PLAYER.move_speed);
}
