#pragma bank 255

// Scene: Cave
// Triggers

#include "gbs_types.h"
#include "data/script_s1t0_interact.h"
#include "data/script_s1t1_interact.h"

const void __at(255) __bank_scene_1_triggers;

const struct trigger_t scene_1_triggers[] = {
    {
        // Trigger 1,
        .x = 9,
        .y = 17,
        .width = 2,
        .height = 1,
        .script = TO_FAR_PTR_T(script_s1t0_interact)
    },
    {
        // Trigger 2,
        .x = 4,
        .y = 10,
        .width = 2,
        .height = 2,
        .script = TO_FAR_PTR_T(script_s1t1_interact)
    }
};
