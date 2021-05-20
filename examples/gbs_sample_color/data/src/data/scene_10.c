#pragma bank 255

// Scene: Path to Sample Town

#include "gbs_types.h"
#include "data/background_9.h"
#include "data/scene_10_collisions.h"
#include "data/palette_5.h"
#include "data/palette_8.h"
#include "data/spritesheet_7.h"
#include "data/scene_10_actors.h"
#include "data/scene_10_triggers.h"
#include "data/scene_10_sprites.h"
#include "data/script_s10_init.h"

const void __at(255) __bank_scene_10;

const struct scene_t scene_10 = {
    .width = 161,
    .height = 18,
    .type = SCENE_TYPE_PLATFORM,
    .background = TO_FAR_PTR_T(background_9),
    .collisions = TO_FAR_PTR_T(scene_10_collisions),
    .parallax_rows = {
        PARALLAX_STEP(0,0,0)
    },
    .palette = TO_FAR_PTR_T(palette_5),
    .sprite_palette = TO_FAR_PTR_T(palette_8),
    .player_sprite = TO_FAR_PTR_T(spritesheet_7),
    .n_actors = 7,
    .n_triggers = 5,
    .n_sprites = 5,
    .actors = TO_FAR_PTR_T(scene_10_actors),
    .triggers = TO_FAR_PTR_T(scene_10_triggers),
    .sprites = TO_FAR_PTR_T(scene_10_sprites),
    .script_init = TO_FAR_PTR_T(script_s10_init)
};
