#pragma bank 255

// Scene: Deeper Underground

#include "gbs_types.h"
#include "data/background_3.h"
#include "data/scene_6_collisions.h"
#include "data/palette_0.h"
#include "data/palette_6.h"
#include "data/spritesheet_11.h"
#include "data/scene_6_actors.h"
#include "data/scene_6_triggers.h"
#include "data/scene_6_sprites.h"
#include "data/script_s6_init.h"

BANKREF(scene_6)

const struct scene_t scene_6 = {
    .width = 32,
    .height = 18,
    .type = SCENE_TYPE_PLATFORM,
    .background = TO_FAR_PTR_T(background_3),
    .collisions = TO_FAR_PTR_T(scene_6_collisions),
    .parallax_rows = {
        PARALLAX_STEP(0,0,0)
    },
    .palette = TO_FAR_PTR_T(palette_0),
    .sprite_palette = TO_FAR_PTR_T(palette_6),
    .player_sprite = TO_FAR_PTR_T(spritesheet_11),
    .n_actors = 1,
    .n_triggers = 1,
    .n_sprites = 1,
    .actors = TO_FAR_PTR_T(scene_6_actors),
    .triggers = TO_FAR_PTR_T(scene_6_triggers),
    .sprites = TO_FAR_PTR_T(scene_6_sprites),
    .script_init = TO_FAR_PTR_T(script_s6_init)
};
