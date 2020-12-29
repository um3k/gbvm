#ifndef ACTOR_H
#define ACTOR_H

#include <gb/gb.h>
#include "BankData.h"

#define MAX_ACTORS            20
#define MAX_ACTORS_ACTIVE     12

#define ACTOR_ATTR_H_FIRST    0x01
#define ACTOR_ATTR_CHECK_COLL 0x02

#define PLAYER                actors[0]

typedef struct actor_t
{
  UINT8 enabled; 
  UINT16 x;
  UINT16 y;
  BYTE dir_x;
  BYTE dir_y;
  UINT8 sprite_no;
  UINT8 pinned;
  UINT8 animate;
  UINT8 frame;
  UINT8 frame_start;
  UINT8 frame_end;
  UINT8 anim_tick;
  UINT8 flip_x;
  UINT8 rerender;
  UINT8 move_speed;

  UINT8 sprite, sprite_type, palette;
  UINT8 n_frames, initial_frame;
  UINT8 direction;
  UINT8 anim_speed;
  far_ptr_t script, script_update, script_hit1, script_hit2, script_hit3;

  // Collisions
  UBYTE collision_group;
  UBYTE collision_enabled;

  // Linked list
  struct actor_t *next;
  struct actor_t *prev;
} actor_t;

extern actor_t actors[MAX_ACTORS];
extern actor_t *actors_active_head;
extern actor_t *actors_inactive_head;
extern UBYTE actors_active_len;

void update_actors() __banked;
void deactivate_actor(actor_t *actor) __banked;
void activate_actor(actor_t *actor) __banked;
void actor_set_flip_x(actor_t *actor, UBYTE flip) __banked;
void actor_set_frames(actor_t *actor, UBYTE frame_start, UBYTE frame_end) __banked;
void actor_set_dir(actor_t *actor, BYTE dir_x, BYTE dir_y) __banked;
actor_t *actor_at_tile(UBYTE tx, UBYTE ty, UBYTE inc_noclip) __banked;

inline void actor_set_anim(actor_t *actor, UBYTE animate) {
    actor->animate = animate;
}

#endif
