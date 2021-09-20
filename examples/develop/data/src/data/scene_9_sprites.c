#pragma bank 255

// Scene: Dancefloor
// Sprites

#include "gbs_types.h"
#include "data/spritesheet_17.h"
#include "data/spritesheet_15.h"

BANKREF(scene_9_sprites)

const far_ptr_t scene_9_sprites[] = {
    TO_FAR_PTR_T(spritesheet_17),
    TO_FAR_PTR_T(spritesheet_15)
};
