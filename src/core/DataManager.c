#pragma bank 1

#include "DataManager.h"
#include "LinkedList.h"
#include "Actor.h"
#include "Scroll.h"
#include "Trigger.h"
#include "Sprite.h"
#include "Camera.h"
#include "data/spritesheet_0.h" // @todo don't hard code this
#include "vm.h"

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

void load_tiles(const tileset_t* tiles, UBYTE bank) __banked {
    UBYTE ntiles = ReadBankedUBYTE(&(tiles->n_tiles), bank);
    SetBankedBkgData(0, ntiles, tiles->tiles, bank);    
}

void load_image(const background_t* background, UBYTE bank) __banked {
    background_t bkg;
    MemcpyBanked(&bkg, background, sizeof(bkg), bank);

    image_bank = bank;
    image_ptr = background->tiles;
    image_tile_width = bkg.width;
    image_tile_height = bkg.height;
    image_width = image_tile_width * 8;
    scroll_x_max = image_width - ((UINT16)SCREENWIDTH);
    image_height = image_tile_height * 8;
    scroll_y_max = image_height - ((UINT16)SCREENHEIGHT);

    load_tiles(bkg.tileset.ptr, bkg.tileset.bank);
}

UBYTE load_sprite(UBYTE sprite_offset, const spritesheet_t *sprite, UBYTE bank) __banked {
    UBYTE n_frames = ReadBankedUBYTE(&(sprite->n_frames), bank);
    UBYTE size = n_frames << 2;
    if ((sprite_offset == 0) && (n_frames > 6)) {
        size = MAX_PLAYER_SPRITE_SIZE;
    }
    SetBankedSpriteData(sprite_offset, size, sprite->frames, bank);
    return size;
}

void load_scene(const scene_t* scene, UBYTE bank) __banked {
    UBYTE i, k;

    scene_t scn;
    MemcpyBanked(&scn, scene, sizeof(scn), bank);

    // Load scene
    scene_type = scn.type;
    actors_len = scn.n_actors + 1;
    triggers_len = scn.n_triggers;
    sprites_len = scn.n_sprites;

    collision_bank = scn.collisions.bank;
    collision_ptr = scn.collisions.ptr;

    image_attr_bank = scn.colors.bank;
    image_attr_ptr = scn.colors.ptr;

    // Load background + tiles
    load_image(scn.background.ptr, scn.background.bank);
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
        far_ptr_t * scene_sprite_ptrs = scn.sprites.ptr;
        for (i = 0; i != sprites_len; i++) {
            far_ptr_t tmp_ptr;
            ReadBankedFarPtr(&tmp_ptr, (void *)scene_sprite_ptrs, scn.sprites.bank);
            UBYTE sprite_len = load_sprite(k, tmp_ptr.ptr, tmp_ptr.bank);
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
    PLAYER.dir_x = 0;
    PLAYER.dir_y = 1;
    PLAYER.sprite = 0;
    PLAYER.sprite_type = SPRITE_TYPE_ACTOR_ANIMATED;
    PLAYER.palette = 0;
    PLAYER.n_frames = 2;
    PLAYER.initial_frame = 0;
    PLAYER.animate = FALSE;
    PLAYER.move_speed = 1;
    PLAYER.anim_tick = 7;
    PLAYER.frame = 0;
    PLAYER.frame_start = 0;
    PLAYER.frame_end = 4;
    PLAYER.flip_x = FALSE;
    PLAYER.pinned = FALSE;    
    load_sprite(0, &spritesheet_0, BANK(spritesheet_0));

    player_moving = FALSE;

    // Load actors
    actors_active_head = 0;
    actors_inactive_head = 0;
    // Add player to inactive
    PLAYER.enabled = FALSE;
    DL_PUSH_HEAD(actors_inactive_head, &PLAYER);
    activate_actor(&PLAYER);
    if (actors_len != 0) {
        actor_t * actor = actors + 1;
        MemcpyBanked(actor, scn.actors.ptr, sizeof(actor_t) * (actors_len - 1), scn.actors.bank);
        for (i = actors_len - 1; i != 0; i--, actor++) {
            DL_PUSH_HEAD(actors_inactive_head, actor);
            // Enable all pinned actors by default
            if (actor->pinned) activate_actor(actor);
        }
    }

    // Load triggers
    if (triggers_len != 0) {
        MemcpyBanked(&triggers, scn.triggers.ptr, sizeof(trigger_t) * triggers_len, scn.triggers.bank);
    }

    scroll_init();

    // Reset last trigger
    last_trigger_tx = 0xFF;
    last_trigger_ty = 0xFF;

    if (scn.script_init.ptr) {
        script_execute(scn.script_init.bank, scn.script_init.ptr, 0, 0);
    }
}
