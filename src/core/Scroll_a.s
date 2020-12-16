.LCDC = 0xFF40
.STAT = 0xFF41

.macro WAIT_STAT ?lbl
lbl:	LDH	A, (.STAT)
        AND	#0x02		; Check if in LCD modes 0 or 1
        JR 	NZ, lbl
.endm

.area _CODE

_SetTile::
        ; de = addr, hl = &t
        ldhl    sp,#2
        ld      a,(hl+)
        ld      e, a
        ld      a,(hl+)
        ld      d, a

        WAIT_STAT

        ; Write tile
        ld      a,(hl)
        ld      (de),a
        ret

_set_win_tile_xy::
        call    _GetWinAddr
        jr      .set_tile_xy
_set_bkg_tile_xy::
        call    _GetBkgAddr
.set_tile_xy:
        push    bc
        ldhl    sp,#4

        ld      a, (hl+)
        ld      b, a
        ld      a, (hl+)
        ld      c, a            ; bc = xy

        ld      e, d
        swap    c
        rlc	c
        ld      a, c
        and     #0x03
        add     e
        ld      d, a
        ld      a, #0xE0
        and     c
        add     b
        ld      e, a		; dest DE = BASE + 0x20 * Y + X

        WAIT_STAT
        ld      a, (hl)
        ld      (de), a

        pop     bc
        ret

_WaitForMode0Or1::
        WAIT_STAT
        ret

_GetWinAddr::
        ldh     a,(.LCDC)
        bit     6,a
        jr      Z,.is98
        jr      .is9c

_GetBkgAddr::
        ldh     a,(.LCDC)
        bit     3,a
        jr      NZ,.is9c
.is98:
        ld      DE,#0x9800	; DE = origin
        ret
.is9c:
        ld      DE,#0x9C00	; DE = origin
        ret
