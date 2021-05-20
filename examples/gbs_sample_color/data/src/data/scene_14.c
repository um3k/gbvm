#pragma bank 255

// Scene: Dream

#include "gbs_types.h"
#include "data/background_0.h"
#include "data/scene_14_collisions.h"
#include "data/palette_1.h"
#include "data/palette_8.h"
#include "data/spritesheet_7.h"
#include "data/script_s14_init.h"

const void __at(255) __bank_scene_14;

const struct scene_t scene_14 = {
    .width = 20,
    .height = 18,
    .type = SCENE_TYPE_TOPDOWN,
    .background = TO_FAR_PTR_T(background_0),
    .collisions = TO_FAR_PTR_T(scene_14_collisions),
    .parallax_rows = {
        PARALLAX_STEP(0,0,0)
    },
    .palette = TO_FAR_PTR_T(palette_1),
    .sprite_palette = TO_FAR_PTR_T(palette_8),
    .player_sprite = TO_FAR_PTR_T(spritesheet_7),
    .n_actors = 0,
    .n_triggers = 0,
    .n_sprites = 0,
    .script_init = TO_FAR_PTR_T(script_s14_init)
};
