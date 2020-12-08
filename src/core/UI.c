#pragma bank 2
#include <stdio.h>
#include "vm.h"
#include "UI.h"
#include "GameTime.h"
#include "data/frame_image.h"
#include "data/font_image.h"
#include "BankData.h"
#include "Scroll.h"
#include <string.h>

#define ui_frame_tl_tiles 0xC0u
#define ui_frame_bl_tiles 0xC6u
#define ui_frame_tr_tiles 0xC2u
#define ui_frame_br_tiles 0xC8u
#define ui_frame_t_tiles  0xC1u
#define ui_frame_b_tiles  0xC7u
#define ui_frame_l_tiles  0xC3u
#define ui_frame_r_tiles  0xC5u
#define ui_frame_bg_tiles 0xC4u

UBYTE ui_load_text_n(SCRIPT_CTX * THIS) __nonbanked;
void ui_draw_frame(UBYTE x, UBYTE y, UBYTE width, UBYTE height);
void ui_draw_text_buffer_char_b();

UBYTE win_pos_x;
UBYTE win_pos_y;
UBYTE win_dest_pos_x;
UBYTE win_dest_pos_y;
UBYTE text_x;
UBYTE text_y;
UBYTE text_drawn;
UBYTE text_count;
UBYTE text_tile_count;
UBYTE win_speed;
UBYTE current_text_speed;
UBYTE text_wait;
UBYTE avatar_enabled;
UBYTE menu_enabled;
UBYTE text_num_lines;

unsigned char ui_text_data[80];
const UBYTE text_draw_speeds[] = {0x0, 0x1, 0x3, 0x7, 0xF, 0x1F};

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

UBYTE ui_text(SCRIPT_CTX * THIS, UBYTE start, UWORD * stack_frame) __banked {    
    stack_frame;
    if (start) {
        text_drawn = FALSE;
        text_x = 0;
        text_y = 0;
        text_count = 0;
        text_tile_count = 0;
        text_wait = 0;
        text_num_lines = 3;
        ui_draw_frame(0, 0, 19, 4);
        ui_load_text_n(THIS);
    }
    return TRUE;    
}

UBYTE ui_load_text_n(SCRIPT_CTX * THIS) __nonbanked {    
    UBYTE _save = _current_bank;
    SWITCH_ROM_MBC1(THIS->bank);
    
    const UBYTE * args = THIS->PC;
    unsigned char * d = ui_text_data; 
    const unsigned char * s = args;

    while (*s) {
        *d++ = *s++;
    }
    *d = 0, s++;

    // puts(ui_text_data);

    SWITCH_ROM_MBC1(_save);
    THIS->PC = s;

    return TRUE;
}

void ui_draw_frame(UBYTE x, UBYTE y, UBYTE width, UBYTE height) {
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
  UBYTE letter;
  UBYTE i, text_remaining, word_len;
  UBYTE text_size;
  UBYTE tile;
  UINT16 id;

  if (text_wait != 0) {
    text_wait--;
    return;
  }

  text_size = strlen(ui_text_data);

  if (text_count < text_size) {
    text_drawn = FALSE;

    if (text_count == 0) {
      text_x = 0;
      text_y = 0;
    }

    letter = ui_text_data[text_count] - 32;

    // Determine if text can fit on line
    text_remaining = 18 - text_x;
    word_len = 0;
    for (i = text_count; i != text_size; i++) {
      // Skip special characters when calculating word length
      if (ui_text_data[i] < ' ') {
        break;
      }
      word_len++;
    }
    if ((text_remaining < word_len) && (word_len < 18u)) {
      text_x = 0;
      text_y++;
    }

    // Skip special characters when drawing text
    if (ui_text_data[text_count] >= ' ') {
      i = text_tile_count + avatar_enabled * 4;

      SetBankedBkgData(TEXT_BUFFER_START + i, 1, (unsigned char* )((UWORD)font_image + (letter * 16)), __bank_font_image);

      tile = TEXT_BUFFER_START + i;
      id = (UINT16)GetWinAddr() +
           MOD_32((text_x + 1 + avatar_enabled * 2 + menu_enabled +
                   (text_y >= text_num_lines ? 9 : 0))) +
           ((UINT16)MOD_32((text_y % text_num_lines) + 1) << 5);
      SetTile(id, tile);

      text_tile_count++;
    }

    // Dynamic switch text speed
    if (ui_text_data[text_count] >= 0x10 && ui_text_data[text_count] < 0x16) {
      current_text_speed = text_draw_speeds[ui_text_data[text_count] - 0x10];
      text_x--;
    }

    text_count++;
    text_x++;
    if (ui_text_data[text_count] == '\n') {
      text_x = 0;
      text_y++;
      text_count++;
    } else if (UBYTE_GT_THAN(text_x, 17u)) {
      text_x = 0;
      text_y++;
    }

  } else {
    text_drawn = TRUE;
  }
}
