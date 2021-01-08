#pragma bank 2

#include "vm.h"

#include "Actor.h"
#include "GameTime.h"
#include "DataManager.h"
#include "Scroll.h"

#define EMOTE_BOUNCE_FRAMES        15
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

const BYTE emote_offsets[] = {2, 1, 0, -1, -2, -3, -4, -5, -6, -5, -4, -3, -2, -1, 0};

void vm_actor_move_to(SCRIPT_CTX * THIS, INT16 idx) __banked {
    actor_t *actor;
    BYTE new_dir_x = 0;
    BYTE new_dir_y = 0;

    // indicate waitable state of context
    THIS->waitable = 1;

    act_move_to_t * params = VM_REF_TO_PTR(idx);
    actor = actors + params->ID;

    // if (start && stack_frame[4]) {
        // Check for collisions and modify
        // stack_frame[1] (x) and stack_frame[2] (y)
        // if obstacle is in the way
    // }

    // Actor reached destination
    if ((actor->x == params->X) && (actor->y == params->Y)) {
        actor_set_anim(actor, FALSE);
        return;
    }

    // Actor not at horizontal destination
    if ((actor->x != params->X) &&
        (!(params->ATTR & ACTOR_ATTR_H_FIRST) || (actor->y == params->Y))) {
        if (actor->x < params->X) {
            new_dir_x = 1;
        } else if (actor->x > params->X) {
            new_dir_x = -1;
        }
    } else {
        // Actor not at vertical destination
        // actor->dir.x = 0;
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
    UBYTE * n_actor = VM_REF_TO_PTR(idx);
    actor_t *actor = actors + *n_actor;

    // on first call load emote sprite 
    if (THIS->flags == 0) {
        THIS->flags = 1;
        *THIS->stack_ptr = 1;
        load_emote(emote_sprite, emote_sprite_bank);
    }

    if (*THIS->stack_ptr == EMOTE_TOTAL_FRAMES) {
        // Reset ctx flags
        THIS->flags = 0;
        move_sprite(0, 0, 0);
        move_sprite(1, 0, 0);
    } else {
        UINT16 screen_x, screen_y;
        THIS->waitable = 1;

        screen_x = 8u + actor->x - scroll_x;
        screen_y = 8u + actor->y - scroll_y;

        if (*THIS->stack_ptr < EMOTE_BOUNCE_FRAMES) {
            screen_y += emote_offsets[*THIS->stack_ptr];
        }

        move_sprite(0, screen_x, screen_y - 16u);
        move_sprite(1, screen_x + 8u, screen_y - 16u);

        (*THIS->stack_ptr)++;
        THIS->PC -= (INSTRUCTION_SIZE + sizeof(idx) + sizeof(emote_sprite_bank) + sizeof(emote_sprite));
    }
}
