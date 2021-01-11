#ifndef PARALLAX_H_INCLUDE
#define PARALLAX_H_INCLUDE

#include <gb/gb.h>

#define PARALLAX_STEP(start, end, shift)  {(start)?(((start) << 3) - 1):0, (end)?(((end) << 3) - 1):0, (shift)}

typedef struct parallax_row_t {
    UBYTE y;
    UBYTE next_y;
    UBYTE shift;
} parallax_row_t;

extern parallax_row_t parallax_rows[3];
extern parallax_row_t * parallax_row;

void parallax_LCD_isr() __nonbanked;

#endif