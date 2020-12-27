#include "DataManager.h"

#include <string.h>

#include "LinkedList.h"
#include "Scroll.h"
#include "Trigger.h"
#include "Sprite.h"
#include "Camera.h"
#include "data/spritesheet_0.h" // @todo don't hard code this

#define MAX_PLAYER_SPRITE_SIZE 24

UBYTE image_bank;
UBYTE image_attr_bank;
UBYTE collision_bank;
unsigned char* image_ptr;
unsigned char* image_attr_ptr;
unsigned char* collision_ptr;
UBYTE image_tile_width;
UBYTE image_tile_height;
UINT16 image_width;
UINT16 image_height;
UBYTE sprites_len;
UBYTE actors_len = 0;
UBYTE scene_type;

void load_tiles(const tileset_t* tiles, UBYTE bank) {
    UBYTE _save = _current_bank;
    SWITCH_ROM_MBC1(bank);
    set_bkg_data(0, tiles->n_tiles, tiles->tiles);
    SWITCH_ROM_MBC1(_save);
}

void load_image(const background_t* background, UBYTE bank) {
    UBYTE _save = _current_bank;

    SWITCH_ROM_MBC1(bank);
    image_bank = bank;
    image_tile_width = background->width;
    image_tile_height = background->height;
    image_width = image_tile_width * 8;
    scroll_x_max = image_width - ((UINT16)SCREENWIDTH);
    image_height = image_tile_height * 8;
    scroll_y_max = image_height - ((UINT16)SCREENHEIGHT);
    image_ptr = background->tiles;

    load_tiles(background->tileset.ptr, background->tileset.bank);
    SWITCH_ROM_MBC1(_save);
}

UBYTE load_sprite(UBYTE sprite_offset, const spritesheet_t *sprite, UBYTE bank) {
    UBYTE _save = _current_bank;
    UBYTE size;

    SWITCH_ROM_MBC1(bank);

    size = sprite->n_frames * 4;

    if (sprite_offset == 0 && sprite->n_frames > 6) {
        size = MAX_PLAYER_SPRITE_SIZE;
    }

    set_sprite_data(sprite_offset, size, sprite->frames);

    SWITCH_ROM_MBC1(_save);

    return size;
}

void load_scene(const scene_t* scene, UBYTE bank) {
    UBYTE _save = _current_bank;
    UBYTE i, k;
    far_ptr_t far_scene_actors;
    far_ptr_t far_scene_triggers;
    far_ptr_t far_scene_sprites;

    // Load scene
    SWITCH_ROM_MBC1(bank);
    far_scene_actors = scene->actors;
    far_scene_triggers = scene->triggers;
    far_scene_sprites = scene->sprites;
    scene_type = 1;
    actors_len = scene->n_actors + 1;
    triggers_len = scene->n_triggers;
    sprites_len = scene->n_sprites;
    collision_bank = scene->collisions.bank;
    collision_ptr = scene->collisions.ptr;
    image_attr_bank = scene->colors.bank;
    image_attr_ptr = scene->colors.ptr;

    // Load background + tiles
    load_image(scene->background.ptr, scene->background.bank);
    //   LoadPalette(scene->palette.ptr, scene->palette.bank);
    //   LoadSpritePalette(scene->sprite_palette.ptr,
    //   scene->sprite_palette.bank);
    //   LoadPlayerSpritePalette(start_player_palette.ptr,
    //   start_player_palette.bank);

    init_sprite_pool();
    camera_init();
    //   ScriptCtxPoolReset();
    //   UIReset();
    //   RemoveInputScripts();
    //   ProjectilesInit();
    //   InitPlayer();

    // Load sprites
    k = 24;
    if (sprites_len != 0) {
        far_ptr_t* scene_sprite_ptrs;
        SWITCH_ROM_MBC1(far_scene_sprites.bank);
        scene_sprite_ptrs = far_scene_sprites.ptr;
        for (i = 0; i != sprites_len; i++) {
            UBYTE sprite_len = load_sprite(k, scene_sprite_ptrs->ptr, scene_sprite_ptrs->bank);
            // sprites_info[i].sprite_offset = DIV_4(k);
            // sprites_info[i].frames_len = DIV_4(sprite_len);
            // if (sprites_info[i].frames_len == 6) {
            //   sprites_info[i].sprite_type = SPRITE_ACTOR_ANIMATED;
            //   sprites_info[i].frames_len = 2;
            // } else if (sprites_info[i].frames_len == 3) {
            //   sprites_info[i].sprite_type = SPRITE_ACTOR;
            //   sprites_info[i].frames_len = 1;
            // } else {
            //   sprites_info[i].sprite_type = SPRITE_STATIC;
            // }
            k += sprite_len;
            scene_sprite_ptrs++;
        }
    }

    // Load player
    actors[0].x = 45;
    actors[0].y = 96;
    actors[0].dir_x = 0;
    actors[0].dir_y = 1;
    actors[0].sprite = 6;
    actors[0].sprite_type = 0;
    actors[0].palette = 0;
    actors[0].n_frames = 1;
    actors[0].initial_frame = 0;
    actors[0].animate = FALSE;
    actors[0].move_speed = 1;
    actors[0].anim_tick = 7;
    actors[0].frame = 0;
    actors[0].frame_start = 0;
    actors[0].frame_end = 4;
    actors[0].flip_x = FALSE;
    actors[0].pinned = FALSE;    
    load_sprite(0, &spritesheet_0, (UBYTE)&__bank_spritesheet_0);

    // Load actors
    actors_active_head = 0;
    actors_inactive_head = 0;
    // Add player to inactive
    actors[0].enabled = FALSE;
    DL_PUSH_HEAD(actors_inactive_head, &actors[0]);
    if (actors_len != 0) {
        MemcpyBanked(&actors[1], far_scene_actors.ptr, sizeof(actor_t) * (actors_len - 1), far_scene_actors.bank);
        for (i = 1; i != actors_len; i++) {
            DL_PUSH_HEAD(actors_inactive_head, &actors[i]);
        }
    }
    activate_actor(&actors[0]);

    // Load triggers
    if (triggers_len != 0) {
        MemcpyBanked(&triggers, far_scene_triggers.ptr, sizeof(trigger_t) * triggers_len, far_scene_triggers.bank);
    }

    scroll_init();

    // Reset last trigger
    last_trigger_tx = 0xFF;
    last_trigger_ty = 0xFF;

    // Enable all pinned actors by default
    for (i = 1; i != actors_len; i++) {
        if (actors[i].pinned) {
            activate_actor(&actors[i]);
        }
    }

    SWITCH_ROM_MBC1(_save);
}
