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
    while (TRUE) {
        switch (script_runner_update()) {
            case RUNNER_DONE:
            case RUNNER_IDLE: {
                input_update();
                if (joy != 0) events_update();
                if (!VM_ISLOCKED()) state_update(); // Update Current Scene Type
                camera_update();
                scroll_update();
                actors_update();
                // projectiles_update();
                ui_update();
                // actors_run_collision_scripts();
                game_time++;
                wait_vbl_done();
                continue;
            }
            case RUNNER_BUSY: continue;
            case RUNNER_EXCEPTION: {
                script_runner_init(FALSE);
                switch (vm_exception_code) {
                    case CHANGE_SCENE_EXCEPTION: {
                        far_ptr_t scene;
                        MemcpyBanked(&scene, (void *)vm_exception_params_offset, sizeof(scene), vm_exception_params_bank);
                        load_scene(scene.ptr, scene.bank);
                        continue;
                    }
                }
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

    sound_init();

    initrand(DIV_REG);

    script_runner_init(TRUE);

    events_init();
    ui_init();
    fade_init();

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

        IE_REG |= (LCD_IFLAG | TIM_IFLAG);
    }
    DISPLAY_ON;

    fade_out_modal();

    load_scene(&scene_1, BANK(scene_1));
    camera_update();
    scroll_update();

    state_init(); // Start Scene Type

    fade_in_modal();

    script_execute(BANK(SCRIPT_1), SCRIPT_1, 0, 0);

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
