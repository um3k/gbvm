#pragma bank 255

// Scene: Underground
// Sprites

#include "data/data_types.h"
#include "data/spritesheet_4.h"
#include "data/spritesheet_5.h"
#include "data/spritesheet_6.h"
#include "data/spritesheet_7.h"

const void __at(255) __bank_scene_1_sprites;

const far_ptr_t scene_1_sprites[] = {
  TO_FAR_PTR_T(spritesheet_4),
  TO_FAR_PTR_T(spritesheet_5),
  TO_FAR_PTR_T(spritesheet_6),
  TO_FAR_PTR_T(spritesheet_7)
};
