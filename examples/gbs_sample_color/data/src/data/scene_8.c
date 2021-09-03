#pragma bank 255

// Scene: Player's House

#include "gbs_types.h"
#include "data/background_10.h"
#include "data/scene_8_collisions.h"
#include "data/palette_4.h"
#include "data/palette_8.h"
#include "data/spritesheet_7.h"
#include "data/scene_8_triggers.h"
#include "data/script_s8_init.h"

BANKREF(scene_8)

const struct scene_t scene_8 = {
    .width = 20,
    .height = 18,
    .type = SCENE_TYPE_POINTNCLICK,
    .background = TO_FAR_PTR_T(background_10),
    .collisions = TO_FAR_PTR_T(scene_8_collisions),
    .parallax_rows = {
        PARALLAX_STEP(0,0,0)
    },
    .palette = TO_FAR_PTR_T(palette_4),
    .sprite_palette = TO_FAR_PTR_T(palette_8),
    .player_sprite = TO_FAR_PTR_T(spritesheet_7),
    .n_actors = 0,
    .n_triggers = 11,
    .n_sprites = 0,
    .triggers = TO_FAR_PTR_T(scene_8_triggers),
    .script_init = TO_FAR_PTR_T(script_s8_init)
};
