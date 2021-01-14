.include "global.s"

.area _CODE

; void get_map_from_buf(UBYTE x, UBYTE y, UBYTE w, UBYTE h, unsigned char * dest, unsigned char * buf, UBYTE buf_w, UBYTE buf_h)

_get_map_from_buf::
        push    BC          ; bc, ret, x, y, w, h, dest, buf, buf_w, buf_h
                            ; 0   2    4  5  6  7  8     10   12     13 
        ldhl    SP, #4    
        ld      D, (HL)     ; D = x
        inc     HL
        ld      E, (HL)     ; E = y
        ldhl    SP, #9
        ld      B, (HL)     ; BC = dest
        dec     HL
        ld      C, (HL)
        dec     HL
        ld      A, (HL-)    ; A = h
        ld      H, (HL)     ; H = w
        ld      L, A        ; L = h

        ld      A, H        ; check x bound
        add     D
        push    HL
        ldhl    SP, #14     ; &buf_w
        cp      (HL)        ; buf_w
        jr      C, 8$
        ld      A, D
        cp      (HL)        ; buf_w
        jp      NC, 9$
        ld      A, (HL)     ; buf_w
        sub     D
        pop     HL
        ld      H, A
        jr      1$
8$:
        pop     HL
1$:
        ld      A, L        ; check y bound
        add     E
        push    HL
        ldhl    SP, #15     ; &buf_h
        cp      (HL)        ; buf_h
        jr      C, 10$
        ld      A, E
        cp      (HL)        ; buf_h
        jp      NC, 9$
        ld      A, (HL)     ; buf_h
        sub     E
        pop     HL
        ld      L, A
        jr      7$
10$:
        pop     HL
7$:
        push    HL          ; Store WH
        
        ldhl    SP, #12     ; HL = origin
        ld      A, (HL+)
        ld      H, (HL)
        ld      L, A
2$:
        push    BC          ; Store dest
        xor     A
        or      E
        jr      Z, 3$

        push    HL
        ldhl    SP, #18     ; &buf_w
        xor     A
        ld      B, A
        ld      C, (HL)     ; buf_w

        pop     HL
11$:                        ; MUL BC by E and add reault to HL
        srl     E
        jr      NC, 12$
        add     HL, BC
12$:
        jr      Z, 3$       ; early exit
        sla     C
        rl      B
        jr      11$
3$:
        ld      B, A
        ld      C, D        ; BC = X coordinate
        add     HL, BC

        pop     BC          ; BC = dest
        pop     DE          ; DE = WH
        
        push    HL          ; Store origin
        push    DE          ; Store WH
        push    BC
16$:
        srl     D
        jr      NC, 14$

        ld      A, (HL+)    ; copy one byte
        ld      (BC), A
        inc     BC
14$:
        jr      Z, 15$
5$:
        ld      A, (HL+)    ; copy two bytes
        ld      (BC), A
        inc     BC
        ld      A, (HL+)
        ld      (BC), A
        inc     BC
        
        dec     D
        jr      NZ,5$
15$:
        pop     BC
        
        pop     HL          ; HL = WH
        ld      D,H         ; Restore D = W
        pop     HL          ; HL = origin
        dec     E
        jr      Z,6$

        push    HL          ; Next line
        ldhl    SP, #14   
        ld      A, (HL)     ; buf_w
        pop     HL
        add     L
        ld      L, A
        ld      A, H
        adc     #0
        ld      H, A
        
        push    HL
        ldhl    SP, #8
        ld      L, (HL)
        
        ld      H, #0
        add     HL, BC
        ld      B, H
        ld      C, L
        pop     HL
        push    HL          ; Store current origin

        push    DE          ; Store WH
        push    BC
        
        jr      16$
9$:
        pop     HL                 
6$:
        pop     BC
        ret
