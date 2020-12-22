#ifndef SCENE_H
#define SCENE_H

#include <gb/gb.h>
#include "data/data_types.h"

void load_tiles(const tileset_t* tiles, UBYTE bank);
void load_image(const background_t *background, UBYTE bank);
void load_palette(const UBYTE *data_ptr, UBYTE bank);
void load_sprite_palette(const UBYTE *data_ptr, UBYTE bank);
void load_player_palette(const UBYTE *data_ptr, UBYTE bank);
UBYTE load_sprite(UBYTE sprite_offset, const spritesheet_t *sprite, UBYTE bank);
void load_scene(const scene_t *scene, UBYTE bank);

#endif
