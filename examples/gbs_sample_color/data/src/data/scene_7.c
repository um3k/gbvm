#pragma bank 255

// Scene: Space Battle

#include "gbs_types.h"
#include "data/background_5.h"
#include "data/scene_7_collisions.h"
#include "data/palette_3.h"
#include "data/palette_8.h"
#include "data/spritesheet_7.h"
#include "data/scene_7_actors.h"
#include "data/scene_7_triggers.h"
#include "data/scene_7_sprites.h"
#include "data/script_s7_init.h"
#include "data/script_s7_p_hit1.h"

BANKREF(scene_7)

const struct scene_t scene_7 = {
    .width = 255,
    .height = 18,
    .type = SCENE_TYPE_SHMUP,
    .background = TO_FAR_PTR_T(background_5),
    .collisions = TO_FAR_PTR_T(scene_7_collisions),
    .parallax_rows = {
        PARALLAX_STEP(0,0,0)
    },
    .palette = TO_FAR_PTR_T(palette_3),
    .sprite_palette = TO_FAR_PTR_T(palette_8),
    .player_sprite = TO_FAR_PTR_T(spritesheet_7),
    .n_actors = 16,
    .n_triggers = 1,
    .n_sprites = 7,
    .actors = TO_FAR_PTR_T(scene_7_actors),
    .triggers = TO_FAR_PTR_T(scene_7_triggers),
    .sprites = TO_FAR_PTR_T(scene_7_sprites),
    .script_init = TO_FAR_PTR_T(script_s7_init),
    .script_p_hit1 = TO_FAR_PTR_T(script_s7_p_hit1)
};
