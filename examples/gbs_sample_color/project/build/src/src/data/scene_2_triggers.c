#pragma bank 255

// Scene: Top House
// Triggers

#include "gbs_types.h"
#include "data/script_s2t0_interact.h"

const void __at(255) __bank_scene_2_triggers;

const struct trigger_t scene_2_triggers[] = {
    {
        // Trigger 1,
        .x = 9,
        .y = 16,
        .width = 2,
        .height = 1,
        .script = TO_FAR_PTR_T(script_s2t0_interact)
    }
};
