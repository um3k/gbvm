#include "DataManager.h"
#include "Scroll.h"

UBYTE image_bank;
UBYTE image_attr_bank;
UBYTE collision_bank;
unsigned char* image_ptr;
unsigned char* image_attr_ptr;
unsigned char* collision_ptr;
UBYTE image_tile_width;
UBYTE image_tile_height;
UINT16 image_width;
UINT16 image_height;
UBYTE sprites_len;
UBYTE actors_len = 0;
UBYTE scene_type;

void load_tiles(const tileset_t* tiles, UBYTE bank) {
    UBYTE _save = _current_bank;  
    SWITCH_ROM_MBC1(bank);
    set_bkg_data(0, tiles->n_tiles, tiles->tiles);
    SWITCH_ROM_MBC1(_save);      
}

void load_image(const background_t *background, UBYTE bank) {
    UBYTE _save = _current_bank;  

    SWITCH_ROM_MBC1(bank);
    image_bank = bank;
    image_tile_width = background->width;
    image_tile_height = background->height;
    image_width = image_tile_width * 8;
    scroll_x_max = image_width - ((UINT16)SCREENWIDTH);
    image_height = image_tile_height * 8;
    scroll_y_max = image_height - ((UINT16)SCREENHEIGHT);
    image_ptr = background->tiles;  

    load_tiles(background->tileset.ptr, background->tileset.bank);
    SWITCH_ROM_MBC1(_save);
}
