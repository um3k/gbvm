#pragma bank 255

// Scene: Deeper Underground
// Triggers

#include "gbs_types.h"
#include "data/script_s6t0_interact.h"

const void __at(255) __bank_scene_6_triggers;

const struct trigger_t scene_6_triggers[] = {
    {
        // Trigger 1,
        .x = 5,
        .y = 0,
        .width = 1,
        .height = 1,
        .script = TO_FAR_PTR_T(script_s6t0_interact)
    }
};
