#pragma bank 255

// Scene: Deep Space
// Sprites

#include "gbs_types.h"
#include "data/spritesheet_29.h"
#include "data/spritesheet_30.h"
#include "data/spritesheet_18.h"

BANKREF(scene_11_sprites)

const far_ptr_t scene_11_sprites[] = {
    TO_FAR_PTR_T(spritesheet_29),
    TO_FAR_PTR_T(spritesheet_30),
    TO_FAR_PTR_T(spritesheet_18)
};
