#include <gb/gb.h>
#include <string.h>
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
#include "FadeManager.h"
#include "Scroll.h"
#include "vm.h"
#include "VM_Exceptions.h"
#include "StatesCaller.h"
#ifdef SGB
    #include "SGBBorder.h"
    #include "data/border.h"
#endif

#include "data/data_ptrs.h"

extern void __bank_bootstrap_script;
extern const UBYTE bootstrap_script[];

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
    if ((LY_REG < SCREENHEIGHT) && (WX_REG == 7u)) HIDE_SPRITES;
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
        // enable LCD interrupt only when window is visible
        IE_REG |= LCD_IFLAG;
    } else {
        HIDE_WIN;
        // disable LCD interrupt
        IE_REG &= ~LCD_IFLAG;
    }
}

void engine_reset() {
    // cleanup core stuff
    sound_init();
    fade_init();
    ui_init();
    events_init();
    timers_init();
    music_init();
    // kill all threads, clear VM memory
    script_runner_init(TRUE);
}

void process_VM() {
    while (TRUE) {
        switch (script_runner_update()) {
            case RUNNER_DONE:
            case RUNNER_IDLE: {                
                input_update();
                if (INPUT_SOFT_RESTART) {
                    // kill all threads (in case something is wrong and all contexts occupied) 
                    script_runner_init(FALSE);
                    // execute bootstrap script              
                    script_execute(BANK(bootstrap_script), bootstrap_script, 0, 0);
                    break;
                }
                if (joy != 0) events_update();
                if (!VM_ISLOCKED()) {
                    state_update();                                     // Update Current Scene Type
                    if ((game_time & 0x0F) == 0x00) timers_update();    // update timers
                }
                camera_update();
                scroll_update();
                actors_update();
                // projectiles_update();
                ui_update();
                actors_handle_player_collision();                
                game_time++;
                wait_vbl_done();
                break;
            }
            case RUNNER_BUSY: break;
            case RUNNER_EXCEPTION: {
                UBYTE fade_in = TRUE;
                switch (vm_exception_code) {
                    case EXCEPTION_RESET: {
                        // reset everything
                        engine_reset();
                        // load start scene
                        fade_in = !(load_scene(start_scene.ptr, start_scene.bank));
                        // load initial player
                        load_player();
                        break;
                    }
                    case EXCEPTION_CHANGE_SCENE: {
                        // kill all threads, but don't clear variables 
                        script_runner_init(FALSE);
                        // reset timers on scene change
                        timers_init();
                        // reset input events on scene change
                        events_init();
                        // reset music events
                        music_init();
                        // load scene
                        far_ptr_t scene;
                        ReadBankedFarPtr(&scene, vm_exception_params_offset, vm_exception_params_bank);
                        fade_in = !(load_scene(scene.ptr, scene.bank));
                        break;
                    }
                    default: {
                        // nothing: suppress any unknown exception
                        continue;
                    }
                }
                state_init();
                actor_reset_dir(&PLAYER);
                camera_update();
                scroll_update();
                actors_update();
                if (fade_in) fade_in_modal();
            }
        }
    }
}

void main() {
#ifdef SGB
    set_sgb_border(SGB_border_chr, SIZE(SGB_border_chr), BANK(SGB_border_chr),
                   SGB_border_map, SIZE(SGB_border_map), BANK(SGB_border_map), 
                   SGB_border_pal, SIZE(SGB_border_pal), BANK(SGB_border_pal));
#endif

    display_off();
#ifdef SGB
    memset((UBYTE *)0x8000, 0, 384 * 16);
#endif

    LCDC_REG = 0x67;

    BGP_REG = OBP0_REG = 0xE4U;
    OBP1_REG = 0xD2U;

    WX_REG = MINWNDPOSX;
    WY_REG = MENU_CLOSED_Y;

    initrand(DIV_REG);

    // reset everything
    engine_reset();

    __critical {
        add_LCD(LCD_isr);
        add_VBL(VBL_isr);
        STAT_REG |= 0x40u; 
        LYC_REG = 144;

        add_TIM(music_update);
        #ifdef CGB
            TMA_REG = _cpu == CGB_TYPE ? 120U : 0xBCU;
        #else
            TMA_REG = 0xBCU;
        #endif
        TAC_REG = 0x04U;

        IE_REG |= TIM_IFLAG;
    }
    DISPLAY_ON;

    // execute bootstrap script that just raises RESET exception
    script_execute(BANK(bootstrap_script), bootstrap_script, 0, 0);

    // grid walking
    // script_execute(BANK(SCRIPT_2), SCRIPT_2, 0, 0);

    // script_execute(BANK(BYTECODE), BYTECODE, 0, 0);
    // script_execute(BANK(SCRIPT_3), SCRIPT_3, 0, 5, 5, 32, 64, 0, 0);
    // script_execute(BANK(SCRIPT_4), SCRIPT_4, 0, 0);

    // script_execute(BANK(SCRIPT_5), SCRIPT_5, 0, 0); // let actor walk, so we test nonmodal UI

    // load up engine with more actors
    // script_execute(BANK(SCRIPT_3), SCRIPT_3, 0, 1,  8);
    // script_execute(BANK(SCRIPT_3), SCRIPT_3, 0, 1, 8 );
    // script_execute(BANK(SCRIPT_3), SCRIPT_3, 0, 1, 9 );
    // script_execute(BANK(SCRIPT_3), SCRIPT_3, 0, 1, 10);
    // script_execute(BANK(SCRIPT_3), SCRIPT_3, 0, 1, 11);
    // script_execute(BANK(SCRIPT_3), SCRIPT_3, 0, 1, 12);

    process_VM();
}
