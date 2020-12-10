#ifndef _VM_ACTOR_H_INCLUDE
#define _VM_ACTOR_H_INCLUDE

#include "vm.h"

void vm_actor_move_to(SCRIPT_CTX * THIS, INT16 idx) __banked;
void vm_actor_activate(void * THIS, UBYTE actor) __banked;
void vm_actor_set_dir(void * THIS, UBYTE actor, INT8 dir_x, INT8 dir_y) __banked;

#endif