#pragma bank 255

// Scene: Deep Space
// Triggers

#include "gbs_types.h"
#include "data/script_s11t0_interact.h"

const void __at(255) __bank_scene_11_triggers;

const struct trigger_t scene_11_triggers[] = {
    {
        // Trigger 1,
        .x = 14,
        .y = 9,
        .width = 2,
        .height = 2,
        .script = TO_FAR_PTR_T(script_s11t0_interact)
    }
};
