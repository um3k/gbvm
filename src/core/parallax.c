#include "parallax.h"

parallax_row_t parallax_rows[3] = { PARALLAX_STEP(0, 3, 8), PARALLAX_STEP(3, 6, 2), PARALLAX_STEP(6, 0, 0)};
parallax_row_t * parallax_row;

void parallax_LCD_isr() __naked __nonbanked {
__asm
        push af
        push hl
        push bc

        ld hl, #_parallax_row
        ld a, (hl+)
        ld h, (hl)
        ld l, a
        ldh a, (#_LYC_REG)
        cp (hl)
        jr nz, 1$
        inc hl

        ld a, (hl+)
        ldh (#_LYC_REG), a
        or a
        ld a, (hl+)
        ld c, a                         ; c = shift
        jr nz, 2$

        ld a, #<_parallax_rows
        ld (#_parallax_row), a
        ld a, #>_parallax_rows
        ld (#_parallax_row + 1), a
        jr 3$
2$:
        ld a, l   
        ld (#_parallax_row), a
        ld a, h
        ld (#_parallax_row + 1), a
3$:     
        ld a, c
        or a
        jr z, 4$
        add a
        add c
        ld c, a                         ; c = shift * 3 

        ld hl, #6$
        ld a, l
        sub c
        ld l, a
        sbc a
        add h
        ld h, a                         ; hl = $6 - c

        ld a, (#_draw_scroll_x + 1)
        ld c, a
        ld a, (#_draw_scroll_x)         ; ac = draw_scroll_x

        jp (hl)                         ; jump into unrolled shift

        .rept 8
            srl c
            rra
        .endm
6$:
        ldh (#_SCX_REG), a
        xor a
        ldh (#_SCY_REG), a
        jr 5$
4$:
        ld a, (#_draw_scroll_x)
        ldh (#_SCX_REG), a
        ld a, (#_draw_scroll_y)
        ldh (#_SCY_REG), a
        jr 5$
1$:
        ld a, (hl)
        ldh (#_LYC_REG), a
5$:
        pop bc
        pop hl
7$:
        ldh a, (#_STAT_REG)
        and #0x02
        jr nz, 7$

        pop af
        reti
__endasm;
}
