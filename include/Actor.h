#ifndef ACTOR_H
#define ACTOR_H

#include <gb/gb.h>
#include "BankData.h"
#include "gbs_types.h"

#define MAX_ACTORS            20
#define MAX_ACTORS_ACTIVE     12

#define ACTOR_ATTR_H_FIRST    0x01
#define ACTOR_ATTR_CHECK_COLL 0x02

#define PLAYER                actors[0]
#define ON_8PX_GRID(A)        (MOD_8((A).x) == 0 && MOD_8((A).y) == 0)
#define ON_16PX_GRID(A)       (MOD_16((A).x) == 0 && MOD_16((A).y) == 8)

extern actor_t actors[MAX_ACTORS];
extern actor_t *actors_active_head;
extern actor_t *actors_inactive_head;
extern UBYTE actors_active_len;
extern UBYTE player_moving;

void actors_update() __banked;
void deactivate_actor(actor_t *actor) __banked;
void activate_actor(actor_t *actor) __banked;
void actor_set_flip_x(actor_t *actor, UBYTE flip) __banked;
void actor_set_frames(actor_t *actor, UBYTE frame_start, UBYTE frame_end) __banked;
void actor_set_dir(actor_t *actor, BYTE dir_x, BYTE dir_y) __banked;
actor_t *actor_at_tile(UBYTE tx, UBYTE ty, UBYTE inc_noclip) __banked;
void player_move(BYTE dir_x, BYTE dir_y) __banked;

inline void actor_set_anim(actor_t *actor, UBYTE animate) {
    actor->animate = animate;
}

#endif
