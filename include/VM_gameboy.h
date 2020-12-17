#ifndef _VM_gameboy_H_INCLUDE
#define _VM_gameboy_H_INCLUDE

#include "vm.h"

void vm_show_sprites() __banked;
void vm_hide_sprites() __banked;
void vm_input_wait(SCRIPT_CTX * THIS, UBYTE mask) __banked;
void vm_input_attach(SCRIPT_CTX * THIS, UBYTE mask, UBYTE bank, UBYTE * pc) __banked;

#endif