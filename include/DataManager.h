#ifndef SCENE_H
#define SCENE_H

#include <gb/gb.h>
#include "gbs_types.h"

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

void load_tiles(const tileset_t* tiles, UBYTE bank) __banked;
void load_image(const background_t *background, UBYTE bank) __banked;
void load_palette(const UBYTE *data_ptr, UBYTE bank) __banked;
void load_sprite_palette(const UBYTE *data_ptr, UBYTE bank) __banked;
void load_player_palette(const UBYTE *data_ptr, UBYTE bank) __banked;
UBYTE load_sprite(UBYTE sprite_offset, const spritesheet_t *sprite, UBYTE bank) __banked;
UBYTE load_scene(const scene_t *scene, UBYTE bank) __banked;
void load_player() __banked;

#endif
