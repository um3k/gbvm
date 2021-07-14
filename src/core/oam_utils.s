        .include    "global.s"

        .title  "OAM utilities"
        .module OAM_utils

        .globl  ___render_shadow_OAM

        .area   _CODE

; void hide_hardware_sprites(UINT8 from, UINT8 to)

_hide_hardware_sprites::
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

        ld      a, e
        ld      e, b            ; b is 0

        rra                     ; carry is never set here, because of ret c above
        jr      nc, 1$

        ld      (hl), e
        add     hl, bc

        ret     z               ; z is not affected by add hl, bc

1$:
        ld      (hl), e
        add     hl, bc

        ld      (hl), e
        add     hl, bc

        dec     a
        jr      nz, 1$

        ret
