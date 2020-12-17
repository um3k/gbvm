#include <gb/gb.h>
#include <gb/font.h>
#include <rand.h>

#include "BankData.h"
#include "GameTime.h"
#include "Actor.h"
#include "Camera.h"
#include "LinkedList.h"
#include "Sprite.h"
#include "UI.h"
#include "Input.h"

#include "vm.h"

#include "gfx.h"

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

void init_actors() {
    UBYTE i;

    // set_bkg_data(0, 186, tile_data);
    // set_bkg_tiles(0, 0, 20, 18, bg_data);
    SetBankedSpriteData(0, 24, sprite_1_data, (UBYTE)&__bank_sprite_1_data);

    init_sprite_pool();

    actors_active_len = 0;
    actors_active_head = 0;
    actors_inactive_head = 0;

    for (i = 0; i != MAX_ACTORS; i++)
    {
        actors[i].enabled = FALSE;
        actors[i].x = (i * 8) % 120;
        actors[i].y = (i * 8) % 120;
        actors[i].dir_x = 0;
        actors[i].dir_y = 1;        
        actors[i].sprite_no = 0;
        actors[i].frame = 0;
        actors[i].frame_start = 0;
        actors[i].frame_end = 8;
        actors[i].anim_tick = 0x7;
        actors[i].rerender = TRUE;
        actors[i].flip_x = FALSE;
        actors[i].pinned = FALSE;
        actors[i].animate = FALSE;
        actors[i].move_speed = 1;
        actors[i].collision_enabled = TRUE;

        DL_PUSH_HEAD(actors_inactive_head, &actors[i]);
    }    

    actors[3].x = 32;
    actors[3].y = 32;
//    activate_actor(&actors[3]);

    actors[5].x = 32;
    actors[5].y = 64;
    // activate_actor(&actors[5]);

    actors[7].x = 64;
    actors[7].y = 64;
    // activate_actor(&actors[7]);

//    actors[8].x = 4*8;
//    actors[8].y = 144;
//    activate_actor(&actors[8]);
//    actors[9].x = 6*8;
//    actors[9].y = 144;
//    activate_actor(&actors[9]);
//    actors[10].x = 8*8;
//    actors[10].y = 144;
//    activate_actor(&actors[10]);
//    actors[11].x = 10*8;
//    actors[11].y = 144;
//    activate_actor(&actors[11]);
//    actors[12].x = 12*8;
//    actors[12].y = 144;
//    activate_actor(&actors[12]);
//    activate_actor(&actors[13]);
//    activate_actor(&actors[14]);
//    activate_actor(&actors[15]);
//    activate_actor(&actors[16]);
}

void main() {
    display_off();

    LCDC_REG = 0x67;

    BGP_REG = OBP0_REG = 0xE4U;
    OBP1_REG = 0xD2U;

    WX_REG = MINWNDPOSX;
    WY_REG = MENU_CLOSED_Y;

    initrand(DIV_REG);

    input_init();
    ui_init();
    init_actors();

    __critical {
        add_LCD(LCD_isr);
        add_VBL(VBL_isr);
        IE_REG |= LCD_IFLAG;
        STAT_REG |= 0x40u; 
        LYC_REG = 144;
    }


    DISPLAY_ON;

    // font_init();
    // font_set(font_load(font_spect));
    
    ScriptRunnerInit();

    ExecuteScript((UBYTE)&__bank_SCRIPT_1, SCRIPT_1, 0, 0);

    // ExecuteScript((UBYTE)&__bank_BYTECODE, BYTECODE, 0, 0);
    // ExecuteScript((UBYTE)&__bank_SCRIPT_3, SCRIPT_3, 0, 5, 5, 32, 64, 0, 0);
    // ExecuteScript((UBYTE)&__bank_SCRIPT_4, SCRIPT_4, 0, 0);

    ExecuteScript((UBYTE)&__bank_SCRIPT_5, SCRIPT_5, 0, 0); // let actor walk, so we test nonmodal UI

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
