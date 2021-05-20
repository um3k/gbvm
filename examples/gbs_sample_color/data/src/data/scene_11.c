#pragma bank 255

// Scene: Deep Space

#include "gbs_types.h"
#include "data/background_12.h"
#include "data/scene_11_collisions.h"
#include "data/palette_6.h"
#include "data/palette_8.h"
#include "data/spritesheet_7.h"
#include "data/scene_11_actors.h"
#include "data/scene_11_triggers.h"
#include "data/scene_11_sprites.h"
#include "data/script_s11_init.h"

const void __at(255) __bank_scene_11;

const struct scene_t scene_11 = {
    .width = 32,
    .height = 32,
    .type = SCENE_TYPE_TOPDOWN,
    .background = TO_FAR_PTR_T(background_12),
    .collisions = TO_FAR_PTR_T(scene_11_collisions),
    .parallax_rows = {
        PARALLAX_STEP(0,0,0)
    },
    .palette = TO_FAR_PTR_T(palette_6),
    .sprite_palette = TO_FAR_PTR_T(palette_8),
    .player_sprite = TO_FAR_PTR_T(spritesheet_7),
    .n_actors = 3,
    .n_triggers = 1,
    .n_sprites = 3,
    .actors = TO_FAR_PTR_T(scene_11_actors),
    .triggers = TO_FAR_PTR_T(scene_11_triggers),
    .sprites = TO_FAR_PTR_T(scene_11_sprites),
    .script_init = TO_FAR_PTR_T(script_s11_init)
};
