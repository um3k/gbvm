#pragma bank 255

// Scene: Player's House

#include "gbs_types.h"
#include "data/background_8.h"
#include "data/scene_4_collisions.h"
#include "data/palette_1.h"
#include "data/palette_6.h"
#include "data/spritesheet_10.h"
#include "data/scene_4_triggers.h"
#include "data/script_s4_init.h"

BANKREF(scene_4)

const struct scene_t scene_4 = {
    .width = 20,
    .height = 18,
    .type = SCENE_TYPE_POINTNCLICK,
    .background = TO_FAR_PTR_T(background_8),
    .collisions = TO_FAR_PTR_T(scene_4_collisions),
    .parallax_rows = {
        PARALLAX_STEP(0,0,0)
    },
    .palette = TO_FAR_PTR_T(palette_1),
    .sprite_palette = TO_FAR_PTR_T(palette_6),
    .player_sprite = TO_FAR_PTR_T(spritesheet_10),
    .n_actors = 0,
    .n_triggers = 11,
    .n_sprites = 0,
    .triggers = TO_FAR_PTR_T(scene_4_triggers),
    .script_init = TO_FAR_PTR_T(script_s4_init)
};
