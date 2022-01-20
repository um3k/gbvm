#pragma bank 255

// Scene: Path to Sample Town
// Sprites

#include "gbs_types.h"
#include "data/spritesheet_13.h"
#include "data/spritesheet_28.h"
#include "data/spritesheet_18.h"

BANKREF(scene_10_sprites)

const far_ptr_t scene_10_sprites[] = {
    TO_FAR_PTR_T(spritesheet_13),
    TO_FAR_PTR_T(spritesheet_28),
    TO_FAR_PTR_T(spritesheet_18)
};
