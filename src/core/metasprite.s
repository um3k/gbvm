        .include    "global.s"

        .title  "Metasprites"
        .module Metasprites

        .area   _DATA

___current_metasprite:: 
        .ds 0x02
___current_base_tile::
        .ds 0x01
___render_shadow_OAM::
        .ds     0x01
_hide_sprites::
	.ds 	0x01

        .area   _GSINIT

        ld      a, #>_shadow_OAM
        ld      (___render_shadow_OAM), a
        xor     a
        ld      (_hide_sprites), a

        .area   _CODE

; UBYTE __move_metasprite(UINT8 id, UINT8 x, UINT8 y)

___move_metasprite::
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
1$:
        ld      a, (hl+)    ; dy
        cp      #0x80
        jr      z, 2$
        add     b
        ld      b, a
        ld      (de), a
        inc     e

        ld      a, (hl+)    ; dx
        add     c
        ld      c, a
        ld      (de), a
        inc     e

        ld      a, (___current_base_tile)
        add     (hl)        ; tile
        inc     hl
        ld      (de), a
        inc     e

        ld      a, (hl+)    ; props
        ld      (de), a
        inc     e

        jr      1$

2$:
        pop     hl
        ld      e,(hl)

        ret

___move_metasprite_hflip::
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
1$:
        ld      a, (hl+)
        cp      #0x80
        jr      z, 2$
        cpl
        inc     a
        add     b
        ld      b, a
        ld      (de), a
        inc     e

        ld      a, (hl+)    ; dx
        add     c
        ld      c, a
        ld      (de), a
        inc     e

        ld      a, (___current_base_tile)
        add     (hl)        ; tile
        inc     hl
        ld      (de), a
        inc     e

        ld      a, (hl+)    ; props
        xor     #0x40
        ld      (de), a
        inc     e

        jr      1$

2$:
        pop     hl
        ld      e,(hl)

        ret

___move_metasprite_vflip::
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
1$:
        ld      a, (hl+)    ; dy
        cp      #0x80
        jr      z, 2$
        add     b
        ld      b, a
        ld      (de), a
        inc     e

        ld      a, (hl+)    ; dx
        cpl
        inc     a
        add     c
        ld      c, a
        ld      (de), a
        inc     e

        ld      a, (___current_base_tile)
        add     (hl)        ; tile
        inc     hl
        ld      (de), a
        inc     e

        ld      a, (hl+)    ; props
        xor     #0x20
        ld      (de), a
        inc     e

        jr      1$

2$:
        pop     hl
        ld      e,(hl)

        ret

___move_metasprite_hvflip::
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
1$:
        ld      a, (hl+)
        cp      #0x80
        jr      z, 2$
        cpl
        inc     a
        add     b
        ld      b, a
        ld      (de), a
        inc     e

        ld      a, (hl+)    ; dx
        cpl
        inc     a
        add     c
        ld      c, a
        ld      (de), a
        inc     e

        ld      a, (___current_base_tile)
        add     (hl)        ; tile
        inc     hl
        ld      (de), a
        inc     e

        ld      a, (hl+)    ; props
        xor     #0x60
        ld      (de), a
        inc     e

        jr      1$

2$:
        pop     hl
        ld      e,(hl)

        ret

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

        xor     a
1$:
        ld      (hl), a
        add     hl, bc

        dec     e
        jr      nz, 1$

        ret
