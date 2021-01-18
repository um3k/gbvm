#pragma bank 255

// Scene: Dancefloor
// Triggers

#include "gbs_types.h"
#include "data/script_s6t0_interact.h"
#include "data/script_s6t1_interact.h"

const void __at(255) __bank_scene_6_triggers;

const struct trigger_t scene_6_triggers[] = {
  {
    // Trigger 1,
    .x = 0,
    .y = 13,
    .width = 1,
    .height = 1,
    .script = TO_FAR_PTR_T(script_s6t0_interact)
  },
  {
    // Trigger 2,
    .x = 19,
    .y = 13,
    .width = 1,
    .height = 1,
    .script = TO_FAR_PTR_T(script_s6t1_interact)
  }
};
