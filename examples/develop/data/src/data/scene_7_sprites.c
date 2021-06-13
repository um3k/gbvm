#pragma bank 255

// Scene: Outside
// Sprites

#include "gbs_types.h"
#include "data/spritesheet_14.h"

const void __at(255) __bank_scene_7_sprites;

const far_ptr_t scene_7_sprites[] = {
    TO_FAR_PTR_T(spritesheet_14)
};
