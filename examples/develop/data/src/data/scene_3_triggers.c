#pragma bank 255

// Scene: Underground
// Triggers

#include "gbs_types.h"
#include "data/script_s3t0_interact.h"
#include "data/script_s3t1_interact.h"

BANKREF(scene_3_triggers)

const struct trigger_t scene_3_triggers[] = {
    {
        // Trigger 1,
        .x = 21,
        .y = 31,
        .width = 2,
        .height = 1,
        .script = TO_FAR_PTR_T(script_s3t0_interact)
    },
    {
        // Trigger 2,
        .x = 11,
        .y = 11,
        .width = 2,
        .height = 2,
        .script = TO_FAR_PTR_T(script_s3t1_interact)
    }
};
