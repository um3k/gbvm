#pragma bank 1

#include "Scroll.h"

#include "Actor.h"
#include "Camera.h"
#include "DataManager.h"
#include "GameTime.h"
#include "Math.h"
#include "FadeManager.h"
#ifdef PARALLAX
    #include "parallax.h"
#endif

#include "data/data_ptrs.h"

void scroll_queue_row(INT16 x, INT16 y);
void scroll_queue_col(INT16 x, INT16 y);
void scroll_load_pending_row();
void scroll_load_pending_col();
void scroll_load_row(INT16 x, INT16 y);
void scroll_render_screen();

INT16 scroll_x = 0;
INT16 scroll_y = 0;
INT16 draw_scroll_x = 0;
INT16 draw_scroll_y = 0;
UINT16 scroll_x_max = 0;
UINT16 scroll_y_max = 0;
INT16 scroll_offset_x = 0;
INT16 scroll_offset_y = 0;
INT16 pending_h_x, pending_h_y;
UINT8 pending_h_i;
unsigned char* pending_h_map = 0;
unsigned char* pending_w_map = 0;
#ifdef CGB
unsigned char* pending_h_cmap = 0;
unsigned char* pending_w_cmap = 0;
#endif
INT16 pending_w_x, pending_w_y;
UINT8 pending_w_i;

void scroll_init() __banked {
    pending_w_i = 0;
    pending_h_i = 0;
    scroll_x = 0x7FFF;
    scroll_y = 0x7FFF;
}

void scroll_update() __banked {
  INT16 x, y;
  INT16 current_column, new_column, current_row, new_row;
  UBYTE render = FALSE;

  x = camera_x - (SCREENWIDTH >> 1);
  y = camera_y - (SCREENHEIGHT >> 1);

  if (x & 0x8000u) {  // check for negative signed bit
    x = 0u;
  } else if (x > scroll_x_max) {
    x = scroll_x_max;
  }
  if (y & 0x8000u) {
    y = 0u;
  } else if (y > scroll_y_max) {
    y = scroll_y_max;
  }

  current_column = scroll_x >> 3;
  new_column = x >> 3;
  current_row = scroll_y >> 3;
  new_row = y >> 3;

  // If column is +/- 1 just render next column
  if (current_column == new_column - 1) {
    // Render right column
    scroll_queue_col(new_column - SCREEN_PAD_LEFT + SCREEN_TILE_REFRES_W - 1,
                                new_row - SCREEN_PAD_TOP);
  } else if (current_column == new_column + 1) {
    // Render left column
    scroll_queue_col(new_column - SCREEN_PAD_LEFT, new_row - SCREEN_PAD_TOP);
  } else if (current_column != new_column) {
    // If column differs by more than 1 render entire screen
    render = TRUE;
  }

  // If row is +/- 1 just render next row
  if (current_row == new_row - 1) {
    // Render bottom row
    scroll_queue_row(new_column - SCREEN_PAD_LEFT,
                             new_row - SCREEN_PAD_TOP + SCREEN_TILE_REFRES_H - 1);
  } else if (current_row == new_row + 1) {
    // Render top row
    scroll_queue_row(new_column - SCREEN_PAD_LEFT, new_row - SCREEN_PAD_TOP);
  } else if (current_row != new_row) {
    // If row differs by more than 1 render entire screen
    render = TRUE;
  }

  scroll_x = x;
  scroll_y = y;
  draw_scroll_x = x + scroll_offset_x;
  draw_scroll_y = y + scroll_offset_y;

#ifdef PARALLAX
    parallax_rows[0].scx = draw_scroll_x >> parallax_rows[0].shift;
    parallax_rows[1].scx = draw_scroll_x >> parallax_rows[1].shift;
    parallax_rows[2].scx = draw_scroll_x >> parallax_rows[2].shift;
#endif

  if (render) {
    scroll_render_screen();
  } else if (IS_FRAME_2) {
    if (pending_w_i) {
      // Render next pending chunk of row
      scroll_load_pending_row();
    }
    if (pending_h_i) {
      // Render next pending chunk of column
      scroll_load_pending_col();
    }
  }
}

void scroll_render_screen() {
    INT16 y;
    UBYTE i;

    draw_scroll_x = scroll_x;
    draw_scroll_y = scroll_y;

    if (!fade_style)
    {
        DISPLAY_OFF
    } else if (!fade_timer == 0)
    {
// Immediately set all palettes black while screen renders.
#ifdef CGB
        if (_cpu == CGB_TYPE) {
            for (UBYTE c = 0; c != 32; ++c) {
                BkgPaletteBuffer[c] = RGB_BLACK;
            }
            set_bkg_palette(0, 8, BkgPaletteBuffer);
            set_sprite_palette(0, 8, BkgPaletteBuffer);
        } else
#endif
        OBP0_REG = 0xFF, BGP_REG = 0xFF;
    }

    // Clear pending rows/ columns
    pending_w_i = 0;
    pending_h_i = 0;

    y = scroll_y >> 3;
    for (i = 0u; i != (SCREEN_TILE_REFRES_H) && y != image_height; ++i, y++) {
        scroll_load_row((scroll_x >> 3) - SCREEN_PAD_LEFT, y - SCREEN_PAD_TOP);
    }

    game_time = 0;

    DISPLAY_ON;
    if (!fade_timer == 0) {
        // Screen palate to nornmal if not fading
        fade_applypalettechange();
    }

}

void scroll_queue_row(INT16 x, INT16 y) {
    actor_t *actor;

    while (pending_w_i) {
        scroll_load_pending_row();
    }

    pending_w_x = x;
    pending_w_y = y;

    pending_w_i = SCREEN_TILE_REFRES_W;
    pending_w_map = image_ptr + image_tile_width * y + x;

    // Activate Actors in Row
    actor = actors_inactive_head;
    while (actor) {
        INT16 ty = actor->y >> 3;
        if (ty == y) {
            INT16 tx = actor->x >> 3;
            if ((tx + 1 > x) && (tx < x + SCREEN_TILE_REFRES_W)) {
                actor_t * next = actor->next;
                activate_actor(actor);
                actor=next;
                continue;
            }
        }
        actor = actor->next;
    }

#ifdef CGB
    pending_w_cmap = image_attr_ptr + image_tile_width * y + x;
#endif
}

void scroll_queue_col(INT16 x, INT16 y) {
    actor_t *actor;
    
    while (pending_h_i) {
        // If previous column wasn't fully rendered
        // render it now before starting next column
        scroll_load_pending_col();
    }

    // Activate Actors in Column
    actor = actors_inactive_head;
    while (actor) {
        INT16 tx = actor->x >> 3;
        if (tx == x) {
            INT16 ty = actor->y >> 3;
            if ((ty > y) && (ty < y + SCREEN_TILE_REFRES_H)) {
                actor_t * next = actor->next;
                activate_actor(actor);
                actor=next;
                continue;
            }
        }
        actor = actor->next;
    }

    pending_h_x = x;
    pending_h_y = y;
    pending_h_i = SCREEN_TILE_REFRES_H;
    pending_h_map = image_ptr + image_tile_width * y + x;

#ifdef CGB
    pending_h_cmap = image_attr_ptr + image_tile_width * y + x;
#endif
}

/* Update pending (up to 5) rows */
void scroll_load_pending_row() __nonbanked {
    UINT8 _save = _current_bank;
    UINT8 i = 0u;
    UBYTE* id;
    UBYTE y_offset;

    y_offset = MOD_32(pending_w_y);

    SWITCH_ROM_MBC1(image_bank);

#ifdef CGB
    if (_cpu == CGB_TYPE) {  // Color Row Load
        for (i = 0u; i != 5 && pending_w_i != 0; ++i, --pending_w_i) {
            id = 0x9800 + MOD_32(pending_w_x++) + ((UINT16)y_offset << 5);
            SWITCH_ROM_MBC1(image_attr_bank);
            VBK_REG = 1;
            SetTile(id, *pending_w_cmap);
            VBK_REG = 0;
            SWITCH_ROM_MBC1(image_bank);
            SetTile(id, *pending_w_map);
            pending_w_map++;
            pending_w_cmap++;
        }
    } else
#endif
    {  // DMG Row Load
        for (i = 0u; i != 5 && pending_w_i != 0; ++i, --pending_w_i) {
            id = (UBYTE*)(0x9800 + MOD_32(pending_w_x++) +
                          ((UINT16)y_offset << 5));
            SetTile(id, *pending_w_map);
            pending_w_map++;
        }
    }
    SWITCH_ROM_MBC1(_save);
}


void scroll_load_row(INT16 x, INT16 y) __nonbanked {
    UINT8 _save = _current_bank;
    actor_t *actor;
    UINT8 i = 0u;
    UBYTE* id;
    UBYTE screen_x, screen_y;
    unsigned char* map = image_ptr + image_tile_width * y + x;
#ifdef CGB
    unsigned char* cmap = image_attr_ptr + image_tile_width * y + x;
#endif

    SWITCH_ROM_MBC1(image_bank);

    screen_x = x;
    screen_y = MOD_32(y);

    for (i = 0; i != 23; i++) {
        id = (UBYTE*)(0x9800 + MOD_32(screen_x++) + ((UINT16)screen_y << 5));

#ifdef CGB
        SWITCH_ROM_MBC1(image_attr_bank);
        VBK_REG = 1;
        SetTile(id, *(cmap++));
        VBK_REG = 0;
        SWITCH_ROM_MBC1(image_bank);
#endif
        SetTile(id, *(map++));
    }

    // Activate Actors in Row
    actor = actors_inactive_head;
    while (actor) {
        INT16 ty = actor->y >> 3;
        if (ty == y) {
            INT16 tx = actor->x >> 3;
            if ((tx + 1 > x) && (tx < x + SCREEN_TILE_REFRES_W)) {
                actor_t * next = actor->next;
                activate_actor(actor);
                actor=next;
                continue;
            }
        }
        actor = actor->next;
    }

    SWITCH_ROM_MBC1(_save);
}

void scroll_load_pending_col() __nonbanked {
    UINT8 _save = _current_bank;
    UINT8 i = 0u;
    UBYTE a = 0;
    UBYTE* id = 0;
    UBYTE x_offset;

    SWITCH_ROM_MBC1(image_bank);

    x_offset = MOD_32(pending_h_x);

#ifdef CGB
    if (_cpu == CGB_TYPE) {  // Color Column Load
        for (i = 0u; i != 5 && pending_h_i != 0; ++i, pending_h_i--) {
            id = 0x9800 + (0x1F & (x_offset)) +
                 ((0x1F & (MOD_32(pending_h_y))) << 5);
            SWITCH_ROM_MBC1(image_attr_bank);
            VBK_REG = 1;
            SetTile(id, *pending_h_cmap);
            VBK_REG = 0;
            SWITCH_ROM_MBC1(image_bank);
            SetTile(id, *pending_h_map);
            pending_h_y++;
            pending_h_map += image_tile_width;
            pending_h_cmap += image_tile_width;
        }
    } else
#endif
    {  // DMG Column Load
        for (i = 0u; i != 5 && pending_h_i != 0; ++i, pending_h_i--) {
            id = (UBYTE*)(0x9800 + (0x1F & (x_offset)) +
                          ((0x1F & (MOD_32(pending_h_y++))) << 5));
            SetTile(id, *pending_h_map);
            pending_h_map += image_tile_width;
        }
    }

    SWITCH_ROM_MBC1(_save);
}
