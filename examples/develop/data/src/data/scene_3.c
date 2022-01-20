#pragma bank 255

// Scene: Underground

#include "gbs_types.h"
#include "data/background_10.h"
#include "data/scene_3_collisions.h"
#include "data/palette_0.h"
#include "data/palette_6.h"
#include "data/spritesheet_2.h"
#include "data/scene_3_actors.h"
#include "data/scene_3_triggers.h"
#include "data/scene_3_sprites.h"
#include "data/script_s3_init.h"

BANKREF(scene_3)

const struct scene_t scene_3 = {
    .width = 32,
    .height = 32,
    .type = SCENE_TYPE_TOPDOWN,
    .background = TO_FAR_PTR_T(background_10),
    .collisions = TO_FAR_PTR_T(scene_3_collisions),
    .parallax_rows = {
        PARALLAX_STEP(0,0,0)
    },
    .palette = TO_FAR_PTR_T(palette_0),
    .sprite_palette = TO_FAR_PTR_T(palette_6),
    .reserve_tiles = 0,
    .player_sprite = TO_FAR_PTR_T(spritesheet_2),
    .n_actors = 6,
    .n_triggers = 2,
    .n_sprites = 4,
    .n_projectiles = 0,
    .actors = TO_FAR_PTR_T(scene_3_actors),
    .triggers = TO_FAR_PTR_T(scene_3_triggers),
    .sprites = TO_FAR_PTR_T(scene_3_sprites),
    .script_init = TO_FAR_PTR_T(script_s3_init)
};
