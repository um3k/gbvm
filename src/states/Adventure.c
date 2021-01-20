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
    WORD tile_x, tile_y;
    UBYTE hit_actor = 0;
    UBYTE hit_trigger = 0;
    BYTE backup_dir_x, backup_dir_y;

    player_moving = FALSE;

    // Move
    if (INPUT_LEFT) {
        PLAYER.dir_x = -1;
        player_moving = TRUE;
    } else if (INPUT_RIGHT) {
        PLAYER.dir_x = 1;
        player_moving = TRUE;
    }

    if (INPUT_UP) {
        PLAYER.dir_y = -1;
        player_moving = TRUE;
    } else if (INPUT_DOWN) {
        PLAYER.dir_y = 1;
        player_moving = TRUE;
    }

    if ((INPUT_LEFT || INPUT_RIGHT) && !INPUT_UP && !INPUT_DOWN) {
        PLAYER.dir_y = 0;
    } else if ((INPUT_UP || INPUT_DOWN) && !INPUT_LEFT && !INPUT_RIGHT) {
        PLAYER.dir_x = 0;
    }

    backup_dir_x = PLAYER.dir_x;
    backup_dir_y = PLAYER.dir_y;

    tile_x = (PLAYER.x + 4 + PLAYER.dir_x) >>
             3;  // Add Left right Bias for Moving=True
    tile_y = (PLAYER.y + 7) >> 3;

    // if (INPUT_A_PRESSED) {
    //   hit_actor = ActorInFrontOfPlayer(8, TRUE);
    //   if (hit_actor != NO_ACTOR_COLLISON) {
    //     ScriptStart(&actors[hit_actor].events_ptr);
    //   }
    // }

    // Left Collision
    if (PLAYER.dir_x < 0) {
        if (tile_at(tile_x, tile_y)) {
            PLAYER.x = (tile_x << 3) + 4;
            PLAYER.dir_x = 0;
        } else if (tile_at(tile_x, (PLAYER.y) >> 3)) {
            PLAYER.dir_y = 1;
        }
    }

    // Right Collision
    if (PLAYER.dir_x > 0) {
        if (tile_at(tile_x + 1, tile_y)) {
            PLAYER.x = (tile_x << 3) - 5;
            PLAYER.dir_x = 0;
        } else if (tile_at(tile_x + 1, (PLAYER.y) >> 3)) {
            PLAYER.dir_y = 1;
        }
    }

    tile_x = (PLAYER.x + 4 - PLAYER.dir_x) >>
             3;  // Remove LeftRight Bias to not stick
    tile_y = (PLAYER.y + PLAYER.dir_y) >> 3;

    // Up Collision
    if (PLAYER.dir_y < 0) {
        if (tile_at(tile_x, tile_y) ||     // Left Edge
            (tile_at(tile_x + 1, tile_y))  // Right edge
        ) {
            PLAYER.y = (tile_y + 1 << 3);
            PLAYER.dir_y = 0;
        }
    }

    // Down Collision
    if (PLAYER.dir_y > 0) {
        if (tile_at(tile_x, tile_y + 1) ||     // Left Edge
            (tile_at(tile_x + 1, tile_y + 1))  // Right edge
        ) {
            PLAYER.y = (tile_y << 3);
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

    tile_x = (PLAYER.x + 4) >> 3;
    tile_y = (PLAYER.y) >> 3;

    // // Check for trigger collisions
    // if (trigger_activate_at(tile_x, tile_y, FALSE)) {
    //   // Landed on a trigger
    //   return;
    // }

    // // Actor Collisions
    // hit_actor = ActorOverlapsPlayer(FALSE);
    // if (hit_actor && hit_actor != NO_ACTOR_COLLISON) {
    //   if (hit_actor == ActorInFrontOfPlayer(8, FALSE)) {
    //     player_moving = FALSE;
    //   }
    //   if (player_iframes == 0) {
    //     if (actors[hit_actor].collision_group) {
    //       PLAYER.hit_actor = 0;
    //       PLAYER.hit_actor = hit_actor;
    //     } else {
    //       player_iframes = 10;
    //     }
    //   }
    // }

    if (player_moving) player_move(PLAYER.dir_x, PLAYER.dir_y);
}
