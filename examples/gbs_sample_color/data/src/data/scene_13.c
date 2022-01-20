#pragma bank 255

// Scene: Deeper Underground

#include "gbs_types.h"
#include "data/background_2.h"
#include "data/scene_13_collisions.h"
#include "data/palette_1.h"
#include "data/palette_8.h"
#include "data/spritesheet_7.h"
#include "data/scene_13_actors.h"
#include "data/scene_13_triggers.h"
#include "data/scene_13_sprites.h"
#include "data/script_s13_init.h"

BANKREF(scene_13)

const struct scene_t scene_13 = {
    .width = 32,
    .height = 18,
    .type = SCENE_TYPE_PLATFORM,
    .background = TO_FAR_PTR_T(background_2),
    .collisions = TO_FAR_PTR_T(scene_13_collisions),
    .parallax_rows = {
        PARALLAX_STEP(0,0,0)
    },
    .palette = TO_FAR_PTR_T(palette_1),
    .sprite_palette = TO_FAR_PTR_T(palette_8),
    .reserve_tiles = 0,
    .player_sprite = TO_FAR_PTR_T(spritesheet_7),
    .n_actors = 1,
    .n_triggers = 1,
    .n_sprites = 1,
    .n_projectiles = 0,
    .actors = TO_FAR_PTR_T(scene_13_actors),
    .triggers = TO_FAR_PTR_T(scene_13_triggers),
    .sprites = TO_FAR_PTR_T(scene_13_sprites),
    .script_init = TO_FAR_PTR_T(script_s13_init)
};
