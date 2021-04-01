#pragma bank 255

// Scene: Level 1

#include "gbs_types.h"
#include "data/background_0.h"
#include "data/scene_0_collisions.h"
#include "data/scene_0_colors.h"
#include "data/palette_0.h"
#include "data/palette_1.h"
#include "data/spritesheet_0.h"
#include "data/scene_0_actors.h"
#include "data/scene_0_sprites.h"

const void __at(255) __bank_scene_0;

const struct scene_t scene_0 = {
    .width = 20,
    .height = 18,
    .type = SCENE_TYPE_TOPDOWN,
    .background = TO_FAR_PTR_T(background_0),
    .collisions = TO_FAR_PTR_T(scene_0_collisions),
    .colors = TO_FAR_PTR_T(scene_0_colors),
    .palette = TO_FAR_PTR_T(palette_0),
    .sprite_palette = TO_FAR_PTR_T(palette_1),
    .player_sprite = TO_FAR_PTR_T(spritesheet_0),
    .n_actors = 2,
    .n_triggers = 0,
    .n_sprites = 2,
    .actors = TO_FAR_PTR_T(scene_0_actors),
    .sprites = TO_FAR_PTR_T(scene_0_sprites)
};
