#ifndef _VM_UI_H_INCLUDE
#define _VM_UI_H_INCLUDE

#include "vm.h"

void vm_load_text(UWORD dummy0, UWORD dummy1, SCRIPT_CTX * THIS, UBYTE nargs) __nonbanked;
void vm_display_text(SCRIPT_CTX * THIS) __banked;

#endif