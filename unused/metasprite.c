
#include "metasprite.h"

UINT8 hide_sprites = FALSE;

UBYTE __render_shadow_OAM = (UWORD)&shadow_OAM >> 8;

const void * __current_metasprite;
UBYTE __current_base_tile;

UBYTE __move_metasprite(UINT8 id, UINT8 x, UINT8 y) __naked __nonbanked {
    id; x; y; 
__asm
        ldhl    sp, #4
        ld      a, (hl-)
        ld      b, a
        ld      a, (hl-)
        ld      c, a
        ld      a, (hl-)
        add     a
        add     a
        ld      e, a

        ld      hl, #___current_metasprite
        ld      a, (hl+)
        ld      h, (hl)
        ld      l, a
        push    hl
        inc     hl 

        ld      a, (___render_shadow_OAM)
        ld      d, a

        ld      a, (hl+)
        inc     a
1$:
        dec     a
        add     a
        add     a
        add     e
        ld      e, a

        ld      a, (hl+)    ; dy
        add     b
        ld      (de), a
        inc     e

        ld      a, (hl+)    ; dx
        add     c
        ld      (de), a
        inc     e

        ld      a, (#___current_base_tile)
        add     (hl)        ; tile
        inc     hl
        ld      (de), a
        inc     e

        ld      a, (hl+)    ; props
        ld      (de), a
        inc     e

        ld      a, (hl+)
        or      a
        jr      nz, 1$

        pop     hl
        ld      e, (hl)

        ret
__endasm;
}

void hide_hardware_sprites(UINT8 from, UINT8 to) __naked __nonbanked {
    from; to;
__asm
        ldhl    sp, #2
        ld      a, (hl+)

        add     a
        add     a
        ld      d, a

        ld      a, (hl-)
        sub     (hl)
        ld      e, a

        ret     c
        ret     z

        ld      bc, #4

        ld      a, (___render_shadow_OAM)
        ld      h, a
        ld      l, d

        xor     a
1$:
        ld      (hl), a
        add     hl, bc

        dec     e
        jr      nz, 1$

        ret
__endasm;
}
