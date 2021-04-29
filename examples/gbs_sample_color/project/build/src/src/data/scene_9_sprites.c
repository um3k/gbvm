#pragma bank 255

// Scene: Menu Page 2
// Sprites

#include "gbs_types.h"
#include "data/spritesheet_23.h"

const void __at(255) __bank_scene_9_sprites;

const far_ptr_t scene_9_sprites[] = {
    TO_FAR_PTR_T(spritesheet_23)
};
