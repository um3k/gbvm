#ifndef METASPRITE_H
#define METASPRITE_H

#include <gb/gb.h>

typedef struct metasprite_item_t {
    INT8  did;
    INT8  dy, dx;
    UINT8 dtile;
    UINT8 props;
} metasprite_item_t;

typedef struct metasprite_t {
    UINT8 count;
    metasprite_item_t items[];
} metasprite_t;

#define metasprite_end 0 

extern volatile struct OAM_item_t shadow_OAM2[40];
extern UBYTE __render_shadow_OAM;

extern UINT8 hide_sprites;

extern const void * __current_metasprite;
extern UBYTE __current_base_tile;

UINT8 __move_metasprite(UINT8 id, UINT8 x, UINT8 y);
void hide_hardware_sprites(UINT8 from, UINT8 to);

inline UINT8 move_metasprite(const void * metasprite, UINT8 base_tile, UINT8 base_sprite, UINT8 x, UINT8 y) {
    __current_metasprite = metasprite; 
    __current_base_tile = base_tile;
    return __move_metasprite(base_sprite, x, y); 
}

#endif
