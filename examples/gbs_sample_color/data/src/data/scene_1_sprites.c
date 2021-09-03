#pragma bank 255

// Scene: Cave
// Sprites

#include "gbs_types.h"
#include "data/spritesheet_16.h"
#include "data/spritesheet_4.h"
#include "data/spritesheet_17.h"
#include "data/spritesheet_18.h"

BANKREF(scene_1_sprites)

const far_ptr_t scene_1_sprites[] = {
    TO_FAR_PTR_T(spritesheet_16),
    TO_FAR_PTR_T(spritesheet_4),
    TO_FAR_PTR_T(spritesheet_17),
    TO_FAR_PTR_T(spritesheet_18)
};
