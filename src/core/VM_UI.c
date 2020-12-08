#pragma bank 2

#include <string.h>
#include <stdlib.h>

#include "vm.h"

extern UBYTE text_drawn;
extern UBYTE text_count;
extern UBYTE text_tile_count;
extern UBYTE text_wait;
extern UBYTE text_num_lines;

extern unsigned char ui_text_data[80];

void ui_draw_frame(UBYTE x, UBYTE y, UBYTE width, UBYTE height) __banked;

// prints debug string into the text buffer then outputs to screen
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
                case 'd':
                    idx = *((INT16 *)args);
                    if (idx < 0) idx = *(THIS->stack_ptr + idx); else idx = script_memory[idx];
                    d += strlen(itoa(idx, d));
                    s++;
                    args += 2;
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

    SWITCH_ROM_MBC1(_save);
    THIS->PC = s;
}

void vm_display_text(SCRIPT_CTX * THIS) __banked {
    THIS;    
    text_drawn = FALSE;
    text_count = 0;
    text_tile_count = 0;
    text_wait = 0;
    text_num_lines = 3;
    ui_draw_frame(0, 0, 19, 4);
}
