#pragma bank 255

// Scene: Platform Scene
// Triggers

#include "gbs_types.h"
#include "data/script_s4t0_interact.h"
#include "data/script_s4t1_interact.h"
#include "data/script_s4t2_interact.h"
#include "data/script_s4t3_interact.h"

const void __at(255) __bank_scene_4_triggers;

const struct trigger_t scene_4_triggers[] = {
  {
    // Trigger 1,
    .x = 160,
    .y = 13,
    .width = 1,
    .height = 1,
    .script = TO_FAR_PTR_T(script_s4t0_interact)
  },
  {
    // Trigger 2,
    .x = 6,
    .y = 13,
    .width = 2,
    .height = 1,
    .script = TO_FAR_PTR_T(script_s4t1_interact)
  },
  {
    // Trigger 3,
    .x = 56,
    .y = 17,
    .width = 3,
    .height = 1,
    .script = TO_FAR_PTR_T(script_s4t2_interact)
  },
  {
    // Trigger 4,
    .x = 14,
    .y = 8,
    .width = 1,
    .height = 1,
    .script = TO_FAR_PTR_T(script_s4t3_interact)
  }  
};
