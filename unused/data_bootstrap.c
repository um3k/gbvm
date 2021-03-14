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
