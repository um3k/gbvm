#pragma bank 255

// Scene: Menu Page 1

#include "gbs_types.h"
#include "data/background_7.h"
#include "data/scene_6_collisions.h"
#include "data/palette_2.h"
#include "data/palette_8.h"
#include "data/spritesheet_7.h"
#include "data/scene_6_actors.h"
#include "data/scene_6_sprites.h"
#include "data/script_s6_init.h"

BANKREF(scene_6)

const struct scene_t scene_6 = {
    .width = 20,
    .height = 18,
    .type = SCENE_TYPE_TOPDOWN,
    .background = TO_FAR_PTR_T(background_7),
    .collisions = TO_FAR_PTR_T(scene_6_collisions),
    .parallax_rows = {
        PARALLAX_STEP(0,0,0)
    },
    .palette = TO_FAR_PTR_T(palette_2),
    .sprite_palette = TO_FAR_PTR_T(palette_8),
    .player_sprite = TO_FAR_PTR_T(spritesheet_7),
    .n_actors = 6,
    .n_triggers = 0,
    .n_sprites = 1,
    .actors = TO_FAR_PTR_T(scene_6_actors),
    .sprites = TO_FAR_PTR_T(scene_6_sprites),
    .script_init = TO_FAR_PTR_T(script_s6_init)
};
