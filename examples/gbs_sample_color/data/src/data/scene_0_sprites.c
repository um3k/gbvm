#pragma bank 255

// Scene: Sample Town
// Sprites

#include "gbs_types.h"
#include "data/spritesheet_8.h"
#include "data/spritesheet_9.h"
#include "data/spritesheet_10.h"
#include "data/spritesheet_11.h"
#include "data/spritesheet_12.h"
#include "data/spritesheet_13.h"
#include "data/spritesheet_14.h"
#include "data/spritesheet_15.h"

const void __at(255) __bank_scene_0_sprites;

const far_ptr_t scene_0_sprites[] = {
    TO_FAR_PTR_T(spritesheet_8),
    TO_FAR_PTR_T(spritesheet_9),
    TO_FAR_PTR_T(spritesheet_10),
    TO_FAR_PTR_T(spritesheet_11),
    TO_FAR_PTR_T(spritesheet_12),
    TO_FAR_PTR_T(spritesheet_13),
    TO_FAR_PTR_T(spritesheet_14),
    TO_FAR_PTR_T(spritesheet_15)
};
