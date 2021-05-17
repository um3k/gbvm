#pragma bank 255

// Scene: Scene 2

#include "gbs_types.h"
#include "data/background_1.h"
#include "data/scene_1_collisions.h"
#include "data/palette_1.h"
#include "data/palette_3.h"
#include "data/spritesheet_1.h"
#include "data/scene_1_actors.h"
#include "data/scene_1_sprites.h"
#include "data/script_s1_init.h"

const void __at(255) __bank_scene_1;

const struct scene_t scene_1 = {
    .width = 61,
    .height = 18,
    .type = SCENE_TYPE_PLATFORM,
    .background = TO_FAR_PTR_T(background_1),
    .collisions = TO_FAR_PTR_T(scene_1_collisions),
    .parallax_rows = {
        PARALLAX_STEP(0, 2, 2), PARALLAX_STEP(2, 6, 1), PARALLAX_STEP(6, 0, 0)
    },
    .palette = TO_FAR_PTR_T(palette_1),
    .sprite_palette = TO_FAR_PTR_T(palette_3),
    .player_sprite = TO_FAR_PTR_T(spritesheet_1),
    .n_actors = 4,
    .n_triggers = 0,
    .n_sprites = 3,
    .actors = TO_FAR_PTR_T(scene_1_actors),
    .sprites = TO_FAR_PTR_T(scene_1_sprites),
    .script_init = TO_FAR_PTR_T(script_s1_init)
};
