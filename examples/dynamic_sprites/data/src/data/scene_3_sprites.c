#pragma bank 255

// Scene: Large Player Sprite
// Sprites

#include "gbs_types.h"
#include "data/spritesheet_7.h"
#include "data/spritesheet_4.h"
#include "data/spritesheet_5.h"

const void __at(255) __bank_scene_3_sprites;

const far_ptr_t scene_3_sprites[] = {
    TO_FAR_PTR_T(spritesheet_7),
    TO_FAR_PTR_T(spritesheet_4),
    TO_FAR_PTR_T(spritesheet_5)
};
