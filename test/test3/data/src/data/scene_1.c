#pragma bank 255

// Scene: Menu

#include "gbs_types.h"
#include "data/background_0.h"
#include "data/scene_1_collisions.h"
#include "data/palette_0.h"
#include "data/spritesheet_0.h"
#include "data/scene_1_sprites.h"
#include "data/script_s1_init.h"

const void __at(255) __bank_scene_1;

const struct scene_t scene_1 = {
    .width = 20,
    .height = 18,
    .type = SCENE_TYPE_TOPDOWN,
    .background = TO_FAR_PTR_T(background_0),
    .collisions = TO_FAR_PTR_T(scene_1_collisions),
    .player_sprite = TO_FAR_PTR_T(spritesheet_0),
    .palette = TO_FAR_PTR_T(palette_0),
    .n_actors = 0,
    .n_triggers = 0,
    .n_sprites = 1,
    .sprites = TO_FAR_PTR_T(scene_1_sprites),
    .script_init = TO_FAR_PTR_T(script_s1_init)
};
