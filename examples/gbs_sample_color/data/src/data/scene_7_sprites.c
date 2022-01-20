#pragma bank 255

// Scene: Space Battle
// Sprites

#include "gbs_types.h"
#include "data/spritesheet_24.h"
#include "data/spritesheet_0.h"
#include "data/spritesheet_2.h"

BANKREF(scene_7_sprites)

const far_ptr_t scene_7_sprites[] = {
    TO_FAR_PTR_T(spritesheet_24),
    TO_FAR_PTR_T(spritesheet_0),
    TO_FAR_PTR_T(spritesheet_2)
};
