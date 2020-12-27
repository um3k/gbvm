#include <gb/gb.h>
#include <gb/font.h>
#include <gb/crash_handler.h>
#include <rand.h>

#include "BankData.h"
#include "GameTime.h"
#include "Actor.h"
#include "Camera.h"
#include "LinkedList.h"
#include "Sprite.h"
#include "UI.h"
#include "Input.h"
#include "events.h"
#include "DataManager.h"
#include "MusicManager.h"
#include "Scroll.h"
#include "vm.h"

#include "gfx.h"
#include "data/tileset_0.h"
#include "data/background_1.h"
#include "data/scene_1.h"

extern const UBYTE BYTECODE[];                  // defined in bytecode.s
extern void __bank_BYTECODE;

extern const UBYTE SCRIPT_1[];                  // defined in SCRIPT_1.s
extern void __bank_SCRIPT_1;

extern const UBYTE SCRIPT_2[];                  // defined in SCRIPT_2.s
extern void __bank_SCRIPT_2;

extern const UBYTE SCRIPT_3[];                  // defined in SCRIPT_3.s
extern void __bank_SCRIPT_3;

extern const UBYTE SCRIPT_4[];                  // defined in SCRIPT_4.s
extern void __bank_SCRIPT_4;

extern const UBYTE SCRIPT_5[];                  // defined in SCRIPT_5.s
extern void __bank_SCRIPT_5;

void LCD_isr() __nonbanked {
    if (hide_sprites) return;
    if ((LYC_REG < SCREENHEIGHT) && (WX_REG == 7u)) HIDE_SPRITES;
}

void VBL_isr() __nonbanked {
    // Update background scroll in vbl
    // interupt to prevent tearing
    SCX_REG = draw_scroll_x;
    SCY_REG = draw_scroll_y;

    if (!hide_sprites) SHOW_SPRITES;
    if ((win_pos_y < MAXWNDPOSY) && (win_pos_x < SCREENWIDTH - 1)) {
        LYC_REG = WY_REG = win_pos_y;
        WX_REG = win_pos_x + 7u;
        SHOW_WIN;
    } else HIDE_WIN;
}

void process_VM() {
    while (1) {
        switch (ScriptRunnerUpdate()) {
            case RUNNER_DONE:
            case RUNNER_IDLE: {
                input_update();
                if (joy != 0) events_update();
                camera_x++;
                camera_y++;
                RefreshScroll_b();
                update_actors();
                ui_update();
                game_time++;
                wait_vbl_done();
                break;
            }
//            case RUNNER_BUSY: ;
        }
    }
}

void main() {
    display_off();

    LCDC_REG = 0x67;

    BGP_REG = OBP0_REG = 0xE4U;
    OBP1_REG = 0xD2U;

    WX_REG = MINWNDPOSX;
    WY_REG = MENU_CLOSED_Y;

    initrand(DIV_REG);

    events_init();
    ui_init();

  
    NR52_REG = 0x80;
    NR51_REG = 0xFF;
    NR50_REG = 0x77;

    __critical {
        add_LCD(LCD_isr);
        add_VBL(VBL_isr);
        STAT_REG |= 0x40u; 
        LYC_REG = 144;

        add_TIM(MusicUpdate);
        #ifdef CGB
            TMA_REG = _cpu == CGB_TYPE ? 120U : 0xBCU;
        #else
            TMA_REG = 0xBCU;
        #endif
        TAC_REG = 0x04U;

        IE_REG |= (LCD_IFLAG | TIM_IFLAG);
    }

    load_scene(&scene_1, (UBYTE)&__bank_scene_1);
    RefreshScroll_b();

    DISPLAY_ON;

    // font_init();
    // font_set(font_load(font_spect));
    
    ScriptRunnerInit();

    ExecuteScript((UBYTE)&__bank_SCRIPT_1, SCRIPT_1, 0, 0);

    // grid walking
    // ExecuteScript((UBYTE)&__bank_SCRIPT_2, SCRIPT_2, 0, 0);

    // ExecuteScript((UBYTE)&__bank_BYTECODE, BYTECODE, 0, 0);
    // ExecuteScript((UBYTE)&__bank_SCRIPT_3, SCRIPT_3, 0, 5, 5, 32, 64, 0, 0);
    // ExecuteScript((UBYTE)&__bank_SCRIPT_4, SCRIPT_4, 0, 0);

    // ExecuteScript((UBYTE)&__bank_SCRIPT_5, SCRIPT_5, 0, 0); // let actor walk, so we test nonmodal UI

    // load up engine with more actors
    // ExecuteScript((UBYTE)&__bank_SCRIPT_3, SCRIPT_3, 0, 1,  8);
    // ExecuteScript((UBYTE)&__bank_SCRIPT_3, SCRIPT_3, 0, 1, 8 );
    // ExecuteScript((UBYTE)&__bank_SCRIPT_3, SCRIPT_3, 0, 1, 9 );
    // ExecuteScript((UBYTE)&__bank_SCRIPT_3, SCRIPT_3, 0, 1, 10);
    // ExecuteScript((UBYTE)&__bank_SCRIPT_3, SCRIPT_3, 0, 1, 11);
    // ExecuteScript((UBYTE)&__bank_SCRIPT_3, SCRIPT_3, 0, 1, 12);
    // ExecuteSc


    // ExecuteScript((UBYTE)&__bank_SCRIPT_3, SCRIPT_3, 0, 5,  8,  4 * 8,  144, 0, 0);
    // ExecuteScript((UBYTE)&__bank_SCRIPT_3, SCRIPT_3, 0, 5,  9,  6 * 8,  144, 0, 0);
    // ExecuteScript((UBYTE)&__bank_SCRIPT_3, SCRIPT_3, 0, 5,  10, 8 * 8,  144, 0, 0);
    // ExecuteScript((UBYTE)&__bank_SCRIPT_3, SCRIPT_3, 0, 5,  11, 10 * 8, 144, 0, 0);
    // ExecuteScript((UBYTE)&__bank_SCRIPT_3, SCRIPT_3, 0, 5,  12, 12 * 8, 144, 0, 0);
    // ExecuteScript((UBYTE)&__bank_SCRIPT_3, SCRIPT_3, 0, 5,  13, 14 * 8, 96,  0, 0);
//    ExecuteScript((UBYTE)&__bank_SCRIPT_3, SCRIPT_3, 0, 5,  14, 10 * 8, 96,  0, 0);
//    ExecuteScript((UBYTE)&__bank_SCRIPT_3, SCRIPT_3, 0, 5,  15, 12 * 8, 64,  0, 0);
//    ExecuteScript((UBYTE)&__bank_SCRIPT_3, SCRIPT_3, 0, 5,  16, 14 * 8, 64,  0, 0);

    // printf(">> VM START\n");
    process_VM();
    // printf("<< VM DONE\n");
}
