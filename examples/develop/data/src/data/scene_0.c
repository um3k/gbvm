#pragma bank 255

// Scene: Cave

#include "gbs_types.h"
#include "data/background_0.h"
#include "data/scene_0_collisions.h"
#include "data/palette_0.h"
#include "data/palette_6.h"
#include "data/spritesheet_1.h"
#include "data/scene_0_actors.h"
#include "data/scene_0_triggers.h"
#include "data/scene_0_sprites.h"
#include "data/script_s0_init.h"

const void __at(255) __bank_scene_0;

const struct scene_t scene_0 = {
    .width = 20,
    .height = 18,
    .type = SCENE_TYPE_TOPDOWN,
    .background = TO_FAR_PTR_T(background_0),
    .collisions = TO_FAR_PTR_T(scene_0_collisions),
    .parallax_rows = {
        PARALLAX_STEP(0,0,0)
    },
    .palette = TO_FAR_PTR_T(palette_0),
    .sprite_palette = TO_FAR_PTR_T(palette_6),
    .player_sprite = TO_FAR_PTR_T(spritesheet_1),
    .n_actors = 6,
    .n_triggers = 1,
    .n_sprites = 4,
    .actors = TO_FAR_PTR_T(scene_0_actors),
    .triggers = TO_FAR_PTR_T(scene_0_triggers),
    .sprites = TO_FAR_PTR_T(scene_0_sprites),
    .script_init = TO_FAR_PTR_T(script_s0_init)
};
