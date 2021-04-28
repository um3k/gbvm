#pragma bank 255

// Scene: Underground
// Sprites

#include "gbs_types.h"
#include "data/spritesheet_2.h"
#include "data/spritesheet_15.h"
#include "data/spritesheet_1.h"

const void __at(255) __bank_scene_6_sprites;

const far_ptr_t scene_6_sprites[] = {
    TO_FAR_PTR_T(spritesheet_2),
    TO_FAR_PTR_T(spritesheet_15),
    TO_FAR_PTR_T(spritesheet_1)
};
