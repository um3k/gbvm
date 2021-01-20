
#include "metasprite.h"

const void * __current_metasprite;
UBYTE __current_base_tile;

void __move_metasprite(UINT8 id, UINT8 x, UINT8 y) __naked {
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

        ld      d, #>_shadow_OAM

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

        ret
__endasm;
}

void __hide_metasprite(UINT8 id) __naked {
    id; 
__asm
        ldhl    sp, #2
        ld      a, (hl-)
        add     a
        add     a
        ld      e, a

        ld      hl, #___current_metasprite
        ld      a, (hl+)
        ld      h, (hl)
        ld      l, a 

        ld      bc, #4

        ld      d, #>_shadow_OAM

        ld      a, (hl+)
        inc     a
1$:
        dec     a
        add     a
        add     a
        add     e
        ld      e, a

        xor     a
        ld      (de), a

        inc     e
        inc     e
        inc     e
        inc     e
        add     hl, bc
       
        ld      a, (hl+)
        or      a
        jr      nz, 1$

        ret
__endasm;
}
