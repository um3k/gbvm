#pragma bank 1

#include <string.h>

#include "UI.h"
#include "GameTime.h"
#include "data/frame_image.h"
#include "data/font_image.h"
#include "data/cursor_image.h"
#include "BankData.h"
#include "Scroll.h"
#include "Sprite.h"
#include "Input.h"
#include "Math.h"

#define ui_frame_tl_tiles 0xC0u
#define ui_frame_bl_tiles 0xC6u
#define ui_frame_tr_tiles 0xC2u
#define ui_frame_br_tiles 0xC8u
#define ui_frame_t_tiles  0xC1u
#define ui_frame_b_tiles  0xC7u
#define ui_frame_l_tiles  0xC3u
#define ui_frame_r_tiles  0xC5u
#define ui_frame_bg_tiles 0xC4u

const unsigned char ui_white[16] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
const unsigned char ui_black[16] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                                    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

const unsigned char avatar_tiles[4] = {TEXT_BUFFER_START, TEXT_BUFFER_START + 2U, TEXT_BUFFER_START + 1U, TEXT_BUFFER_START + 3U};

void ui_draw_frame(UBYTE x, UBYTE y, UBYTE width, UBYTE height) __banked;
void ui_draw_text_buffer_char() __banked;

UBYTE win_pos_x;
UBYTE win_pos_y;
UBYTE win_dest_pos_x;
UBYTE win_dest_pos_y;
UBYTE win_speed;

UBYTE text_drawn;
UBYTE current_text_speed;
UBYTE text_wait;
UBYTE text_line_count;

UBYTE avatar_enabled;

UBYTE menu_enabled;
UBYTE menu_index;
UBYTE menu_item_count;

UBYTE text_in_speed = 1;
UBYTE text_out_speed = 1;
UBYTE text_draw_speed = 1;
UBYTE text_ff_joypad = 1;
UBYTE text_ff; 
UBYTE menu_layout = MENU_LAYOUT_1_COLUMN;
UBYTE menu_cancel_on_last_option = 0;
UBYTE menu_cancel_on_b = 0;

unsigned char ui_text_data[80];

// char printer internals
static UBYTE * ui_text_ptr  = 0;
static UBYTE * ui_dest_ptr  = 0;
static UBYTE * ui_dest_base = 0;
static UBYTE ui_text_width  = 0;
static UBYTE ui_width_left  = 0;
static UBYTE ui_tile_no     = 0;
static UBYTE ui_line_no     = 0;

// const far_ptr_t far_font_image = TO_FAR_PTR(font_image);
// const far_ptr_t far_frame_image = TO_FAR_PTR(frame_image);

void ui_init() __banked {
    ui_set_pos(0, MENU_CLOSED_Y);

    avatar_enabled = 0;
    menu_enabled = 0;
    win_speed = 1;
    text_drawn = TRUE;
    text_draw_speed = 1;

    SetBankedBkgData(192, 9, frame_image, (UBYTE)&__bank_frame_image);
    SetBankedBkgData(ui_cursor_tile, 1, cursor_image, (UBYTE)&__bank_cursor_image);

    set_bkg_data(ui_while_tile, 1, ui_white);
    set_bkg_data(ui_black_tile, 1, ui_black);

}

void ui_draw_frame(UBYTE x, UBYTE y, UBYTE width, UBYTE height) __banked {
    set_win_tile_xy (x,         y,                                 ui_frame_tl_tiles);
    fill_win_rect   (x + 1,     y,              width - 1, 1,      ui_frame_t_tiles );   // top
    set_win_tile_xy (x + width, y,                                 ui_frame_tr_tiles);
    fill_win_rect   (x,         y + 1,          1,         height, ui_frame_l_tiles );   // left
    fill_win_rect   (x + width, y + 1,          1,         height, ui_frame_r_tiles );   // right
    set_win_tile_xy (x,         y + height + 1,                    ui_frame_bl_tiles);
    fill_win_rect   (x + 1,     y + height + 1, width - 1, 1,      ui_frame_b_tiles );   // bottom
    set_win_tile_xy (x + width, y + height + 1,                    ui_frame_br_tiles);
    fill_win_rect   (x + 1,     y + 1,          width - 1, height, ui_frame_bg_tiles);  // background
}

static const UBYTE time_masks[] = {0x00, 0x00, 0x00, 0x01, 0x03, 0x07}; 

void ui_update() __nonbanked {
    UBYTE interval, is_moving = FALSE;

    if (game_time & time_masks[win_speed]) return;

    interval = (win_speed == 1) ? 2 : 1;

    if (win_pos_x != win_dest_pos_x) {
        // move window left/right
        if (win_pos_x < win_dest_pos_x) win_pos_x += interval; else win_pos_x -= interval;
        is_moving = TRUE;
    }

    if (win_pos_y != win_dest_pos_y) {
        // move window up/down
        if (win_pos_y < win_dest_pos_y) win_pos_y += interval; else win_pos_y -= interval;
        is_moving = TRUE;
    }

    // don't draw text while moving
    if (is_moving) return;
    // all drawn - nothing to do
    if (text_drawn) return;
    // too fast - wait
    if ((!INPUT_A_OR_B) && game_time & current_text_speed) return;
    // render next char
    do {
        ui_draw_text_buffer_char();
    } while (((text_ff) || (current_text_speed == 0)) && (!text_drawn));
}

void ui_draw_text_buffer_char() __banked {
    if ((text_ff_joypad) && (INPUT_A_OR_B)) text_ff = TRUE;

    if ((!text_ff) && (text_wait != 0)) {
        text_wait--;
        return;
    }

    if (ui_text_ptr == 0) {
        // reset to first line
        ui_line_no = 0;
        // current char pointer
        ui_text_ptr = ui_text_data;
        // VRAM destination
        ui_dest_base = GetWinAddr() + 32 + 1; // current width of window in tiles
        // text width
        ui_text_width = 18;
        // with and initial pos correction
        if (avatar_enabled) { 
            ui_text_width -= AVATAR_WIDTH;
            ui_dest_base += AVATAR_WIDTH;
        }
        if (menu_enabled) {
            ui_text_width -= SELECTOR_WIDTH;
            ui_dest_base += SELECTOR_WIDTH;
        }
        // initialize current pointer with corrected base value
        ui_dest_ptr = ui_dest_base;
        // character counter
        ui_width_left = ui_text_width;
        // tileno destination
        ui_tile_no = TEXT_BUFFER_START;  
        if (avatar_enabled) {
            ui_tile_no += 4;
        }    
    }

    switch (*ui_text_ptr) {
        case 0x00:
            ui_text_ptr = 0; 
            text_drawn = TRUE;
            return;
        case '\n':
            ui_line_no++;
            if (menu_enabled && menu_layout == MENU_LAYOUT_2_COLUMN && ui_line_no == 4) {
                ui_dest_base = GetWinAddr() + 32 + 1 + 9;
                ui_dest_ptr = ui_dest_base;
            } else {
                ui_dest_ptr = ui_dest_base += 32;
            }
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
            SetBankedBkgData(ui_tile_no, 1, font_image + ((UWORD)(*ui_text_ptr - 32) << 4), (UBYTE)&__bank_font_image);
            SetTile(ui_dest_ptr++, ui_tile_no);
            ui_tile_no++;
            break;
    }
    ui_text_ptr++;
}

void ui_draw_menu_cursor(UBYTE show) __banked {
    UBYTE x = (avatar_enabled) ? 3 : 1;
    if (menu_layout == MENU_LAYOUT_2_COLUMN) {
        UBYTE height = MIN(4, menu_item_count);
        fill_win_rect(x, 1, 1, height, ui_bg_tile);
        fill_win_rect(9, 1, 1, height, ui_bg_tile);
        if (menu_index >= 4) x = 9;
        if (show) set_win_tile_xy(x, (menu_index%4) + 1, ui_cursor_tile);
    } else {
        fill_win_rect(x, 1, 1, menu_item_count, ui_bg_tile);
        if (show) set_win_tile_xy(x, menu_index + 1, ui_cursor_tile);
    }
}

INT8 ui_run_menu() __banked {
    // no menu items
    if (menu_item_count == 0) return 0;
    // run menu
    menu_index = 0;
    ui_draw_menu_cursor(TRUE);
    while (1) {
        input_update();
        ui_update();
        game_time++;
        wait_vbl_done();
        if (INPUT_UP_PRESSED) {
            if (menu_index != 0) menu_index--;
        } else if (INPUT_DOWN_PRESSED) {
            if (menu_index != menu_item_count - 1) menu_index++;
        } else if (INPUT_LEFT_PRESSED) {
            if (menu_layout == MENU_LAYOUT_2_COLUMN) {
                menu_index = MAX(menu_index - 4, 0);
            } else {
                menu_index = 0;
            }
        } else if (INPUT_RIGHT_PRESSED) {
            if (menu_layout == MENU_LAYOUT_2_COLUMN) {
                menu_index = MIN(menu_index + 4, menu_item_count - 1);
            } else {
                menu_index = menu_item_count - 1;
            }
        } else if (INPUT_A_PRESSED) {
            ui_draw_menu_cursor(FALSE);
            return menu_index;
        } else if (INPUT_B_PRESSED) {
            ui_draw_menu_cursor(FALSE);
            return menu_item_count - 1;
        } else {
            continue;
        }
        ui_draw_menu_cursor(TRUE);
    };
}

void ui_run_modal(UBYTE wait_flags) __banked {
    UBYTE fail;
    do {
        fail = 0;
    
        if (wait_flags & UI_WAIT_WINDOW)
            if ((win_pos_x != win_dest_pos_x) || (win_pos_y != win_dest_pos_y)) fail = 1;
        if (wait_flags & UI_WAIT_TEXT)
            if (!text_drawn) fail = 1;
        if (wait_flags & UI_WAIT_BTN_A)
            if (!INPUT_A_PRESSED) fail = 1;
        if (wait_flags & UI_WAIT_BTN_B)
            if (!INPUT_B_PRESSED) fail = 1;
        if (wait_flags & UI_WAIT_BTN_ANY)
            if (!INPUT_ANY_PRESSED) fail = 1;

        if (!fail) return;
        
        ui_update();
        game_time++;
        wait_vbl_done();
        input_update();
    } while (fail);    
}

void ui_draw_avatar(spritesheet_t *avatar, UBYTE avatar_bank) __banked {
    UBYTE *avatar_ui_ptr = GetWinAddr() + 32 + 1;
    SetBankedBkgData(TEXT_BUFFER_START, AVATAR_TILE_SIZE, avatar->frames, avatar_bank);
    set_win_tiles(1, 1, 2, 2, avatar_tiles);
}
