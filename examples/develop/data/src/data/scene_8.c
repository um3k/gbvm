#pragma bank 255

// Scene: Parallax

#include "gbs_types.h"
#include "data/background_6.h"
#include "data/scene_8_collisions.h"
#include "data/palette_4.h"
#include "data/palette_6.h"
#include "data/spritesheet_12.h"
#include "data/scene_8_actors.h"
#include "data/scene_8_triggers.h"
#include "data/scene_8_sprites.h"

BANKREF(scene_8)

const struct scene_t scene_8 = {
    .width = 80,
    .height = 18,
    .type = SCENE_TYPE_PLATFORM,
    .background = TO_FAR_PTR_T(background_6),
    .collisions = TO_FAR_PTR_T(scene_8_collisions),
    .parallax_rows = {
        PARALLAX_STEP(0, 10, 6), PARALLAX_STEP(10, 14, 3), PARALLAX_STEP(14, 0, 0)
    },
    .palette = TO_FAR_PTR_T(palette_4),
    .sprite_palette = TO_FAR_PTR_T(palette_6),
    .player_sprite = TO_FAR_PTR_T(spritesheet_12),
    .n_actors = 1,
    .n_triggers = 2,
    .n_sprites = 1,
    .n_projectiles = 0,
    .actors = TO_FAR_PTR_T(scene_8_actors),
    .triggers = TO_FAR_PTR_T(scene_8_triggers),
    .sprites = TO_FAR_PTR_T(scene_8_sprites)
};
