#pragma bank 2

#include <string.h>
#include <stdlib.h>

#include "vm.h"
#include "UI.h"
#include "Sprite.h"
#include "Input.h"

void ui_draw_frame(UBYTE x, UBYTE y, UBYTE width, UBYTE height) __banked;
void ui_draw_avatar(spritesheet_t *avatar, UBYTE avatar_bank) __banked;

// renders UI text into buffer
void vm_load_text(UWORD dummy0, UWORD dummy1, SCRIPT_CTX * THIS, UBYTE nargs) __nonbanked {
    dummy0; dummy1; // suppress warnings

    UBYTE _save = _current_bank;
    SWITCH_ROM_MBC1(THIS->bank);
    
    const UBYTE * args = THIS->PC;
    unsigned char * d = ui_text_data; 
    const unsigned char * s = args + (nargs << 1);
    INT16 idx;

    while (*s) {
        if (*s == '%') {
            s++;
            switch (*s) {
                // variable value
                case 'd':
                    idx = *((INT16 *)args);
                    if (idx < 0) idx = *(THIS->stack_ptr + idx); else idx = script_memory[idx];
                    d += strlen(itoa(idx, d));
                    s++;
                    args += 2u;
                    continue;
                // char from variable
                case 'c':
                    idx = *((INT16 *)args);
                    if (idx < 0) idx = *(THIS->stack_ptr + idx); else idx = script_memory[idx];
                    *d++ = (unsigned char)idx;
                    s++;
                    args += 2u;
                    continue;
                // text tempo from variable
                case 't':
                    idx = *((INT16 *)args);
                    if (idx < 0) idx = *(THIS->stack_ptr + idx); else idx = script_memory[idx];
                    *d++ = (unsigned char)idx + 0x10u;
                    s++;
                    args += 2u;
                    continue;
                case '%':
                    break;
                default:
                    s--;
            }
        }
        *d++ = *s++;
    }
    *d = 0, s++;

    // count newlines (no wrapping)
    text_line_count = 1;
    for (UBYTE * i = ui_text_data; (*i); i++)
        if (*i == '\n') text_line_count++;

    SWITCH_ROM_MBC1(_save);
    THIS->PC = s;
}

// start displaying text
void vm_display_text(SCRIPT_CTX * THIS, UBYTE avatar_bank, spritesheet_t *avatar) __banked {
    THIS;

    text_drawn = FALSE;
    text_wait  = FALSE;
    text_ff    = FALSE;
    
    avatar_enabled = (avatar_bank != 0);

    INT8 width = 20 - (win_dest_pos_x >> 3);
    if (width > 2) {
        // don't draw if too small 
        ui_draw_frame(0, 0, width - 1, text_line_count);
        if (avatar_enabled) {
            ui_draw_avatar(avatar, avatar_bank);
        }
    }
}

// set position of overlayed window
void vm_overlay_setpos(SCRIPT_CTX * THIS, UBYTE pos_x, UBYTE pos_y) __banked {
    THIS;
    ui_set_pos(pos_x << 3, pos_y << 3);
}

// hides overlayed window
void vm_overlay_hide() __banked {
    ui_set_pos(0, MENU_CLOSED_Y);
}

// wait until overlay window reaches destination
void vm_overlay_wait(SCRIPT_CTX * THIS, UBYTE is_modal, UBYTE wait_flags) __banked {
    if (is_modal) {
        ui_run_modal(wait_flags);
        return;
    }

    UBYTE fail = 0;
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

    if (fail) {
        THIS->waitable = 1;
        THIS->PC -= INSTRUCTION_SIZE + sizeof(is_modal) + sizeof(wait_flags);
    }
}

// set position of overlayed window
void vm_overlay_move_to(SCRIPT_CTX * THIS, UBYTE pos_x, UBYTE pos_y, UBYTE speed) __banked {
    THIS;
    ui_move_to(pos_x << 3, pos_y << 3, speed);
}

// clears overlay window
void vm_overlay_clear(SCRIPT_CTX * THIS, UBYTE color) __banked {
    THIS;
    fill_win_rect(0, 0, 20, 18, ((color) ? ui_while_tile : ui_black_tile));
}

// shows overlay
void vm_overlay_show(SCRIPT_CTX * THIS, UBYTE pos_x, UBYTE pos_y, UBYTE color) __banked {
    THIS;
    vm_overlay_clear(THIS, color);
    ui_set_pos(pos_x << 3, pos_y << 3);
}
