#pragma bank 2

#include "states/TopDown.h"

#include "Actor.h"
#include "Camera.h"
#include "Collision.h"
#include "DataManager.h"
#include "GameTime.h"
#include "Input.h"
#include "Trigger.h"
#include "vm.h"
#include "data/data_ptrs.h"

void topdown_init() __banked {
    camera_offset_x = 0;
    camera_offset_y = 0;
    camera_deadzone_x = 0;
    camera_deadzone_y = 0;

    if (topdown_grid == 16) {
        // Snap to 16px grid
        PLAYER.x = MUL_16(DIV_16(PLAYER.x));
        PLAYER.y = 8 + MUL_16(DIV_16(PLAYER.y));
    } else {
        PLAYER.x = MUL_8(DIV_8(PLAYER.x));
        PLAYER.y = MUL_8(DIV_8(PLAYER.y));
    }

    actor_set_frames(&PLAYER, 0, 16);
}

void topdown_update() __banked {
    actor_t *hit_actor;
    UBYTE tile_x, tile_y;

    tile_x = PLAYER.x >> 7;
    tile_y = PLAYER.y >> 7;

    // Is player on an 8x8px tile?
    if ((topdown_grid == 16 && ON_16PX_GRID(PLAYER)) ||
        (topdown_grid == 8 && ON_8PX_GRID(PLAYER))) {
        // Player landed on an tile
        // so stop movement for now
        player_moving = FALSE;

        // Check for trigger collisions
        if (trigger_activate_at(tile_x, tile_y, FALSE)) {
            // If landed on a trigger don't update movement this frame
            return;
        }

        // Check input to set player movement
        if (INPUT_RECENT_LEFT) {
            actor_set_dir(&PLAYER, -1, 0);

            // Check for collisions to left of player
            if (topdown_grid == 16) {
                UBYTE tile_left = tile_x - 2;
                if (tile_x != 0 &&
                    !(tile_at_2x2(tile_left, tile_y - 1) & COLLISION_RIGHT)) {
                    player_moving = TRUE;
                }
            } else {
                UBYTE tile_left = tile_x - 1;
                if (tile_x != 0 &&
                    !(tile_at_2x1(tile_left, tile_y) & COLLISION_RIGHT)) {
                    player_moving = TRUE;
                }
            }

        } else if (INPUT_RECENT_RIGHT) {
            actor_set_dir(&PLAYER, 1, 0);

            // Check for collisions to right of player
            if (topdown_grid == 16) {
                UBYTE tile_right = tile_x + 2;
                if (tile_x != image_tile_width - 2 &&
                    !(tile_at_2x2(tile_right, tile_y - 1) & COLLISION_LEFT)) {
                    player_moving = TRUE;
                }
            } else {
                UBYTE tile_right = tile_x + 1;
                if (tile_x != image_tile_width - 2 &&
                    !(tile_at_2x1(tile_right, tile_y) & COLLISION_LEFT)) {
                    player_moving = TRUE;
                }
            }

        } else if (INPUT_RECENT_UP) {
            actor_set_dir(&PLAYER, 0, -1);

            // Check for collisions above player
            if (topdown_grid == 16) {
                UBYTE tile_up = tile_y - 3;
                if (tile_y != 0 &&
                    !(tile_at_2x2(tile_x, tile_up) & COLLISION_BOTTOM)) {
                    player_moving = TRUE;
                }
            } else {
                UBYTE tile_up = tile_y - 1;
                if (tile_y != 0 &&
                    !(tile_at_2x1(tile_x, tile_up) & COLLISION_BOTTOM)) {
                    player_moving = TRUE;
                }
            }

        } else if (INPUT_RECENT_DOWN) {
            actor_set_dir(&PLAYER, 0, 1);

            // Check for collisions below player
            if (topdown_grid == 16) {
                UBYTE tile_down = tile_y + 1;
                if (tile_y != image_tile_height - 1 &&
                    !(tile_at_2x2(tile_x, tile_down) & COLLISION_TOP)) {
                    player_moving = TRUE;
                }
            } else {
                UBYTE tile_down = tile_y + 1;
                if (tile_y != image_tile_height - 1 &&
                    !(tile_at_2x1(tile_x, tile_down) & COLLISION_TOP)) {
                    player_moving = TRUE;
                }
            }
        }

        hit_actor = actor_overlapping_player(FALSE);
        if (hit_actor != NULL && hit_actor->collision_group) {
            player_register_collision_with(hit_actor);
        }

        // Check if walked in to actor
        if (player_moving) {
            hit_actor = actor_in_front_of_player(topdown_grid, FALSE);
            if (hit_actor != NULL) {
                player_register_collision_with(hit_actor);
                player_moving = FALSE;
            }
        }

        if (INPUT_A_PRESSED) {
            hit_actor = actor_in_front_of_player(topdown_grid, TRUE);
            if (hit_actor != NULL && !hit_actor->collision_group) {
                actor_set_dir(hit_actor, -PLAYER.dir_x, -PLAYER.dir_y);
                player_moving = FALSE;
                if (hit_actor->script.bank) {
                    script_execute(hit_actor->script.bank, hit_actor->script.ptr, 0, 0);
                }
            }
        }

        actor_set_anim(&PLAYER, player_moving);

    }

    if (player_moving) player_move(PLAYER.dir_x, PLAYER.dir_y);
}
