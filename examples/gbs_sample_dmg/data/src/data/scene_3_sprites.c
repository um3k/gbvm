#pragma bank 255

// Scene: Stars
// Sprites

#include "gbs_types.h"
#include "data/spritesheet_14.h"
#include "data/spritesheet_11.h"

BANKREF(scene_3_sprites)

const far_ptr_t scene_3_sprites[] = {
    TO_FAR_PTR_T(spritesheet_14),
    TO_FAR_PTR_T(spritesheet_11)
};
