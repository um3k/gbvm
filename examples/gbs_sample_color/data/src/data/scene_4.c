#pragma bank 255

// Scene: Title Screen

#include "gbs_types.h"
#include "data/background_13.h"
#include "data/scene_4_collisions.h"
#include "data/palette_1.h"
#include "data/palette_8.h"
#include "data/spritesheet_7.h"
#include "data/script_s4_init.h"

BANKREF(scene_4)

const struct scene_t scene_4 = {
    .width = 20,
    .height = 18,
    .type = SCENE_TYPE_TOPDOWN,
    .background = TO_FAR_PTR_T(background_13),
    .collisions = TO_FAR_PTR_T(scene_4_collisions),
    .parallax_rows = {
        PARALLAX_STEP(0,0,0)
    },
    .palette = TO_FAR_PTR_T(palette_1),
    .sprite_palette = TO_FAR_PTR_T(palette_8),
    .reserve_tiles = 0,
    .player_sprite = TO_FAR_PTR_T(spritesheet_7),
    .n_actors = 0,
    .n_triggers = 0,
    .n_sprites = 0,
    .n_projectiles = 0,
    .script_init = TO_FAR_PTR_T(script_s4_init)
};
