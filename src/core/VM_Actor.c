#pragma bank 2

#include <stdio.h>

#include "vm.h"

#include "Actor.h"
#include "GameTime.h"

void actor_move_to(SCRIPT_CTX * THIS, INT16 idx) __banked {
    actor_t *actor;
    BYTE new_dir_x = 0;
    BYTE new_dir_y = 0;

    UWORD * stack_frame = (idx < 0) ? THIS->stack_ptr + idx : script_memory + idx;

    // indicate waitable state of context
    THIS->waitable = 1;

    actor = &actors[stack_frame[0]];

    // if (start && stack_frame[4]) {
        // Check for collisions and modify
        // stack_frame[1] (x) and stack_frame[2] (y)
        // if obstacle is in the way
    // }

    // Actor reached destination
    if (actor->x == stack_frame[1] &&
        actor->y == stack_frame[2])
    {
        actor_set_anim(actor, FALSE);
        return;
    }

    // Actor not at horizontal destination
    if (actor->x != stack_frame[1] &&
        (!stack_frame[3] || (actor->y == stack_frame[2])))
    {
        if (actor->x < stack_frame[1])
        {
            new_dir_x = 1;
        }
        else if (actor->x > stack_frame[1])
        {
            new_dir_x = -1;
        }
    }
    else
    {
        // Actor not at vertical destination
        // actor->dir.x = 0;
        if (actor->y < stack_frame[2])
        {
            new_dir_y = 1;
        }
        else if (actor->y > stack_frame[2])
        {
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
    if (actor->move_speed == 0)
    {
        // Half speed only move every other frame
        if (IS_FRAME_2)
        {
            actor->x += (WORD)new_dir_x;
            actor->y += (WORD)new_dir_y;
        }
    }
    else
    {
        actor->x += (WORD)(new_dir_x * actor->move_speed);
        actor->y += (WORD)(new_dir_y * actor->move_speed);
    }

    THIS->PC -= (INSTRUCTION_SIZE + sizeof(idx));
    return;
}

UBYTE vm_actor_activate(void * THIS, UBYTE start, UWORD * stack_frame) __banked {    
    THIS, start;
    actor_t *actor;
    actor = &actors[stack_frame[0]];
    activate_actor(actor);
    return TRUE;
}

UBYTE vm_actor_set_dir(void * THIS, UBYTE start, UWORD * stack_frame) __banked {
    THIS, start;
    actor_t *actor;
    actor = &actors[stack_frame[0]];
    actor_set_dir(actor, stack_frame[1], stack_frame[2]);
    return TRUE;
}
