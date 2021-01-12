#include "parallax.h"

parallax_row_t parallax_rows[3] = { PARALLAX_STEP(3, 4), PARALLAX_STEP(6, 2), PARALLAX_STEP(0, 0)};
parallax_row_t * parallax_row;

void parallax_LCD_isr() __naked __nonbanked {
__asm
        ld hl, #_parallax_row
        ld a, (hl+)
        ld h, (hl)
        ld l, a
1$:
        ldh a, (#_STAT_REG)
        and #0x02
        jr nz, 1$

        ld a, (hl+)             ; scx
        ld (#_SCX_REG), a
        ld a, (hl)              ; next y
        or a
        jr nz, 2$

        ld a, (#_draw_scroll_y)
        ldh (#_SCY_REG), a
        jr 3$
2$:
        xor a
        ldh (#_SCY_REG), a
3$:
        ld a, (hl+)             ; next y
        ldh (#_LYC_REG), a
        or a
        jr z, 4$
        inc hl                  ; skip shift

        ld a, l   
        ld (#_parallax_row), a
        ld a, h
        ld (#_parallax_row + 1), a
        ret
4$:
        ld a, #<_parallax_rows
        ld (#_parallax_row), a
        ld a, #>_parallax_rows
        ld (#_parallax_row + 1), a
        ret
__endasm;
}
