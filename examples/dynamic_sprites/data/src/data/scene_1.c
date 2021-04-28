#pragma bank 255

// Scene: Alt Player Sprite

#include "gbs_types.h"
#include "data/background_0.h"
#include "data/scene_1_collisions.h"
#include "data/palette_0.h"
#include "data/palette_1.h"
#include "data/spritesheet_3.h"
#include "data/scene_1_actors.h"
#include "data/scene_1_sprites.h"

const void __at(255) __bank_scene_1;

const struct scene_t scene_1 = {
    .width = 20,
    .height = 18,
    .type = SCENE_TYPE_TOPDOWN,
    .background = TO_FAR_PTR_T(background_0),
    .collisions = TO_FAR_PTR_T(scene_1_collisions),
    .palette = TO_FAR_PTR_T(palette_0),
    .sprite_palette = TO_FAR_PTR_T(palette_1),
    .player_sprite = TO_FAR_PTR_T(spritesheet_3),
    .n_actors = 2,
    .n_triggers = 0,
    .n_sprites = 2,
    .actors = TO_FAR_PTR_T(scene_1_actors),
    .sprites = TO_FAR_PTR_T(scene_1_sprites)
};
