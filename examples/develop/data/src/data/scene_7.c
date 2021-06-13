#pragma bank 255

// Scene: Outside

#include "gbs_types.h"
#include "data/background_5.h"
#include "data/scene_7_collisions.h"
#include "data/palette_3.h"
#include "data/palette_6.h"
#include "data/spritesheet_1.h"
#include "data/scene_7_actors.h"
#include "data/scene_7_triggers.h"
#include "data/scene_7_sprites.h"
#include "data/script_s7_init.h"

const void __at(255) __bank_scene_7;

const struct scene_t scene_7 = {
    .width = 32,
    .height = 32,
    .type = SCENE_TYPE_ADVENTURE,
    .background = TO_FAR_PTR_T(background_5),
    .collisions = TO_FAR_PTR_T(scene_7_collisions),
    .parallax_rows = {
        PARALLAX_STEP(0,0,0)
    },
    .palette = TO_FAR_PTR_T(palette_3),
    .sprite_palette = TO_FAR_PTR_T(palette_6),
    .player_sprite = TO_FAR_PTR_T(spritesheet_1),
    .n_actors = 1,
    .n_triggers = 3,
    .n_sprites = 1,
    .actors = TO_FAR_PTR_T(scene_7_actors),
    .triggers = TO_FAR_PTR_T(scene_7_triggers),
    .sprites = TO_FAR_PTR_T(scene_7_sprites),
    .script_init = TO_FAR_PTR_T(script_s7_init)
};
