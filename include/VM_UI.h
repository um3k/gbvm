#ifndef _VM_UI_H_INCLUDE
#define _VM_UI_H_INCLUDE

#include "vm.h"

void vm_load_text(UWORD dummy0, UWORD dummy1, SCRIPT_CTX * THIS, UBYTE nargs) __nonbanked;
void vm_display_text(SCRIPT_CTX * THIS, UBYTE avatar_index) __banked;

void vm_overlay_setpos(SCRIPT_CTX * THIS, UBYTE pos_x, UBYTE pos_y) __banked;
void vm_overlay_hide() __banked;
void vm_overlay_wait(SCRIPT_CTX * THIS) __banked;
void vm_overlay_move_to(SCRIPT_CTX * THIS, UBYTE pos_x, UBYTE pos_y, UBYTE speed) __banked;
void vm_overlay_show(SCRIPT_CTX * THIS, UBYTE pos_x, UBYTE pos_y, UBYTE color) __banked;
void vm_overlay_clear(SCRIPT_CTX * THIS, UBYTE color) __banked;

#endif