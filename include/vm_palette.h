#ifndef _VM_PALETTE_H_INCLUDE
#define _VM_PALETTE_H_INCLUDE

#include <gb/gb.h>

#include "vm.h"
#include "palette.h"

#define PALETTE_COMMIT 1
#define PALETTE_BKG    2
#define PALETTE_SPRITE 4

void vm_load_palette(SCRIPT_CTX * THIS, UBYTE mask, UBYTE options) __banked;
void vm_set_sgb_attributes(SCRIPT_CTX * THIS, UBYTE x1, UBYTE y1, UBYTE x2, UBYTE y2, UBYTE control, UBYTE palettes) __banked;

#endif