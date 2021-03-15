#pragma bank 1

#include <string.h>

#include "ui.h"
#include "game_time.h"
#include "data/data_bootstrap.h"
#include "data/frame_image.h"
#include "data/cursor_image.h"
#include "bankdata.h"
#include "scroll.h"
#include "input.h"
#include "math.h"
#include "actor.h"
#include "projectiles.h"
#include "shadow.h"

#define ui_frame_tl_tiles 0xC0u
#define ui_frame_bl_tiles 0xC6u
#define ui_frame_tr_tiles 0xC2u
#define ui_frame_br_tiles 0xC8u
#define ui_frame_t_tiles  0xC1u
#define ui_frame_b_tiles  0xC7u
#define ui_frame_l_tiles  0xC3u
#define ui_frame_r_tiles  0xC5u
#define ui_frame_bg_tiles 0xC4u

const unsigned char avatar_tiles[4] = {TEXT_BUFFER_START, TEXT_BUFFER_START + 2U, TEXT_BUFFER_START + 1U, TEXT_BUFFER_START + 3U};

UBYTE win_pos_x, win_dest_pos_x;
UBYTE win_pos_y, win_dest_pos_y;
UBYTE win_speed;

UBYTE text_drawn;
UBYTE current_text_speed;
UBYTE text_wait;
UBYTE text_line_count;

UBYTE avatar_enabled;

UBYTE menu_enabled;
UBYTE menu_layout;

UBYTE text_in_speed;
UBYTE text_out_speed;
UBYTE text_draw_speed;
UBYTE text_ff_joypad;
UBYTE text_ff; 
UBYTE text_bkg_fill;

unsigned char ui_text_data[TEXT_MAX_LENGTH];

// char printer internals
static UBYTE * ui_text_ptr;
static UBYTE * ui_dest_ptr;
static UBYTE * ui_dest_base;
static UBYTE ui_text_width;
static UBYTE ui_width_left;
static UBYTE ui_line_no;
static UBYTE ui_current_tile;
static UBYTE vwf_current_offset;
static UBYTE vwf_tile_data[16 * 2];
UBYTE vwf_current_mask;
UBYTE vwf_current_rotate;
UBYTE vwf_inverse_map;

font_desc_t vwf_current_font_desc;
UBYTE vwf_current_font_bank;

extern const UBYTE ui_time_masks[];

void ui_init() __banked {
    vwf_current_font_bank = ui_fonts[0].bank;
    MemcpyBanked(&vwf_current_font_desc, ui_fonts[0].ptr, sizeof(font_desc_t), vwf_current_font_bank);

    text_in_speed               = 1;
    text_out_speed              = 1;
    text_draw_speed             = 1;
    text_ff_joypad              = 1;
    text_bkg_fill               = TEXT_BKG_FILL_W;
    menu_layout                 = MENU_LAYOUT_1_COLUMN;

    ui_text_ptr                 = 0;
    ui_dest_ptr                 = 0;
    ui_dest_base                = 0;
    ui_text_width               = 0;
    ui_width_left               = 0;
    ui_line_no                  = 0;

    ui_set_pos(0, MENU_CLOSED_Y);

    avatar_enabled              = 0;
    menu_enabled                = 0;
    win_speed                   = 1;
    text_drawn                  = TRUE;
    text_draw_speed             = 1;

    ui_load_tiles();
}

void ui_load_tiles() __banked {
    ui_load_frame_tiles(frame_image, BANK(frame_image));
    ui_load_cursor_tile(cursor_image, BANK(cursor_image));

    memset(vwf_tile_data, TEXT_BKG_FILL_W, 16);
    set_bkg_data(ui_while_tile, 1, vwf_tile_data);
    memset(vwf_tile_data, TEXT_BKG_FILL_B, 16);
    set_bkg_data(ui_black_tile, 1, vwf_tile_data);
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

static void ui_print_reset(UBYTE tile) {
    ui_current_tile = tile;
    vwf_current_offset = 0;
    memset(vwf_tile_data, text_bkg_fill, sizeof(vwf_tile_data));
}

void ui_print_shift_char(void * dest, const void * src, UBYTE bank) __nonbanked;

static UBYTE ui_print_render(const unsigned char ch) {
    UBYTE letter = ReadBankedUBYTE(vwf_current_font_desc.recode_table + (ch & ((vwf_current_font_desc.attr & RECODE_7BIT) ? 0x7fu : 0xffu)), vwf_current_font_bank);
    const UBYTE * bitmap = vwf_current_font_desc.bitmaps + letter * 16u;
    if (vwf_current_font_desc.attr & FONT_VWF) {
        vwf_inverse_map = (vwf_current_font_desc.attr & FONT_VWF_1BIT) ? text_bkg_fill : 0;
        UBYTE width = ReadBankedUBYTE(vwf_current_font_desc.widths + letter, vwf_current_font_bank);
        UBYTE dx = (8u - vwf_current_offset);
        vwf_current_mask = (0xffu << dx) | (0xffu >> (vwf_current_offset + width));

        vwf_current_rotate = vwf_current_offset;
        ui_print_shift_char(vwf_tile_data, bitmap, vwf_current_font_bank);
        if ((UBYTE)(vwf_current_offset + width) > 8u) {
            vwf_current_rotate = dx | 0x80u;
            vwf_current_mask = 0xffu >> (width - dx);
            ui_print_shift_char(vwf_tile_data + 16u, bitmap, vwf_current_font_bank);
        }
        vwf_current_offset += width;

        set_bkg_data(ui_current_tile, 1, vwf_tile_data);
        if (vwf_current_offset > 7u) {
            memcpy(vwf_tile_data, vwf_tile_data + 16u, 16);
            memset(vwf_tile_data + 16u, text_bkg_fill, 16);
            vwf_current_offset -= 8u;
            ui_current_tile++;
            if (vwf_current_offset) set_bkg_data(ui_current_tile, 1, vwf_tile_data);
            return TRUE;
        } 
        return FALSE;
    } else {
        SetBankedBkgData(ui_current_tile++, 1, bitmap, vwf_current_font_bank);
        vwf_current_offset = 0;
        return TRUE;
    }
}

static void ui_draw_text_buffer_char() __banked {
    if ((text_ff_joypad) && (INPUT_A_OR_B_PRESSED)) text_ff = TRUE;

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
        ui_print_reset(((avatar_enabled) ? (UBYTE)(TEXT_BUFFER_START + 4) : TEXT_BUFFER_START));
    }

    switch (*ui_text_ptr) {
        case 0x00:
            ui_text_ptr = 0; 
            text_drawn = TRUE;
            return;
        case 0x01:
            current_text_speed = ui_time_masks[*++ui_text_ptr] & 0x1fu;
            break;
        case 0x02:
            //font_image_ptr = ui_fonts[*++ui_text_ptr - 0x01u];
            ++ui_text_ptr;
            MemcpyBanked(&vwf_current_font_desc, ui_fonts[*ui_text_ptr - 0x01u].ptr, sizeof(font_desc_t), ui_fonts[*ui_text_ptr - 0x01u].bank);
            break;
        case 0x03:
            ui_dest_ptr = ui_dest_base = GetWinAddr() + *++ui_text_ptr * 32 + *++ui_text_ptr;
            if (vwf_current_offset) ui_print_reset(ui_current_tile + 1u);
            break; 
        case '\n':
            ui_line_no++;
            if (menu_enabled && (menu_layout == MENU_LAYOUT_2_COLUMN) && (ui_line_no == 4u)) {
                ui_dest_base = GetWinAddr() + 32 + 1 + 9;
                ui_dest_ptr = ui_dest_base;
            } else {
                ui_dest_ptr = ui_dest_base += 32;
            }
            if (vwf_current_offset) ui_print_reset(ui_current_tile + 1u);
            break; 
        default:
            if (ui_print_render(*ui_text_ptr)) {
                SetTile(ui_dest_ptr++, ui_current_tile - 1);
            }
            if (vwf_current_offset) SetTile(ui_dest_ptr, ui_current_tile);
            break;
    }
    ui_text_ptr++;
}

void ui_update() __nonbanked {
    UBYTE is_moving = FALSE;

    if (game_time & ui_time_masks[win_speed]) return;

    // y should always move first
    if (win_pos_y != win_dest_pos_y) {
        UBYTE interval = (win_speed == 1) ? 2 : 1;
        // move window up/down
        if (win_pos_y < win_dest_pos_y) win_pos_y += interval; else win_pos_y -= interval;
        is_moving = TRUE;
    }
    if (win_pos_x != win_dest_pos_x) {
        UBYTE interval = (win_speed == 1) ? 2 : 1;
        // move window left/right
        if (win_pos_x < win_dest_pos_x) win_pos_x += interval; else win_pos_x -= interval;
        is_moving = TRUE;
    }

    // don't draw text while moving
    if (is_moving) return;
    // all drawn - nothing to do
    if (text_drawn) return;
    // too fast - wait
    if ((!INPUT_A_OR_B_PRESSED) && game_time & current_text_speed) return;
    // render next char
    do {
        ui_draw_text_buffer_char();
    } while (((text_ff) || (current_text_speed == 0)) && (!text_drawn));
}

UBYTE ui_run_menu(menu_item_t * start_item, UBYTE bank, UBYTE options, UBYTE count) __banked {
    menu_item_t current_menu_item;
    UBYTE current_index = 0, next_index = 0;
    // copy first menu item
    MemcpyBanked(&current_menu_item, start_item, sizeof(menu_item_t), bank);
    // draw menu cursor
    set_win_tile_xy(current_menu_item.X, current_menu_item.Y, ui_cursor_tile);
    while (TRUE) {
        input_update();
        ui_update();
        
        toggle_shadow_OAM();
        actors_update();
        projectiles_render();
        activate_shadow_OAM();

        game_time++;
        wait_vbl_done();

        if (INPUT_UP_PRESSED) {
            next_index = current_menu_item.iU;
        } else if (INPUT_DOWN_PRESSED) {
            next_index = current_menu_item.iD;
        } else if (INPUT_LEFT_PRESSED) {
            next_index = current_menu_item.iL;
        } else if (INPUT_RIGHT_PRESSED) {
            next_index = current_menu_item.iR;
        } else if (INPUT_A_PRESSED) {
            return ((current_index == count) && (options & MENU_CANCEL_LAST)) ? 0u : current_index;
        } else if ((INPUT_B_PRESSED) && (options & MENU_CANCEL_B))  {
            return 0u;
        } else {
            continue;
        }

        if (!next_index) continue;

        // update current index
        current_index = next_index--;
        // erase old cursor
        set_win_tile_xy(current_menu_item.X, current_menu_item.Y, ui_bg_tile);
        // read menu data
        MemcpyBanked(&current_menu_item, start_item + next_index, sizeof(menu_item_t), bank);
        // put new cursor
        set_win_tile_xy(current_menu_item.X, current_menu_item.Y, ui_cursor_tile);
        // reset next index
        next_index = 0;
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

        toggle_shadow_OAM();
        actors_update();
        projectiles_render();
        activate_shadow_OAM();

        game_time++;
        wait_vbl_done();
        input_update();
    } while (fail);    
}

void ui_draw_avatar(spritesheet_t *avatar, UBYTE avatar_bank) __banked {
    UBYTE *avatar_ui_ptr = GetWinAddr() + 32 + 1;
    SetBankedBkgData(TEXT_BUFFER_START, AVATAR_TILE_SIZE, avatar->tiles, avatar_bank);
    set_win_tiles(1, 1, 2, 2, avatar_tiles);
}
