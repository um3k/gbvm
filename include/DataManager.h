#ifndef SCENE_H
#define SCENE_H

#include <gb/gb.h>
#include "data/data_types.h"

extern UBYTE image_bank;
extern UBYTE image_attr_bank;
extern UBYTE collision_bank;
extern unsigned char *image_ptr;
extern unsigned char *image_attr_ptr;
extern unsigned char *collision_ptr;
extern UBYTE image_tile_width;
extern UBYTE image_tile_height;
extern UINT16 image_width;
extern UINT16 image_height;
extern UBYTE scene_type;
extern UBYTE actors_len;
extern UBYTE sprites_len;
extern UBYTE actors_len;

void load_tiles(const tileset_t* tiles, UBYTE bank);
void load_image(const background_t *background, UBYTE bank);
void load_palette(const UBYTE *data_ptr, UBYTE bank);
void load_sprite_palette(const UBYTE *data_ptr, UBYTE bank);
void load_player_palette(const UBYTE *data_ptr, UBYTE bank);
UBYTE load_sprite(UBYTE sprite_offset, const spritesheet_t *sprite, UBYTE bank);
void load_scene(const scene_t *scene, UBYTE bank);

#endif
