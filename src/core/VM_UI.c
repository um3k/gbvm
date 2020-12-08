#pragma bank 2

#include <string.h>
#include <stdlib.h>

#include "vm.h"

extern UBYTE text_drawn;
extern UBYTE text_wait;
extern UBYTE text_num_lines;
extern UBYTE avatar_enabled;

extern unsigned char ui_text_data[80];

void ui_draw_frame(UBYTE x, UBYTE y, UBYTE width, UBYTE height) __banked;

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
                // variable by index
                case 'd':
                    idx = *((INT16 *)args);
                    if (idx < 0) idx = *(THIS->stack_ptr + idx); else idx = script_memory[idx];
                    d += strlen(itoa(idx, d));
                    s++;
                    args += 2;
                    continue;
                // text tempo
                case 't':
                    *d++ = *((UINT8 *)args) + 0x10;
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

void vm_display_text(SCRIPT_CTX * THIS, UBYTE avatar_index) __banked {
    THIS;
    text_drawn = FALSE;
    text_wait = 0;
    text_num_lines = 3;
    avatar_enabled = (avatar_index != 0);
    ui_draw_frame(0, 0, 19, 4);
}
