#pragma bank 2

#include <string.h>

#include "Input.h"
#include "vm.h"

UBYTE joy = 0;
UBYTE last_joy = 0;
UBYTE recent_joy = 0;

script_event_t input_events[8];

void input_init() __banked {
    memset(input_events, 0, sizeof(input_events));
}

void input_update() __nonbanked {
    last_joy = joy;
    joy = joypad();

    if ((joy & INPUT_DPAD) != (last_joy & INPUT_DPAD))
        recent_joy = joy & ~last_joy;

    if (joy == 0) return;

    script_event_t * event = input_events;    
    for (UBYTE tmp = joy; (tmp); tmp = tmp >> 1, event++) {
        if (tmp & 1) {
            if (!event->script_addr) continue;
            if ((event->handle == 0) || ((event->handle & 0x8000) == 0)) {
                ExecuteScript(event->script_bank, event->script_addr, &event->handle, 0);
            }
        }
    }
}
