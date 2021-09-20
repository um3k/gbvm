#pragma bank 255

// Scene: Dancefloor
// Sprites

#include "gbs_types.h"
#include "data/spritesheet_16.h"
#include "data/spritesheet_14.h"

BANKREF(scene_9_sprites)

const far_ptr_t scene_9_sprites[] = {
    TO_FAR_PTR_T(spritesheet_16),
    TO_FAR_PTR_T(spritesheet_14)
};
