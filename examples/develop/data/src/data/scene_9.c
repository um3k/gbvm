#pragma bank 255

// Scene: Dancefloor

#include "gbs_types.h"
#include "data/background_1.h"
#include "data/scene_9_collisions.h"
#include "data/palette_5.h"
#include "data/palette_7.h"
#include "data/spritesheet_12.h"
#include "data/scene_9_actors.h"
#include "data/scene_9_triggers.h"
#include "data/scene_9_sprites.h"
#include "data/script_s9_init.h"

BANKREF(scene_9)

const struct scene_t scene_9 = {
    .width = 20,
    .height = 18,
    .type = SCENE_TYPE_PLATFORM,
    .background = TO_FAR_PTR_T(background_1),
    .collisions = TO_FAR_PTR_T(scene_9_collisions),
    .parallax_rows = {
        PARALLAX_STEP(0,0,0)
    },
    .palette = TO_FAR_PTR_T(palette_5),
    .sprite_palette = TO_FAR_PTR_T(palette_7),
    .player_sprite = TO_FAR_PTR_T(spritesheet_12),
    .n_actors = 2,
    .n_triggers = 2,
    .n_sprites = 2,
    .n_projectiles = 0,
    .actors = TO_FAR_PTR_T(scene_9_actors),
    .triggers = TO_FAR_PTR_T(scene_9_triggers),
    .sprites = TO_FAR_PTR_T(scene_9_sprites),
    .script_init = TO_FAR_PTR_T(script_s9_init)
};
