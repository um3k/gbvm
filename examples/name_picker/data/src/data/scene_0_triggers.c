#pragma bank 255

// Scene: Scene 1
// Triggers

#include "gbs_types.h"
#include "data/script_s0t0_interact.h"
#include "data/script_s0t1_interact.h"

const void __at(255) __bank_scene_0_triggers;

const struct trigger_t scene_0_triggers[] = {
    {
        // Caps Letters,
        .x = 1,
        .y = 1,
        .width = 9,
        .height = 9,
        .script = TO_FAR_PTR_T(script_s0t0_interact)
    },
    {
        // Low letters,
        .x = 10,
        .y = 1,
        .width = 9,
        .height = 9,
        .script = TO_FAR_PTR_T(script_s0t1_interact)
    }
};
