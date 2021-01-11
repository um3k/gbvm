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
#include "LoadSave.h"
#ifdef SGB
    #include "SGBBorder.h"
    #include "data/border.h"
#endif

#include "data/data_ptrs.h"

#define PARALLAX

extern void __bank_bootstrap_script;
extern const UBYTE bootstrap_script[];

void LCD_isr() __nonbanked {
    if (hide_sprites) return;
    if ((LY_REG < SCREENHEIGHT) && (WX_REG == 7u)) HIDE_SPRITES;
}

void parallax_LCD_isr() __nonbanked {
    switch (LYC_REG) {
        case 0x00:
            SCX_REG = draw_scroll_x >> 4; 
            SCY_REG = 0;
            LYC_REG = 23;
            break;
        case 23:
            SCX_REG = draw_scroll_x >> 2; 
            SCY_REG = 0;
            LYC_REG = 47;
            break;
        case 47:
            SCX_REG = draw_scroll_x; 
            SCY_REG = draw_scroll_y;
            LYC_REG = 0x00;
            break;
        default:             
            LYC_REG = 0x00;
            break;
    }
}

void VBL_isr() __nonbanked {
    // Update background scroll in vbl
    // interupt to prevent tearing
#ifndef PARALLAX
    SCX_REG = draw_scroll_x;
    SCY_REG = draw_scroll_y;
#endif
    if (!hide_sprites) SHOW_SPRITES;
    if ((win_pos_y < MAXWNDPOSY) && (win_pos_x < SCREENWIDTH - 1)) {
        LYC_REG = WY_REG = win_pos_y;
        WX_REG = win_pos_x + 7u;
        SHOW_WIN;
#ifndef PARALLAX
        // enable LCD interrupt only when window is visible
        IE_REG |= LCD_IFLAG;
#endif
    } else {
        HIDE_WIN;
#ifndef PARALLAX
        // disable LCD interrupt
        IE_REG &= ~LCD_IFLAG;
#endif
    }
}

void engine_reset() {
    // cleanup core stuff
    sound_init();
    fade_init();
    ui_init();
    events_init(FALSE);
    timers_init(FALSE);
    music_init(FALSE);
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
                    music_events_update();                              // update music events
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
                        fade_in = !(load_scene(start_scene.ptr, start_scene.bank, TRUE));
                        // load initial player
                        load_player();
                        break;
                    }
                    case EXCEPTION_CHANGE_SCENE: {
                        // kill all threads, but don't clear variables 
                        script_runner_init(FALSE);
                        // reset timers on scene change
                        timers_init(FALSE);
                        // reset input events on scene change
                        events_init(FALSE);
                        // reset music events
                        music_init(FALSE);
                        // load scene
                        far_ptr_t scene;
                        ReadBankedFarPtr(&scene, vm_exception_params_offset, vm_exception_params_bank);
                        fade_in = !(load_scene(scene.ptr, scene.bank, TRUE));
                        break;
                    }
                    case EXCEPTION_SAVE: {
                        data_save();
                        continue;
                    }
                    case EXCEPTION_LOAD: {
                        fade_out_modal();
                        data_load();
                        fade_in = !(load_scene(current_scene.ptr, current_scene.bank, FALSE));
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
    data_init();
#ifdef SGB
    set_sgb_border(SGB_border_chr, SIZE(SGB_border_chr), BANK(SGB_border_chr),
                   SGB_border_map, SIZE(SGB_border_map), BANK(SGB_border_map), 
                   SGB_border_pal, SIZE(SGB_border_pal), BANK(SGB_border_pal));
#endif

    display_off();
#ifdef SGB
    #ifdef DEVBUILD
    memset((UBYTE *)0x8000, 0, 384 * 16);
    #endif
#endif
    memset(actors, 0, sizeof(actors));

    LCDC_REG = 0x67;

    BGP_REG = OBP0_REG = 0xE4U;
    OBP1_REG = 0xD2U;

    WX_REG = MINWNDPOSX;
    WY_REG = MENU_CLOSED_Y;

    initrand(DIV_REG);

    // reset everything (before init interrupts below!)
    engine_reset();

    __critical {
#ifdef PARALLAX
        add_LCD(parallax_LCD_isr);
        LYC_REG = 0u;
#else
        add_LCD(LCD_isr);
        LYC_REG = 144u;
#endif
        add_VBL(VBL_isr);
        STAT_REG |= 0x40u; 

        #ifdef CGB
            TMA_REG = _cpu == CGB_TYPE ? 0xE0u : 0xC0u;
        #else
            TMA_REG = 0xC0u;
        #endif
        TAC_REG = 0x07u;

#ifdef PARALLAX
        IE_REG |= (TIM_IFLAG | LCD_IFLAG);
#else
        IE_REG |= TIM_IFLAG;
#endif
    }
    DISPLAY_ON;

    // execute bootstrap script that just raises RESET exception
    script_execute(BANK(bootstrap_script), bootstrap_script, 0, 0);

    // execute VM
    process_VM();
}
