.include "global.s"

.area _CODE

; void get_map_from_buf(UBYTE x, UBYTE y, UBYTE w, UBYTE h, unsigned char * dest, unsigned char * buf, UBYTE buf_w, UBYTE buf_h)

_get_map_from_buf::
        push    bc          ; bc, ret, x, y, w, h, dest, buf, buf_w, buf_h
                            ; 0   2    4  5  6  7  8     10   12     13 
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
        ldhl    sp, #14     ; &buf_w
        cp      (hl)        ; buf_w
        jr      c, 8$
        ld      a, d
        cp      (hl)        ; buf_w
        jp      nc, 9$
        ld      a, (hl)     ; buf_w
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
        ldhl    sp, #15     ; &buf_h
        cp      (hl)        ; buf_h
        jr      c, 10$
        ld      a, e
        cp      (hl)        ; buf_h
        jp      nc, 9$
        ld      a, (hl)     ; buf_h
        sub     e
        pop     hl
        ld      l, a
        jr      7$
10$:
        pop     hl
7$:
        push    hl          ; store wh
        
        ldhl    sp, #12     ; hl = origin
        ld      a, (hl+)
        ld      h, (hl)
        ld      l, a
2$:
        push    bc          ; store dest
        xor     a
        or      e
        jr      z, 3$

        push    hl
        ldhl    sp, #18     ; &buf_w
        xor     a
        ld      b, a
        ld      c, (hl)     ; buf_w

        pop     hl
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

        push    hl          ; next line
        ldhl    sp, #14   
        ld      a, (hl)     ; buf_w
        pop     hl
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
