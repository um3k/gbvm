#pragma bank 2

#include <string.h>

#include "UI.h"
#include "GameTime.h"
#include "data/frame_image.h"
#include "data/font_image.h"
#include "BankData.h"
#include "Scroll.h"

#define ui_frame_tl_tiles 0xC0u
#define ui_frame_bl_tiles 0xC6u
#define ui_frame_tr_tiles 0xC2u
#define ui_frame_br_tiles 0xC8u
#define ui_frame_t_tiles  0xC1u
#define ui_frame_b_tiles  0xC7u
#define ui_frame_l_tiles  0xC3u
#define ui_frame_r_tiles  0xC5u
#define ui_frame_bg_tiles 0xC4u

void ui_draw_frame(UBYTE x, UBYTE y, UBYTE width, UBYTE height) __banked;
void ui_draw_text_buffer_char_b();

UBYTE win_pos_x;
UBYTE win_pos_y;
UBYTE win_dest_pos_x;
UBYTE win_dest_pos_y;
UBYTE text_drawn;
UBYTE win_speed;
UBYTE current_text_speed;
UBYTE text_wait;
UBYTE avatar_enabled;
UBYTE menu_enabled;
UBYTE text_num_lines;

unsigned char ui_text_data[80];

// char printer internals
static UBYTE * ui_text_ptr  = 0;
static UBYTE * ui_dest_ptr  = 0;
static UBYTE * ui_dest_base = 0;
static UBYTE ui_text_width  = 0;
static UBYTE ui_width_left  = 0;
static UBYTE ui_tile_no     = 0;

// const far_ptr_t far_font_image = TO_FAR_PTR(font_image);
// const far_ptr_t far_frame_image = TO_FAR_PTR(frame_image);

void init_ui() __nonbanked {
    UBYTE _save = _current_bank;
    win_pos_x = 0;
    win_pos_y = 0;
    win_dest_pos_x = 0;
    win_dest_pos_y = 0;
    avatar_enabled = 0;
    menu_enabled = 0;
    text_num_lines = 0;
    win_speed = 1;
    current_text_speed = 1;
    SWITCH_ROM_MBC1(__bank_frame_image);
    set_bkg_data(192, 9, frame_image);
    SWITCH_ROM_MBC1(_save);
}

void ui_draw_frame(UBYTE x, UBYTE y, UBYTE width, UBYTE height) __banked {
  fill_win_rect(x,         y,              1,         1,      ui_frame_tl_tiles);  // top-left
  fill_win_rect(x + 1,     y,              width - 1, 1,      ui_frame_t_tiles);   // top
  fill_win_rect(x + width, y,              1,         1,      ui_frame_tr_tiles);  // top-right
  fill_win_rect(x,         y + 1,          1,         height, ui_frame_l_tiles);   // left
  fill_win_rect(x + width, y + 1,          1,         height, ui_frame_r_tiles);   // right
  fill_win_rect(x,         y + height + 1, 1,         1,      ui_frame_bl_tiles);  // bottom-left
  fill_win_rect(x + 1,     y + height + 1, width - 1, 1,      ui_frame_b_tiles);   // bottom
  fill_win_rect(x + width, y + height + 1, 1,         1,      ui_frame_br_tiles);  // bottom-right
  fill_win_rect(x + 1,     y + 1,          width - 1, height, ui_frame_bg_tiles);  // background
}

static const UBYTE time_masks[] = {0x00, 0x00, 0x00, 0x01, 0x03, 0x07}; 

void update_ui() __banked {
  UBYTE interval;

  if (game_time & time_masks[win_speed]) return;

  interval = (win_speed == 1) ? 2 : 1;

  if (win_pos_x != win_dest_pos_x) {
    if (win_pos_x < win_dest_pos_x) {
      win_pos_x += interval;
    } else {
      win_pos_x -= interval;
    }
  }

  if (win_pos_y != win_dest_pos_y) {
    if (win_pos_y < win_dest_pos_y) {
      win_pos_y += interval;
    } else {
      win_pos_y -= interval;
    }
  } else if(!text_drawn) {
    if (((game_time & current_text_speed) == 0) ) {
      do {
        ui_draw_text_buffer_char_b();
      } while ((current_text_speed == 0) && (!text_drawn));
    }
  }

  WX_REG = win_pos_x + 7;
  WY_REG = win_pos_y;
}

void ui_draw_text_buffer_char_b() {
  if (text_wait != 0) {
    text_wait--;
    return;
  }

  if (ui_text_ptr == 0) {
    // current char pointer
    ui_text_ptr = ui_text_data;
    // VRAM destination
    ui_dest_base = GetWinAddr() + 32 + 1;
    // text width
    ui_text_width = 18;
    // with and initial pos correction
    if (avatar_enabled) { 
      ui_text_width -= 4;
      ui_dest_base += 4;
    }
    ui_text_width -= menu_enabled;
    ui_dest_base += menu_enabled;
    // initialize current pointer with corrected base value
    ui_dest_ptr = ui_dest_base;
    // character counter
    ui_width_left = ui_text_width;
    // tileno destination
    ui_tile_no = TEXT_BUFFER_START;
  }

  switch (*ui_text_ptr) {
    case 0x00:
      ui_text_ptr = 0; 
      text_drawn = TRUE;
      return;
    case '\n':
      ui_dest_ptr = ui_dest_base += 32;
      ui_width_left = ui_text_width;
      break; 
    case 0x10:
      current_text_speed = 0;
      break;
    case 0x11:
      current_text_speed = 1;
      break;
    case 0x12:
      current_text_speed = 3;
      break;
    case 0x13:
      current_text_speed = 7;
      break;
    case 0x14:
      current_text_speed = 0x0f;
      break;
    case 0x15:
      current_text_speed = 0x1f;
      break;
    default:
      if (ui_width_left == 0) {
        ui_dest_ptr = ui_dest_base += 32;
        ui_width_left = ui_text_width; 
      }
      ui_width_left--;
      SetBankedBkgData(ui_tile_no, 1, font_image + ((UWORD)(*ui_text_ptr - 32) << 4), __bank_font_image);
      SetTile(ui_dest_ptr++, ui_tile_no);
      ui_tile_no++;
      break;
  }
  ui_text_ptr++;
}
