#pragma bank 255

// Scene: Title Screen

#include "gbs_types.h"
#include "data/background_6.h"
#include "data/scene_5_collisions.h"
#include "data/palette_0.h"
#include "data/palette_1.h"
#include "data/spritesheet_0.h"
#include "data/script_s5_init.h"

const void __at(255) __bank_scene_5;

const struct scene_t scene_5 = {
    .width = 20,
    .height = 18,
    .type = SCENE_TYPE_TOPDOWN,
    .background = TO_FAR_PTR_T(background_6),
    .collisions = TO_FAR_PTR_T(scene_5_collisions),
    .palette = TO_FAR_PTR_T(palette_0),
    .sprite_palette = TO_FAR_PTR_T(palette_1),
    .player_sprite = TO_FAR_PTR_T(spritesheet_0),
    .n_actors = 0,
    .n_triggers = 0,
    .n_sprites = 0,
    .script_init = TO_FAR_PTR_T(script_s5_init)
};
