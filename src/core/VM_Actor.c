#pragma bank 2

#include "vm.h"

#include "Actor.h"
#include "GameTime.h"
#include "DataManager.h"
#include "Scroll.h"
#include "Math.h"
#include "metasprite.h"

#define EMOTE_TOTAL_FRAMES         60

typedef struct act_move_to_t {
    UBYTE ID;
    UBYTE _pad0; 
    INT16 X, Y;
    UBYTE ATTR; 
} act_move_to_t;

typedef struct act_set_pos_t {
    UBYTE ID;
    UBYTE _pad0;
    INT16 X, Y;
} act_set_pos_t;

void vm_actor_move_to(SCRIPT_CTX * THIS, INT16 idx) __banked {
    actor_t *actor;
    BYTE new_dir_x = 0;
    BYTE new_dir_y = 0;

    // indicate waitable state of context
    THIS->waitable = 1;

    act_move_to_t * params = VM_REF_TO_PTR(idx);
    actor = actors + params->ID;

    if (THIS->flags == 0) {
        THIS->flags = 1;
        // Check for collisions in path
        if (params->ATTR & ACTOR_ATTR_CHECK_COLL) {
            if (params->ATTR & ACTOR_ATTR_H_FIRST) {
                // Check for horizontal collision
                if (actor->x != params->X) {
                    UBYTE check_dir = (actor->x > params->X) ? CHECK_DIR_LEFT : CHECK_DIR_RIGHT;
                    params->X = check_collision_in_direction((actor->x >> 7), (actor->y >> 7), (params->X >> 7), check_dir) << 7;
                }
                // Check for vertical collision
                if (actor->y != params->Y) {
                    UBYTE check_dir = (actor->y > params->Y) ? CHECK_DIR_UP : CHECK_DIR_DOWN;
                    params->Y = check_collision_in_direction((params->X >> 7), (actor->y >> 7), (params->Y >> 7), check_dir) << 7;
                }
            } else {
                // Check for vertical collision
                if (actor->y != params->Y) {
                    UBYTE check_dir = (actor->y > params->Y) ? CHECK_DIR_UP : CHECK_DIR_DOWN;
                    params->Y = check_collision_in_direction((actor->x >> 7), (actor->y >> 7), (params->Y >> 7), check_dir) << 7;
                }
                // Check for horizontal collision
                if (actor->x != params->X) {
                    UBYTE check_dir = (actor->x > params->X) ? CHECK_DIR_LEFT : CHECK_DIR_RIGHT;
                    params->X = check_collision_in_direction((actor->x >> 7), (params->Y >> 7), (params->X >> 7), check_dir) << 7;
                }
            }
        }
    }

    // Actor reached destination
    if ((actor->x == params->X) && (actor->y == params->Y)) {
        THIS->flags = 0;
        actor_set_anim(actor, FALSE);
        return;
    }

    // Actor not at horizontal destination
    if ((actor->x != params->X) &&
        ((params->ATTR & ACTOR_ATTR_H_FIRST) || (actor->y == params->Y))) {
        if (actor->x < params->X) {
            new_dir_x = 1;
        } else if (actor->x > params->X) {
            new_dir_x = -1;
        }
    } else {
        // Actor not at vertical destination
        if (actor->y < params->Y) {
            new_dir_y = 1;
        } else if (actor->y > params->Y) {
            new_dir_y = -1;
        }
    }

    // If changed direction, trigger actor rerender
    if ((actor->dir_x != new_dir_x) ||
        (actor->dir_y != new_dir_y)) {
        actor_set_dir(actor, new_dir_x, new_dir_y);
    }

    actor_set_anim(actor, TRUE);

    // Move actor
    if (actor->move_speed == 0) {
        // Half speed only move every other frame
        if (IS_FRAME_2) {
            actor->x += (WORD)new_dir_x;
            actor->y += (WORD)new_dir_y;
        }
    } else {
        actor->x += (WORD)(new_dir_x * actor->move_speed);
        actor->y += (WORD)(new_dir_y * actor->move_speed);
    }

    THIS->PC -= (INSTRUCTION_SIZE + sizeof(idx));
    return;
}

void vm_actor_activate(SCRIPT_CTX * THIS, INT16 idx) __banked {    
    UBYTE * n_actor = VM_REF_TO_PTR(idx);
    activate_actor(actors + *n_actor);
}

void vm_actor_deactivate(SCRIPT_CTX * THIS, INT16 idx) __banked {    
    UBYTE * n_actor = VM_REF_TO_PTR(idx);
    deactivate_actor(actors + *n_actor);
}

void vm_actor_set_dir(SCRIPT_CTX * THIS, INT16 idx, INT8 dir_x, INT8 dir_y) __banked {
    UBYTE * n_actor = VM_REF_TO_PTR(idx);
    actor_set_dir(actors + *n_actor, dir_x, dir_y);
}

void vm_actor_set_anim(SCRIPT_CTX * THIS, INT16 idx, INT16 idx_anim) __banked {
    UBYTE * n_actor = VM_REF_TO_PTR(idx);
    UBYTE * n_anim = VM_REF_TO_PTR(idx_anim);
    actor_set_anim(actors + *n_actor, *n_anim);
}

void vm_actor_set_pos(SCRIPT_CTX * THIS, INT16 idx) __banked {
    actor_t *actor;
    
    act_set_pos_t * params = VM_REF_TO_PTR(idx);
    actor = actors + params->ID;

    actor->x = params->X;
    actor->y = params->Y;
}

void vm_actor_emote(SCRIPT_CTX * THIS, INT16 idx, UBYTE emote_sprite_bank, spritesheet_t *emote_sprite) __banked {

    // on first call load emote sprite 
    if (THIS->flags == 0) {
        UBYTE * n_actor = VM_REF_TO_PTR(idx);
        THIS->flags = 1;
        emote_actor = actors + *n_actor;
        emote_timer = 1;
        load_emote(emote_sprite, emote_sprite_bank);
    }

    if (emote_timer == EMOTE_TOTAL_FRAMES) {
        // Reset ctx flags
        THIS->flags = 0;
        emote_actor = NULL;
    } else {
        THIS->waitable = 1;
        emote_timer++;
        THIS->PC -= (INSTRUCTION_SIZE + sizeof(idx) + sizeof(emote_sprite_bank) + sizeof(emote_sprite));
    }
}
