#pragma bank 255

// Scene: Underground
// Sprites

#include "gbs_types.h"
#include "data/spritesheet_13.h"
#include "data/spritesheet_21.h"
#include "data/spritesheet_8.h"
#include "data/spritesheet_22.h"

const void __at(255) __bank_scene_5_sprites;

const far_ptr_t scene_5_sprites[] = {
    TO_FAR_PTR_T(spritesheet_13),
    TO_FAR_PTR_T(spritesheet_21),
    TO_FAR_PTR_T(spritesheet_8),
    TO_FAR_PTR_T(spritesheet_22)
};
