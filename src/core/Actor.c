#pragma bank 1

#include <string.h>

#include "Actor.h"
#include "GameTime.h"
#include "Scroll.h"
#include "LinkedList.h"
#include "Math.h"
#include "Sprite.h"
#include <gb/gb.h>
#ifdef STRICT
#include <gb/bgb_emu.h>
#include <gb/crash_handler.h>
#endif

actor_t actors[MAX_ACTORS];
actor_t *actors_active_head = 0;
actor_t *actors_inactive_head = 0;
UBYTE actors_active_len = 0;

actor_t *actor;
INT8 screen_x, screen_y;
actor_t *invalid;
UBYTE player_moving = FALSE;

void actors_update() __banked
{
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
            move_sprite(actor->sprite_no,     0, 0);
            move_sprite(actor->sprite_no + 1, 0, 0);
            actor = actor->next;
            continue;
        }

        move_sprite(actor->sprite_no,     screen_x,     screen_y);
        move_sprite(actor->sprite_no + 1, screen_x + 8, screen_y);

        // Check if should animate
        if ((actor->animate) && ((game_time & 0x3) == 0)) {
          // Check reached animation tick frame
            if ((game_time & actor->anim_tick) == 0) {
                actor->frame += 4;

                // Check reached end of animation
                if (actor->frame == actor->frame_end) actor->frame = actor->frame_start;

                actor->rerender = TRUE;
            }
        }

        // Check for forced rerender
        if (actor->rerender) {
              if (actor->flip_x) {
                  set_sprite_tile(actor->sprite_no + 1, actor->frame);
                  set_sprite_tile(actor->sprite_no, actor->frame + 2);
              } else  {
                  set_sprite_tile(actor->sprite_no, actor->frame);
                  set_sprite_tile(actor->sprite_no + 1, actor->frame + 2);
              }      
              actor->rerender = FALSE;
        }

        actor = actor->next;
    }
    return;
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
    if (!actor->enabled) {
        return;
    }
    actors_active_len--;
    actor->enabled = FALSE;
    DL_REMOVE_ITEM(actors_active_head, actor);
    move_sprite(actor->sprite_no, 0, 0);
    move_sprite(actor->sprite_no + 1, 0, 0);
    release_sprite(actor->sprite_no);
    DL_PUSH_HEAD(actors_inactive_head, actor);
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
    if (actors_active_len == MAX_ACTORS_ACTIVE) return;
    if (actor->enabled) return;
    actors_active_len++;
    actor->enabled = TRUE;
    actor->rerender = TRUE;
    actor->sprite_no = get_free_sprite();
    DL_REMOVE_ITEM(actors_inactive_head, actor);
    DL_PUSH_HEAD(actors_active_head, actor);
}

void actor_set_flip_x(actor_t *actor, UBYTE flip) __banked
{
    if (flip) {
        set_sprite_prop(actor->sprite_no, S_FLIPX);
        set_sprite_prop(actor->sprite_no + 1, S_FLIPX);
    } else {
        set_sprite_prop(actor->sprite_no, 0);
        set_sprite_prop(actor->sprite_no + 1, 0);
    }
    actor->flip_x = flip;
    actor->rerender = TRUE;
}

void actor_set_frames(actor_t *actor, UBYTE frame_start, UBYTE frame_end) __banked
{
    if (actor->frame_start != frame_start || actor->frame_end != frame_end) {
        actor->frame = frame_start;
        actor->frame_start = frame_start;
        actor->frame_end = frame_end;
        actor->rerender = TRUE;
    }
}

void actor_set_dir(actor_t *actor, BYTE dir_x, BYTE dir_y) __banked
{
    actor->dir_x = dir_x;
    actor->dir_y = dir_y;
    
    if (actor->sprite_type != SPRITE_TYPE_STATIC) {
        if (dir_x == -1) {
            actor_set_frames(actor, MUL_4(actor->sprite + (2 * actor->n_frames)), MUL_4(actor->sprite + (3 * actor->n_frames)));
            actor_set_flip_x(actor, TRUE);
        } else if (dir_x == 1) {
            actor_set_frames(actor, MUL_4(actor->sprite + (2 * actor->n_frames)), MUL_4(actor->sprite + (3 * actor->n_frames)));
            actor_set_flip_x(actor, FALSE);
        } else if (dir_y == -1) {
            actor_set_frames(actor, MUL_4(actor->sprite + actor->n_frames), MUL_4(actor->sprite + (2 * actor->n_frames)));
            actor_set_flip_x(actor, FALSE);
        } else if (dir_y == 1) {
            actor_set_frames(actor, MUL_4(actor->sprite), MUL_4(actor->sprite + actor->n_frames));
            actor_set_flip_x(actor, FALSE);
        }
    }

    actor->rerender = TRUE;
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
