#ifndef __MAP2BUF_H_INCLUDE
#define __MAP2BUF_H_INCLUDE

#include <gb/gb.h>

// extract tile map from buffer, containing another tilemap with buf_w / buf_h dimentions
void get_map_from_buf(UBYTE x, UBYTE y, UBYTE w, UBYTE h, unsigned char * dest, unsigned char * buf, UBYTE buf_w, UBYTE buf_h) __preserves_regs(b, c);

#endif