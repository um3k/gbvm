#ifndef SPRITE_H
#define SPRITE_H

#include <gb/gb.h>
#include "data/data_types.h"

#define MAX_SPRITES 20

// typedef struct spritesheet_t {
//     UINT8 n_frames;
//     UINT8 frames[];
// } spritesheet_t;

extern UINT8 sprites_pool[MAX_SPRITES];
extern UINT8 sprites_pool_next;
extern UINT8 hide_sprites;

void init_sprite_pool() __banked;
UINT8 get_free_sprite() __banked;
void release_sprite(UINT8 sprite_no) __banked;

#endif
