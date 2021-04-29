#pragma bank 255

// Scene: Space Battle
// Sprites

#include "gbs_types.h"
#include "data/spritesheet_24.h"
#include "data/spritesheet_25.h"
#include "data/spritesheet_26.h"
#include "data/spritesheet_0.h"
#include "data/spritesheet_2.h"
#include "data/spritesheet_3.h"
#include "data/spritesheet_4.h"

const void __at(255) __bank_scene_7_sprites;

const far_ptr_t scene_7_sprites[] = {
    TO_FAR_PTR_T(spritesheet_24),
    TO_FAR_PTR_T(spritesheet_25),
    TO_FAR_PTR_T(spritesheet_26),
    TO_FAR_PTR_T(spritesheet_0),
    TO_FAR_PTR_T(spritesheet_2),
    TO_FAR_PTR_T(spritesheet_3),
    TO_FAR_PTR_T(spritesheet_4)
};
