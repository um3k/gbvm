#pragma bank 255

// Scene: Parallax Test
// Sprites

#include "gbs_types.h"
#include "data/spritesheet_9.h"

const void __at(255) __bank_scene_5_sprites;

const far_ptr_t scene_5_sprites[] = {
  TO_FAR_PTR_T(spritesheet_9)
};
