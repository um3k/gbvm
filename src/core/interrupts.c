#include <gb/gb.h>

#include "Scroll.h"
#include "metasprite.h"
#include "UI.h"

void simple_LCD_isr() __nonbanked {
    if (LYC_REG == 0) {
        SCX_REG = draw_scroll_x;
        SCY_REG = draw_scroll_y;
        if (!hide_sprites) SHOW_SPRITES;
        LYC_REG = win_pos_y;
    } else {
        LYC_REG = 0;
        if (hide_sprites) return;
        if ((LY_REG < SCREENHEIGHT) && (WX_REG == 7u)) HIDE_SPRITES;
    }
}

void fullscreen_LCD_isr() __nonbanked {
    if (LYC_REG == 0) {
        LCDC_REG &= 0b11101111;
        SCX_REG = draw_scroll_x;
        SCY_REG = draw_scroll_y;
        if (!hide_sprites) SHOW_SPRITES;
        LYC_REG = (9 * 8) - 1;    
    } else {
        LCDC_REG |= 0b00010000;
        LYC_REG = 0;
    }
}

void VBL_isr() __nonbanked {
    if ((win_pos_y < MAXWNDPOSY) && (win_pos_x < SCREENWIDTH - 1)) {
        WX_REG = win_pos_x + 7u;
        WY_REG = win_pos_y;
        SHOW_WIN;
    } else {
        HIDE_WIN;
    }
}
