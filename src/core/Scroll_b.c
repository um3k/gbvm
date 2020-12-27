#pragma bank 1

#include "DataManager.h"
#include "GameTime.h"
#include "Scroll.h"
#include "Camera.h"

void ScrollUpdateRowWithDelay(INT16 x, INT16 y);
void ScrollUpdateColumnWithDelay(INT16 x, INT16 y);
void ScrollUpdateRowR();
void ScrollUpdateColumnR();
void ScrollUpdateRow(INT16 x, INT16 y);

void RefreshScroll_b() __banked {
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
    ScrollUpdateColumnWithDelay(new_column - SCREEN_PAD_LEFT + SCREEN_TILE_REFRES_W - 1,
                                new_row - SCREEN_PAD_TOP);
  } else if (current_column == new_column + 1) {
    // Render left column
    ScrollUpdateColumnWithDelay(new_column - SCREEN_PAD_LEFT, new_row - SCREEN_PAD_TOP);
  } else if (current_column != new_column) {
    // If column differs by more than 1 render entire screen
    render = TRUE;
  }

  // If row is +/- 1 just render next row
  if (current_row == new_row - 1) {
    // Render bottom row
    ScrollUpdateRowWithDelay(new_column - SCREEN_PAD_LEFT,
                             new_row - SCREEN_PAD_TOP + SCREEN_TILE_REFRES_H - 1);
  } else if (current_row == new_row + 1) {
    // Render top row
    ScrollUpdateRowWithDelay(new_column - SCREEN_PAD_LEFT, new_row - SCREEN_PAD_TOP);
  } else if (current_row != new_row) {
    // If row differs by more than 1 render entire screen
    render = TRUE;
  }

  scroll_x = x;
  scroll_y = y;
  draw_scroll_x = x + scroll_offset_x;
  draw_scroll_y = y + scroll_offset_y;

  if (render) {
    RenderScreen();
  } else if (IS_FRAME_2) {
    if (pending_w_i) {
      // Render next pending chunk of row
      ScrollUpdateRowR();
    }
    if (pending_h_i) {
      // Render next pending chunk of column
      ScrollUpdateColumnR();
    }
  }
}

void RenderScreen() __banked {
    INT16 y;
    UBYTE i;

    draw_scroll_x = scroll_x;
    draw_scroll_y = scroll_y;

    // if (!fade_style)
    // {
    //   DISPLAY_OFF
    // } else if (!fade_timer == 0)
    // {
    //   // Immediately set all palettes black while screen renders.
    //   #ifdef CGB
    //   if (_cpu == CGB_TYPE) {
    //     for (UBYTE c = 0; c != 32; ++c) {
    //       BkgPaletteBuffer[c] = RGB_BLACK;
    //     }
    //     set_bkg_palette(0, 8, BkgPaletteBuffer);
    //     set_sprite_palette(0, 8, BkgPaletteBuffer);
    //   } else
    //   #endif
    //     OBP0_REG = 0xFF;
    //     BGP_REG = 0xFF;
    // }

    // Clear pending rows/ columns
    pending_w_i = 0;
    pending_h_i = 0;

    y = scroll_y >> 3;
    for (i = 0u; i != (SCREEN_TILE_REFRES_H) && y != image_height; ++i, y++) {
        ScrollUpdateRow((scroll_x >> 3) - SCREEN_PAD_LEFT, y - SCREEN_PAD_TOP);
    }

    game_time = 0;

    DISPLAY_ON;
    // if (!fade_timer == 0) {
    //   // Screen palate to nornmal if not fading
    //   ApplyPaletteChange();
    // }

}
