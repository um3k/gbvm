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
#include "Sprite.h"
#include "Trigger.h"
#include "data/data_ptrs.h"

#define PLATFORM_CAMERA_DEADZONE_X 4
#define PLATFORM_CAMERA_DEADZONE_Y 16

UBYTE grounded = FALSE;
UBYTE on_ladder = FALSE;
WORD pl_vel_x = 0;
WORD pl_vel_y = 0;
WORD pl_pos_x = 16512;
WORD pl_pos_y = 1024;

void platform_init() __banked {
  UBYTE tile_x, tile_y;

  pl_pos_x = (PLAYER.x + 4u) << 4;
  pl_pos_y = PLAYER.y << 4;
  pl_vel_x = 0;
  pl_vel_y = 0;

  if (PLAYER.dir_x == 0) {
    PLAYER.dir_y = 0;
    PLAYER.dir_x = 1;
    PLAYER.rerender = TRUE;
  }

  tile_x = DIV_8(PLAYER.x)+1;
  tile_y = DIV_8(PLAYER.y);

  grounded = FALSE;
  // If starting tile was a ladder start scene attached to it
  if (TileAt(tile_x, tile_y) & TILE_PROP_LADDER) {
    on_ladder = TRUE;
    PLAYER.dir_x = 0;
    PLAYER.dir_y = -1;
  }

  camera_offset_x = 0;
  camera_offset_y = 0;
  camera_deadzone_x = PLATFORM_CAMERA_DEADZONE_X;
  camera_deadzone_y = PLATFORM_CAMERA_DEADZONE_Y;

  game_time = 0;
}

void platform_update() __banked {
  UBYTE tile_x, tile_x_mid, tile_y, tile_y_ceil;
  UBYTE hit_actor = 0;
  UBYTE hit_trigger = 0;

  // Update scene pos from player pos (incase was moved by a script)
  pl_pos_x = ((PLAYER.x + 4u) << 4) + (pl_pos_x & 0xF);
  pl_pos_y = ((PLAYER.y) << 4) + (pl_pos_y & 0xF);

  tile_x = DIV_8(PLAYER.x);
  tile_x_mid = DIV_8(PLAYER.x+4u);
  tile_y = DIV_8(PLAYER.y);

  // Move
  if (on_ladder) {
    PLAYER.dir_x = 0;
    PLAYER.dir_y = -1;
    pl_vel_x = 0;
    if (INPUT_UP) {
      pl_vel_y = -plat_walk_vel;
    } else if (INPUT_DOWN) {
      pl_vel_y = plat_walk_vel;
    } else {
      if (INPUT_LEFT) {
        on_ladder = FALSE;
        PLAYER.dir_x = -1;
        PLAYER.dir_y = 0;
        PLAYER.rerender = TRUE;
      } else if (INPUT_RIGHT) {
        on_ladder = FALSE;
        PLAYER.dir_x = 1;
        PLAYER.dir_y = 0;
        PLAYER.rerender = TRUE;
      }
      pl_vel_y = 0;
    }
  } else {
    PLAYER.dir_y = 0;
    if ((INPUT_UP || INPUT_DOWN) && ((TileAt(tile_x_mid, tile_y) & TILE_PROP_LADDER))) {
      on_ladder = TRUE;
      pl_vel_x = 0;
      PLAYER.dir_x = 0;
      PLAYER.dir_y = -1;
      PLAYER.rerender = TRUE;
    }
 
    if (INPUT_LEFT) {
      PLAYER.dir_x = -1;
      if (INPUT_A) {
        pl_vel_x -= plat_run_acc;
        pl_vel_x = CLAMP(pl_vel_x, -plat_run_vel, -plat_min_vel);
      } else {
        pl_vel_x -= plat_walk_acc;
        pl_vel_x = CLAMP(pl_vel_x, -plat_walk_vel, -plat_min_vel);
      } 
      if (INPUT_LEFT_PRESSED) { // update player facing direction if button pressed this frame
        PLAYER.rerender = TRUE;
      }
    } else if (INPUT_RIGHT) {
      PLAYER.dir_x = 1;
      if (INPUT_A) {
        pl_vel_x += plat_run_acc;
        pl_vel_x = CLAMP(pl_vel_x, plat_min_vel, plat_run_vel);
      } else {
        pl_vel_x += plat_walk_acc;
        pl_vel_x = CLAMP(pl_vel_x, plat_min_vel, plat_walk_vel);
      }
      if (INPUT_RIGHT_PRESSED) { // update player facing direction if button pressed this frame
        PLAYER.rerender = TRUE;
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
  }

  pl_pos_x += pl_vel_x >> 8;
  tile_x = pl_pos_x >> 7;
  tile_y = pl_pos_y >> 7;

  /*
  if (grounded && INPUT_A_PRESSED) {
    if (PLAYER.dir_x == 1) {
      hit_actor = ActorAtTile(tile_x + 2, tile_y, TRUE);
    } else {
      hit_actor = ActorAtTile(tile_x - 1, tile_y, TRUE);
    }
    if (hit_actor && (hit_actor != NO_ACTOR_COLLISON)) {
      ScriptStart(&actors[hit_actor].events_ptr);
    }
  }
  */

  // Jump
  if (INPUT_B_PRESSED && grounded) {
    if (!( (((pl_pos_x >> 4) & 0x7) != 7 &&
          TileAt(tile_x, tile_y - 1) & COLLISION_BOTTOM) ||  // Left Edge
          (((pl_pos_x >> 4) & 0x7) != 0 &&
           TileAt(tile_x + 1, tile_y - 1) & COLLISION_BOTTOM))) {  // Right edge
      pl_vel_y = -plat_jump_vel;
      grounded = FALSE;
    }
  }

  if (!on_ladder) {
    // Gravity
    if (INPUT_B && pl_vel_y < 0) {
      pl_vel_y += plat_hold_grav;
    } else {
      pl_vel_y += plat_grav;
    }
  }

  pl_vel_y = MIN(pl_vel_y, plat_max_fall_vel);
  pl_pos_y += pl_vel_y >> 8;
  tile_y = pl_pos_y >> 7;
  tile_y_ceil = (pl_pos_y - 7u) >> 7;

  // Left Collision
  if (pl_vel_x < 0) {
    if (TileAt(tile_x, tile_y) & COLLISION_RIGHT || 
        TileAt(tile_x, tile_y_ceil) & COLLISION_RIGHT) {
      pl_vel_x = 0;
      pl_pos_x = ((tile_x + 1) * 8) << 4;
      tile_x = pl_pos_x >> 7;
    }
  }

  // Right Collision
  if (pl_vel_x > 0) {
    if (TileAt(tile_x + 1, tile_y) & COLLISION_LEFT ||
        TileAt(tile_x + 1, tile_y_ceil) & COLLISION_LEFT) {
      pl_vel_x = 0;
      pl_pos_x = (tile_x * 8) << 4;
      tile_x = pl_pos_x >> 7;
    }
  }

  if (on_ladder) {
    // Ladder vertical collision
    UBYTE tile_below;
    if (!(TileAt(tile_x_mid, tile_y) & TILE_PROP_LADDER)) {
      if (INPUT_DOWN) {
        on_ladder = FALSE;
        PLAYER.dir_x = 1;
        PLAYER.dir_y = 0;
        PLAYER.rerender = TRUE;
      } else {
        pl_pos_y -= pl_vel_y >> 8;
        pl_vel_y = 0;
      }
    }

    // Check if can pass through ground collision (ground also contains ladder)
    tile_below = TileAt(tile_x_mid, tile_y + 1);
    if (pl_vel_y >= 0) {
      if ((tile_below & COLLISION_TOP) && !(tile_below & TILE_PROP_LADDER)) {
        grounded = TRUE;
        pl_vel_y = 0;
        pl_pos_y = (tile_y * 8) << 4;
      }
    }

  } else {
    // Ground Collision
    if (pl_vel_y >= 0 && (TileAt(tile_x, tile_y + 1) & COLLISION_TOP ||  // Left Edge
                          (((pl_pos_x >> 4) & 0x7) != 0 &&
                           TileAt(tile_x + 1, tile_y + 1) & COLLISION_TOP))  // Right edge
    ) {
      grounded = TRUE;
      pl_vel_y = 0;
      pl_pos_y = (tile_y * 8) << 4;
    } else {
      grounded = FALSE;

      // Ceiling Collision
      if (pl_vel_y < 0) {
        if (TileAt(tile_x, tile_y - 1) & COLLISION_BOTTOM ||  // Left Edge
            (((pl_pos_x >> 4) & 0x7) != 0 &&
             TileAt(tile_x + 1, tile_y - 1) & COLLISION_BOTTOM)  // Right edge
        ) {
          pl_vel_y = 0;
          pl_pos_y = (((tile_y + 1) * 8) << 4);
        }
      }
    }
  }

  // Position player sprite using precision coordinates
  PLAYER.x = (pl_pos_x >> 4) - 4u;
  PLAYER.y = pl_pos_y >> 4;

  // Clamp to screen
  if (PLAYER.x < 0) {
    PLAYER.x = 0;
    pl_pos_x = 0;
    pl_vel_x = 0;
  } else if (PLAYER.x > image_width - 16) {
    PLAYER.x = image_width - 16;
    pl_pos_x = 0;
    pl_vel_x = 0;
  }

  if (PLAYER.y < 0) {
    PLAYER.y = 0;
    pl_pos_y = 0;
    pl_vel_y = 0;
  } else if (PLAYER.y > image_height - 8) {
    PLAYER.y = image_height - 8;
    pl_pos_y = 0;
    pl_vel_y = 0;
    grounded = TRUE;
  }

  PLAYER.animate = (grounded && pl_vel_x != 0) || (on_ladder && pl_vel_y != 0);

  // Check for trigger collisions
  /*
  if (ActivateTriggerAt(tile_x, tile_y, INPUT_UP_PRESSED)) {
    // Landed on a trigger
    return;
  }
  */

  // Actor Collisions
  /*
  hit_actor = ActorOverlapsPlayer(FALSE);
  if (hit_actor && hit_actor != NO_ACTOR_COLLISON && player_iframes == 0) {
    if (actors[hit_actor].collision_group) {
      PLAYER.hit_actor = 0;
      PLAYER.hit_actor = hit_actor;
    }
  }
  */
}
