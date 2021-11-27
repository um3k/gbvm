#pragma bank 255

// Scene: Platform
// Sprites

#include "gbs_types.h"
#include "data/spritesheet_7.h"
#include "data/spritesheet_6.h"

BANKREF(scene_5_sprites)

const far_ptr_t scene_5_sprites[] = {
    TO_FAR_PTR_T(spritesheet_7),
    TO_FAR_PTR_T(spritesheet_6)
};
