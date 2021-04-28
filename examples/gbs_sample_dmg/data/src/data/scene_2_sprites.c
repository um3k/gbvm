#pragma bank 255

// Scene: House
// Sprites

#include "gbs_types.h"
#include "data/spritesheet_12.h"
#include "data/spritesheet_13.h"
#include "data/spritesheet_2.h"

const void __at(255) __bank_scene_2_sprites;

const far_ptr_t scene_2_sprites[] = {
    TO_FAR_PTR_T(spritesheet_12),
    TO_FAR_PTR_T(spritesheet_13),
    TO_FAR_PTR_T(spritesheet_2)
};
