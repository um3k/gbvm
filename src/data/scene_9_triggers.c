#pragma bank 255

// Scene: Scene 10
// Triggers

#include "gbs_types.h"
#include "data/script_s9t0_interact.h"
#include "data/script_s9t1_interact.h"

const void __at(255) __bank_scene_9_triggers;

const struct trigger_t scene_9_triggers[] = {
  {
    // Trigger 1,
    .x = 10,
    .y = 7,
    .width = 3,
    .height = 3,
    .script = TO_FAR_PTR_T(script_s9t0_interact)
  },
  {
    // Trigger 2,
    .x = 0,
    .y = 2,
    .width = 3,
    .height = 12,
    .script = TO_FAR_PTR_T(script_s9t1_interact)
  }
};
