#pragma bank 255

// Scene: Launch Site
// Sprites

#include "gbs_types.h"
#include "data/spritesheet_31.h"
#include "data/spritesheet_32.h"
#include "data/spritesheet_33.h"

const void __at(255) __bank_scene_12_sprites;

const far_ptr_t scene_12_sprites[] = {
    TO_FAR_PTR_T(spritesheet_31),
    TO_FAR_PTR_T(spritesheet_32),
    TO_FAR_PTR_T(spritesheet_33)
};
