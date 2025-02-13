#pragma bank 255

// Scene: Menu Page 2

#include "gbs_types.h"
#include "data/background_8.h"
#include "data/scene_9_collisions.h"
#include "data/palette_2.h"
#include "data/palette_8.h"
#include "data/spritesheet_7.h"
#include "data/scene_9_actors.h"
#include "data/scene_9_sprites.h"
#include "data/script_s9_init.h"

BANKREF(scene_9)

const struct scene_t scene_9 = {
    .width = 20,
    .height = 18,
    .type = SCENE_TYPE_TOPDOWN,
    .background = TO_FAR_PTR_T(background_8),
    .collisions = TO_FAR_PTR_T(scene_9_collisions),
    .parallax_rows = {
        PARALLAX_STEP(0,0,0)
    },
    .palette = TO_FAR_PTR_T(palette_2),
    .sprite_palette = TO_FAR_PTR_T(palette_8),
    .reserve_tiles = 0,
    .player_sprite = TO_FAR_PTR_T(spritesheet_7),
    .n_actors = 5,
    .n_triggers = 0,
    .n_sprites = 1,
    .n_projectiles = 0,
    .actors = TO_FAR_PTR_T(scene_9_actors),
    .sprites = TO_FAR_PTR_T(scene_9_sprites),
    .script_init = TO_FAR_PTR_T(script_s9_init)
};
