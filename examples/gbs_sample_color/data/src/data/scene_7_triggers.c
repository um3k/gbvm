#pragma bank 255

// Scene: Space Battle
// Triggers

#include "gbs_types.h"
#include "data/script_s7t0_interact.h"

BANKREF(scene_7_triggers)

const struct trigger_t scene_7_triggers[] = {
    {
        // Trigger 1,
        .x = 231,
        .y = 0,
        .width = 1,
        .height = 18,
        .script = TO_FAR_PTR_T(script_s7t0_interact),
        .script_flags = TRIGGER_HAS_ENTER_SCRIPT
    }
};
