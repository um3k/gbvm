#pragma bank 255

// Scene: Outside
// Triggers

#include "gbs_types.h"
#include "data/script_s0t0_interact.h"
#include "data/script_s0t1_interact.h"

const void __at(255) __bank_scene_0_triggers;

const struct trigger_t scene_0_triggers[] = {
    {
        // Trigger 1,
        .x = 2,
        .y = 10,
        .width = 2,
        .height = 2,
        .script = TO_FAR_PTR_T(script_s0t0_interact)
    },
    {
        // Trigger 2,
        .x = 2,
        .y = 23,
        .width = 2,
        .height = 2,
        .script = TO_FAR_PTR_T(script_s0t1_interact)
    }
};
