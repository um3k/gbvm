#ifndef DATA_PTRS_H
#define DATA_PTRS_H

#include "bankdata.h"
#include "gbs_types.h"

#define NUM_VARIABLES 500
#define TMP_VAR_1 -1
#define TMP_VAR_2 -1

extern const INT16 start_scene_x;
extern const INT16 start_scene_y;
extern const direction_e start_scene_dir;
extern const far_ptr_t start_scene;
extern const far_ptr_t start_player_palette;
extern const UBYTE start_player_move_speed;
extern const UBYTE start_player_anim_tick;

extern const far_ptr_t ui_fonts[];

// Engine fields
extern WORD plat_min_vel;
extern WORD plat_walk_vel;
extern WORD plat_run_vel;
extern WORD plat_climb_vel;
extern WORD plat_walk_acc;
extern WORD plat_run_acc;
extern WORD plat_dec;
extern WORD plat_jump_vel;
extern WORD plat_grav;
extern WORD plat_hold_grav;
extern WORD plat_max_fall_vel;
extern UBYTE topdown_grid;
extern UBYTE fade_style;

#endif
