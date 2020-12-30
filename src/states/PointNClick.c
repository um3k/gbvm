#pragma bank 2

#include "states/PointNClick.h"

#include "Actor.h"
#include "Camera.h"
#include "DataManager.h"
#include "GameTime.h"
#include "Input.h"
#include "Trigger.h"

#define POINT_N_CLICK_CAMERA_DEADZONE 24

UBYTE last_hit_trigger = MAX_TRIGGERS;

void pointnclick_init() __banked {
    camera_offset_x = 0;
    camera_offset_y = 0;
    camera_deadzone_x = POINT_N_CLICK_CAMERA_DEADZONE;
    camera_deadzone_y = POINT_N_CLICK_CAMERA_DEADZONE;

    // PLAYER.sprite_type = SPRITE_STATIC;
    PLAYER.dir_x = 0;
    PLAYER.dir_y = 1;
    PLAYER.rerender = TRUE;
}

void pointnclick_update() __banked {
    UBYTE tile_x, tile_y, hit_actor, hit_trigger, is_hover_actor,
        is_hover_trigger;

    tile_x = DIV_8(PLAYER.x);
    tile_y = DIV_8(PLAYER.y);

    player_moving = FALSE;
    PLAYER.dir_x = 0;
    PLAYER.dir_y = 0;

    // Move cursor horizontally
    if (INPUT_LEFT && (PLAYER.x > 0)) {
        PLAYER.dir_x = -1;
        player_moving = TRUE;
    } else if (INPUT_RIGHT && (PLAYER.x < image_width - 8)) {
        PLAYER.dir_x = 1;
        player_moving = TRUE;
    }

    // Move cursor vertically
    if (INPUT_UP && (PLAYER.y > 8)) {
        PLAYER.dir_y = -1;
        player_moving = TRUE;
    } else if (INPUT_DOWN && (PLAYER.y < image_height)) {
        PLAYER.dir_y = 1;
        player_moving = TRUE;
    }

    // Find trigger or actor under player cursor
    // hit_trigger = TriggerAtTile(tile_x, tile_y - 1);
    // hit_actor = ActorAtTile(tile_x, tile_y, TRUE);

    // is_hover_trigger = (hit_trigger != NO_TRIGGER_COLLISON) &&
    //                    (hit_trigger != last_hit_trigger) &&
    //                    (triggers[hit_trigger].events_ptr.bank != 0);
    // is_hover_actor = (hit_actor != NO_ACTOR_COLLISON) && (hit_actor != 0) &&
    //                  (actors[hit_actor].events_ptr.bank != 0);

    // Set player cursor to second frame on hover
    // if ((is_hover_trigger || is_hover_actor) && PLAYER.frames_len != 1) {
    //     PLAYER.frame = 1;
    //     PLAYER.rerender = TRUE;
    // } else {
    //     PLAYER.frame = 0;
    //     PLAYER.rerender = TRUE;
    // }

    // if (INPUT_A_PRESSED) {
    //   player_moving = FALSE;

    //   if (is_hover_actor) {
    //     // Run actor's interact script
    //     ActorRunScript(hit_actor);
    //   } else if (is_hover_trigger) {
    //     // Run trigger script
    //     TriggerRunScript(hit_trigger);
    //   }
    // }

    if (player_moving) player_move(PLAYER.dir_x,  PLAYER.dir_y);
}
