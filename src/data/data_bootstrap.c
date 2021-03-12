#include "data/data_bootstrap.h"
#include "data/scene_7.h"
#include "data/palette_0.h"
#include "data/vwf_font.h"
#include "data/vwf_font_bold.h"

const INT16 start_scene_x = 2560;
const INT16 start_scene_y = 0;
const direction_e start_scene_dir = DIR_RIGHT;
const far_ptr_t start_scene = TO_FAR_PTR_T(scene_7);
const far_ptr_t start_player_palette = TO_FAR_PTR_T(palette_0);
const UBYTE start_player_move_speed = 16;
const UBYTE start_player_anim_tick = 7;
const far_ptr_t ui_fonts[] = {TO_FAR_PTR_T(vwf_font), TO_FAR_PTR_T(vwf_font_bold)};

void bootstrap_init() __banked {
    plat_min_vel = 304;
    plat_walk_vel = 6400;
    plat_climb_vel = 4000;
    plat_run_vel = 10496;
    plat_walk_acc = 152;
    plat_run_acc = 228;
    plat_dec = 208;
    plat_jump_vel = 16384;
    plat_grav = 1792;
    plat_hold_grav = 512;
    plat_max_fall_vel = 20000;
    topdown_grid = 8;
    fade_style = 1;    
}
