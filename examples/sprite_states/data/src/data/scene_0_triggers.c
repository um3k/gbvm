#pragma bank 255

// Scene: Start
// Triggers

#include "gbs_types.h"
#include "data/script_s0t0_interact.h"
#include "data/script_s0t1_interact.h"
#include "data/script_s0t2_interact.h"
#include "data/script_s0t3_interact.h"

const void __at(255) __bank_scene_0_triggers;

const struct trigger_t scene_0_triggers[] = {
    {
        // Trigger 1,
        .x = 2,
        .y = 11,
        .width = 28,
        .height = 1,
        .script = TO_FAR_PTR_T(script_s0t0_interact)
    },
    {
        // Trigger 2,
        .x = 2,
        .y = 20,
        .width = 28,
        .height = 1,
        .script = TO_FAR_PTR_T(script_s0t1_interact)
    },
    {
        // Trigger 3,
        .x = 2,
        .y = 12,
        .width = 28,
        .height = 1,
        .script = TO_FAR_PTR_T(script_s0t2_interact)
    },
    {
        // Trigger 4,
        .x = 2,
        .y = 19,
        .width = 28,
        .height = 1,
        .script = TO_FAR_PTR_T(script_s0t3_interact)
    }
};
