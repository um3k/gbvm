#pragma bank 255

// Scene: Outside
// Sprites

#include "gbs_types.h"
#include "data/spritesheet_15.h"
#include "data/spritesheet_3.h"
#include "data/spritesheet_1.h"

BANKREF(scene_7_sprites)

const far_ptr_t scene_7_sprites[] = {
    TO_FAR_PTR_T(spritesheet_15),
    TO_FAR_PTR_T(spritesheet_3),
    TO_FAR_PTR_T(spritesheet_1)
};
