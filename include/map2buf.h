#ifndef __MAP2BUF_H_INCLUDE
#define __MAP2BUF_H_INCLUDE

#include <gb/gb.h>

// extract tile map from buffer, containing another tilemap with image_tile_width X image_tile_width dimentions, stored in global variables
void get_map_from_buf(UBYTE x, UBYTE y, UBYTE w, UBYTE h, unsigned char * dest, unsigned char * image) __preserves_regs(b, c);
void map_to_screen(UBYTE x, UBYTE y, UBYTE w, UBYTE h, unsigned char * dest, unsigned char * image) __preserves_regs(b, c);

#endif