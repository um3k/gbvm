#pragma bank 255

// Scene: Underground

#include "gbs_types.h"
#include "data/background_14.h"
#include "data/scene_5_collisions.h"
#include "data/palette_1.h"
#include "data/palette_8.h"
#include "data/spritesheet_7.h"
#include "data/scene_5_actors.h"
#include "data/scene_5_triggers.h"
#include "data/scene_5_sprites.h"
#include "data/script_s5_init.h"

const void __at(255) __bank_scene_5;

const struct scene_t scene_5 = {
    .width = 32,
    .height = 32,
    .type = SCENE_TYPE_TOPDOWN,
    .background = TO_FAR_PTR_T(background_14),
    .collisions = TO_FAR_PTR_T(scene_5_collisions),
    .palette = TO_FAR_PTR_T(palette_1),
    .sprite_palette = TO_FAR_PTR_T(palette_8),
    .player_sprite = TO_FAR_PTR_T(spritesheet_7),
    .n_actors = 6,
    .n_triggers = 2,
    .n_sprites = 4,
    .actors = TO_FAR_PTR_T(scene_5_actors),
    .triggers = TO_FAR_PTR_T(scene_5_triggers),
    .sprites = TO_FAR_PTR_T(scene_5_sprites),
    .script_init = TO_FAR_PTR_T(script_s5_init)
};
