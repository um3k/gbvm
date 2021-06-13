#pragma bank 255

// Scene: Platform
// Sprites

#include "gbs_types.h"
#include "data/spritesheet_12.h"
#include "data/spritesheet_6.h"
#include "data/spritesheet_5.h"
#include "data/spritesheet_0.h"

const void __at(255) __bank_scene_5_sprites;

const far_ptr_t scene_5_sprites[] = {
    TO_FAR_PTR_T(spritesheet_12),
    TO_FAR_PTR_T(spritesheet_6),
    TO_FAR_PTR_T(spritesheet_5),
    TO_FAR_PTR_T(spritesheet_0)
};
