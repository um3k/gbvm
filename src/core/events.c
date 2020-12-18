#include <string.h>

#include "events.h"
#include "Input.h"

script_event_t input_events[8];
UBYTE event_slots[8];

void events_init() __banked {
    memset(event_slots, 0, sizeof(event_slots));
    memset(input_events, 0, sizeof(input_events));
}

void events_update() __nonbanked {
    UBYTE * slot = event_slots;
    UBYTE key = 1;    
    for (UBYTE tmp = joy; (tmp); tmp = tmp >> 1, key = key << 1, slot++) {
        if (tmp & 1) {
            if (*slot == 0) continue;
            script_event_t * event = &input_events[*slot - 1u];
            if (!event->script_addr) continue;
            if ((event->handle == 0) || ((event->handle & 0x8000) != 0))
                ExecuteScript(event->script_bank, event->script_addr, &event->handle, 1, (int)key);
        }
    }
}