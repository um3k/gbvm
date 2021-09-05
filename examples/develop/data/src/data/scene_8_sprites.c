#pragma bank 255

// Scene: Parallax
// Sprites

#include "gbs_types.h"
#include "data/spritesheet_15.h"

BANKREF(scene_8_sprites)

const far_ptr_t scene_8_sprites[] = {
    TO_FAR_PTR_T(spritesheet_15)
};
