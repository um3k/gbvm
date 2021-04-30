#pragma bank 255

// Scene: Path to Sample Town
// Sprites

#include "gbs_types.h"
#include "data/spritesheet_13.h"
#include "data/spritesheet_27.h"
#include "data/spritesheet_28.h"
#include "data/spritesheet_18.h"
#include "data/spritesheet_6.h"

const void __at(255) __bank_scene_10_sprites;

const far_ptr_t scene_10_sprites[] = {
    TO_FAR_PTR_T(spritesheet_13),
    TO_FAR_PTR_T(spritesheet_27),
    TO_FAR_PTR_T(spritesheet_28),
    TO_FAR_PTR_T(spritesheet_18),
    TO_FAR_PTR_T(spritesheet_6)
};
