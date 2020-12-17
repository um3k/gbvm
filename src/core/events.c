#include <string.h>

#include "events.h"
#include "Input.h"

script_event_t input_events[8];

void events_init() __banked {
    memset(input_events, 0, sizeof(input_events));
}

void events_update() __nonbanked {
    script_event_t * event = input_events;    
    for (UBYTE tmp = joy; (tmp); tmp = tmp >> 1, event++) {
        if (tmp & 1) {
            if (!event->script_addr) continue;
            if ((event->handle == 0) || ((event->handle & 0x8000) != 0))
                ExecuteScript(event->script_bank, event->script_addr, &event->handle, 0);
        }
    }
}