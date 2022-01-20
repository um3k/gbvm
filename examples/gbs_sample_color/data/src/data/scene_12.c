#pragma bank 255

// Scene: Launch Site

#include "gbs_types.h"
#include "data/background_4.h"
#include "data/scene_12_collisions.h"
#include "data/palette_7.h"
#include "data/palette_8.h"
#include "data/spritesheet_7.h"
#include "data/scene_12_actors.h"
#include "data/scene_12_triggers.h"
#include "data/scene_12_sprites.h"
#include "data/script_s12_init.h"

BANKREF(scene_12)

const struct scene_t scene_12 = {
    .width = 20,
    .height = 18,
    .type = SCENE_TYPE_TOPDOWN,
    .background = TO_FAR_PTR_T(background_4),
    .collisions = TO_FAR_PTR_T(scene_12_collisions),
    .parallax_rows = {
        PARALLAX_STEP(0,0,0)
    },
    .palette = TO_FAR_PTR_T(palette_7),
    .sprite_palette = TO_FAR_PTR_T(palette_8),
    .reserve_tiles = 0,
    .player_sprite = TO_FAR_PTR_T(spritesheet_7),
    .n_actors = 6,
    .n_triggers = 2,
    .n_sprites = 3,
    .n_projectiles = 0,
    .actors = TO_FAR_PTR_T(scene_12_actors),
    .triggers = TO_FAR_PTR_T(scene_12_triggers),
    .sprites = TO_FAR_PTR_T(scene_12_sprites),
    .script_init = TO_FAR_PTR_T(script_s12_init)
};
