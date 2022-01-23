#pragma bank 255

// Scene: Stars

#include "gbs_types.h"
#include "data/background_5.h"
#include "data/scene_3_collisions.h"
#include "data/palette_0.h"
#include "data/palette_1.h"
#include "data/spritesheet_0.h"
#include "data/scene_3_actors.h"
#include "data/scene_3_triggers.h"
#include "data/scene_3_sprites.h"
#include "data/script_s3_init.h"

BANKREF(scene_3)

const struct scene_t scene_3 = {
    .width = 32,
    .height = 32,
    .type = SCENE_TYPE_TOPDOWN,
    .background = TO_FAR_PTR_T(background_5),
    .collisions = TO_FAR_PTR_T(scene_3_collisions),
    .parallax_rows = {
        PARALLAX_STEP(0,0,0)
    },
    .palette = TO_FAR_PTR_T(palette_0),
    .sprite_palette = TO_FAR_PTR_T(palette_1),
    .reserve_tiles = 0,
    .player_sprite = TO_FAR_PTR_T(spritesheet_0),
    .n_actors = 2,
    .n_triggers = 1,
    .n_sprites = 2,
    .n_projectiles = 0,
    .actors = TO_FAR_PTR_T(scene_3_actors),
    .triggers = TO_FAR_PTR_T(scene_3_triggers),
    .sprites = TO_FAR_PTR_T(scene_3_sprites),
    .script_init = TO_FAR_PTR_T(script_s3_init)
};
