#pragma bank 255

// Scene: Underground

#include "gbs_types.h"
#include "data/background_7.h"
#include "data/scene_6_collisions.h"
#include "data/palette_0.h"
#include "data/palette_1.h"
#include "data/spritesheet_0.h"
#include "data/scene_6_actors.h"
#include "data/scene_6_triggers.h"
#include "data/scene_6_sprites.h"
#include "data/script_s6_init.h"

const void __at(255) __bank_scene_6;

const struct scene_t scene_6 = {
    .width = 32,
    .height = 32,
    .type = SCENE_TYPE_TOPDOWN,
    .background = TO_FAR_PTR_T(background_7),
    .collisions = TO_FAR_PTR_T(scene_6_collisions),
    .palette = TO_FAR_PTR_T(palette_0),
    .sprite_palette = TO_FAR_PTR_T(palette_1),
    .player_sprite = TO_FAR_PTR_T(spritesheet_0),
    .n_actors = 5,
    .n_triggers = 1,
    .n_sprites = 3,
    .actors = TO_FAR_PTR_T(scene_6_actors),
    .triggers = TO_FAR_PTR_T(scene_6_triggers),
    .sprites = TO_FAR_PTR_T(scene_6_sprites),
    .script_init = TO_FAR_PTR_T(script_s6_init)
};
