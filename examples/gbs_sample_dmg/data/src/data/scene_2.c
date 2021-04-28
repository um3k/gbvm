#pragma bank 255

// Scene: House

#include "gbs_types.h"
#include "data/background_1.h"
#include "data/scene_2_collisions.h"
#include "data/palette_0.h"
#include "data/palette_1.h"
#include "data/spritesheet_0.h"
#include "data/scene_2_actors.h"
#include "data/scene_2_triggers.h"
#include "data/scene_2_sprites.h"
#include "data/script_s2_init.h"

const void __at(255) __bank_scene_2;

const struct scene_t scene_2 = {
    .width = 20,
    .height = 18,
    .type = SCENE_TYPE_TOPDOWN,
    .background = TO_FAR_PTR_T(background_1),
    .collisions = TO_FAR_PTR_T(scene_2_collisions),
    .palette = TO_FAR_PTR_T(palette_0),
    .sprite_palette = TO_FAR_PTR_T(palette_1),
    .player_sprite = TO_FAR_PTR_T(spritesheet_0),
    .n_actors = 5,
    .n_triggers = 1,
    .n_sprites = 3,
    .actors = TO_FAR_PTR_T(scene_2_actors),
    .triggers = TO_FAR_PTR_T(scene_2_triggers),
    .sprites = TO_FAR_PTR_T(scene_2_sprites),
    .script_init = TO_FAR_PTR_T(script_s2_init)
};
