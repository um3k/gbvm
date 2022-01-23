#pragma bank 255

// Scene: Menu

#include "gbs_types.h"
#include "data/background_3.h"
#include "data/scene_7_collisions.h"
#include "data/palette_0.h"
#include "data/palette_1.h"
#include "data/spritesheet_0.h"
#include "data/scene_7_actors.h"
#include "data/scene_7_sprites.h"
#include "data/script_s7_init.h"

BANKREF(scene_7)

const struct scene_t scene_7 = {
    .width = 20,
    .height = 18,
    .type = SCENE_TYPE_TOPDOWN,
    .background = TO_FAR_PTR_T(background_3),
    .collisions = TO_FAR_PTR_T(scene_7_collisions),
    .parallax_rows = {
        PARALLAX_STEP(0,0,0)
    },
    .palette = TO_FAR_PTR_T(palette_0),
    .sprite_palette = TO_FAR_PTR_T(palette_1),
    .reserve_tiles = 0,
    .player_sprite = TO_FAR_PTR_T(spritesheet_0),
    .n_actors = 6,
    .n_triggers = 0,
    .n_sprites = 1,
    .n_projectiles = 0,
    .actors = TO_FAR_PTR_T(scene_7_actors),
    .sprites = TO_FAR_PTR_T(scene_7_sprites),
    .script_init = TO_FAR_PTR_T(script_s7_init)
};
