#pragma bank 255

// Scene: Outside

#include "gbs_types.h"
#include "data/background_1.h"
#include "data/scene_0_collisions.h"
#include "data/palette_0.h"
#include "data/spritesheet_0.h"
#include "data/scene_0_actors.h"
#include "data/scene_0_triggers.h"
#include "data/scene_0_sprites.h"

const void __at(255) __bank_scene_0;

const struct scene_t scene_0 = {
    .width = 32,
    .height = 32,
    .type = SCENE_TYPE_TOPDOWN,
    .background = TO_FAR_PTR_T(background_1),
    .collisions = TO_FAR_PTR_T(scene_0_collisions),
    .player_sprite = TO_FAR_PTR_T(spritesheet_0),
    .palette = TO_FAR_PTR_T(palette_0),
    .n_actors = 1,
    .n_triggers = 2,
    .n_sprites = 2,
    .actors = TO_FAR_PTR_T(scene_0_actors),
    .triggers = TO_FAR_PTR_T(scene_0_triggers),
    .sprites = TO_FAR_PTR_T(scene_0_sprites)
};
