#ifndef _VM_MUSIC_H_INCLUDE
#define _VM_MUSIC_H_INCLUDE

#include "vm.h"

void vm_music_play(SCRIPT_CTX * THIS, UBYTE track, UBYTE loop) __banked;
void vm_music_stop() __banked;

#endif