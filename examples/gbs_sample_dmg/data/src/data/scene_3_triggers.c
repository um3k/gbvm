#pragma bank 255

// Scene: Stars
// Triggers

#include "gbs_types.h"
#include "data/script_s3t0_interact.h"

const void __at(255) __bank_scene_3_triggers;

const struct trigger_t scene_3_triggers[] = {
    {
        // Trigger 1,
        .x = 15,
        .y = 7,
        .width = 2,
        .height = 2,
        .script = TO_FAR_PTR_T(script_s3t0_interact)
    }
};
