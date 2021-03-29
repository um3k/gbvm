#pragma bank 2

#include <gb/cgb.h>
#include <gb/sgb.h>

#include "gbs_types.h"
#include "vm_palette.h"

#include "vm.h"
#include "bankdata.h"

void vm_load_palette(SCRIPT_CTX * THIS, UBYTE mask, UBYTE options) __banked {
    UBYTE bank = THIS->bank;
    #ifdef SGB
        UBYTE sgb_changes = SGB_PALETTES_NONE;
    #endif
    const palette_entry_t * sour = (const palette_entry_t *)THIS->PC;
    palette_entry_t * dest = (options & PALETTE_BKG) ? BkgPalette : SprPalette;
    for (UBYTE i = mask, nb = 0; (i != 0); dest++, nb++, i >>= 1) {
        if ((i & 1) == 0) continue;
        MemcpyBanked(dest, sour, sizeof(palette_entry_t), bank);
        if (options & PALETTE_COMMIT) {
            #ifdef CGB
                if (_cpu == CGB_TYPE) { 
                    if (options & PALETTE_BKG) set_bkg_palette(nb, 1, (void *)dest);
                    if (options & PALETTE_SPRITE) set_sprite_palette(nb, 1, (void *)dest); 
                    sour++;
                    continue;
                }
            #endif
            #ifdef SGB
                if (options & PALETTE_BKG) {
                    if ((nb == 4) || (nb == 5)) sgb_changes |= SGB_PALETTES_01;
                    if ((nb == 6) || (nb == 7)) sgb_changes |= SGB_PALETTES_23;
                }
            #endif
            if (options & PALETTE_BKG) {
                if (nb == 0) BGP_REG = (UBYTE)dest->c0;
            }
            if (options & PALETTE_SPRITE) {
                switch (nb) {
                    case 0:
                        OBP0_REG = (UBYTE)dest->c0;
                        break;
                    case 1:
                        OBP1_REG = (UBYTE)dest->c0;
                        break;
                }
            } 
        } 
        sour++; 
    }
    #ifdef SGB
        if (sgb_changes) SGBTransferPalettes(sgb_changes);
    #endif
    THIS->PC = (UBYTE *)sour;
}

typedef struct sgb_attr_packet_t {
    UBYTE cmd, nsets;
    UBYTE ctl, pals;
    UBYTE X1, Y1, X2, Y2;
} sgb_attr_packet_t;

void vm_set_sgb_attributes(SCRIPT_CTX * THIS, UBYTE x1, UBYTE y1, UBYTE x2, UBYTE y2, UBYTE control, UBYTE palettes) __banked {
    THIS;
    sgb_attr_packet_t pkt = {(SGB_ATTR_BLK << 3) | 1, 1, control, palettes, x1, y1, x2, y2};
    sgb_transfer_nowait((void *)&pkt);
}