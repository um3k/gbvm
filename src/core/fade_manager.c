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

/*
#define CLIP(X) ( (X) > 255 ? 255 : (X) < 0 ? 0 : X)

// RGB -> YUV
#define RGB2Y(R, G, B) CLIP(( (  66 * (R) + 129 * (G) +  25 * (B) + 128) >> 8) +  16)
#define RGB2U(R, G, B) CLIP(( ( -38 * (R) -  74 * (G) + 112 * (B) + 128) >> 8) + 128)
#define RGB2V(R, G, B) CLIP(( ( 112 * (R) -  94 * (G) -  18 * (B) + 128) >> 8) + 128)

// YUV -> RGB
#define C(Y) ( (Y) - 16  )
#define D(U) ( (U) - 128 )
#define E(V) ( (V) - 128 )

#define YUV2R(Y, U, V) CLIP(( 298 * C(Y)              + 409 * E(V) + 128) >> 8)
#define YUV2G(Y, U, V) CLIP(( 298 * C(Y) - 100 * D(U) - 208 * E(V) + 128) >> 8)
#define YUV2B(Y, U, V) CLIP(( 298 * C(Y) + 516 * D(U)              + 128) >> 8)

UWORD CGBFadeToWhiteStep(UWORD rgb, UBYTE step) {
    static UBYTE R, G, B;
    static UBYTE Y, U, V;
    R = rgb & 0x1f; G = (pal >> 5) & 0x1f; B = (pal >> 10) & 0x1f;
    Y = RGB2Y(R, G, B);
    U = RGB2U(R, G, B);
    V = RGB2V(R, G, B);
    Y += (UBYTE)(6 * step);
    R = YUV2R(Y, U, V);
    G = YUV2G(Y, U, V);
    B = YUV2B(Y, U, V);
    return RGB(R, G, B);
}
*/

#ifdef CGB
UWORD CGBFadeToWhiteStep(UWORD rgb, UBYTE step) __naked {
    rgb; step;
__asm
        ldhl sp, #2
        ld a, (hl+)
        ld e, a
        ld a, (hl+)
        ld d, a
        ld a, (HL)
        or a
        ret z

        push bc

        ld l, a
        ld bc, #0x0421
1$:
        sla e
        rr d

        ld a, c
        or e
        ld c, a
        ld e, a
        ld a, b
        or d
        ld b, a
        ld d, a

        dec l
        jr nz, 1$

        res 7, d

        pop bc
        ret   
__endasm;
}

UWORD CGBFadeToBlackStep(UWORD rgb, UBYTE step) __naked {
    rgb; step;
__asm
        ldhl sp, #2
        ld a, (hl+)
        ld e, a
        ld a, (hl+)
        ld d, a
        ld a, (HL)
        or a
        ret z

        push bc

        ld l, a
        ld bc, #0xfdef
1$:
        srl d
        rr e

        ld a, c
        and e
        ld e, a
        ld a, b
        and d
        ld d, a

        dec l
        jr nz, 1$

        pop bc
        ret   
__endasm;
}

void ApplyPaletteChangeColor(UBYTE index) {
    UWORD tmp_palette[32];

    if (index == FADED_IN_FRAME) {
        set_bkg_palette(0, 8, BkgPalette);
        set_sprite_palette(0, 8, SprPalette);
    }

    for (UBYTE i = 0; i != 32; i++) 
        if (!fade_style) tmp_palette[i] = CGBFadeToWhiteStep(BkgPalette[i], index); else tmp_palette[i] = CGBFadeToBlackStep(BkgPalette[i], index);
    set_bkg_palette(0, 8, tmp_palette);

    for (UBYTE i = 0; i != 32; i++) 
        if (!fade_style) tmp_palette[i] = CGBFadeToWhiteStep(SprPalette[i], index); else tmp_palette[i] = CGBFadeToBlackStep(SprPalette[i], index);
    set_sprite_palette(0, 8, tmp_palette);
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