#ifndef _VM_gameboy_H_INCLUDE
#define _VM_gameboy_H_INCLUDE

#include "vm.h"

void vm_show_sprites() __banked;
void vm_hide_sprites() __banked;
void vm_input_wait(SCRIPT_CTX * THIS, UBYTE mask) __banked;
void vm_context_prepate(SCRIPT_CTX * THIS, UBYTE slot, UBYTE bank, UBYTE * pc) __banked;
void vm_input_attach(SCRIPT_CTX * THIS, UBYTE mask, UBYTE slot) __banked;
void vm_input_get(SCRIPT_CTX * THIS, INT16 idx) __banked;
void vm_fade_in_modal() __banked; 
void vm_fade_out_modal() __banked; 

#endif