.include "global.s"

.area _CODE

.globl _image_tile_width
.globl _image_tile_height

.globl _set_bkg_tiles

; void get_map_from_buf(UBYTE x, UBYTE y, UBYTE w, UBYTE h, unsigned char * dest, unsigned char * image)

.map_save_w:    .ds 1
.map_save_h:    .ds 1

_map_to_screen::
        ldhl    sp, #4
        ld      a, (hl+)
        ld      (#.map_save_w), a
        ld      a, (hl)
        ld      (#.map_save_h), a
        call    _get_map_from_buf
        ldhl    sp, #2
        ld      a, (hl)
        and     #31
        ld      (hl+), a
        ld      a, (hl)
        and     #31
        ld      (hl+), a
        ld      a, (#.map_save_w)
        ld      (hl+), a
        ld      a, (#.map_save_h)
        ld      (hl), a
        jp      _set_bkg_tiles

_get_map_from_buf::
        push    bc          ; bc, ret, x, y, w, h, dest, image
                            ; 0   2    4  5  6  7  8     10 
        ldhl    sp, #4    
        ld      d, (hl)     ; d = x
        inc     hl
        ld      e, (hl)     ; e = y
        ldhl    sp, #9
        ld      b, (hl)     ; bc = dest
        dec     hl
        ld      c, (hl)
        dec     hl
        ld      a, (hl-)    ; a = h
        ld      h, (hl)     ; h = w
        ld      l, a        ; l = h

        ld      a, h        ; check x bound
        add     d
        jr      nc, 18$
        ld      a, #0xff
18$:
        push    hl
        ld      hl, #_image_tile_width
        cp      (hl)        ; _image_tile_width
        jr      c, 8$
        ld      a, d
        cp      (hl)        ; _image_tile_width
        jp      nc, 9$
        ld      a, (hl)     ; _image_tile_width
        sub     d
        pop     hl
        ld      h, a
        jr      1$
8$:
        pop     hl
1$:
        ld      a, l        ; check y bound
        add     e
        jr      nc, 17$
        ld      a, #0xff
17$:
        push    hl
        ld      hl, #_image_tile_height
        cp      (hl)        ; _image_tile_height
        jr      c, 10$
        ld      a, e
        cp      (hl)        ; _image_tile_height
        jp      nc, 9$
        ld      a, (hl)     ; _image_tile_height
        sub     e
        pop     hl
        ld      l, a
        jr      7$
10$:
        pop     hl
7$:
        push    hl          ; store wh
        
        ldhl    sp, #12     ; hl = image
        ld      a, (hl+)
        ld      h, (hl)
        ld      l, a
2$:
        push    bc          ; store dest
        xor     a
        or      e
        jr      z, 3$

        ld      a, (#_image_tile_width)
        ld      c, a
        xor     a
        ld      b, a
11$:                        ; mul bc by e and add reault to hl
        srl     e
        jr      nc, 12$
        add     hl, bc
12$:
        jr      z, 3$       ; early exit
        sla     c
        rl      b
        jr      11$
3$:
        ld      b, a
        ld      c, d        ; bc = x coordinate
        add     hl, bc

        pop     bc          ; bc = dest
        pop     de          ; de = wh
        
        push    hl          ; store origin
        push    de          ; store wh
        push    bc
16$:
        srl     d
        jr      nc, 14$

        ld      a, (hl+)    ; copy one byte
        ld      (bc), a
        inc     bc
14$:
        jr      z, 15$
5$:
        ld      a, (hl+)    ; copy two bytes
        ld      (bc), a
        inc     bc
        ld      a, (hl+)
        ld      (bc), a
        inc     bc
        
        dec     d
        jr      nz,5$
15$:
        pop     bc
        
        pop     hl          ; hl = wh
        ld      d,h         ; restore d = w
        pop     hl          ; hl = origin
        dec     e
        jr      z,6$

        ld      a, (#_image_tile_width)
        add     l
        ld      l, a
        ld      a, h
        adc     #0
        ld      h, a
        
        push    hl
        ldhl    sp, #8
        ld      l, (hl)
        
        ld      h, #0
        add     hl, bc
        ld      b, h
        ld      c, l
        pop     hl
        push    hl          ; store current origin

        push    de          ; store wh
        push    bc
        
        jr      16$
9$:
        pop     hl                 
6$:
        pop     bc
        ret
