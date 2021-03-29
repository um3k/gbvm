#ifndef PALETTE_H
#define PALETTE_H

#include <gb/gb.h>
#include "gbs_types.h"

extern palette_entry_t SprPalette[8];
extern palette_entry_t BkgPalette[8];

void palette_init() __banked;

#ifdef CGB
void CGBZeroPalette(UBYTE reg) __banked;
#endif

#endif
