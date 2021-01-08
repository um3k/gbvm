#ifndef _LOADSAVE_H_INCLUDE
#define _LOADSAVE_H_INCLUDE

#include <gb/gb.h>

// check SRAM contains valid save blob
UBYTE data_is_saved() __banked;

// save state to SRAM
void data_save() __banked;

// load state from SRAM
UBYTE data_load() __banked;

#endif