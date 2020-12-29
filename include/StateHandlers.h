#ifndef __STATEHANDLERS_H_INCLUDE
#define __STATEHANDLERS_H_INCLUDE

#include <gb/gb.h>

typedef void (*Void_Func_Void)();

extern const Void_Func_Void state_start_fns[];
extern const Void_Func_Void state_update_fns[];
extern const UBYTE stateBanks[];

#endif