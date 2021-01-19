#ifndef METASPRITE_H
#define METASPRITE_H

#include <gb/gb.h>

extern const void * __current_metasprite;
extern UBYTE __current_base_tile;

void __move_metasprite(UINT8 id, UINT8 x, UINT8 y);
void __hide_metasprite(UINT8 id);

inline void move_metasprite(const void * metasprite, UINT8 base_tile, UINT8 base_sprite, UINT8 x, UINT8 y) {
    __current_metasprite = metasprite; 
    __current_base_tile = base_tile;
    __move_metasprite(base_sprite, x, y); 
}

inline void hide_metasprite(const void * metasprite, UINT8 base_sprite) {
    __current_metasprite = metasprite; 
    __hide_metasprite(base_sprite);
}

#endif
