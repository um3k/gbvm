#pragma bank 255

// Scene: Alt Player Sprite
// Sprites

#include "gbs_types.h"
#include "data/spritesheet_4.h"
#include "data/spritesheet_5.h"

const void __at(255) __bank_scene_1_sprites;

const far_ptr_t scene_1_sprites[] = {
    TO_FAR_PTR_T(spritesheet_4),
    TO_FAR_PTR_T(spritesheet_5)
};
