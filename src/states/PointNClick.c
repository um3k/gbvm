#pragma bank 3

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

    PLAYER.dir = DIR_DOWN;
}

void pointnclick_update() __banked {
    UBYTE tile_x, tile_y, hit_actor, hit_trigger, is_hover_actor,
        is_hover_trigger;

    tile_x = DIV_8(PLAYER.pos.x);
    tile_y = DIV_8(PLAYER.pos.y);

    player_moving = FALSE;
    PLAYER.dir = DIR_DOWN;

    // Move cursor horizontally
    if (INPUT_LEFT && (PLAYER.pos.x > 0)) {
        actor_set_dir(&PLAYER, DIR_LEFT);
        player_moving = TRUE;
    } else if (INPUT_RIGHT && (PLAYER.pos.x < image_width - 8)) {
        actor_set_dir(&PLAYER, DIR_RIGHT);
        player_moving = TRUE;
    }

    // Move cursor vertically
    if (INPUT_UP && (PLAYER.pos.y > 8)) {
        actor_set_dir(&PLAYER, DIR_UP);
        player_moving = TRUE;
    } else if (INPUT_DOWN && (PLAYER.pos.y < image_height)) {
        actor_set_dir(&PLAYER, DIR_DOWN);
        player_moving = TRUE;
    }

    // Find trigger or actor under player cursor
    // hit_trigger = trigger_at_tile(tile_x, tile_y - 1);
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
    //     trigger_interact(hit_trigger);
    //   }
    // }

    if (player_moving) point_translate_dir(&PLAYER.pos, PLAYER.dir, PLAYER.move_speed);
}
