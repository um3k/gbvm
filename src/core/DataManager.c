#pragma bank 1

#include <string.h>

#include "vm.h"
#include "DataManager.h"
#include "LinkedList.h"
#include "Actor.h"
#include "Scroll.h"
#include "Trigger.h"
#include "Camera.h"
#include "UI.h"
#ifdef CGB
    #include "Palette.h"
#endif
#include "data/spritesheet_0.h" // @todo don't hard code this
#include "data/data_ptrs.h"

#define MAX_PLAYER_SPRITE_SIZE  24
#define EMOTE_SPRITE            124
#define EMOTE_SPRITE_SIZE       4

far_ptr_t current_scene;
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
UBYTE player_sprite_len = 0;
scene_type_e scene_type;
LCD_isr_e scene_LCD_type;

void load_tiles(const tileset_t* tiles, UBYTE bank) __banked {
    UWORD ntiles = ReadBankedUWORD(&(tiles->n_tiles), bank);
    UBYTE bkg_tiles, sprite_tiles;
    if (ntiles > 256) {
        bkg_tiles = 0; sprite_tiles = ntiles - 256; 
    } else {
        bkg_tiles = ntiles; sprite_tiles = 0;
    }
    SetBankedBkgData(0, bkg_tiles, tiles->tiles, bank);
    if (sprite_tiles) SetBankedSpriteData(0, sprite_tiles, tiles->tiles + (256 * 16), bank);
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
    UBYTE n_tiles = ReadBankedUBYTE(&(sprite->n_tiles), bank);
    UBYTE size = n_tiles << 2;
    if ((sprite_offset == 0) && (n_tiles > 6)) {
        size = MAX_PLAYER_SPRITE_SIZE;
    }
    SetBankedSpriteData(sprite_offset, size, sprite->tiles, bank);
    return size;
}

#ifdef CGB
void load_palette(const UBYTE *palette, UBYTE bank) __banked {
  if (palette_update_mask == 0x3F) {
    MemcpyBanked(BkgPalette, palette, 48, bank);
  } else {
    if (palette_update_mask & 0x1) {
      MemcpyBanked(BkgPalette, palette, 8, bank);
    }
    if (palette_update_mask & 0x2) {
      MemcpyBanked(BkgPalette + 4, palette + 8, 8, bank);
    }
    if (palette_update_mask & 0x4) {
      MemcpyBanked(BkgPalette + 8, palette + 16, 8, bank);
    }
    if (palette_update_mask & 0x8) {
      MemcpyBanked(BkgPalette + 12, palette + 24, 8, bank);
    }    
    if (palette_update_mask & 0x10) {
      MemcpyBanked(BkgPalette + 16, palette + 32, 8, bank);
    }    
    if (palette_update_mask & 0x20) {
      MemcpyBanked(BkgPalette + 20, palette + 40, 8, bank);
    }            
  }
}

void load_ui_palette(const UBYTE *data_ptr, UBYTE bank) __banked {
  MemcpyBanked(BkgPalette + UI_PALETTE_OFFSET, data_ptr, 8, bank);
}

void load_sprite_palette(const UBYTE *data_ptr, UBYTE bank) __banked {
  MemcpyBanked(SprPalette, data_ptr, 56, bank);
}

void load_player_palette(const UBYTE *data_ptr, UBYTE bank) __banked {
  MemcpyBanked(SprPalette + PLAYER_PALETTE_OFFSET, data_ptr, 8, bank);
}
#endif

static void load_player_data() {
    UBYTE sprite_frames = DIV_4(load_sprite(0, start_player_sprite.ptr, start_player_sprite.bank));
    if (sprite_frames > 6) {
        // Limit player to 6 frames to prevent overflow into scene actor vram
        PLAYER.sprite_type = SPRITE_TYPE_STATIC;
        PLAYER.n_frames = 6;
    } else if (sprite_frames == 6) {
        PLAYER.sprite_type = SPRITE_TYPE_ACTOR_ANIMATED;
        PLAYER.n_frames = 2;
    } else if (sprite_frames == 3) {
        PLAYER.sprite_type = SPRITE_TYPE_ACTOR;
        PLAYER.n_frames = 1;    
    } else {
        PLAYER.sprite_type = SPRITE_TYPE_STATIC;
        PLAYER.n_frames = sprite_frames;    
    }
}

UBYTE load_scene(const scene_t* scene, UBYTE bank, UBYTE init_data) __banked {
    UBYTE i, k;
    scene_t scn;

    ui_load_tiles();

    MemcpyBanked(&scn, scene, sizeof(scn), bank);

    current_scene.bank = bank;
    current_scene.ptr = (void *)scene;

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
#ifdef CGB
    load_palette(scn.palette.ptr, scn.palette.bank);
    load_sprite_palette(scn.sprite_palette.ptr, scn.sprite_palette.bank);
    load_player_palette(start_player_palette.ptr, start_player_palette.bank);
#endif

    // Copy parallax settings
    memcpy(&parallax_rows, &scn.parallax_rows, sizeof(parallax_rows));
    if (scn.parallax_rows[0].tile_height == 0) {
        scn.parallax_rows[0].tile_height = PARALLAX_MAX_HEIGHT;
        scene_LCD_type = (scene_type == SCENE_TYPE_LOGO) ? LCD_fullscreen : LCD_simple;
    } else {
        scene_LCD_type = LCD_parallax;
    }

    //   ProjectilesInit();

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

    if (init_data) {
        camera_init();

        // Copy scene player hit scripts to player actor
        memcpy(&PLAYER.script_hit1, &scn.script_p_hit1, sizeof(far_ptr_t));
        memcpy(&PLAYER.script_hit2, &scn.script_p_hit2, sizeof(far_ptr_t));
        memcpy(&PLAYER.script_hit3, &scn.script_p_hit3, sizeof(far_ptr_t));

        player_moving = FALSE;
        PLAYER.animate = FALSE;

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
                actor->enabled = FALSE;
                DL_PUSH_HEAD(actors_inactive_head, actor);
                // Enable all pinned actors by default
                if (actor->pinned) activate_actor(actor);
            }
        }
    } else {
        actor_t *actor = actors_active_head;
        while (actor) {
            actor_reset_dir(actor);
            actor = actor->next;
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

    emote_actor = NULL;

    // load initial player
    if (scene_type != SCENE_TYPE_LOGO) load_player_data();

    if (init_data && scn.script_init.ptr) {
        return (script_execute(scn.script_init.bank, scn.script_init.ptr, 0, 0) != 0);
    }
    return FALSE;
}

void load_player() __banked {
    PLAYER.pos.x = start_scene_x;
    PLAYER.pos.y = start_scene_y;
    PLAYER.dir_x = start_scene_dir_x;
    PLAYER.dir_y = start_scene_dir_y;    
    PLAYER.sprite = start_player_sprite;
#ifdef CGB
    PLAYER.palette = PLAYER_PALETTE;
#endif
    PLAYER.animate = FALSE;
    PLAYER.move_speed = start_player_move_speed;
    PLAYER.anim_tick = start_player_anim_tick;
    PLAYER.frame = 0;
    PLAYER.frame_start = 0;
    PLAYER.frame_end = 2;
    PLAYER.flip_x = FALSE;
    PLAYER.pinned = FALSE;    
    PLAYER.collision_group = 0;
    PLAYER.collision_enabled = TRUE;
    PLAYER.bounds.left = 2;
    PLAYER.bounds.right = 14;
    PLAYER.bounds.top = -12;
    PLAYER.bounds.bottom = 0;
}

void load_emote(const spritesheet_t *sprite, UBYTE bank) __banked {
    SetBankedSpriteData(EMOTE_SPRITE, EMOTE_SPRITE_SIZE, sprite->tiles, bank);
    set_sprite_prop(0, 0);
    set_sprite_prop(1, 0);
    set_sprite_tile(0, EMOTE_SPRITE);
    set_sprite_tile(1, EMOTE_SPRITE + 2);
}
