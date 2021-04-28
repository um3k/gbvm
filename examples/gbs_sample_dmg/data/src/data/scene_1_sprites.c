#pragma bank 255

// Scene: Cave
// Sprites

#include "gbs_types.h"
#include "data/spritesheet_7.h"
#include "data/spritesheet_8.h"
#include "data/spritesheet_9.h"
#include "data/spritesheet_10.h"
#include "data/spritesheet_11.h"

const void __at(255) __bank_scene_1_sprites;

const far_ptr_t scene_1_sprites[] = {
    TO_FAR_PTR_T(spritesheet_7),
    TO_FAR_PTR_T(spritesheet_8),
    TO_FAR_PTR_T(spritesheet_9),
    TO_FAR_PTR_T(spritesheet_10),
    TO_FAR_PTR_T(spritesheet_11)
};
