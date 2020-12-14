#ifndef UI_H
#define UI_H

#include <gb/gb.h>

#define TEXT_BUFFER_START 0xCCU
#define AVATAR_WIDTH 2
#define SELECTOR_WIDTH 1
#define AVATAR_TILE_SIZE 4
#define MENU_OPEN_Y 112
#define WIN_LEFT_X 7
#define MENU_CLOSED_Y (MAXWNDPOSY + 1U)
#define TEXT_BUFFER_START 0xCCU
#define MENU_LAYOUT_INITIAL_X 88
#define MENU_CANCEL_ON_LAST_OPTION 0x01U
#define MENU_CANCEL_ON_B_PRESSED 0x02U

#define ui_bkg_tile   0x07u
#define ui_while_tile 0xC9u
#define ui_black_tile 0xCAu

#define ui_cursor_tile 0xCBu
#define ui_bg_tile 0xC4u

extern UBYTE win_pos_x;
extern UBYTE win_pos_y;
extern UBYTE win_dest_pos_x;
extern UBYTE win_dest_pos_y;
extern UBYTE win_speed;

extern UBYTE text_drawn;
extern UBYTE text_wait;
extern UBYTE text_line_count;

extern UBYTE avatar_enabled;

extern unsigned char ui_text_data[80];

void ui_init() __banked;
void ui_update() __nonbanked;  // critical path, __nonbanked for speed

#define UI_WAIT_WINDOW  1
#define UI_WAIT_TEXT    2
#define UI_WAIT_BTN_A   4
#define UI_WAIT_BTN_B   8
#define UI_WAIT_BTN_ANY 16

void ui_run_modal(UBYTE wait_flags) __banked;  // process UI until closed

inline void ui_set_pos(UBYTE x, UBYTE y) {
    win_pos_x = win_dest_pos_x = x;
    win_pos_y = win_dest_pos_y = y;
}

inline void ui_move_to(UBYTE x, UBYTE y, UBYTE speed) {
    win_dest_pos_x = x;
    win_dest_pos_y = y;
    if (speed == 0) win_pos_x = x, win_pos_y = y; else win_speed = speed;
}

#endif
