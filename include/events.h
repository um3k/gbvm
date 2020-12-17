#ifndef _EVENTS_H_INCLUDE
#define _EVENTS_H_INCLUDE

#include "vm.h"

typedef struct script_event_t {
    UWORD handle;
    UBYTE script_bank;
    void * script_addr;
} script_event_t;

extern script_event_t input_events[8]; 

void events_init() __banked;
void events_update() __nonbanked;

#endif