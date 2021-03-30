#pragma bank 3

#include "palette.h"

#ifdef SGB
    #include <gb/sgb.h>
#endif
#include <string.h>

palette_entry_t SprPalette[8];
palette_entry_t BkgPalette[8];

void palette_init() __banked {
    #ifdef CGB
        if (_cpu == CGB_TYPE) {
            memset(BkgPalette, 0, sizeof(BkgPalette));
            memset(SprPalette, 0, sizeof(SprPalette));
            return;
        }
    #endif
    BkgPalette[0].c0 = SprPalette[1].c0 = DMG_PAL(3, 2, 1, 0); 
    SprPalette[0].c0 = DMG_PAL(3, 1, 0, 2);
}

#ifdef CGB
void CGBZeroPalette(UBYTE reg) __banked __naked {
    reg;
__asm
        ldhl sp, #6
        ld c, (hl)
        ld a, #0x80
        ldh (c), a
        inc c

        ld b, #(8 * 4 * 2)
1$:
        ldh a, (_STAT_REG)
        and #0x02
        jr nz, 1$
        xor a
        ldh (c), a

        dec b
        jr nz, 1$

        ret   
__endasm;
}
#endif

#ifdef SGB
typedef struct sgb_pal_packet_t {
    UBYTE cmd;
    UWORD palettes[7];
} sgb_pal_packet_t;

void SGBTransferPalettes(UBYTE palettes) __banked {
    sgb_pal_packet_t data;
    data.cmd = (SGB_PAL_01 << 3) | 1;
    if (palettes & SGB_PALETTES_01) {
        data.cmd = (SGB_PAL_01 << 3) | 1;
        memcpy(data.palettes, &BkgPalette[4], sizeof(palette_entry_t));
        memcpy(&data.palettes[4], &BkgPalette[5].c1, sizeof(palette_entry_t) - sizeof(UWORD));
        sgb_transfer((void *)&data);
    }
    if (palettes & SGB_PALETTES_23) {
        data.cmd = (SGB_PAL_23 << 3) | 1;
        memcpy(data.palettes, &BkgPalette[6], sizeof(palette_entry_t));
        memcpy(&data.palettes[4], &BkgPalette[7].c1, sizeof(palette_entry_t) - sizeof(UWORD));
        sgb_transfer((void *)&data);
    }
}
#endif