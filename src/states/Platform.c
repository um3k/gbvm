#pragma bank 2

#include "states/Platform.h"
#include "Actor.h"
#include "Camera.h"
#include "Collision.h"
#include "DataManager.h"
#include "GameTime.h"
#include "Input.h"
#include "Math.h"
#include "Scroll.h"
#include "Trigger.h"
#include "vm.h"
#include "data/data_ptrs.h"

#define PLATFORM_CAMERA_DEADZONE_X 4
#define PLATFORM_CAMERA_DEADZONE_Y 16

UBYTE grounded = FALSE;
UBYTE on_ladder = FALSE;
WORD pl_vel_x = 0;
WORD pl_vel_y = 0;

void platform_init() __banked {
    UBYTE tile_x, tile_y;

    pl_vel_x = 0;
    pl_vel_y = 0;

    if (PLAYER.dir_x == 0) {
        PLAYER.dir_y = 0;
        PLAYER.dir_x = 1;
    }

    tile_x = PLAYER.pos.x >> 7;
    tile_y = PLAYER.pos.y >> 7;

    grounded = FALSE;
    // If starting tile was a ladder start scene attached to it
    if (tile_at(tile_x, tile_y) & TILE_PROP_LADDER) {
        on_ladder = TRUE;
        PLAYER.dir_x = 0;
        PLAYER.dir_y = -1;
    } else {
        on_ladder = FALSE;
    }

    camera_offset_x = 0;
    camera_offset_y = 0;
    camera_deadzone_x = PLATFORM_CAMERA_DEADZONE_X;
    camera_deadzone_y = PLATFORM_CAMERA_DEADZONE_Y;

    game_time = 0;
}

void platform_update() __banked {
    UBYTE tile_start, tile_end;
    actor_t *hit_actor;
    UBYTE p_half_width = (PLAYER.bounds.right - PLAYER.bounds.left) >> 1;

    // Input
    if (on_ladder) {
        // PLAYER.pos.x = 0;
        UBYTE tile_x_mid = ((PLAYER.pos.x >> 4) + PLAYER.bounds.left + p_half_width) >> 3; 
        pl_vel_y = 0;
        if (INPUT_UP) {
            // Climb laddder
            UBYTE tile_y = ((PLAYER.pos.y >> 4) + PLAYER.bounds.top) >> 3;
            if (tile_at(tile_x_mid, tile_y + 1) & TILE_PROP_LADDER) {
                pl_vel_y = -plat_climb_vel;
                actor_set_dir(&PLAYER, DIR_NONE, DIR_UP);
            }
        } else if (INPUT_DOWN) {
            // Descend ladder
            UBYTE tile_y = ((PLAYER.pos.y >> 4) + PLAYER.bounds.bottom) >> 3;
            if (tile_at(tile_x_mid, tile_y + 1) & TILE_PROP_LADDER) {
                pl_vel_y = plat_climb_vel;
                actor_set_dir(&PLAYER, DIR_NONE, DIR_UP);
            }
        } else if (INPUT_LEFT || INPUT_RIGHT) {
            on_ladder = FALSE;           
        }
        PLAYER.pos.y += (pl_vel_y >> 8);
    } else {
        if (INPUT_LEFT) {
            if (INPUT_B) {
                pl_vel_x -= plat_run_acc;
                pl_vel_x = CLAMP(pl_vel_x, -plat_run_vel, -plat_min_vel);
            } else {
                pl_vel_x -= plat_walk_acc;
                pl_vel_x = CLAMP(pl_vel_x, -plat_walk_vel, -plat_min_vel);
            } 
            actor_set_dir(&PLAYER, DIR_LEFT, DIR_NONE);
        } else if (INPUT_RIGHT) {
            PLAYER.dir_x = 1;
            if (INPUT_B) {
                pl_vel_x += plat_run_acc;
                pl_vel_x = CLAMP(pl_vel_x, plat_min_vel, plat_run_vel);
            } else {
                pl_vel_x += plat_walk_acc;
                pl_vel_x = CLAMP(pl_vel_x, plat_min_vel, plat_walk_vel);
            }
            actor_set_dir(&PLAYER, DIR_RIGHT, DIR_NONE);
        } else if (INPUT_UP) {
            // Grab upwards ladder
            UBYTE tile_x_mid = ((PLAYER.pos.x >> 4) + PLAYER.bounds.left + p_half_width) >> 3;
            UBYTE tile_y   = (((PLAYER.pos.y >> 4) + PLAYER.bounds.top) >> 3);
            if (tile_at(tile_x_mid, tile_y) & TILE_PROP_LADDER) {
                PLAYER.pos.x = (((tile_x_mid << 3) + 4 - (PLAYER.bounds.left + p_half_width) << 4));
                actor_set_dir(&PLAYER, DIR_NONE, DIR_UP);
                on_ladder = TRUE;
                pl_vel_x = 0;
            }
        } else if (INPUT_DOWN) {
            // Grab downwards ladder
            UBYTE tile_x_mid = ((PLAYER.pos.x >> 4) + PLAYER.bounds.left + p_half_width) >> 3;
            UBYTE tile_y   = (((PLAYER.pos.y >> 4) + PLAYER.bounds.bottom) >> 3) + 1;
            if (tile_at(tile_x_mid, tile_y) & TILE_PROP_LADDER) {
                PLAYER.pos.x = (((tile_x_mid << 3) + 4 - (PLAYER.bounds.left + p_half_width) << 4));
                actor_set_dir(&PLAYER, DIR_NONE, DIR_UP);
                on_ladder = TRUE;
                pl_vel_x = 0;
            }
        } else if (grounded) {
            if (pl_vel_x < 0) {
                pl_vel_x += plat_dec;
                if (pl_vel_x > 0) {
                    pl_vel_x = 0;
                }
            } else if (pl_vel_x > 0) {
                pl_vel_x -= plat_dec;
                if (pl_vel_x < 0) {
                    pl_vel_x = 0;
                }
            }
        }

        // Gravity
        if (INPUT_A && pl_vel_y < 0) {
            pl_vel_y += plat_hold_grav;
        } else {
            pl_vel_y += plat_grav;
        }

        // Step X
        tile_start = (((PLAYER.pos.y >> 4) + PLAYER.bounds.top)    >> 3) + 1;
        tile_end   = (((PLAYER.pos.y >> 4) + PLAYER.bounds.bottom) >> 3) + 1;
        if (pl_vel_x > 0) {
            WORD new_x = PLAYER.pos.x + (pl_vel_x >> 8);
            UBYTE tile_x = ((new_x >> 4) + PLAYER.bounds.right) >> 3;
            while (tile_start != tile_end) {
                if (tile_at(tile_x, tile_start) & COLLISION_LEFT) {
                    new_x = (((tile_x << 3) - PLAYER.bounds.right) << 4) - 1;
                    pl_vel_x = 0;
                    break;
                }
                tile_start++;
            }
            PLAYER.pos.x = MIN((image_width - 16) << 4, new_x);
        } else if (pl_vel_x < 0) {
            WORD new_x = PLAYER.pos.x + (pl_vel_x >> 8);
            UBYTE tile_x = ((new_x >> 4) + PLAYER.bounds.left) >> 3;
            while (tile_start != tile_end) {
                if (tile_at(tile_x, tile_start) & COLLISION_RIGHT) {
                    new_x = ((((tile_x + 1) << 3) - PLAYER.bounds.left) << 4) + 1;
                    pl_vel_x = 0;
                    break;
                }
                tile_start++;
            }
            PLAYER.pos.x = MAX(0, new_x);
        }

        // Step Y
        grounded = FALSE;    
        tile_start = (((PLAYER.pos.x >> 4) + PLAYER.bounds.left)  >> 3);
        tile_end   = (((PLAYER.pos.x >> 4) + PLAYER.bounds.right) >> 3) + 1;
        if (pl_vel_y > 0) {
            UWORD new_y = PLAYER.pos.y + (pl_vel_y >> 8);
            UBYTE tile_y = ((new_y >> 4) + PLAYER.bounds.bottom) >> 3;
            while (tile_start != tile_end) {
                if (tile_at(tile_start, tile_y + 1) & COLLISION_TOP) {
                    new_y = (((tile_y) << 3) - PLAYER.bounds.bottom) << 4;
                    pl_vel_y = 0;
                    grounded = TRUE;
                    break;
                }
                tile_start++;
            }
            PLAYER.pos.y = new_y;
        } else if (pl_vel_y < 0) {
            UWORD new_y = PLAYER.pos.y + (pl_vel_y >> 8);
            UBYTE tile_y = (((new_y >> 4) + PLAYER.bounds.top) >> 3) + 1;
            while (tile_start != tile_end) {
                if (tile_at(tile_start, tile_y) & COLLISION_BOTTOM) {
                    new_y = (((UBYTE)(tile_y) << 3) - PLAYER.bounds.top) << 4;
                    pl_vel_y = 0;
                    break;
                }
                tile_start++;
            }
            PLAYER.pos.y = new_y;
        }

        // Clamp Y Velocity
        pl_vel_y = MIN(pl_vel_y, plat_max_fall_vel);
    }

    actor_set_anim(&PLAYER, (grounded && pl_vel_x != 0) || (on_ladder && pl_vel_y != 0));

    UBYTE tile_x_mid = ((PLAYER.pos.x >> 4) + ((PLAYER.bounds.right - PLAYER.bounds.left) >> 2)) >> 3;
    UBYTE tile_y_mid = ((PLAYER.pos.y >> 4) + ((PLAYER.bounds.bottom - PLAYER.bounds.top) >> 2)) >> 3;

    // Check for trigger collisions
    // Probably should check entire bounding box for trigger collision...
    if (trigger_activate_at(tile_x_mid, tile_y_mid, INPUT_UP_PRESSED)) {
        // Landed on a trigger
        return;
    }

    // Actor Collisions
    UBYTE can_jump = TRUE;
    hit_actor = actor_overlapping_player(FALSE);
    if (hit_actor != NULL && hit_actor->collision_group) {
        player_register_collision_with(hit_actor);
        can_jump = FALSE;
    } else if (INPUT_A_PRESSED) {
        if (!hit_actor) {
            hit_actor = actor_in_front_of_player(8, TRUE);
        }
        if (hit_actor && !hit_actor->collision_group && hit_actor->script.bank) {
            script_execute(hit_actor->script.bank, hit_actor->script.ptr, 0, 0);
            can_jump = FALSE;
        }
    }

    // Jump
    if (INPUT_A_PRESSED && grounded && can_jump) {
        pl_vel_y = -plat_jump_vel;
        grounded = FALSE;
    }    
}
