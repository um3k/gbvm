#ifndef _VM_ACTOR_H_INCLUDE
#define _VM_ACTOR_H_INCLUDE

#include "vm.h"

void vm_actor_move_to(SCRIPT_CTX * THIS, INT16 idx) __banked;
void vm_actor_activate(SCRIPT_CTX * THIS, INT16 idx) __banked;
void vm_actor_set_dir(SCRIPT_CTX * THIS, INT16 idx, INT8 dir_x, INT8 dir_y) __banked;
void vm_actor_deactivate(SCRIPT_CTX * THIS, INT16 idx) __banked;
void vm_actor_set_anim(SCRIPT_CTX * THIS, INT16 idx, INT16 idx_anim) __banked;
void vm_actor_set_pos(SCRIPT_CTX * THIS, INT16 idx) __banked;

#endif