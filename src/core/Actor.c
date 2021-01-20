#pragma bank 1

#include "Actor.h"
#include "GameTime.h"
#include "Scroll.h"
#include "LinkedList.h"
#include "Math.h"
#include "Collision.h"
#include "metasprite.h"
#include "vm.h"
#include <gb/gb.h>

#ifdef STRICT
    #include <gb/bgb_emu.h>
    #include <gb/crash_handler.h>
#endif

actor_t actors[MAX_ACTORS];
actor_t *actors_active_head = 0;
actor_t *actors_inactive_head = 0;

INT8 screen_x, screen_y;
actor_t *invalid;
UBYTE player_moving = FALSE;
UBYTE player_iframes = 0;
actor_t *player_collision_actor = 0;
far_ptr_t *script_p_hit1, script_p_hit2, script_p_hit3;

const metasprite_item_t actor_animated_down_frame_1[]  = {{0, 0, 0, 0,  0},    {1, 0, 8, 2,  0},     {metasprite_end}};
const metasprite_item_t actor_animated_down_frame_2[]  = {{0, 0, 0, 4,  0},    {1, 0, 8, 6,  0},    {metasprite_end}};
const metasprite_item_t actor_animated_up_frame_1[]    = {{0, 0, 0, 8,  0},    {1, 0, 8, 10, 0},     {metasprite_end}};
const metasprite_item_t actor_animated_up_frame_2[]    = {{0, 0, 0, 12, 0},    {1, 0, 8, 14, 0},     {metasprite_end}};
const metasprite_item_t actor_animated_right_frame_1[] = {{0, 0, 0, 16, 0},    {1, 0, 8, 18, 0},     {metasprite_end}};
const metasprite_item_t actor_animated_right_frame_2[] = {{0, 0, 0, 20, 0},    {1, 0, 8, 22, 0},     {metasprite_end}};
const metasprite_item_t actor_animated_left_frame_1[]  = {{0, 0, 0, 18, 0x20}, {1, 0, 8, 16, 0x20U}, {metasprite_end}};
const metasprite_item_t actor_animated_left_frame_2[]  = {{0, 0, 0, 22, 0x20}, {1, 0, 8, 20, 0x20U}, {metasprite_end}};

const metasprite_item_t (*actor_animated_metasprites[])[] = {
    &actor_animated_down_frame_1,
    &actor_animated_down_frame_2,
    &actor_animated_up_frame_1,
    &actor_animated_up_frame_2,
    &actor_animated_right_frame_1,
    &actor_animated_right_frame_2,
    &actor_animated_left_frame_1,
    &actor_animated_left_frame_2
};

void actors_update()
{
    UBYTE _save = _current_bank;
    UBYTE next_sprite = 0;
    static actor_t *actor;

    actor = actors_active_head;
    
    while (actor) {
        if (actor->pinned) 
            screen_x = actor->x + 8, screen_y = actor->y + 8;
        else 
            screen_x = actor->x - draw_scroll_x + 8, screen_y = actor->y - draw_scroll_y + 8;

        if ((UINT8)(screen_x + 8) > 184 || (UINT8)(screen_y) > 160) {
            // Deactivate if offscreen
            actor_t * next = actor->next;
            deactivate_actor(actor);
            actor = next;
            continue;
        } else if ((WX_REG != 7) && (WX_REG < (UINT8)screen_x + 8) && (WY_REG < (UINT8)(screen_y)-8)) {
            // Hide if under window (don't deactivate)
            actor = actor->next;
            continue;
        }

        // Check reached animation tick frame
        if ((actor->animate) && ((game_time & actor->anim_tick) == 0)) {
            actor->frame++;
            // Check reached end of animation
            if (actor->frame == actor->frame_end) {
                actor->frame = actor->frame_start;
            }
        }

        next_sprite += move_metasprite(
            actor_animated_metasprites[actor->frame],
            actor->base_tile,
            next_sprite,
            screen_x,
            screen_y
        );

        actor = actor->next;
    }

    hide_hardware_sprites(next_sprite, 40);

    SWITCH_ROM_MBC1(_save);
}

void deactivate_actor(actor_t *actor) __banked
{
#ifdef STRICT
    // Check exists in inactive list
    UBYTE found = 0;
    actor_t *current = actors_active_head;
    DL_CONTAINS(current, actor, found);
    if (!found)
    {
        BGB_MESSAGE("Deactivated non active actor\n");
        __HandleCrash();
        return;
    }
#endif
    if (!actor->enabled) return;
    actor->enabled = FALSE;
    DL_REMOVE_ITEM(actors_active_head, actor);
    DL_PUSH_HEAD(actors_inactive_head, actor);
    if (actor->ctx_id) {
        script_terminate(actor->ctx_id);
        actor->ctx_id = 0;
    }
}

void activate_actor(actor_t *actor)
{
#ifdef STRICT
    // Check exists in inactive list
    UBYTE found = 0;
    actor_t *current = actors_inactive_head;
    DL_CONTAINS(current, actor, found);
    if (!found)
    {
        BGB_MESSAGE("Activated non inactive actor\n");
        __HandleCrash();
        return;
    }
#endif
    if (actor->enabled) return;
    actor->enabled = TRUE;
    DL_REMOVE_ITEM(actors_inactive_head, actor);
    DL_PUSH_HEAD(actors_active_head, actor);
    if (actor->script_update.bank) {
        SCRIPT_CTX *ctx = script_execute(actor->script_update.bank, actor->script_update.ptr, 0, 0);
        actor->ctx_id = ctx->ID;
    }
}

void activate_actors_in_row(UBYTE x, UBYTE y) __banked {
    static actor_t *actor;
    actor = actors_inactive_head;

    while (actor) {
        UBYTE ty = actor->y >> 3;
        if (ty == y) {
            UBYTE tx = actor->x >> 3;
            if ((tx + 1 > x) && (tx < x + SCREEN_TILE_REFRES_W)) {
                actor_t * next = actor->next;
                activate_actor(actor);
                actor = next;
                continue;
            }
        }
        actor = actor->next;
    }    
}

void activate_actors_in_col(UBYTE x, UBYTE y) __banked {
    static actor_t *actor;
    actor = actors_inactive_head;

    while (actor) {
        UBYTE tx = actor->x >> 3;
        if (tx == x) {
            UBYTE ty = actor->y >> 3;
            if ((ty > y) && (ty < y + SCREEN_TILE_REFRES_H)) {
                actor_t * next = actor->next;
                activate_actor(actor);
                actor=next;
                continue;
            }
        }
        actor = actor->next;
    }
}

void actor_set_frames(actor_t *actor, UBYTE frame_start, UBYTE frame_end) __banked
{
    if (actor->frame_start != frame_start || actor->frame_end != frame_end) {
        actor->frame = frame_start;
        actor->frame_start = frame_start;
        actor->frame_end = frame_end;
    }
}

void actor_set_dir(actor_t *actor, BYTE dir_x, BYTE dir_y) __banked
{
    actor->dir_x = dir_x;
    actor->dir_y = dir_y;
    
    if (actor->sprite_type != SPRITE_TYPE_STATIC) {
        if (dir_x == DIR_LEFT) {
            actor_set_frames(actor, 3 * actor->n_frames, 4 * actor->n_frames);
        } else if (dir_x == DIR_RIGHT) {
            actor_set_frames(actor, 2 * actor->n_frames, 3 * actor->n_frames);
        } else if (dir_y == DIR_UP) {
            actor_set_frames(actor, actor->n_frames, 2 * actor->n_frames);
        } else if (dir_y == DIR_DOWN) {
            actor_set_frames(actor, 0, actor->n_frames);
        }
    } else {
        actor_set_frames(actor, 0, actor->n_frames);
    }
}

void actor_reset_dir(actor_t *actor) __banked
{
    actor_set_dir(actor, actor->dir_x, actor->dir_y);
}

actor_t *actor_at_tile(UBYTE tx, UBYTE ty, UBYTE inc_noclip) __banked
{
    for (actor_t *actor = actors_active_head; (actor); actor = actor->next) {
        if ((!inc_noclip && !actor->collision_enabled))
            continue;

        UBYTE a_tx = DIV_8(actor->x), a_ty = DIV_8(actor->y);
        if ((ty == a_ty || ty == a_ty + 1) && (tx == a_tx || tx == a_tx + 1 || tx == a_tx - 1)) return actor;
    }
    return NULL;
}

void player_move(BYTE dir_x, BYTE dir_y) __banked {
    // Move actor
    if (PLAYER.move_speed == 0) {
        // Half speed only move every other frame
        if (IS_FRAME_2) {
            PLAYER.x += (WORD)dir_x;
            PLAYER.y += (WORD)dir_y;
        }
    } else {
        PLAYER.x += (WORD)(dir_x * PLAYER.move_speed);
        PLAYER.y += (WORD)(dir_y * PLAYER.move_speed);
    }
}

actor_t *actor_at_3x3_tile(UBYTE tx, UBYTE ty, UBYTE inc_noclip) __banked {
    for (actor_t *actor = actors_active_head; (actor); actor = actor->next) {
        if ((!inc_noclip && !actor->collision_enabled))
            continue;

        UBYTE a_tx = DIV_8(actor->x), a_ty = DIV_8(actor->y);
        if ((ty == a_ty || ty == a_ty - 1 || ty == a_ty - 2) && (tx == a_tx || tx == a_tx - 1 || tx == a_tx - 2)) return actor;
    }
    return NULL;
}

actor_t *actor_at_1x3_tile(UBYTE tx, UBYTE ty, UBYTE inc_noclip) __banked {
    for (actor_t *actor = actors_active_head; (actor); actor = actor->next) {
        if ((!inc_noclip && !actor->collision_enabled))
            continue;

        UBYTE a_tx = DIV_8(actor->x), a_ty = DIV_8(actor->y);
        if ((ty == a_ty || ty == a_ty - 1 || ty == a_ty - 2) && (tx == a_tx)) return actor;
    }
    return NULL;
}

actor_t *actor_at_3x1_tile(UBYTE tx, UBYTE ty, UBYTE inc_noclip) __banked {
    for (actor_t *actor = actors_active_head; (actor); actor = actor->next) {
        if ((!inc_noclip && !actor->collision_enabled)) 
            continue;

        UBYTE a_tx = DIV_8(actor->x), a_ty = DIV_8(actor->y);
        if ((ty == a_ty) && (tx == a_tx || tx == a_tx - 1 || tx == a_tx - 2)) return actor;
    }
    return NULL;
}

actor_t *actor_at_1x2_tile(UBYTE tx, UBYTE ty, UBYTE inc_noclip) __banked {
    for (actor_t *actor = actors_active_head; (actor); actor = actor->next) {
        if ((!inc_noclip && !actor->collision_enabled))
            continue;

        UBYTE a_tx = DIV_8(actor->x), a_ty = DIV_8(actor->y);
        if ((ty == a_ty || ty == a_ty - 1) && (tx == a_tx)) return actor;
    }
    return NULL;
}

actor_t *actor_in_front_of_player(UBYTE grid_size, UBYTE inc_noclip) __banked {
    UBYTE tile_x = DIV_8(PLAYER.x), tile_y = DIV_8(PLAYER.y);

    if (grid_size == 16) {
        if (PLAYER.dir_y == -1) {
            return actor_at_3x3_tile(tile_x - 1, tile_y - 3, inc_noclip);
        } else if (PLAYER.dir_y == 1) {
            return actor_at_3x3_tile(tile_x - 1, tile_y + 1, inc_noclip);
        } else {
            if (PLAYER.dir_x == -1) {
                return actor_at_3x3_tile(tile_x - 3, tile_y - 1, inc_noclip);
            } else if (PLAYER.dir_x == 1) {
                return actor_at_3x3_tile(tile_x + 1, tile_y - 1, inc_noclip);
            }
        }
    } else {
        if (PLAYER.dir_y == -1) {
            return actor_at_3x1_tile(tile_x - 1, tile_y - 1, inc_noclip);
        } else if (PLAYER.dir_y == 1) {
            return actor_at_3x1_tile(tile_x - 1, tile_y + 2, inc_noclip);
        } else {
            if (PLAYER.dir_x == -1) {
                return actor_at_1x2_tile(tile_x - 2, tile_y, inc_noclip);
            } else if (PLAYER.dir_x == 1) {
                return actor_at_1x2_tile(tile_x + 2, tile_y, inc_noclip);
            }
        }
    }

    return NULL;
}

actor_t *actor_overlapping_player(UBYTE inc_noclip) __banked {
    actor_t *actor = actors_active_head;

    while (actor) {
        if ((actor == &PLAYER) || (!inc_noclip && !actor->collision_enabled)) {
            actor = actor->next;
            continue;
        };

        if ((PLAYER.x + 15 >= actor->x) && (PLAYER.x <= actor->x + 15) &&
            (PLAYER.y + 7 >= actor->y) && (PLAYER.y <= actor->y + 7)) {
            return actor;
        }

        actor = actor->next;
    }

    return NULL;
}

void actors_handle_player_collision() __banked {
    if (player_iframes == 0 && player_collision_actor != NULL) {
        if (player_collision_actor->collision_group) {
            // Execute scene player hit scripts based on actor's collision group
            switch (player_collision_actor->collision_group) {
                case COLLISION_GROUP_1: {
                    if (PLAYER.script_hit1.bank) {
                        script_execute(PLAYER.script_hit1.bank, PLAYER.script_hit1.ptr, 0, 0);
                    }
                    break;
                }
                case COLLISION_GROUP_2: {
                    if (PLAYER.script_hit2.bank) {
                        script_execute(PLAYER.script_hit2.bank, PLAYER.script_hit2.ptr, 0, 0);
                    }
                    break;
                }                
                case COLLISION_GROUP_3: {
                    if (PLAYER.script_hit3.bank) {
                        script_execute(PLAYER.script_hit3.bank, PLAYER.script_hit3.ptr, 0, 0);
                    }
                    break;
                } 
            }
  
            // Execute actor's onHit player script
            if (player_collision_actor->script.bank) {
                script_execute(player_collision_actor->script.bank,
                               player_collision_actor->script.ptr, 0, 0);
            }

            // Set player to be invicible for N frames
            player_iframes = PLAYER_HURT_IFRAMES;
        }
    } else if (player_iframes != 0) {
        player_iframes--;
    }
    player_collision_actor = NULL; 
}

UBYTE check_collision_in_direction(UBYTE start_x, UBYTE start_y, UBYTE end_tile, col_check_dir_e check_dir) __banked {
  switch (check_dir) {
    case CHECK_DIR_LEFT:  // Check left
      while (start_x != end_tile) {
        if (tile_at_2x2(start_x - 1, start_y - 1) ||                    // Tile left
            actor_at_1x3_tile(start_x - 2, start_y - 1, FALSE) != NULL  // Actor left
        ) {
          return start_x;
        }
        start_x--;
      }
      return end_tile;
    case CHECK_DIR_RIGHT:  // Check right
      while (start_x != end_tile) {
        if (tile_at_2x2(start_x + 1, start_y - 1) ||                    // Tile right
            actor_at_1x3_tile(start_x + 2, start_y - 1, FALSE) != NULL  // Actor right
        ) {
          return start_x;
        }
        start_x++;
      }
      return end_tile;
    case CHECK_DIR_UP:  // Check up
      while (start_y != end_tile) {
        if (tile_at_2x2(start_x, start_y - 2) ||                          // Tile up
            (actor_at_3x1_tile(start_x - 1, start_y - 2, FALSE) != NULL)  // Actor up
        ) {
          return start_y;
        }
        start_y--;
      }
      return end_tile;
    case CHECK_DIR_DOWN:  // Check down
      while (start_y != end_tile) {
        if (tile_at_2x2(start_x, start_y) ||                               // Tile down
            actor_at_3x1_tile(start_x - 1, start_y + 1, FALSE) != NULL ||  // Actor down 1 tile
            actor_at_3x1_tile(start_x - 1, start_y + 2, FALSE) != NULL     // Actor down 2 tiles
        ) {
          return start_y;
        }
        start_y++;
      }
      return end_tile;
  }
  return end_tile;
}
