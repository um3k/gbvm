#pragma bank 255

// Scene: Digits

#include "gbs_types.h"
#include "data/background_2.h"
#include "data/scene_10_collisions.h"
#include "data/palette_0.h"
#include "data/palette_6.h"
#include "data/spritesheet_2.h"

BANKREF(scene_10)

const struct scene_t scene_10 = {
    .width = 20,
    .height = 18,
    .type = SCENE_TYPE_TOPDOWN,
    .background = TO_FAR_PTR_T(background_2),
    .collisions = TO_FAR_PTR_T(scene_10_collisions),
    .parallax_rows = {
        PARALLAX_STEP(0,0,0)
    },
    .palette = TO_FAR_PTR_T(palette_0),
    .sprite_palette = TO_FAR_PTR_T(palette_6),
    .player_sprite = TO_FAR_PTR_T(spritesheet_2),
    .n_actors = 0,
    .n_triggers = 0,
    .n_sprites = 0,
    .n_projectiles = 0
};
