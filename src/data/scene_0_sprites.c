#pragma bank 255

// Scene: Cave
// Sprites

#include "data/gbs_types.h"
#include "data/spritesheet_1.h"
#include "data/spritesheet_2.h"
#include "data/spritesheet_3.h"

const void __at(255) __bank_scene_0_sprites;

const far_ptr_t scene_0_sprites[] = {
  TO_FAR_PTR_T(spritesheet_1),
  TO_FAR_PTR_T(spritesheet_2),
  TO_FAR_PTR_T(spritesheet_3)
};
