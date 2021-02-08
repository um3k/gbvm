#include <gb/gb.h>
#include <stdio.h>
#include <string.h>

#include "actor.h"
#include "camera.h"
#include "data_manager.h"
#include "linked_list.h"
#include "scroll.h"
#include "Sprite.h"
#include "framework/test_main.h"

#define TEST_ACTORS_LEN 8

const unsigned char sprite_1_data[] = {
    0,   0,   7,   7,   8,   15,  16,  31,  61,  35,  34,  63,  45,  62,  43,
    60,  43,  62,  47,  58,  63,  44,  111, 95,  127, 127, 57,  63,  29,  27,
    14,  14,  0,   0,   224, 224, 16,  240, 56,  200, 92,  164, 172, 212, 66,
    254, 190, 126, 212, 124, 244, 92,  244, 60,  250, 254, 60,  228, 252, 228,
    248, 248, 112, 112, 0,   0,   7,   7,   8,   15,  16,  31,  61,  35,  34,
    63,  45,  62,  43,  60,  43,  62,  47,  58,  63,  44,  111, 95,  124, 127,
    63,  39,  31,  31,  14,  14,  0,   0,   224, 224, 16,  240, 56,  200, 92,
    164, 172, 212, 66,  254, 190, 126, 212, 124, 244, 92,  244, 60,  242, 254,
    254, 254, 156, 252, 184, 216, 112, 112, 0,   0,   7,   7,   8,   15,  22,
    25,  33,  62,  96,  127, 32,  63,  32,  63,  41,  54,  41,  54,  41,  54,
    85,  106, 126, 125, 63,  39,  31,  31,  0,   0,   0,   0,   224, 224, 16,
    240, 104, 152, 132, 124, 4,   252, 4,   252, 4,   252, 36,  220, 36,  220,
    36,  220, 162, 222, 158, 254, 248, 248, 176, 208, 112, 112, 0,   0,   7,
    7,   8,   15,  22,  25,  33,  62,  32,  63,  96,  127, 32,  63,  41,  54,
    41,  54,  41,  54,  85,  106, 126, 125, 63,  63,  13,  11,  14,  14,  0,
    0,   224, 224, 16,  240, 104, 152, 132, 124, 4,   252, 4,   252, 4,   252,
    36,  220, 36,  220, 36,  220, 162, 222, 158, 254, 252, 228, 248, 248, 0,
    0,   0,   0,   3,   3,   12,  15,  22,  25,  42,  55,  36,  63,  41,  62,
    39,  63,  34,  63,  51,  46,  51,  47,  124, 71,  57,  63,  31,  19,  15,
    15,  6,   6,   0,   0,   240, 240, 56,  200, 12,  244, 98,  190, 210, 126,
    172, 220, 56,  200, 248, 40,  252, 36,  248, 8,   240, 240, 48,  208, 248,
    232, 92,  100, 56,  56,  0,   0,   3,   3,   12,  15,  22,  25,  42,  55,
    36,  63,  41,  62,  39,  63,  34,  63,  51,  46,  49,  47,  126, 67,  62,
    63,  55,  63,  23,  25,  14,  14,  0,   0,   240, 240, 56,  200, 12,  244,
    98,  190, 210, 126, 172, 220, 56,  200, 248, 40,  252, 36,  248, 8,   240,
    240, 80,  240, 252, 60,  252, 252, 48,  48};

void test() {
    UBYTE i = 0;
    display_off();

    LCDC_REG = 0x67;
    BGP_REG = OBP0_REG = 0xE4U;
    OBP1_REG = 0xD2U;
    WX_REG = MINWNDPOSX;
    WY_REG = 96;

    DISPLAY_ON;

    set_sprite_data(0, 24, sprite_1_data);
    init_sprite_pool();

    // Init actors
    actors_active_len = 0;
    actors_active_head = 0;
    actors_inactive_head = 0;
    for (i = 0; i != TEST_ACTORS_LEN; i++) {
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
        actors[i].enabled = FALSE;
        DL_PUSH_HEAD(actors_inactive_head, &actors[i]);
    }
    actors[0].x = 0;
    actors[0].y = 8;

    // Init scroll
    scroll_x_max = 256;
    scroll_y_max = 0;
    scroll_init();

    // Position actors from top right of screen
    // to offscreen spaced out by 16px
    for (i = 1; i != TEST_ACTORS_LEN; i++) {
        actors[i].x = 144 + (i << 3) - 16;
        actors[i].y = 8 + (i << 4) - 16;
    }

    // Move camera allowing offscreen actors to
    // become visible
    for (i = 0; i != 104; i++) {
        camera_x++;
        scroll_update();
        actors_update();
    }

    delay(100);
}
