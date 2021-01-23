#ifndef GBS_TYPES_H
#define GBS_TYPES_H

#include "BankData.h"
#include "parallax.h"
#include "metasprite.h"
#include "Collision.h"

typedef enum {
    SCENE_TYPE_TOPDOWN = 0,
    SCENE_TYPE_PLATFORM,
    SCENE_TYPE_ADVENTURE,
    SCENE_TYPE_SHMUP,
    SCENE_TYPE_POINTNCLICK
} scene_type_e;

typedef enum {
    SPRITE_TYPE_STATIC = 0,
    SPRITE_TYPE_ACTOR,
    SPRITE_TYPE_ACTOR_ANIMATED
} sprite_type_e;

typedef enum {
    COLLISION_GROUP_NONE = 0,
    COLLISION_GROUP_PLAYER = 1,
    COLLISION_GROUP_1 = 2,
    COLLISION_GROUP_2 = 4,
    COLLISION_GROUP_3 = 8,
} collision_group_e;

typedef struct actor_t
{
  UINT8 enabled; 
  position_t pos;
  BYTE dir_x;
  BYTE dir_y;
  bounding_box_t bounds;
  UINT8 base_tile;
  UINT8 pinned;
  UINT8 animate;
  UINT8 frame;
  UINT8 frame_start;
  UINT8 frame_end;
  UINT8 anim_tick;
  UINT8 flip_x;
  UINT8 move_speed;
  sprite_type_e sprite_type;
  UINT8 palette;
  UINT8 n_frames;
  far_ptr_t sprite;
  far_ptr_t script, script_update, script_hit1, script_hit2, script_hit3;
  UBYTE ctx_id;

  // Collisions
  collision_group_e collision_group;
  UBYTE collision_enabled;

  // Linked list
  struct actor_t *next;
  struct actor_t *prev;
} actor_t;

typedef struct trigger_t {
    UINT8 x, y, width, height;
    far_ptr_t script;
} trigger_t;

typedef struct scene_t {
    UINT8 width, height;
    scene_type_e type;
    UINT8 n_actors, n_triggers, n_sprites;
    far_ptr_t background, collisions, colors, palette, sprite_palette;
    far_ptr_t script_init, script_p_hit1, script_p_hit2, script_p_hit3;
    far_ptr_t sprites;
    far_ptr_t actors;
    far_ptr_t triggers;
    parallax_row_t parallax_rows[3];
} scene_t;

typedef struct background_t {
    UINT8 width, height;
    far_ptr_t tileset;
    UINT8 tiles[];
} background_t;

typedef struct tileset_t {
    UINT8 n_tiles;
    UINT8 tiles[];
} tileset_t;

typedef struct spritesheet_t {
    UINT8 n_tiles;
    UINT8 n_metasprites;
    metasprite_t * const *metasprites;
    UINT8 tiles[];
} spritesheet_t;

#endif
