#pragma bank 255

// Scene: Outside
// Triggers

#include "gbs_types.h"
#include "data/script_s0t0_interact.h"
#include "data/script_s0t1_interact.h"
#include "data/script_s0t2_interact.h"

const void __at(255) __bank_scene_0_triggers;

const struct trigger_t scene_0_triggers[] = {
    {
        // Trigger 1,
        .x = 25,
        .y = 13,
        .width = 2,
        .height = 2,
        .script = TO_FAR_PTR_T(script_s0t0_interact)
    },
    {
        // Trigger 2,
        .x = 24,
        .y = 8,
        .width = 2,
        .height = 1,
        .script = TO_FAR_PTR_T(script_s0t1_interact)
    },
    {
        // Trigger 3,
        .x = 10,
        .y = 8,
        .width = 2,
        .height = 1,
        .script = TO_FAR_PTR_T(script_s0t2_interact)
    }
};
