#pragma bank 3

#ifdef CGB
    #include <gb/gb.h>
    #include <gb/cgb.h>
    #include <string.h>
#endif

#include "fade_manager.h"
#include "palette.h"

#define FADED_OUT_FRAME 5
#define FADED_IN_FRAME 0

UBYTE fade_running;
UBYTE fade_frames_per_step;
UBYTE fade_black;
UBYTE fade_timer;
UBYTE fade_style;

const UBYTE fade_speeds[] = {0x0, 0x1, 0x3, 0x7, 0xF, 0x1F, 0x3F};

static UBYTE fade_frame;
static FADE_DIRECTION fade_direction;

#ifdef CGB

inline UWORD UpdateColorBlack(UINT8 i, UWORD col) {
    return RGB2((PAL_RED(col) >> 5 - i),  (PAL_GREEN(col) >> 5 - i), (PAL_BLUE(col) >> 5 - i));
}

static void ApplyPaletteChangeColor(UBYTE index) {
    if (index == FADED_IN_FRAME) {
        set_bkg_palette(0, 8, BkgPalette);
        set_sprite_palette(0, 8, SprPalette);
        return;
    }

    index = FADED_OUT_FRAME - index;

    UINT8 c;
    UWORD paletteWhite;
    UWORD* col;
    UWORD tmp[32];
    if (fade_style) {
        col = BkgPalette;
        for (c = 0; c != 32; ++c, ++col) {
            tmp[c] = UpdateColorBlack(index, *col);
        }
        set_bkg_palette(0, 1, tmp);
        col = SprPalette;
        for (c = 0; c != 32; c++, ++col) {
            tmp[c] = UpdateColorBlack(index, *col);
        }
        set_sprite_palette(0, 8, tmp);
    } else {
        col = BkgPalette; 
        paletteWhite = RGB2((0x1F >> index), (0x1F >> index), (0x1F >> index));
        for (c = 0; c != 32; ++c, ++col) {
            tmp[c] = (UWORD)*col | paletteWhite;
        }
        set_bkg_palette(0, 8, tmp);
        col = SprPalette;
        for (c = 0; c != 32; ++c, ++col) {
            tmp[c] = (UWORD)*col | paletteWhite;
        }
        set_sprite_palette(0, 8, tmp);
    }
}
#endif

UBYTE DMGFadeToWhiteStep(UBYTE pal, UBYTE step) __naked {
    pal; step;
__asm
        ldhl    SP, #3
        ld      A, (HL-)
        ld      E, (HL)
        or      A
        ret     Z
        
        ld      D, A
1$: 
        ld      H, #4
2$:
        ld      A, E
        and     #3
        jr      Z, 3$
        dec     A         
3$:
        srl     A
        rr      L
        srl     A
        rr      L
        
        srl     E
        srl     E

        dec     H
        jr      NZ, 2$

        ld      E, L

        dec     D
        jr      NZ, 1$
        ret   
__endasm;
}

UBYTE DMGFadeToBlackStep(UBYTE pal, UBYTE step) __naked {
    pal; step;
__asm
        ldhl    SP, #3
        ld      A, (HL-)
        ld      E, (HL)
        or      A
        ret     Z
        
        ld      D, A
1$: 
        ld      H, #4
2$:
        ld      A, E
        and     #3
        cp      #3
        jr      Z, 3$
        inc     A         
3$:
        srl     A
        rr      L
        srl     A
        rr      L
        
        srl     E
        srl     E

        dec     H
        jr      NZ, 2$

        ld      E, L

        dec     D
        jr      NZ, 1$
        ret   
__endasm;
}

void ApplyPaletteChangeDMG(UBYTE index) {
    if (index > 4) index = 4;
    if (!fade_style) {
        BGP_REG = DMGFadeToWhiteStep((UBYTE)BkgPalette[0], index); 
        OBP0_REG = DMGFadeToWhiteStep((UBYTE)SprPalette[0], index); 
        OBP1_REG = DMGFadeToWhiteStep((UBYTE)SprPalette[4], index); 
    } else {
        BGP_REG = DMGFadeToBlackStep((UBYTE)BkgPalette[0], index); 
        OBP0_REG = DMGFadeToBlackStep((UBYTE)SprPalette[0], index); 
        OBP1_REG = DMGFadeToBlackStep((UBYTE)SprPalette[4], index); 
    }
}

void fade_init() __banked {
    fade_frames_per_step = fade_speeds[2];
    fade_timer = FADED_OUT_FRAME;
    fade_running = FALSE;
    fade_black = 0;
    fade_style = 0;
#ifdef CGB
    if (_cpu == CGB_TYPE) {
        ApplyPaletteChangeColor(fade_timer);
        return;
    }
#endif
    ApplyPaletteChangeDMG(FADED_OUT_FRAME);    
}

void fade_in() __banked {
    if (fade_timer == FADED_IN_FRAME) {
        return;
    }
    fade_frame = 0;
    fade_direction = FADE_IN;
    fade_running = TRUE;
    fade_timer = FADED_OUT_FRAME;
#ifdef CGB
    if (_cpu == CGB_TYPE) {
        ApplyPaletteChangeColor(FADED_OUT_FRAME);
        return;
    }
#endif
    ApplyPaletteChangeDMG(FADED_OUT_FRAME);
}

void fade_out() __banked {
    if (fade_timer == FADED_OUT_FRAME) {
        return;
    }    
    fade_frame = 0;
    fade_direction = FADE_OUT;
    fade_running = TRUE;
    fade_timer = FADED_IN_FRAME;
#ifdef CGB
    if (_cpu == CGB_TYPE) {
        ApplyPaletteChangeColor(fade_timer);
        return;
    }
#endif
        ApplyPaletteChangeDMG(FADED_IN_FRAME);
}

void fade_update() __banked {
    if (fade_running) {
        if ((fade_frame++ & fade_frames_per_step) == 0) {
            if (fade_direction == FADE_IN) {
                if (fade_timer > FADED_IN_FRAME) fade_timer--;
                if (fade_timer == FADED_IN_FRAME) fade_running = FALSE;
            } else {
                if (fade_timer < FADED_OUT_FRAME) fade_timer++;
                if (fade_timer == FADED_OUT_FRAME) fade_running = FALSE;
            }
#ifdef CGB
            if (_cpu == CGB_TYPE) {
                ApplyPaletteChangeColor(fade_timer);
                return;
            }
#endif
            ApplyPaletteChangeDMG(fade_timer);
        }
    }
}

void fade_applypalettechange() __banked {
#ifdef CGB
    if (_cpu == CGB_TYPE) {
        ApplyPaletteChangeColor(fade_timer);
        return;
    }
#endif
    ApplyPaletteChangeDMG(fade_timer);
}

void fade_setspeed(UBYTE speed) __banked {
    fade_frames_per_step = fade_speeds[speed];
}

void fade_in_modal() __banked {
    DISPLAY_ON;
    fade_in();
    while (fade_isfading()) {
        wait_vbl_done();
        fade_update();
    }
}

void fade_out_modal() __banked {
    fade_out();
    while (fade_isfading()) {
        wait_vbl_done();
        fade_update();
    }
    if (!fade_style) DISPLAY_OFF;
}