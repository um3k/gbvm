#pragma bank 255

// Scene: Sample Town

#include "gbs_types.h"
#include "data/background_11.h"
#include "data/scene_0_collisions.h"
#include "data/palette_0.h"
#include "data/palette_8.h"
#include "data/spritesheet_7.h"
#include "data/scene_0_actors.h"
#include "data/scene_0_triggers.h"
#include "data/scene_0_sprites.h"
#include "data/script_s0_init.h"

BANKREF(scene_0)

const struct scene_t scene_0 = {
    .width = 56,
    .height = 56,
    .type = SCENE_TYPE_TOPDOWN,
    .background = TO_FAR_PTR_T(background_11),
    .collisions = TO_FAR_PTR_T(scene_0_collisions),
    .parallax_rows = {
        PARALLAX_STEP(0,0,0)
    },
    .palette = TO_FAR_PTR_T(palette_0),
    .sprite_palette = TO_FAR_PTR_T(palette_8),
    .reserve_tiles = 0,
    .player_sprite = TO_FAR_PTR_T(spritesheet_7),
    .n_actors = 9,
    .n_triggers = 14,
    .n_sprites = 8,
    .n_projectiles = 0,
    .actors = TO_FAR_PTR_T(scene_0_actors),
    .triggers = TO_FAR_PTR_T(scene_0_triggers),
    .sprites = TO_FAR_PTR_T(scene_0_sprites),
    .script_init = TO_FAR_PTR_T(script_s0_init)
};
