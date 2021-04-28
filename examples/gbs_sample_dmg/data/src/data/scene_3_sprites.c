#pragma bank 255

// Scene: Stars
// Sprites

#include "gbs_types.h"
#include "data/spritesheet_13.h"

const void __at(255) __bank_scene_3_sprites;

const far_ptr_t scene_3_sprites[] = {
    TO_FAR_PTR_T(spritesheet_13)
};
