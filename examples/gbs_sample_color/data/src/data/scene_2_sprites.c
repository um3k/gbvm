#pragma bank 255

// Scene: Top House
// Sprites

#include "gbs_types.h"
#include "data/spritesheet_19.h"
#include "data/spritesheet_20.h"
#include "data/spritesheet_13.h"

BANKREF(scene_2_sprites)

const far_ptr_t scene_2_sprites[] = {
    TO_FAR_PTR_T(spritesheet_19),
    TO_FAR_PTR_T(spritesheet_20),
    TO_FAR_PTR_T(spritesheet_13)
};
