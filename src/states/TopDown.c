#pragma bank 2

#include "states/TopDown.h"
#include "Actor.h"
#include "Camera.h"
#include "Collision.h"
#include "DataManager.h"
#include "GameTime.h"
#include "Input.h"
#include "Trigger.h"
#include "data/data_ptrs.h"

void Start_TopDown() __banked {
  camera_offset_x = 0;
  camera_offset_y = 0;
  camera_deadzone_x = 0;
  camera_deadzone_y = 0;

  if (topdown_grid == 16) {
    // Snap to 16px grid
    PLAYER.x = MUL_16(DIV_16(PLAYER.x));
    PLAYER.y = 8 + MUL_16(DIV_16(PLAYER.y));
  } else {
    // PLAYER.x = MUL_8(DIV_8(PLAYER.x));
    // PLAYER.y = 8 + MUL_8(DIV_8(PLAYER.y));
    // PLAYER.x = 64;
    // PLAYER.y = 64;
  }

    actor_set_frames(&PLAYER, 0, 16);
  // actor_set_anim(&PLAYER, TRUE);
}

void Update_TopDown() __banked {
  UBYTE moving = FALSE;

  UBYTE tile_x, tile_y, hit_actor;

  tile_x = DIV_8(PLAYER.x);
  tile_y = DIV_8(PLAYER.y);

  // Is player on an 8x8px tile?
  if ((topdown_grid == 16 && (MOD_16(PLAYER.x) == 0 && MOD_16(PLAYER.y) == 8)) ||
      (topdown_grid ==  8 && (MOD_8(PLAYER.x)  == 0 && MOD_8(PLAYER.y)  == 0))) {
    // Player landed on an tile
    // so stop movement for now
    moving = FALSE;

    // Check for trigger collisions
    if (ActivateTriggerAt(tile_x, tile_y, FALSE)) {
      // If landed on a trigger don't update movement this frame
      return;
    }

    // Check input to set player movement
    if (INPUT_RECENT_LEFT) {
      PLAYER.dir_x = -1;
      PLAYER.dir_y = 0;
      PLAYER.rerender = TRUE;

      // Check for collisions to left of player
      if (topdown_grid == 16) {
        UBYTE tile_left = tile_x - 2;
        if (tile_x != 0 && !(TileAt2x2(tile_left, tile_y-1) & COLLISION_RIGHT)) {
          moving = TRUE;
        }
      } else {
        UBYTE tile_left = tile_x - 1;
        if (tile_x != 0 && !(TileAt2x1(tile_left, tile_y) & COLLISION_RIGHT)) {
          moving = TRUE;
        }
      }

    } else if (INPUT_RECENT_RIGHT) {
      PLAYER.dir_x = 1;
      PLAYER.dir_y = 0;
      PLAYER.rerender = TRUE;

      // Check for collisions to right of player
      if (topdown_grid == 16) {
        UBYTE tile_right = tile_x + 2;
        if (tile_x != image_tile_width - 2 && !(TileAt2x2(tile_right, tile_y-1) & COLLISION_LEFT)) {
          moving = TRUE;
        }
      } else {    
        UBYTE tile_right = tile_x + 1;
        if (tile_x != image_tile_width - 2 && !(TileAt2x1(tile_right, tile_y) & COLLISION_LEFT)) {
          moving = TRUE;
        }
      }

    } else if (INPUT_RECENT_UP) {

      PLAYER.dir_x = 0;
      PLAYER.dir_y = -1;
      PLAYER.rerender = TRUE;

      // Check for collisions above player
      if (topdown_grid == 16) {
        UBYTE tile_up = tile_y - 3;
        if (tile_y != 0 && !(TileAt2x2(tile_x, tile_up) & COLLISION_BOTTOM)) {
          moving = TRUE;
        }        
      } else {
        UBYTE tile_up = tile_y - 1;
        if (tile_y != 0 && !(TileAt2x1(tile_x, tile_up) & COLLISION_BOTTOM)) {
          moving = TRUE;
        }
      }

    } else if (INPUT_RECENT_DOWN) {
      PLAYER.dir_x = 0;
      PLAYER.dir_y = 1;
      PLAYER.rerender = TRUE;

      // Check for collisions below player
      if (topdown_grid == 16) {
        UBYTE tile_down = tile_y + 1;
        if (tile_y != image_tile_height - 1 && !(TileAt2x2(tile_x, tile_down) & COLLISION_TOP)) {
          moving = TRUE;
        }
      } else {
        UBYTE tile_down = tile_y + 1;
        if (tile_y != image_tile_height - 1 && !(TileAt2x1(tile_x, tile_down) & COLLISION_TOP)) {
          moving = TRUE;
        }
      }
    }

  /*
    hit_actor = ActorOverlapsPlayer(FALSE);
    if (hit_actor && hit_actor != NO_ACTOR_COLLISON) {
      if (actors[hit_actor].collision_group) {
        PLAYER.hit_actor = 0;
        PLAYER.hit_actor = hit_actor;
      }
    }

    // Check if walked in to actor
    if (moving) {
      hit_actor = ActorInFrontOfPlayer(topdown_grid, FALSE);
      if (hit_actor != NO_ACTOR_COLLISON) {
        PLAYER.hit_actor = hit_actor;
        moving = FALSE;
      }
    }

    if (INPUT_A_PRESSED) {
      hit_actor = ActorInFrontOfPlayer(topdown_grid, TRUE);
      if (hit_actor != NO_ACTOR_COLLISON && !actors[hit_actor].collision_group) {
        // Turn actor to face player
        actors[hit_actor].dir_x = -PLAYER.dir_x;
        actors[hit_actor].dir_y = -PLAYER.dir_y;
        actors[hit_actor].rerender = TRUE;

        // Stop player from moving
        moving = FALSE;

        // Run actors interact script
        ActorRunScript(hit_actor);
      }
    }
    */
  }


//   PLAYER.x = 10;
//   PLAYER.y = 8;

//  if (INPUT_DOWN) {
//    moving = TRUE;
//    PLAYER.animate = TRUE;
//   PLAYER.y = 32;
//  }

  // Move player
  if (moving) {
    // Move actor
    if (PLAYER.move_speed == 0) {
      // Half speed only move every other frame
      if (IS_FRAME_2) {
        PLAYER.x += (WORD)PLAYER.dir_x;
        PLAYER.y += (WORD)PLAYER.dir_y;
      }
    } else {
      PLAYER.x += (WORD)(PLAYER.dir_x * PLAYER.move_speed);
      PLAYER.y += (WORD)(PLAYER.dir_y * PLAYER.move_speed);
    }
  }



}
