#pragma bank 255

// Scene: Large Player Sprite

#include "gbs_types.h"
#include "data/background_0.h"
#include "data/scene_3_collisions.h"
#include "data/palette_0.h"
#include "data/palette_1.h"
#include "data/spritesheet_7.h"
#include "data/scene_3_actors.h"
#include "data/scene_3_sprites.h"

BANKREF(scene_3)

const struct scene_t scene_3 = {
    .width = 20,
    .height = 18,
    .type = SCENE_TYPE_TOPDOWN,
    .background = TO_FAR_PTR_T(background_0),
    .collisions = TO_FAR_PTR_T(scene_3_collisions),
    .parallax_rows = {
        PARALLAX_STEP(0,0,0)
    },
    .palette = TO_FAR_PTR_T(palette_0),
    .sprite_palette = TO_FAR_PTR_T(palette_1),
    .player_sprite = TO_FAR_PTR_T(spritesheet_7),
    .n_actors = 2,
    .n_triggers = 0,
    .n_sprites = 2,
    .actors = TO_FAR_PTR_T(scene_3_actors),
    .sprites = TO_FAR_PTR_T(scene_3_sprites)
};
