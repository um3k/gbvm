#pragma bank 255

// Scene: Scene 1
// Sprites

#include "gbs_types.h"
#include "data/spritesheet_0.h"

BANKREF(scene_0_sprites)

const far_ptr_t scene_0_sprites[] = {
    TO_FAR_PTR_T(spritesheet_0)
};
