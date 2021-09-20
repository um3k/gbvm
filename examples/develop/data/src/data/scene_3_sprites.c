#pragma bank 255

// Scene: Underground
// Sprites

#include "gbs_types.h"
#include "data/spritesheet_7.h"
#include "data/spritesheet_8.h"
#include "data/spritesheet_9.h"
#include "data/spritesheet_10.h"

BANKREF(scene_3_sprites)

const far_ptr_t scene_3_sprites[] = {
    TO_FAR_PTR_T(spritesheet_7),
    TO_FAR_PTR_T(spritesheet_8),
    TO_FAR_PTR_T(spritesheet_9),
    TO_FAR_PTR_T(spritesheet_10)
};
